#include <stdio.h>
#include <string.h>

char pretvori(char znak)
{

	if(znak>='A' && znak<='Z') znak=znak+'a'-'A';
	return znak;
}

void najduzi(char*s,char*rijec)
{
	char *pok=s,*novi=s,*klizeci=s;
	char znak1,znak2;
	int br=0,duzina=strlen(rijec);

	while((*pok>='A' && *pok<='Z')  || (*pok>='a' && *pok<='z')) {
		znak1=pretvori(*pok);
		klizeci=s;
		while(klizeci<pok) {
			znak2=pretvori(*klizeci);
			if(znak2==znak1 && duzina<br) {
				while(novi<pok) {
					*rijec=*novi;
					rijec++;
					novi++;
				} *rijec='\0';
				return;



			} else if(znak1==znak2) return;
			klizeci++;
		}

		pok++;
		br++;
	}

	if(duzina<br) {
		while(novi<pok) {
			*rijec=*novi;
			rijec++;
			novi++;
		} *rijec='\0';
	}


}
void najduzi_bp(char*s1,char*s2)
{
	*s2='\0';
	while(*s1!='\0') {
		if((*s1>='A' && *s1<='Z')  || (*s1>='a' && *s1<='z')) najduzi(s1,s2);
		s1++;

	}

}



int main()
{

	return 0;
}
