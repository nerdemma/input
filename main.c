#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include "input.h"





void main (void)
{
char string[26];
strcpy(string,clear(26,string));
strcpy(string,input(26,string)); 
printf("%s \n",string);	

}
