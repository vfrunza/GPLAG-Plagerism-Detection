#include <stdio.h>


int vel=10;

int DaLiJeFibonacijev(int x){
	int pom,i,j;
	if(x<=0) return 0;
	else if(x==1) return 1;
	
	i=1;
	j=1;
	while(i+j<=x){
		if(i+j==x) return 1;
		
		pom=j;
		j=i+j;
		i=pom;
	}
	return 0;
}
void ubaci(int niz[],int vel){
	int i=0,br,pomVel=vel;
	for(br=0;br<pomVel;br++){
			int novi=0,x=niz[i],j;
			if(x<0) x*=-1;
		while(x>0){
		
			novi+=x%10;
			x/=10;
		}
		vel++;
		for(j=vel-1;j>i+1;j--)
			niz[j]=niz[j-1];
			
		
     	niz[i+1]=novi;
	     i+=2;
		 
	}
	
}
int izbaci(int niz[],int vel){
	int i,j;
	
	for(i=0;i<vel;i++)
	if(DaLiJeFibonacijev(niz[i])==1){
		
		for(j=i;j<vel-1;j++)
			niz[j]=niz[j+1];
		
		vel--;
		i--;
		 

		}

return vel;
}

int main()
{
int niz[100],i;
printf("Unesite niz od %d brojeva: ",vel);
	
 for(i=0;i<vel;i++)
	scanf("%d",&niz[i]);

	
ubaci(niz, vel); vel*=2;
vel=izbaci(niz, vel); 

printf("Modificirani niz glasi: ");
for(i=0;i<vel;i++)
{
	if(i==vel-1) printf("%d.",niz[i]);
     else  printf("%d, ",niz[i]);
}
	return 0;
}