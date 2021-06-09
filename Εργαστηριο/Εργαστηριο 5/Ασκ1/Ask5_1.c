#include <main-proteus.h>
#byte PORTB         =0xF81 
#byte PORTC         =0xF82
#byte PORTD         =0xF83

int8  des=0;       

int16 tenthseconds,tenthseconds_stop=0; 
                  
int8 counter;      
int1 start=0;       
int1 stop=0;      
int8 table[16] ={ 0b00111111,   
                        0b00000110,   
                             0b01011011, 
                             0b01001111, 
                             0b01100110, 
                             0b01101101, 
                             0b01111101, 
                             0b00000111, 
                             0b01111111, 
                             0b01101111, 
                             0b01110111, 
                             0b01111100, 
                             0b00111001, 
                             0b01011110, 
                             0b01111001, 
                             0b01110001};  
int8 dig[3] = {1,2,4}; 
            
// ÄÞëùóç óõíáñôÞóåùí
void timer0_int(void);
void init (void);
// Êýñéá óõíÜñôçóç
void main()
{
      init();  
   
     while (TRUE){    
   if ((INPUT(PIN_D1)==0) && (start==0)){   
                  
   start=1;                
         }
   else if(start == 1 && INPUT(PIN_D1) == 1){            
                    stop = 1; 
                                 
                    
                  }
                  else {         
                     stop = 0;  
                           
                                }         
      } 
         
}           
#INT_TIMER0 HIGH   
void timer0_int(void){
      int16 mon,dec,eka;  
      counter--; 
            
      if (counter == 0){  
            if (start == 1){ 
            tenthseconds++; 
                                       }
            counter = 20; 
            if (tenthseconds > 999){              
                     tenthseconds = 0;  
                              }              
            }
      if (stop == 0 ){                        
                   tenthseconds_stop = tenthseconds;  
                  }               
          eka = (int8) (tenthseconds_stop /100);    
          dec = (int8) ((tenthseconds_stop - (100*eka))/10); 
                           
          mon = (int8) (tenthseconds_stop - (100 * eka) -(10 * dec)); 
                                          
         des = ++des%3;  
           
      PORTC = dig[des];
              
      if (des==0){                               
         PORTB = table[mon]; 
                        
                       }         
      if (des==1){                        
         PORTB = table[dec]; 
                                                }            
      if (des==2){                         
         PORTB = table[eka]; 
                     
         }               
}                     
// ÓõíÜñôçóç áñ÷éêïðïßçóçò
void init (void){
   set_tris_b(0x00);        
    set_tris_c(0x00);        
    PORTB = 0;           
    PORTC = 0;          
    counter = 300;          
    tenthseconds = 0;    
    tenthseconds_stop = 0;
    start=0; 
    stop=0; 
    des =0; 
   SETUP_TIMER_0(T0_INTERNAL | T0_DIV_1 ); 
   set_timer0(5536);                           
          enable_interrupts(INT_TIMER0);  
          enable_interrupts(GLOBAL);                                                   
            
      }         
