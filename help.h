#pragma once
const int MAX_H2x = 512*2;
const int MAX_W2x = 512*2;

void writeImage2x(std::string filename, int image[MAX_H2x][MAX_W2x], int height, int width);
int sobel(int a, int b, int c, int d, int e, int f, int g, int h, int i);
