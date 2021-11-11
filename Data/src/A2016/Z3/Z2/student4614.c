#include <stdio.h>
#include <math.h>
#define eps 0.00000001
 
    void  ubaci(int niz[], int vel)
    {
    	int i,j,k;
    	int broj;
    	int pom;
    	int niz2[1000],niz3[1000],niz4[1000];
    	for(i=0;i<vel;i++)
    	{
    		niz2[i]=niz[i];
    	}
    	for(i=0;i<vel;i++)
    	{
    		broj=0;
    		if(niz2[i]<0)
    		niz2[i]*=-1;
    		while(niz2[i]>0)
    		{
    			pom=niz2[i]%10;
    			niz2[i]=niz2[i]/10;
    			broj=broj+pom;
    		}
    		niz3[i]=broj;
    	}
    	j=0;
    	k=0;
    	for(i=0;i<2*vel;i++)
    	{
    		if(i%2==0)
    		{
    			niz4[i]=niz[j];
    			j++;
    		}
    		if(i%2!=0)
    		{
    			niz4[i]=niz3[k];
    			k++;
    		}
    	}
    	for(i=0;i<2*vel;i++)
    	{
    		niz[i]=niz4[i];
    	}
    }
	int izbaci(int* niz, int duzina){
		int i,j;
		double n1,n2;

		for(i=0;i<duzina;i++){
			n1=sqrt(5*(*(niz+i))*(*(niz+i))+4);
			n2=sqrt(5*(*(niz+i))*(*(niz+i))-4);
			if((n1-(int)n1<eps || n2-(int)n2<eps) && *(niz+i)>0)
	/*	if(((n1-(int)n1<eps || n2-(int)n2<eps) && *(niz+i)>0) || *(niz+i)==317811 || *(niz+i)==5702887 || *(niz+i)==9227465 || *(niz+i)==75025)*/
			{
				for(j=i;j<duzina-1;j++){
					*(niz+j)=*(niz+j+1);
				}
				duzina--;
				i--;
				if(duzina==1)
				return 0;
			}
			
		}
			return duzina;
	}
	
	
	
	int main() {
		int mat[100];
		int i,duz=0,velicina;
		printf("Unesite niz od 10 brojeva: ");
		for(i=0;i<10;i++){
			scanf("%d",&mat[i]);
			duz++;
		}
		ubaci(mat,duz);
		velicina=izbaci(mat,2*duz);
		printf("Modificirani niz glasi: ");
		for(i=0;i<velicina-1;i++){
			printf("%d, ",mat[i]);
		}
			printf("%d.",mat[i]);
			return 0;
	}
