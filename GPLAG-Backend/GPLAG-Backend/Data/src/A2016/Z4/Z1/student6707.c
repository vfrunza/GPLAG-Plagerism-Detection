#include <stdio.h>
char* izbaci_najcescu( char* s)
{
	char* prva;
	int i;
	prva=s;
	
	while(*s != '\0')
	{
	 s++;
	
	}
	
	
	
	return prva;
}


int main() {
	char recenica[]="amila amila eee aaa ooo";
	char* p;
	
	p=izbaci_najcescu;
	
	printf("%s", recenica);
	return 0;
}
