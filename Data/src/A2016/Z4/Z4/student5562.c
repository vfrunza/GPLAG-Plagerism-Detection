#include <stdio.h>
#include <math.h>
#define E 0.0001

void unesi(char*s, int duzina){
	
	int i = 0;
	char znak = getchar();
	if (znak == '\n') znak = getchar();
	
	while (znak != '\n' && i < duzina - 1){
		
		s[i] = znak;
		i++;
		znak = getchar();
	}
	s[i] = '\0';
	
}

int pravilan(char*unos){
    
    int lijevih = 0, desnih = 0, zareza = 0;
    char * p = unos;
    
    /*Prazan string*/
    if (*unos == '\0')
        return 1;
    
    while(*p != '\0'){
        
        /*Ako se nadje znak koji uopste ne spada u opseg koristenih znakova*/
        if (((int)*p < 48 || (int)*p >57) && *p != '(' && *p != ')' && *p != ',' && *p != '-' && *p != '.')
            return 0;
            
        /*Ako prvi znak nije otvorena zagrada*/
        if (p == unos && *p != '(')
            return 0;
            
        /*Ako zadnji znak nije zatvorena zagrada*/
        if (*(p + 1) == '\0' && *p != ')')
            return 0;
        
        /*Ako se oko zagrada nalaze nedozvoljeni znakovi*/
        if (*p == '('){
            lijevih++;
            if ((p > unos && *(p - 1) != ',') || (*(p + 1) != '-' && ((int)*(p + 1) < 48 || (int)*(p + 1) > 57) && *(p + 1) != '\0'))
                return 0;
        }
        if (*p == ')'){
            desnih++;
            if ((((int)*(p - 1) < 48 || (int)*(p - 1) >57) && *(p - 1) != '.') || (*(p + 1) != ',' && *(p + 1) != '\0'))    
                return 0;
        }
        
        /*Ako se oko zareza nalaze nedozvoljeni znakovi*/
        if (*p == ','){
            zareza++;
            if (*(p - 1) == '(' || *(p - 1) == '-' || *(p + 1) == ',' || *(p + 1) == '.' || *(p + 1) == ')')
                return 0;
        }
        
        /*Ako se oko decimala (tacke) nalaze nedozvoljeni znakovi*/
        if (*p == '.')
            if (*(p + 1) == '.' || *(p - 1) == '.' || *(p + 1) == '-' || *(p - 1) == '-')
                return 0;
        
        /*Ponavljanje minusa*/
        if (*p == '-')
            if (*(p + 1) == '-' || *(p - 1) == '-')
                return 0;
        
        /*Broj ne smije biti okruzen decimalima*/
        if(*p >= 48 && *p <= 57)
            if (*(p + 1) == '.' && *(p - 1) == '.')
                return 0;
        p++;
        
    }
    
    if (desnih + lijevih - zareza != 1)
        return 0;
    
    return 1;
}

char* obuhvat(char*unos, float x1, float y1, float x2, float y2){
    
    char*p = unos, *ppoc, *p2;
    float koord[100];
    float cijeli = 0, decimala = 0;
    int br_decimala = 0;
    int i = 0, j = 0, m, minus = 0, br_koor = 0, unutar;
    float xT, yT;
    char*pok[100];
    
    /*Ako je unos nepravilan vrati nul pokazivac*/
    if (pravilan(unos) == 0)
        return NULL;
    
    /*Skeniranje koordinata iz stringa*/
    while (*p != '\0'){
        
        if (*p == '-')
            minus = 1;
        
        if ((*p >= 48 && *p <= 57)){ 
            
            /*Spasiti adresu trenutne zagrade*/
            ppoc = p;
            while (*p != '(')
                p--;
            
            /*Spasi lokaciju u niz pokazivaca*/
            pok[i] = p;
            p = ppoc;
            
            /*Dodavanje cifri cijelog dijela*/
            while (*p >= 48 && *p <= 57){
                
                cijeli = cijeli*10 + (float)*p - 48;
                
                p++;
            }
            
            /*Dodavanje cifri decimalnog dijela*/
            if (*p == '.'){ 
                    
                p++;
                    
                while (*p >= 48 && *p <= 57){
                    
                    decimala = decimala*10 + (float)*p - 48;
                    br_decimala++;
                    
                    p++;
                }
                
                decimala /= pow(10, br_decimala);
            }
            
            /*Reset vrijednosti i store-ovanje koordinate*/
            koord[i] = cijeli + decimala;
            br_koor++;
            if (minus == 1)
                koord[i] = -koord[i];
            
            cijeli = 0;
            decimala = 0;
            br_decimala = 0;
            minus = 0;
            
            i++;
        }
    
    p++;    
    }
    br_koor = i;
    p = unos;
    
    
    /*Provjeravanje da li tacke pripadaju cetverouglu*/
    for (i = 0; i < br_koor - 1; i = i + 2){
        xT = koord[i];
        yT = koord[i + 1];
        
        /*Uslov*/
        
        if (xT < x1 || (xT > x2 && fabsf(xT - x2) > E) || yT < y1  || (yT > y2 && fabsf (yT - y2) > E))
            unutar = 0;
        else
            unutar = 1;
        
        /*Izbacivanje ako uslov nije ispunjen*/
        
        if (unutar == 0){
            
            p = pok[i];
            ppoc = p;
            
            while (*p != ')' && *p != '\0')
                p++;
            p2 = p;
            p = ppoc;
            
            for (j = 0; j <= p2 - p + 1; j++){
                
                while (*p != '\0'){
                    
                    *p = *(p + 1);
                    
                    p++;
                }
                
                /*Pokazivaci se moraju pomjeriti jer su vrijednosti pomjerene*/
                for (m = 0; m < br_koor; m++){
                    pok[m]--;
                }
                
                p = ppoc;
                
            }
        
        }
            
    }
    
    /*Uklanjanje viska zareza na kraju*/
    p = unos;
    while (*p != '\0'){
        
        if (*p == ',' && *(p + 1) == '\0')
            *p = *(p + 1);
        
        p++;
    }
    
    return unos;
}

int main() {
	
	char unos[100];
	unesi(unos,1000);
	
	printf("%s", obuhvat(unos, 3, 3, 7, 7));
	
	return 0;
}
