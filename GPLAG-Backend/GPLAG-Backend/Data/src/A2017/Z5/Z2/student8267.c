#include <stdio.h>

int main() {
	printf("Zadaća 5, Zadatak 2");
	return 0;
}
/*#include <stdio.h>

int duzina(char *a)
{
	int broj=0;
	while(*a++!='\0') broj++;
	return broj;
}

char* zamijeni_slova(char* s1, char* s2)
{
	int n=duzina(s2)-1;
	int i;
	int broj=0;
	for(i=0;i<=n/2;i++)
	{
		broj=0;
		while(*s1!='\0')
		{
			if(*s1==s2[i]) *s1=s2[n-i];
			s1++;
			broj++;
		}
		s1-=broj;
	}
	return s1;
}

int main() 
{
	char a[20]="";
	char b[5]="":
	printf("%s",zamijeni_slova(a,b));
	return 0;
}*/