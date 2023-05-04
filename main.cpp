#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "imageio.h"
#include <cmath>
#include "help.h"
using namespace std;

//	Task A

void invert(string input){
	//blank 2d array of image
	int img[MAX_H][MAX_W];

	// height, width
	int h, w;

	//fills in the value of image(img) from the pgm file(input)
	readImage(input, img, h, w);

	//output image
	int out[MAX_H][MAX_W];

	//nested loop to fill in output image with new values
	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			//output image = inverts the specific value in the 2d array(image)
			out[row][col] = abs(255 - img[row][col]);
		}
	}
	//creates the output image in pgm format, that can be viewed
	writeImage("taskA.pgm", out, h, w);
}

//	Task B

void invertHalf(string input){
	//blank 2d array of image
	int img[MAX_H][MAX_W];

	// height, width
	int h, w;

	//fills in the value of image(img) from the pgm file(input)
	readImage(input, img, h, w);

	//output image
	int out[MAX_H][MAX_W];

	//nested loop to fill in output image with new values
	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {

		    if(col > w/2) {	// half the image (vertically)
				out[row][col] = abs(255 - img[row][col]); //inverts the specific value in the 2d array(image)
		    }
			else {//output image = regular input image values
				out[row][col] = img[row][col];
		    }
		}
	}
	//creates the output image in pgm format, that can be viewed
	writeImage("taskB.pgm", out, h, w);
}

//	Task C

void box(string input){
	//blank 2d array of image
	int img[MAX_H][MAX_W];

	// height, width
	int h, w;

	//fills in the value of image(img) from the pgm file(input)
	readImage(input, img, h, w);

	//output image
	int out[MAX_H][MAX_W];

	//nested loop to fill in output image with new values
	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			//	height
			//row > h/4 stops at the top (1/4)
			//row < h*0.75 continues from the bottom (4/4)
			//	width
			//col > w/4 stops at the left (1/4)
			//col > w*075 continues from the right (4/4)
		    if( (row > h/4) && (row < h*0.75) && (col > w/4) && (col < w*0.75) ) {
				//output image value = white
				out[row][col] = 255;
		    }
			else {//output image = regular input image values
				out[row][col] = img[row][col];
		    }
		}
	}
	//creates the output image in pgm format, that can be viewed
	writeImage("taskC.pgm", out, h, w);
}

//	Task D

void frame(string input){
	//blank 2d array of image
	int img[MAX_H][MAX_W];

	// height, width
	int h, w;

	//fills in the value of image(img) from the pgm file(input)
	readImage(input, img, h, w);

	//output image
	int out[MAX_H][MAX_W];

	//nested loop to fill in output image with new values
	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			//whites out the border from the box function
		    if( ((col== int(w*0.25))) && ((row < int(h*0.75)) && (row>int(h*0.25))) || //left
			((col== int(w*0.75))) && ((row < int(h*0.75)) && (row>int(h*0.25))) ||// right
			((row == int(h/4)) && ((col > w/4) && (col < int(w*0.75)))) || // top
			((row == int(h*0.75)) && ((col > w/4) && (col < int(w*0.75)))) ) { //bottom
				out[row][col] = 255;
		    }
			else {//output image = regular input image values
				out[row][col] = img[row][col];
		    }
		}
	}
	//creates the output image in pgm format, that can be viewed
	writeImage("taskD.pgm", out, h, w);
}

//task E

void scale(string input){
	//blank 2d array of image
	int img[MAX_H][MAX_W];

	// height, width
	int h, w;

	//fills in the value of image(img) from the pgm file(input)
	readImage(input, img, h, w);

	//output image with double the max size
	int out[MAX_H*2][MAX_W*2];

	//nested loop to fill in output image with new values
	for(int row = 0; row < h*2; row++) {//height*2
		for(int col = 0; col < w*2; col++) {//width*2
			//output image = image values X 4(!)
			//(!)(height and width multiplied by 2) and (row and col divided by 2)
			out[row][col] = img[row/2][col/2];
		}
	}
	//creates the output image in pgm format, that can be viewed
	writeImage2x("taskE.pgm", out, h*2, w*2);
}

//	Task F

void pixelate(string input){
	//blank 2d array of image
	int img[MAX_H][MAX_W];

	// height, width
	int h, w;

	//fills in the value of image(img) from the pgm file(input)
	readImage(input, img, h, w);

	//output image
	int out[MAX_H][MAX_W];

	//nested loop to fill in output image with new values
	for(int row = 0; row < h; row+=2) {//increase by 2 to make the next square
		for(int col = 0; col < w; col+=2) {//increase by 2 to make the next square
			//rounded = (round a 2x2 square/4 + 0.5) = average color value of the 2x2
		    int rounded = round((img[row][col] + img[row+1][col] + img[row][col+1] + img[row+1][col+1])/4 +0.5);
		   
		    //a 2x2 square from output image becomes rounded
			out[row][col] = rounded;
		    out[row+1][col] = rounded;
		    out[row][col+1] = rounded;
		    out[row+1][col+1] = rounded;
		}
	}
	//creates the output image in pgm format, that can be viewed
	writeImage("taskF.pgm", out, h, w);
}

//	Task G

void kernel(string input){
	//blank 2d array of image
	int img[MAX_H][MAX_W];

	// height, width
	int h, w;

	//fills in the value of image(img) from the pgm file(input)
	readImage(input, img, h, w);

	//output image
	int out[MAX_H][MAX_W];

	//nested loop to fill in output image with new values
	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			//gets a 3x3 window made of a,b,c,e,d,f,g,h,i
			//sobel = a,b,c,e,d,f,g,h,i > 255 = 0
			//then return (g+2h+i)-(a+2b+c)
		    int f = sobel(img[row-1][col-1],img[row-1][col],img[row-1][col+1],img[row][col-1],img[row][col],img[row][col+1],img[row+1][col-1],img[row+1][col],img[row+1][col+1]);
		    
			if(f < 0) {
				f = 0;
		    }
			else if(f > 255) {
				f = 255;
		    }
			// output image = sobel(3x3 window)
		    out[row][col] = f;
		}
	}
	//creates the output image in pgm format, that can be viewed
	writeImage("taskG.pgm", out, h, w);
}

int main() {
	//	image
    std::string input = "image1.pgm";
	//	Task A
    invert(input);
	//	Task B
    invertHalf(input);
	//	Task C
    box(input);
	//	Task D
    frame(input);
	// Task E
    scale(input);
	//Task F
    pixelate(input);
	//Task G
    kernel(input);

    return 0;
}
