#include <stdio.h>

void unesi(char niz[], int velicina)
{
	char znak = getchar();
	if (znak == '\n') znak = getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}

int slovo(char c)
{
	if((c>='A' && c<='Z') || (c>='a' && c<='z'))
		return 1;
	return 0;
}

int provjeri_duzine(char *s,int niz[],int v)
{
	int i=0,rijec=0,duz;
	do 
	{
		if(slovo(*(s+i))==1) 
		{
			duz=1;
			while(slovo(*(s+(++i)))==1)
				duz++;
			if(duz!=niz[rijec] || rijec>=v) {
				return 0;
			}
			rijec++;
		}
	} while(*(s+(i++))!='\0');
	if(rijec!=v)
		return 0;
	return 1;
}

int main()
{
	int i,niz[100],vel;
	char s[1000];
	printf("Velicina niza: ");
	scanf("%d",&vel);
	printf("Niz: ");
	for(i=0; i<vel; i++) {
		scanf("%d",&niz[i]);
	}
	printf("String: ");
	unesi(s,1000);
	printf("%d ",provjeri_duzine(s,niz,vel));
	return 0;
}
