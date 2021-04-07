#include <main-proteus.h>

#byte PORTB=0xF81
#byte PORTD=0xF83

int8 counter=0x30;

void init(void);
void rb(void);


void main(){
    init();
    while (TRUE)
    {
    }
    
}

void init()
{
    set_tris_b(0xFF);
    set_tris_d(0x00);

    port_b_pullups(TRUE);
    enable_interrupts(GLOBAL);
    enable_interrupts(INT_RB);
    PORTD=0x00;
}

#INT_RB
void rb(void)
{
    if(input(PIN_B0)==1)
    {
        delay_ms(3000);
        if(input(PIN_B0)==1)
        {
            output_high(PIN_D0);
            delay_ms(3000);
            output_low(PIN_D0);
        }
    }
}