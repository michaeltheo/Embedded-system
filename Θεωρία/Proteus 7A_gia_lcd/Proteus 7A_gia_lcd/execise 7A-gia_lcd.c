#include <main-proteus.h>
#include <gia_lcd.h>

#byte PORTB=0xf81 // ���� ���� 0xf81 ����� � ����������� ��������� 
                  //��� ������ �
                  
void main() {
             set_tris_b(0x00);
             
             LCD_Init();           
             LCD_SetPosition(LINE_1+5);
             LCD_PutChar("ELECTRONICS");
             LCD_SetPosition(LINE_2+4);
             LCD_PutChar("*****"); 
             delay_ms(100);           

while(TRUE) {}     // ����� ��� ������������, ���������� ������� ���� ������

            }      // ������� � ������ ��� main

