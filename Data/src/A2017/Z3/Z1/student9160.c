#include <stdio.h>

int dva_od_tri (int niz1[], int a, int niz2[], int b, int niz3[], int c){
	
	int pom1[100]={0},pom2[100]={0},pom3[100]={0};
	int i,j,k,br=0,T;
	
	//IZBACIVANJE ISTIH CLANOVA IZ NIZOVA KOJE SMO POSLALI U F-JU I KOPIRANJE U POMOCNI
	
	//PRVI NIZ
	
	for(i=0;i<a;i++){
		for(j=i+1;j<a;j++){
			if(niz1[i]==niz1[j]){
				for(k=j;k<a-1;k++){
					niz1[k]=niz1[k+1];
				}
				a--;
				j--;
			}
		}
	}
	
	for(i=0;i<a;i++){
		pom1[i]=niz1[i];
	}
	
	//DRUGI NIZ
	
	for(i=0;i<b;i++){
		for(j=i+1;j<b;j++){
			if(niz2[i]==niz2[j]){
				for(k=j;k<b-1;k++){
					niz2[k]=niz2[k+1];
				}
				b--;
				j--;
			}
		}
	}
	
	for(i=0;i<b;i++){
		pom2[i]=niz2[i];
	}
	
	
	//TRECI NIZ
	
	for(i=0;i<c;i++){
		for(j=i+1;j<c;j++){
			if(niz3[i]==niz3[j]){
				for(k=j;k<c-1;k++){
					niz3[k]=niz3[k+1];
				}
				c--;
				j--;
			}
		}
	}
	
	for(i=0;i<c;i++){
		pom3[i]=niz3[i];
	}
	
	
	//PROVJERA DVA_OD_TRI ZA PRVI I DRUGI ILI PRVI I TRECI
	
	T=0;
	
	for(i=0;i<a;i++){
		T=0;
		for(j=0;j<b;j++){
			if(pom1[i]==pom2[j]){
				br++;
				T=1;
				break;
			}
		}
		for(k=0;k<c;k++){
			if(pom1[i]==pom3[k] && T==0) {
				br++;
				break;
			}
			else if(pom1[i]==pom3[k] && T==1) {
				br--;
				break;
			}
		}
	}
	
	//PROVJERA DVA_OD_TRI ZA DRUGI I TRECI SA ISKLJUCENJEM AKO SE NALAZI I U  PRVOM 
	
	for(i=0;i<b;i++){
		T=0;
		for(j=0;j<a;j++){
			if(pom2[i]==pom1[j]){
				T=1;
				break;
			}
		}
		for(j=0;j<c;j++){
			if(pom2[i]==pom3[j] && T==0){
				br++;
				break;
			}
		}
	}
	
	return br;
	
}


int main() {

	int niz1[100],niz2[100],niz3[100];
	int a,b,c;//oznake za dimenzije nizova
	int i;

	
	printf("Dimenzije nizova: ");
	scanf("%d %d %d",&a,&b,&c);
	
	//UNOS CLANOVA NIZOVA
	
	for(i=0;i<a;i++){
		scanf("%d",&niz1[i]);
	
	}
	
	for(i=0;i<b;i++){
		scanf("%d",&niz2[i]);
		
	}
	
	for(i=0;i<c;i++){
		scanf("%d",&niz3[i]);
		
	}
	
	printf("%d",dva_od_tri(niz1,a,niz2,b,niz3,c));
	return 0;
}
