#include <stdio.h>

void najduzi_bp(char* s1, char* s2){
    char* pomocni, *slobodni, *drugi_pomocni, *index;
    int brojac=0, control=0, max=0;
    drugi_pomocni=s2;
    pomocni=s1;
    slobodni=s1;
    while(*s1!='\0'){
        pomocni=s1;
        index=s1+1;
        while(((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) && (*s1!='\0')){
            slobodni=pomocni;
            control=0;
            while(slobodni<s1){
                if(*slobodni==*s1 || *slobodni+32==*s1 || *slobodni==*s1+32){
                    control=1;
                    break;
                }
                slobodni++;
            }
            if(control==1) break;
            s1++;
            brojac++;
        }
        if(brojac>max){
            max=brojac;
            slobodni=pomocni;
            while(pomocni<s1){
                *s2=*pomocni;
                s2++;
                pomocni++;
            }
            *s2='\0';
            s2=drugi_pomocni;
        }
        brojac=0;
        s1=index-1;
        s1++;
    }
}

int main() {
	return 0;
}
