#include <main.h> 
                  
#byte PORTB=0xF81 
#byte PORTD=0xF83
       
                  


void main(void){

set_tris_b(0x00);  
set_tris_d(0xff);


int i;
   while(TRUE) {
      if(PORTD%2==0) {
        for(i=0;i<10;i++){
            output_high(PIN_B0);
            delay_ms(1000);
            output_low(PIN_B0);
            delay_ms(1000);
        }
      }
      else{
         if(input(PIN_D7)){
            for(i=0;i<5;i++)
            {
            output_high(PIN_B1);
            delay_ms(1000);
            output_low(PIN_B1);
            delay_ms(1000);}
         }else{
            for(i=0;i<2;i++){
            output_high(PIN_B2);
            delay_ms(1000);
            output_low(PIN_B2);
            delay_ms(1000);}
         }
      
      delay_ms(3000);
   }
}
}
    
