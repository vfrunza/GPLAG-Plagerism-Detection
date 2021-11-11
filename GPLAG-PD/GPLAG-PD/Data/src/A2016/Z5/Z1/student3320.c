#include <stdio.h>
#define epsilon 0.0000000000000000001

struct Student {
	char ime[20];
	char prezime[20];
	int ocjene[50];
	int br_ocjena;
};


int genijalci(struct Student s[], int duzina, double min_prosjek) {
	int i, j, k;
	int suma;
	int provjera;
	float prosjek;
	float spremnik[100];
	int temp=0, temp1, temp2, temp3, temp4;
	double max;
	char* s1;
	char* s2;
	

	i=0;
	while(i<duzina) {
		suma=0;
		provjera=1;
		if(s[i].br_ocjena == 0) {
			prosjek=5.0;
			provjera=0;
			spremnik[temp]=prosjek;
			temp++;
		}
		j=0;
		while(j<s[i].br_ocjena) {
			suma=suma+s[i].ocjene[j];
			if(s[i].ocjene[j] == 5) {
				prosjek=5.0;
				provjera=0;
				spremnik[temp]=prosjek;
				temp++;
				break;
			}
			j++;
		}
		if(provjera) {
			prosjek=suma/(s[i].br_ocjena*1.);
			spremnik[temp]=prosjek;
			temp++;
		}
		if(prosjek-min_prosjek<0.0) {
			k=i;
			while(k<duzina-1) {
				s[k]=s[k+1];
				k++;
			}
			duzina--;
			i--;
			temp--;
		}
		i++;
	}

	
	max=0;
	temp1=-1;
	i=0;
	while(i<duzina) {
		
		if(max<spremnik[i]) {
			max=spremnik[i];
			temp1=i;
		}
		
		if(max-spremnik[i]<epsilon && i != 0) {
			s1=&s[i].prezime[0];
			s2=&s[temp1].prezime[0];
			temp4=0;
			
			while(*s1 != '\0' || *s2 != '\0') {
				if(*s1>*s2) {
					break;
				} else {
					if(*s1<*s2) {
					temp1=i;
					temp4++;
					break;
					}
				}
				s1++;
				s2++;
			}
			
		if(temp4==0) {
			s1=&s[i].ime[0];
			s2=&s[temp1].ime[0];
			
			while(*s1 != '\0' && *s2 != '\0') {
				if(*s1>*s2) {
					break;
				} else {
					if(*s1<*s2) {
					temp1=i;
					}
				}
				s1++;
				s2++;
			}
		}
	}
		i++;
	}

	


	max=0;
	temp2=-1;
	i=0;
	while(i<duzina) {
		
		if(max<spremnik[i] && i != temp1) {
			max=spremnik[i];
			temp2=i;
		}
		
		if(max-spremnik[i]<epsilon && (i != 0 && i != temp1)) {
			s1=&s[i].prezime[0];
			s2=&s[temp2].prezime[0];
			temp4=0;
			
			while(*s1 != '\0' || *s2 != '\0') {
				if(*s1>*s2) {
					break;
				} else {
					if(*s1<*s2) {
					temp2=i;
					temp4++;
					break;
					}
				}
				s1++;
				s2++;
			}
			
		if(temp4==0) {
			s1=&s[i].ime[0];
			s2=&s[temp2].ime[0];
			
			while(*s1 != '\0' && *s2 != '\0') {
				if(*s1>*s2) {
					break;
				} else {
					if(*s1<*s2) {
					temp2=i;
					}
				}
				s1++;
				s2++;
			}
		}
	}
		i++;
	}
	


	max=0;
	temp3=-1;
	i=0;
	while(i<duzina) {
		
		if(max<spremnik[i] && i != temp2 && i != temp1) {
			max=spremnik[i];
			temp3=i;
		}
		
		if(max-spremnik[i]<epsilon && (i != 0 && i != temp2 && i != temp1)) {
			s1=&s[i].prezime[0];
			s2=&s[temp3].prezime[0];
			temp4=0;
			
			while(*s1 != '\0' && *s2 != '\0') {
				if(*s1>*s2) {
					break;
				} else {
					if(*s1<*s2) {
					temp3=i;
					temp4++;
					break;
					}
				}
				s1++;
				s2++;
			}
			
		if(temp4==0) {
			s1=&s[i].ime[0];
			s2=&s[temp3].ime[0];
			
			while(*s1 != '\0' && *s2 != '\0') {
				if(*s1>*s2) {
					break;
				} else {
					if(*s1<*s2) {
					temp3=i;
					}
				}
				s1++;
				s2++;
			}
		}
	}
		i++;
	}
	if(temp1 != -1) {
		printf("%s %s\n", s[temp1].prezime, s[temp1].ime);
	}
	if(temp2 != -1) {
		printf("%s %s\n", s[temp2].prezime, s[temp2].ime);
	}
	if(temp3 != -1) {
		printf("%s %s\n", s[temp3].prezime, s[temp3].ime);
	}

	return duzina;
}
		
int main() {

	return 0;
}
