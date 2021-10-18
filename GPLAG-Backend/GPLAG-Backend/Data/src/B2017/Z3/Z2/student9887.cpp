/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <tuple>
/*Prvo ćete napraviti funkciju “KreirajIndeksPojmova” koja kao 
parametar prima neki objekat tipa “Knjiga”, koji predstavlja tekst
koji se analizira. Funkcija kao rezultat treba vratiti mapu koja predstavlja traženi indeks pojmova.
Ključna polja ove mape su tipa “string”, a pridružene vrijednosti su skupovi čiji su elementi uređene trojke
(tipa “tuple”), čija je prva koordinata tipa “string”, a druga i treća su cijeli brojevi. 
Vrijednosti ključnih polja predstavljaju različite riječi pronađene u analiziranom tekstu, 
dok su odgovarajuće pridružene vrijednosti skupovi čiji elementi opisuju pozicije na kojima
se odgovarajuća riječ nalazi unutar razmatranog teksta. Svaka pozicija opisana je kao uređena trojka,
pri čemu prva koordinata predstavlja oznaku poglavlja, druga koordinata redni broj stranice (uz numeraciju koja počinje od jedinice, a ne od nule)
, dok treća koordinata predstavlja poziciju razmatrane riječi unutar stranice (tj. indeks od kojeg počinje riječ).*/
typedef std::map<std::string ,std::vector<std::string>> Knjiga;
struct PolozajiIRijeci{
    std::vector<std::string> rijeci;
    std::vector<std::vector<int>> indeksi;
};
bool Ponavljanja(std::vector<std::string> s, std::string rijec){
    for(int i=0;i<s.size();i++){
    if(s.at(i)==rijec){
    return true;}}
    return false;
}
PolozajiIRijeci  Vrati_Rijeci_I_Indekse(std::string sadrzaj_stranice){
    
    PolozajiIRijeci rezultat;
    bool razmak=true;
    std::string cuva;
int cuva_indeks(0);
    int i(0);
    int po_redu_rijec(0);
    while(i<sadrzaj_stranice.length()) {
        if(sadrzaj_stranice[i]==' ')
            razmak=true;
        else if(razmak) {
            razmak=false;
        cuva_indeks=i;
                rezultat.indeksi[po_redu_rijec].push_back(i);
            while(sadrzaj_stranice[i]!=' '&& i<sadrzaj_stranice.length()) {
                
                cuva.push_back(sadrzaj_stranice[i]);
                
                i++;
            }
            if(!Ponavljanja(rezultat.rijeci, cuva)){
                rezultat.rijeci.push_back(cuva);
                
            
            int pocetak(0);
            for(int j=i;j<sadrzaj_stranice.length();j++){
                while(cuva_indeks!=-1){
                cuva_indeks=sadrzaj_stranice.find(cuva, pocetak);
                pocetak=cuva_indeks+1;
                if(cuva_indeks!=-1)
                rezultat.indeksi[po_redu_rijec].push_back(cuva_indeks);
            }
}
            po_redu_rijec++;
}
        }
        i++;

    }
    return rezultat;

}
std::map<std::string , std::set<std::tuple<std::string, int, int>>>KreirajIndeksPojmova(Knjiga tekst){
   std::map<std::string , std::set<std::tuple<std::string, int, int>>> rezultat;
   int broj_stranica=tekst.size();
   for(auto it=tekst.begin() ;it!=tekst.end();it++){
       for(int i=0;i<broj_stranica;i++){
          PolozajiIRijeci jedna_stranica;
          jedna_stranica=Vrati_Rijeci_I_Indekse(tekst[it->first][i]);
          std::cout<<
       }
   }
}
int main ()
{
	return 0;
}
