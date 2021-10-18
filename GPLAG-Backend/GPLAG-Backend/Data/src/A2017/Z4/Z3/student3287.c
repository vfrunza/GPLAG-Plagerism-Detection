#include <stdio.h>

int JeLiSlovo (char znak){
    return ((znak >= 'A' && znak <= 'Z') || (znak >= 'a' && znak <= 'z'));
}

//provjera duzine stringa, tj. pojedinacne rijeci

int duzina (char * string){
    int duzina = 0;
    while (*string != '\0' && JeLiSlovo(*string)){
        duzina++;
        string++;
    }
    return duzina;
} 



/*int prebroji(const char*s, char znak){
    int broj = 0;
    if (znak >= 'A' && znak<= 'Z') znak += 'a' - 'A';
    while(*s != '\0' && JeLiSlovo(*s)){
        char tmp = *s;
        if(tmp >= 'A' && tmp <= 'Z') tmp += 'a' - 'A';
        if (tmp == znak) broj++;
        s++;
    }
    return broj;
} */

char * Izbaci (char * string){
    int i, j, k;
    char *q = string;
    int duzinaR = 0;
    duzinaR = duzina(string);
    
    for(i = 0; i < duzinaR; i++){
        for(j = 1; j < duzinaR ; j++){
            if(string [i] == string[j]){
            for(k = i; duzinaR; k++ )
                string[k] = string[k + 1];
            duzinaR--;
            i--;
        }
    }
    }
    return q;
}


void najduzi_bp (char * s1, char * s2){
    int max = 0, DuzinaRijeci = 0;
    
    char* p = s1;
    char *poc = s1;
  
    char *naMAX = s1;
    
    while( *p != '\0'){
            if (JeLiSlovo(*p)){
                
                Izbaci(p);
                poc = p;
                
               while(*p != '\0' && JeLiSlovo(*p)){
                    
                    p++;
                }
               DuzinaRijeci = duzina(poc);
               if(DuzinaRijeci > max) {
                   naMAX = poc ;
                    max = DuzinaRijeci;
            }
            
        }
        p++;
    }
    
    while (*s2 != '\0' && JeLiSlovo(*s2)){
        *naMAX = *s2;
        naMAX ++;
        s2++;
    }
   

}

int main(){
   
	return 0;
}