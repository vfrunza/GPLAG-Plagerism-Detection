#include <stdio.h>

int dva_od_tri(int niz1[], int velicina1, int niz2[], int velicina2, int niz3[], int velicina3){
	int i, j, k, br_clanova=0, broj, ima_li=0, niz4[50], velicina4=0, p, niz5[50], velicina5=0, niz6[50], velicina6=velicina2;
	
	for(i=0; i<velicina2; i++){
		niz6[i]=niz2[i];
	}
	
	if(velicina1==0){
		for(i=0; i<velicina2; i++){
			for(j=0; j<velicina3; j++){
				if(niz2[i]==niz3[j]){
					br_clanova++;
					break;
				}
			}
		}
		return br_clanova;
	}else if(velicina2==0){
		for(i=0; i<velicina1; i++){
			for(j=0; j<velicina3; j++){
				if(niz1[i]==niz3[j]){
					br_clanova++;
					break;
				}
			}
		}
		return br_clanova;;
	}else if(velicina3==0){
		for(i=0; i<velicina1; i++){
			for(j=0; j<velicina2; j++){
				if(niz1[i]==niz2[j]){
					br_clanova++;
					break;
				}
			}
		}
		return br_clanova;
	}
	
	for(i=0; i<velicina1; i++){
		broj=niz1[i];
		ponovo: for(p=0; p<velicina4; p++){
			if(niz4[p]==broj && i<=velicina1-1){
				broj=niz1[++i];
				if(i<velicina1-1) goto ponovo;
				else goto izlaz;
			}
		}
		for(j=0; j<velicina2; j++){
			if(niz2[j]==broj){
				ima_li=1;
				break;
			}
		}
		for(k=0; k<velicina3; k++){
			if(niz3[k]==broj && ima_li==1){
				ima_li=0;
				break;
			}else if(niz3[k]==broj && ima_li==0){
				ima_li=1;
				break;
			}
		}
		if(ima_li) br_clanova++;
		ima_li=0;
		niz4[i]=broj;
		velicina4++;
	}
	izlaz:
	
	for(i=0; i<velicina1; i++){
		for(j=0; j<velicina6; j++){
			if(niz1[i]==niz6[j]){
				niz6[j]=niz6[velicina6-1];
				velicina6--;
				j--;
			}
		}
	}
	
	for(i=0; i<velicina6; i++){
		broj=niz6[i];
		opet:
		for(p=0; p<velicina5; p++){
			if(broj==niz5[p]){
				broj=niz6[++i];
				if(i<velicina1-1) goto opet;
				else goto vani;
			}
		}
		for(j=0; j<velicina3; j++){
			if(broj==niz3[j]){
				br_clanova++;
				break;
			}
		}
		niz5[i]=broj;
		velicina5++;
	}
	vani:
	
	
	return br_clanova;
}

int main(){
	int br_clanova,velicina1,velicina2,velicina3,niz1[100], niz2[100], niz3[100], i, j, k;
	printf("Unesi velicinu prvog niza: ");
	scanf("%d", &velicina1);
	printf("Unesi velicinu drugog niza: ");
	scanf("%d", &velicina2);
	printf("Unesi velicinu treceg niza: ");
	scanf("%d", &velicina3);
	for(i=0; i<velicina1; i++){
		printf("Unesi clanove prvog niza: ");
		scanf("%d", &niz1[i]);
	}
	for(j=0; j<velicina2; j++){
		printf("Unesi clanove drugog niza: ");
		scanf("%d", &niz2[j]);
	}
	for(k=0; k<velicina3; k++){
		printf("Unesi clanove treceg niza: ");
	scanf("%d", &niz3[k]);
	}
	br_clanova=dva_od_tri(niz1, velicina1, niz2, velicina2, niz3, velicina3);
	

printf("Funkcija vraca broj %d", br_clanova);
return 0;
}
