#include <stdio.h>
#include <string.h>
#include <math.h>
#define eps 0.0001
struct Student{
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};
/*Nova funk prima pokazivace!!!!*/
int LeksPoredi(struct Student* s1, struct Student* s2){
	if(s1 == 0 || s2 == 0){
		return -1;
	}
	if(strcmp(s1->prezime, s2->prezime) == 0){
		return (strcmp(s1->ime, s2->ime));
	} else {
		return strcmp(s1->prezime, s2->prezime);
	}
	
	return 0;
}
/*pomocna funkcija koja racuna prosjek*/
double prosjek_ocjena(struct Student* s){
	
	if (s == 0) return 0;
	int x, sum=0;
	if(s->br_ocjena==0) return 5.0;
	for(x=0;x<s->br_ocjena;x++){
		if(s->ocjene[x]==5) return 5.0;
		else
			sum+=s->ocjene[x];
	}
	return (double)sum/s->br_ocjena;
}
/*vraca broj preostalih studenata pa je zato int*/
int genijalci(struct Student* s, int velicina, double prosjek){
	int i,j;
	double max1=-1,max2=-1,max3=-1;
	struct Student *s1,*s2,*s3,*pom;
	s1 = s2 = s3 = 0;
	/*izbacivanje*/
	for(i=0;i<velicina;i++){
		if(prosjek_ocjena(&s[i])<prosjek){
			for(j=i;j<velicina-1;j++){
				s[j]=s[j+1];
			}
			velicina--;
			i--;
		}
	}
	/*trazenje max prosjeka tri studenta*/
	for(i=0;i < velicina; i++){
		if(prosjek_ocjena(&s[i])>max1){
			max3=max2;
			max2=max1;
			max1=prosjek_ocjena(&s[i]);
			s3=s2;
			s2=s1;
			s1=&s[i];
		}
		else if(prosjek_ocjena(&s[i])>max2) {
			max3=max2;
			max2=prosjek_ocjena(&s[i]);
			s3=s2;
			s2=&s[i];
		}
		else { 
			max3=prosjek_ocjena(&s[i]);
			s3=&s[i];
		}
	
		/*leksikografski*/
		if(LeksPoredi(s3,s2) < 0 && fabs(prosjek_ocjena(s2) - prosjek_ocjena(s3)) < eps) {
			pom = s2;
			s2 = s3;
			s3 = pom;
		}
		if (LeksPoredi(s2,s1) < 0 && fabs(prosjek_ocjena(s1) - prosjek_ocjena(s2)) < eps) {
			pom = s1;
			s1 = s2;
			s2 = pom;
		}
	}
	
	if(s1 != 0) printf("%s %s\n", s1->prezime,s1->ime);
	if(s2 != 0) printf("%s %s\n", s2->prezime,s2->ime);
	if(s3 != 0) printf("%s %s\n", s3->prezime,s3->ime);
	
	return velicina;
}

int main() {
	struct Student studenti[3]={{"Asko","Askic",{6,6,7},3},{"Besko","Beskic",{7,7,7,7,7,7,7},7},{"Edko","Edkic",{7,7,7,7,7,7,8},7}};
	genijalci(studenti,3,7.0);
	return 0;
}
