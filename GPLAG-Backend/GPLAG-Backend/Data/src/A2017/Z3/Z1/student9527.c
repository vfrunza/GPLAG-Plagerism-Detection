#include <stdio.h>
#define EL 100

/*int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3) {
	
    int i, brojac=0, j, k, p[EL], clan=0, e;
    for(i=0;i<vel1;i++) {
    	if(i==vel1-1) continue;
    	if(niz1[i]==niz1[i+1]) {
    		niz1[i]=niz1[vel1-1];
    		vel1--;
    		i--;
    		}
    	}
    	
    for(i=0;i<vel2;i++) {
    	if(i==vel2-1) continue;
    	if(niz2[i]==niz2[i+1]) {
    		niz2[i]=niz2[vel2-1];
    		vel2--;
    		i--;
    		}
    	}
    	
    for(i=0;i<vel3;i++) {
    	if(i==vel3-1) continue;
    	if(niz3[i]==niz3[i+1]) {
    		niz3[i]=niz3[vel3-1]<
    		vel3--;
    		i--;
    	}
    }
    
    for(i=0;i<vel1;i++) {
    	for(j=0;j<vel2;j++) {
    		for(k=0;k<vel3;k++) {
    			if(niz1[i]==niz2[j] && niz2[j]==niz3[k]) {
    				p[clan]=niz2[i];
    				clan++;
    			}
    		}
    	}
    }
    
    for(e=0;e<clan;e++) {
    	for(i=0;i<vel1;i++) {
    		if(niz1[i]==p[e]) {
    			niz1[i]=niz1[vel1-1];
    			vel1--;
    			i--;
    		}
    	}
    }
    for(e=0;e<clan;e++) {
    	for(j=0;j<vel2;j++) {
    		if(niz2[j]==p[e]) {
    			niz2[j]=niz2[vel2-1];
    			vel2--;
    			j--;
    		}
    	}
    }
    for(e=0;e<clan;e++) {
    	for(k=0;k<vel3;k++) {
    		if(niz3[k]==p[e]) {
    			niz3[k]=niz3[vel3-1];
    			vel3--;
    			k--;
    		}
    	}
    }
    
    for(i=0;i<vel1;i++) {
    	for(j=0;j<vel2;j++) {
    		if(niz1[i]==niz2[j] && niz1[i]!=niz3[i])
    		brojac++;
    	}
    }
    
    for(i=0;i<vel2;i++) {
    	for(j=0;j<vel3;j++) {
    		if(niz2[i]==niz3[j] && niz2[i]!=niz1[i])
    		brojac++;
    	}
    }
    
    for(i=0;i<vel1;i++) {
    	for(j=0;j<vel3;j++) {
    		if(niz1[i]==niz3[j] && niz1[i]!=niz2[i])
    		brojac++;
    	}
    }

    return brojac;
}

int main() {
	
	int niz1[EL], niz2[EL], niz3[EL], i, n1, n2, n3;
	
	printf("niz1:");
	for(i=0;i<EL;i++) {
		scanf("%d", &niz1[i]);
		if(niz1[i]==-1)
		break;
	}
	n1=i;
	printf("niz2:");
	for(i=0;i<EL;i++) {
		scanf("%d", &niz2[i]);
		if(niz2[i]==-1)
		break;
	}
	n2=i;
	printf("niz3:");
	for(i=0;i<EL;i++) {
		scanf("%d", &niz3[i]);
		if(niz3[i]==-1)
		break;
	}
	n3=i;
	dva_od_tri(niz1,n1,niz2,n2,niz3,n3);
	
	return 0;
}
*/


#include <stdio.h>
#define VELICINA 200
#define NOVA 400

int dva_od_tri(int niz1[], int brojac1, int niz2[], int brojac2, int niz3[], int brojac3) {
	int i, j, k, niz4[NOVA], niz5[NOVA], niz6[NOVA], brojac4=0, brojac5=0, brojac6=0;
	int niz7[1000], brojac7=0;
	int niz_brojevi[1000], brojac8, clan;
	
//	Nalazenje zajednickih clanova niza 1 i 2
	for(i=0;i<brojac1;i++) {
		for(j=0;j<brojac2;j++) {
			if(niz1[i]==niz2[j]) {
				niz4[brojac4]=niz2[j];
				brojac4++;
			}
		}
	}
	
	
//	Nalazenje zajednickih clanova niza 1 i 3
	for(i=0;i<brojac1;i++) {
		for(j=0;j<brojac3;j++) {
			if(niz1[i]==niz3[j]) {
				niz5[brojac4]=niz3[j];
				brojac5++;
			}
		}
	}
	
	
//	Nalazenje zajednickih clanova 2 i 3
	for(i=0;i<brojac2;i++) {
		for(j=0;j<brojac3;j++) {
			if(niz2[i]==niz3[j]) {
				niz6[brojac6]=niz3[j];
				brojac6++;
			}
		}
	}
	
	
//	Nalazenje elemenata koji su zajednicki u sva tri niza
	brojac7=0;
	for(i=0;i<brojac4;i++) {
		for(j=0;j<brojac5;j++) {
			for(k=0;k<brojac6;k++) {
				if(niz4[i]==niz5[j] && niz4[i]==niz6[k] && niz5[j]==niz6[k]) {
					niz7[brojac7]=niz4[i];
					brojac7++;
				}
			}
		}
	}
	
//	Brisanje zajednickih elemenata sva tri niza iz niza1, niza2, niza3
	for(i=0;i<brojac7;i++) {
		clan=niz7[i];
		for(j=0;j<brojac4;j++) {
			if(niz4[j]==clan) {
				niz4[j]=niz1[brojac4-1];
				brojac4--;
				j--;
			}
		}
	}
	
	
	for(i=0;i<brojac7;i++) {
		clan=niz7[i];
		for(j=0;j<brojac5;j++) {
			if(niz5[j]==clan) {
				niz5[j]=niz5[brojac2-1];
				brojac5--;
				j--;
			}
		}
	}
	
	
	for(i=0;i<brojac7;i++) {
		clan=niz7[i];
		for(j=0;j<brojac6;j++) {
			if(niz6[j]==clan) {
				niz6[j]=niz6[brojac6-1];
				brojac6--;
				j--;
			}
		}
	}
	
//	Pravim niz svih brojeva koji se pojavljuju u dva od tri niza
	brojac8=brojac4+brojac5+brojac6;
	for(i=0;i<brojac8;i++) {
		if(brojac8>=0 && brojac8<brojac4) {
			niz_brojevi[i]=niz4[i];
		} else if(brojac8>=brojac4 && brojac8<(brojac4+brojac5)) {
			niz_brojevi[i]=niz5[i-brojac4-brojac5];
		} else niz_brojevi[i]=niz6[i-brojac4-brojac5-brojac6];
	}
	
	for(i=0;i<brojac8;i++) {
    	//if(i==brojac8-1) continue;
    	for(j=1;j<brojac8;j++){
    	if(niz_brojevi[i]==niz_brojevi[j]) {
    		niz_brojevi[i]=niz_brojevi[brojac8-1];
    		brojac8--;
    		i--;
    		j--;
    	}
    		}
    	}
	
	for(i=0;i<brojac8;i++) {
		printf("%d ", niz_brojevi[i]);
	}
	
	return 1;
}

int main() {
	int niz1[VELICINA], niz2[VELICINA], niz3[VELICINA];
	int i,duz1,duz2,duz3;
	
	printf("Unesite duzinu prvog niza: ");
	scanf("%d", &duz1);
	printf("Unesite elemente prvog niza: ");
	for(i=0;i<duz1;i++) {
		scanf("%d", &niz1[i]);
	}
	
	printf("Unesite duzinu drugog niza: ");
	scanf("%d", &duz2);
	printf("Unesite elemente drugog niza: ");
	for(i=0;i<duz2;i++) {
		scanf("%d", &niz2[i]);
	}
	printf("Unesite duzinu treceg niza: ");
	scanf("%d", &duz3);
	printf("Unesite elemente treceg niza: ");
	for(i=0;i<duz3;i++) {
		scanf("%d", &niz3[i]);
	}
	
	dva_od_tri(niz1,duz1,niz2,duz2,niz3,duz3);
	//printf("Zadaća 3, Zadatak 1");
	return 0;
}