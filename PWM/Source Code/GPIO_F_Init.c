#include <stdint.h>

// System Control Registers
#define SYSCTL_RCGCGPIO       (*((volatile uint32_t *)0x400FE608))

// GPIO Port F Registers
#define GPIOF_AFSEL        (*((volatile uint32_t *)0x4005D420U)) // GPIO Alternate Function Select
#define GPIOF_PCTL         (*((volatile uint32_t *)0x4005D52CU))  // GPIO Port Control
#define GPIOF_DEN          (*((volatile uint32_t *)0x4005D51CU))  // GPIO Digital Enable
#define GPIOF_DIR          (*((volatile uint32_t *)0x4005D400U))  // GPIO Direction

//GPIO Port F Initialization
void GPIO_F_Init()
{
    // Enable Port F clock
    SYSCTL_RCGCGPIO |= 0x20;

    // Configure PF0 for PWM output
    GPIOF_DIR |= 0x01U;        // Set PF0 as output
    GPIOF_AFSEL |= 0x01U;      // Enable alternate function on PF0
    GPIOF_PCTL = (GPIOF_PCTL & ~0x0000000F) | 0x00000006U; // Configure PF0 for PWM
    GPIOF_DEN |= 0x01U;        // Enable digital I/O on PF0
}

