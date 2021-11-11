#include <stdio.h>

int main() {
	int i,j,p;
	int n;
	int br;
	br=0;
	int t;
	t=1;
	
	/*unos broja n*/
	do{
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n>50 || n<=0) printf("Pogresan unos\n");
	}while (n>50 || n<=0);
	
	i=0;
	for(j=0;j<((n-1)*4)+1;j++){
		
				if(j==(n-1)*0 || j==(n-1)*2 || j==(n-1)*4) p++;
				else { br++;}}
		
	br=br/2;
	br-=2;
	for(i=0; i<n;i++){
		for(j=0;j<((n-1)*4)+1;j++){
			if(n==1){
				for(p=0;p<3*n;p++)printf("*");
				return 0;
			}
			if(i==0){ /*prvi red*/
				
				if(j==(n-1)*0 || j==(n-1)*2 || j==(n-1)*4) {printf("*");}
				else {printf(" ");}
				
			}
			
		else if(i==n-1){ /*Zadnji red*/
			if(j==(n-1)*3 || j==n-1) printf("*");
			else {printf(" ");}
			}
			
			/*tijelo izmedju*/
			else {
				for(p=0;p<i;p++){printf(" ");j++;}
				printf("*");
				j++;
				for(p=0;p<br;p++) {printf(" ");j++;}
				
				printf("*");j++;
				for(p=0;p<t;p++){printf(" ");j++;}
				t+=2;
				printf("*");
				for(p=0;p<br;p++) {printf(" ");j++;}
				br-=2;
				printf("*");
				
				j=(n-1)*4+2;
			}
		}
		printf("\n");
	}
	
/*TOOOO SARITA <3*/
	return 0;
}
