#include <stdio.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
	};
	
void unesi(char niz[], int velicina){
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
    niz[i] = znak;
    i++;
    znak = getchar();}
    
    niz[i]='\0';}
	
double pros (struct Student s){
	double prosjek;
	int suma=0, i;
		for (i=0;i<s.br_ocjena;i++){
			if (s.ocjene[i]==5 || s.br_ocjena==0){
				prosjek=5.00;
				return prosjek;
			}
			suma=suma+s.ocjene[i];
		}
	
	prosjek=(double)suma/s.br_ocjena;
	return prosjek;
	
}



int genijalci (struct Student s[], int vel, double prosjek){
	int i, j, p, q, r;
	struct Student max1, max2, max3;
	double m1, m2, m3;
	for (i=0;i<vel;i++){
		if (pros(s[i])<prosjek){
				for (j=i; j<vel-1; j++) {
                s[j] = s[j+1];
            }
            vel--;
            i--;
            
		}
	}
	m1=pros(s[0]);
	p=0;
	for (i=0;i<vel;i++){
		if (pros(s[i])>m1){
			max1=s[i];
			p=1;
		}
	}
	if (p!=0){
	printf ("%s %s\n", max1.prezime, max1.ime);}
	
	q=0;
	m2=pros(s[0]);
	for (i=0;i<vel;i++){
		if (pros(s[i])>m2 && pros(s[i])!=m1){
			max2=s[i];
			q=1;
		}
	}
	
	if (q!=0){
	printf ("%s %s\n", max2.prezime, max2.ime);}
	
	r=0;
	m3=pros(s[0]);
	for (i=0;i<vel;i++){
		if (pros(s[i])>m3 && pros(s[i])!=m1 && pros(s[i])!=m2){
			max3=s[i];
			r=1;
		}
	}
	if (r!=0){
	printf ("%s %s\n", max3.prezime, max3.ime);}
	


	return vel;
}




int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
