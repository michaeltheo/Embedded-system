#include <main-proteus.h>

#byte PORTD=0xF83
#byte PORTB=0xF81





void init(void);
void ext_int1(void);
void ext_int2(void);



void main(void)
{
    init();
    while(TRUE)
    {
        output_toggle(PIN_D5);
        delay_ms(500);
    }
}



#INT_EXT1 
void ext_int1()
{
   for(int8 i=0;i<10;i++){
       output_toggle(PIN_D0);
        delay_ms(1000);
   }
       
        
}
#INT_EXT2 HIGH
void ext_int2()
{
   for(int8 i=0;i<10;i++){
       output_toggle(PIN_D7);
        delay_ms(1000);
   }
       
      
}


void init()
{
    set_tris_b(0xFF);
    set_tris_d(0x00);
    PORTD=0x00;
    ext_int_edge(1,L_TO_H);
    ext_int_edge(2,L_TO_H);
    enable_interrupts(INT_EXT1);
    enable_interrupts(INT_EXT2);
    enable_interrupts(GLOBAL);
}