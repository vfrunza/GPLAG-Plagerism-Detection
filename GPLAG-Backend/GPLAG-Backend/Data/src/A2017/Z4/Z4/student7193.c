#include <stdio.h>

    int provjeri(char *s){
    	char *pom=s;
        char *p, *poc, *pocetak1, *pocetak2, *kraj1, *kraj2, *p1, *p2, *q1, *q2, *kr;
        int slash=0,DA=0,vrati=0;;

        while(*s!='\0'){
        	if(vrati==1){
        		vrati=0;
        		s=pom;
        	}
            slash=0;
            if(*s=='<'){
                p=s;
                poc=s;
                p++;
                while(*p!='\0'){
                    if(*p=='<') return 0;
                    if(*p=='>' || *p==' ') { kr=p; break; }
                    if(*p=='/') slash=1;
                    p++;
                }
                if(*p=='\0') return 0;

                if(slash==0){
                    pocetak1=poc;
                    kraj1=kr;
                    DA=1;
                }
                else{
                    pocetak2=poc;
                    kraj2=kr;
                    if(DA==1){
                        DA=0;

                        p1=pocetak1;
                        p2=pocetak2;
                        q1=kraj1;
                        q2=kraj2;

                        p1++;
                        p2++;p2++;

                        while(p1!=q1 && p2!=q2){
                            if(*p1!=*p2) return 0;
                            p1++;
                            p2++;
                        }
                        if(p1!=q1 || p2!=q2) return 0;
                            kraj2++;
                            if(kraj2=='\0') return 1;
                            
                    }
                }

            }
           
            s++;
        }
		if(DA==1) return 0; 
        return 1;
    }

int main()
{
    printf("%d",provjeri("<asda><b></ab></asda>"));

    return 0;
}
