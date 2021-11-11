#include <stdio.h>

int main() {
int n,c=0,j=0,u=1,i,m,zh,zj,x,xy,zjl=1; /*boze pomozi svima koji moraju debuggovati ovo*/





do{
	printf("Unesite broj n: ");
	scanf("%d",&n);
if ((n<1)||(n>50)){
	printf("Pogresan unos\n");
	n=0;}
	} while ((n<1)||(n>50));

 if (n==1){
	printf("***");
} else if (n==2){
printf("* * *\n");
printf(" * *");}
else{
c=(2*n-3);

zh=c;
zj=c;

	printf("*"); /*prva zvjezdica+prvi red*/
	for (j=0;j<c;j++){
		printf(" ");
		
	}
		printf("*");
	for (j=0;j<c;j++){
		printf(" ");
		
	}
		printf("*");
		printf("\n");
	
	while(1){ /*glavna petlja za slovo w*/
	
		
		if (u!=(n-1)){   /*test za razmak, dupli uslov, popravi kasnije redundantno*/
			for (i=0;i!=u;i++) {/*Razmaci na pocetku redova*/
			printf(" ");
				}
		u++;
		printf("*");
	}
	
	
	for (m=(zh-2);m>0;m--){/*razmaci od prvog * do drugog * */
		printf(" ");
	} 
	printf("*");
	zh-=2;

	for (xy=0;xy!=zjl;xy++){/*centralni razmak izmedju * i * */
		printf(" ");
	}
	printf("*");
	zjl+=2;
	
	for (m=(zj-2);m>0;m--){/*razmaci od drugog * do treceg * */
		printf(" ");
	}
	printf("*");
	zj-=2;
	
	
	
	
	
	printf("\n");
	if (zh==1){
		break;
	}
	} 
	
	for (x=0;x<(n-1);x++){ /*Zadnji red*/
		printf(" ");
		
	}
	printf("*"); 
		for (j=0;j<c;j++){
			printf(" ");
		}
		printf("*"); /*kraj zadnjeg reda*/
	}
	

	
	
	
	
	
	
	
	
	


	return 0;
}
