#### Para dúvidas, comentários ou sugestões fiquem à vontade, estarei à disposição através de minha página: 

[Matheus Grossi](https://www.linkedin.com/in/matheus-grossi/)

# Projeto de Blink Simples - PIC32MK (Versão Modular)

## Descrição
Este projeto é um exemplo prático de inicialização, configuração de hardware e alternância de estado de um pino (Blink) em um microcontrolador da família PIC32MK. O código configura o pino **RB10** como saída e intercala os níveis lógicos alto e baixo a cada **2000 milissegundos**, utilizando o compilador XC32.

**Autor:** Matheus Grossi
**Data:** 13 de Fevereiro de 2026

## Hardware Alvo
* **Microcontrolador:** PIC32MK0128MCA048
* **Pino de Saída (LED/Sinal):** RB10
* **Frequência de Clock de Sistema (`SYSCLK`):** 12 MHz (12000000 Hz)

## Circuito rodando em bancada:

<div align="center">
 
| **Ação** |
| :--- |
| Estado desligado |
|![Estado desligado](https://github.com/MattGrossi12/PIC32MK-advanced_blink/blob/main/blink_state_0.jpeg)|
| Estado ligado |
|![Estado ligado](https://github.com/MattGrossi12/PIC32MK-advanced_blink/blob/main/blink_state_1.jpeg)|

</div>

<div align="justify">
 
## Estrutura do Projeto

O projeto foi organizado de forma modular para facilitar a manutenção e escalabilidade:

* **`defs.h`**: Centraliza os *Configuration Bits* (`#pragma config`) e definições globais como a frequência de clock.
* **`main.c`**: Ponto de entrada que coordena a inicialização do hardware e executa o loop principal (`blink_led`).
* **`pin_declaration.c`**: Responsável pela configuração dos periféricos e I/Os, incluindo a desativação do JTAG para liberar os pinos.
* **`aux_func.c`**: Contém funções utilitárias, como o controle de tempo preciso via hardware.
* **`blink.c`**: Implementa a lógica específica de alternância do estado do LED.

## Detalhes de Implementação

### Função de Atraso Exata (`delay_ms`)
A função de atraso utiliza o **Core Timer** do núcleo MIPS (Coprocessador 0). O registrador `_CP0_GET_COUNT()` incrementa na taxa de `SYSCLK / 2`. A função calcula os *ticks* necessários para o tempo em milissegundos solicitado, garantindo um bloqueio preciso sem depender de timers periféricos.

### Inicialização e Configuração
* **JTAG**: Desabilitado tanto via *Configuration Bits* quanto em tempo de execução no `pins_init` (`CFGCONbits.JTAGEN = 0`) para garantir o uso pleno das portas de I/O.
* **Modo de Saída**: O pino RB10 é configurado como saída através do registrador `TRISBbits.TRISB10 = 0`.

### Lógica do Loop Principal
A lógica de blink reside em uma função dedicada que executa as seguintes etapas:
1. Define o pino RB10 como nível baixo (`0`).
2. Aguarda 2000 ms.
3. Define o pino RB10 como nível alto (`1`).
4. Aguarda 2000 ms.

## Como Utilizar e Compilar

1. Crie um novo projeto no **MPLAB X IDE**.
2. Adicione todos os arquivos `.c` à pasta *Source Files* e os arquivos `.h` à pasta *Header Files*.
3. Certifique-se de que o compilador **Microchip XC32** está selecionado nas propriedades.
4. A macro `_CONFIG_BITS_SOURCE` deve permanecer definida no topo do `main.c` para que as configurações do `defs.h` sejam aplicadas corretamente.
5. Compile e grave o firmware no microcontrolador.

</div>