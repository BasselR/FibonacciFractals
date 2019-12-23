# FibonacciFractals
This C program computes the nth Fibonacci fractal of your choice, then draws it and outputs the result in a bmp image file.

To run the program, execute the fib script with parameters of your choice, for example: `./fib 9 10 10 5 100 100 fib9.bmp`

Usage: ./fib n x y step width height filename

Caution should be taken to ensure that the output image's width and height are large enough to contain the fractal, or the program will terminate.

Legend:
- n: how many fibonacci words will be concatenated to form the fractal
- x: starting point's x value
- y: starting point's y value
- step: step value for each line drawn (in pixels)
- width: output image file's width (in pixels)
- height: output image file's height (in pixels)
- filename: output image file's filename

Additionally provided is the makefile used to create the linux executable, shown below (also in the repository):

```
CFLAGS=-Wall -O2 -ansi
fib: main_fib.o fib.o bmp.o timing.o
        $(CXX) -o fib $?
clean:
        @rm -rf fib *.o *bmp
```
