#include <stdio.h>
#include <stdlib.h>
#define vel 100

int pitanje(int niz[], int bel, int br){ 
	int i=0;
	while(i<bel){
		if(niz[i]==br){
		return 1;
		} i++;
	} return 0;
}

int dva_od_tri (int Niz1[], int bel1, int Niz2[], int bel2, int Niz3[], int bel3){
	int ponovljeni_broj=0;
	int pomocni_niz[100];
	
	int i=0;
	while(i<bel1){
		if(pitanje(Niz2,bel2,Niz1[i])==1){
			if(pitanje(Niz3,bel3,Niz1[i])==0){
				pomocni_niz[ponovljeni_broj]=Niz1[i];
				ponovljeni_broj++;
			}
		} else if(pitanje(Niz3,bel3,Niz1[i])==1){
			pomocni_niz[ponovljeni_broj]=Niz1[i];
			ponovljeni_broj++;
	} i++;
}

i=0;
while(i<bel2){
	if(pitanje(Niz3,bel3,Niz2[i])==1 && pitanje(Niz1,bel1,Niz2[i])==0){
		pomocni_niz[ponovljeni_broj]=Niz2[i];
		ponovljeni_broj++;
	} i++;
}

int zavrsni_broj=0;
i=0;
while(i<ponovljeni_broj){
	int dupli=0,j;
	for(j=i+1;j<ponovljeni_broj;j++){
		if(pomocni_niz[i]==pomocni_niz[j]){
			dupli=1;
			break;
		}
	} if(dupli==0){
		zavrsni_broj++;
	} i++;
}
       return zavrsni_broj;
}

int main (){
	int i=0,j=0,k=0,rezultat;
	int bel1,bel2,bel3;
	int Niz1[100],Niz2[100],Niz3[100];
	
	
	while(i<=vel){
		scanf("%d", &Niz1[i]);
		if(Niz1[i]==-1)
		break;
		bel1=i;
		i++;
	}
	
	
	while(j<=vel){
		scanf("%d", &Niz2[j]);
		if(Niz2[j]==-1)
		break;
		bel2=j;
		j++;
	}
	
	
	while(k<=vel){
		scanf("%d", &Niz3[k]);
		if(Niz3[k]==-1)
		break;
		bel3=k;
        k++;
	}
	rezultat=dva_od_tri(Niz1,bel1,Niz2,bel2,Niz3,bel3);
	printf("%d", rezultat);
	return 0;
}

