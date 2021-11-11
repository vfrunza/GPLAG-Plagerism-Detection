#include <stdio.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
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

int jednaki(char*a, char*b){
    
    int jednaki = 0;
    
    while (*a != '\0' && *b != '\0'){
        
        if (*a != *b)
            jednaki = 0;
        
        a++;
        b++;
    }
    
    if (*a == '\0' && *b == '\0')
        jednaki = 1;
    
    return jednaki;
}

float Prosjek(struct Student s){
	
	float s_prosjek = 0;
	int i;
	float suma = 0;
	
	if (s.br_ocjena == 0)
		return s_prosjek;
	
	else
	
	for (i = 0; i < s.br_ocjena; i++){
			
		if (s.ocjene[i] == 5){
			
			s_prosjek = 5;
			break;
		}
				
		if (s.ocjene[i] > 5 && s.ocjene[i] <= 10){
			suma += s.ocjene[i];
		}
			
	}
		
	if (s_prosjek == 0)
		s_prosjek = suma/s.br_ocjena;
		
	return s_prosjek;
}

int zabiljezen(struct Student s, struct Student*n, int x, int* ind, int ind2){
	
	int i;
	int zabiljez = 0;
	
	for (i = 0; i < x; i++){
		if (jednaki(s.ime, n[i].ime) && jednaki(s.prezime, n[i].prezime) && Prosjek(s) == Prosjek(n[i]) && ind2 == ind[i])
			zabiljez = 1;
	}
	
	return zabiljez;
}

int genijalci(struct Student* s, int vel, float prosjek){
	
	struct Student* stud = s;
	struct Student najbolji[3];
	int ind[3];
	int i, j, brnaj = 0;
	
	/*Izbaci prosjeke nize od unesenog*/
	for (i = 0; i < vel; i++){
		
		if (Prosjek(stud[i]) < prosjek){
			
			for (j = i; j < vel - 1; j++)
				stud[j] = stud[j + 1];
			vel--;
			i--;
		}
		
	}
	stud = s;
	
	/*Inicijalizuj najbolje*/
	for (i = 0; i < 3; i++){
		
		if (i < vel){
			najbolji[i] = stud[i];
			ind[i] = i;
			brnaj++;
		}
		
	}
	
	/*Odaberi najbolje*/
	for (i = 0; i < brnaj; i++){
		
		for (j = 0; j < vel; j++){
			
			if ((Prosjek(stud[j]) > Prosjek(najbolji[i]) && zabiljezen(stud[j], najbolji, i, ind, j) == 0)){
				
				najbolji[i] = stud[j];
				ind[i] = j;
				
			}
			
			/*Ako se lik pojavljuje dva puta, moze ga zamijeniti bilo ko*/
			if ((Prosjek(stud[j]) <= Prosjek(najbolji[i]) && zabiljezen(stud[j], najbolji, i, ind, j) == 0) && zabiljezen(najbolji[i], najbolji, i, ind, i) == 1){
				
				najbolji[i] = stud[j];
				ind[i] = j;
				
			}
			
			/*Ako su prosjeci isti, prednost ima onaj koji je abecedno ispred*/
			if (Prosjek(stud[j]) == Prosjek(najbolji[i]) && zabiljezen(stud[j], najbolji, i, ind, j) == 0){
				
				if (strcmpp(stud[j].prezime, najbolji[i].prezime, 1) == -1){
					najbolji[i] = stud[j];
					ind[i] = j;
				}
				else if (strcmpp(stud[j].prezime, najbolji[i].prezime, 1) == 0)
					if (strcmpp(stud[j].ime, najbolji[i].ime, 1) == -1){
						najbolji[i] = stud[j];
						ind[i] = j;
					}
				
			}
			
		}	
		
	}
	
	/*Ispisi najbolje*/
	if (vel > 0){
		for (i = 0; i < brnaj; i++)
			printf("%s %s\n", najbolji[i].prezime, najbolji[i].ime);
	}
	
	return vel;
}

int main() {
	
	return 0;
}
