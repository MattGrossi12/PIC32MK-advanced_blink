/* 
 * File:   blink.c
 * Author: matheus
 *
 * Created on February 27, 2026, 5:19 PM
 */

#include <xc.h>
#include <stdint.h>
#include <sys/attribs.h>
#include "aux_func.h"

void blink_led(void)
{
    // Forca nivel logico baixo:
    LATBbits.LATB10 = 0;

    // Tempo de espera:
    delay_ms(2000);

    // Forca nivel logico alto:
    LATBbits.LATB10 = 1;

    // Tempo de espera:
    delay_ms(2000);
}