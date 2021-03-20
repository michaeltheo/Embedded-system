#include <main.h>

#byte PORTB=0xF81
#byte PORTD=0xF83




void main()
{
    set_tris_b(0x00);
    set_tris_d(0xff);

    int a;
    int onoma=5;
    int eponyma=7;


    while(TRUE){
        a=PORTD+onoma-eponyma;
        PORTB=a;
    }
}