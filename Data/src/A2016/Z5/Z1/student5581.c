#include <stdio.h>

int strcmp(char* s1, char* s2)
{
	while (*s1 != '\0' && *s2 != '\0') {
		if (*s1 < *s2) return -1;
		if (*s1 > *s2) return 1;
		s1++;
		s2++;
	}

	if(*s1=='\0'&&*s2=='\0') return 0;
	if (*s1 != '\0') return 1;
	if (*s2 != '\0') return -1;


	return 0;

}

struct Student {

	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

/*funkcija koja računa prosjek jednog studenta*/
double prosjek (struct Student st)
{

	int i;
	double sum=0;

	if(st.br_ocjena==0) {
		return 5;
	}

	for(i=0; i<st.br_ocjena; i++) {

		if(st.ocjene[i]==5) {
			return 5;
		}

		sum=sum+st.ocjene[i];
	}
	return sum/st.br_ocjena;
}

int genijalci (struct Student studenti[], int vel, float prosjek1)
{

	int i,j;
	int max1=0,max2=0,max3=0;

	/*izbacivanje studenata koji ne ispunjavaju uslov*/
	for(i=0; i<vel; i++) {

		if(prosjek(studenti[i])<prosjek1) {
			for(j=i; j<vel-1; j++) {
				studenti[j]=studenti[j+1];
			}

			vel--;
			i--;
		}
	}
	
	/*traženje studenta sa najvećim prosjekom*/
	for(i=0; i<vel; i++) {

		if(prosjek(studenti[i])>prosjek(studenti[max1])) {
			max1=i;
		} else if(prosjek(studenti[i])==prosjek(studenti[max1])) {
			if(strcmp(studenti[i].prezime,studenti[max1].prezime)<0) {
				max1=i;
			}
		} else if(strcmp(studenti[i].prezime,studenti[max1].prezime)==0) {
			if(strcmp(studenti[i].ime,studenti[max1].ime)<0) {
				max1=i;
			}
		}
	}

	if(max1==0) {
		max2++;
	}
	
	/*traženje drugog studenta sa najvećim prosjekom*/
	if(vel>=2) {
		for(i=0; i<vel; i++) {

			if(max2>vel)
				break;

			if(i==max1) {
				continue;
			}

			if(prosjek(studenti[i])>prosjek(studenti[max2])) {
				max2=i;
			} else if(prosjek(studenti[i])==prosjek(studenti[max2])) {
				if(strcmp(studenti[i].prezime,studenti[max2].prezime)<0) {
					max2=i;
				}
			} else if(strcmp(studenti[i].prezime,studenti[max2].prezime)==0) {
				if(strcmp(studenti[i].ime,studenti[max2].ime)<0) {
					max2=i;
				}
			}
		}
		
		/*traženje trećeg studenta sa najvećim prosjekom*/
		if (vel>=3) {
			if(max1==0||max2==0) {
				max3++;
				if(max1==1||max2==1) {
					max3++;
				}
			}

			for(i=0; i<vel; i++) {
				if(max3>vel)
					break;

				if(i==max1||i==max2) {
					continue;
				}


				if(prosjek(studenti[i])>prosjek(studenti[max3])) {
					max3=i;
				} else if(prosjek(studenti[i])==prosjek(studenti[max3])) {
					if(strcmp(studenti[i].prezime,studenti[max3].prezime)<0) {
						max3=i;
					}
				} else if(strcmp(studenti[i].prezime,studenti[max3].prezime)==0) {
					if(strcmp(studenti[i].ime,studenti[max3].ime)<0) {
						max3=i;
					}
				}
			}

		}
	}
	/*ispis studenata*/
	if(prosjek(studenti[max1])>=prosjek1) printf("%s %s\n", studenti[max1].prezime, studenti[max1].ime);
	if(prosjek(studenti[max2])>=prosjek1 && max2!=max1 && max2<=vel) printf("%s %s\n", studenti[max2].prezime, studenti[max2].ime);
	if(prosjek(studenti[max3])>=prosjek1 && max3!=max2 && max3!=max1 && max3<=vel) printf("%s %s\n", studenti[max3].prezime, studenti[max3].ime);



	return vel;
}


int main()
{

	struct Student studenti[6] = {
		{ "Mujo", "Mujic", { 7,7,7,7,8}, 5},
		{ "Meho", "Mujic", { 7,7,7,7,8}, 5},
		{ "Pero", "Peric", { 8,8,8,8,7}, 5},
		{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
		{ "Mujo", "Mujic", { 7,7,7,7,8}, 5},
		{ "Fata", "Fatic", { 7,7,7,7,8}, 5},
	};

	printf("%d", strcmp(studenti[1].ime, studenti[0].ime));

	return 0;

}
