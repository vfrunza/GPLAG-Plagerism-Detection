#include <stdio.h>
#include <math.h>

void ubaci(int* niz,int vel)
{
	int i,cifra,suma=0,k;
	int *p=niz;
	for(i=0;i<vel-1;i++)
	{
		*(p+2*(vel-1-i))=*(p+vel-1-i);
	}
	for(i=0;i<2*vel;i++)
	{
		if(i%2==0){
			k=fabs(*(p+i));
			suma=0;
		while(k>0)
		{
			cifra=k%10;
			k=k/10;
			suma=suma+cifra;
		}
		}
		else
		{
			*(p+i)=suma;
		}
	}
}
int izbaci(int niz[],int vel)
{
	int i,j,k,b,prvi,drugi,f_broj;
	for(k=0;k<vel;k++)
	{
		prvi=1;
		drugi=1;
		b=niz[k];
		for(i=0;i<b;i++){
			f_broj=prvi+drugi;
			prvi=drugi;
			drugi=f_broj;
			if(b==f_broj || b==1){
			for(j=k;j<vel-1;j++)
			niz[j]=niz[j+1];
			vel--;
			k--;
			}
		}
	}
	return vel;
}
int main() {
	int niz[20]={0},i,velicina,kraj_vel;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	scanf("%d",&niz[i]);
	velicina=10;
	ubaci(niz,velicina);
	kraj_vel=izbaci(niz,2*velicina);
	printf("Modificirani niz glasi: ");
	for(i=0;i<kraj_vel;i++)
	if(i<kraj_vel-1)
	printf("%d, ",niz[i]);
	else
	printf("%d.",niz[i]);
	return 0;
}
