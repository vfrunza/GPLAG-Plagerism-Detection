#include <stdio.h>
#include<math.h>
void ubaci(int niz[],int d){
	int i,p,a,s;
	p=2*d-2;
	for(i=d-1;i>=0;i--){
		niz[p]=niz[i];
		p=p-2;
	}	
	for(i=0;i<2*d;i+=2){
		s=0;
		a=fabs(niz[i]);
			do{
				s=s+a%10;
				a=a/10;
				}while(a>0);
				niz[i+1]=s;
			}
}

int izbaci(int niz[],int v){
	int i,f1,f2,f3,j;

	for(i=0;i<v;i++){
		f1=1;
		f2=1;
		f3=1;
	
		
		while(f2<=niz[i]){
			f1=f2+f3;
			f2=f3;
			f3=f1;
			if(niz[i]==f2){
				for(j=i;j<v-1;j++) {
					niz[j]=niz[j+1];
			
				}
		v--;
		i--; 
		break;
			}
		
		}
		
	}
	return v;
}


int main() {
	int niz[20],i,x;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	x=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<x;i++){
		if(i<x-1){
		printf("%d, ", niz[i]);
		}
		else{
			printf("%d.", niz[i]);
		}
	}
	
	return 0;
}





