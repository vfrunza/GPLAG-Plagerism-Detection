// Ovo je ujedno prvi zadatak sa ispisima iz fajla or-rokovi-ispisi-i-mali-zadaci.pdf

#include<stdio.h>
void f1(char *x, char *s)
{
	while(*x++!='\0');
	x--;
	while(*s!='\0') *x++=*s++;
	*x='\0';
}
f2(char *x)
{
	int q;
	q=*x++;
	q++;
	q+=*x++;
	return q;
}
f3(char *x,int s)
{
	*++x=s;
	*x++='-';
	x++;
	*x--=s;
}
int main()
{
	int P[4][4]={1,8,15,22};
	char s[8]="Travnik";
	char Q[5]={'A','E','I','O','\0'};
	int q,p=1;
	q=P[1][1]+Q[3];
	printf("%d\n",q);
	f1(s,Q);
	printf("%s\n",s);
	q=f2(Q);
	printf("%d\n",q);
	f2(P);
	printf("%d\n",p);
	f3(s,Q[0]);
	printf("%s\n",s);
	return 0;
}
