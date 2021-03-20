//Keypad connection:
#define row0 PIN_d4
#define row1 PIN_d5
#define row2 PIN_d6
#define row3 PIN_d7
#define col0 PIN_d0
#define col1 PIN_d1
#define col2 PIN_d2
#define col3 PIN_d3

//------------------- Variable definition----------------------------
char const KEYS[4][4] =
{{'7','8','9','/'},
 {'4','5','6','X'},
 {'1','2','3','-'},
 {'C','0','=','+'}};


#define KBD_DEBOUNCE_FACTOR 200// Set this number to apx n/333 where
// n is the number of times you expect
// to call kbd_getc each second

//------------------Function Definition------------------------------
short int ALL_ROWS (void);
void kbd_init(void);
char kbd_getc(void);
//-------------------------------------------------------------------
void kbd_init(void)
{
set_tris_d(0xF0);
output_d(0x0F);
}
//-----------------------------------------------------------
short int ALL_ROWS (void)
{
if(input (row0) & input (row1) & input (row2) & input (row3))
return (0);
else
return (1);
}

//-----------------------------------------------------------

char kbd_getc(void)
{
static byte kbd_call_count;
static short int kbd_down;
static char last_key;
static byte col;

byte kchar;
byte row;

kchar='\0';

if(++kbd_call_count>KBD_DEBOUNCE_FACTOR)
  {
      switch (col)
              {
               case 0:
                output_low(col0);
              output_high(col1);
              output_high(col2);
              output_high(col3);
              break;
   
              case 1:
              output_high(col0);
              output_low(col1);
              output_high(col2);
              output_high(col3);
              break;

               case 2:
              output_high(col0);
                output_high(col1);
              output_low(col2);
              output_high(col3);
              break;

               case 3:
              output_high(col0);
              output_high(col1);
              output_high(col2);
              output_low(col3);
              break;
               }

            if(kbd_down)
                 {
                  if(!ALL_ROWS())
                       {
                       kbd_down=false;
                       kchar=last_key;
                        last_key='\0';
                          }
                 }
         else
              {
               if(ALL_ROWS())
                 {
                  if(!input (row0))
                        row=0;
                  else if(!input (row1))
                        row=1;
                  else if(!input (row2))
                       row=2;
                  else if(!input (row3))
                        row=3;

                  last_key =KEYS[row][col];
                  kbd_down = true;
                 }
            else
                    {
               ++col;
               if(col==4)
                     col=0;
                    }
             }
            kbd_call_count=0;
     }
         return(kchar);
}

//-------------------------------------------------------------
