#include <stdio.h>
/*Funkcija koja provjerava da li su dvije rijeci iste*/
int provjera_rijeci(char* provjera, char *prva, char* zadnja1){
    int vrati=1;
    while(*provjera!='\0' && (( *provjera>='A' && *provjera<='Z') || (*provjera >='a' && *provjera <='z')) && prva<=zadnja1){
        if(*provjera!=*prva && *provjera!=*prva-32 && *provjera!=*prva+32)
            vrati= 0;
        prva++;
        provjera++;
        if (*provjera=='\0')
            break;
        if(*prva=='\0')
            break;
    }
    prva--;
    if((*provjera>='A' && *provjera<='Z') || (*provjera >='a' && *provjera <='z') || prva<zadnja1)
        vrati= 0;
    return vrati;
}
int duzina_rijeci(char* zp, char* zk){
    int brojac=0;
    while(zp<=zk && *zp!='\0'){
        brojac++;
        zp++;
    }
    return brojac;
}
/*Provjeravamo da li smo naisli na rijec koju treba izbaciti*/
int provjera_citav_rijeci(char* provjera,char* prva){
    int vrati=1;
    while(*provjera!='\0' && (( *provjera>='A' && *provjera<='Z') || (*provjera >='a' && *provjera <='z') )&& prva!='\0'){
        if(*provjera!=*prva && *provjera!=*prva-32 && *provjera!=*prva+32)
            vrati=0;
        prva++;
        provjera++;
        if (*provjera=='\0')
            break;
        if(*prva=='\0')
            break;
    }
    
    if((*provjera>='A' && *provjera<='Z') || (*provjera >='a' && *provjera <='z'))
        vrati=0;
    return vrati;
}
/*Izbacujemo rijec*/ 
char* izbacivanje_rijeci(char* provjera, int duzina){
    char*s,*vrati;
    vrati=provjera;
    s=provjera;
    s+=duzina;
    while(*s!='\0'){
        if(*s=='\0')
            break;
        *provjera++=*s++;
    }
    *provjera='\0';
    return vrati;
}
char* izbaci_najcescu(char *s){
    char *vrati,*pocetak,*kraj,*test,*zp,*provjera,*zk,*t,*szp;
    char novi[10000];
    int broj_rijeci=0,max=0,ista=0,duzina=0,i=0;
    vrati=s;
    t=s;
    while(*s!='\0'){
        if(*s=='\0')
            break;
        while((*s<'A' || (*s>'Z' && *s<'a') || *s>'z')){
            s++;
            if(*s=='\0')
                break;
        }
        if(*s=='\0')
            break;
        pocetak=s;
        kraj=s;
        while((*kraj>='A' && *kraj<='Z') || (*kraj>='a' && *kraj<='z'))
            kraj++;
        kraj--;
        provjera=s;
        while(*provjera != '\0'){
            test=pocetak;
            ista=provjera_rijeci(provjera,test,kraj);
            if(ista){
                broj_rijeci++;
                ista=0;
            }
            while((*provjera>='A' && *provjera<='Z') || (*provjera>='a' && *provjera<='z')){
                if(*provjera=='\0')
                    break;
                provjera++;
            }
            while(*provjera!='\0' && (*provjera<'A' || (*provjera>'Z' && *provjera<'a') || *provjera>'z')){
                if(*provjera=='\0')
                    break;
                provjera++;
            }
        }
        if(broj_rijeci>max){
            max=broj_rijeci;
            zp=pocetak;
            zk=kraj;
        }
        broj_rijeci=0;
        s=kraj;
        if(*s=='\0')
            break;
        s++;
    }
    
    if(max>0){
        szp=zp;
        duzina=duzina_rijeci(szp,zk);
        t=vrati;
        while(zp<=zk){
            novi[i]=*zp;
            zp++;
            i++;
        }
        novi[i]='\0';
        for(;;){
            if(*t=='\0')
                break;
            while((*t<'A' || (*t>'Z' && *t<'a') || *t>'z')){
                t++;
                if(*t=='\0')
                    break;
            }
            ista=provjera_citav_rijeci(t,novi);
            if(ista){
                ista=0;
                izbacivanje_rijeci(t,duzina);
            }   
            while((*t>='A' && *t<='Z') || (*t>='a' && *t<='z')){
                t++;
                if(*t=='\0')
                    break;
            }
        }
    }
    return vrati;
}
void unesi(char niz[], int velicina) {
	int i = 0;
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}
int main() {
    char s[100000];
    printf("Unesi : ");
    unesi(s,100000);
    izbaci_najcescu(s);
    printf("%s",s);
	return 0;
}
