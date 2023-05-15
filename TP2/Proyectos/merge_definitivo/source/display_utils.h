#ifndef __DISPLAY_UTILS_H
#define __DISPLAY_UTILS_H

/*==================[inclusions]=============================================*/

#include <stdint.h>
#include "font5x7.h"
#include "coyote.h"
#include "oled.h"

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions definition]==========================*/

void print_image(uint8_t x0, uint8_t y0, unsigned char* image, uint8_t width_in_px, uint8_t height_in_px);
void print_falling_state(void);
void print_accel_display_state(int acceleration);

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif

#endif /* end __DISPLAY_UTILS_H */
