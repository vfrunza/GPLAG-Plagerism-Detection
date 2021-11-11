#include <stdio.h>
#include <math.h>
#define eps 0.00001

char* obuhvat (char *string, double x1, double y1, double x2, double y2) {
	char tempniz[150];
	double BR[10] = {0};
	double *pokx = BR, *poky = BR;
	char *temp = tempniz, *PocZagradice = string;
	char *glavni = string, *resetS = string, *zagradica = string;
	double cifra = 0, decimala = 0, broj = 0;
	int brojidecimale = 0, kontrolna = 0, kolkopetlja, i = 0;
	
	/* provjera ispravnosti */
	glavni = resetS;
	while (*glavni != '\0') {
		
		/* Provjera dozvoljenih duplih znakova */
		if (*glavni == '(' && *(glavni+1) >= '0' && *(glavni+1)<= '9') 
		return 0;
		if (*glavni == '(' && *(glavni+1) == '(') 
		return 0;
		if (*glavni == ')' && *(glavni+1) == ')') 
		return 0;
		if (*glavni == ' ' && *(glavni+1) == ' ') 
		return 0;
		if (*glavni == ',' && *(glavni+1) == ',') 
		return 0;
		if (*glavni == '.' && *(glavni+1) == '.') 
		return 0;
		/* Provjera znakova koji su svakako nedozvoljeni nalaziti u stringu */
		if ((*glavni >= ' ') && (*glavni < '('))
		return 0;
		if ((*glavni >= ':') && (*glavni >= '~'))
		return 0;
		
		glavni++;
	} 
	
	glavni = resetS;
	kolkopetlja = 0;
	while (*glavni != '\0') {
		
		zagradica = glavni;
		/* Znaci da se radi o broju, minusu ili tacki */
		if ((*glavni >= '-' && *glavni <= '.') || (*glavni >= '0' && *glavni <= '9')) {
			kolkopetlja++;
			/* Provjeriti jel minus ispred */
			kontrolna = 0;
			while (*zagradica == '-') {
				kontrolna = 1;
				zagradica++;
			}
			
			/* Ide do tacke tj. uzima cijelu vrijednost */
			cifra = 0;
			while (*zagradica != ',' && *zagradica != ')' && *zagradica != '.') {
				cifra = 10*cifra + (double)*zagradica - '0';
				zagradica++;
			}
			
			/* Ide od tacke tj. uzima decimalnu vrijednost */
			decimala = 0;
			if (*zagradica == '.') {
				++zagradica;
				brojidecimale = 0;
				while (*zagradica != ',' && *zagradica != ')') {
					decimala = 10*decimala + (double)*zagradica - '0';
					brojidecimale++;
					zagradica++;
				}
				decimala /= pow (10, brojidecimale);
			}
			
			if (kontrolna)
			broj = (-1)*(cifra + decimala);
			else
			broj = cifra + decimala; 
			
			*pokx = broj;
			pokx++;
			
			glavni = zagradica;
		}	else ++glavni;
	}	*pokx = '\0';	*poky = '\0';
	
	pokx = BR;
	poky = BR+1;
	glavni = resetS;
	for (i=0; i<(kolkopetlja/2); i++) {
		
		while (*glavni != '(')
		glavni++;
		
		PocZagradice = glavni;
		if ((*pokx >= x1 && *pokx <= x2) && (*poky >= y1 && *poky <= y2)) {
			
			while ((*(PocZagradice-1) != ')' || *(PocZagradice) != ',')) {
				*temp = *PocZagradice;
				PocZagradice++;
				temp++;
			}	
		}
		
		pokx += 2;
		poky += 2;
		glavni++;
		
	}	*temp = '\0';
	
	temp = tempniz;
	glavni = resetS;
	while (*temp != '\0') {
		*glavni = *temp;
		temp++;
		if (*glavni == ')') {
			glavni++;
			*glavni = ',';
		}
		glavni++;
	}	*glavni = '\0';
	
	glavni = resetS;
	while (*glavni != '\0') {
		if (*glavni == ',' && *(glavni+1) == '\0')
		*glavni = *(glavni+1);
		glavni++;
	}
	
	return resetS;
}
int main() {
	char niz[] = "(15,30)";
	printf ( "'%s'" , obuhvat ( niz,15,30,16,31 ) );
	return 0;
}
