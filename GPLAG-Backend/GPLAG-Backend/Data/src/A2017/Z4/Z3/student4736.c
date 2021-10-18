#include <stdio.h>

int daLiJeSlovo(char z)
{
	if(z>='a'&&z<='z' || z>='A'&&z<='Z') {
		return 1;
	}
	return 0;
}

void najduzi_bp(char* s1, char* s2)
{

	char *pocetak_najduzeg = 0, *kraj_najduzeg=0,*p1,*k1,*t;
	char z1,z2;
	int duzina_najduzeg=0;

	while(*s1!='\0') {

		if(daLiJeSlovo(*s1)) {
			p1=s1;

			while(daLiJeSlovo(*s1)) {
				s1++;
				int duplikat=0;
				t=p1;
				z1=*s1;
				if(z1>='a'&&z1<='z') {
					z1-=32; //pretvaram u veliko slovo
				}

				while(t<s1) {
					z2=*t;
					if(z2>='a'&&z2<='z') {
						z2-=32; //pretvaram u veliko slovo
					}

					if(z1==z2) {
						duplikat=1;
						break;
					}
					t++;
				}
				if(duplikat) {
					break;
				}
			}
			k1=s1;

			if(k1-p1 > duzina_najduzeg) {
				duzina_najduzeg=k1-p1;
				pocetak_najduzeg=p1;
				kraj_najduzeg=k1;
			}
			else{
				s1=p1+1;
			}

			s1--;
		}

		s1++;
	}


	while(pocetak_najduzeg<kraj_najduzeg) {
		*s2=*pocetak_najduzeg;
		s2++;
		pocetak_najduzeg++;
	}
	*s2='\0';

}



int main()
{
	char recenica[]="Ovo je neki primjer teksta";
	char najduzi[100];

	najduzi_bp(recenica,najduzi);

	printf("%s",najduzi);
	return 0;
}
