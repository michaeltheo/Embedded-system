#include <main-proteus.h>
#include <flex_lcd-proteus.h>


#byte PORTB=0xf81


//kathe 200 ms toogle opote meta apo 4 diakopes 4*50 =200ms 
int counter=4; 

//initialize state 
//state 1= emfanisontai ****
//state 2=  den emfanisontai ****

int8 state=0;

void timer0_int(void);
void init(void);

void main(){
init();
lcd_init();
lcd_putc("\f"); //clear lcd screen;
lcd_gotoxy(5,1); //go to 4 position row 1 
lcd_putc(" MICRO LAB");

while (TRUE)
{

}



}

void init(){
set_tris_b(0x00);
set_tris_d(0x00);
PORTB=0;
state=0;
counter=4;
setup_timer_0(T0_INTERNAL|T0_DIV_64);
set_timer0(56161);
enable_interrupts(INT_TIMER0);
enable_interrupts(GLOBAL);
}

#INT_TIMER0
void timer0_int(){
set_timer0(56161);
counter--;
if(counter==0 && state==0){
    counter=4;
    state=1;
    lcd_gotoxy(5,2);
    lcd_putc("*****");
}
if(counter==0 && state==1){
    counter=4;
    state=0;
    lcd_gotoxy(5,2);
    lcd_putc("     ");
}
}
