#include <stdio.h>
#include <math.h>

int Fibonacci[46];
void popuniFibonacci(){
	int i=2;
	int prvi,drugi;
	Fibonacci[0]=1;
	Fibonacci[1]=1;
	prvi=Fibonacci[0];
	drugi=Fibonacci[1];
	while(i<46){
		Fibonacci[i]=prvi+drugi;
		prvi = drugi;
		drugi = Fibonacci[i];
		i++;
	}
}
int jelFibonacci(int broj){
	int i;
	for(i=0;i<46;i++){
		if(broj==Fibonacci[i]) return 1;
	}
	return 0;
}
int suma(int broj){
	int sumica;
	broj = fabs(broj);
	sumica = 0;
	while(broj!=0){
		sumica += broj%10;
		broj/=10;
	}
	return sumica;
}

void ubaci(int *pok,int vel){
	int niz[100]; 
	int *poc=pok;
	int i;
	for(i=0;i<vel*2;i+=2){
		niz[i]=*(poc);
		niz[i+1]=suma(*(poc));
		poc++;
	}
	for(i=0;i<vel*2;i++){
		*(pok)=niz[i];
		pok++;
	}
	
	
}
int izbaci(int *pok,int vel){
	
	popuniFibonacci();
	
	int *kraj;
	int *poc;
	int i;
	int temp;
	int niz[100];
	int j=0;
	poc = pok;
	kraj = pok+vel;
	while(poc<kraj){
		if(!jelFibonacci(*(poc))){
			niz[j] = *(poc);
			poc++;
			j++;
		}
		else{
			poc++;
		}
	}
	if(j==0) return 0;
	
	for(i=0;i<j;i++){
		*(pok)=niz[i];
		pok++;
	}
	return j;
}

int main() {
	int niz[20];
	int i;
	popuniFibonacci();
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	int vel=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i = 0;i<vel;i++){
		if(i==vel-1) printf("%d.",niz[i]);
		else printf("%d, ",niz[i]);
	}
	
	return 0;
}
