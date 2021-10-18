#include <stdio.h>
#include <math.h>

void zaokruzi1(float *niz,int velicina);
void preslozi (float *niz,int velicina,int k);

void zaokruzi1(float *niz,int velicina)
{
	int i;
	float c,prvi,druga_dec;
	for(i=0; i<velicina; i++) {
		prvi=(*(niz+i)-(int)*(niz+i))*10.0;
		/*druga_dec varijablu koristimo da bismo provjerili drugu decimalnu vrijednost broja, da bi utvrdili da li da zaokruzimo na gornju
		ili donju vrijednost prve decimale*/
		druga_dec=(int)((prvi-(int)prvi)*10);
		if(druga_dec>=5)
			c=0.1;
		else if(druga_dec<=-5)
			c=-0.1;
		else
			c=0.0;
		*(niz+i)=(((int)(prvi)/10.0) + (int)*(niz+i))+c;
	}
}


int zbir_cifara(int n)
{
	/*vraca zbir cifara zaokruzenih na jedno decimalno mjesto*/
	int suma=0;
	n=fabs(n);
	do {
		suma+=n%10;
		n=n/10;
	} while(n!=0);
	return suma;
}

void preslozi(float *niz,int velicina,int k)
{
	int i,j;
	int br=0;
	float temp;
	zaokruzi1(niz,velicina);
	for(i=velicina-1; i>=br; i--) {
		if(zbir_cifara((int)((*(niz+i))*10))>=k) {
			temp=*(niz+i);
			for(j=i; j>0; j--)
				*(niz+j)=*(niz+j-1);
			*niz=temp;
			br++;
			i++;
		}
	}
}


int main()
{
	float niz[1000];
	int velicina,i,k;
	do {
		scanf("%d",&velicina);
	} while(velicina<0 || velicina>1000);
	for(i=0; i<velicina; i++) {
		scanf("%f",&niz[i]);
	}
	scanf("%d",&k);
	preslozi(niz,velicina,k);
	printf("NIz glasi: ");
	for(i=0; i<velicina; i++) {
		printf("%g ",niz[i]);
	}
	return 0;
}
