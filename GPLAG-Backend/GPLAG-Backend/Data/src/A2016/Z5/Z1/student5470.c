#include <stdio.h>
struct Student {
	char ime[20], prezime[20];
	int ocjene[50]; //sve ocjene koje je student stekao tokom studija
	int br_ocjena; //broj članova tog niza
};
int genijalci(struct Student* studenti,int vel, float prosjek) {
	int i,j,k,br=0,max=-1,temp=-1;
	float prosjek1[100]={0},s=0;
	for(i=0; i<vel; i++) {
		for(j=0;j<studenti[i].br_ocjena;j++) {
			if(studenti[i].ocjene[j]==5) {
				prosjek1[i]=5;
				j=studenti[i].br_ocjena;
			}
			s+=studenti[i].ocjene[j];
		}
		if(s==0) prosjek1[i]=5;
		else if(prosjek1[i]!=5)
			prosjek1[i]=(float)s/studenti[i].br_ocjena;
		if (prosjek1[i]<prosjek) {
			for(k=i;k<vel-1;k++)
				studenti[k]=studenti[k+1];
				vel--;
				i--;
		}
		s=0;
	}
	for(i=0;i<vel;i++) {
		if(prosjek1[i]>max) {
			max=prosjek1[i];
			temp=i;
		}
	}
	if(temp!=-1) printf("%s %s\n",studenti[temp].prezime,studenti[temp].ime);
	
	
	return vel;
}
int main() {
	struct Student studenti[100];
	int vel,i,j;
	float prosjek;
	printf("Unesite velicinu i prosjek:");
	scanf("%d %f",&vel,&prosjek);
	for(i=0;i<vel;i++) {
		printf("unesite ime prezime broj ocjena studenta:\n");
		scanf("%s%s%d",studenti[i].ime,studenti[i].prezime,&studenti[i].br_ocjena);
		printf("unesite ocjene studenta:\n");
		for(j=0; j<studenti[i].br_ocjena; j++)
			scanf("%d",&studenti[i].ocjene[j]);
	}
	genijalci(studenti,vel,prosjek);
	return 0;
}
