#include <stdio.h>
void ubaci(int*niz, int vel){
	int i,suma,pomocni,j;
	for(i=0;i<2*vel;i++){
		suma=0;
		pomocni=niz[i];
		if (pomocni<0)pomocni=pomocni*(-1);
		while(pomocni!=0){
			suma+=pomocni%10;
			pomocni/=10;
		}
		for(j=(2*vel)-1;j>i;j--)
		{
			niz[j]=niz[j-1];
		}
		i++;
		niz[i]= suma;
		}
		}
		int izbaci(int*niz, int vel){
			int i,j,x,prvi,drugi,zbir;
			for(i=0;i<vel;i++){
				x=0;
				prvi=1;
				drugi=1;
				zbir=prvi+drugi;
				if(niz[i]==1) x=1;
				else if(niz[i]<1) x=0;
				else while(zbir<=niz[i]){
					if(zbir==niz[i]) x=1;
					prvi=drugi;
					drugi=zbir;
					zbir=prvi+drugi;
				}
				if(x){
					for(j=i;j<vel-1;j++)
					niz[j]=niz[j+1];
					vel--;
					i--;
				}
				}
			return vel;
		}
		int main(){
			int niz[20];
			int vel,i;
			printf("Unesite niz od 10 brojeva:");
			for(i=0;i<10;i++)
			{
				scanf("%d",&niz[i]);
			}
			ubaci(niz,10);
			vel=izbaci(niz,10*2);
			printf("Modificirani niz glasi:");
			for(i=0;i<vel;i++)
			if(i==vel-1) 
			printf("%d.",niz[i]);
			else 
			printf("%d,",niz[i]);
			
			
		return 0;
			}
		
		
		
		
	
