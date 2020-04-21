# System-Monitor using Ncurses

## About
The project follows an object-oriented programming approach and implements a Linux parser that extracts system and process data and displays vital system information on a terminal UI using the ncurses library. Information such as CPU Utilization, Memory Utilization and System Up-time are calculated and displayed. Along with this, information on the running processes and their CPU and memory utilization are displayed on the UI.

## ncurses
[ncurses](https://www.gnu.org/software/ncurses/) is a library that facilitates text-based graphical output in the terminal. This project relies on ncurses for display output.

To install ncurses within Linux environment: `sudo apt install libncurses5-dev libncursesw5-dev`

## Make
This project uses [Make](https://www.gnu.org/software/make/). The Makefile has four targets:
* `build` compiles the source code and generates an executable
* `format` applies [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) to style the source code
* `debug` compiles the source code and generates an executable, including debugging symbols
* `clean` deletes the `build/` directory, including all of the build artifacts


## Note
Starter code for this project can be obtained from this [Udacity-Repository](https://github.com/udacity/CppND-System-Monitor-Project-Updated.git)
