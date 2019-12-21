# FibonacciFractals
This C program computes the nth Fibonacci fractal of your choice, then draws it and outputs the result in a bmp image file.

A makefile has been provided that links all the necessary object files and outputs sample fibonacci fractal bmp files.

The makefile can be modified to change the n value (see legend below). However, caution should be taken to ensure that the output image's width and height are large enough to contain the fractal.

Usage: ./fib n x y step width height filename

To run the program, run the makefile by executing the command `make`, and then execute the fib script with parameters of your choice, for example: `./fib 9 10 10 5 100 100 fib9.bmp`

Legend:
- n: how many fibonacci words will be concatenated to form the fractal
- x: starting point's x value
- y: starting point's y value
- step: step value for each line drawn (in pixels)
- width: output image file's width (in pixels)
- height: output image file's height (in pixels)
- filename: output image file's filename

Below is the provided makefile (also in the repository):

```
CFLAGS=-Wall -O2 -ansi
fib: main_fib.o fib.o bmp.o timing.o
        $(CXX) -o fib $?
clean:
        @rm -rf fib *.o *bmp
```
