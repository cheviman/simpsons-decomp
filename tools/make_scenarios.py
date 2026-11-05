"""
Name:        make_scenarios.py
Description: writes the control scripts of tests/controls: the attract mode, the EEPROM's factory reset, each page
             of the test mode, games of one and four players, a continue, the story before the first stage
             untouched, and a four-player game in each of the eight stages and the two bonus games, to its
             boss's end and, in the last, the ending
Version:     0.1.0
Created:     05-11-2026
Modified:    05-11-2026
Author:      Sebastian Toyos

Usage: python tools/make_scenarios.py

The players do what a script can do without looking: each one walks right, attacks every ATTACK_EVERY frames,
jumps every JUMP_EVERY, and walks down and up the street in turn. A game starts with a coin and the start button
in a seat: Marge in the first, then Homer, Bart and Lisa. The first player's attack button skips the story before
the first stage.

Places of the work RAM that make the rest of the game reachable (found by kref's ROM reads of the stage names,
the code that reads them, and the RAM of games losing their lives):
  - the game's mode, at 4800: 0 in the attract mode, 2 while a game is played (1 as it ends);
  - the game's step, at 4803: 1 the story before the first stage, then the stages and what is between them
    (STEPS), and its stage within the step, at 4804, which a step's handler starts from 0 (the step's setup:
    the stage's script from bank 13, its scene, 4867, the table at E88D's entry for it, BA87: LDX #$E88D;
    LDA <$03; LDA A,X; STA <$67). The game goes on to the next step as the program does at a step's end (A75E:
    INC <$03, then 4804-4806 cleared): pokes of 4804-4806 to 0 and of 4803 to a step, while the first stage is
    played, start that step whole (a poke of the step alone, during the story, loads its stage's place but not
    its script: the players walk and nothing comes);
  - each player's lives, at 49D1 + 8 x the player's index (2 at the start): a poke every LIVES_EVERY frames keeps
    them up, so a game goes on as long as the script says (TMNT keeps them the same way, 060101 + 8 x player).
The test switch held from the power-on resets the EEPROM's settings ("EEP ROM TEST OK, RECOMMAND SET COMPLETE");
pressed during the attract mode it opens the test mode's menu, which the first player's joystick and attack button
go through.
"""
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CONTROLS = ROOT / "tests" / "controls"

STEP = 0x4803
STEP_STAGE = 0x4804             # the stage within the step, then two bytes the step's handler clears with it
LIVES = 0x49D1                  # the first player's; each other player's 8 bytes further
COIN_AT = 700                   # the attract mode's title is on by then
START_AT = 760
SKIP_STORY_AT = 1600
STEP_POKE_AT = 2500             # the first stage is played by then
PLAY_FROM = 1700
ATTACK_EVERY = 8
JUMP_EVERY = 240
LIVES_EVERY = 300
WANDER_EVERY = 480              # down for WANDER_STEP frames, then up as long, in each of these
WANDER_STEP = 60
# the frame the next step starts at in each step's game, these players beating its boss (measured on build/bin/kref,
# within 1000 frames): their games go on PAST_THE_END frames past it, for the boss's end and the next step's start.
# Stage 3's game plays its step 7 too (the cemetery's second part, which a poke alone leaves without its graphics)
STEP_ENDS = {2: 11000, 3: 4000, 4: 18000, 6: 29000, 8: 25000, 9: 25000, 11: 24000, 12: 5000, 13: 34000, 15: 34000}
PAST_THE_END = 1500
# stage 8: the players let go once Mr. Burns falls (about frame 34500; a button skips the ending as it does the
# stories), and the ending runs: the family (step 16, from about 35000), the staff roll, THANK YOU FOR PLAYING, the
# game round again from stage 1 (step 2, about 40000), where no one plays, the continue countdowns, the game's end
# (its mode 1 about 45000) and the attract mode
ENDING_LAST = 50000
# a one-player game's player who does nothing after the story: her lives run out about frames 3100 and 4100
CONTINUE_AT = 4600              # and the continue countdown runs until about 5700
BUY_IN_AT = 3000                # a coin while she plays: a life more
SERVICE_AT = 700                # the test mode's menu opens with the test switch pressed in the attract mode
MENU_STEP = 60                  # the frames between two moves of the menu's cursor

# the game's steps (4803) and what they are
STEPS = {
    2: "stage 1, Downtown Springfield",
    3: "the first bonus game (the Krusty dolls blown up)",
    4: "stage 2, Krustyland",
    6: "stage 3, the night forest and the cemetery",
    8: "stage 4, the street of Moe's Tavern",
    9: "stage 5, the gorge and its cave",
    11: "stage 6, Dreamland",
    12: "the second bonus game",
    13: "stage 7, Channel 6",
    15: "stage 8, the Springfield Nuclear Power Plant",
}

# the test mode's menu: its items, from the top
TEST_PAGES = ["rom", "screen", "color", "io", "music", "sound", "start", "options"]


def start(lines, players):
    """a coin and the start button in each seat"""
    for player in players:
        lines.append(f"{COIN_AT + 10 * (player - 1)} press coin{player}")
    for player in players:
        lines.append(f"{START_AT + 10 * (player - 1)} press start{player}")


def play(lines, players, first, last, keep_lives=False):
    """the players walk right, attack and jump from frame 'first' to 'last', and walk down and up the street in
    turn (WANDER_EVERY frames, each player a quarter of it later), so that an enemy above or below them is in
    reach too"""
    for player in players:
        lines.append(f"{first} hold right{player}")
    for frame in range(first, last - WANDER_EVERY, WANDER_EVERY):
        for player in players:
            begin = frame + (player - 1) * WANDER_EVERY // 4
            lines += [f"{begin} hold down{player}", f"{begin + WANDER_STEP} release down{player}",
                      f"{begin + WANDER_EVERY // 2} hold up{player}",
                      f"{begin + WANDER_EVERY // 2 + WANDER_STEP} release up{player}"]
    for frame in range(first, last, ATTACK_EVERY):
        for player in players:
            lines.append(f"{frame} press attack{player} 2")
        if (frame - first) % JUMP_EVERY == JUMP_EVERY // 2:
            for player in players:
                lines.append(f"{frame} press jump{player} 2")
        if keep_lives and (frame - first) % LIVES_EVERY == 0:
            for player in players:
                lines.append(f"{frame} poke {LIVES + 8 * (player - 1):04X} 02")
    for player in players:
        lines.append(f"{last} release right{player}")


def test_page(lines, item):
    """the test mode's menu, its cursor down to item 'item' (from 1), and the page opened: the frame it opens at"""
    lines.append(f"{SERVICE_AT} press service 10")
    frame = SERVICE_AT + 200
    for _ in range(item - 1):
        lines.append(f"{frame} press down1 6")
        frame += MENU_STEP
    lines.append(f"{frame} press attack1 6")
    return frame + MENU_STEP


def write(name, header, lines):
    text = "\n".join([f"# {line}" for line in header] + lines) + "\n"
    (CONTROLS / f"{name}.txt").write_text(text, encoding="ascii", newline="\n")


def main():
    CONTROLS.mkdir(parents=True, exist_ok=True)
    write("attract", ["The attract mode from power-on, no input: the RAM and ROM check (the Z80's own test too), the",
                      "title, the family's profiles, the demo game, and the attract mode again"],
          ["7200 end"])

    write("eeprom_reset", ["The test switch held from power-on: the EEPROM's settings back to the recommended ones",
                           "(EEP ROM TEST OK, RECOMMAND SET COMPLETE), then the switch let go"],
          ["0 hold service", "900 release service", "2400 end"])

    # the test mode's pages, one script each
    lines = []
    frame = test_page(lines, 1)
    lines.append(f"{frame + 12000} end")
    write("test_rom", ["The test mode's ROM check: the tile, sprite and sample ROMs read through their chips"], lines)

    for item, name, pages in ((2, "screen", "the screen check's patterns"), (3, "color", "the color check's bars")):
        lines = []
        frame = test_page(lines, item)
        for press in range(8):
            lines.append(f"{frame + 120 * press} press attack1 6    # the next one, or the page's exit")
        lines.append(f"{frame + 120 * 8 + 300} end")
        write(f"test_{name}", [f"The test mode's {name} check: {pages}, the attack button pressed in turn"], lines)

    lines = []
    frame = test_page(lines, 4)
    for player in range(1, 5):
        for control in ("left", "right", "up", "down", "attack", "jump", "start"):
            if (player, control) != (1, "attack"):
                lines.append(f"{frame} press {control}{player} 8")
                frame += 15
    for control in ("coin1", "coin2", "coin3", "coin4"):
        lines.append(f"{frame} press {control} 8")
        frame += 15
    lines += [f"{frame + 60} press attack1 6    # the page's exit", f"{frame + 400} end"]
    write("test_io", ["The test mode's I/O check: every input of the four players and the four coin slots pressed in",
                      "turn, then its exit"], lines)

    for item, name, count, every in ((5, "music", 48, 240), (6, "sound", 160, 40)):
        lines = []
        frame = test_page(lines, item)
        for press in range(count):
            lines.append(f"{frame + every * press} press attack1 4    # the next {name}")
        lines.append(f"{frame + every * count + 300} end")
        write(f"test_{name}", [f"The test mode's {name} check: the attack button plays the next {name}, {count} of them,",
                               f"{every} frames each"], lines)

    lines = []
    frame = test_page(lines, 7)
    lines += [f"{frame} press down1 6    # with start buttons", f"{frame + MENU_STEP} press attack1 6",
              f"{frame + 3 * MENU_STEP} press down1 6", f"{frame + 4 * MENU_STEP} press attack1 6    # the page's exit",
              f"{frame + 600} end"]
    write("test_start", ["The test mode's start button page: games with start buttons chosen, then its exit"], lines)

    lines = []
    frame = test_page(lines, 8)
    for _ in range(7):
        for _ in range(3):
            lines.append(f"{frame} press right1 6    # the setting changed")
            frame += MENU_STEP
        lines.append(f"{frame} press down1 6    # the next setting")
        frame += MENU_STEP
    lines += [f"{frame} press attack1 6    # the factory setting", f"{frame + 600} end"]
    write("test_options", ["The test mode's coin and game options: each setting changed three times, then the factory",
                           "setting chosen (the EEPROM written)"], lines)

    lines = []
    start(lines, [1])
    lines.append(f"{SKIP_STORY_AT} press attack1 8    # the story skipped")
    lines.append("9000 end")
    write("one_player", ["A one-player game: a coin and the start button, the story skipped, then Marge does nothing:",
                         "her lives run out, the continue countdown runs out (about frame 5700), and the attract mode",
                         "comes back"], lines)

    lines = []
    start(lines, [1])
    play(lines, [1], 3600, 7000)
    lines.append("8000 end")
    write("story_untouched", ["A one-player game in which no button is pressed through the story before the first",
                              "stage, to its end, then Marge plays a while"], lines)

    lines = []
    start(lines, [1])
    lines.append(f"{SKIP_STORY_AT} press attack1 8    # the story skipped")
    lines += [f"{CONTINUE_AT} press coin1    # during the continue countdown", f"{CONTINUE_AT + 60} press start1"]
    play(lines, [1], CONTINUE_AT + 200, 9000)
    lines.append("11000 end")
    write("continue", ["A one-player game that continues: Marge does nothing after the story, her lives run out, and",
                       "a coin and the start button during the continue countdown bring her back"], lines)

    lines = []
    start(lines, [1])
    lines.append(f"{SKIP_STORY_AT} press attack1 8    # the story skipped")
    play(lines, [1], PLAY_FROM, BUY_IN_AT)
    lines += [f"{BUY_IN_AT} press coin1    # while she plays: a life more", f"{BUY_IN_AT + 60} press start1"]
    play(lines, [1], BUY_IN_AT + 200, 9000)
    lines.append("11000 end")
    write("buy_in", ["A one-player game in which a coin and the start button, while Marge plays, buy her a life"],
          lines)

    lines = []
    start(lines, [1, 2, 3, 4])
    lines.append(f"{SKIP_STORY_AT} press attack1 8    # the story skipped")
    play(lines, [1, 2, 3, 4], PLAY_FROM, 7000)
    lines.append("9000 end")
    write("four_players", ["A four-player game: a coin and the start button in every seat (Marge, Homer, Bart, Lisa),",
                           "all of them walking right and attacking until their lives run out"], lines)

    for step, place in STEPS.items():
        lines = []
        start(lines, [1, 2, 3, 4])
        lines.append(f"{SKIP_STORY_AT} press attack1 8    # the story skipped")
        if step != 2:
            lines += [f"{STEP_POKE_AT} poke {STEP_STAGE + offset:04X} 00" for offset in range(3)]
            lines.append(f"{STEP_POKE_AT} poke {STEP:04X} {step:02X}    # the game goes on at step {step}")
        if step == 15:
            play(lines, [1, 2, 3, 4], PLAY_FROM, STEP_ENDS[step], keep_lives=True)
            last = ENDING_LAST
        else:
            last = STEP_ENDS[step] + PAST_THE_END
            play(lines, [1, 2, 3, 4], PLAY_FROM, last, keep_lives=True)
        lines.append(f"{last + 100} end")
        name = place.split(",")[0].replace(" ", "")
        if "bonus" in place:
            name = "bonus1" if step == 3 else "bonus2"
        header = [f"Step {step}, {place}: a four-player game" + ("," if step == 2 else
                                                                   " that goes on there from the first stage:")]
        if step != 2:
            header.append(f"at frame {STEP_POKE_AT} the step poked at {STEP:04X} and its stage at "
                          f"{STEP_STAGE:04X}-{STEP_STAGE + 2:04X} cleared, as a step's end does;")
        ending = ([f"until Mr. Burns falls; then they let go (frame {STEP_ENDS[step]}) and the ending runs: the family, "
                   "the staff roll,", "THANK YOU FOR PLAYING, the game round again where no one plays, its end and "
                   "the attract mode"] if step == 15 else
                  [f"until its boss falls and the next step starts, about frame {STEP_ENDS[step]}"])
        write(name, header + ["the players walking right and attacking, their lives kept up,"] + ending, lines)


if __name__ == "__main__":
    main()
