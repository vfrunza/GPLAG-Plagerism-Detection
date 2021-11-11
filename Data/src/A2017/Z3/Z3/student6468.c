#include <stdio.h>
#include <math.h>
#define DUZINA 100

int prebroj_cifre(int x) {
	int brojac=0;
	while(x!=0) {
		x=x/10;
		brojac++;
	}
	return brojac;
}

int vrati_broj(int niz1[],int duzina1) {
	int i,brojac=0;
	for(i=0;i<duzina1;i++) {
		if(niz1[i]==0) 
			brojac ++;
	}
	return brojac;
}


int izbaci_cifre(int niz1[],int duzina1,int niz2[],int duzina2) {
	int i,j,k;
	int velicina_niza,temp1,temp2,temp3,cifra,x,velicina;
	int niz_cifara_broja[DUZINA];
	
	for(i=0;i<duzina1;i++) {
		temp1=niz1[i];
		/*Formira se niz cifara elementa niza brojeva na koji pokazuje i*/
		for(j=0;temp1!=0;j++) {
			cifra=temp1%10;
			niz_cifara_broja[j]=cifra;
			temp1=temp1/10;
		}
		velicina_niza=prebroj_cifre(niz1[i]);
		
		for(j=0;j<velicina_niza;j++) {
			temp2=fabs(niz_cifara_broja[j]);
			for(k=0;k<duzina2;k++) {
				/*Ako je cifra broja jedana cifri koja treba biti izbacena; postavi je na nulu*/
				if(temp2==niz2[k]) niz_cifara_broja[j]=0;
			}
		}
		
		/*Izbacujemo sve nule*/
		for(j=0;j<velicina_niza;j++) {
			temp3=fabs(niz_cifara_broja[j]);
			if(temp3==0) {
				for(k=j;k<velicina_niza-1;k++) {
					niz_cifara_broja[k]=niz_cifara_broja[k+1];
				}
				velicina_niza--;
				j--;
			}
		}
		
		/*Nova velicina niza cifara elementa niza brojeva*/
		velicina=velicina_niza-vrati_broj(niz_cifara_broja,velicina_niza);
		
		/*Vracanje u niza cifara u broj*/
		for(j=i;j<=i;j++) {
			niz1[j]=0;
			for(k=0;k<velicina;k++) {
				niz1[j]+=niz_cifara_broja[k]*pow(10,k);
			}
		}
	}
	
	/*Provjera da li ima istih cifara u Nizu Cifara*/
	for(i=0;i<duzina2;i++) {
		x=niz2[i];
		for(j=i+1;j<duzina2;j++) {
			if(x==niz2[j]) return 0;
		}
	}
	/*Provjera da li ima negativnih ili vecih od nule cifara u Nizu Cifara*/
	for(i=0;i<duzina2;i++) {
		if(niz2[i]<0 || niz2[i]>9) return 0;
	}
	
	
	return 1;
}


int main() {
	int i,niz1[DUZINA],duzina1,niz2[DUZINA],duzina2,istina;
	
	printf("Duzina niza cijelih brojeva: "); scanf("%d",&duzina1);
	printf("Niz cijelih brojeva: ");
	for(i=0;i<duzina1;i++) {
		scanf("%d",&niz1[i]);
	}
	
	printf("Duzina niza cifara: "); scanf("%d",&duzina2);
	printf("Niz cifara: ");
	for(i=0;i<duzina2;i++) {
		scanf("%d",&niz2[i]);
	}
	
	istina=izbaci_cifre(niz1,duzina1,niz2,duzina2);
	
	if(istina==1) {
		for(i=0;i<duzina1;i++) {
		printf("%d ",niz1[i]);
		}
	}
	
	return 0;
}