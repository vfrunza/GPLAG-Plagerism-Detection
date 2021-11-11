#include <stdio.h>
	void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
char *izbaci_najcescu(char *s)
{
	char *q=s;
	
	while(((*s<65 || *s>90) && (*s<97 || *s>122)) && *s!='\0')
	s++;

	return q;
}
int main() {
	char string[100];
	unesi(string,100);
	izbaci_najcescu(string);
	return 0;
}
