int read_pbm(char filename[], int height, int width, int pixels[height][width]);
int get_pbm_dimensions(char filename[], int *height, int *width);
void print_image(int height, int width, int pixels[height][width]);
void get_bounding_box(int height, int width, int pixels[height][width],
                      int *start_row, int *start_column, int *box_height, int *box_width);
void copy_pixels(int height, int width, int pixels[height][width],
                 int start_row, int start_column, int copy_height, int copy_width,
                 int copy[copy_height][copy_width]);
double get_horizontal_balance(int height, int width, int pixels[height][width]);
double get_vertical_balance(int height, int width, int pixels[height][width]);
int haveo(int height, int width, int pixels[height][width], int startendindex[2]);
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
double check1(int height, int width, int pixels[height][width]);
