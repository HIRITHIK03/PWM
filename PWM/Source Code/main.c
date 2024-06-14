#include "GPIO_F_Init.h"
#include "PWM0_Init.h"

int main(void)
{
    // GPIO Port F Initialization
    GPIO_F_Init();

    // PWM0 Initialization
    PWM0_Init();

    while(1) {
        // Infinite loop
    }
}
