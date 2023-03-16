#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include "help.h"
using namespace std;

// Writes a PGM file 2x the size of the original
// Need to provide the array data and the image dimensions
void writeImage2x(std::string filename, int image[MAX_H2x][MAX_W2x], int height, int width) {
	ofstream ostr;
	ostr.open(filename);
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

int sobel(int a, int b, int c, int d, int e, int f, int g, int h, int i){
    if(a > 255){
        a = 0;
    }
    if(b > 255){
        b = 0;
    }
    if(c > 255){
        c = 0;
    }
    if(d > 255){
        d = 0;
    }
    if(e > 255){
        e = 0;
    }
    if(f > 255){
        f = 0;
    }
    if(g > 255){
        g = 0;
    }
    if(h > 255){
        h = 0;
    }
    if(i > 255){
        i = 0;
    }
    return ((g+(2*h)+i)-(a+(2*b)+c));
}

