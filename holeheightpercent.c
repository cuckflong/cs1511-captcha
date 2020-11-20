#include<stdio.h>
#include"captcha.h"

double holeheightpercent(int height, int startendindex[2]);

double holeheightpercent(int height, int startendindex[2]){
    double percent;
    percent=(double)(startendindex[1]-startendindex[0]+1)/(double)(height);
    return percent;
}
