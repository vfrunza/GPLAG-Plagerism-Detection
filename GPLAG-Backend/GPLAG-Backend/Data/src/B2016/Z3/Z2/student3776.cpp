#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <utility>
#include <cctype>
#include <cstring>
typedef std::map<std::string,std::set<int> > Mapa;
void pretvori(std::string &s){
     for(auto& c : s)
{
   c = std::tolower(c);
}
}

 bool Legalno( char znak){
 	 if(  (znak>='a' && znak<='z') || (znak>='A' && znak<='Z') || (znak>='0' && znak<='9') ) {return true;}
 	 else return false;
 }
 
void UkloniDuple( std::vector<std::string> &vec)
{
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

std::vector<std::string>NadjiRijec(std::string s){
    pretvori(s);
    std::vector<std::string>Kraj;
	 std::vector<int>Kopije;
	 std::string Vrat;
     for(int i(0);i<s.length();i++){
         if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9') ){
             Kopije.push_back(i);
         }
     }
     for(int i(0);i<Kopije.size();i++){
         Vrat.push_back(s[Kopije[i]]);
         if((i+1)!=Kopije.size() and abs(Kopije[i]-Kopije[i+1])!=1) Vrat.push_back(' ');
    }
    int poc(0),duz(0);
    for(int i(0);i<Vrat.size();i++){
        if(Vrat[i]!=' ')  duz++;
         if(Vrat[i]==' ' || i==Vrat.size()-1) {Kraj.push_back(Vrat.substr(poc,duz)); poc=i+1; duz=0;}
    }
    UkloniDuple(Kraj);
return Kraj;
}
   void calc_z (std::string &s, std::vector<int> &z)
{
    int len = s.size();
    z.resize (len);

    int l = 0, r = 0;
    for (int i=1; i<len; ++i)
        if (z[i-l]+i <= r)
            z[i] = z[i-l];
        else
        {
            l = i;
            if (i > r) r = i;
            for (z[i] = r-i; r<len; ++r, ++z[i])
                if (s[r] != s[z[i]])
                    break;
            --r;
        }
}
std::set<int>NadjiIndeks(std::string s,std::string rijec){
    
    std::set<int>sk;
    std::string main_string = s;
    std::string substring = rijec;
    std::string working_string = s+rijec;
    std::vector<int> z;
    calc_z(working_string, z);
    for(int i = substring.size(); i < working_string.size(); ++i){
        if(z[i] >=substring.size()   and   rijec.size()==1 and Legalno(s[i - substring.size()-1])==false  && Legalno(s[i - substring.size()+1])==false )   sk.insert( i - substring.size() );
           if(z[i] >=substring.size()  ) {sk.insert(i-substring.size());}
    }
    return sk;
}
Mapa KreirajIndeksPojmova( std::string s){
    std::vector<std::string>Kljucevi;
     Mapa Indeksi;
     Kljucevi=NadjiRijec(s);
     for(int i(0);i<Kljucevi.size();i++){
         Indeksi.insert(std::make_pair(Kljucevi[i],NadjiIndeks(s,Kljucevi[i])));
     }
     return Indeksi;
}
std::set<int> PretraziIndeksPojmova(std::string rijec,Mapa Pojmovi){
   auto it=Pojmovi.find(rijec);  
   if( it == Pojmovi.end() ) throw std::logic_error("Pojam nije nadjen");  
   else  return  it->second;
 
}
void IspisiIndeksPojmova(Mapa Pojmovi){
    std::string k;
    for(auto it=Pojmovi.begin();it!=Pojmovi.end();it++){
         std::cout<<it->first<<": ";
        auto &zadnji = *(--(it->second).end());
        for (auto x : it->second)
{
    std::cout << x;
    if (&x != &zadnji)
        std::cout << ",";
}
        std::cout<<std::endl;
     
    }
}
bool Provjeri(std::string rijec,std::vector<std::string>rijeci){
    int brojac(0);
    for(int i(0);i<rijeci.size();i++){
        if(rijec==rijeci[i]) brojac++;
    }
    if(brojac==0) return true;
    if(brojac!=0) return false;
}

int main ()
{
    std::set<int>Indexi;
    std::string Polazni;
    Mapa Pojam=KreirajIndeksPojmova(Polazni);
    try{
        std::cout<<"Unesite tekst: ";
        std::vector<std::string>v;
        v=NadjiRijec(Polazni);
        std::getline(std::cin,Polazni);
        Mapa Pojam=KreirajIndeksPojmova(Polazni);
        IspisiIndeksPojmova(Pojam);
        for(;;){
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin,rijec);
        if(rijec==".") break ;
        Indexi=PretraziIndeksPojmova(rijec,Pojam);
        for(auto x: Indexi){
            std::cout<<x<<" ";
        }
        std::cout<<std::endl;
        }
    }
    catch(std::logic_error e){
        if(e.what()!="Unesena rijec nije nadjena!\n") {std::cout<<"Unesena rijec nije nadjena!\n";
        for(;;){
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin,rijec);
        
        if(rijec==".") break ;
        Indexi=PretraziIndeksPojmova(rijec,Pojam);
        for(auto x: Indexi){
            std::cout<<x<<" ";
        }
        std::cout<<std::endl;
        }
        }
    }
	return 0;
}