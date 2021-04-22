//gia msb T=200 ms ,ara 100 tha einai off kai 100 tha einai on 
//gia lsb T=500 ms ,ara 250 tha einai off kai 250 tha einai on
// pernoume xrono diakopis xrono mikrotero tou 100
// pou dierei oles tis imiperiodous px 25ms

//gia 25ms
//LSb tha kanoun toogle kathe 100ms ara counter=4
//MSb tha kanoun toogle kathe 250ms ara counter=10

// set timer
// 25000000=83.333*32*(65536-x) => x=56161





#include "main_.h"

#byte PORTB=0xF81



int8 counter100ms=4;
int8 counter250ms=10;



void timer0_int(void);
void init(void);

void main()
{
init();
while (1)
{

}}


void  init (void)
{   
    
    set_tris_b(0x00);
    set_tris_d(0xff);
    setup_timer_0(T0_INTERNAL|T0_DIV_32);
    set_timer0(56161);
    enable_interrupts(INT_TIMER0);
    enable_interrupts(GLOBAL);
}

#INT_TIMER0
void timer0_int(){
    set_timer0(56161);
    counter100ms--;
    counter125ms--;

if(input_state(PIN_D0))
{
    if (counter250ms==0)
    {
        PORTB=0b11110000;
        counter250ms=10;
        PORTB=PORTB^0b11110000;
    }
}else{
    if (counter100ms==0)
    {
        PORTB=0b00001111;
        counter100ms=4;
        PORTB=PORTB^0b00001111;
    }
}
}

    

    
