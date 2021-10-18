#include <stdio.h>

int da_li_su_isti(char *p1,char *p2){
    while(*p2!='>' && *p2!=' '){
        char c1=*p1;
        char c2=*p2;
        if(c1>='A' && c1<='Z')c1+=32;
        if(c2>='A' && c2<='Z')c2+=32;
        if(c1!=c2) return 0;
        p1++;
        p2++;
    }
    return 1;
}

int provjeri(char *s){
    char *niz_pok_otvoreno[500];
    char *niz_pok_zatvoreno[500];
    char *pok[1000];
    int brojac1=0, brojac2=0,brojac0=0;
    int i,j;
    while(*s!='\0'){
        if(*s=='<' && *(s+1)!='/'){ 
            if(*(s+1)==' ' ||*(s+1)=='>' ) return 0;
            
            niz_pok_otvoreno[brojac1++]=s+1;
            pok[brojac0++]=s+1;
        }
        else if(*s=='<' && *(s+1)=='/'){
            if(*(s+2)==' ' ||*(s+2)=='>' ) return 0;
            
            niz_pok_zatvoreno[brojac2++]=s+2; 
            pok[brojac0++]=s+2;
        }
        s++;
    }
    
    int ne_broji[500]={0};
    if(brojac1!=brojac2) return 0;
    for(i=0;i<brojac1;i++){
        int brojac=0;
        for(j=0;j<brojac2;j++){
            
            if(ne_broji[j]==1){brojac++;continue;}
            
            if(da_li_su_isti(niz_pok_otvoreno[i],niz_pok_zatvoreno[j])){
                int prvi=i,drugi=0;
                
                while(niz_pok_otvoreno[i]!=pok[prvi])prvi++;
                drugi=prvi+1;
                while(niz_pok_zatvoreno[j]!=pok[drugi])drugi++;
                if((drugi-prvi)%2==0)return 0;
                
                ne_broji[j]=1;
                break;
            }
            brojac++;
        }
        if(brojac==brojac2)return 0;
    }
    return 1;
}









int main() {
	char tekst[200]="<div id=\"tekst\"><h2>Naslov</h2><p>Ovo je <b>cetvrti</b> i <i>posljednji</i> zadatak iz <a href=\"zadaca4\">zadace 4</a></p></div>";
	printf("%d",provjeri(tekst));
	
	return 0;
	

}



