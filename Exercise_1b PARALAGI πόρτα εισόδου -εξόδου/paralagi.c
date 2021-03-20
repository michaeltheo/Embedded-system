#include <main.h>

#byte PORTB=0xF81
#byte PORTD=0xF83
void main()
{
    set_tris_b(0xff);
    set_tris_d(0x00);

  
    while(TRUE){
        int8 repeat=PORTB; //metaferw tin timi tis portasB stin repeat 
        for(int i=0;i<repeat;i++)
        {
            PORTD=0xff;
            delay_ms(100);
            PORTD=0x00;
            delay_ms(100);
        }
        delay_ms(500);

}
}


