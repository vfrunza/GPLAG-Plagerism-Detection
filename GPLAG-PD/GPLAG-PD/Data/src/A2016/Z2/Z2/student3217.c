#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int st=0, m=0, s=0, n, i, j;
	double niz[500], us=0 ;
	
	do {
		printf("Unesite broj uglova: ");
		
		scanf("%d", &n);
		
	} while (n < 1 || n > 500);
	
	printf("Uglovi su: \n");
	
	for(i=0; i<n ; i++){
		
		scanf("%lf", &niz[i]);
		
		us=fabs(niz[i]*180/PI)*3600;
		
		us=abs((int)(us + 0.5));
		
		st=(us/3600);
		
		m=abs((us - st*3600)/60);
		
		s=abs((us - st*3600-m*60));
		
		if(s>=60){
			m+=1;
			s-=60;
		} 
		
		if ( m>=60){
			st+=1;
			m-=60;
		}
		
		if(s > 30){
			
			for(j=i; j<n-1 ; j++ ){
				niz[j] = niz[j+1];
				
			n--;
			i--;
			
			}
			
		} 
		
		else if(niz[i]<0) printf("-%d stepeni %d minuta %d sekundi\n", st, m, s);
			
		else printf("%d stepeni %d minuta %d sekundi \n", st, m ,s);
		
	}
	
	return 0;
}
