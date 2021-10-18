#include<stdio.h>

int main() {
	int broj_tacaka=0,i,j,brojac=0;
	
char m[20][20];

for(i=0;i<20;i++){
	for(j=0;j<20;j++){
		
	m[i][j]=' ';
    }
}
while(broj_tacaka<=0 || broj_tacaka>10){
	printf("Unesite broj tacaka: ");
	scanf("%d",&broj_tacaka);
	
	if(broj_tacaka<=0 || broj_tacaka>10){
		printf("Pogresan unos\n");
	}
}

while(brojac<broj_tacaka){
	printf("Unesite %d. tacku: ",++brojac);
	scanf("%d %d",&j,&i);
	
	if(i<0 || i>19 || j<0 || j>19){
	printf("Pogresan unos\n");
	
	brojac--;
	
	continue;
	
	}
	
	m[i][j]='*';
    
	
    }

 for(i=0;i<20;i++){
 	for(j=0;j<20;j++){
 		printf("%c",m[i][j]);
 	}
 	printf("\n");
 }

	
	
	return 0;
}
