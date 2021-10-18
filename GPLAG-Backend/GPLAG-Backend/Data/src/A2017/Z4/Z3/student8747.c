#include <stdio.h>
#include <math.h>
#include <string.h>
int PrebrojRijeci(char* s)
{
	char* p=s;
	char* q=s;
	int BrojRazmaka=1;
	while(*p!='\0') {
		if((*p<65 || *p>90) && (*p<97 || *p>122) && *p==' ' || *p=='-') {
			q=p;
			while((*q<65 || *q>90) && (*q<97 || *q>122) && *q==' '  || *q=='-') {
				q++;
			}
			p=q;
			BrojRazmaka++;
		}

		else p++;
	}
	return BrojRazmaka;
}
void najduzi_bp(char* s1, char* s2){
    char* p=s1;
    char* q=s1;
    char* r=s1;
    char* q2=s1;
    char* Ubacivanje=s2;
    char* Pocetak;
    char* Kraj;
    int Temp=0;
    int Duzina=0;
    int NizPonavljanja[200]={0};
    int MaxDuzina=0;
    int Ponavljanje=PrebrojRijeci(s1);
   if(Ponavljanje==1){Ponavljanje++;}
    while(Ponavljanje!=0){
    while(*q2!='\0'){q2++;}
    while(p<q2){
        while(q<q2){
            q++;
            if(*q==*p  || *p==*q+32 || *p==*q-32 || *q=='\0' || *q==' '){q2=q;}
            if(*q>=48 && *q<=57){q2=q;}
            if((*q<'A' || *q>'Z' ) && (*q<'a'  || *q>'z')){q2=q;}
        }
        if(*p==*q || *p==*q+32 || *p==*q-32 || *q=='\0' || *q==' ' || (*q>=48 && *q<=57)){q2=q;}
        
    p++;
    q=p;
    }
    Duzina=q2-r;
    int Duzina2=0;
    char* p2=r+1;
    char* q4=s1+strlen(s1);
    char* q3=r+2;
    while(p2<q4){
        while(q3<q4){
            q3++;
           if(*q3==*p2  || *p2==*q3+32 || *p2==*q3-32 || *q3=='\0' || *q3==' '){q4=q3;}
            if(*q3>=48 && *q3<=57){q4=q3;}
            if((*q3<'A' || *q3>'Z' ) && (*q3<'a'  || *q3>'z')){q4=q3;} 
        }
        if(*p2==*q3 || *p2==*q3+32 || *p2==*q3-32 || *q3=='\0' || *q3==' ' || (*q3>=48 && *q3<=57)){q4=q3;}
        p2++;
        q3=p2;
    }
    Duzina2=q4-r;
    if(Duzina<Duzina2-1){p=p2;q=q3;q2=q4;Duzina=Duzina2-1;r=r+1;}
    
    if(Duzina>MaxDuzina){
        MaxDuzina=Duzina;
        Pocetak=r;
        Kraj=q2;
    if(*Pocetak>=48 && *Pocetak<=57 || (*Pocetak<'A' || *Pocetak>'Z' ) && (*Pocetak<'a'  || *Pocetak>'z')){Pocetak++;Duzina--;}
    if(*Kraj>=48 && *Kraj<=57){Duzina--;}
        while(Duzina!=0){
            *Ubacivanje=*Pocetak;
            Pocetak++;
            Duzina--;
            Ubacivanje++;
            Temp++;
        }
        *Ubacivanje='\0';
        Pocetak=Kraj-Temp;
    }
    while(p){
        if(*p==' ' || (*p>=48 && *p<=57)){break;}
        p++;
    }
    p=p+1;
    q=p+1;
    r=p;
    Ubacivanje=s2;
    Ponavljanje--;
    }
}
int main() {
  //AT5, iste duzine su abcdef i bcdefg, ali je abcdef prva
        char niz[10];
        najduzi_bp ("paramauntirajuci traktor eetankerskog sistema dvoumi abcdefg", niz);
        printf ("\nNiz: '%s'", niz);
      
    //Niz: 'abcdef'
	return 0;
}
