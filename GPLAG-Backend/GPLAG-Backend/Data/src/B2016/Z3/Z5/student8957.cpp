/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <set>
#include <vector>
#include <stdexcept>

int BrojKoraka (std::string s){
    int broj(0);
    for (int i=0;i<s.length();i++){
        if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            broj++;
    }
    return broj;
}
struct Dijete{
    std::string ime;
    Dijete *sljedeci;
}
std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v, int n){
    std::vector<std::set<std::string>> konacni;
    std::set<std::string> skup;
    Dijete *pocetak(nullptr),*prethodni;
    for (int i=0;i<v.size();i++){
        Dijete *novi(new Dijete);
        novi->ime=v[i];novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    
    
}

int main ()
{
    int d;
    std::cout<<"Unesite broj djece: ";
    std::cin>>d;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
    std::vector<std::string>v;
    std::string pomocni;
    std::cout<<"Unesite imena djece: "<<std::endl;
    for (int i=0;i<d;i++){
        std::getline(std::cin,pomocni);
        v.push_back(pomocni);
    }
    int t;
    
    std::cout<<"Unesite broj timova: ";
    std::cin>>t;
    try{
        std::vector<std::set<std::string>>vektor(Razvrstavanje(v,t));
        int brojac(0);
        for (int i=0;i<vektor.size();i++){
            std::cout<<"Tim "<<i+1<<": ";
            brojac=0;
            for (std::string x : vektor[i]){
                if (brojac==0){
                    std::cout<<x;
                    brojac++;
                }
                else 
                    std::cout<<", "<<x;
            }
            std::cout<<std::endl;
        }
    }
    catch (std::logic_error izuzetak){
        std::cout<<izuzetak.what();
    }
	return 0;
}