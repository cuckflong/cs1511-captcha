#include <stdio.h>
#include "captcha.h"

int main(int argc, char *argv[]) {
    int height, width, start_row, start_column, box_width, box_height;
    double balance;
    double get_vertical_balance(int height, int width, int pixels[height][width]);

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
        
        balance = get_vertical_balance(box_height, box_width, box_pixels);
        
        printf("Vertical balance %.3lf\n", balance);
    }
    return 0;
}
