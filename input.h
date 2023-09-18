#ifndef _input_h
#define _input_h
#include<termios.h>
#include<unistd.h>


//insert key and return to ascii code

int getch(void)
{
struct termios oldattr, newattr;
int ch;

tcgetattr( STDIN_FILENO, &oldattr );
newattr = oldattr;
newattr.c_lflag &= ~( ICANON | ECHO );
tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
ch = getchar();
tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
return ch; //return ascii code
}

void cursor(int x, int y)
{
//move x,y coord.	
printf("_");	
}

//int output(int counter, char string)
//{
//printf("%c",string[counter]);
//return counter; 
//}


char *input(int size, char *string)
{	
	int counter=0;
	int remain = size;
	int ac;
	
	do
	{
	
	ac=getch();
	
	//save to array less of the specifiqued size
	if(counter<size-1){
	
	//only save alphanumerical characters.
	if(ac >=65 && ac <=90 || ac >=97 && ac <=122 ) //a to z, A to Z
	{ 
	string[counter]=(char)ac;
	//move cursor(counter+1,y); //when counter is more than size
	printf("%c",string[counter]);
	
	printf("%d",remain-=1); //Remain counter
	counter+=1;
	}//end of if
	
		//SPACE
		else if(ac==32){
		string[counter]=' ';
		//counter+=output(counter,string[counter]);
		printf("%c",string[counter]);
		counter+=1;
		}
	
	//BACKSPACE
	//CURSOR LEFT
	//CURSOR RIGHT
	}
	}
	
	
	while(ac!=10); //ENTER
	
	//while(counter<size-1);
	
	printf("\n");	
	string[counter+1]='\n';
	
	return string;
}


char *clear(int size, char *string)
{
int i;
for(i=0;i<size;i++)
{
string[i]==' ';	
}	
return string;
}

#endif
