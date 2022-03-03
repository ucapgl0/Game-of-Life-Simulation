PHAS0100ASSIGNMENT1
------------------

[![Build Status](https://travis-ci.com/[USERNAME]/PHAS0100Assignment1.svg?branch=master)](https://travis-ci.com/[USERNAME]/PHAS0100Assignment1)
[![Build Status](https://ci.appveyor.com/api/projects/status/[APPVEYOR_ID]/branch/master)](https://ci.appveyor.com/project/[USERNAME]/PHAS0100Assignment1)


Purpose
-------

This project serves as a starting point for the PHAS0100 2021/22 Assignment 1 Game of Life Simulation coursework. It has a reasonable folder structure for [CMake](https://cmake.org/) based projects,
that use [CTest](https://cmake.org/) to run unit tests via [Catch](https://github.com/catchorg/Catch2). 

Further information on the specific project is left as an exercise for the student.


Credits
-------

This project is maintained by [Dr. Jim Dobson](https://www.ucl.ac.uk/physics-astronomy/people/dr-jim-dobson). It is based on [CMakeCatch2](https://github.com/UCL/CMakeCatch2.git) that was originally developed as a teaching aid for UCL's ["Research Computing with C++"](http://rits.github-pages.ucl.ac.uk/research-computing-with-cpp/)
course developed by [Dr. James Hetherington](http://www.ucl.ac.uk/research-it-services/people/james)
and [Dr. Matt Clarkson](https://iris.ucl.ac.uk/iris/browse/profile?upi=MJCLA42).


Build Instructions
------------------

To build this project.

First, turn on the IDE(like VS code) by Dev Container and open the project as the folder.

Second, open new terminal and input the comand below on terminal to build the document.

```Bash
mkdir build
cd build
cmake ..
make
```
After building document, users could run the project following the run instruction below.

Use instruction
---
There are two application on this project, one is ***gofSimulator*** and the other is ***Still-life***

### **Command-line application 1: gofSimulator**

This command line application runs the Game of Life simulation.

User could check the usage information by input comands from the build director:

```Bash
./bin/gofSimulator -h
```
or
```Bash
./bin/gofSimulator --help
```

And there are two options to use this command-line application.

(1) specifying a text file input;

```Bash
./bin/gofSimulator <file> <iterations>
```
(2) starting with random cell contents for the initial conditions. 

```Bash
./bin/gofSimulator <rows> <columns> <alives> <iterations>
```

If users input invaild number of arguments, the usage information will be returned.

### **Command-line application 2: Still_life**

This command line application will print stationary patterns of grid cells if it is exist.

User could check the usage information by input comands from the build director:

```Bash
./bin/Still_life -h
```
or
```Bash
./bin/Still_life --help
```
And there is only one option to use this command-line application.

User could app 5 arguments to control the number of alive cells, the grid size, the number of iterations and the number of stationary patterns to try for each configuration when searching for Still Life’s.

```Bash
./bin/Still_life <alives> <rows> <columns> <iterations> <number_of_configurations>
```

If users input invaild number of arguments, the usage information will be returned.

### **Unit Tests**
Users can input the command below to run the file "unit_test.cpp" to test.
```Bash
ctest -V
```

Still Life’s 
------------

I found these stationary patterns from generations.

3 x 3 Grid | |
--------- | --------|
![3x3fig1](/screengrabs/3x3still_life.png)|![3x3fig2](/screengrabs/3x3still_life2.png)

4 x 4 Grid| | |
--------- | --------|--------|
![4x4fig1](/screengrabs/problem9d_4x4still_life1.png)  | ![4x4fig2](/screengrabs/problem9d_4x4still_life2.png) |![4x4fig3](/screengrabs/problem9d_4x4still_life3.png)

5 x 5 Grid| |
--------|--------
![5x5fig1](/screengrabs/5x5still_life1.png)|![5x5fig2](/screengrabs/5x5still_life2.png)

6 x 6 Grid| |
--------|--------
![6x6fig1](/screengrabs/6x6still_life1.png)|![6x6fig2](/Screengrabs/6x6still_life2.png)
