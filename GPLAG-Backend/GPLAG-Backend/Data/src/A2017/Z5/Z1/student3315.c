#include <stdio.h>
#include <string.h>
#include <math.h>

struct Datum{
    int dan;
    int mjesec;
    int godina;
};

struct Uposlenik{
    char ime_prezime[50];
    struct Datum datum_rodjenja;
};

int provjera_prezimena(char s1[],char s2[]){
    
           char *prezime1;
           char *prezime2;
           char *prezime11;
           char *prezime22;
       while(*s1!='\0'){
           
           
           if(*s1==' '){
               prezime1=s1+1;
               prezime11=s1+1;
               
           }
          
          if(*s1=='-') prezime11=s1+1;
          s1++;
 
       }
       while(*s2!='\0'){ 
          if(*s2==' '){ 
             prezime2=s2+1;
             prezime22=s2+1;
          }
          if(*s2=='-') prezime22=s2+1;
          s2++;
       }
      char *pok=prezime1;
      int brojac1=0,brojac11=0,brojac2=0, brojac22=0;
      while(*pok!=' ' && *pok!='-' && *pok!='\0'){brojac1++;pok++;}
      pok=prezime2;
      while(*pok!=' ' && *pok!='-' && *pok!='\0'){brojac2++;pok++;}
      pok=prezime22;
      while(*pok!=' ' && *pok!='-' && *pok!='\0'){brojac22++; pok++;} 
      pok=prezime11;
      while(*pok!=' ' && *pok!='-' && *pok!='\0'){brojac11++;pok++;}
      int k;
      int postoji=0;
      if(brojac1>brojac2)k=brojac1;
      else k=brojac2;
      int i=0;
      for(i=0;i<k;i++){
          if(prezime1[i]==prezime2[i]) postoji=1;
          else{postoji=0;break;}
      }
      if(postoji) return 1;
      
      if(brojac1>brojac22)k=brojac1;
      else k=brojac22;
      i=0;
      postoji=0;
      for(i=0;i<k;i++){
          if(prezime1[i]==prezime22[i]) postoji=1;
          else{postoji=0;break;}
      }
      if(postoji) return 1;
      
      if(brojac11>brojac2)k=brojac11;
      else k=brojac2;
      i=0;
      postoji=0;
      for(i=0;i<k;i++){
          if(prezime11[i]==prezime2[i]) postoji=1;
          else{postoji=0;break;}
      }
      if(postoji) return 1;
      
      if(brojac11>brojac22)k=brojac11;
      else k=brojac22;
      i=0;
      postoji=0;
      for(i=0;i<k;i++){
          if(prezime11[i]==prezime2[i]) postoji=1;
          else{postoji=0;break;}
      }
      return postoji;
}

int prestupna_godina(int godina){
    if( (godina%4==0 || godina%400==0) && (godina%100!=0) ){
        return 1;
    }
    else
    return 0;
}

int funkcija(int m,int d,int prestupna,int mjesec_direktora,int dani_direktora){
    int ukupni_dani=0;
    int razlika_mjeseci;
    int razlika_dana;
    
   if(mjesec_direktora<m){
        ukupni_dani=0;
        return ukupni_dani;
    }
    
    else if(mjesec_direktora>m){
        if(m==2 && prestupna==1 && d==1){
            ukupni_dani=29;
            return ukupni_dani;
        }
        else if(m==2 && prestupna==0 && d==1){
            ukupni_dani=28;
            return ukupni_dani;
        }
        else if(m==2 && ((prestupna==1)||(prestupna==0)) && d==dani_direktora){
            ukupni_dani=0;
            return ukupni_dani;
        }
        else if(m!=2){
            razlika_mjeseci=(mjesec_direktora-m);
            if(razlika_mjeseci>1){
                ukupni_dani=32;
                return ukupni_dani;
            }
            else if(razlika_mjeseci==1){
                if(d==dani_direktora){
                    ukupni_dani=32;
                    return ukupni_dani;
                }
                else if(d>dani_direktora){
                    if(m==1 || m==3 || m==5 || m==7 || m==8 ||m==10 || m==12){
                        ukupni_dani=32;
                        return ukupni_dani;
                    }
                    else{
                        ukupni_dani=0;
                        return ukupni_dani;
                    }
                }
                else if(d<dani_direktora){
                    ukupni_dani=32;
                    return ukupni_dani;
                }
                
                
            }
            else if(razlika_mjeseci==0){
                razlika_dana=fabs(dani_direktora-d);
                if(razlika_dana>28){
                ukupni_dani=32;
                return ukupni_dani;
            }
            
            
            
        }
    }
    
    }
}

    
    
    
    
    
int suzi_listu(struct Uposlenik kandidati[],int velicina, struct Uposlenik direktor,int broj_dana){
    int i,j;
    int prestupna_godina_kandidata;
    int prestupna_godina_direktora;
    int daj_dane1;
    int daj_dane2;
    
    
 
    for(i=0;i<velicina;i++){
        if(broj_dana>0){
        if((kandidati[i].datum_rodjenja.godina)>(direktor.datum_rodjenja.godina))
        continue;
        else if(kandidati[i].datum_rodjenja.godina<direktor.datum_rodjenja.godina){
            if((provjera_prezimena(kandidati[i].ime_prezime,direktor.ime_prezime)))
            continue;
                for(j=i;j<velicina-1;j++){
                    kandidati[j]=kandidati[j+1];
                }
                velicina--;
                i--;
        }
        else if(kandidati[i].datum_rodjenja.godina==direktor.datum_rodjenja.godina){
            
            if((provjera_prezimena(kandidati[i].ime_prezime,direktor.ime_prezime)))
            continue;
            
            if(prestupna_godina(kandidati[i].datum_rodjenja.godina)){
                int prestupna=1;
              daj_dane1=funkcija(kandidati[i].datum_rodjenja.mjesec,kandidati[i].datum_rodjenja.dan,prestupna,
              direktor.datum_rodjenja.mjesec,direktor.datum_rodjenja.dan);
                if(daj_dane1>broj_dana){
                    for(j=i;j<velicina-1;j++){
                        kandidati[j]=kandidati[j+1];
                    }
                    velicina--;
                   i--;
                }
            
                
            }
            else{
                int prestupna=0;
                if(provjera_prezimena(kandidati[i].ime_prezime,direktor.ime_prezime))
                continue;
                    daj_dane2=funkcija(kandidati[i].datum_rodjenja.mjesec,kandidati[i].datum_rodjenja.dan,prestupna,
                    direktor.datum_rodjenja.mjesec,direktor.datum_rodjenja.dan);
                    if(daj_dane2>broj_dana){
                        for(j=i;j<velicina-1;j++){
                            kandidati[j]=kandidati[j+1];
                        }
                        velicina--;
                        i--;
                    }
                    
                    
            }
            
        }
        
        
        
        
        }
        
        
        //OVAJ ELSE
        // 
    }
    
    return velicina;
}




int main() {
    /* AT12: Varijante sa dva prezimena (samo kandidati) */
struct Uposlenik direktor = {"Mujo Mujic", {3, 3, 1992} };
struct Uposlenik kandidati[7] = {
    { "Jozo Jozic-Mujic", { 1, 10, 1990 } },
};

int novi_br = suzi_listu(kandidati, 7, direktor, 3);
int i;
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);
	
	
	return 0;
}



