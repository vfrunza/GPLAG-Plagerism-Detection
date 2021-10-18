#include <stdio.h>

int main() {
int red=1,kolona=1;
int i,j,k;
long double matrica[100][100];
int teplecenova=1;
int cirkularna=1;
long double prvi_element;
long double niz[100]={555};
long double temp;
int min;

for(i=0;i<100;i++){
for(j=0;j<100;j++){
	matrica[i][j]=0;
}
}

	do
	{	
	if(red<=0 || red>100 || kolona<=0 || kolona>100) {printf("Pogresan unos!\n");}
	printf("Unesite M i N: ");
	scanf("%d %d",&red,&kolona);
	
	}while(red<=0 || red>100 || kolona>100 || kolona<=0);

	printf("Unesite elemente matrice: ");
	for(i=0;i<red;i++){
	for(j=0;j<kolona;j++){
	scanf("%ld",&matrica[i][j]);
	}
	}
	if(red==1){
	printf("Matrica je cirkularna");
	return 0;
	}
	if(kolona==1){
	printf("Matrica je Teplicova");
	return 0;
	}


	if(red==kolona || kolona<red){
	for(k=0;k<kolona;k++){
	i=0;
	j=k;
	prvi_element=matrica[i][j];
	while((i<red-1) && (j<kolona-1))
	{
	i++;
	j++;
	if(matrica[i][j]!=prvi_element){
	teplecenova=0;
	}
	}
	}
	}
	
	if(kolona>red){
	for(k=0;k<kolona;k++){
	i=0;
	j=k;
	prvi_element=matrica[i][j];
	while((i<red-1) && (j<kolona-1))
	{
	i++;
	j++;
	if(matrica[i][j]!=prvi_element){
	teplecenova=0;
	}
	}
	}
	}
	
	
	

	for(k=1;k<red;k++){
	i=k;
	j=0;
	prvi_element=matrica[i][j];
	while((i<red-1) && (j<kolona-1)){
	i++;
	j++;
	if(matrica[i][j]!=prvi_element){
	teplecenova=0;
	}
	}
	}
	
	for(i=0;i<kolona;i++){
	niz[i]=matrica[0][i];
	}



	 for (i=0; i<kolona; i++) {
     min=i;
     for (j=i+1; j<kolona; j++) {
     if (niz[j] < niz[min])
     min = j;
     }
     temp = niz[i];
     niz[i] = niz[min];
  	 niz[min] = temp;
     }
	for(k=0;k<red;k++){
	for (i=0; i<kolona; i++) {
    min=i;
    for (j=i+1; j<kolona; j++) {
    if (matrica[k][j] < matrica[k][min])
    min = j;
    }
    temp = matrica[k][i];
    matrica[k][i] = matrica[k][min];
    matrica[k][min] = temp;
    }
    }


	for(i=0;i<red;i++){
	for(j=0;j<kolona;j++){
	if(niz[j]!=matrica[i][j]) cirkularna=0;
		
	}
	}


	if(cirkularna==1) {printf("Matrica je cirkularna");
	return 0;
	}
	if(teplecenova==1){
	
	printf("Matrica je Teplicova");
	return 0;
	}

	printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
