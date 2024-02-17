#ifndef _input_h
#define _input_h

#include<termios.h>
#include<unistd.h>

//char raw_input()


void goto_xy(int x, int y)
{
printf("%c[%d;%df",0x1B,x,y);
}


int get_ascii()
{
struct termios old_attr, new_attr;
int ascii;
tcgetattr( STDIN_FILENO, &old_attr);
new_attr = old_attr;
new_attr.c_lflag &= ~( ICANON | ECHO );
tcsetattr( STDIN_FILENO, TCSANOW, &new_attr);
ascii = getchar();
tcsetattr(STDIN_FILENO,TCSANOW, &old_attr);
return ascii;
}


#endif

