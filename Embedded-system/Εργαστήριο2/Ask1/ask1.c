#include <main.h>

#byte PORTB=0xF81
#byte PORTD=0xF83

void lled(int pin){
    output_high(pin);
    delay_ms(2000);
    output_low(pin);
    delay_ms(2000);
}
void main()
{

set_tris_b(0x00);
set_tris_d(0xFF);


int i;
while (TRUE)
{
    if(PORTD%2==0)
        for(i=0;i<10;i++){
            lled(PIN_B0);
        }
    
    else
        if(input(PIN_D7))
        
          for(i=0;i<5;i++)
          {
            lled(PIN_B1);
          }
        else
            for(i=0;i<2;i++)
          {
            lled(PIN_B2);
          }
        
    delay_ms(300);
}
}


