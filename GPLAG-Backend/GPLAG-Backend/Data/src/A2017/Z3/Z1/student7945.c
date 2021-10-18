#include <stdio.h>

int dva_od_tri(int niz_1[], int vel_1, int niz_2[], int vel_2, int niz_3[], int vel_3){
	int brojac=0,i,j,k;
	int brojac_2=0, brojac_3=0;
	
	for(i=0; i<vel_1; i++){
		for(j=0; j<vel_2; j++){
			if(niz_1[i]==niz_2[j]){
				brojac_2++;
			}
		}
	}
	for(i=0; i<vel_1; i++){
		for(k=0; k<vel_3; k++){
			if(niz_1[i]==niz_3[k]){
				brojac_2++;
			}
		}
	}
	for(j=0; j<vel_2; j++){
		for(k=0; k<vel_3; k++){
			if(niz_2[j]==niz_3[k]){
				brojac_2++;
			}
		}
	}
	for(i=0; i<vel_1; i++){
		for(j=0; j<vel_2; j++){
			for(k=0; k<vel_3; k++){
				if(niz_1[i]==niz_2[j]==niz_3[k]){
					brojac_3++;
				}
			}
		}
	}
	

	return brojac;
}


int main () {
	int niz_1[100], vel_1, niz_2[100], vel_2, niz_3[100], vel_3;
	int i, j, k, brojac=0;
	
	for(i=0; i<100; i++){
		scanf("%d", &niz_1[i]);
		if(niz_1[i]==-1){
			break;
		}
	}
	vel_1=i;
	
	for(j=0; j<100; j++){
		scanf("%d", &niz_2[j]);
		if(niz_2[j]==-1){
			break;
		}
	}
	vel_2=j;
	
	for(k=0; k<100; k++){
		scanf("%d", &niz_3[k]);
		if(niz_3[k]==-1){
			break;
		}
	}
	vel_3=k;
	
	brojac=dva_od_tri(niz_1, vel_1, niz_2, vel_2, niz_3, vel_3);
	printf("%d", brojac);
	
	return 0;
}