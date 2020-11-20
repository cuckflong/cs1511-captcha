#include<stdio.h>
#include "captcha.h"

double get_horizontal_balance(int height, int width, int pixels[height][width]);

double get_horizontal_balance(int height, int width, int pixels[height][width]){
    int i=0, j=0, num=0;
    double sumindex=0;
    while(i<height){
        j=0;
        while(j<width){
            if(pixels[i][j]==1){
                num++;
                sumindex = sumindex+j;
            }
            j++;
        }
        i++;
    }
    return (sumindex/num + 0.5)/width;
}
