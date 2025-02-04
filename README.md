# Aluno: Wilton Lacerda Silva Júnior
## Grupo 6 Subgrupo 5
# Tarefa 1: Semáforo com Temporizador Repetitivo.

Este projeto implementa um semáforo utilizando o SDK do Raspberry Pi Pico e a placa BitDogLab. Através de um temporizador repetitivo (função `add_repeating_timer_ms()`), os LEDs são alternados a cada 3 segundos, de maneira funcional de um semáforo. Enquanto isso, o loop principal imprime uma mensagem a cada 1 segundo na saída serial.

## Funcionalidades

- **Semáforo:**  
  - **Estado Inicial:** O semáforo inicia com o LED verde ligado.
  - **Transição de Estados:**  
    - Quando o LED verde está aceso, a próxima transição acende o LED vermelho.
    - Quando o LED vermelho está aceso, a próxima transição acende o LED amarelo.
    - Quando o LED amarelo está aceso, a próxima transição acende o LED verde.
  - Essa sequência se repete indefinidamente a cada 3 segundos.

- **Mensagens na Serial:**  
  O loop principal do programa imprime uma mensagem a cada 1 segundo, permitindo acompanhar a execução do código.

## Hardware Utilizado

- **Placa:** BitDogLab (ou Raspberry Pi Pico adaptado)
- **Componentes Wokwi:**  
  - LED Vermelho no GPIO 11
  - LED Amarelo no GPIO 12
  - LED Verde no GPIO 13
  - 3 Resistores de 330 ohms
  - Placa Raspberry Pi Pico

## Instruções de uso

  - **Placa BitDogLab:**
    Para usar na placa BitDogLab, o programa deve ser importado no Visual Studio Code com a extensão do Raspberry Pi Pico, conectar a placa no computador no modo de bootloader, e clicar na opção "Run". Para verificar a saída serial, deve iniciar o Serial Monitor.

- **Wokwi:**
  Para usar no simulador wokwi, deve seguir os mesmos passos descritos anteriormente, porém com a extensão wokwi instalada. Quando abrir o programa no VsCode, clicar sobre o diagram.json, compilar o programa, e clicar na seta para rodar o programa no simulador.
