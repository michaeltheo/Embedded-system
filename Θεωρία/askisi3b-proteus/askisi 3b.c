#include <main.h>
//des C0=0000 0001
//des C2=0000 0010
//des C3=0000 0100
//an to C3 itan 0000 0011 tote tha aneve kai to C1 to C0
//giauto to des einai des={1,2,4}
#byte PORTB         =0xF81 
#byte PORTC         =0xF82 
#byte PORTD         =0xF83 

     int8 isodos,ekatondates,decades,monades;
     int8 table[16] ={ 0b00111111,      //Πίνακας με του κώδικες για
                                                    // εμφάνιση σε ενδείκτη 7 τομέων
                             0b00000110,   //των ψηφίων 0, 1, 2, … 9, … F.
                             0b01011011,   //κώδικας για εμφάνιση του 2
                             0b01001111,    //κώδικας για εμφάνιση του 3
                             0b01100110,    //κώδικας για εμφάνιση του 4
                             0b01101101,    //κώδικας για εμφάνιση του 5
                             0b01111101,     //κώδικας για εμφάνιση του 6
                             0b00000111,    //κώδικας για εμφάνιση του 7
                             0b01111111,     //κώδικας για εμφάνιση του 8
                             0b01101111,     //κώδικας για εμφάνιση του 9
                             0b01110111,     //κώδικας για εμφάνιση του Α
                             0b01111100,    //κώδικας για εμφάνιση του Β
                             0b00111001,    //κώδικας για εμφάνιση του C
                             0b01011110,     //κώδικας για εμφάνιση του D
                             0b01111001,     //κώδικας για εμφάνιση του Ε
                             0b01110001};

void main(){
     set_tris_b(0xFF);
     set_tris_c(0x00);
     set_tris_d(0x00);
     while (TRUE)
     {
          
          isodos=PORTB;
          ekatondates=(int8)(isodos/100);
          decades=(int8)(isodos-(ekatondates*100))/10;
          monades=(int8)(isodos-(ekatondates*100)-(decades*10));

          //show ekatondates
          PORTC=0b00000100;
          PORTD=table[ekatondates];
          delay_ms(200);
          

          //show dekades
          PORTC=0b00000010;
          PORTD=table[decades];
          delay_ms(200);
          
      
      //show monades
         PORTC=0b00000001;
          PORTD=table[monades];
          delay_ms(200);
          
        
     
     }
}
