#include <stdio.h>

int daLiJeSlovo(char z){
	if((z>='a'&&z<='z')||(z>='A'&&z<='Z'))return 1;
	return 0;
}

int provjeri(char* s)
{
	char*otvoreni_tagovi[100];
	int broj_otvorenih_tagova=0,tag_je,pokusaj_otvaranja_taga;
	char*p,*t1,*t2,z1,z2;

	while(*s!='\0') {

		if(*s=='<') {
			pokusaj_otvaranja_taga=1;
			p=s+1;
			tag_je=0;
			while(*p!='\0') {
				if(*p=='<')return 0;
				if(*p=='>') {
					tag_je=1;
					pokusaj_otvaranja_taga=0;
					break;
				}
				p++;
			}
			if(pokusaj_otvaranja_taga)return 0;

			if(tag_je) {
				if(*(s+1)!='/') {
					otvoreni_tagovi[broj_otvorenih_tagova++] = s+1;
				}
				else{
					t1=otvoreni_tagovi[broj_otvorenih_tagova-1];
					t2=s+2;
					
					if(!daLiJeSlovo(*t1)||!daLiJeSlovo(*t2)) return 0;
					while(*t1!='>'&&*t2!='>'){
						z1=*t1; 
						z2=*t2;
						if(z1>='A'&&z1<='Z'){
							z1+=32;
						}
						if(z2>='A'&&z2<='Z'){
							z2+=32;
						}
						
					
						
						if(z1!=z2) return 0;
						
						t1++;
						t2++;
					}
			

					if((*t2!='>'&&*t2!=' ')||(*t1!=' '&&*t1!='>'))return 0;
					broj_otvorenih_tagova--;
				}
			}
		}

		s++;
	}
	
	if(broj_otvorenih_tagova>0)return 0;

	return 1;
}

int main()
{
char tekst1[] = "<div id=\"tekst\"><h2>Naslov</h2><p>Ovo je <b>cetvrti</b> i <i>posljednji</i> zadatak iz <a href=\"zadaca4\">zadace 4</a></p></div>";
printf("%d ", provjeri(tekst1));
	return 0;
}
