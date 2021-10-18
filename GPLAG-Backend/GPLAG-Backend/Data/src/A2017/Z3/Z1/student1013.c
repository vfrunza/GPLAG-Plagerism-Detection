#include <stdio.h>

int dva_od_tri(int niz1[],int a,int niz2[],int b,int niz3[],int c);
void provjera_2_od_tri(int niz1[],int a,int niz2[],int b,int niz3[],int c,int *br);
void duplikati(int *niz,int *velicina);

int provjera_elemenata(int n,int niz[],int velicina)
{
	/*provjerava postoji li vrijednost n u nizu*/
	int i;
	for(i=0; i<velicina; i++)
		if(n==niz[i])
			return 1;
	return 0;
}


void provjera_2_od_tri(int niz1[],int a,int niz2[],int b,int niz3[],int c,int *br)
{
	/*provjera elemenata jednog niza sa ostala dva */
	int i;
	for(i=0; i<a; i++) {
		if(provjera_elemenata(niz1[i],niz2,b)==1)
			if(provjera_elemenata(niz1[i],niz3,c)==0)
				(*br)++;
	}
}

void duplikati(int *niz, int *velicina)
{
	/*ogranicava niz na elemente tako da nemaju duplikata*/
	int i,j,k;
	for(i=0; i<*velicina-1; i++) {
		for(j=i+1; j<*velicina; j++) {
			if(*(niz+i)==*(niz+j)) {
				(*velicina)--;
				for(k=j; k<*velicina; k++)
					*(niz+k)=*(niz+k+1);
				j--;
			}
		}
	}
}

int dva_od_tri(int niz1[],int a,int niz2[],int b,int niz3[],int c)
{
	int br=0;
	duplikati(niz1,&a);
	duplikati(niz2,&b);
	duplikati(niz3,&c);

	provjera_2_od_tri(niz1,a,niz2,b,niz3,c,&br);
	provjera_2_od_tri(niz2,b,niz3,c,niz1,a,&br);
	provjera_2_od_tri(niz3,c,niz1,a,niz2,b,&br);
	return br;
}

int main()
{
	int niz1[100],niz2[100],niz3[100];
	int velicina1,velicina2,velicina3;
	int i;
	do {
		printf("Unesite velicinu prvog niza: ");
		scanf("%d",&velicina1);
	} while(velicina1<0 || velicina1>10000);
	for(i=0; i<velicina1; i++) {
		scanf("%d",&niz1[i]);
	}
	do {
		printf("Unesite velicinu drugog niza: ");
		scanf("%d",&velicina2);
	} while(velicina2<0 || velicina2>10000);
	for(i=0; i<velicina2; i++) {
		scanf("%d",&niz2[i]);
	}
	do {
		printf("Unesite velicinu treceg niza: ");
		scanf("%d",&velicina3);
	} while(velicina3<0 || velicina3>10000);
	for(i=0; i<velicina3; i++) {
		scanf("%d",&niz3[i]);
	}
	printf("%d ",dva_od_tri(niz1,velicina1,niz2,velicina2,niz3,velicina3));
	return 0;
}
