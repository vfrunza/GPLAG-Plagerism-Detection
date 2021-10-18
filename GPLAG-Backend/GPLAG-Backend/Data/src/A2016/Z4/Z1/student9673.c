#include <stdio.h> 

void unesi(char niz[], int velicina){
    char znak;
    int i=0;
    /* korisnik unosi znak sa tastature (u slucaju entera ponavlja unos) */
    do{
        znak=getchar();
    }while(znak=='\n');
    /* sve dok ne unese enter od unesenih karaktera pravi se niz */
    while(i<velicina-1 && znak!='\n'){
        niz[i++]=znak;
        znak=getchar();
    }
    /* string po standardu zavrsava znakom \0 */
    niz[i]='\0';
}

char* izbaci_najcescu(char* niz){
    char* p=niz;
    char* q=niz;
    char* r=niz;
    char* poc=niz;
    char* kraj=niz;
    char* pi=niz;
    char* ki=niz;
    char* prvi=niz;
    char* drugi=niz;
    char* pocetak_izbacivanja=niz;
    char* kraj_izbacivanja=niz;
    char* temp=niz;
    char* pomocna=niz;
    char string[10000];
    int brojac=0, max=0, pret=1, i=0, pret_1=0, pret_2=0;
    
    while(*p!='\0'){
        /* pronalazi pocetak rijeci u stringu */
        if(((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && (p==niz || *(p-1)==' ' || *(p-1)=='-'  || *p=='-' || (*p>='0' && *p<='9'))){
            poc=p; 
            while((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))p++;
                /* ako je samo jedna rijec u stringu */
                if(poc==niz && *p=='\0'){
                    max=1;
                    pocetak_izbacivanja=poc;
                    kraj_izbacivanja=p;
                    break;
                    }
                /* pronalazi kraj rijeci */    
                else if(*p==' ' || *p=='\0' || *p=='-' || (*p>='0' && *p<='9')){
                    kraj=p;
                    brojac=0;
                    r=p;
                    /* prolazi kroz string i pronalazi ostale rijeci */
                while(*r!='\0'){
                if(((*r>='A' && *r<='Z') || (*r>='a' && *r<='z')) && (r==niz || *(r-1)==' ' || *(r-1)=='-' || (*(r-1)>='0' && *(r-1)<='9'))){
                    pi=r; /* pocetak pronadjene rijeci */
                    while((*r>='A' && *r<='Z') || (*r>='a' && *r<='z'))r++;
                        if(*r==' ' || *r=='\0' || *r=='-'  || (*p>='0' && *p<='9')){
                            ki=r; /* kraj pronadjene rijeci */
                            pret=1; /* logicka promjenjiva postavljena na 1- pretpostavka da su rijeci jednake */
                        }
                    prvi=poc;
                    drugi=pi;
                    /* da li je trenutna rijec ista kao i ona sa kojom poredimo (bez obzira na velika i mala slova) */
                    while(drugi!=ki && drugi!='\0'){
                        pret_1=0;
                        pret_2=0;
                        if(*prvi>='A' && *prvi<='Z'){
                            *prvi+='a'-'A';
                            pret_1=1;
                        }
                        if(*drugi>='A' && *drugi<='Z'){
                            *drugi+='a'-'A';
                            pret_2=1;
                        }
                        if(*prvi!=*drugi)pret=0;
                        if(pret_1)*prvi-='a'-'A';
                        if(pret_2)*drugi-='a'-'A';
                        prvi++;
                        drugi++;
                    }
                    /* ako jeste (pret==1) uveca se broj njenog ponavljanja u stringu */
                    if(pret==1)brojac++;
                   
                }  
                if(*r=='\0')break;
                 r++;
                }
    
             }
             if(*p=='\0')break;
        }
        /* ako je broj ponavljanja trenutne veci od prethodnog maksimuma postavimo tu rijec kao rijec koju treba izbaciti */
        if(brojac>max)
        {
            max=brojac;
            pocetak_izbacivanja=poc;
            kraj_izbacivanja=kraj;
        }
        
    p++;    
    }

    /* ako se string sastoji od samo jedne rijeci */
    if(poc==niz)
    {
        do{
            *pocetak_izbacivanja=*kraj_izbacivanja;
        }while(*kraj_izbacivanja!='\0' && pocetak_izbacivanja++!=kraj_izbacivanja++);
    }
    
    p=niz;
    
    /* ako se nijedna rijec ne ponavlja izbaci prvu! */
    if(max==0){
        while(*p!='\0'){
             if(((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && ((p==niz || *(p-1)==' ' || *(p-1)=='-' || (*(p-1)>='0' && *(p-1)<='9')))){
                 poc=p;
                 while(((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')))p++;
                    if(*p==' ' || *p=='\0')kraj=p;
                    break;
            }
        p++;
        }
    
    /* izbacivanje */
        while(*kraj!='\0'){
                *poc=*kraj;
                poc++;
                kraj++;
            }
             if(*kraj=='\0')*poc='\0';
        }
        
    /* rijec koja se ponavlja */
    if(max!=0 && poc!=niz){
        /* kreiranje pomocnog stringa (cine ga samo mala slova) preko kojeg cemo traziti rijec za izbaciti */
        while(pocetak_izbacivanja!=kraj_izbacivanja){
            if(*pocetak_izbacivanja>='A' && *pocetak_izbacivanja<='Z')string[i]=(*pocetak_izbacivanja+32);
            else string[i]=*pocetak_izbacivanja;
            pocetak_izbacivanja++;
            i++;
        }
        string[i]='\0';

    p=niz;
    temp=string;
    
    while(*p!='\0'){
        poc=niz;
        kraj=niz;
        temp=string;
        pret=0;
        if((*p==*temp || *p==(*temp-32)) && (p==niz || *(p-1)==' ' || *(p-1)=='-' || (*(p-1)>='0' && *(p-1)<='9'))){
            poc=p;
            pomocna=p;
            while((*pomocna==*temp || *pomocna==(*temp-32)) && *temp!='\0'){
                pomocna++; temp++;
            }
            if(*temp=='\0' && (*pomocna==' ' || *pomocna=='\0' || *pomocna=='-' || (*pomocna>='0' && *pomocna<='9'))){
                kraj=pomocna;
                pret=1;
            }
            
        }
        /* ako je rijec pronadjena logicka promjenjiva je 1, slijedi izbacivanje */
        if(pret){
                while(*kraj!='\0'){
                    *poc++=*kraj++;
                }
                if(*kraj=='\0')*poc='\0';
        }
        p++;
       }
    
    }
       
    /*prazan string - ne radi nista */
    else{
        return q;
    }
return q;
}

int main(){
    char tekst[100];
    printf("Unesi tekst: ");
    unesi(tekst,100);
    izbaci_najcescu(tekst);
    printf("%s",tekst);
    return 0;
}


