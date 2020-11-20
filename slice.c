#include<stdio.h>
#include"captcha.h"

void slice(int height, int width, int pixels[height][width]);

void slice(int height, int width, int pixels[height][width]){
    int i=0, j=0;
    while(i<height){
        j=1;
        while(j<width){
            if(pixels[i][j] != pixels[i][j-1]){
                if(pixels[i][j]==1){
                    pixels[i][j]=0;
                    j++;
                }
                else{
                    pixels[i][j-1]=0;
                    j++;
                }
            }
            if(j==0 || j==width-1){
                pixels[i][j]=0;
            }
            j++;
        }
        i++;
    }
}

