#include <main.h>

#byte PORTB=0xF81
#byte PORTD=0xF83  


void main(){
    int8 lastPortD,ginomeno,b;

set_tris_b(0x00);
set_tris_d(0xff);

while (TRUE)
{
PORTB=0x00;
while (input(PIN_D7)==1)
{
    lastPortD=PORTD & 0x0F;
}
if(input(PIN_D7)==0)
{
b=PORTD & 0x0F;
ginomeno=lastPortD*b;
if(ginomeno>100)
{
    output_high(PIN_B7);
    output_low(PIN_B0);
}
else{
    output_high(PIN_B0);
    output_low(PIN_B7);
}
}
delay_ms(500);
}
}