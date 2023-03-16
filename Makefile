
main: main.o imageio.o help.o
	g++ -o main main.o imageio.o help.o

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

main.o: main.cpp imageio.h help.h

help.o: help.cpp help.h

clean:
	rm -f sample.o imageio.o main.o help.o

rmImages:
	rm -f taskA.pgm taskB.pgm taskC.pgm taskD.pgm