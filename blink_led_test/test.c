#include <test.h>
uint32_t pin_num = 16;
OM_GPIO_Type *om_gpio=OM_GPIO0;

void led_thread(void *param){
	while(1){
		osDelay(osMS2TicksRound(500));
		gpio_write(om_gpio,GPIO_MASK(pin_num%32),0);
		osDelay(osMS2TicksRound(500));
		gpio_write(om_gpio,GPIO_MASK(pin_num%32),1);
	}
}

void led_thread_init(void)
{
    osThreadId_t        led_thread_id;
    static const osThreadAttr_t led_thread_thread_attr = {
        .name       = "led_thread",
        .priority   = osPriorityNormal,
        .stack_size = 4096U,
    };
		const pin_config_t pin_config =  {pin_num,{PINMUX_PAD16_GPIO0_16_CFG},   PMU_PIN_MODE_PP, PMU_PIN_DRIVER_CURRENT_MAX, PMU_PIN_VOLTAGE_3_3};
		const gpio_config_t gpio_config = {om_gpio,pin_num%32,GPIO_DIR_OUTPUT, 1, GPIO_TRIG_NONE};
		pin_init(&pin_config,1);
		gpio_init(&gpio_config,1);
    led_thread_id = osThreadNew(led_thread, NULL, &led_thread_thread_attr);
    OM_ASSERT(led_thread_id);
}