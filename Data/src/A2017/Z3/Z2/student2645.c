#include <stdio.h>
#include <math.h>
#define eps 0.1
	void zaokruzi1(float *niz, int vel){
		int i;
		int temp;
		float pom;
		int neg;
		for(i=0;i<5;i++){
			neg=0;
			pom=niz[i];
			pom*=100;
			temp=(int)pom;
			if(temp<0) {
				neg=1;
				temp=-temp;
				
			}
			
			temp+=5;
			temp/=10;
			pom=(float)temp/10.;
			if(neg) niz[i]=-pom;
			else
			niz[i]=pom;
		}
	}
	
	int sum(int x){
		
		int suma=0;
		if(x<0) x=-x;
		while(x!=0){
			suma+=x%10;
			x/=10;
		}
		return suma;
	}
	
	void preslozi(float *niz,int vel, int k){
		int i;
		int suma,suma1;
		float pom;
		int pom1;
		float temp;
		zaokruzi1(niz,vel);
		for(i=0;i<vel;i++){
			
			pom=(niz[i]*10);
		
			pom1=(int)pom;
			suma=sum(pom1);
			
			
			if(suma>=k){
				if(i!=0){
					suma1=sum(niz[i-1]*10);
					if(suma1<k){
						temp=niz[i];
						niz[i]=niz[i-1];
						niz[i-1]=temp;
						if(i>1) i-=2;
						else i--;
						
						
					}
				}
				
			}
			
			
		}
		
	}
	


int main() {
	int i;
	float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
 

	return 0;
}
