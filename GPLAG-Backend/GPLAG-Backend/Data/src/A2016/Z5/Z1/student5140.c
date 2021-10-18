#include <stdio.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
    int br_ocjena;
};


int genijalci(struct Student* student, int vel, float prosjek){
	int i,j,istina=0,max1,max2,max3,pom,pom2,pom3;
	float suma,prosj[100],pros[100];
	/*Petlja koja izbacuje studente za nizim prosjekom*/
	for(i=0; i<vel; i++) {
		suma=0;
		istina=0;
		for(j=0; j<student[i].br_ocjena; j++){
			if(student[i].ocjene[j]==5)
				istina=1;
			suma+=student[i].ocjene[j];
		}
		if(student[i].br_ocjena==0)
			istina=1;
		prosj[i]=suma/student[i].br_ocjena;
		if(istina)
			prosj[i]=5.00;
		if(prosj[i]<prosjek){
				for(j=i; j<vel-1; j++){
					student[j]=student[j+1];
				}
				vel--;
				i--;
			}
	}
	/*Petlja koja pravi niz prosjeka svih studenata*/
	for(i=0; i<vel; i++){
		suma=0;
		for(j=0; j<student[i].br_ocjena; j++){
			suma+=student[i].ocjene[j];
		}
		pros[i]=suma/student[i].br_ocjena;
	}
	
	/*Poredak studenata po prosjeku*/
	if(vel>=3){
		max1=pros[0];
		pom=0;
		for(i=0; i<vel; i++){
			if(max1<pros[i]){
				max1=pros[i];
				pom=i;
			}
		}
		printf("%s %s\n", student[pom].prezime, student[pom].ime);
		
		max2=pros[0];
		pom2=0;
		for(i=0; i<vel; i++){
			if(max2<pros[i]){
				if(i!=pom){
					max2=pros[i];
					pom2=i;
				}else if(i==pom)
					continue;
			}
		}
		printf("%s %s\n", student[pom2].prezime, student[pom2].ime);
		
		max3=pros[0];
		pom3=0;
		for(i=0; i<vel; i++){
			if(max3<pros[i]){
				if(i!=pom2 && i!=pom){
					max3=pros[i];
					pom3=i;
				}else if(i==pom2 || i==pom)
					continue;
			}
		}
		printf("%s %s\n", student[pom3].prezime, student[pom3].ime);
	} else if(vel==2) {
		max1=pros[0];
		for(i=0; i<vel; i++){
			if(max1<pros[i]){
				max1=pros[i];
				pom=i;
			}
		}
		printf("%s %s\n", student[pom].prezime, student[pom].ime);
		
		if(pom==0)
			printf("%s %s\n", student[1].prezime, student[1].ime);
		else if(pom==1)
			printf("%s %s\n", student[0].prezime, student[0].ime);
	} else if (vel==1) {
		pom=0;
		printf("%s %s\n", student[pom].prezime, student[pom].ime);
	}
	return vel;
}

int main() {
	
	return 0;
}
