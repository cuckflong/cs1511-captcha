#include<stdio.h>
#include"captcha.h"
int check6(int height, int width, int pixels[height][width], int startendindex[2]);
int checkholelength(int height, int width, int checkline, int pixels[height][width]);
int checkupper(int height, int width, int checkline, int checkindex, int pixels[height][width], int startendindex[2]);

int check6(int height, int width, int pixels[height][width], int startendindex[2]){
    int i=startendindex[1], j=0, longest=checkholelength(height, width, startendindex[1], pixels), longestindex=startendindex[1], checkstart=0, is6=0, islongest=0;
    while(islongest==0 && i>startendindex[0]){
        if(checkholelength(height, width, i-1, pixels)>=longest){
            longest=checkholelength(height, width, i-1, pixels);
            longestindex=i-1;
        }
        else{
            islongest=1;
        }
        i--;
    }
    while(j<width){
        if(pixels[longestindex][j]==1 && checkstart==0){
            checkstart=1;
        }
        if(pixels[longestindex][j]==0 && (checkstart==1 || checkstart==2)){
            checkstart=2;
            if(checkupper(height, width, longestindex, j, pixels, startendindex)>2){
                is6=1;
            }
        }
        if(pixels[longestindex][j]==1 && checkstart==2){
            checkstart=3;
        }
        j++;
    }
    //printf("%d\n", longestindex);
    return is6;
}
int checkholelength(int height, int width, int checkline, int pixels[height][width]){
    int length=0, j=0, checkstart=0;
    while(j<width){
        if(pixels[checkline][j]==1 && checkstart==0){
            checkstart=1;
        }
        if(pixels[checkline][j]==0 && (checkstart==1 || checkstart==2)){
            checkstart=2;
            length++;
        }
        if(pixels[checkline][j]==1 && checkstart==2){
            checkstart=3;
        }
        j++;
    }
    return length;
}
int checkupper(int height, int width, int checkline, int checkindex, int pixels[height][width], int startendindex[2]){
    int checkstart=0, change=0;
    while(checkline<height){
        if(pixels[checkline][checkindex]==0 && checkstart==0){
            checkstart=1;
        }
        if(pixels[checkline][checkindex]==1 && checkstart==1){
            checkstart=2;
        }
        if((checkline!=0) && (pixels[checkline][checkindex] != pixels[checkline-1][checkindex]) && checkstart==2 && checkline>startendindex[1]){
            change++;
        }
        if(pixels[checkline][checkindex]==1 && checkline==height-1){
            change++;
        }
        checkline++;
    }
    return change;
}
