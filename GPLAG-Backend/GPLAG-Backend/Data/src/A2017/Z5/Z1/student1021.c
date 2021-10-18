#include <stdio.h>
#include <string.h>
struct Datum {
	int dan,mjesec,godina;
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
void pomjeri(struct Datum *dat)
{
	int dani[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
	if(((*dat).godina%4==0 && (*dat).godina%100!=0) || (*dat).godina%400==0)
		dani[1]++;
	(*dat).dan++;
	if((*dat).dan>dani[(*dat).mjesec-1]) {
		(*dat).dan=1;
		(*dat).mjesec++;
	}
	if((*dat).mjesec>12) {
		(*dat).mjesec=1;
		(*dat).godina++;
	}
}
int rodbina(char* direktor,char* kandidat)
{
	char prezimed1[50];
	char prezimed2[50];
	char prezimek1[50];
	char prezimek2[50];
	char* p1=(direktor);
	char* p2=(kandidat);
	int prvi1=0,prvi2=0,drugi1=0,drugi2=0;
	int i1=0,i2=0,j1=0,j2=0;
	int l=0,m=0;
	while(*(direktor)!='\0') {
		if(*(direktor)==' ') prvi1++;
		if(*(direktor)=='-') prvi2++;
		direktor++;
	}
	while(*(kandidat)!='\0') {
		if(*(kandidat)==' ') drugi1++;
		if(*(kandidat)=='-') drugi2++;
		kandidat++;
	}
	while(*p1!='\0') {
		if(*p1==' ') i1++;
		if(*p1=='-') i2++;
		if(i1==prvi1 && *p1!=' ' && *p1!='-' && (prvi2==0 || i2!=prvi2)) {
			prezimed1[l+1]='\0';
			prezimed1[l]=*p1;
			l++;
		}
		if(i1==prvi1 && *p1!=' ' && *p1!='-' && prvi2>0 && i2>0) {
			prezimed2[m+1]='\0';
			prezimed2[m]=*p1;
			m++;
		}
		p1++;
	}
	l=0;
	m=0;
	while(*p2!='\0') {
		if(*p2==' ') j1++;
		if(*p2=='-') j2++;
		if(j1==drugi1 && *p2!=' ' && *p2!='-' && (drugi2==0 || j2!=drugi2)) {
			prezimek1[l+1]='\0';
			prezimek1[l]=*p2;
			l++;
		}
		if(j1==drugi1 && *p2!=' ' && *p2!='-' && drugi2>0 && j2>0) {
			prezimek2[m+1]='\0';
			prezimek2[m]=*p2;
			m++;
		}
		p2++;
	}
	if(prvi2==0 && drugi2==0 && strcmp(prezimed1,prezimek1)==0) return 1;
	if(prvi2==1 && drugi2==0 && (strcmp(prezimed1,prezimek1)==0 || strcmp(prezimed2,prezimek1)==0)) return 1;
	if(prvi2==0 && drugi2==1 && (strcmp(prezimed1,prezimek1)==0 || strcmp(prezimed1,prezimek2)==0)) return 1;
	if(prvi2==1 && drugi2==1 && (strcmp(prezimed1,prezimek1)==0 || strcmp(prezimed2,prezimek1)==0 || strcmp(prezimed1,prezimek2)==0 || strcmp(prezimed2,prezimek2)==0)) return 1;
	return 0;
}
int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int i,j,k;
	struct Datum pom;
	for(i=0; i<vel; i++)	{
		if(broj_dana>=0) {
			pom.godina=(kandidati[i]).datum_rodjenja.godina;
			pom.mjesec=(kandidati[i]).datum_rodjenja.mjesec;
			pom.dan=(kandidati[i]).datum_rodjenja.dan;
			for(j=0; j<broj_dana; j++)
				pomjeri(&pom);
			if(pom.godina<direktor.datum_rodjenja.godina || (pom.godina==direktor.datum_rodjenja.godina && pom.mjesec<direktor.datum_rodjenja.mjesec) || (pom.godina==direktor.datum_rodjenja.godina && pom.mjesec==direktor.datum_rodjenja.mjesec && pom.dan<direktor.datum_rodjenja.dan)) {
				if(rodbina(direktor.ime_prezime,(kandidati[i]).ime_prezime)==0) {
					for(k=i; k<vel-1; k++) {
						kandidati[k]=kandidati[k+1];
					}
					i--;
					vel--;
				}
			}
		}
		if(broj_dana<0) {
			pom.godina=direktor.datum_rodjenja.godina;
			pom.mjesec=direktor.datum_rodjenja.mjesec;
			pom.dan=direktor.datum_rodjenja.dan;
			for(j=0; j<(-1*broj_dana); j++)
				pomjeri(&pom);
			if(pom.godina>(kandidati[i]).datum_rodjenja.godina || (pom.godina==(kandidati[i]).datum_rodjenja.godina && pom.mjesec>(kandidati[i]).datum_rodjenja.mjesec) || (pom.godina==(kandidati[i]).datum_rodjenja.godina && pom.mjesec==(kandidati[i]).datum_rodjenja.mjesec && pom.dan>(kandidati[i]).datum_rodjenja.dan)) {
				if(rodbina(direktor.ime_prezime,(kandidati[i]).ime_prezime)==0) {
					for(k=i; k<vel-1; k++) {
						kandidati[k]=kandidati[k+1];
					}
					i--;
					vel--;
				}
			}
		}
	}
	return vel;
}
int main()
{
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
