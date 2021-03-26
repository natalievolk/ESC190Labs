#include "c_img.h"
#include <stdio.h>
#include <math.h>

int main(){
    struct rgb_img **im;
    char file[200] = "C:\\Users\\qingy\\OneDrive\\Documents\\Year_1\\Sem_2\\ESC190-C\\Lab7\\3x4.bin";

    read_in_img(im, file);
    for(int i = 0; i < (*im)->height; i++){
        for(int j = 0; j < (*im)->width; j++){
            float scale = 3;
            uint8_t red = (int) scale * get_pixel(*im, i, j, 0);
            uint8_t green = (int) scale * get_pixel(*im, i, j, 1);
            uint8_t blue = (int) scale * get_pixel(*im, i, j, 2);
            
            if ((int)(red) > 255) {red = 255;}
            if ((int)(green) > 255) {green = 255;}
            if ((int)(blue) > 255) {blue = 255;}

            set_pixel(*im, i, j, (int)red, (int)green, (int)blue);

            write_img(*im, "C:\\Users\\qingy\\OneDrive\\Documents\\Year_1\\Sem_2\\ESC190-C\\Lab7\\20_scale2.bin");
            
        }
    }
    //set_pixel(struct rgb_img *im, int y, int x, int r, int g, int b)
    destroy_image(*im);
    return 0;
}