// 0.25 hz = 4sec = 4000ms  imiperiodos 2000 
// 1hz = 1sec 1000ms  imiperiodos 500
// 2hz = 0.5sec 500ms imiperiodos 250
// 4hz = 0.25sec 250ms imiperiodos 125
// 10hz=0.1 100ms imiperiodos 50

// pernoume xrono diakopis xrono mikrotero tou 100 αλλα να διαιρει και ολα τα υπολοιπα
// pou dierei oles ti periodous px 25ms

// gia 25 ms 
// 10hz counter na einai 2
// 4hz counter na einai 5
// 2hz counter na einai 10
// 1hz counter na einai 20
// 0.25hz counter na einai 80

// set timer
// 25000000=83.333*128*(65536-x) => x=63192.2

#include "main_.h"

#byte PORTB=0xF81

int8 counter0_25=80;
int8 counter1=20;
int8 counter2=10;
int8 counter4=5;
int8 counter10=2;


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
    setup_timer_0(T0_INTERNAL|T0_DIV_128);
    set_timer0(63192);
    enable_interrupts(INT_TIMER0);
    enable_interrupts(GLOBAL);
}

#INT_TIMER0
void timer0_int(){
    set_timer0(63192);
    counter0_25--;
    counter10--;
    counter1--;
    counter2--;
    counter4--;
if (counter0_25==0)
{
    counter0_25=80;
    output_toggle(PIN_B3);
   
}
if (counter10==0)
{
    counter10=2;
    output_toggle(PIN_B7);
    
}
if (counter1==0)
{
    counter1=20;
    output_toggle(PIN_B4);
   
}
if (counter2==0)
{
    counter2=10;
    output_toggle(PIN_B5);
   
}
if (counter4==0)
{
    counter4=5;
    output_toggle(PIN_B6);
}

    

    
}
