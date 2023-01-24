Project:

Names:

Eviatar Davidyan  207259755
Shir Yadid  208327957

The Project is about building a Super Pacman game.

The files we created:

GameController.h 
runs the program and links all the elements.
GameController. cpp
 public run function implementation. and the other relevant functions as privacy.

Toolbar.h 
class responsible for the information menu that includes clock time, life points and the number of keys.
Toolbar.cpp
 implementing the appropriate relevant functions.

Board.h 
is a class responsible for printing the board and holding the objects on it.
Board.cpp
 implementing the relevant functions.

Resources.h Singleton class that loads the textures, the font, the sounds. and allows access to those objects with appropriate functions
Resources.cpp implementation of relevant functions mainly loading and access.

AddLife.h 
A class of gift that adds life to Pacman.
AddLife.cpp
Application of adding life by collision double dispatch.

AddTime.h 
A gift class that adds seconds to the game (and you can see it on the sides of the game)
AddTime.cpp
Application of adding Time by collision double dispatch.


Freeze.h 
A class of gifts that freezes the elves for 5 seconds in place
Freeze.cpp
Application of stopping the deamon by collision double dispatch.

Freeze.h 
A class of gifts that freezes the elves for 5 seconds in place
Freeze.cpp
Application of stopping the deamon by collision double dispatch.

SuperPacman.h 
A class of gifts that turns Pacman into Super Pacman
SuperPacman.cpp
Application of stopping the deamon by collision double dispatch.

Deamons.h
A class of demons that kill Pacman and take his life and have an independent movement algorithm
Deamons.cpp
Application of the functions Move, collisions.

Door.h
A stationary object class of a door - which does not allow normal Pacman to only switch to Super Pacman.
If keys are available, an option to enter will be given.
Door.cpp
Application of the functions handlecollision.

GameObject.h
An abstract class of game objects contains the location and the sprite.
GameObject.cpp
Implementation of position calculation and sprite update functions.

Key.h
A class of keys that can be collected until reaching a door that can then be opened
Key.cpp
Application of collection

Matrix.h
A matrix class called from the file.
Matrix.cpp
Application of functions of reading from a file and of updating the matrix if necessary to read another step.

Menu.h
A menu class that takes care of the buttons, for the short video at the beginning
Menu.cpp
Application of functions of display all the objects

MovingObject.h
An abstract class of moving figures allows to produce pointers of its type and thus to separate them from the stationary objects
MovingObject.cpp
Partial implementation of double dispatch and other functions.

StaticObject.h
A class of stationary objects.
StaticObject.cpp
implementation of  functions.

NormalPacman.h
A class inherits from a state class. Application in it of dealing with collisions of door and demons.
NormalPacman.cpp
Application of the functions.

Pacman.h
Pacman class inheriting from moving objects.
Contains the ability to move according to keys .Data and information about it
Pacman.cpp
Implementation of displacement and collision functions

SupaerPacmanState.h
A class inherits from a state class. Application in it of dealing with collisions of door and demons.
SupaerPacmanState.cpp
Application of the functions.


PacmanState.h
Pacman's state abstract class is Pacman as a pointer to the state of Pacman
PacmanState.cpp
Declarations of collision functions with pacman or door


Present.h
An abstract class from which all gifts inherit
Present.cpp
Statement of collision functions

Wall.h
 stationary object of a wall - which does not allow Pacman to pass. And not for elves
Wall.cpp
Application of Collisions





Main data structures:
A 2D vector of char. which contains the characters from the file.
A two-dimensional vector of rectangleshape. Draws the rectangles behind with color
Vector of unique ptr to hold the moving object, staatic object and pacman state.
Array of strings, textures

Noteworthy algorithms:
 The deamons runs after the pacman base on his cuurant location.
their speed is diffrent but all of them has the same algotithm.
 the pacman is more spped than them . in order to allow him to play.



The controller class is a connecting class between the objects. It contains members from some of the created class 
It is responsible for calling relevant functions found in the other classes and updating the information in the relevant class.
The board contains the objects (as a vector of pointers to the corresponding abstract class)
and responsible for updating them. An object is responsible for its own movement.
 

Known bugs:

Remarks :
The deamons speed is diffrent but all of them has the same algotithm.
 the pacman is more spped than them . in order to allow him to play.

There is polymorphism on the gifts.
Each gift is a different color.
Freezing gift - blue.
Extra time - White
Extra Life - Green
SuperPacman- Blue

