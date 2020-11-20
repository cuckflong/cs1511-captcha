#include<stdio.h>
#include "captcha.h"

void get_bounding_box(int height, int width, int pixels[height][width],
                      int *start_row, int *start_column, int *box_height, int *box_width);

void get_bounding_box(int height, int width, int pixels[height][width],
                      int *start_row, int *start_column, int *box_height, int *box_width){
    int i=0, j=0;
    while(i<height){
        j=0;
        while(j<width){
            if(pixels[i][j]==1){
                *start_row=i;
                j=width;
                i=height;
            }
            j++;
        }
        i++;
    }
    i=0;
    j=0;
    while(i<width){
        j=0;
        while(j<height){
            if(pixels[j][i]==1){
                *start_column=i;
                j=height;
                i=width;
            }
            j++;
        }
        i++;
    }
    i=height-1;
    j=0;
    while(i>=0){
        j=0;
        while(j<width){
            if(pixels[i][j]==1){
                *box_height=i-*start_row+1;
                j=width;
                i=0;
            }
            j++;
        }
        i--;
    }
    i=width-1;
    j=0;
    while(i>=0){
        j=0;
        while(j<height){
            if(pixels[j][i]==1){
                *box_width=i-*start_column+1;
                j=height;
                i=0;
            }
            j++;
        }
        i--;
    }
}
