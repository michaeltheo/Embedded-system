#include <main.h> //Ο„ΞµΟƒΟ„ Ξ±Ο…Ο„ΞΏ ΞµΞΉΞ½Ξ±ΞΉ ΞµΞ½Ξ± Ο„ΞµΟƒΟ„
//τεστ στα ελληνικά
//τεστ στα ελληνικκααα
//ελληνικα τεστ

#byte PORTB=0xF81


void main(){

int8 i;
set_tris_b(0x00);
PORTB=0b10000000;
while (TRUE)
{
    for ( i = 1; i <=7 ; i++)
    {
        delay_ms(100);
        PORTB=PORTB/2;
    }
    for ( i = 7; i >= 1; i--)
    {
        delay_ms(100);
        PORTB=PORTB*2;
    }
}

}
