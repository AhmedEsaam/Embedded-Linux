# Makefile Task - Guessing Game

This makefile example automates the building process (compilation and linking) of the source files for a given game (Guessing a random number between 1 and 10 in only five tries).

---

## How to Compile the Game Application

### 1. Move your working directory to `Makefile_Task1/`

### 2. You may want to remove object and executable files using this command

```shell
make clean
```

### 3. Compile the application by running the makefile using `make`

```shell
make
```

### 4. Run the game application

```shell
./bin/game.exe
```

---

## The Game

* The game asks the user to guess a random number between 1 and 10 and gives him/her only five guesses.

* You start by entering the first number and the game checks if it matches the generated random number.

* If it does not match, the game asks the user to enter a second guess and so on.

* The game exits if the user entered the correct generated number or exhausted the five tries limit.
