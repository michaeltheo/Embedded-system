#define LCD_D4  PIN_B4
#define LCD_D5  PIN_B5
#define LCD_D6  PIN_B6
#define LCD_D7  PIN_B7
#define LCD_EN  PIN_B3
#define LCD_RS  PIN_B2
#define LINE_1  0x00
#define LINE_2  0x40
#define CLEAR_DISP  0x01

void LCD_Init ( void );
void LCD_SetPosition ( unsigned int cX );
void LCD_PutChar ( unsigned int cX );
void LCD_PutCmd ( unsigned int cX );
void LCD_PulseEnable ( void );
void LCD_SetData ( unsigned int cX );

// LCD FUNCTIONS =================================

void LCD_Init ( void )
    {
    LCD_SetData ( 0x00 );
    delay_ms ( 200 );       // wait enough time after Vdd rise
    output_low ( LCD_RS );
    LCD_SetData ( 0x03 );   // init with specific nibbles to start 4-bit mode
    delay_ms (2);
    LCD_PulseEnable();
    delay_ms (1);
    LCD_PulseEnable();
    delay_ms (1);
    LCD_PulseEnable();
    delay_ms (1);
    LCD_SetData ( 0x02 );   // set 4-bit interface
    delay_ms (1);
    LCD_PulseEnable();      // send dual nibbles hereafter, MSN first
    delay_ms (1);
    LCD_PutCmd ( 0x2C );    // function set (all lines, 5x7 characters)
    delay_ms (1);
    LCD_PutCmd ( 0x0C );    // display ON, cursor off, no blink
    delay_ms (1);
    LCD_PutCmd ( 0x01 );    // clear display
    delay_ms (1);
    LCD_PutCmd ( 0x06 );    // entry mode set, increment
    delay_ms (1);
    }

void LCD_SetPosition ( unsigned int cX )
    {
    // this subroutine works specifically for 4-bit Port A
    LCD_SetData ( swap ( cX ) | 0x08 );
    LCD_PulseEnable();
    delay_ms (1);
    LCD_SetData ( swap ( cX ) );
    LCD_PulseEnable();
    delay_ms (1);
    }

void LCD_PutChar ( unsigned int cX )
    {
    // this subroutine works specifically for 4-bit Port A
    output_high ( LCD_RS );
    delay_ms (1);
    LCD_SetData ( swap ( cX ) );     // send high nibble
    LCD_PulseEnable();
    delay_ms (1);
    LCD_SetData ( swap ( cX ) );     // send low nibble
    LCD_PulseEnable();
    delay_us (1);
    output_low ( LCD_RS );
    }

void LCD_PutCmd ( unsigned int cX )
    {
    // this subroutine works specifically for 4-bit Port A
    LCD_SetData ( swap ( cX ) );     // send high nibble
    delay_ms (1);
    LCD_PulseEnable();
    delay_ms (1);
    LCD_SetData ( swap ( cX ) );     // send low nibble
    delay_ms (1);
    LCD_PulseEnable();
    delay_ms (1);
    }

void LCD_PulseEnable ( void )
    {
    output_high ( LCD_EN );
    delay_ms ( 1 );
    output_low ( LCD_EN );
    delay_ms ( 1 );
    }

void LCD_SetData ( unsigned int cX )
    {
    output_bit ( LCD_D4, cX & 0x01 );
    output_bit ( LCD_D5, cX & 0x02 );
    output_bit ( LCD_D6, cX & 0x04 );
    output_bit ( LCD_D7, cX & 0x08 );
    }
    
