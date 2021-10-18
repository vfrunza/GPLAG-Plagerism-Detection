#include <iostream>
#include <string>
#include <vector>
//uzimamo 1 po 1 string iz spiska fraza iz vektora, radimo dok ima rijeci u spisku fraza
std::string ObrniFraze(std::string recenica,std::vector<std::string>fraze){
    std::string pomocni;
    std::string p1;
    int h(0),n,p(0);
    int c;
    c=fraze.size();
    while(c>0){
        pomocni=fraze[h];
        n=pomocni.size();
               for(int i=0; i<recenica.size(); i++){
                   if(i==(recenica.size()-1) && recenica[i]=='.'){p++;}
                   if(pomocni[p]==recenica[i] && pomocni[p+1]==recenica[i+1] && p<n) {p++;}
                   else if(p==n-1 && recenica[i+1]==' ') p++;
                   else if(p==n-1 && recenica[i+1]!=' ') p=0;
                   else if(pomocni[pomocni.size()-1]==' '){
                       pomocni.erase(pomocni.begin()+ (pomocni.size()-1));
                       n--;
                   }
                   if(p==n){
                       for(int j=i; j>i-p; j--){
                           if(j>=i-p+1){
                               //ubacuje prvo slovo, da ga sacuva u pomocni1
                               p1.push_back(recenica[j]);
                               recenica[j]=recenica[i-p+1];
                               recenica[i-p+1]=p1[0];
                               p1.erase(p1.begin()+0);
                               p--;
                           }
                       }
                       p=0;

                   }
               } 
                            while(n>0){
                            int a(0);
                            pomocni.erase(pomocni.begin()+a);
                            a++;
                            n--;
    }    
                h++;
                c--;
    }
    return recenica;
}
//Ukoliko se kao drugi parametar funkciji pošalje prazan vektor, onda ona treba izmijeniti sve
//riječi u rečenici.
std::string  IzmijeniUPigLatin(std::string recenica, std::vector<std::string>fraze){
    std::string pomocni;
    std::string pomocni1;
    int h(0),n,p(0);
    int c;
    if(fraze.size()==0){ //brojac slova treba
        int rijec(0),brojac_slova(0);
        int razmak(0);
        for(int i=0; i<recenica.size(); i++){
            //za zadnju riječ u recenici se to odnosi
            if(i==(recenica.size()-1) && razmak==1){
                bool zadnje_slovo;
                zadnje_slovo=false;
                pomocni1.push_back(recenica[i-brojac_slova]);
                for(int j=i-brojac_slova; j<=i; j++){
                    if(j==i){
                            recenica[j]=pomocni1[0];
                            zadnje_slovo = true;
                        }else recenica[j]=recenica[j+1];
                    }
                //okrene rijec, sada treba dodati ay i prosiriti velicinu
                if(zadnje_slovo){
                       recenica.resize(recenica.size()+2);
                       //dodavanje ay na rijec
                       for(int p=i+1; p<i+3; p++){
                          if(p==i+1) recenica[p]='a';
                          else recenica[p]='y';
                       }
                   }
                
                pomocni1.erase(pomocni1.begin()+ 0);
                brojac_slova=0;
                razmak=0;
                i++;   
            }else if((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z')){ 
                razmak=1;
                brojac_slova++;
            }
            else if(razmak==1) {
              //nadjena rijec 
              bool zadnje_slovo;
              zadnje_slovo=false;
              pomocni1.push_back(recenica[i-brojac_slova]);
                for(int j=i-brojac_slova; j<i; j++){
                    if(j==i-1){
                            recenica[j]=pomocni1[0];
                            zadnje_slovo = true;
                        }
                        else recenica[j]=recenica[j+1];
                    }
                //okrene rijec, sada treba dodati ay i prosiriti velicinu
                if(zadnje_slovo){
                       recenica.resize(recenica.size()+2);
                       //k postavljam na zadnje slovo u prosirenoj recenici
                       //prosirim rijec sa dva razmaka
                       for(int k=recenica.size()-3; k>=i; k--){
                           recenica[k+2]=recenica[k];
                       }
                       //dodavanje ay na rijec
                       for(int p=i; p<i+2; p++){
                          if(p==i) recenica[p]='a';
                          else recenica[p]='y';
                       }
                   }
                
                pomocni1.erase(pomocni1.begin()+ 0);
                brojac_slova=0;
                razmak=0;
                i++;
            }
        
        }
        return recenica;
        
    }else{
    //c postaje velicina fraze
    c=fraze.size();
    while(c>0){
        //u pomocni stavljam  frazu po frazu
        pomocni=fraze[h];
        n=pomocni.size();
               for(int i=0; i<recenica.size(); i++){
                   //prvi if radi do zadnjeg slova
                   if(pomocni[p]==recenica[i] && pomocni[p+1]==recenica[i+1] && p<n) {p++;}
                   //provjerava da li je razmak iza te rijeci u recenici, ako jeste onda je to ta fraza
                   else if(p==n-1 && recenica[i+1]==' ') p++;
                   else if(p==n-1 && recenica[i+1]!=' ') p=0;
                   //brise razmake, ako ih je korisnih unio na kraj rijeci
                   else if(pomocni[pomocni.size()-1]==' '){
                       pomocni.erase(pomocni.begin()+ (pomocni.size()-1));
                       n--;
                   }
                   //ako je broj jednakih slova jednak velicini fraze
                   bool zadnje_slovo;
                   zadnje_slovo=false;
                   if(p==n){
                     pomocni1.push_back(recenica[i-p+1]);
                    //prebacuje prvo slovo na kraj
                    for(int j=i-p+1; j<i+1; j++){
                        if(j==i){
                            recenica[j]=pomocni1[0];
                            zadnje_slovo = true;
                        }
                        else recenica[j]=recenica[j+1];
                    }
                        pomocni1.erase(pomocni1.begin()+ 0);
                        p=0;
                   }
                   //prethodno if je stavilo prvo slovo na kraj
                   if(zadnje_slovo){
                       recenica.resize(recenica.size()+2);
                       //k postavljam na zadnje slovo u prosirenoj recenici
                       //prosirim rijec sa dva razmaka
                       for(int k=recenica.size()-3; k>i; k--){
                           recenica[k+2]=recenica[k];
                       }
                       //dodavanje ay na rijec
                       for(int p=i+1; p<i+3; p++){
                          if(p==i+1) recenica[p]='a';
                          else recenica[p]='y';
                       }
                   }
               }
                while(n>0){
                 int a(0);
                 pomocni.erase(pomocni.begin()+a);
                 a++;
                 n--;
            }
            h++;
            c--;
        }
            return recenica;
    }
}
int main (){
    std::string recenica;
        std::cout<<"Unesite recenicu: ";
        std::getline(std::cin,recenica);
        std::cout<<"Unesite fraze: ";
    std::vector<std::string>fraze;
        while(1){
            std::string rijeci;
            if(std::cin.peek()=='\n') break;
            std::getline(std::cin,rijeci);
            fraze.push_back(rijeci);
        }
    std::string PigLatin;
    std::cout<<"Recenica nakon PigLatin transformacije: ";
    PigLatin = IzmijeniUPigLatin(recenica,fraze);
    for(int i=0; i<PigLatin.size(); i++){
        std::cout<<PigLatin[i];
    }
    std::cout<<std::endl;
    std::cout<<"Recenica nakon obrtanja fraza: ";
    std::string povratni;
    povratni = ObrniFraze(recenica,fraze);
    for(int i=0; i<povratni.size(); i++){
        std::cout<<povratni[i];
    }
	return 0;
}




 