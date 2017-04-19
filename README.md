# Assignment 1.10: Choose your own assignment

## Description

In this assignment, we were able to do whatever we wanted to improve the game.
I chose to do a hodgepodge of things to make the game more fun:

* Implemented ranged attacks. Clicking `r` when it is your turn will activate
ranged mode. Then, you move around the dungeon as usual with your keys, and
upon clicking enter, you will attempt to attack the monster where your cursor
is. If there is no monster, nothing happens and it is still your turn. To exit
ranged mode, you can click escape.

* Implemented weight. Now, the player has a max carrying capacity (equipment
weight + inventory weight) and if the player is carrying more than their max
carrying capacity, their speed is reduced by 75%. A message will appear at the
beginning of each turn while the player is overencumbered to encourage them to
drop some of their items.

* Implemented health regeneration. This applies both for monsters and for
players. Each character regenerates 0.1 percent of their health each turn until
they reach their maximum health.

* Implemented a HUD page. This page is used to give important information to
the user about their player. Clicking `H` will open the HUD page. Right now,
it only displays health and weight.

* Fixed attack damage computation. Previously, bare hand damage would be
included even if a weapon was wielded. Now, bare hand damage is only included
if there are no weapons wielded.

* I also fixed a couple of issues that were causing seg faults and bad allocs

## Looking Ahead

Some upcoming features I to be added include:

* Leveling up
* Player statistics (strength, dexterity, etc.)
* Spells (the player reads a book and then permanently knows a spell)

## Usage

Same usage as always:
`make`
`./generate_dungeon`
