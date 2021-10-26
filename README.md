```
______                          _   _       _ _    
| ___ \                        | \ | |     (_) |   
| |_/ / ___  _ __  _ __   ___  |  \| |_   _ _| |_  
| ___ \/ _ \| '_ \| '_ \ / _ \ | . ` | | | | | __|
| |_/ / (_) | | | | | | |  __/ | |\  | |_| | | |_  
\____/ \___/|_| |_|_| |_|\___| \_| \_/\__,_|_|\__|

```
# Table of Contents
1. [About](#About)
2. [Build](#Build)
3. [Rules of the game](#rules-of-the-game)
   1. [First part](#premire-phase)
   2. [Second part](#deuxime-phase)
4. [Project Structure](#project-structure)

# About
This project was created for my class of ATLIR5/C++ @ ESI.
- Author : [Gregory van der Pluijm](54786@etu.he2b.be)
- Title : Bonne Nuit
- Date : 29/10/2021

# Build
Needed dependencies
- QT6
- Catch2
- Git
- CMake

```bash
cd esi-atlir5-bonne_nuit
make
cd build/release
./bonne_nuit
```

# Rules of the game
Dans l’explication de la règle, les pions rouges sont appelés « cases ».

##### Première phase:

Chaque joueur, quand c’est son tour, lance le dé. Il avance la goutte de rosée d’autant de cases que
de points obtenus, dans le sens des aiguilles d’une montre, et dépose la goutte sur la case atteinte.
Il place ensuite autour de cette case, à quelques centimètres de distance une étoile de sa couleur.
Ainsi startWindow’allume une première étoile dans le ciel.
Chaque joueur joue ainsi de la même manière. Le ciel se remplit d’étoiles.

##### Deuxième phase:

Éteignez la lumière. S’il fait vraiment noir, on ne voit plus la couleur des pions mais seulement les
étoiles phosphorescentes. L’adulte invite à la suite du jeu : quelle est l’étoile qui va briller le plus
longtemps dans la nuit ?
Chaque enfant espère que c’est la sienne.
Jouer, ce n’est plus lancer le dé mais éteindre une étoile, en la retournant et en espérant que ce n’est
pas une des siennes (mémoire ou hasard !).
Ainsi les étoiles startWindow’éteignent une à une (autant celles des joueurs que celles qui n’appartiennent à
personne)… et quand il n’en reste plus qu’une seule sur la table, allumez la lumière pour découvrir
celui qui gagne la partie.
# Project structure
```bash
-- src
|   |-- exceptions
|   |   |-- NoPawnFound.h
|   |   |-- NumberOfPlayerException.h
|   |   |-- OutOfGameBoardException.h
|   |   `-- PawnInPlaceException.h
|   |-- game
|   |   |-- Board.cpp
|   |   |-- Board.h
|   |   |-- Game.cpp
|   |   |-- Game.h
|   |   |-- GameState.h
|   |   |-- Pawn.h
|   |   `-- Player.h
|   |-- main.cpp
|   |-- ressources
|   |   |-- images
|   |   |   `-- img
|   |   |       |-- drop.png
|   |   |       |-- empty.png
|   |   |       |-- night.png
|   |   |       |-- no_drop.png
|   |   |       |-- star_black.png
|   |   |       |-- star_blue.png
|   |   |       |-- star_down.png
|   |   |       |-- star_green.png
|   |   |       |-- star_night.png
|   |   |       |-- star_purple.png
|   |   |       `-- star_red.png
|   |   |-- images.qrc
|   |   `-- random.hpp
|   |-- utils
|   |   |-- Observable.h
|   |   `-- Observer.h
|   `-- view
|       |-- View.cpp
|       |-- View.h
|       `-- windows
|           |-- mainWindow.cpp
|           |-- mainWindow.h
|           |-- newPlayerWidget.cpp
|           |-- newPlayerWidget.h
|           |-- winnerWidget.cpp
|           `-- winnerWidget.h
`-- test
    |-- mainTest.cpp
    `-- testGame.cpp

```
