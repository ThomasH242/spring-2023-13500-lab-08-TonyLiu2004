
main: main.o imageio.o
	g++ -o main main.o imageio.o

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

main.o: main.cpp imageio.h

clean:
	rm -f sample.o imageio.o main.o

rmImages:
	rm -f taskA.pgm taskB.pgm taskC.pgm taskD.pgm