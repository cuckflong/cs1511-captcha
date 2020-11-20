#include<stdio.h>
#include "captcha.h"

void print_image(int height, int width, int pixels[height][width]);

void print_image(int height, int width, int pixels[height][width]){
    int i=height-1, j=0;
    while(i>=0){
        j=0;
        while(j<width){
            if(pixels[i][j]==0){
                printf(".");
            }
            else{
                printf("*");
            }
            j++;
        }
        printf("\n");
        i--;
    }

}
