#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define BROJ_UGLOVA 500

int main() {
    
    int i,n,st,min,sek,j;
    double niz[BROJ_UGLOVA],stepeni,minute,sekunde,s,m;
    
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	printf("Uglovi su: \n");
	
	for(i=0;i<n;i++){
		scanf("%lf",&niz[i]);
	}
	
	for(i=0;i<n;i++){
		
			stepeni=niz[i]*180/PI;
			st=(int)stepeni;
			
			
			s=(double)(stepeni-st);
			minute=s*60;
			
			min=(int)minute;
			m=(double)(minute-min);
			
			sekunde=m*60;
			sek=(int)(sekunde+0.5);
			
			
			if(sek>=60){
				min++;
				sek-=60;
			}
			if(min>=60){
				st++;
				min-=60;
			}
			if(st<0){
				min=min*(-1);
				sek=sek*(-1);
			}
			
			if(sek<=30){
				printf("%d stepeni %d minuta %d sekundi\n",st,min,sek);
				
			}else if(sek>30){
				for(j=i;j<n-1;j++){
					niz[j]=niz[j+1];
				}
				n--;
				i--;
			}
			
			}

	/*printf("Uglovi su :\n");
		for(i=0;i<n;i++){
			
			printf("%d stepeni %d minuta %d sekundi\n",st[i],min[i],sek[i]);
			
		}*/
	return 0;
}
