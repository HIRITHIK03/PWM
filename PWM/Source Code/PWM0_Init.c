#include <stdint.h>

// Memory-mapped register addresses for PWM
#define SYSCTL_RCGCPWM     (*((volatile uint32_t *)0x400FE640U))  // Enable clock for PWM

// PWM0 Registers

#define PWM_CTL            (*((volatile uint32_t *)0x40028040U))  // PWM Control
#define PWM0_LOAD          (*((volatile uint32_t *)0x40028050U))  // PWM Load
#define PWM0_CMPA0         (*((volatile uint32_t *)0x40028058U))  // PWM Compare A
#define PWM0_CMPB0         (*((volatile uint32_t *)0x4002805CU))  // PWM Compare B
#define PWM0_GENA0         (*((volatile uint32_t *)0x40028060U))  // PWM Generator A
#define PWM0_GENB0         (*((volatile uint32_t *)0x40028064U))  // PWM Generator B
#define PWM_ENABLE         (*((volatile uint32_t *)0x40028008U))  // PWM Enable

void PWM0_Init()
{
    // Enable Clock for PWM0
    SYSCTL_RCGCPWM |= 0x01U;

    // Disable PWM before configuration
    PWM_CTL = 0x00U;

    // Configure PWM0 to generate a 50% duty cycle at 1 kHz
    PWM0_GENA0 = 0x8C;         // Configure PWM Generator A
    PWM0_LOAD = 16000U;         // Set PWM frequency to 10 kHz (16 MHz / 1600)
    PWM0_CMPA0 = 8000U;         // Set PWM duty cycle to 50%
    PWM_CTL = 0x01U;           // Enable PWM
    PWM_ENABLE = 0x01U;        // Enable PWM output
}
