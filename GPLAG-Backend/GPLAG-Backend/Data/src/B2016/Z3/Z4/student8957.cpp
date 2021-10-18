/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

int BrojKoraka (std::string s){
    int broj(0);
    for (int i=0;i<s.length();i++){
        if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            broj++;
    }
    return broj;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v, int n){
    if (n<1 || n>v.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    int ostatak(int(v.size())%n);
    std::list<std::string> l;
    std::vector<std::set<std::string>> konacni;
    for (int i=0;i<v.size();i++){
        l.push_back(v[i]);
    }
    int broj,temp(0),brojjednogtima;
    auto it=l.begin();
    for (int i=0; i<n; i++){
        if (ostatak>0){
            brojjednogtima=(int(v.size())/n)+1;
            ostatak--;
        }
        else 
            brojjednogtima=(int(v.size())/n);
        
        std::set<std::string>skup;
        
        for (int j=0;j<brojjednogtima;j++){
            skup.insert(*it);
            broj=BrojKoraka(*it);
            it=l.erase(it);
            temp=1;
            if (it==l.end())it=l.begin();
            while (temp<broj){
                it++;
                temp++;
                if (it==l.end())it=l.begin();
            }
        }
        konacni.push_back(skup);
    }
    return konacni;
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
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    
	return 0;
}