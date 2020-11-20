#include<stdio.h>
#include"captcha.h"

void verticalgaps(int height, int width, int pixels[height][width], int a);

void verticalgaps(int height, int width, int pixels[height][width], int a){
    int i=0, j=0, k=0, countstart=0, gapsnum=0;
    int gaps[5]={0};
    while(j<width){
        i=0;
        countstart=0;
        gapsnum=0;
        if(pixels[i][j]==1){
            countstart=1;
        }
        while(i<height){
            if(gapsnum<=a && pixels[i][j]==0 && countstart==1){
                k=0;
                while(k<gapsnum){
                    pixels[gaps[k]][j]=0;
                    k++;
                }
            }
            if(pixels[i][j]==0 && countstart==1){
                countstart=0;
                gapsnum=0;
            }
            if(gapsnum==a){
                countstart=0;
                gapsnum=0;
            }
            if(pixels[i][j]==0 && countstart==0){
                countstart=1;
            }
            if(pixels[i][j]==1 && countstart==1){
                gaps[gapsnum]=i;
                gapsnum++;
            }
            i++;
        }
        j++;
    }
    i=0;
    j=0;
    k=0;
    countstart=0;
    gapsnum=0;
    while(j<width){
        i=0;
        countstart=0;
        gapsnum=0;
        while(i<height){
            if(gapsnum<=a && pixels[i][j]==1 && countstart==1){
                k=0;
                while(k<gapsnum){
                    pixels[gaps[k]][j]=1;
                    k++;
                }
            }
            if(pixels[i][j]==1 && countstart==1){
                countstart=0;
                gapsnum=0;
            }
            if(gapsnum==a){
                countstart=0;
                gapsnum=0;
            }
            if(pixels[i][j]==1 && countstart==0){
                countstart=1;
            }
            if(pixels[i][j]==0 && countstart==1){
                gaps[gapsnum]=i;
                gapsnum++;
            }
            i++;
        }
        j++;
    }
}
