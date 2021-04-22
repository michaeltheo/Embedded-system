//Askisi stin opoia kathe fora pou pataw to RBO (button) emfanizei stin PORTD posa deuterolepta perasan 
//apo tin telautaia ofora pou to patisa
//o xronos diakopis einai se 1 sec to counter exei time int8 kathws to PORTB mporei
// na parei times mexri 255
//set timer 1000000000=83.333*256*(65536-x)=18660

#include <main-proteus.h>

#byte PORTD=0xF83




void init(void);
void timer0_int(void);
void ext_int(void);
int8 seconds=0;


void main(void){
    init();
    while (TRUE)
    {
       
    }
}

void init(){
set_tris_b(0xff);
set_tris_d(0x00);
setup_timer_0(T0_INTERNAL|T0_DIV_256);
set_timer0(18660);
ext_int_edge(0,H_TO_L);
enable_interrupts(INT_TIMER0);
enable_interrupts(INT_EXT);
enable_interrupts(GLOBAL);
}


#INT_TIMER0 HIGH
void timer0_int(){
    set_timer0(18660);
    seconds++;
}

#INT_EXT
void ext_int()
{
    PORTD=seconds;
    seconds=0;
}
