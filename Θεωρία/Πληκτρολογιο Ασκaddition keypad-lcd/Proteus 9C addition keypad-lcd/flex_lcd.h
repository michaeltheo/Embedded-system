//---------------------------------------------------
#define LCD_DB4   PIN_D4
#define LCD_DB5   PIN_D5
#define LCD_DB6   PIN_D6
#define LCD_DB7   PIN_D7

#define LCD_E      PIN_D3
#define LCD_RS     PIN_D2
#define LCD_RW     PIN_D1
#define lcd_type 2        // 0=5x7, 1=5x10, 2=2 lines
#define lcd_line_two 0x40 // LCD RAM address for the 2nd line
int8 const LCD_INIT_STRING[4] =
{
 0x20 | (lcd_type << 2), // Func set: 4-bit, 2 lines, 5x8 dots
 0xc,                    // Display on
 1,                      // Clear display
 6                       // Increment cursor
 };
//=================================================================
void lcd_send_nibble(int8 nibble);
void lcd_send_byte(int8 address, int8 n);
void lcd_init(void);
void lcd_gotoxy(int8 x, int8 y);
void lcd_putc(char c);
//=================================================================
//-------------------------------------------------------------
void lcd_send_nibble(int8 nibble)
{
// Note:  !! converts an integer expression
// to a boolean (1 or 0).
 output_bit(LCD_DB4, !!(nibble & 1));
 output_bit(LCD_DB5, !!(nibble & 2)); 
 output_bit(LCD_DB6, !!(nibble & 4));   
 output_bit(LCD_DB7, !!(nibble & 8));   

 delay_cycles(20);
 output_high(LCD_E);
 delay_us(50);
 output_low(LCD_E);
}

//-----------------------------------
// This sub-routine is only called by lcd_read_byte().
// It's not a stand-alone routine.  For example, the
// R/W signal is set high by lcd_read_byte() before
// this routine is called.     


//----------------------------------------
// Send a byte to the LCD.
void lcd_send_byte(int8 address, int8 n)
{
output_low(LCD_RS);

if(address)
   output_high(LCD_RS);
else
   output_low(LCD_RS);
     
 delay_cycles(10);

output_low(LCD_E);

lcd_send_nibble(n >> 4);
lcd_send_nibble(n & 0xf);
}

//----------------------------
void lcd_init(void)
{
int8 i;

output_low(LCD_RS);

output_low(LCD_E);

delay_ms(200);

for(i=0 ;i < 3; i++)
   {
    lcd_send_nibble(0x03);
    delay_ms(10);
   }

lcd_send_nibble(0x02);

for(i=0; i < sizeof(LCD_INIT_STRING); i++)
   {
    lcd_send_byte(0, LCD_INIT_STRING[i]);
   
    // If the R/W signal is not used, then
    // the busy bit can't be polled.  One of
    // the init commands takes longer than
    // the hard-coded delay of 60 us, so in
    // that case, lets just do a 5 ms delay
    // after all four of them.
   
    delay_ms(10);
    }

}

//----------------------------

void lcd_gotoxy(int8 x, int8 y)
{
int8 address;

if(y != 1)
   address = lcd_line_two;
else
   address=0;

address += x-1;
lcd_send_byte(0, 0x80 | address);
}

//-----------------------------
void lcd_putc(char c)
{
 switch(c)
   {
    case '\f':
      lcd_send_byte(0,1);
      delay_ms(4);
      break;
   
    case '\n':
       lcd_gotoxy(1,2);
       break;
   
    case '\b':
       lcd_send_byte(0,0x10);
       break;
   
    default:
       lcd_send_byte(1,c);
       break;
   }
}

//------------------------------

