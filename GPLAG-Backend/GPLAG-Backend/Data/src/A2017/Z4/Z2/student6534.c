#include <stdio.h>
/*void izbacirijec(char* recenica, int niz[], int vel) {
    char* s=recenica, *p=recenica,*pt, *pm, *kt, *km;
    int brojac=0, i=0;
    while(*s!='\0') {
        if((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) {
            brojac=0;
            pt=s;
            while((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) {
                s++;
                brojac++;
            }
            if(*s==' ' || *s=='\0'){
                kt=s;
                if(brojac<niz[i]){
                    pm=pt;
                    km=kt+1;
                    while(*km!='\0'){
                         *pm=*km;
                         pm++;
                         km++;
                     }
                *pm='\0';
                s=pt-1;
                }
            }
        }
        i++;
        s++;
    }
}
int main() {
    char s[]="Ja idem kuci danas";
    int niz[3]={3,4,5,6};
    izbacirijec(s,niz,3);
    printf("%s", s);
    return 0;
}


void apsolutna(char*s, char*p) {
    char*kraj, *pm, *km;
    
        while(!((*p>='a' && *p<='z') || (*p>='A' && *p<='Z'))) {
        if(*p=='.' && *(p+1)=='.' && *(p+2)=='\\') {
            kraj=s;
            while (*kraj!='\0') kraj++;
            while (*kraj!='\\') kraj--;
                pm=kraj;
                *pm='\0';
                p=p+2;
        }
        p++;
        }
        km=s;
        while(*km!='\0') km++;
        *km='\\';
        km++;
        while(*p!='\0') {
            *km=*p;
            km++;
            p++;
        }
        *km='\0';
}
    
int main() {
    char s[]="C:\\Users\\student\\Desktop\\PrviProjekat";
    char p[]="..\\..\\dir\\file.txt";
    apsolutna(s,p);
    printf("%s", s);
    return 0;
}
*/
#include <stdio.h>
int f1(int p, int *q) {
    *q=p* *q;
    return *q--;
}

int f2(char *x, char p){
 char *q=x;
 while (*q<p && *q!='\0') q++;
 return q-x;
}

void f3(char*x){
*(x+1)=*(x+1)+1;
*x++='P';
x+=1;
*x--='P';
}
int main() {
 int P[4]={10,11,12,13};
 int Q[7]={1,2,3,4};
 char s[8]="Belgija";
 int q=P[1],p=Q[1];
f1(p,&p);
 printf("%d\n",p);
q=Q[1]+*(P+1);
 printf("%d\n",q);
q=f1(q,Q);
 printf("%d\n",q);
 q=f2(s,'s');
 printf("%d\n",q);
f3(s);
 printf("%s\n",s);
 return 0;
}