#include <main.h>

#byte PORTB=0xF81
#byte PORTD=0xF83

void main()
{
set_tris_b(0x00);
set_tris_d(0xFF);

int patronymo=0b00000010; // NIKOLAOS
int i ;
while(TRUE)
{
    int answear=PORTD+patronymo;
    int total_bits;
    for(i=0;i<answear;i++)
    {
        total_bits+=bit_test(answear,i);
    }
    if(total_bits % 2 ==0) {
        output_high(PIN_B0); //change pin_bo to 1 
    }else{
        output_low(PIN_B0); //change pin_bo to 0
    }
    delay_ms(100);
    
}

}
