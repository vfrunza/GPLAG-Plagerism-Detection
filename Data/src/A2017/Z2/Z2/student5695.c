#include <stdio.h>
int main() {
	int uneseni[100],finalni[1000],pomocni[1000],velicina_unesenog,velicina_finalnog,i,j,brojac,element,temp=0,indeks=0;
	double vel_niz;
	
	do {
		printf("Unesite velicinu niza: ");
		scanf("%lf",&vel_niz);
		velicina_unesenog=vel_niz;
	} while(vel_niz-velicina_unesenog!=0 || velicina_unesenog>100 || velicina_unesenog<0);
	
	printf("Unesite clanove niza: ");
	for(i=0;i<velicina_unesenog;i++) scanf("%d",&uneseni[i]);
	
	for(i=0;i<velicina_unesenog;i++) {
		element=uneseni[i];
		brojac=0;
		if(element==0) {
			pomocni[temp]=element;
			temp++;
		}
		else {
			while(element!=0) {
				element/=10; brojac++;
			}
			element=uneseni[i];
			for(j=temp+brojac-1;j>=temp;j--) {
				pomocni[j]=element%10;
				element/=10;
			}
			temp+=brojac;
		}
	}
	
	for(i=0;i<temp;i++) {
		finalni[indeks]=pomocni[i];
		brojac=1;
		for(j=i+1;j<temp;j++) {
			if(pomocni[i]==pomocni[j]) brojac++;
			else break;
		}
		finalni[indeks+1]=brojac;
		indeks+=2;
		i+=(brojac-1);
	}
	
	printf("Finalni niz glasi:\n");
	for(i=0;i<indeks;i++) printf("%d ",finalni[i]);
	return 0;
}