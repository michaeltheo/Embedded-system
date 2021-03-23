#include <main.h>
#byte PORTB=0xF81 
#byte PORTD=0xF83


//msf 2^7
//lsf 2^0


void main()
{
set_tris_b(0x00);  
set_tris_d(0xff);
int i,leds_on,leds_flash;
while(TRUE){
    leds_flash=0;
    leds_on=0;
for(i=0;i<=3;i++ )
{
    if(bit_test(PORTD,i))
    {
        leds_flash++;
    }
}
// for(i=4;i<=7;i++ )
// {
//     if(input_state(PORTD))
//     {
//         leds_on++;
//     }
// }

while(leds_flash!=0){
    PORTB=0xff;
    delay_ms(100);
    PORTB=0x00;
    leds_flash--;

}
delay_ms(300);
}
}