/* 
 * File:   main.c
 * Author: Matheus Grossi
 * Created on 13 de Fevereiro de 2026, 14:11
 */

// 1. DEFINA A MACRO AQUI para ativar os config bits do defs.h
#define _CONFIG_BITS_SOURCE 

// PIC LIBS:
#include <xc.h>
#include <stdint.h>
#include <sys/attribs.h>

// OURS LIBS:
#include "defs.h"
#include "pin_declaration.h"
#include "aux_func.h"
#include "blink.h"

/*
Anotacoes importantes:
    Os pinos do Header1 reservados para a UART, sao:

    - RC0 -> RX
    - RC1 -> TX
*/

//=============================================================================
// Funcao principal:
int main(void)
{
    // Inicializa pinos (antes de usar qualquer um deles)
    pins_init();

    // Chama o loop:
    while (operation)
    {
        blink_led();
    }

    // Opcional: nunca chega aqui
    return 0;
}