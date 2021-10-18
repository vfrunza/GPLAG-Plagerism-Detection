#include <stdio.h>
int dva_od_tri (int *nizA, int velA, int *nizB, int velB, int *nizC, int velC){
	int i,j;
	int JavljaUDvaNiza=0;
	int JavljaUJednomNizu=0;
	int brojac=0;
	int NoviNiz[1000];

	for(i=0;i<velA;i++){
		for(j=0;j<brojac;j++)
			if(nizA[i]==NoviNiz[j])break;
			if(j==brojac) NoviNiz[brojac++]=nizA[i];
	}
	
	for(i=0;i<velB;i++){
		for(j=0;j<brojac;j++)
			if(nizB[i]==NoviNiz[j])break;
			if(j==brojac) NoviNiz[brojac++]=nizB[i];
	}
	
	for(i=0;i<velC;i++){
		for(j=0;j<brojac;j++)
			if(nizC[i]==NoviNiz[j])break;
			if(j==brojac) NoviNiz[brojac++]=nizC[i];
	}
	
	for(i=0;i<brojac;i++){
		JavljaUJednomNizu=0;
		for(j=0;j<velA;j++){
			if(nizA[j]==NoviNiz[i]){
				JavljaUJednomNizu++;
				break;
			}
		}
		for(j=0;j<velB;j++){
			if(nizB[j]==NoviNiz[i]){
				JavljaUJednomNizu++;
				break;
			}
		}
		for(j=0;j<velC;j++){
			if(nizC[j]==NoviNiz[i]){
				JavljaUJednomNizu++;
				break;
		   }
		}
		if(JavljaUJednomNizu==2)
		JavljaUDvaNiza++;
	}
	return JavljaUDvaNiza;
}

int main(){
	int nizA[100], nizB[100], nizC[100];
	int i,velA,velB,velC;
	int rez;
	do {
		printf("Unesite velicinu nizova A, B i C: ");
		scanf("%d %d %d", &velA,&velB,&velC);
	} while((velA<1 || velA>100) && (velB<1 || velB>100) && (velC<1 || velC>100));

	printf("Unesite elemente niza A: ");
	for(i=0; i<velA; i++) {
		scanf("%d", &nizA[i]);
	}
	printf("Unesite elemente niza B: ");
	for(i=0; i<velB; i++) {
		scanf("%d", &nizB[i]);
	}
	printf("Unesite elemente niza C: ");
	for(i=0; i<velC; i++) {
		scanf("%d", &nizC[i]);
	}
	rez=dva_od_tri(nizA,velA,nizB,velB,nizC,velC);
	printf("%d",rez);

	return 0;
}
