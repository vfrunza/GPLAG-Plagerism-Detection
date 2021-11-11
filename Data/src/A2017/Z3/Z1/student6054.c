#include <stdio.h>
int dva_od_tri (int*niza,int vela,int*nizb,int velb,int*nizc,int velc)
{
	int i,j,k,temp,m,n,min,o,brojac=1,velx,brojacx=0;
	int nizx[300],nizaa[100],nizbb[100],nizcc[100];
	for(i=0; i<vela; i++) {
		nizaa[i]=niza[i];
	}
	for(j=0; j<velb; j++) {
		nizbb[j]=nizb[j];
	}
	for(k=0; k<velc; k++) {
		nizcc[k]=nizc[k];
	}
	/*sortiranje niza a*/
	for(i=0; i<vela; i++) {
		min=i;
		for(j=i+1; j<vela; j++) {
			if(nizaa[j]<nizaa[min]) {
				min=j;
			}
		}
		temp=nizaa[i];
		nizaa[i]=nizaa[min];
		nizaa[min]=temp;
	}
	/*izbacivanje duplikata iz niza a*/
	for(i=0; i<vela; i++) {
		for(j=i+1; j<vela; j++) {
			if(nizaa[i]==nizaa[j]) {
				for(m=j; m<vela; m++) {
					nizaa[m]=nizaa[m+1];
				}
				vela--;
				j--;
			}
		}
	}
	/*sortiranje niza b*/
	for(i=0; i<velb; i++) {
		min=i;
		for(j=i+1; j<velb; j++) {
			if(nizbb[j]<nizbb[min]) {
				min=j;
			}
		}
		temp=nizbb[i];
		nizbb[i]=nizbb[min];
		nizbb[min]=temp;
	}
	/*izbacivanje duplikata iz niza b*/
	for(i=0; i<velb; i++) {
		for(j=i+1; j<velb; j++) {
			if(nizbb[i]==nizbb[j]) {
				for(n=j; n<velb; n++) {
					nizbb[n]=nizbb[n+1];
				}
				velb--;
				j--;
			}
		}
	}
	/*sortiranje niza c*/
	for(i=0; i<velc; i++) {
		min=i;
		for(j=i+1; j<velc; j++) {
			if(nizcc[j]<nizcc[min]) {
				min=j;
			}
		}
		temp=nizcc[i];
		nizcc[i]=nizcc[min];
		nizcc[min]=temp;
	}
	/*izbacivanje duplikata iz niza c*/
	for(i=0; i<velc; i++) {
		for(j=i+1; j<velc; j++) {
			if(nizcc[i]==nizcc[j]) {
				for(o=j; o<velc; o++) {
					nizcc[o]=nizcc[o+1];
				}
				velc--;
				j--;
			}
		}
	}
	/*prepisivanje nizova u novi nizx*/
	for(i=0; i<vela; i++) {
		nizx[i]=nizaa[i];

	}
	for(j=0; j<velb; j++) {
		nizx[j+i]=nizbb[j];
	}
	for(k=0; k<velc; k++) {
		nizx[k+j+i]=nizcc[k];
	}
	velx=k+j+i;
	/*sortiranje nizax*/
	for(i=0; i<velx; i++) {
		min=i;
		for(j=i+1; j<velx; j++) {
			if(nizx[j]<nizx[min]) {
				min=j;
			}
		}
		temp=nizx[i];
		nizx[i]=nizx[min];
		nizx[min]=temp;
	}
	/*prebrojavanje clanova koji se poavljaju u 2 od 3 niza*/
	for(i=0; i<velx-1; i++) {
		if(nizx[i]==nizx[i+1]) {
			brojac++;
		} else {
			if(brojac==2) {
				brojacx++;
			}
			brojac=1;
		}
	}
	if(brojac==2)brojacx++;

	return brojacx;

}
int main()
{
	int niza[100],nizb[100],nizc[100];
	int i,k,l,brojac,vela,velb,velc;
	printf("Unesite velicinu niza A: ");
	scanf("%d",&vela);
	printf("Unesite clanove niza A: ");
	/*unos niza a*/
	for(i=0; i<vela; i++) {
		scanf("%d",&niza[i]);
	}
	/*unos niza b*/
	printf("Unesite velicinu niza B: ");
	scanf("%d",&velb);
	printf("Unesite clanove niza B: ");
	for(k=0; k<velb; k++) {
		scanf("%d",&nizb[k]);
	}

	/*unos niza c*/
	printf("Unesite velicinu niza C: ");
	scanf("%d",&velc);
	printf("Unesite clanove niza C: ");
	for(l=0; l<velc; l++) {
		scanf("%d",&nizc[l]);
	}

	brojac=dva_od_tri(niza,vela,nizb,velb,nizc,velc);
	printf("%d",brojac);


	return 0;
}
