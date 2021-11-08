#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))


int counter = 0;
int main()
{
    RCC_AHB2ENR = RCC_AHB2ENR | 0x1; // Enable the clock, set first bit to true
    //RCC_AHB2ENR = 0x00000001;
    //RCC_AHB2ENR = 0x1;
    
    //F.Y.I: GPIOA_MODER RESET VALUE
    // 1010 1011 1111 1111 1111 1111 1111 1111
    // Change bits 11 & 10
    GPIOA_MODER = GPIOA_MODER & 0xABFFF7FF;
    
    while(1)
    {
        GPIOA_ODR |= 0x0020; // GPIOx_ODR Turn LED1 (PA5) on
        counter = 0;
        while (counter < 100000)
        {
            counter++;
        }
        
        GPIOA_ODR = GPIOA_ODR ^ ~0x0000; // Turn LED1 (PA5) off
        counter = 0;
        while (counter < 100000)
        {
            counter++;
        }
    }
}