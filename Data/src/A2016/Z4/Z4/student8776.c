#include <stdio.h>
char* obuhvat(char* string,double a, double b, double c, double d)
{
	char* vrati=string;
	int tacke[2][100];
	int i=0;
	while(*string!='\0')
	{
		if(*string>='0' || *string<='9')
		{
		 tacke[i][i]=(int)*string;
		}
		string++;
	}
	string=vrati;
	while(*string)
	{
		if(*string=='(')
		{
			*string=' ';
			
		}
		else if(*string==')')
		{
			*string='-';
		}
		string++;
	}
	vrati=NULL;
	return vrati;
}

int main() {
	
	return 0;
}
