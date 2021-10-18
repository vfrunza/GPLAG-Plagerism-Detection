#include <stdio.h>

int provjeri (char* s) {
	int i=0, j, k=0, l;
	char* temp=s;
	char niz_otvorenih[1000][1000];
	char niz_zatvorenih[1000][1000];
	
	while (*s!='\0') {
		j=0;
		if (*s=='<' && *(s+1)!='/') {
			temp=s+1;
			while ((*temp>='A' && *temp<='Z') || (*temp>='a' && *temp<='z') || (*temp>='0' && *temp<='9')) {
				if (*temp>='a') niz_otvorenih[i][j]=*temp-32;
				else niz_otvorenih[i][j]=*temp;
				j++;
				temp++;
			}
			
			/* Svaki otvoreni tag mora biti pravilno zatvoren: */
			if (*temp!=' ' && *temp!='>') return 0;
			niz_otvorenih[i][j]='\0';
			i++;
			
			/* Potreban znak ">": */
			while (*temp!='>' && *temp!='\0') {
				temp++;
				if (*temp=='<') return 0;
			}
			
			/* Nepotreban znak ">": */
			while (*temp!='<' && *temp!='\0') {
				temp++;
				if (*temp=='>') return 0;
			}
			 
		}
		else if (*s=='<' && *(s+1)=='/') {
			
			/* Tag mora biti prethodno otvoren: */
			if (i==0) return 0;
			
			temp=s+2;
			while ((*temp>='A' && *temp<='Z') || (*temp>='a' && *temp<='z') || (*temp>='0' && *temp<='9')) {
				if (*temp>='a') niz_zatvorenih[k][j]=*temp-32;
				else niz_zatvorenih[k][j]=*temp;
				
				j++;
				temp++;
			}
			/* Ne smije biti prazan tag: */
			if (j==0) return 0;
			
			/* Svaki otvoreni tag mora biti pravilno zatvoren: */
			if (*temp!='>' && *temp!=' ') return 0;
			
			
			/* Potreban znak ">": */
			while (*temp!='>' && *temp!='\0') {
				temp++;
				if (*temp=='<') return 0;
				if (*temp=='\0') return 0;
			}
			
			/* Nepotreban znak ">": */
			while (*temp!='<' && *temp!='\0') {
				temp++;
				if (*temp=='>') return 0;
			}
			
			niz_zatvorenih[k][j]='\0';
			k++;
			
			for (l=0; l<=j; l++) {
				if (niz_otvorenih[i-1][l]!=niz_zatvorenih[k-1][l]) return 0;
			}
			i--;
		}
		s++;
	}
	/* Ne smije biti više otvorenih nego zatvorenih tagova: */
	if (i!=0) return 0;
	
	return 1;
}


int main() {
	printf ("Zadaća 4, Zadatak 4");
	return 0;
}
