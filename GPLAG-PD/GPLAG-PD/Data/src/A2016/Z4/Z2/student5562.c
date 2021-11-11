#include <stdio.h>

void unesi (char* s, int velicina){
    
    int i = 0;
    char znak = getchar();
    if (znak == '\n') znak = getchar();
    
    while (znak != '\n' && i < velicina - 1){
        
        s[i] = znak;
        i++;
        znak = getchar();
        
    }
    s[i] = '\0';
    
}

char * kodiraj(char* tekst, char* tablica){
    
    int pon[100];
    int i, j, k = 0, znak = 0 , max;
    char* t = tekst;
    int nadjen = 0;
    char temp;
    int tempint;
    
    /*Postaviti sva ponavljanja na 0 (inicijalizacija)*/
    for (i = 0; i < 100; i++)
        pon[i] = 0;
    
    /*Trazenje znakova koji se koriste*/
    while (*t != '\0'){
        
        nadjen = 0;
        
        for (i = 0; i < znak; i++){
            
            if (*t == tablica[i]){
                nadjen = 1;
                break;
            }
        }
        
        if (nadjen == 0){
            
            tablica[znak] = *t;
            znak++;
        }
            
        t++;
    }
    
    /*Brojanje ponavljanja znakova*/
    t = tekst;
    for (i = 0; i < znak; i++){
        
        while (*t != '\0'){
            
            if(*t == tablica[i]){
                pon[i]++;
            } 
            t++;
        }
        t = tekst;
        
    }
    
    /*Sortiranje znakova po brojanju ponavljanja*/
    for (i = 0; i < znak; i++){
        
        max = i;
        
        for (j = i + 1; j < znak; j++){
            
            if (pon[j] > pon[max] || (pon[j] == pon[max] && (int)tablica[j] < (int)tablica[max])){

                max = j;
            }
            
        }
        tempint = pon[i];
        pon[i] = pon[max];
        pon[max] = tempint;
        
        temp = tablica[i];
        tablica[i] = tablica[max];
        tablica[max] = temp;
        
    }
    
    
    /*Ubacivanje ostalih znakova u tablicu*/
    for (i = 32; i <= 126; i++){
        
        for (j = 0; j < znak; j++){
            
            if ((char)i == tablica[j])
                break;
                
            if (j == znak - 1){
                tablica[znak + k] = (char)i;
                k++;
                
            }
        }
    }
    tablica[znak + k] = '\0';
    
    k = 0;
    if (znak == 0){
        
        for (i = 32; i <= 126; i++){
            tablica[k] = (char)i;
            k++;
        }
    }

    
    /*Kodiranje*/
    t = tekst;
    while (*t != '\0'){
        
        for (i = 0; i < znak; i++){
            
            if (*t == tablica[i]){
                
                *t = (char)(126 - i);
                break;
            }
        }
        
        t++;
    }
    
    t = tekst;
    return t;
}


char * dekodiraj(char*tekst, char*tablica){
    
    char * t = tekst;
    int poz;
   
    while (*t != '\0'){
        
        poz = 126 - (int)*t;
        *t = tablica[poz];
        t++;
    }
    
    t = tekst;
    return t;
}


int main() {
	
	char tekst[200];
	char tablica[200];
	
	unesi(tekst, 200);
	
	printf("%s", kodiraj(tekst, tablica));
	printf("\n");
	printf("%s", dekodiraj(tekst, tablica));
	
	return 0;
}
