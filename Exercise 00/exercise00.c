#include <main.h>
#byte PORTB=0xF81
void main(void){
set_tris_b(0x00);
PORTB=0b11100000;

while (TRUE)
{
    /*
    //na anavoun 11 ta lampakia entoli rotate 
    delay_ms(100);
    rotate_left(&PORTB,1);
    /*





    /*
    delay_ms(100); //perimenw 100 ms kleinoun ola ta lampakia 
    PORTB=0b00000000;
    delay_ms(100);
    PORTB=0xF0;  //anavoun ta 4 prwta 
    //IDIA ENTOLI THA ITAN PORTB=~PORTB PORTB OXI PORTVB TA 1 => 0 && 0=>1 PROSOXI ME MIA TETOIA ENTOLI TO PROGRAMMA DEN THA MPROEI NA KANEI TIPOTA ALLO 
    */

}


}


