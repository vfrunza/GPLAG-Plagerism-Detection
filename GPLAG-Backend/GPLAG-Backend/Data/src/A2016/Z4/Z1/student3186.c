#include <stdio.h>

void unesi(char niz[], int velicina)
{
    char znak = getchar();
    int i;
    
    if (znak == '\n') znak = getchar();
    i = 0;
    while (i < velicina-1 && znak != '\n')
    {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i] = '\0';
}

char* izbaci_najcescu (char *s) {
	char temprijec[100], najcesca[100];
	char *resetS = s, *glavni = s;
	char *pocRijec = s, *krajRijec = s, *IzbacujKraj = s;
	char *sarackomarackrozstring = s;
	char *rijec = temprijec;
	char *najrijec = najcesca;
	int duzina = 0, slova = 0, rijeci = 0, max = 0, kolkopetlja = 0, najduzina = 0;
	
	/* Pronalazak najcesce rijeci */
	while (*glavni != '\0') {
		
		if ((*glavni >= 'a' && *glavni <= 'z')||(*glavni >= 'A' && *glavni <= 'Z')) {
			
			pocRijec = glavni;
			while ((*glavni >= 'a' && *glavni <= 'z')||(*glavni >= 'A' && *glavni <= 'Z'))
			glavni++;
			krajRijec = glavni;
			
			/* kopiram u temporaryaryary niz rijececec sa ehomeomeomeomomomehom rijec koju cu testirat */
			duzina = 0;
			rijec = temprijec;
			while (pocRijec < krajRijec) {
				*rijec = *pocRijec;
				rijec++;
				pocRijec++;
				duzina++;
			}	*rijec = '\0';
			
			/* Šarackomarackrozstring all night long testing my brojac for words */
			rijeci = 0;
			sarackomarackrozstring = resetS;
			
			while (*sarackomarackrozstring != '\0') {
				if ((*sarackomarackrozstring >= 'a' && *sarackomarackrozstring <= 'z')||(*sarackomarackrozstring >= 'A' && *sarackomarackrozstring <= 'Z')) {
					
					slova = 0;
					kolkopetlja = 0;
					rijec = temprijec;
					while ((*sarackomarackrozstring >= 'a' && *sarackomarackrozstring <= 'z')||(*sarackomarackrozstring >= 'A' && *sarackomarackrozstring <= 'Z'))
					{
						
					if (((*sarackomarackrozstring == *rijec) || (*sarackomarackrozstring == *rijec+('a'-'A')) || (*sarackomarackrozstring == *rijec-('a'-'A'))) && (*rijec != '\0'))
						slova++;
						kolkopetlja++;
						if (*rijec != '\0')
						rijec++;
						sarackomarackrozstring++;
					}
					
					if (slova == duzina && kolkopetlja == duzina)
						rijeci++;
				}
				else sarackomarackrozstring++;
			}
			
			if (rijeci > max) {
				max = rijeci;
				najduzina = 0;
				najrijec = najcesca;
				rijec = temprijec;
				
				while (*rijec != '\0') {
					*najrijec = *rijec;
					najrijec++;
					rijec++;
					najduzina++;
				}	*najrijec = '\0';
			}
		}
		else glavni++;
	}
	
	/* Eh sad cu da te izbacim jeednom za sva vremena */
	glavni = resetS;
	while (*glavni != '\0') {
		if ((*glavni >= 'a' && *glavni <= 'z')||(*glavni >= 'A' && *glavni <= 'Z')) {
			
					slova = 0;
					kolkopetlja = 0;
					najrijec = najcesca;
					sarackomarackrozstring = glavni;
					pocRijec = sarackomarackrozstring;
				while ((*sarackomarackrozstring >= 'a' && *sarackomarackrozstring <= 'z')||(*sarackomarackrozstring >= 'A' && *sarackomarackrozstring <= 'Z'))
				{
						
				if (((*najrijec == *sarackomarackrozstring)||(*sarackomarackrozstring == *najrijec-('a'-'A'))||(*sarackomarackrozstring == *najrijec+('a'-'A'))) && (*najrijec != '\0'))
					slova++;
					kolkopetlja++;
					sarackomarackrozstring++;
					if (*najrijec != '\0')
					najrijec++;
				}
				if (slova == najduzina && kolkopetlja == najduzina) {
					slova = 0;
					IzbacujKraj = sarackomarackrozstring;
					while (*IzbacujKraj != '\0') {
						*pocRijec = *IzbacujKraj;
						pocRijec++;
						IzbacujKraj++;
						slova++;
					}	*pocRijec = '\0';
				}
				else glavni += kolkopetlja;
			}
			else glavni++;
		}
	
	return resetS;
}

int main() {
	char string[300];
	/* unosim string */
	printf ("Unesi string: ");
	unesi (string, 300);
	
	/* izbacujem string */
	printf ("'%s'", izbaci_najcescu(string));
	
	return 0;
}