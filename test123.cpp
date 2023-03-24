#include <iostream>
#include "imageio.h"
#include <cmath>

using namespace std;

void pixelate(std::string fileimg) {
    int height; 
    int width; 
    int image[MAX_H][MAX_W];
    int average;

    readImage(fileimg, image, height, width);

    for(int i = 0;i < height; i+=2){
        for(int j = 0;j < width;j+=2){
            average = round(((image[i][j] + image[i+1][j] + image[i][j+1] + image[i+1][j+1]) / 4) + 0.5);
            image[i][j] = average;
            image[i + 1][j] = average;
            image[i][j + 1] = average;
            image[i + 1][j + 1] = average;
        }
    }

    writeImage("picF.pgm", image, height, width);
}