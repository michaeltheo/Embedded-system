// Να γραφεί πρόγραμμα με το οποίο κάθε φορά που 
// πατάμε ένα μπουτόν το οποίο είναι συνδεδεμένοτον ακροδέκτη 
// RB4 της πόρτας Β το περιεχόμενο της πόρτας D αυξάνεται κατά 1.
// Το αποτέλεσμα της αύξησης να φαίνεται σε 8 LED  τα οποία είναι συνδεδεμένα 
// στην πόρτα D του μικροελεγκτή. 
// Να χρησομοποιηθεί συνάρτηση με την οποία ελέγχεται ότι πατήθηκε το μπουτόν. 
// Στη συνάρτηση να δοθεί το όνομα push_button.

#include <main.h>

#byte PORTD=0xF83
#byte PORTB=0xF81

void pushbutton(void);

void main(){
    set_tris_d(0x00);
    set_tris_b(0xFF);
    PORTD=0x00;

    while (TRUE)
    {
        pushbutton();
        PORTD=PORTD+1;
    }
}

void pushbutton(void){
    while (input(PIN_B4)==1)
    {
    }
    delay_ms(50);
    while (input(PIN_B4)==0)
    {
    }
    delay_ms(50); 
}