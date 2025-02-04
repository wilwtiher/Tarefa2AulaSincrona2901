#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Define os pinos dos LEDs (configurados conforme o Wokwi/BitDogLab)
#define LED_PIN_RED    11
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN  13

// Enum para identificar os estados do semáforo
typedef enum {
    ESTADO_RED,
    ESTADO_YELLOW,
    ESTADO_GREEN
} semaforo_state_t;

// Variável para armazenar o estado atual do semáforo
semaforo_state_t current_state = ESTADO_RED;

// Callback do temporizador que é chamado a cada 3 segundos
bool repeating_timer_callback(struct repeating_timer *t) {
    // Troca o estado do semáforo e atualiza os LEDs
    switch(current_state) {
        case ESTADO_GREEN:
            // Acende o LED vermelho e apaga os demais
            gpio_put(LED_PIN_RED, 1);
            gpio_put(LED_PIN_YELLOW, 0);
            gpio_put(LED_PIN_GREEN, 0);
            current_state = ESTADO_RED;
            break;
        case ESTADO_RED:
            gpio_put(LED_PIN_RED, 0);
            gpio_put(LED_PIN_YELLOW, 1);
            gpio_put(LED_PIN_GREEN, 0);
            current_state = ESTADO_YELLOW;
            break;
        case ESTADO_YELLOW:
            gpio_put(LED_PIN_RED, 0);
            gpio_put(LED_PIN_YELLOW, 0);
            gpio_put(LED_PIN_GREEN, 1);
            current_state = ESTADO_GREEN;
            break;
    }
    printf("Mudança de estado do semaforo\n");
    // Retorna true para que o temporizador continue repetindo
    return true;
}

int main() {
    // Inicializa a comunicação serial
    stdio_init_all();

    // Inicializa e configura os pinos dos LEDs como saída
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);
    
    // Começa o programa com o led verde ligado
    gpio_put(LED_PIN_RED, 1);
    gpio_put(LED_PIN_YELLOW, 0);
    gpio_put(LED_PIN_GREEN, 0);
    current_state = ESTADO_RED;

    // Configura o temporizador para chamar a callback a cada 3000 ms (3 segundos)
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    // Loop principal: imprime uma mensagem a cada 1 segundo
    while (true) {
        printf("Mensagem do loop principal (a cada 1 segundo).\n");
        sleep_ms(1000);
    }
    
    return 0;
}
