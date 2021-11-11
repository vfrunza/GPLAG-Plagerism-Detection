#include <stdio.h>

char* kodiraj (char* s, char* q){
    char* p=s;
    char* pocetak = s;
    int i,j,m=0,temp,temp1,max,min,frekvencija[95]={0},referentni[95]={0};
    
    for (i=0;i<95;i++){
        referentni[i]=i;
    }
    while (*p!='\0'){
        i=0;
        i=(*p-32);
        frekvencija[i]++;
        p++;
    }
    for (i=0;i<95;i++){
        max=i;
        for(j=i+1;j<95;j++){
            if (frekvencija[j]>frekvencija[max]){
                max=j;
            }
        }
                temp=frekvencija[i];
                frekvencija[i]=frekvencija[max];
                frekvencija[max]=temp;
                
                temp1=referentni[i];
                referentni[i]=referentni[max];
                referentni[max]=temp1;
    }
    for (i=0;i<95;i++){
    if (frekvencija[i]!=0) m++;}
    
    for (i=m;i<95;i++){
        min=i;
        for(j=i+1;j<95;j++){
            if (referentni[j]<referentni[min])
                min=j;
        }
        temp=referentni[i];
        referentni[i]=referentni[min];
        referentni[min]=temp;
    }
    i=0;
    while (i<96){
        if (i==95) *(q+i)='\0';
        else *(q+i)=referentni[i]+32;
        i++;
    }
    while (*s !='\0'){
        i=0;
        while (1){
            if (*(q+i)==*s){
                *s=126-i;
                break;
            }
            i++;
        }
        s++;
    }
    return pocetak;
}

char* dekodiraj (char* s, char* q){
    char* pocetak = s;
    int i;
    while (*s !='\0'){
        i=0;
        while (1){
            if (*(q+i)==*s){
                *s=*(q+126-i-32);
                break;
            }
            i++;
        }
        s++;
    }
    return pocetak;
}

int main() {
    char s[]="U ovom testu cemo testirati samo dekodiranje";
    char q[96]="";
    printf("%s",kodiraj(s,q));
    printf("\n%s",dekodiraj(s,q));
    printf("\n%s",q);
	return 0;
}
