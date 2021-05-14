# Loggo

A logging system implemented as a part of the courswork for Design Patterns.

## Abstract 

The project implements a variation of the Observer Pattern to mimic the logging
system dependencies. Here Libraries usually depend on other libraries and
updating any one Library leads to the change of states in all the Libraries
depending on the one being changed. The state updates are cascaded through
the libraries which resembles the Daisy Chain Pattern.<br>
Singleton and Mediator Patterns concepts have been included into the
implementation of Observer Pattern.<br>
Concept of partial dependency where an observer depends only on a state of
the Subject has also been implemented.

## Patterns used

* Observer Pattern
* Singleton Pattern
* Mediator Pattern

## Implementation

There are two examples created to depict the use of these Patterns
* Library : behaves both as a Subject and Observer
* Geometry : calculates slope of a line formed between two coordinates

## Getting Started

* Clone the repository
* From the root of the repository, run `make` to generate all the object files, and the final executable.

## Directory Structure

* All header files belong in the `include/` directory
* All source files belong in the `src/` directory
* All object files are generated in the `bin/` directory
* The `Makefile` must be updated everytime a new file is added in either directory, appropriately.
* Object files are generated in `bin/` following the same directory structure as observed in `src/`.

## Team Members

* [Afreen Noorani](https://github.com/ghost)
* [Anant Thazhemadam](https://github.com/thazhemadam)
* [Roshini Bhaskar](https://github.com/roshbhaskar)
