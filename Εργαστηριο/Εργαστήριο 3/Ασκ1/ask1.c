#include <main-proteus.h>
#byte PORTD=0xF83
#byte PORTB=0xF81


int8 counter=0;
void init(void);
void ext_int1(void);
void ext_int2(void);


void main()
{
    init();
    while (TRUE)
    {
    }
}

void init(void){
    set_tris_d(0x00);
    set_tris_b(0xFF);
    enable_interrupts(GLOBAL);
    enable_interrupts(INT_EXT1); //energopoisi diakopwn apo ton akrodekti RB1
    ext_int_edge(1,L_TO_H); //energopoisi tis diakopis kata tin metavasi 1 se 0 
    enable_interrupts(INT_EXT2);
    ext_int_edge(2,L_TO_H);
    PORTD=0x00;
}

#INT_EXT1
void ext_int1(){
    if(input(PIN_B7)==1)
    {
        if(counter !=255 || counter>0 )
            {counter++;
             PORTD=counter;
             delay_ms(200);
            }
        }
    }

#INT_EXT2
void ext_int2(){
    if(input(PIN_B7)==0)
    {
        if(counter != 0 && counter<255)
        {
            counter--;
            PORTD=counter;
             delay_ms(200);
        }
    }

}