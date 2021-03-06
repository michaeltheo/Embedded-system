// Να γραφεί πρόγραμμα με το οποίο προκαλείται μια διακοπή από αλλαγή κατάστασης στους ακροδέκτες RB4, RB5, RB6, RB7.
//  Κάθε φορά που αλλάζει η κατάσταση σε έναν από τους διακόπτες που είναι συνδεδεμένοι στου ακροδέκτες RB4, RB5, RB6, RB7 να αλλάζει η κατάσταση όλων των bit της πόρτας D. 
//  Η αρχική τιμή της πόρτας D να είναι FF.


#include <main.h>
#byte PORTD=0xF83
#byte PORTB=0xF81 

void init(void);
void rb(void);



void main(){
    init();
    while (TRUE)
    {
    }
}


void init(){
    set_tris_d(0x00);
    set_tris_b(0xff);
    enable_interrupts(INT_RB);
    enable_interrupts(GLOBAL);
    PORTD=0xFF;
}

#INT_RB
void rb(){
    int8 a;
    PORTD=PORTD^0xFF;
    a=PORTB;
    delay_ms(100);
}
