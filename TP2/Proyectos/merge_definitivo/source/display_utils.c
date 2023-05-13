#include "display_utils.h"

void print_image(uint8_t x0, uint8_t y0, unsigned char* image, uint8_t width_in_px, uint8_t height_in_px) {
    
    int width_in_bytes = width_in_px * 8;
    int array_length = width_in_px * height_in_px / 8;
    
    int row_pos = 0;
    for (int i = 0; i < array_length; i++) {
        
        //Avanzar a la fila inferior del display
        if ((i % width_in_bytes) == 0 && i > 0) {
            row_pos++;
        }

        //Imprimir 8 pixeles
        unsigned char img_segment = image[i];
        for (int k = 7; k >= 0; k--)
        {
            char pixel_value = (image[i] >> k) & 0x01;
            oled_color_t pixel_color = (pixel_value) ? OLED_COLOR_WHITE : OLED_COLOR_BLACK;
            
            uint8_t bit_offset = (7 - k);
            uint8_t segment_offset = (i % width_in_bytes) * 8;
            uint8_t x = x0 + segment_offset + bit_offset;

            uint8_t y = y0 + row_pos;
            
            led_putPixel(x, y, pixel_color);
        }
    }
}

void print_falling_state() {
    print_image(32, 0, coyote_cayendo, 64, 64);
}

void print_accel_display_state(float acceleration) {
    print_image(32, 0, coyote_golpeado, 64, 64);

    char c[4];
    sprintf(c, "%.2f", acceleration);
    oled_putString(88, 8, (uint8_t*)c, OLED_COLOR_WHITE, OLED_COLOR_BLACK);
}