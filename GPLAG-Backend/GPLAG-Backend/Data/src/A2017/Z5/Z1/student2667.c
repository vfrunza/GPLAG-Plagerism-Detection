#include <stdio.h>
#include <math.h>
struct Datum {
	int dan, mjesec, godina
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{

	int j,i=0,z,f,d,m,q,w,bio=0;
	int svi=0,broj;
	broj=vel;
	int da1=0,da=0;
	for(z=0; z<broj; z++) {
		if(bio) {
			i--;
			bio=0;
		}
		da1=0;
		da=0;
		if(kandidati[i].datum_rodjenja.mjesec==1) d=31,w=29;
		else if(kandidati[i].datum_rodjenja.mjesec==2) {
			if(kandidati[i].datum_rodjenja.godina%4==0 && (kandidati[i].datum_rodjenja.godina%400==0 || kandidati[i].datum_rodjenja.godina%100!=0)) {
				d=29,w=31;
			} else d=28,w=31;
		} else if(kandidati[i].datum_rodjenja.mjesec==3) d=31,w=30;
		else if(kandidati[i].datum_rodjenja.mjesec==4) d=30,w=31;
		else if(kandidati[i].datum_rodjenja.mjesec==5) d=31,w=30;
		else if(kandidati[i].datum_rodjenja.mjesec==6) d=30,w=31;
		else if(kandidati[i].datum_rodjenja.mjesec==7) d=31,w=31;
		else if(kandidati[i].datum_rodjenja.mjesec==8) d=31,w=30;
		else if(kandidati[i].datum_rodjenja.mjesec==9) d=30,w=31;
		else if(kandidati[i].datum_rodjenja.mjesec==10) d=31,w=30;
		else if(kandidati[i].datum_rodjenja.mjesec==11) d=30,w=31;
		else if(kandidati[i].datum_rodjenja.mjesec==12) d=31,w=30;
         m=31-kandidati[i].datum_rodjenja.dan+direktor.datum_rodjenja.dan;
		if(direktor.datum_rodjenja.mjesec-kandidati[i].datum_rodjenja.mjesec==1) {
			q=0;
			f=fabs(kandidati[i].datum_rodjenja.dan-d);
			q=f+direktor.datum_rodjenja.dan;

		} else if(direktor.datum_rodjenja.mjesec==kandidati[i].datum_rodjenja.mjesec) {
			q=0;
			q=fabs(direktor.datum_rodjenja.dan-kandidati[i].datum_rodjenja.dan);
		} else {
			q=0;
			q=w+fabs(kandidati[i].datum_rodjenja.dan-d)+direktor.datum_rodjenja.dan;
		}
		char*p;

		p=kandidati[i].ime_prezime;

		while( *p!=' ') {
			p++;

		}
		p++;
		char*s;

		s=direktor.ime_prezime;
		while(*s!=' ') {
			s++;

		}
		s++;
		char *t;
		t=direktor.ime_prezime;
		while(*t!='-' && *t!='\0') {
			t++;
			 
		}
		if(*t=='-') da1=1;
		if(*t!='\0') t++;
		else t--;
        char *f; 
        f=kandidati[i].ime_prezime;
        while(*f!='\0'  && *f!='-'){
        	f++;
        }
        if(*f=='-') da=1;
        if(*f!='\0') f++;
        else f--;
        if(da1){
        if(*p==*s) {
			while(*p==*s && (*p!='\0' || *s!='\0' )) {
				p++;
				s++;
			}
		} else if(*t==*p){
			while(*t==*p && (*t!='\0' || *p!='\0')) {
				t++;
				p++;
			}
			
		}	
        }
        else if(da){
        	if(*p==*s){
        			while(*p==*s && (*p!='\0' || *s!='\0'  || *p!='-')) {
				p++;
				s++;
			}
        	}
		if(*f==*s){
			while(*f==*s && (*s!='\0' || *f!='\0')){
				f++;
				s++;
			}
	
		}
        }
		else  {
			while(*p==*s && (*p!='\0' || *s!='\0') ) {
				p++;
				s++;
			}
        }
		if((*p=='\0' || *p=='-') && (*s=='\0' || *s=='-')) {
			i++;
			continue;
		}
		else if(*t=='\0' && *p=='\0') {
			i++;
			continue;
		}
		else if(*f=='\0' && *s=='\0'){
			i++;
			continue;
		}
	    else if(kandidati[i].datum_rodjenja.mjesec==12 && direktor.datum_rodjenja.mjesec==1){
	    	if(m>fabs(broj_dana)){
	    			for(j=i; j<vel-1; j++) {
				kandidati[j]=kandidati[j+1];
			}
			j--;
			vel--;
			bio=1;
			i++;
	    	}
	    	else i++;
	    }
		else if(kandidati[i].datum_rodjenja.godina==direktor.datum_rodjenja.godina  ) {
			if(kandidati[i].datum_rodjenja.mjesec>direktor.datum_rodjenja.mjesec ) {i++;  continue; }
			
else if(fabs(kandidati[i].datum_rodjenja.mjesec-direktor.datum_rodjenja.mjesec)>2) {
	for(j=i; j<vel-1; j++) {
					kandidati[j]=kandidati[j+1];

				}
				j--;
				vel--;
				bio=1;
				i++;
}else if(direktor.datum_rodjenja.mjesec-kandidati[i].datum_rodjenja.mjesec>2) {i++; continue; }
			else if(q>fabs(broj_dana)) {
				for(j=i; j<vel-1; j++) {
					kandidati[j]=kandidati[j+1];

				}
				j--;
				vel--;
				bio=1;
				i++;
			}
			else i++;
		} else if(kandidati[i].datum_rodjenja.godina<direktor.datum_rodjenja.godina) {
			for(j=i; j<vel-1; j++) {
				kandidati[j]=kandidati[j+1];
			}
			j--;
			vel--;
			bio=1;
			i++;
		} else{ i++; continue; }
	}

	return vel;

}
int main(){
struct Uposlenik direktor = {"Mujo Mujic", {1, 1, 1992} };
struct Uposlenik kandidati[7] = {/*
    { "Meho Mehic", { 31, 1, 1990 } },
    { "Pero Peric", { 1, 2, 1990 } },
    { "Sara Sarac", { 2, 10, 1990 } },
    { "Fata Mujicic", { 1, 2, 1986 } },
    { "Jozo Jozic", { 1, 10, 1990 } },
    { "Mijo Mijic", { 4, 3, 1989 } },*/
    { "Suljo Suljc", { 15, 1, 1992 } },
};

int novi_br = suzi_listu(kandidati, 1, direktor, -15);
int i;
printf("Novi broj: %d", novi_br);
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);
return 0;
}
