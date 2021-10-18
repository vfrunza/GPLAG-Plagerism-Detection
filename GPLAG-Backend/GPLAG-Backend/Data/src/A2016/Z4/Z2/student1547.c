#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
/*Broji koliko razlicitih karaktera ima u stringu*/
int brojkaraktera(char*a){
    int br=0, desiosebreak=0;
    char*p=a, *q=a;
    while(*p!='\0'){
        q=a;
        desiosebreak=0;
        while(q!=p){
            if(*q==*p){
                desiosebreak=1;
                break;
            }
            q++;
        }
        if(desiosebreak){ 
            p++;
            continue;
        }
        br++;
        p++;
    }
    return br;
}
/*funkcija za tabelu*/
char* redaj_po_velicini(char*a, char*b){
    int brkar=brojkaraktera(a), i=0, brojpon[100], desiosebreak, j, ascii=32, tempp;
    char* karakter[100], *p=a, *q, temp, *y=b, *z=b;
    char ns[100];
    char *pns=ns; /*ns=novi string, pns=pokazivacnovistring*/
    while(*p!='\0'){
        *pns=*p;
        p++; pns++;
    }
    *pns='\0';
    p=ns; 
    while(*p!='\0'){
        q=ns;
        desiosebreak=0;
        while(q!=p){
            if(*q==*p){
                desiosebreak=1;
                break;
            }
            q++;
        }
        if(desiosebreak){
            p++;
            continue;
        }
        else{
            karakter[i]=p;
            p++;
            i++;
        }
    }
    for(i=0;i<brkar;i++){
        q=ns;
        brojpon[i]=0;
        while(*q!='\0'){
            if(*karakter[i]==*q) brojpon[i]++;
            q++;
        }
    }
    for(i=0;i<brkar;i++){
        for(j=i+1;j<brkar;j++){
            if(brojpon[i]<brojpon[j]){
                /*zamjena karaktera*/
                temp=*karakter[i];
                *karakter[i]=*karakter[j];
                *karakter[j]=temp;
                /*zamjena broja ponavljanja*/
                tempp=brojpon[i];
                brojpon[i]=brojpon[j];
                brojpon[j]=tempp;
            }
            else if(brojpon[i]==brojpon[j]){
                if(*karakter[i]>*karakter[j]){
                    /*zamjena karaktera*/
                    temp=*karakter[i];
                    *karakter[i]=*karakter[j];
                    *karakter[j]=temp;
                    /*zamjena broja ponavljanja*/
                    tempp=brojpon[i];
                    brojpon[i]=brojpon[j];
                    brojpon[j]=tempp;
            }
            
            }
        }
        
    }
    for(i=0;i<brkar;i++){
        *y=*karakter[i];
        y++;
    }   
    /*Dodavanje ostalih karaktera u tabelu*/
    if(brkar<96){
        while(brkar!=96){
            z=b;
            while(z!=y){
                if(*z==ascii) break;
                z++;
            }
            if(z==y){
                *y=ascii;
                y++;
                brkar++;
                ascii++;
            }
            else ascii++;
        }
        y--;
    }
    *y='\0';
    return b;
}
/*Nalazi poziciju karaktera u tabeli*/
int pozicija(char x, char*b){
    int pozicija=0;
    while(x!=*b){
        pozicija++;
        b++;
        if(*b=='\0') break;
    }
    return pozicija;
}

char* kodiraj(char* a, char*b){
    char*p=a;
    b=redaj_po_velicini(a,b);
    while(*p!='\0'){
        *p=126-pozicija(*p,b);
        p++;
    }
    return a;
}


char* dekodiraj(char* a, char*b){
    char*p=a, pozicija;
    while(*p!='\0'){
        pozicija=126-*p;
        *p=*(b+pozicija);
        p++;
    }
    return a;
}

int main (){
    char a[500], b[100]= "";
	printf("Unesite tekst: ");
	unesi(a,500);
    printf("'%s'\n", kodiraj(a,b));
    printf("'%s'\n", b);
	printf("'%s'", dekodiraj(a,b));

	return 0;
}
