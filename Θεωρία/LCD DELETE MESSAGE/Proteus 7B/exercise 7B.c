#include <main-proteus.h>
#include <flex_lcd-proteus.h> // �� h ������ ��� ������������ �������� ��� ������ �� 
                     // ������ �� ����� ���� ���� ������ ���� �� �������������
                     //�� ��������� ���
                     //�� ������ �� ����� ������� ��� ������� ����������� 
                     // ���� �������� #define LCD_DB4 PIN_B4 ��� ���
                     // �������� ���� flex_lcd.c. �� ����� ���
                    // �������� ����������� �� ������ ���������� ��� 
                     // ������������ ��������� � �����.

#byte PORTB=0xf81 // ���� ���� 0xf81 ����� � ����������� ��������� 
                  //��� ������ �

void main() {

lcd_init();      // ������������ ��� ������

lcd_putc("\f"); // ���������� ��� ������

lcd_gotoxy(4,1); // � ����� �� ��������� ���� 4� ���� ��� 1�� �������

lcd_putc("MICRO LAB"); // ����������� �� ������ ���� ���� ��� 
            // �������� ��� ��� ����������� ������

while(TRUE){

lcd_gotoxy(5,2);  // � ����� �� ��������� ���� 5� ���� ��� 2�� �������

lcd_putc("*****"); // ������������ �� ���������� ���� ���� ��� �����������
          // ��� ��� ����������� ������

delay_ms(500);  // ����������� 500 �������� ��� �������������

lcd_gotoxy(5,2);  // � ����� �� ��������� ���� ���� 5� ���� ��� 2�� �������

lcd_putc("     ");  // ��������� 5 ����� ���������� ���� ���� ����� ������
        // �� ����� ����������

delay_ms(500);  // ������� ��� 500 ms

         } // ������� � ������ ��� while(TRUE)

   } // ������� � ������ ��� main


