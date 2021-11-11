#include <stdio.h>

int main() {
		int k,j,i,a,b,c,g;
		
do{
printf("Unesite broj redova: "); scanf("%d", &a);}
while(a<=0 || a>10);

do{
printf("Unesite broj kolona: "); scanf("%d", &b);}
while (b<=0 || b>10);

do{
printf("Unesite sirinu jedne kolone: "); scanf("%d", &c);}
	while(c<=0 || c>10);
	

for(i=0;i<=2*a;i++) {
		
		for(j=1;j<=b;j++){
			
		
			if(i%2==0){printf("+");}
				if(i%2==1){printf("|");}
				
				
				for(k=0;k<c;k++){
			if(i%2==1){printf(" ");}
		if(i%2==0){printf("-");}
			}
			
		}
		if(i%2==0){printf("+");}
				if(i%2==1){printf("|");}
		printf("\n");
	}



	return 0;
}
