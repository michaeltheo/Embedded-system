#include<main.h>

#byte PORTB = 0xF81
#byte PORTD = 0xF83

int8 leds[8] = {
  1,
  2,
  4,
  8,
  16,
  32,
  64,
  128
};

void pattern2(void);
void pattern3(void);

void main()

{
  set_tris_b(0x00);
  set_tris_d(0xff);

  int a;
  int b;
  int i;
  int m;
// px PortB=00010001 credit Jojos
//a = PORTD & 0xF0;   0xF0=11110000
// ara 00010001
      // &11110000     (1&1=1,1&0=0,0&0=0)
      //  00010000 kai thelw na kanw 00000001 opote thelw na kanw shift 
      //  4 fores opote >> kai pairnw 00000001

// gia ta les significant bit tha kanw & me to 0x0F;
// px 00010001
//    00001111 
// kai pairnw 00000001 den xreiazetai na kanw shift b 

  PORTB = 0x00;
  a = PORTD & 0xF0;
  a = a >> 4;

  b = PORTD & 0x0F;

  while(TRUE) {
     for (i = 0; i < a; i++) {
       PORTB = 0xff;
       delay_ms(500);
       PORTB = 0x00;
       delay_ms(500);
     }
   
     for (m = 0; m < b; m++) {
       pattern2();
       pattern3();
   
     }
  }
}

void pattern2(void) { // O?inioo?iaoio pattern2          
  int8 i;
  for (i = 8; i > 0; i--) {
    PORTB = leds[i - 1];
    delay_ms(500);
  }
}

void pattern3(void) {
  int8 i;
  for (i = 0; i < 8; i++) {
    PORTB = leds[i];
    delay_ms(500);
  }
}