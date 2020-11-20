#include<stdio.h>
#include"captcha.h"

double check1(int height, int width, int pixels[height][width]);

double check1(int height, int width, int pixels[height][width]){
    int i=height/3, j=0, changes=0, num=0, start=1, times=0;
    while(i<height/3+3){
        j=0;
        while(j<width){
            if(pixels[i][j]==1){
                if(start==1){
                    num=j;
                    start=0;
                }
                else{
                    if(j!=num){
                        if(j-num>0){
                            changes=changes+(j-num);
                            num=j;
                            times++;
                        }
                        else{
                            changes=changes-(j-num);
                            num=j;
                            times++;
                        }
                    }
                }
                j=width;
            }
            j++;
        }
        i++;
    }
    if(times==0){
        return 0;
    }
    return (double)(changes)/(double)(times);
}
