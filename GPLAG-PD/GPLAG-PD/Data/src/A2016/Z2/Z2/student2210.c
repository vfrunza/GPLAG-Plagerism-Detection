#include <stdio.h>
#define PI 3.1415926
int main() {
	float niz[500],h;
	int n,i,j,s,m,sek,k,mi;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
		printf("Uglovi su:\n");
	for(i=0;i<n;i++){
		
	scanf("%f",&niz[i]);
	}
	for(i=0;i<n;i++){
				h=(((niz[i]*180)/PI)*3600);
				h=(int)(h+0.5);
				s=(h/3600);
				k=(s*3600);
				m=((h-k)/60);
				mi=(m*60);
				sek=(h-k-mi);
  
	
	if(sek>=60){
		m++;
		sek-=60;
	}
	if(m>=60){
		s++;
		m-=60;
	}


	if(sek>30){
		for(j=i;j<n-1;j++){
			niz[j]=niz[j+1];
		}
		n--;
		i--;
	
	}
	else
	printf("%d stepeni %d minuta %d sekundi \n",s,m,sek);
	}
	 

	
   

	return 0;
}
