#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "imageio.h"
#include <cmath>
#include "help.h"
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

	writeImage("taskA.pgm", out, h, w);
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

	writeImage("taskB.pgm", out, h, w);
}

void box(string input){
    int img[MAX_H][MAX_W];
	int h, w;

	readImage(input, img, h, w);
	int out[MAX_H][MAX_W];

	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
            if((row > h/4) && (row<h*0.75)&& (col < w*0.75) && (col > w/4)){
                out[row][col] = 255;
            }else{
                out[row][col] = img[row][col];
            }
		}
	}

	writeImage("taskC.pgm", out, h, w);
}

void frame(string input){
    int img[MAX_H][MAX_W];
	int h, w;

	readImage(input, img, h, w);
	int out[MAX_H][MAX_W];

	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
            if( ((col== int(w*0.25))) && ((row < int(h*0.75)) && (row>int(h*0.25))) || //left
                ((col== int(w*0.75))) && ((row < int(h*0.75)) && (row>int(h*0.25))) ||// right
                ((row == int(h/4)) && ((col > w/4) && (col < int(w*0.75)))) || // top
                ((row == int(h*0.75)) && ((col > w/4) && (col < int(w*0.75)))) ){ //bottom
                out[row][col] = 255;
            }else{
                out[row][col] = img[row][col];
            }
		}
	}

	writeImage("taskD.pgm", out, h, w);
}

void scale(string input){
    int img[MAX_H][MAX_W];
	int h, w;

	readImage(input, img, h, w);
	int out[MAX_H*2][MAX_W*2];

	for(int row = 0; row < h*2; row++) {
		for(int col = 0; col < w*2; col++) {
			out[row][col] = img[row/2][col/2];
		}
	}

	writeImage2x("taskE.pgm", out, h*2, w*2);
}

void pixelate(string input){
    int img[MAX_H][MAX_W];
	int h, w;

	readImage(input, img, h, w);
	int out[MAX_H][MAX_W];

	for(int row = 0; row < h; row+=2) {
		for(int col = 0; col < w; col+=2) {
            int rounded = round((img[row][col] + img[row+1][col] + img[row][col+1] + img[row+1][col+1])/4 +0.5);
			out[row][col] = rounded;
            out[row+1][col] = rounded;
            out[row][col+1] = rounded;
            out[row+1][col+1] = rounded;
		}
	}

	writeImage("taskF.pgm", out, h, w);
}

void kernel(string input){
    int img[MAX_H][MAX_W];
	int h, w;

	readImage(input, img, h, w);
	int out[MAX_H][MAX_W];

	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
            int f = sobel(img[row-1][col-1],img[row-1][col],img[row-1][col+1],img[row][col-1],img[row][col],img[row][col+1],img[row+1][col-1],img[row+1][col],img[row+1][col+1]);
            if(f < 0){
                f = 0;
            }else if(f > 255){
                f = 255;
            }
            out[row][col] = f;
		}
	}

	writeImage("taskG.pgm", out, h, w);
}

int main() {
    std::string input = "image2.pgm";
    invert(input);
    invertHalf(input);
    box(input);
    frame(input);
    scale(input);
    pixelate(input);
    kernel(input);
    return 0;
}
