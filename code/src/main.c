#include "main.h"

void gpio_init();
void vTaskLed(void *argument);
void vTaskLed1(void *argument);
int main(void) {
	gpio_init();
	xTaskCreate(vTaskLed, "vTaskLed", 32, NULL, 1, NULL);
	// xTaskCreate(vTaskLed1, "vTaskLed1", 130, NULL, 2, NULL);
	vTaskStartScheduler();
	while(1){
		GPIOA->BSRR |= GPIO_BSRR_BS5;
	}

}

void gpio_init() {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODE5_0;
}

void vTaskLed(void *argument){

	while(1){
		GPIOA->BSRR |= GPIO_BSRR_BS5;
		vTaskDelay(500);
		GPIOA->BSRR |= GPIO_BSRR_BR5;
		vTaskDelay(500);
	}
}
void vTaskLed1(void *argument){
	while(1){

	}
}
