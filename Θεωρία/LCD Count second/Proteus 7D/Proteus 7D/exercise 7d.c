#include <main-proteus.h>
#include <flex_lcd-proteus.h>       // �� h ������ ��� ������������ �������� ��� ������ �� 
                     // ������ �� ����� ���� ���� ������ ���� �� �������������
                     //�� ��������� ���.

                     //�� ������ �� ����� ������� ��� ������� ����������� 
                     // ���� �������� #define LCD_DB4 PIN_B4 ��� ���
                     // �������� ���� flex_lcd.c. �� ����� ���
                     // �������� ����������� �� ������ ���������� ��� 
                     // ������������ ��������� � ���� ���������� ��� ������.

            // ������� �� flex_lcd.h �� �� Notepad ��� ������
            //������ ���� �������� �������� ��� ����������. �� ���
            //��������� �� ��� ����� ��� ��������� ��� ������������ ���� 
            //����� �� ������ �� ������ �������������. 

#byte PORTB=0xf81       // ���� ���� 0xf81 ����� � ����������� ��������� 
                           //��� ������ �

 // ������ ����������
int counter=20;       //�������� �������� (���� ��� 20 �������� ��� 50 ms �� �����
                      // ������� 20�50=1000 ms=1 second.
                                    // 4*250=1000
int seconds=0;      // ��������� ��� ������ � ���� �� ����������� ���� �����

// ������ �����������
void timer0_int(void);     //�� ����������� ��� �� ��������������� ���������� ���� ��� ��� main()
void init (void);

void main() {
init();                 //����� ��� �������� �������������
lcd_init();             // ������������ ��� ������
lcd_putc("\f");         // ���������� ��� ������
while(TRUE)       //������� ������(������ ��� ���������� ������� ����� ����� ������).
{      }
                 }      // ������� � ������ ��� main


// ������� �������� ��� ��� timer0. 
#INT_TIMER0          // Directive. ������ ���� ��� Compiler. ������� ��� � ������� �������
                     // ����� �������
                     // �������� ��� ��� timer0
void timer0_int(void){
         set_timer0(56161);         // ������ ���� ��� �������
                                    // ��� �� ������ � �������
                                    // ������� �� 50ms
         counter--;                 // ����������� � �������� ��������
if (counter==0) {
      counter=20;                   //o counter ����������� ��� ���� 20 ��� �� �������� ����� 20 ��������
      seconds++;                    //���� 20 �������� � ������� ��� ������������� ������� ���� 1
      lcd_gotoxy(5,1);               // ������ �� ������ � ����� ���� 5� ���� ��� ������ �������
      printf(lcd_putc,"SECONDS=%d",seconds);  // ����������� �� SECONDS= ��� ��� 
                                             // ��� �������� � ���� ��� ���������� seconds ��� �������� 
                                             // ���������� �������  
                  }                          
                   }                         //������ ����������� ��� �������� ��������

// ������� �������������
void init (void){
           set_tris_b(0x00);              // ���������� ��� ������ � �� ������
           set_tris_d(0x00);              // ���������� ��� ������ D �� �������
           seconds=0;                     // ������ ���� ��� ������� ������������� ��� �� �����
           counter=20;                    // ������ ���� ��� counter=20. ���� ��� 20 �������� � counter �� ����� 0
           SETUP_TIMER_0(T0_INTERNAL | T0_DIV_64 );    //Prescaler=1/64
            set_timer0(56161);                  //  ������ ���� ���  ������� timer0 ��� ��������
                                                //���� 50 ms 
            enable_interrupts(INT_TIMER0);   // ������������ ��� 
                                             //�������� ��� timer0
            enable_interrupts(GLOBAL);       // ������������ ��� ������� 
                                             // �������� ��� ��������   
               }

