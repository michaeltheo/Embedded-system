  
#include <main-proteus.h>

#byte PORTD=0xF83
#byte PORTB=0xF81





void init(void);
void ext_int0(void);
void ext_int2(void);



void main(void)
{
    init();
    while(TRUE)
    {
    }
}



#INT_EXT
void ext_int0()
{
   for(int8 i=0;i<100;i++){
       PORTD=PORTD^0XFF;
        delay_ms(125); //gia na exei F=4hz simainei tha
                       //kanei ena olokliro kiklo (250 ms) ara ta misa 
   }
            
}
#INT_EXT2 
void ext_int2()
{
   for(int8 i=0;i<100;i++){
       PORTD=PORTD^0XFF;
        delay_ms(50);
   }
       
      
}


void init()
{
    set_tris_b(0xFF);
    set_tris_d(0x00);
    PORTD=0x00;
    ext_int_edge(0,H_TO_L);
    ext_int_edge(2,H_TO_L);
    enable_interrupts(INT_EXT);
    enable_interrupts(INT_EXT2);
    enable_interrupts(GLOBAL);
}
