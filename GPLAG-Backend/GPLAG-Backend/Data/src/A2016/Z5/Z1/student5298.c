#include <stdio.h>
#include <string.h>

struct Student{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int genijalci(struct Student *studenti,int vel,double prosjek){
	int i,j,suma,br,br2,br3;
	double prosjeci[1000],max;
	for(i=0;i<vel;i++){
		suma=0;
		br=1;
		if(studenti[i].br_ocjena==0){
				prosjeci[i]=5.;
				br--;
			}
		for(j=0;j<studenti[i].br_ocjena;j++){
			br=1;
			if(studenti[i].ocjene[j]==5){
				prosjeci[i]=5.;
				br--;
				break;
			}
			else suma+=studenti[i].ocjene[j];
		}
		if(br==1) prosjeci[i]=suma*1./studenti[i].br_ocjena;
	}
	for(i=0;i<vel;i++){
		if(prosjeci[i]<prosjek){
			for(j=i;j<vel-1;j++){
				prosjeci[j]=prosjeci[j+1];
				studenti[j]=studenti[j+1];
			}
			vel--;
			i--;
		}
	}
	if(vel<=3) br3=vel;
	else if(vel>3) br3=3;
	for(i=0;i<br3;i++){
		max=4.;
		br=0;
		for(j=0;j<vel;j++){
			if(prosjeci[j]>max){
				max=prosjeci[j];
				br=j;
			}
			else if(prosjeci[j]<max);
			else {
				br2=strcmp(studenti[j].prezime,studenti[br].prezime);
				if(br2>0) max=prosjeci[j];
				else if(br2<0){
					max=prosjeci[j];
					br=j;
				}
				else{
					br2=strcmp(studenti[j].ime,studenti[br].ime);
					if(br2>0) max=prosjeci[j];
					else if(br2<0){
						max=prosjeci[j];
						br=j;
					}
					else max=prosjeci[j];
				}
			}
		}
		printf("%s %s\n", studenti[br].prezime,studenti[br].ime);
		prosjeci[br]=-1.;
	}
	br=0;
	for(i=0;i<vel;i++) br++;
	return br;
}

int main() {
	
	return 0;
}