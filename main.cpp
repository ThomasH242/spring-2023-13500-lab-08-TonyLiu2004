#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "imageio.h"
using namespace std;

void invert(string input){
	int img[MAX_H][MAX_W];
	int h, w;

	readImage(input, img, h, w);
	int out[MAX_H][MAX_W];

	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			out[row][col] = abs(255- img[row][col]);
		}
	}

	writeImage("taskA.pgm",out, h, w);
}

void invertHalf(string input){
    int img[MAX_H][MAX_W];
	int h, w;

	readImage(input, img, h, w); 
	int out[MAX_H][MAX_W];

	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
            if(col > w/2){
			    out[row][col] = abs(255- img[row][col]);
            }else{
                out[row][col] = img[row][col];
            }
		}
	}

	writeImage("taskB.pgm",out, h, w);
}


int main() {
    std::string input = "image2.pgm";
    invert(input);
    invertHalf(input);
    return 0;
}
