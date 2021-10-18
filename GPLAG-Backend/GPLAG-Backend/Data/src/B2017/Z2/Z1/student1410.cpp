#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cin;
using std::string;
using std::cout;
enum class Komande{PomjeriJednoMjesto, PomjeriDalje, Blokiraj,Deblokiraj,PrikaziOkolinu,ZavrsiIgru,KreirajIgru };
enum class Smjerovi{GoreLijevo,Desno,DoljeDesno,Gore,GoreDesno,Dolje,DoljeLijevo,Lijevo};
 enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class KodoviGresaka { PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar};
 typedef vector<vector<Polje>> Tabla;
void PrijaviGresku(KodoviGresaka kod){
    if(kod==KodoviGresaka::PogresnaKomanda) cout<<"Nerazumljiva komanda!";
}
//5 pogresna komanda 6 suvisan parametar
string Brisi(string &str){
    str.erase(std::remove(str.begin(),str.end(),' '),str.end()); return str;}
int ProvjeraP(string &str){ 
    //if(str.length()<4) return false;
            if(str.at(0)!='P'|| str.at(1)!='>')return 5;
    for(int i=2;i<str.length();i++){  if(!(str[i]>='0' && str[i]<='9') || str[i]!=' ' || str[i]!='\n' )return 6;}
    return 1;}
int ProvjeraB(string &str){ 
    //if(str.length()<3) return false;
     if(str.at(0)!='B')return 5;
    for(int i=1;i<str.length();i++){  if(!(str[i]>='0' && str[i]<='9') || str[i]!=' ' || str[i]!='\n' )return 6;} 
    return 1;}
int ProvjeraD(string &str){
   // if(str.length()<3) return false;
    if(str.at(0)!='D')return 5;
    for(int i=1;i<str.length();i++){  if(!(str[i]>='0' && str[i]<='9') || str[i]!=' ' || str[i]!='\n' )return 6;}
    return 1;}
int UpisiBroj(string kopija,int &x,int &y){
     int brojac(0);
     for(int i=0;i<kopija.length();i++) {
         if (kopija[i] >= '0' && kopija[i] <= '9') {
             brojac++;
             int broj(0);
            while (kopija[i] >= '0' && kopija[i] <= '9') {
                broj = broj * 10 + kopija[i] - '0';
                i++;}
            if(brojac==1) x=broj;
            else y=broj;
} while(i<kopija.length() && kopija[i]>='0' && kopija[i]<='9') i++; 
} //ako nema parametara vraca 2
 if(brojac<=1) return 2;    else return 1;}
//OCISTIT SPREMNIK NA KRAJU
//ako dodje do vracanja return true brojac++ tako cemo biti sigurni da se fakat k unijelo prvi put i da se tek tad treba vratiti true
 bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska){
    static int brojac_unosa(0);
    string kom;
    std::getline(cin,kom); string kopija(kom);Brisi(kom); 
    if(kom!="K" &&brojac_unosa==0)return false;
      if(kom!="K" && kom!="P1GL" && kom!="P1G" && kom!="P1GD" && kom!="P1D" && kom!="P1DoD" && kom!="P1Do" && kom!="DoL" && kom!="L"&&kom!="Z" &&kom!="PO" &&kom!="K"&& (ProvjeraB(kom)==5&&ProvjeraD(kom)==5&&ProvjeraP(kom)==5))
{greska=KodoviGresaka::PogresnaKomanda; PrijaviGresku(greska);
return false;}
else if(ProvjeraB(kom)==6 || ProvjeraD(kom)==6 || ProvjeraP(kom)==6){greska=KodoviGresaka::SuvisanParametar;return false;}
else if(UpisiBroj(kopija,x,y)==2){greska=KodoviGresaka::NedostajeParmetar; return false;}
    else{
    if(kom=="K" && brojac_unosa==0) {brojac_unosa++; komanda=Komande::KreirajIgru;return true;}
else if(kom=="P1GL" && brojac_unosa!=0){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::GoreLijevo;return true;}
 else if (kom=="P1G" && brojac_unosa!=0){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::Gore;return true;}
else if(kom=="P1GD"&&brojac_unosa!=0){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::GoreDesno;return true;}
else if(kom=="P1D" &&brojac_unosa!=0){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::Desno;return true;}
else if(kom=="P1DoD" && brojac_unosa!=0){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::DoljeDesno;return true;}
else if(kom=="P1Do"&&brojac_unosa!=0){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::Dolje;return true;}
else if(kom=="P1DoL"&&brojac_unosa!=0){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::DoljeLijevo;return true;}
 else if(kom=="L"&&brojac_unosa!=0){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::Lijevo;return true;}
else if(ProvjeraP(kom) &&brojac_unosa!=0 && UpisiBroj(kopija,x,y)==1){komanda=Komande::PomjeriDalje;UpisiBroj(kopija,x,y);return true;}
else if(ProvjeraB(kom)&&brojac_unosa!=0 && UpisiBroj(kopija,x,y)==1){komanda=Komande::Blokiraj;UpisiBroj(kopija,x,y);return true;}
else if(ProvjeraD(kom)&&brojac_unosa!=0 && UpisiBroj(kopija,x,y)==1){komanda=Komande::Deblokiraj;UpisiBroj(kopija,x,y);return true;}
else if(kom=="PO" &&brojac_unosa!=0){komanda=Komande::PrikaziOkolinu;return true;}  
else if(kom=="Z" &&brojac_unosa!=0){komanda=Komande::ZavrsiIgru;return true;}
else if(kom=="K" &&brojac_unosa!=0){komanda=Komande::KreirajIgru;return true;}}
cin.ignore(100,'\n');
  }
int main ()
{
    
    
	return 0;
}