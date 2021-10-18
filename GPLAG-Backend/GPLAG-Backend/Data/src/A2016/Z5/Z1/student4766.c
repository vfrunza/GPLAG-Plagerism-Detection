#include <stdio.h>
#include <string.h>

struct Student;
void popuniGenijalce(struct Student *popuni, struct Student *niz, int size, int brValid);

struct Student {
char ime[20], prezime[20];
int ocjene[50];
	int br_ocjena;
};

double odrediProsjek(struct Student student){
	//funkcija vraca prosjek studenta student
	double prosjek;
	double suma = 0;
	int pao = 0, imaBarJednu = 0;
	int i;
	if(student.br_ocjena > 0)
		imaBarJednu = 1;
		
	for(i = 0; i < student.br_ocjena; i++){
		suma += student.ocjene[i];
		if(student.ocjene[i] == 5)
			pao = 1;
	}
	if(imaBarJednu)
		prosjek = suma / student.br_ocjena;
	if(pao || !imaBarJednu)
		prosjek = 5;
	
	return prosjek;
}
int genijalci(struct Student *studenti, int size, double prosjek){
//	int ret = size;
	int i, j;
	struct Student niz[3];
	int brValidnih;//max 3
	
	for(i = 0; i < size; i++){
		if(odrediProsjek(studenti[i]) < prosjek){
			for(j = i; j < size - 1; j++){
				studenti[j] = studenti[j + 1];
			}	
			i--;
			size--;
		}
	}
	brValidnih = (size > 3) ? 3 : size;//3 ako ih ima 3 ili vise, u suprotnom onliko koliko ih ima
	//nakon sto smo izbacili studente sa prosjekom manjim od trazenog mozemo ponovo proc kroz njihov niz i ispisat one koje zelimo
	popuniGenijalce(niz, studenti, size, brValidnih);
	
	//printamo najbolje koji se nalaze u niz
	for(i = 0; i < brValidnih; i++){
		printf("%s %s\n", niz[i].prezime, niz[i].ime);///////
		
	}
	
	return size;
}
int testLeks(struct Student a, struct Student b){
	//vraca 1 ako je student a ispred b, -1 u suportnom, 0 ako su isti
	int x = strcmp(a.prezime, b.prezime);
	if(x < 0)
		return -1;
	else if(x > 0)
		return 1;
	else if( x == 0){
		int y = strcmp(a.ime, b.ime);
		if(y < 0)
			return -1;
		else if( y > 0)
			return 1;
		else
			return 0;
	}
}
void popuniGenijalce(struct Student *popuni, struct Student *niz, int size, int brValid){
	int i, j, maxInd1 = 0, maxInd2 = 0, maxInd3 = 0;
	int nizMaxova[3];
	int temp;
	maxInd1 = 0;
        
        for (j=0; j<size; j++) {
            if (odrediProsjek(niz[j]) >= odrediProsjek(niz[maxInd1])){
            	if (odrediProsjek(niz[j]) == odrediProsjek(niz[maxInd1])){
            		if(testLeks(niz[j], niz[maxInd1]) == -1)
            		maxInd1 = j;
            	}
            	else
            	maxInd1 = j;
       		}
        }
        
        for(i = 0; i < brValid; i++){
        	if(i != maxInd1){
        		maxInd2 = i;
        		break;
        	}
        }
        
        for (j=0; j<size; j++) {
            if (odrediProsjek(niz[j]) >= odrediProsjek(niz[maxInd2]) && j!= maxInd1){
            	if (odrediProsjek(niz[j]) == odrediProsjek(niz[maxInd2])){
            		if(testLeks(niz[j], niz[maxInd2]) == -1)
            		maxInd2 = j;
            	}
            	else
            	maxInd2 = j;
       		}
        }
        
        for(i = 0; i < brValid; i++){
        	if(i != maxInd1 && i != maxInd2){
        		maxInd3 = i;
        		break;
        	}
        }
        
        for (j=0; j<size; j++) {
            if (odrediProsjek(niz[j]) >= odrediProsjek(niz[maxInd3]) && j!= maxInd1 && j != maxInd2){
            	if (odrediProsjek(niz[j]) == odrediProsjek(niz[maxInd3])){
            		if(testLeks(niz[j], niz[maxInd3]) == -1)
            		maxInd3 = j;
            	}
            	else
            	maxInd3 = j;
       		}
        }
        
        popuni[0] = niz[maxInd1];
        popuni[1] = niz[maxInd2];
   		popuni[2] = niz[maxInd3];
    
}

int main() {

	return 0;
}
