#include <main-proteus.h>

#byte  PORTB=0xF81
#byte  PORTD=0xF83


int pin=0;
void init(void);
void rb(void);


void main(void)
{
    init();
    while(TRUE)
    {}
}


#INT_RB
void rb()
{
    pin=input_state(PIN_B2);
    if(pin==0)
    {
        delay_ms(4000);
        if(input_state(PIN_B2)==pin)
        {
            output_high(PIN_D1);
            delay_ms(5000);
            output_toggle(PIN_D1);
        }
    }
    int a;
    a=PORTB;
}


void init()
{
    set_tris_b(0xFF);
    set_tris_d(0x00);
    PORTD=0x00;
    enable_interrupts(GLOBAL);
    enable_interrupts(INT_RB);
}