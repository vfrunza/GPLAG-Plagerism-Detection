#include <stdio.h>


char *ubaci_broj(char *tekst,int broj){
    char *str=tekst,brojStr[10];
    int tmp=broj,counter,brojacCifri=0,negativan=0,niz[10];
    int i=0,umetac;
    char *pokNaBroj=brojStr,*pNaBroj=brojStr,*izaKraja,*kraj,*spejser,*provjeraRikverca;
    if(tmp<0){negativan=1;tmp*=-1;}
    while(tmp!=0){
        brojacCifri++;
        niz[i]=tmp%10;
        tmp/=10;
        i++;
    }
    i=brojacCifri-1;
    if(negativan){
        *pokNaBroj='-';
        pokNaBroj++;
        while(i>=0){
            *pokNaBroj=niz[i]+'0';
            pokNaBroj++;
            i--;
        }
        *pokNaBroj='\0';
    }else{
        while(i>=0){
            *pokNaBroj=niz[i]+'0';
            pokNaBroj++;
            i--;
        }
        *pokNaBroj='\0';
    }
    pokNaBroj=pNaBroj;
    while(*str!='\0'){
        if(*str==' '){
            spejser=str;
            counter=0;
            while(*spejser==' '){spejser++;counter++;}
            provjeraRikverca=spejser-1;
            if(provjeraRikverca==tekst){str=spejser;continue;}
            while(*provjeraRikverca==' ' && provjeraRikverca!=tekst)provjeraRikverca--;
            if(provjeraRikverca==tekst && *tekst==' '){str=spejser;continue;}
            if(*spejser=='\0')break;
            if(counter==1){
                    //brojacCifri+1+1
                    kraj=spejser;
                    izaKraja=spejser;
                    while(*kraj!='\0')kraj++;
                    while(*izaKraja!='\0')izaKraja++;
                    if(negativan)izaKraja+=brojacCifri+2;
                    else izaKraja+=brojacCifri+1;
                    while(kraj!=spejser){
                        *izaKraja=*kraj;
                        kraj--;
                        izaKraja--;
                    }
                    *izaKraja=*kraj;
                    str++;
                    pokNaBroj=pNaBroj;
                    while(*pokNaBroj!='\0'){
                        *str=*pokNaBroj;
                        str++;
                        pokNaBroj++;
                    }
                    *str=' ';
            }else if(counter>1){
                     //brojacCifri+counter-1
                    kraj=spejser;
                    izaKraja=spejser;
                    while(*kraj!='\0')kraj++;
                    while(*izaKraja!='\0')izaKraja++;
                    if(negativan)izaKraja+=brojacCifri+counter;
                    else izaKraja+=brojacCifri+counter-1;
                    spejser=str+1;
                    while(kraj!=spejser){
                        *izaKraja=*kraj;
                        kraj--;
                        izaKraja--;
                    }
                    *izaKraja=*kraj;
                    str++;
                    pokNaBroj=pNaBroj;
                    while(*pokNaBroj!='\0'){
                        *str=*pokNaBroj;
                        str++;
                        pokNaBroj++;
                    }
                    umetac=0;
                    while(str!=izaKraja){
                        *str=' ';
                        str++;
                    }
                    str++;
            }
        }
        str++;   
    }
    return tekst;
}

int main(){
char s[77] = "Ovdje  izmedju    rijeci ima      po nekoliko   razmaka";
printf("\"%s\"", ubaci_broj(s, 320));
    return 0;	
}
