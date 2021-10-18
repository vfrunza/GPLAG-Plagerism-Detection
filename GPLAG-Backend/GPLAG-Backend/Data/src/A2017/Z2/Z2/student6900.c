#include <stdio.h>
#include <math.h>
#define BROJ_EL 100

int main() {
	int broj_el,niz[BROJ_EL+1],rez[BROJ_EL*10+10],temp[BROJ_EL*10]={0},br,tmp,br_pomocni=0,j,i,k;
	
	printf("Unesite velicinu niza: ");
	do
		scanf("%d", &broj_el);
	while((broj_el<0)||(broj_el>BROJ_EL));
	
	printf("Unesite clanove niza: ");
	
	for (i = 0; i < broj_el; i++) {
		scanf("%d", &niz[i]);
		if(niz[i]<0)
		i--;
	}
	
	for (i = 0; i < broj_el; i++) {
		tmp=niz[i];
		br=1;
		while(tmp>=10){
			br++;
			tmp=tmp/10;
		}
		
		for (j = br_pomocni; ; j++) {
			tmp=niz[i]/(pow(10,br-1));
			temp[j]=tmp;
			niz[i]=niz[i]-tmp*(pow(10,br-1));
			br--;
			if (br==0)
			break;
		}
		br_pomocni=j+1;
	}
	temp[j+1]=-1;
	
	k=0;
	for (i = 0; ; i+=2) {
		br_pomocni=1;
		if(temp[k]==-1)
		break;
		rez[i]=temp[k];
			
		for (j = k; ; j++) {
			if (temp[k]!=temp[j+1])
			break;	else
			br_pomocni++;
		}
		rez[i+1]=br_pomocni;
		k+=br_pomocni;
	}
	br_pomocni=i;
	
	printf("Finalni niz glasi: \n");
	for (i = 0; i < br_pomocni ; i++)
		printf("%d ",rez[i]);
	
	return 0;
}
