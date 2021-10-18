#include <stdio.h>
int provjeri(char *s)
{
 int brojac=0;
 while(*s!='\0')
 {
  brojac++;
  s++;
 }
 if(*s!='>') return 0;
 s-=brojac;
 return 1;
}
int main() {
	return 0;
}
