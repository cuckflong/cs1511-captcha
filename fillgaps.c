#include<stdio.h>
#include"captcha.h"

void fillgaps(int height, int width, int pixels[height][width]);

void fillgaps(int height, int width, int pixels[height][width]){
    int i=0, j=0, k=0, countstart=0, gapsnum=0;
    int gaps[2]={0};
    while(i<height){
        j=0;
        countstart=0;
        gapsnum=0;
        while(j<width){
            if(gapsnum<=2 && pixels[i][j]==1 && countstart==1){
                k=0;
                while(k<gapsnum){
                    pixels[i][gaps[k]]=1;
                    k++;
                }
            }
            if(pixels[i][j]==1 && countstart==1){
                countstart=0;
                gapsnum=0;
            }
            if(gapsnum==2){
                countstart=0;
                gapsnum=0;
            }
            if(pixels[i][j]==1 && countstart==0){
                countstart=1;
            }
            if(pixels[i][j]==0 && countstart==1){
                gaps[gapsnum]=j;
                gapsnum++;
            }
            j++;
        }
        i++;
    }
}
