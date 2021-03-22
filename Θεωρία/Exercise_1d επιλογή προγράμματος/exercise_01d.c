#include <main.h>

#byte PORTB=0xF81
#byte PORTD=0xF83

void main()
{
    set_tris_b(0x00);
    set_tris_d(0xFF);

    int a;
    while(TRUE)
    {
        a=PORTD;
        switch (a)
        {
        case 0: 
                PORTB=0xFF;
                delay_ms(100);
                PORTB=0x00;
                delay_ms(100);
            break;
        case 1: PORTB=0b11000011;
                delay_ms(100);
                PORTB=0b00111100;
                delay_ms(100);
            break;
        case 2:
                PORTB=0b10101010;
                delay_ms(100);
                PORTB=0b01010101;
                delay_ms(100);
            break;
        case 3:
                PORTB=0b10000000;
                for(int i=1;i<=7;i++)
                {
                    delay_ms(50);
                    PORTB=PORTB/2;
                }
                delay_ms(100);
            break;
        case 4:PORTB=0xF0;
               delay_ms(100);
               PORTB=0x0F;
               delay_ms(100);
            break;
        }
    }
}