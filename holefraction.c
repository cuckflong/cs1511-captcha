#include<stdio.h>
#include"captcha.h"

double holefraction(int height, int width, int pixels[height][width], int startendindex[2]);

double holefraction(int height, int width, int pixels[height][width], int startendindex[2]){
    int i=startendindex[0], j=0, checkstart=0, holeptcount=0, onecount=0;
    while(i<=startendindex[1]){
        j=0;
        checkstart=0;
        while(j<width){
            if(pixels[i][j]==1 && checkstart==0){
                checkstart=1;
            }
            if(pixels[i][j]==0 && (checkstart==1 || checkstart==2)){
                checkstart=2;
                holeptcount++;
            }
            if(pixels[i][j]==1 && checkstart==2){
                checkstart=3;
            }
            j++;
        }
        i++;
    }
    i=0;
    j=0;
    while(i<height){
        j=0;
        while(j<width){
            if(pixels[i][j]==1){
                onecount++;
            }
            j++;
        }
        i++;
    }
    return (double)(holeptcount)/(double)(onecount);
}
