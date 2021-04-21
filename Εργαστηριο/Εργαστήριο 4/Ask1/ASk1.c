#include <main_.h>

#byte PORTB=0xF81

int8 counter;



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
    
    set_tris_b(0xff);
    counter=0;
    setup_timer_0(T0_INTERNAL|T0_DIV_128);
    set_timer0(53817);
    enable_interrupts(INT_TIMER0);
    enable_interrupts(GLOBAL);
}


#INT_TIMER0
void timer0_int(){
    set_timer0(53817);
    counter++;
    if(!input_state(PIN_B1))
    {
        output_low(PIN_B7);
            //anavei to RB4 kathe deutero interrupt 
            // To Rb4 exei imiperiodo 250 ms 
            // To Rb7 exei imiperiodo 125 ms 
            // h arxiki timi tou metriti tou interrupt exei ipologistei gia 125 ms
            // to Rb4 prepei na anavei omws gia 250 ms 
            // opote vazw ena counter gia na ipologisw na anavei gia kathe deutero Intterupt
            // 125 *2 = 250 

        if(counter%2==0)
        {
        output_toggle(PIN_B4);
        
        }
    }
    else{
        output_low(PIN_B4);
        output_toggle(PIN_B7);
    }
}

