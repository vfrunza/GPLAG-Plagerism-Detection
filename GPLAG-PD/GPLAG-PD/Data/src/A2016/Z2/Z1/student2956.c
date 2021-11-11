#include <stdio.h>
int main(){
	int n,suma=0,k=1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0) n*=-1;
	while(n>10){
	int	cifra1=n%10;
	int	cifra2=(n/10)%10;
	int	razlika=cifra2-cifra1;
	if(razlika<0) razlika*=-1;
	suma=razlika*k+suma;
	k*=10;
	n/=10;
	
		
	}
	printf("%d",suma);
	return 0;
}