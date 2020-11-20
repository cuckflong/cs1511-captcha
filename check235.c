#include<stdio.h>
#include"captcha.h"

int check235(int height, int width, int pixels[height][width]);
int checkvertical(int height, int width, int checkindex, int pixels[height][width]);

int check235(int height, int width, int pixels[height][width]){
    int j=0, confirm=0;
    while(j<width){
        if(checkvertical(height, width, j, pixels)>4){
            confirm=1;
        }
        j++;
    }
    return confirm;
}

int checkvertical(int height, int width, int checkindex, int pixels[height][width]){
    int i=1, checkstart=0, change=0;
    while(i<height){
        if(pixels[i][checkindex]==1 && checkstart==0){
            checkstart=1;
        }
        if(pixels[i][checkindex]==0 && checkstart==1){
            checkstart=2;
        }
        if((pixels[i][checkindex] != pixels[i-1][checkindex]) && checkstart==2){
            change++;
        }
        if(pixels[i][checkindex]==1 && i==height-1){
            change++;
        }
        i++;
    }
    return change;
}
