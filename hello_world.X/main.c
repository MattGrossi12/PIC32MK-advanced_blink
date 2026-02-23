/* * File:   main.c
 * Author: Matheus Grossi
 * Created on 13 de Fevereiro de 2026, 14:11
 */

// 1. DEFINA A MACRO AQUI para ativar os config bits do defs.h
#define _CONFIG_BITS_SOURCE 

#include "defs.h"

#include <xc.h>
#include <stdint.h>
#include <sys/attribs.h>

#define SYSCLK_HZ 12000000UL   // ajuste para o clock REAL do seu projeto

static void delay_ms(uint32_t ms)
{
    // CP0 Count geralmente incrementa a SYSCLK/2
    const uint32_t ticks_per_ms = (SYSCLK_HZ / 2U) / 1000U;
    uint32_t start = _CP0_GET_COUNT();
    uint32_t wait  = ticks_per_ms * ms;

    while ((uint32_t)(_CP0_GET_COUNT() - start) < wait) { }
}

int main(void)
{
    // garante JTAG desligado em runtime também
    CFGCONbits.JTAGEN = 0;

    // RB10 como saída
    TRISBCLR = (1u << 10);

    // inicia em LOW
    LATBCLR = (1u << 10);

    while (1)
    {
        // 2. CORREÇÃO DO TOGGLE:
        // LATBINV inverte o bit passado. Para inverter sempre, 
        // basta mandar 1 na posição 10 a cada ciclo.
        LATBINV = (1u << 10);   // Inverte o estado atual do RB10
        delay_ms(500);
    }
}
