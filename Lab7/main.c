#include "c_img.h"
#include <stdio.h>
#include <math.h>

int main(){
    struct rgb_img *im;
    char file[200] = "3x4.bin";

    read_in_img(&im, file);
    for(int i = 0; i < (im)->height; i++){
        for(int j = 0; j < (im)->width; j++){
            float scale = 1.2;
            int red = (int) (scale * get_pixel(im, i, j, 0));
            int green = (int) (scale * get_pixel(im, i, j, 1));
            int blue = (int) (scale * get_pixel(im, i, j, 2));
            
            if (red > 255) {red = 255;}
            if (green > 255) {green = 255;}
            if (blue > 255) {blue = 255;}

            set_pixel(im, i, j, (int)red, (int)green, (int)blue);            
        }
    }
    write_img(im, "scale1.bin");
    //set_pixel(struct rgb_img *im, int y, int x, int r, int g, int b)
    destroy_image(im);
    return 0;
}