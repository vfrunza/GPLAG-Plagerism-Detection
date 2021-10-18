#include <stdio.h>
#define MAX_SIZE 100
int main() {
	int velicina;
	int i,j,counter=1,position=0,width=0;
	int brojevi[MAX_SIZE], rezultat[MAX_SIZE],razdvojeni[MAX_SIZE]={};
	printf("Unesite velicinu niza: ");
	scanf("%d",&velicina);
	
	printf("Unesite clanove niza: ");
	for(i=0; i<velicina; i++){
		scanf("%d", &brojevi[i]);
	};
	for(i=0;i<velicina;i++){
		if(brojevi[i]>=10){
			int digit = brojevi[i];
			int reversedNumArr[10]={0},k=0;
			while (digit>0){
				int remainder = digit%10;
				reversedNumArr[k]=remainder;
				k++;
				digit /=10;
			}
			for(j=k;j>0;j--){
				razdvojeni[width]=reversedNumArr[j-1];
				width++;
			}
			continue;
		}
		razdvojeni[width]=brojevi[i];
		width++;
	}
	
	for(i=0;i<width-1;i++){
		if(razdvojeni[i]!=razdvojeni[i+1]){
			rezultat[position]=razdvojeni[i];
			rezultat[position+1]=counter;
			position=position+2;
			counter=0;
		}
		counter++;
	}
	if(i+1==width){
		rezultat[position]=razdvojeni[i];
		rezultat[position+1]=counter;
		position=position+2;
	}
	printf("Finalni niz glasi:");
	printf("\n");
	for(i=0;i<position;i++){
		printf("%d",rezultat[i]);
		if(i!=position-1)
		printf(" ");
	}
	return 0;
}
