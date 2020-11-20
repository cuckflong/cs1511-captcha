#include <stdio.h>
#include "captcha.h"

int main(int argc, char *argv[]) {
    int height, width, start_row, start_column, box_width, box_height;
    double vbalance, hbalance;
    int result;
    double get_vertical_balance(int height, int width, int pixels[height][width]);
    int haveo(int height, int width, int pixels[height][width], int startendindex[2]);
    double get_horizontal_balance(int height, int width, int pixels[height][width]);
    void fillgaps(int height, int width, int pixels[height][width]);
    int check6(int height, int width, int pixels[height][width], int startendindex[2]);
    double holefraction(int height, int width, int pixels[height][width], int startendindex[2]);
    double holeheightpercent(int height, int startendindex[2]);
    int check235(int height, int width, int pixels[height][width]);
    void verticalgaps(int height, int width, int pixels[height][width], int a);
    void slice(int height, int width, int pixels[height][width]);
    int check2(int height, int width, int pixels[height][width]);
    int check3(int height, int width, int pixels[height][width]);
    int check5(int height, int width, int pixels[height][width]);
    int check49(int height, int width, int pixels[height][width]);
    int startendindex[2]={0};
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }
    
    if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
        return 1;
    }
    
    int pixels[height][width];
    if (read_pbm(argv[1], height, width, pixels)) {
        get_bounding_box(height, width, pixels, &start_row, &start_column, &box_height, &box_width);
        
        int box_pixels[box_height][box_width];
        copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, box_pixels);
        vbalance = get_vertical_balance(box_height, box_width, box_pixels);
        //printf("%f\n", vbalance);
        
        result = haveo(box_height, box_width, box_pixels, startendindex);
        //printf("Box width: %d\n", box_width);
        
        if(result == 1 && check6(box_height, box_width, box_pixels, startendindex)==0){
            if(holeheightpercent(box_height, startendindex)>0.58){
                printf("0\n");
                //printf("Hole: %d\n", result);
                return 0;
            }
            
        }
        //printf("%d\n", check235(box_height, box_width, box_pixels));
        //return 0;
        fillgaps(box_height, box_width, box_pixels);
        result = haveo(box_height, box_width, box_pixels, startendindex);
        if(result==2){
            printf("8\n");
            return 0;
        }
        
        verticalgaps(box_height, box_width, box_pixels, 2);
        slice(box_height, box_width, box_pixels);
        
        if(result == 1 && check6(box_height, box_width, box_pixels, startendindex)==1){
            printf("6\n");
            //printf("Hole: %d\n", result);
            return 0;
        }
        //printf("%f\n", holefraction(box_height, box_width, box_pixels, startendindex));
        //return 0;
        if(result==1 && (check49(box_height, box_width, box_pixels)==1 || holefraction(box_height, box_width, box_pixels, startendindex)<=0.09)){
            printf("4\n");
            return 0;
        }
        if(result==1 && check49(box_height, box_width, box_pixels)==0){
            printf("9\n");
            return 0;
        }
        if(result==0){
            if(check235(box_height, box_width, box_pixels)==0 && get_vertical_balance(box_height, box_width, box_pixels)<=0.54){
                printf("1\n");
                return 0;
            }
            if(check235(box_height, box_width, box_pixels)==0 && get_vertical_balance(box_height, box_width, box_pixels)>0.54){
                printf("7\n");
                return 0;
            }
            //verticalgaps(box_height, box_width, box_pixels,2);
            //slice(box_height, box_width, box_pixels);
            fillgaps(box_height, box_width-1, box_pixels);
            hbalance=get_horizontal_balance(box_height, box_width, box_pixels);
            //printf("%f\n", hbalance);
            if(result==0 && check3(box_height, box_width, box_pixels)==1 && hbalance>=0.52){
                printf("3\n");
                return 0;
            }
            if(result==0 && check2(box_height, box_width, box_pixels)==1){
                printf("2\n");
                return 0;
            }
            if(result==0 && check5(box_height, box_width, box_pixels)==1){
                printf("5\n");
                return 0;
            }
            else{
                printf("1\n");
                return 0;
            }
        }
    }
    return 0;
}
