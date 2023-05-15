#include "display_utils.h"
#include "oled.h"
#include <stdio.h>
#include "fsl_debug_console.h"

void print_image(uint8_t x0, uint8_t y0, unsigned char* image, uint8_t width_in_px, uint8_t height_in_px)
{
    int width_in_bytes = width_in_px / 8;
    int array_length = width_in_px * height_in_px / 8;
    
    int row_pos = 0;

    oled_clearScreen(OLED_COLOR_BLACK);

    for (int i = 0; i < array_length; i++) {
        
        //Avanzar a la fila inferior del display
        if ((i % width_in_bytes) == 0 && i > 0) {
            row_pos++;
        }

        //Imprimir 8 pixeles
        //unsigned char img_segment = image[i];
        for (int k = 7; k >= 0; k--)
        {
            char pixel_value = (image[i] >> k) & 0x01;
            oled_color_t pixel_color = (pixel_value) ? OLED_COLOR_WHITE : OLED_COLOR_BLACK;
            
            uint8_t bit_offset = (7 - k);
            uint8_t segment_offset = (i % width_in_bytes) * 8;
            uint8_t x = x0 + segment_offset + bit_offset;

            uint8_t y = y0 + row_pos;
            
            oled_putPixel(x, y, pixel_color);
        }
    }
}

void display_fallingState() {
    print_image(32, 0, coyote_cayendo, 64, 64);
}

void display_sleepingState() {
    print_image(8, 0, coyote_durmiendo, 96, 64);
}

void display_accelDisplayState(int acceleration) {
    print_image(32, 0, coyote_golpeado, 64, 64);

    char completo[5], entero[3], decimales[3], a_imprimir[6];

    sprintf(completo, "%d", acceleration);

    if(strlen(completo) > 3)
    {
    	// Es un número de dos sifras con 2 decimales xx.yy
    	entero[0] = completo[0];
    	entero[1] = completo[1];
    	entero[2] = 0;

    	decimales[0] = completo[2];
    	decimales[1] = completo[3];
    	decimales[2] = 0;
    }
    else
    {
    	// Es un número de 1 sifra con 2 decimales x.yy

    	entero[0] = completo[0];
    	entero[1] = 0;

    	decimales[0] = completo[1];
    	decimales[1] = completo[2];
    	decimales[2] = 0;
    }

    sprintf(a_imprimir, "%s.%s", entero, decimales);
    //oled_putString(88, 8, (uint8_t*)c, OLED_COLOR_WHITE, OLED_COLOR_BLACK);
    oled_putString(88, 8, (uint8_t*)a_imprimir, OLED_COLOR_WHITE, OLED_COLOR_BLACK);
}
