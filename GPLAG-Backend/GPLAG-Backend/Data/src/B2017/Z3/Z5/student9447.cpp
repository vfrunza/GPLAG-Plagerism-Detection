/B2017/2018: Zadaća 3, Zadatak 5
/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <queue>
#include <stdexcept>


enum class Boje {Pik, Tref, Herc, Karo};

struct Karta{
    Boje boja;
    std::string vrijednost;
};
struct Cvor{
    Karta karta;
    Cvor *sljedeci;
};

typedef std::list<std::pair<Boje,std::string>> SpilLista;
typedef std::queue<std::pair<Boje,std::string>> SpilRed;

Cvor *KreirajSpil (){
    Cvor<Karta> *pocetak(nullptr),*prethodni;
    for (int i(0);i<4;i++){
        for (int k(2);k<=14;k++){
            std::string j;
            if(k<=10) j=std::to_string(k);
            else if (k==11) j="J";
            else if (k==12) j="Q";
            else if (k==13) j="K";
            else if (k==14) j="A";
            
            if (i==0) Spil.push_back(std::make_pair(Boje::Pik,j));
            else if (i==1) Spil.push_back(std::make_pair(Boje::Tref,j));
            else if (i==2) Spil.push_back(std::make_pair(Boje::Herc,j));
            else if (i==3) Spil.push_back(std::make_pair(Boje::Karo,j));
        }
    }
   /* SpilLista Spil;
    for (int i(0);i<4;i++){
        for (int k(2);k<=14;k++){
            std::string j;
            if(k<=10) j=std::to_string(k);
            else if (k==11) j="J";
            else if (k==12) j="Q";
            else if (k==13) j="K";
            else if (k==14) j="A";
            
            if (i==0) Spil.push_back(std::make_pair(Boje::Pik,j));
            else if (i==1) Spil.push_back(std::make_pair(Boje::Tref,j));
            else if (i==2) Spil.push_back(std::make_pair(Boje::Herc,j));
            else if (i==3) Spil.push_back(std::make_pair(Boje::Karo,j));
        }
    }*/
    return Spil;
}
void IzbaciKarte (SpilLista &Karte, std::multimap<Boje,std::string> &KarteKojeSeIzbacuju){
 
    for (auto i=Karte.begin();i!=Karte.end();i++){
         for (auto k=KarteKojeSeIzbacuju.begin();k!=KarteKojeSeIzbacuju.end();k++){
            if (i->first==k->first && i->second==k->second){
                Karte.erase(i);
            }
        }   
    }
}
SpilRed IzbaciKarteRazbrajanjem (SpilLista &Karte, const short int &r, const int &b){ //r korak razbrajanja b broj karata koje treba izbaciti
    if (r<1 || r>52 || b<1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    SpilRed NoviSpil;
   
    int i(1),j(0),br(1);
    auto it=Karte.begin();
    
    while (true){
        if (i==r){
           br--;
            NoviSpil.push(std::pair<Boje,std::string> (it->first,it->second));
            it=Karte.erase(it);
            it--;
            i=0;
            j++;
        }
        i++;
        if (br==Karte.size()) {
            it=Karte.begin();
            br=1;
            continue;
        }
        br++;
        it++;
        if(j==b) break;
    }
    return NoviSpil;
}
int DajInt(std::pair<Boje,std::string> a){
    if (a.second=="2") return 2;
    else if (a.second=="3") return 3;
    else if (a.second=="4") return 4;
    else if (a.second=="5") return 5;
    else if (a.second=="6") return 6;
    else if (a.second=="7") return 7;
    else if (a.second=="8") return 8;
    else if (a.second=="9") return 9;
    else if (a.second=="10") return 10;
    else if (a.second=="J") return 11;
    else if (a.second=="Q") return 12;
    else if (a.second=="K") return 13;
    return 14;
}
void VratiPrvihNKarata (SpilLista &Karte, SpilRed &novekarte, int n){
    SpilRed karte;
    if (n<0 || n>52) throw std::domain_error ("Broj n je besmislen!");
    if (n>novekarte.size()) throw std::range_error ("Nedovoljno karata u redu!");
    if (Karte.size()>52) throw std::logic_error ("Neispravna lista!");
    int x,y;
   // auto it=Karte.begin();
    /*if (Karte.size()==0){
        int br(0);
        while(!novekarte.empty()){
            std::pair<Boje,std::string> a(novekarte.front());
            novekarte.pop();
            Karte.push_back(a);
     //       Karte.insert(it,a);
            br++;
            //it++;
            if(br==n)break;
        }
        return;
    }*/
     
    for(int i(0);i<n;i++){
        std::pair<Boje,std::string> a(novekarte.front());
        
        if (!(a.first!=Boje::Pik || a.first!=Boje::Tref || a.first!=Boje::Herc || a.first!=Boje::Karo || 
        a.second!="1"|| a.second!="2"|| a.second!="3"|| a.second!="4"
        || a.second!="5"|| a.second!="6"|| a.second!="7"|| a.second!="8"||
        a.second!="9"|| a.second!="10"|| a.second!="J"|| a.second!="Q" || a.second!="K" || a.second!="A")) throw std::logic_error ("Neispravne karte!");
        
        x=DajInt(a);
        novekarte.pop();
        for(auto it=Karte.begin();it!=Karte.end();it++){
            std::pair <Boje,std::string> b(std::make_pair(it->first,it->second));
            y=DajInt(b);
            if (a.first==it->first && x==y-1) {
                Karte.insert(it,a);
                break;
            }
            else if (a.first==it->first && x==14 && y==13){
                Karte.insert(++it,a);
                break;
            }
        }
    }
}

int main ()
{
    SpilLista spil (KreirajSpil());
    SpilRed spil1;
    int n,x,x1;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> n;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> x;
    try{
        spil1=IzbaciKarteRazbrajanjem(spil, n, x);
    }
    catch (std::logic_error err){
        std::cout << "Izuzetak: " << err.what() << std::endl;
        return 0;
    }
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to: " << std::endl;

    for (auto it=spil.begin();it!=spil.end();it++){
        std::cout << "Pik: ";
        while(it->first==Boje::Pik){
            std::cout << it->second << " ";
            it++;
        }
        std::cout << std::endl;
        std::cout << "Tref: ";
        while(it->first==Boje::Tref){
            std::cout << it->second << " ";
            it++;
        }
        std::cout << std::endl;
        std::cout << "Herc: ";
        while(it->first==Boje::Herc){
            std::cout << it->second << " ";
            it++;
        }
        std::cout << std::endl;
        std::cout << "Karo: ";
        while(it->first==Boje::Karo){
            std::cout << it->second << " ";
            it++;
            if (it==spil.end())break;
        }
        if (it==spil.end())break;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
    std::cin >> x1;
    try{
        VratiPrvihNKarata (spil,spil1,x1);
    }
    catch (std::range_error err){
        std::cout << "Izuzetak: " << err.what() << std::endl;
        return 0;
    }
    catch (std::logic_error err){
        std::cout << "Izuzetak: " << err.what() << std::endl;
        return 0;
    }
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to: " << std::endl;
    
    for (auto it=spil.begin();it!=spil.end();it++){
        std::cout << "Pik: ";
        while(it->first==Boje::Pik){
            std::cout << it->second << " ";
            it++;
        }
        std::cout << std::endl;
        std::cout << "Tref: ";
        while(it->first==Boje::Tref){
            std::cout << it->second << " ";
            it++;
        }
        std::cout << std::endl;
        std::cout << "Herc: ";
        while(it->first==Boje::Herc){
            std::cout << it->second << " ";
            it++;
        }
        std::cout << std::endl;
        std::cout << "Karo: ";
        while(it->first==Boje::Karo){
            std::cout << it->second << " ";
            it++;
            if (it==spil.end())break;
        }
        if (it==spil.end())break;
        std::cout << std::endl;
    }
	return 0;
}
