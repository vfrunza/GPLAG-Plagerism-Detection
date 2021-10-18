//printf("Zadaća 3, Zadatak 1");
#include <stdio.h>

int dva_od_tri(const int *niz1,int vel1,const int *niz2, int vel2,const int *niz3, int vel3) {
	
	int i;
	int br=0;
	
	int br1[1000]={0};
	int br2[1000]={0};
	int br3[1000]={0};
	
int max;

if(vel1!=0) max=niz1[0];
else if(vel2!=0) max=niz2[0];
else if(vel3!=0) max=niz3[0];


if(vel1!=0) {
	for(i=0; i<vel1;i++) {
		if(br1[niz1[i]]==0) br1[niz1[i]]++;
		if(niz1[i]>max) max=niz1[i];
	}
}
	
if(vel2!=0) {
	for(i=0; i<vel2;i++) {
		if(br2[niz2[i]]==0) br2[niz2[i]]++;
		if(niz2[i]>max) max=niz2[i];
	}
}


if(vel3!=0) {
	for(i=0; i<vel3;i++) {
		if(br3[niz3[i]]==0) br3[niz3[i]]++;
		if(niz3[i]>max) max=niz3[i];
	}
}


for(i=0; i<=max; i++) {
	if((br1[i]==br2[i] && br1[i]!=br3[i] && br1[i]!=0) || (br1[i]==br3[i] && br2[i]!=br1[i] && br1[i]!=0) || (br2[i]==br3[i] && br1[i]!=br2[i] && br2[i]!=0)) br++;
}



return br;
	
}

int main() {



int i,br;
int niz1[1000], niz2[1000], niz3[1000];
int vel1,vel2,vel3;

printf("Unesite velicinu prvog niza: ");
scanf("%d", &vel1);

printf("Unesite elemente prvog niza: ");
for(i=0; i<vel1; i++) {
	scanf("%d", &niz1[i]);
}

printf("Unesite velicinu drugog niza: ");
scanf("%d", &vel2);

printf("Unesite elemente drugog niza: ");
for(i=0; i<vel2; i++) {
	scanf("%d", &niz2[i]);
}

printf("Unesite velicinu trceg niza: ");
scanf("%d", &vel3);

printf("Unesite elemente treceg niza: ");
for(i=0; i<vel3; i++) {
	scanf("%d", &niz3[i]);
}


br=dva_od_tri(niz1,vel1,niz2,vel2,niz3,vel3);

printf("%d", br);

	return 0;
}
