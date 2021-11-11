#include<stdio.h>
#include<ctype.h>

int Strlen(char*s){
    int duzina=0;
    while(*s!='\0') {
        duzina++;
        s++;
    }
    return duzina;
}
int my_strcmp(char* s1,char* s2) {
    while(*s1==*s2 && *s1!='\0' && *s2!=' ') {
        s1++;s2++;}
        if(*s1=='\0' || *s1==' ')
        return 1; else return 0; }
        void my_strcpy(char*s1,char*s2) {
            while(*s2!='\0') *s1++=*s2++;
        }
        int poredi2(char*s1,char*s2,char*p1,char*p2) {
            while(s1!=s2 && p1!=p2) {
                if(!(*s1==*p1 || *s1==(*p1+32) || *s1==(*p1-32))) return 0;
                s1++; p1++; }
                if (p1==p2 && s1==s2) return 1;
                return 0;}
            void izbaci(char*s,char*rijec) {
                    int neslovo=1;
                    char*poc=rijec;
                    char*kraj=rijec+Strlen(rijec);
                while(*s!='\0') {
                    if(!((*s>='A' && *s<='Z')||(*s>='a' && *s<='z')))
                neslovo=1;
                else if(neslovo==1) {
                    neslovo=0;
                    char *p1=s;
                    while((*p1>='A'&& *p1<='Z') || (*p1>='a' && *p1<='z')) p1++;
                    if(poredi2(poc,kraj,s,p1)==1) {
                        char*s1=s;
                        while(*p1!='\0') {
                            *s1=*p1;
                            s1++;
                            p1++;
                        } *s1='\0';
                        neslovo=1;
                    }}
                    s++; }}
             char*izbaci_najcescu(char*str) {
                 
                        char rijeci[1000][1000]={0};
                        int brojac[1000]={0};
                        int rijec_cnt=0,i;
                        char*s=str;
                        int len=Strlen(str);

                        char rijec[1000];
                        int clen;
                        for(i=0;i<len;i++){
                            clen=0;
                            while(isalpha(str[i]) && i<len) {
                                rijec[clen]=str[i];
                                i++;
                                clen++;
                            }
                            if (clen>0) {
                            rijec[clen]='\0';
                            int naso_rijec=0;
                            int j;
                            for(j=0;j<rijec_cnt;j++) {
                                if(my_strcmp(rijeci[j],rijec)==1) {
                                    naso_rijec=1;
                                    brojac[j]++;break;
                                }
                            }
                            if (naso_rijec==0) {
                                my_strcpy(rijeci[rijec_cnt],rijec);
                                brojac[rijec_cnt]=1;
                                rijec_cnt++;
                            }
                            }
                        }
                       // for(i=0;i<rijec_cnt;i++)
                       // printf("%d %s\n",brojac[i],rijec[i]);
                        int max=0;int index=0;
                        for(i=0;i<rijec_cnt;i++) {
                            if (brojac[i]>max) {
                                max=brojac[i];
                                index=i;
                            }}
                            
                            char*pocetak_najcesce=rijeci[index];
                            izbaci(s,pocetak_najcesce);
                            return s;
                            }
                    int main() {
    char s[100]="koja rijec je najcesca je je";
    printf("%s",izbaci_najcescu(s));
    return 0;
}