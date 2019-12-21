CFLAGS=-Wall -O2 -ansi
fib: main_fib.o fib.o bmp.o timing.o
	$(CXX) -o fib $?
runall:
	./fib 7 10 10 5 50 50 fib7.bmp
	#./fib 9 10 10 5 100 100 fib9.bmp
	#./fib 25 10 10 5 5500 5500 fib25.bmp
clean:
	@rm -rf fib *.o *bmp