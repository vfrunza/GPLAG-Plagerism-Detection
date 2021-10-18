#include <stdio.h>

int provjeri(char* tekst)
{
	do
	{
		
		tekst++;
	}
	while(tekst!="\0");
	
}

int provjeri_naziv_taga(char* naziv)
{
	do
	{
		if(!((*naziv > 96 && *naziv< 123) || (*naziv> 64 && *naziv< 91) || (*naziv > 47 && *naziv< 58))
		{
			return 0;
		}
		naziv++;
	}
	while(naziv!="\0");
	return 1;
}

int main() {
	printf("Zadaća 4, Zadatak 4");
	return 0;
}
