#include <main.h>

#byte PORTB=0xF81
#byte PORTD=0xF83

void main () 
{ 
    set_tris_b(0xFF);
    set_tris_d(0x00);
    int patronimo=7;
    int a;
    while(1)
    {
       a=input_b();
       set_tris_d(a);
       delay_ms(100);
       PORTD=patronimo*6; 
       delay_ms(200);

    }
}
