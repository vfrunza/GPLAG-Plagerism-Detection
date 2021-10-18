#include <stdio.h>
#include <string.h>

struct Datum {
	int dan,mjesec,godina;
};

int dim[12]= {31,59,90,120,151,181,212,243,273,304,334,365};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int br_dana(struct Datum d)
{
	/*vraca broj dana od datuma 1/1/1 do d*/
	return ((d.godina-1)*365+(d.mjesec>1 ? dim[d.mjesec-2] :0)+d.dan-1+(d.mjesec>2 ? d.godina/4-d.godina/100+d.godina/400 :
	        (d.godina-1)/4-(d.godina-1)/100+(d.godina-1)/400));
}

int razlika_datuma(struct Datum d1,struct Datum d2)
{
	return br_dana(d1)-br_dana(d2);
}

void izdvoji_prezime(char *s,char *c,char x)
{
	/*izdvaja prezime do znaka razmaka ili crtice*/
	int i=strlen(s),j;
	while(s[--i]!=x && s[i]!=' ');
	for(j=0; s[i++]!='\0'; j++) {
		*(c+j)=s[i];
	}
}

void do_crtice(char *s)
{
	int i=0;
	while(*(s+i++)!='\0') {
		if(*(s+i)=='-') {
			*(s+i)='\0';
			break;
		}
	}
}

int ista_prezimena(char p1[],char p2[])
{
	char s1[50],s2[50],b1[50],b2[50];
	izdvoji_prezime(p1,s1,' ');
	izdvoji_prezime(p2,s2,' ');
	izdvoji_prezime(p1,b1,'-');
	izdvoji_prezime(p2,b2,'-');
	do_crtice(s1);
	do_crtice(s2);
	if(strcmp(s1,s2)==0 || strcmp(s1,b2)==0 || strcmp(b1,s2)==0 || strcmp(b1,b2)==0)
		return 0;
	return 1;
}

int suzi_listu(struct Uposlenik* kandidati,int vel,struct Uposlenik direktor,int broj_dana)
{
	int i,j;
	for(i=0; i<vel; i++) {
		if(razlika_datuma(direktor.datum_rodjenja,kandidati[i].datum_rodjenja)>broj_dana)
			if(ista_prezimena(direktor.ime_prezime,kandidati[i].ime_prezime)!=0) {
				vel--;
				for(j=i--; j<vel; j++) {
					kandidati[j]=kandidati[j+1];
				}
			}
	}
	return vel;
}

int main()
{
	int i=0,novi_br;
	struct Uposlenik dat10= {"Mujo Mujic",{3,3,1992}};
	struct Uposlenik kat10[7]=
	{
		{"Meho Mehic",{31,1,1990}},
		{"Pero Peric",{1,2,1990}},
		{"Sara Sarac",{2,2,1990}},
		{"Fata Mujicic",{1,2,1986}},
		{"Jozo Jozic-Mujic",{1,10,1990}},
		{"Mijo Mujic-Mijic",{4,3,1989}},
		{"Suljo Suljic",{31,12,1991}}};
	novi_br=suzi_listu(kat10,7,dat10,3);
	printf("Nakon suzenja liste: ");
	for(i=0;i<novi_br;i++){
		printf("%s ",kat10[i].ime_prezime);
	}
	return 0;
}
