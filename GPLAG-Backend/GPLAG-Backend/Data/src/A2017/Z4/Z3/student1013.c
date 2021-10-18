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

int isto_slovo(char *s,int i,int j)
{
	/*provjera da li se od pozicije i do pozicije j neko slovo ponavlja*/
	for(i; i<j; i++)
		if(*(s+i)==*(s+j) || *(s+i)==*(s+j)+32 || *(s+i)==*(s+j)-32)
			return 1;
	return 0;
}

void najduzi_bp(char *s1,char *s2)
{
	int i=0,j,start,duz=0;
	do {
		if(slovo(*(s1+i))==1) {
			j=i;
			while(slovo(*(s1+(++j)))==1 && isto_slovo(s1,i,j)==0);
			if(duz<j-i) {
				start=i;
				duz=j-i;
			}
		}
	} while(*(s1+(++i))!='\0');
	for(i=0; i<duz; i++,start++)
		*(s2+i)=*(s1+start);
	*(s2+i)='\0';
}


int main()
{
	char s[1000],niz[1000];
	int i;
	printf("String: ");
	unesi(s,1000);
	najduzi_bp(s,niz);
	printf("Niz: '%s'",niz);
	return 0;
}
