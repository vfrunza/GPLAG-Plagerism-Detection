#include <stdio.h>
int provjeri_duzine(char *s, int *niz, int velicina)
{
    int i=0,brojac=0;
    while(*s!='\0') {
        if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
            brojac++;
        }

        else if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
            if(brojac!=0) {
                if(niz[i]!=brojac) {
                    return 0;
                    break;
                }
                i++;
            }
            brojac=0;
        }
        s++;
    }/*da bi nam uzimao u obzir i rijeci poslije kojih nema nista*/
    if(brojac!=0) {
        if(niz[i]!=brojac) {
            return 0;
        }
        i++;
    }
/*ako su velicine nizova razlicite,vracamo nulu*/
    if(velicina!=i)
        return 0;

    return 1;

}
int main()
{
    
    return 0;
}