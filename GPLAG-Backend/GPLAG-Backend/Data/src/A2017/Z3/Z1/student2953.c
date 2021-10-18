#include <stdio.h>
#include <math.h>


int dva_od_tri(int* niz1, int vel1, int* niz2, int vel2, int* niz3, int vel3) {
    
    int brojac=0;
    int* prosli=NULL;
    int* pok1=niz1;
    int* pok2=niz2;
    int* pok3=niz3;
    
    while(pok1<niz1+vel1) {
        pok2=niz2;
        while(pok2<niz2+vel2) {
            if(*pok1==*pok2 && (prosli==NULL || *pok1!=*prosli)) {
                int pronadjen=0;
                pok3=niz3;
                while(pok3<niz3+vel3) {
                    if(*pok3==*pok2) {
                        pronadjen=1; 
                        break;
                    }
                    else pok3++;
                }
                if(!pronadjen) brojac++;
            }
            pok2++;
        }
        prosli=pok1;
    pok1++;
}

pok1=niz1;
pok2=niz2;
pok3=niz3;

    while(pok1<niz1+vel1) {
        pok3=niz3;
        while(pok3<niz3+vel3) {
            if(*pok1==*pok3 && (prosli==NULL || *pok1!=*prosli)) {
                int pronadjen=0;
                pok2=niz2;
                while(pok2<niz2+vel2) {
                    if(*pok3==*pok2) {
                        pronadjen=1; 
                        break;
                    }
                    else pok2++;
                }
                if(!pronadjen) brojac++;
                }
                pok3++;
            }
            prosli=pok1;
            pok1++;
        }
pok1=niz1;
pok2=niz2;
pok3=niz3;
int *k1 = niz1 + vel1;
int *k2 = niz2 + vel2;
int *k3 = niz3 + vel3;
    while(pok2<niz2+vel2) {
        pok3=niz3;
        while(pok3<niz3+vel3) {
            if(*pok2==*pok3 && (prosli==NULL || *pok2!=*prosli)) {
                int pronadjen=0;
                pok1=niz1;
                while(pok1<niz1+vel1) {
                    if(*pok1==*pok2) {
                        pronadjen=1; 
                        break;
                    }
                    else pok1++;
                }
                if(!pronadjen) brojac++;
                }
                pok3++;
            }
            prosli=pok2;
            pok2++;
}

return brojac;

}

int main() {
	
	int niz1[]={1,2,3,5};
	int niz2[]={1,2,4,6,7};
	int niz3[]={1,3,4,8,9,10};
	int rez=dva_od_tri(niz1, 4, niz2, 5, niz3, 6);
	printf("%d", rez);
	
	return 0;
}
