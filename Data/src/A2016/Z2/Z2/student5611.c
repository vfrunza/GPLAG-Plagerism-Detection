#include <stdio.h>

int main() {
	int n,i;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	if(n>=1 && n<=499){
		float niz[500];
		int a,c,e,y,x;
		double b,d;
		
		for(i=0;i<=n-1;i++){
			scanf("%f", &niz[i]);
		}
		printf("Uglovi su: ");
		
		for(i=0;i<=n-1;i++){
			a=niz[i]*180/3.1415926;
			
			if(a<=-1){
				b=((-niz[i]*180/3.1415926)+a)*60;
				c=b;
				d=(b-c)*60;
				e=d;
				y=d*10;
				x=y%10;
				
				if(d>=59.4 && c==59){
					printf("\n%d stepeni 0 minuta 0 sekundi", a-1);
				}
				else{
					
					if(e<=29){
						if(x>=6){
							printf("\n%d stepeni %d minuta %d sekundi", a,c,e+1);
						}
						else{
							printf("\n%d stepeni %d minuta %d sekundi", a,c,e);
						}
					}
				}
			}
			else if(a>=0){
				b=((niz[i]*180/3.1415926)-a)*60;
				c=b;
				d=(b-c)*60;
				e=d;
				y=d*10;
				x=y%10;
				
				if(d>59.4 && c==59){
					printf("\n%d stepeni 0 minuta 0 sekundi", a+1);
				}
				else{
					if(e<=29){
						if(x>=6){
							printf("\n%d stepeni %d minuta %d sekundi", a,c,e+1);
						}
						else{
							printf("\n%d stepeni %d minuta %d sekundi", a,c,e);
						}
					}
				}
			}
		}
	}
	return 0;
}
