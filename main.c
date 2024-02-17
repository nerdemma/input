// input.h UNIX Like BSD Library for C
// 2023-2024 Created by Nerdemma 
// hello@emmanuelbreyaue.com
// https://emmanuelbreyaue.com

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "input.h"

int main()
{

//input();
	

int ascii;
int counter=0;
printf("\e[?25l"); //hide the cursor 'h' to enable 
system("clear");

do
{

ascii = get_ascii();

//BACKSPACE
		if(ascii == 127 || ascii == 8)
		{

		if( counter > 0)
		{
		goto_xy(1,counter+1);
		printf(" ");
		counter--;
		}
		}

		else
		{
		counter++;
		goto_xy(1,counter);
		printf("%c",ascii);
		}

goto_xy(1,counter+1);
printf("|");

}


while( ascii != 10 && counter < 40);

printf("\n");
return 0;
}
