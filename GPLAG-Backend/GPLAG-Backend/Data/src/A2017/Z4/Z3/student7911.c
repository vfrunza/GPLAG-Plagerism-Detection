#include <stdio.h>

int Slovo(char s){
    if((s>='a' && s<='z') || (s>='A' && s<='Z')) return 1;
    else return 0;
}

int Prebrojistring(char *s){
    int brojac = 0;
    while(*s != '\0'){
        brojac++;
        s++;
    }
    return brojac;
}

void Izbaciiste(char niz[]){
    int i, j, k, vel;
    vel = Prebrojistring(niz);
    
    for (i=0; i<vel-1; i++) {
        for (j=i+1; j<vel; j++) {
            if (niz[i] == niz[j] || niz[i] == (niz[j] + 32) || niz[i] == (niz[j] - 32)) {
                for (k=j; k<vel; k++) {
                    niz[k] = niz[k+1];
                }
                niz[vel] = '\0';
                vel--;
                j--;
            }
        }
    }
}

void najduzi_bp(char* s1, char* s2){
    char temp[200], *poktemp, *poc, *kraj, *cuvar;
    int veltemp, vels2 = 0;
    cuvar = s2;
    
         while(*s1 != '\0'){
            if (Slovo(*s1)) {
                poc = s1;
                while(Slovo(*s1)) s1++;
                kraj = s1;
                
                poktemp = temp;
                while(poc < kraj) {
                    *poktemp = *poc;
                    poc++;
                    poktemp++;
                }
                *poktemp = '\0';
                
                Izbaciiste(temp);
                veltemp = Prebrojistring(temp);
                
                if(veltemp > vels2){
                    vels2 = veltemp;
                    poktemp = &temp[0];
                    s2 = cuvar;
                    while(*poktemp != '\0'){
                        *s2 = *poktemp;
                        s2++;
                        poktemp++;
                    }
                    *s2 = '\0';
                }
            }
            else    s1++;
        }
}
int main() {
    char s[100] = "Ovo";
    Izbaciiste(s);
    printf ("%s.", s);
	return 0;
}
