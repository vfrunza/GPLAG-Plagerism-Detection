#include<stdio.h>
void unesi(char niz[], int velicina){
 	char znak=getchar();
	if(znak == '\n') znak = getchar ();
	int i = 0;
	while(i < velicina-1 && znak != '\n') {
		niz [i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0'; 
}   
char *ubaci_broj (char *tekst, int broj){
int a;
while(a!=0) {
	
	a = broj % 10;
	broj / = 10;
	
} 
}






int main ()
{
	char tekst[100];
	int broj;
	printf("Unesite neki tekst");
	unesi(tekst,100);
}