#include <main.h>
#byte PORTB=0xF81 
#byte PORTD=0xF83


//msf 2^7
//lsf 2^0

int8 pattern=0;
int8 leds[8]={1,2,4,8,16,64,128};

void pattern1(void);
void pattern2(void);
void pattern3(void);



void main(){

set_tris_b(0x00);
set_tris_d(0xFF);

pattern=PORTD;

while(1){

if(pattern == 0x00 )
{
    pattern1()
}
if(pattern == 0x0f )
{
 pattern2()
}
if(pattern == 0xFF )
{
  pattern3();
}
delay_ms(300);
}
}

void pattern1(void){
    PORTB=0x00;
}
void pattern2(void){
    int8 i;
    for(i=0 ; i<=4 ;++)
    {
        PORTB=PORTB/2;
        delay_ms(1000);
    }
}
void pattern3(){
    
}