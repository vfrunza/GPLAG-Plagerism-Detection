#include <stdio.h>

int dva_od_tri(int niz1[], int n1, int niz2[], int n2, int niz3[], int n3){

	int pomocni[1000],pomocni2[1000], pomocni3[1000],broj_el=0,br=0,i=0,j=0,z=0,t=0;

	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			if(niz1[i]==niz2[j]){
				int ima_ga=0;
				for(t=0;t<broj_el;t++){
					if(niz1[i]==pomocni[t]){
						ima_ga=1;
						break;
					}
				}
				if(ima_ga==0){
					pomocni[broj_el++]=niz1[i];
				}
			}
		}
	}
	for(i=0;i<broj_el;i++){
		int ima_ga=0;
		for(j=0;j<n3;j++){
            if(pomocni[i]==niz3[j]){
            	ima_ga=1;
            	break;
            }
		}
		if(ima_ga==0){
			br++;
		}
		
	}
	
	broj_el=0;
	for(i=0;i<n1;i++){
		for(j=0;j<n3;j++){
			if(niz1[i]==niz3[j]){
				int ima_ga=0;
				for(t=0;t<broj_el;t++){
					if(niz1[i]==pomocni2[t]){
						ima_ga=1;
						break;
					}
				}
				if(ima_ga==0){
					pomocni2[broj_el++]=niz1[i];
				}
			}
		}
	}
	for(i=0;i<broj_el;i++){
		int ima_ga=0;
	    for(j=0;j<n2;j++){
            if(pomocni2[i]==niz2[j]){
            	ima_ga=1;
            	break;
            }
		  }
		if(ima_ga==0){
			br++;
		}
	}


broj_el=0;
	for(i=0;i<n2;i++){
		for(j=0;j<n3;j++){
			if(niz2[i]==niz3[j]){
				int ima_ga=0;
				for(t=0;t<broj_el;t++){
					if(niz2[i]==pomocni3[t]){
						ima_ga=1;
						break;
					}
				}
				if(ima_ga==0){
					pomocni3[broj_el++]=niz2[i];
				}
			}
		}
	}
	for(i=0;i<broj_el;i++){
		int ima_ga=0;
	    for(j=0;j<n1;j++){
            if(pomocni3[i]==niz1[j]){
            	ima_ga=1;
            	break;
            }
		  }
		if(ima_ga==0){
			br++;
		}
	}

	return br;
}

int main(){

	int niz1[1000]={0},niz2[1000]={0},niz3[1000]={0},n1,n2,n3,i=0, rez;

	printf("Unesite broj elemenata za prvi niz: "); scanf("%d",&n1);
	printf("Unesite broj elemenata za drugi niz: "); scanf("%d",&n2);
	printf("Unesite broj elemenata za treci niz: "); scanf("%d",&n3);

	printf("Unesite elemente prvog niza: \n");
	for(i=0;i<n1;i++){
		printf("%d. clan: ",i+1);
		scanf("%d",&niz1[i]);
	}

	printf("Unesite elemente drugog niza: \n");
	for(i=0;i<n2;i++){
		printf("%d. clan: ",i+1);
		scanf("%d",&niz2[i]);
	}

	printf("Unesite elemente treceg niza: \n");
	for(i=0;i<n3;i++){
		printf("%d. clan: ",i+1);
		scanf("%d",&niz3[i]);
	}
	
	rez = dva_od_tri(niz1, n1, niz2, n2, niz3, n3);
	printf("Broj elemenata koji se ponavljaju u dva od tri niza je %d", rez);

	return 0;
}
