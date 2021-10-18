#include <stdio.h>

void unesi(char niz[],int duzina)
{
	char znak=getchar();
	if (znak=='\n')
		znak=getchar();
	int i=0;
	while (i<duzina-1 && znak!='\n' ) {
		niz[i]=znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

int provjeri(char *s)
{
	char  sadrzaj_prvih[100][100]= {{0}},sadrzaj_drugih[100][100]= {{0}};
	int br_prvih_tagova=0,br_drugih_tagova=0,duz_sadrzaja_prvih[100]= {0},duzina_sadrzaja_drugih[100]= {0},i,j,k,test_za_druge,test_za_prve;
	while (*s!='\0') {
		test_za_druge=0;
		test_za_prve=0;

		if (*s=='<' && *(s+1)!='/') {
			j=0;
			while (*s!=' ' && *s!='>') {
				sadrzaj_prvih[br_prvih_tagova][j]=*s;
				j++;
				duz_sadrzaja_prvih[br_prvih_tagova]++;

				test_za_prve=1;
				s++;
			}
		}

		else if(*s=='<' && *(s+1)=='/') {
			k=0;
			while (*s!='>' && *s!='\0') {
				if(*s=='/') {
					s++;
					continue;
				}
				sadrzaj_drugih[br_drugih_tagova][k]=*s;
				k++;
				duzina_sadrzaja_drugih[br_drugih_tagova]++;
				test_za_druge=1;
				s++;
			}
		}

		if (test_za_prve) {
			sadrzaj_prvih[br_prvih_tagova][j]='>';
			br_prvih_tagova++;
		}
		if(test_za_druge) {
			sadrzaj_drugih[br_drugih_tagova][k]='>';
			br_drugih_tagova++;
		}
		s++;
	}

	if (br_drugih_tagova!=br_prvih_tagova)
		return 0;
    int kraj,pocetak;
	for (i=0; i<br_prvih_tagova; i++) {
		pocetak=1;
		kraj=1;
		for (j=1; j<duz_sadrzaja_prvih[i]; j++) {
			if(sadrzaj_prvih[i][j]==sadrzaj_drugih[i][j] && pocetak==1)
				kraj=0;
			else if (sadrzaj_prvih[i][j]==sadrzaj_drugih[br_drugih_tagova-1][j] && kraj==1)
				pocetak=0;
			else if (pocetak == 0 || kraj == 0)
				return 0;
		}
		if (kraj==1 && br_drugih_tagova>0)
			br_drugih_tagova--;
	}
	return 1;
}

int main()
{
	char niz[1000];
	printf("Unesi HTML kod: ");
	unesi(niz,1000);
	printf ("Vrijedost je: %d", provjeri(niz));
	return 0;
}
