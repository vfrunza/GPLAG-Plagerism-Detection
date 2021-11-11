#include <stdio.h>


int dva_od_tri (int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3){
	int i, j;
	int niz4[1000];
	int m=0;
	int brojac=0;
	int isti=0;
	
	for (i=0; i<vel1; i++){
		isti=0;
		for (j=0; j<i; j++){
			if (niz1[i] == niz1[j]){    //trazi duplikate u nizu ako nadje dva ista pise isti=1
				isti = 1;
			}
		}
		if (isti == 0){                //ako isti ostane 0 znaci da nije duplikat i pise ga u novi niz 
			niz4[m]=niz1[i];
			m++;
		}
	}
	
	
	for (i=0; i<vel2; i++){
		isti=0;
		for (j=0; j<i; j++){
			if (niz2[j] == niz2[i]){
				isti = 1;
			}
		}
		if (isti == 0){
			niz4[m]=niz2[i];
			m++;
			
		}
	}
	
	
	for (i=0; i<vel3; i++){
		isti = 0;
		for (j=0; j<i; j++){
			if (niz3[j] == niz3[i]){
				isti = 1;
			}
		}
		 if (isti == 0){
			niz4[m]=niz3[i];
			m++;
		}
	}
	
	 int brojac2 = 0;
	for (i=0; i<m; i++){
			brojac=0;
			for (j=0; j<m; j++){          //trazi iste brojeve u nizu, kada ih nadje brojac poveca za 1
				if (niz4[i] == niz4[j]){
					brojac++;
				}
			}
			if (brojac == 2){
				brojac2++;
			}
		}
		
		brojac2/=2;     //ako se neki element nalazi u dva niza biti ce upisan 2 puta u novi niz znaci da ce ga dva puta brojati zato dijelimo sa 2
	
	
	
	return brojac2;
}




int main() {
	
	return 0;
}
