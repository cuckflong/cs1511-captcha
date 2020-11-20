#include <stdio.h>
#include "captcha.h"

int main(int argc, char *argv[]) {
    int height, width, start_row, start_column, box_width, box_height, i=0, j=0, check=1, box1start=0, box1end=0, box2start=0, box2end=0, box3start=0, box3end=0, box4start=0, box4end=0, no1=1;
    double balance;
    int captchadigitcrack(int box_height, int box_width, int box_pixels[box_height][box_width]);
    
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
        
        while(j<box_width){
            i=0;
            no1=1;
            while(i<box_height){
                if(box_pixels[i][j]==1 && check==1){
                    box1start=j;
                    check=2;
                }
                if(box_pixels[i][j]==1 && check==3){
                    box2start=j;
                    check=4;
                }
                if(box_pixels[i][j]==1 && check==5){
                    box3start=j;
                    check=6;
                }
                if(box_pixels[i][j]==1 && check==7){
                    box4start=j;
                    check=8;
                }
                if(box_pixels[i][j]==1){
                    no1=0;
                }
                i++;
            }
            if(no1==1 && check==2){
                box1end=j-1;
                check=3;
            }
            if(no1==1 && check==4){
                box2end=j-1;
                check=5;
            }
            if(no1==1 && check==6){
                box3end=j-1;
                check=7;
            }
            if(j==box_width-1 && check==8){
                box4end=j;
                check=9;
            }
            j++;
        }
        int box1_pixels[box_height][box1end-box1start+1];
        copy_pixels(box_height, box_width, box_pixels, 0, box1start, box_height, box1end-box1start+1, box1_pixels);
        //print_image(box_height, box1end-box1start+1, box1_pixels);
        printf("%d", captchadigitcrack(box_height, box1end-box1start+1, box1_pixels));
        int box2_pixels[box_height][box2end-box2start+1];
        copy_pixels(box_height, box_width, box_pixels, 0, box2start, box_height, box2end-box2start+1, box2_pixels);
        //print_image(box_height, box2end-box2start+1, box2_pixels);
        printf("%d", captchadigitcrack(box_height, box2end-box2start+1, box2_pixels));
        int box3_pixels[box_height][box3end-box3start+1];
        copy_pixels(box_height, box_width, box_pixels, 0, box3start, box_height, box3end-box3start+1, box3_pixels);
        printf("%d", captchadigitcrack(box_height, box3end-box3start+1, box3_pixels));
        int box4_pixels[box_height][box4end-box4start+1];
        copy_pixels(box_height, box_width, box_pixels, 0, box4start, box_height, box4end-box4start+1, box4_pixels);
        printf("%d\n", captchadigitcrack(box_height, box4end-box4start+1, box4_pixels));
    }
    return 0;
}
