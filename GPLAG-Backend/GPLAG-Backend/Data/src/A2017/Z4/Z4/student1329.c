#include <stdio.h>

int provjeri (char *s)
{
	char *pocetak=s;
	char *temp;
	char *temp_2;
	char *temp_3;
	int duzina=0;
	int otvorenih;
	int zatvorenih;
	int closed;
	int provjera=1;
	int dodaj1=0;
	int dodaj2=0;
	int i=0,k;
	int skok;

	s=pocetak;
	while (*s!='\0') {
		if (*s=='<') {
			if (i==0 && *(s+1)=='/')
				return 0;
			if (*(s+1)=='/')
				i=2;
			else
				i=1;
			for (; ; i++) {
				if(*(s+i)=='/')
					return 0;
				if (*(s+i)==' ')
					continue;
				if (*(s+i)=='>') {
					i=5;
					break;
				}
				if ((*(s+i)>='A' && *(s+i)<='Z')||(*(s+i)>='a' && *(s+i)<='z')) {
					i=10;
					break;
				}
			}
		}
		if (i==5)
			return 0;

		if (*s=='<') {
			while (*s!='>' && *s!='\0') {
				s++;
				if (*s=='<' || *s=='\0')
					return 0;
			}
			s--;
		}

		if (*s=='>') {
			while (*s!='<' && *s!='\0') {
				s++;
				if (*s=='>')
					return 0;
			}
			s--;
		}
		s++;
	}
	s--;

	s=pocetak;
	otvorenih=0;
	zatvorenih=0;
	closed=0;
	while (*s!='\0') {
		if (*s=='<') {
			otvorenih++;
		}
		if (*s=='>')
			zatvorenih++;
		if (*s=='<' && *(s+1)=='/')
			closed++;
		s++;
	}
	if (otvorenih!=zatvorenih)
		return 0;
	if (otvorenih/2!=closed)
		return 0;
	if (otvorenih==0 && zatvorenih==0)
		return 1;

	s=pocetak;
	otvorenih=0;
	zatvorenih=0;
	while (*s!='\0') {
		if (*s=='<' && *(s+1)!='/') {
			duzina=0;
			provjera=1;
			temp=s;
			zatvorenih=0;
			while (*s!='>') {
				if (*s==' ')
					provjera=0;
				if (provjera)
					duzina++;
				s++;
			}
			temp++;
			while (*s!='\0') {
				if (*s=='<' && *(s+1)=='/') {
					s+=2;
					if (*s==' ')
						return 0;
					k=0;
					for (i = 0; i < duzina; i++) {
						if (*(s+i+k)==' ') {
							while (*(s+i+k)==' ')
								k++;
						}
						if (*(temp+i)>='A' && *(temp+i)<='Z')
							dodaj1='a'-'A';
						else
							dodaj1=0;
						if (*(s+i+k)>='A' && *(s+i+k)<='Z')
							dodaj2='a'-'A';
						else
							dodaj2=0;
						if (provjera==0 && i==duzina-1) {
							if ('>'!=*(s+i+k))
								break;
						} else if (*(temp+i)+dodaj1!=*(s+i+k)+dodaj2)
							break;
					}
					if (i==duzina)
						zatvorenih=1;
				}
				s++;
			}
			if (!zatvorenih)
				return 0;
			s=temp;
			s--;
		}
		s++;
	}

	s=pocetak;
	while (*s!='\0') {
		if (*s=='<' && *(s+1)!='/') {
			skok=0;
			duzina=0;
			provjera=1;
			temp_3=s;
			temp_3++;
			temp=s;
			while (*s!='>') {
				if (*s==' ')
					provjera=0;
				if (provjera)
					duzina++;
				s++;
			}
			temp++;

			while (*s!='\0') {
				if (*s=='<' && *(s+1)!='/') {
					s++;
					for (i = 0; i < duzina; i++) {
						if (*(temp+i)>='A' && *(temp+i)<='Z')
							dodaj1='a'-'A';
						else
							dodaj1=0;
						if (*(s+i)>='A' && *(s+i)<='Z')
							dodaj2='a'-'A';
						else
							dodaj2=0;
						if (*(temp+i)+dodaj1==' ' && *(s+i)+dodaj2==' ') {
							i=duzina;
							break;
						}
						if (*(temp+i)+dodaj1!=*(s+i)+dodaj2)
							break;
					}
					if (i==duzina)
						skok++;
				}
				s++;
			}

			duzina=0;
			provjera=1;
			s=temp;
			s--;
			while (*s!='>') {
				if (*s==' ')
					provjera=0;
				if (provjera)
					duzina++;
				s++;
			}

			while (*s!='\0') {
				if (*s=='<' && *(s+1)=='/') {
					s+=2;
					k=0;
					for (i = 0; i < duzina; i++) {
						if (*(s+i+k)==' ') {
							while (*(s+i+k)==' ')
								k++;
						}
						if (*(temp+i)>='A' && *(temp+i)<='Z')
							dodaj1='a'-'A';
						else
							dodaj1=0;
						if (*(s+i+k)>='A' && *(s+i+k)<='Z')
							dodaj2='a'-'A';
						else
							dodaj2=0;
						if (provjera==0 && i==duzina-1) {
							if ('>'!=*(s+i+k))
								break;
						} else if (*(temp+i)+dodaj1!=*(s+i+k)+dodaj2)
							break;
					}
					if (i==duzina) {
						i=0;
						while (*(s+i)!='>') {
							i++;
						}
						if (*(s+i+1)=='\0')
							skok=0;
						if (skok>0)
							skok--;
						else {
							temp_2=temp;
							while (*temp_2++!='>');
							otvorenih=0;
							zatvorenih=0;
							while (temp_2!=s-2) {
								if (*temp_2=='<' && *(temp_2+1)!='/') {
									otvorenih++;
								}
								if (*temp_2=='<' && *(temp_2+1)=='/')
									zatvorenih++;
								temp_2++;
							}
							if (otvorenih!=zatvorenih)
								return 0;
							break;
						}
					}
				}
				s++;
			}
			s=temp_3;
			s--;
			if (skok!=0)
				return 0;
		}
		s++;
	}

	return 1;
}

int main()
{
	char tekst [] = "<b><a>proba</b></a>";
	printf("%d", provjeri(tekst));
	return 0;
}