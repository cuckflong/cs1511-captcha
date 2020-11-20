#include<stdio.h>
#include"captcha.h"

int captchadigitcrack(int box_height, int box_width, int box_pixels[box_height][box_width]){
    int result=0;
    double vbalance, hbalance;
    double get_vertical_balance(int height, int width, int pixels[height][width]);
    
    int startendindex[2]={0};
    vbalance = get_vertical_balance(box_height, box_width, box_pixels);
    //printf("%f\n", vbalance);
    
    result = haveo(box_height, box_width, box_pixels, startendindex);
    //printf("Box width: %d\n", box_width);
    
    if(result == 1 && check6(box_height, box_width, box_pixels, startendindex)==0){
        if(holeheightpercent(box_height, startendindex)>0.58){
            //printf("0\n");
            //printf("Hole: %d\n", result);
            return 0;
        }
        
    }
    //printf("%d\n", check235(box_height, box_width, box_pixels));
    //return 0;
    fillgaps(box_height, box_width, box_pixels);
    result = haveo(box_height, box_width, box_pixels, startendindex);
    if(result==2){
        //printf("8\n");
        return 8;
    }
    
    verticalgaps(box_height, box_width, box_pixels, 2);
    slice(box_height, box_width, box_pixels);
    
    if(result == 1 && check6(box_height, box_width, box_pixels, startendindex)==1){
        //printf("6\n");
        //printf("Hole: %d\n", result);
        return 6;
    }
    //printf("%f\n", holefraction(box_height, box_width, box_pixels, startendindex));
    //return 0;
    if(result==1 && (check49(box_height, box_width, box_pixels)==1 || holefraction(box_height, box_width, box_pixels, startendindex)<=0.09)){
        //printf("4\n");
        return 4;
    }
    if(result==1 && check49(box_height, box_width, box_pixels)==0){
        //printf("9\n");
        return 9;
    }
    if(result==0){
        if(check235(box_height, box_width, box_pixels)==0 && get_vertical_balance(box_height, box_width, box_pixels)<=0.54){
            //printf("1\n");
            return 1;
        }
        if(check235(box_height, box_width, box_pixels)==0 && get_vertical_balance(box_height, box_width, box_pixels)>0.54){
            //printf("7\n");
            return 7;
        }
        //verticalgaps(box_height, box_width, box_pixels,2);
        //slice(box_height, box_width, box_pixels);
        fillgaps(box_height, box_width-1, box_pixels);
        hbalance=get_horizontal_balance(box_height, box_width, box_pixels);
        //printf("%f\n", hbalance);
        if(result==0 && check3(box_height, box_width, box_pixels)==1 && hbalance>=0.52){
            //printf("3\n");
            return 3;
        }
        if(result==0 && check2(box_height, box_width, box_pixels)==1){
            //printf("2\n");
            return 2;
        }
        if(result==0 && check5(box_height, box_width, box_pixels)==1){
            //printf("5\n");
            return 5;
        }
        else{
            //printf("1\n");
            return 1;
        }
    }
    return 1;
}
