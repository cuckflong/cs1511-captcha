#include<stdio.h>
#include "captcha.h"

void copy_pixels(int height, int width, int pixels[height][width],
                 int start_row, int start_column, int copy_height, int copy_width,
                 int copy[copy_height][copy_width]);

void copy_pixels(int height, int width, int pixels[height][width],
                 int start_row, int start_column, int copy_height, int copy_width,
                 int copy[copy_height][copy_width]){
    int i=start_row, j=start_column, k=0, l=0;
    while(i<start_row+copy_height){
        j=start_column;
        l=0;
        while(j<start_column+copy_width){
            copy[k][l]=pixels[i][j];
            l++;
            j++;
        }
        k++;
        i++;
    }
}
