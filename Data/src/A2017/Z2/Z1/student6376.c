#include <stdio.h>
#include <math.h>

int main() {
	int n,j,x,y,i,k,p,q;
	do {
	printf("Unesite broj N:");
	scanf("%d",&n);
	if (n<8 || n%4!=0) {
		printf(" Neispravno N!\n");
		
	}
}
	while (n<8 || n%4!=0);


printf("\n");
	
	/*PRVA LINIJA*/
	
	printf("\\");
	for(i=0;i<((n/2)-2);i++) {
		printf(" "); 
	}
	printf("/+");
	for(i=0;i<((n/2)-2);i++) {
		printf("-"); 
	}
	printf("+\n");
	
	/* LINIJE DO n/4 */
	
	y=(n/4);
	for(i=1;i<y;i++){
		for(k=0;k<i;k++){
			printf(" ");
		}
		
    printf("\\");
    
       x=(n/2)-2*(i+1);
		for (j=0;j<x;j++){
		printf(" ");
	}
	printf("/");
	for(k=0;k<i;k++){
			printf(" ");
		}
		printf("|");
		  x=(n/2)-2;
		for (j=0;j<x;j++){
		printf(" ");
	}
	printf("|");
		printf("\n");
}

	/*LINIJE DO n/2 */
      
      	y=(n/4);
	for(i=y;i>1;i--){
		for(k=i-1;k>0;k--){
			printf(" ");
		}
		printf("/");
		 x=(n/2)-2*(i);
		for (j=x;j>0;j--){
		printf(" ");
	}
	printf("\\");
	for(k=i-1;k>0;k--){
			printf(" ");
		}
			printf("|");
		  x=(n/2)-2;
		for (j=0;j<x;j++){
		printf(" ");
	}
	printf("|");
		printf("\n");
	}
      /* LINIJA NA n/4 */
      
      	printf("/");
	for(i=0;i<((n/2)-2);i++) {
		printf(" "); 
	}
	printf("\\+");
	for(i=0;i<((n/2)-2);i++) {
		printf("-"); 
	}
	printf("+\n");
	
	/*LINIJA NA n/4 + 1 */
		printf("+");
	for(i=0;i<((n/2)-2);i++) {
		printf("-"); 
	}
	printf("+");
	p=(n-4)/4;
	for (i=0;i<p;i++) {
		printf(" ");
	}
	printf("||");
		for (i=0;i<p;i++) {
		printf(" ");
	}
	printf("\n");
	
	/*LINIJE IZMEDJU PRVE I SREDNJIH LINIJA*/

    q=(n-8)/4;
	for (i=0;i<q;i++) {
	
	printf("|");
		  x=(n/2)-2;
		for (j=0;j<x;j++){
		printf(" ");
	}
	printf("|");
		p=(n-4)/4;
	for (j=0;j<p;j++) {
		printf(" ");
	}
	printf("||");
		for (j=0;j<p;j++) {
		printf(" ");
	}
	printf("\n");
	}
	
	/*DVIJE SREDNJE LINIJE*/
	for (k=0;k<2;k++){
		printf("|");
		  x=(n/2)-2;
		for (j=0;j<x;j++){
		printf(" ");
	}
	printf("|");
		for (i=0;i<p;i++) {
		printf("-");
	}
	printf("++");
		for (i=0;i<p;i++) {
		printf("-");
	}
	printf("\n");
	}
	
	/*LINIJE IZMEDJU SREDNJIH I ZADNJE LINIJE*/
	
	  q=(n-8)/4;
	for (i=0;i<q;i++) {
	
	printf("|");
		  x=(n/2)-2;
		for (j=0;j<x;j++){
		printf(" ");
	}
	printf("|");
		p=(n-4)/4;
	for (j=0;j<p;j++) {
		printf(" ");
	}
	printf("||");
		for (j=0;j<p;j++) {
		printf(" ");
	}
	printf("\n");
	}
	
	/*POSLJEDNJA LINIJA*/
	
		printf("+");
	for(i=0;i<((n/2)-2);i++) {
		printf("-"); 
	}
	printf("+");
	p=(n-4)/4;
	for (i=0;i<p;i++) {
		printf(" ");
	}
	printf("||");
		for (i=0;i<p;i++) {
		printf(" ");
	}
	
	
	return 0;
}
