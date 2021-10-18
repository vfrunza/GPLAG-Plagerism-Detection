#include <stdio.h>

void unesi (char niz[],int velicina)
{
	char znak=getchar();
	if (znak == '\n')
		znak = getchar();
	int i=0;
	while (i<velicina-1 && znak != '\n') {
		niz[i]=znak;
		znak=getchar();
		i++;
	}
	niz[i]='\0';
}

void najduzi_bp(char*s1,char*s2)
{
	char *temp=s1,*temp2=s2;
	int duzina[100]= {0},i=0,broj_rijeci=0,max_duzina,brojac_rijeci=0,redni_broj=1,j,s,k;
	/*pronalazak*/
	while (*s1!='\0') {
		if ((*s1>='a' && *s1<='z') || (*s1>='A' && *s1<='Z')) {
			char rijec[100];
			j=0;
			while ((*s1>='a' && *s1<='z') || (*s1>='A' && *s1<='Z')) {
				duzina[i]++;
				rijec[j]=*s1;
				s1++;
				j++;
			}
			for(s=0; s<j; s++) {
				for(k=s; k<j; k++) {
					if(j==(k+1))
						break;
					if(rijec[s]==rijec[k+1] || (rijec[s]+32)==rijec[k+1] || (rijec[s]-32)==rijec[k+1])
						duzina[i]--;
				}
			}

			i++;
			broj_rijeci++;
			if(*s1=='\0')
				break;
		}
		s1++;
	}

	/*trazenje najduze rijeci*/
	max_duzina=duzina[0];
	for (i=0; i<broj_rijeci; i++) {
		if (max_duzina<duzina[i]) {
			max_duzina=duzina[i];
			redni_broj=i+1;
		}
	}

	/*ubacivanje */
	while (*temp!='\0') {
		if ((*temp>='a' && *temp<='z') || (*temp>='A' && *temp<='Z')) {
			brojac_rijeci++;
			while (((*temp>='a' && *temp<='z') || (*temp>='A' && *temp<='Z')) && *temp!='\0') {
				if (brojac_rijeci==redni_broj) {
					*s2=*temp;
					temp++;
					s2++;
				} else
					temp++;
			}
		}
		if (*temp=='\0')
			break;
		temp++;
	}
	
	*s2='\0';
	s2=temp2+1;
	max_duzina++;
	int test;
	
	while (*temp2!='\0') {
		test=1;
		while(*s2!='\0'){
		if(*temp2==*s2 ||(*temp2+32==*s2) || (*temp2-32==*s2)) {
			while(*s2!='\0') {
				*s2=*(s2+1);
				s2++;
				test=0;
			}
			*s2='\0';
		} 
		else s2++;
		}
		if(test)
		temp2++;
		s2=temp2+1;
	}
	
	

}

int main()
{
	char niz1[100],niz2[101];
	printf ("Unesi recenicu: ");
	unesi(niz1,100);
	najduzi_bp(niz1,niz2);
	printf ("Najduzi podniz je: %s", niz2);

	return 0;
}
