#include <stdio.h>

struct Rijec{
	char sadrzaj[50];
	int pon;
};

int strcmpp(char *rijec1, char *rijec2, int velikamala){
    
    while (*rijec1 != '\0' && *rijec2 != '\0'){
        
        
        if (velikamala == 1){
            
            if (*rijec1 < *rijec2)
                return -1;
            if (*rijec1 > *rijec2)
                return 1;
            rijec1++;
            rijec2++;
        }
        else {
            if (*rijec1 + 32 < *rijec2)
                return -1;
            if (*rijec1 - 32 > *rijec2)
                return 1;
            rijec1++;
            rijec2++;
        }
    }
    
    if (*rijec1 == '\0' && *rijec2 != '\0')
        return -1;
    
    return 0;
}

int jednake(char * prva, char* druga){
	
	char *p = prva;
	char *q = druga;
	
	while (*p != '\0' && *q != '\0'){
		
		if (*p != *q)
			return 0;
		
		
		
		if (*(p + 1) == '\0' && *(q + 1) == '\0')
			return 1;
		
		p++;
		q++;
		
	}
	
}

int zabiljezena (char * rijec, struct Rijec * rijeci, int i){
	
	int duz = 0;
	int j, k;
	char * p = rijec;
	
	while (*p != '\0'){
		p++;
		duz++;
	}
		
	
	
	for (j = 0; j < i; j++){
		
		for (k = 0; k < duz; k++){
			if (rijeci[j].sadrzaj[k] != rijec[k])
				break;
				
			if (k == duz - 1 && rijeci[j].sadrzaj[k + 1] == '\0' && rijec[k + 1] == '\0')
				return j + 1;
		}
	}
	return 0;
}

void kompresuj(char* imeulaz, char* imeizlaz){
	
	struct Rijec rijeci [1000];
	struct Rijec temp;
	char znak;
	char rijec[50];
	int j = 0, i = 0, k,  kraj = 0, ind, duga = 0, slova = 0, max, br = 0, ne = 0, jdn = 0;
	
	FILE * ulaz, *izlaz;
		
	ulaz = fopen(imeulaz, "r");
	izlaz = fopen(imeizlaz, "w");
		
	if (ulaz == NULL || izlaz == NULL){
		printf("Greska pri otvaranju datoteke.");
	}
	
	/*Izvuci rijeci i ponavljanja*/
	znak = fgetc(ulaz);
	while (!kraj){
		
		if ((znak >= 'A' && znak <= 'Z') || (znak >= 'a' && znak <= 'z')){
			rijec[j] = znak;
			j++;
			if (j > 1 && j < 10)
				duga = 1;
			else
				duga = 0;
			slova = 1;
		}
		else {
				
			rijec[j] = '\0';
			
			
			if ((ind = zabiljezena(rijec, rijeci, i)) == 0 && slova && duga){
				slova = 0;
				duga = 0;
				rijeci[i].pon = 1;
				
				if (i < 10){
				for (k = 0; k <= j; k++)
					rijeci[i].sadrzaj[k] = rijec[k];
				
				i++;
				}
				
			}
			else{
				if (slova && duga){
					rijeci[ind - 1].pon++;
					slova = 0;
					duga = 0;
				}
			}
			
			j = 0;
			
			if (znak == EOF)
				break;
		}
	
		znak = fgetc(ulaz);
		
	}
	
	/*Sort*/
	
	for (k = 0; k < i; k++){
		
		max = k;
		
		for (j = k + 1; j < i; j++){
			
			if (rijeci[j].pon > rijeci[max].pon)
				max = j;
				
			if (rijeci[j].pon == rijeci[max].pon && strcmpp(rijeci[j].sadrzaj, rijeci[max].sadrzaj, 1) == -1)
				max = j;
		}
		
		temp = rijeci[k];
		rijeci[k] = rijeci[max];
		rijeci[max] = temp;
		
	}
	
	/*Print*/
	for (k = 0; k < i; k++)
		fprintf(izlaz, "%s\n", rijeci[k].sadrzaj);
	
	fprintf(izlaz, "\n");
	
	j = 0;
	slova = 0;
	fseek(ulaz, 0, SEEK_SET);
	znak = fgetc(ulaz);
	while (!kraj){
		
		if ((znak < 'A' || znak > 'z' || (znak > 'Z' && znak < 'a')) && znak != EOF)
			fprintf(izlaz, "%c", znak);
		
		if ((znak >= 'A' && znak <= 'Z') || (znak >= 'a' && znak <= 'z')){
			
			while (((znak >= 'A' && znak <= 'Z') || (znak >= 'a' && znak <= 'z')) && znak != EOF){
				rijec[j] = znak;
				j++;
				znak = fgetc(ulaz);
				ne = 1;
				
			}
			rijec[j] = '\0';
			
			j = 0;
			
			for (k = 0; k < i; k++){
				if (jednake(rijec, rijeci[k].sadrzaj)){
					fprintf(izlaz, "%c", (char)(k + 20));
					break;
						
				}
				
				if (k == (i - 1))
					fprintf(izlaz, "%s", rijec);
					
			}
			
		}
		
		if (znak == EOF)
			break;
		if (!ne)	
			znak = fgetc(ulaz);
		ne = 0;
		
	}
	
	fclose(izlaz);
	fclose(ulaz);
	printf("Datoteka kompresovana.\n");
}

void dekompresuj(char* imeulaz, char* imeizlaz){
	
	FILE * ulaz, *izlaz;
	int i = 0, k = 0, kraj = 0, duz = 0, duz2;
		
	ulaz = fopen(imeulaz, "r");
	izlaz = fopen(imeizlaz, "w");
		
	if (ulaz == NULL || izlaz == NULL){
		printf("Greska pri otvaranju datoteke.");
	}
	
	char znak;
	char rijeec[10][50];
	
	fseek(ulaz, 0, SEEK_SET);
	
	znak = fgetc(ulaz);
	while (znak != EOF){
		
		while (znak != '\n' && znak != EOF){
			
			if (k < 49){
				rijeec[i][k] = znak;
			
			k++;
			}
			znak = fgetc(ulaz);
			duz++;
		}
		rijeec[i][k] = '\0';
		if (i < 9) i++; k = 0; duz2 = duz; duz = 0;
		
		if (znak == EOF){
			fseek(ulaz, -duz2, SEEK_CUR);
			break;
		}
		
		znak = fgetc(ulaz);
	}
	
	znak = fgetc(ulaz);
	while (znak != EOF){
		if ((int)znak >= 20 && (int)znak <= 29)
			fprintf(izlaz, "%s", rijeec[(int)znak - 20]);
		else	
			fprintf(izlaz, "%c", znak);
		znak = fgetc(ulaz);
	}
	
	fclose(ulaz);
	fclose(izlaz);
	printf("Datoteka dekompresovana.\n");
	
}

int main() {
	
	int odabir = 0;
	char imeulaz[50], imeizlaz[50];
	
	FILE* ulaz = NULL, *izlaz = NULL;
	
	do{
		printf ("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf ("%d", &odabir);
		
		if (odabir == 0){
			if (ulaz != NULL && izlaz != NULL){
				fclose (ulaz);
				fclose (izlaz);
			}
				return 0;
			
		}
		else if (odabir == 1){
			
			printf("Unesite ime ulazne datoteke: ");
			scanf("%s", imeulaz);
			printf("Unesite ime izlazne datoteke: ");
			scanf("%s", imeizlaz);
			
			kompresuj(imeulaz, imeizlaz);
			
		}
		else if (odabir == 2){
			printf("Unesite ime ulazne datoteke: ");
			scanf("%s", imeulaz);
			printf("Unesite ime izlazne datoteke: ");
			scanf("%s", imeizlaz);
			
			dekompresuj(imeulaz, imeizlaz);
		}
	
	} while (odabir != 0);
	
	return 0;
}
