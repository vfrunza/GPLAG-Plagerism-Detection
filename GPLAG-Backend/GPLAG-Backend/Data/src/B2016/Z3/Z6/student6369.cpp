/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <set>
#include <memory>

bool IsCharOrDigit(char x) {
    return ( (x>='a' && x<='z') || (x>='A' && x<='Z') || (x>='0' && x<='9') ); 
}

struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int brojTimova) {
    if(brojTimova < 1 || brojTimova>imena.size())
        throw std::logic_error("Razvrstavanje nemoguce");
        int kolikoClanova = imena.size() / brojTimova;
        int kolikoVise = imena.size() % brojTimova;
        int kojiTim =1 ;
        std::vector<std::set<std::string>> timovi;
        int brDjece = imena.size();
        int k = 0;
        std::shared_ptr<Dijete> prvo = nullptr;
        std::shared_ptr<Dijete> zadnje = nullptr;
        std::shared_ptr<Dijete> trenutno = nullptr;
        for(int i=0;i<imena.size();i++) {
            if(!prvo) {
                prvo = std::make_shared<Dijete>();
                prvo->ime = imena[0];
                prvo->sljedeci = nullptr;
                zadnje = prvo;
                trenutno = prvo;
            }
            else {
                trenutno = prvo;
                while(trenutno->sljedeci) trenutno = trenutno->sljedeci;
                std::shared_ptr<Dijete> novo = std::make_shared<Dijete>();
                novo->ime = imena[i];
                if(i+1!=imena.size())
                    novo->sljedeci = nullptr;
                else novo ->sljedeci = prvo;
                trenutno ->sljedeci = novo;
                if(i+1 == imena.size()) zadnje = novo;
            }
        }
        trenutno = prvo;
        std::set<std::string> trenutniTim;
        
        while(brDjece>0) {
            std::string dijete = trenutno->ime;
            trenutniTim.insert(dijete);
            if( (kojiTim <= kolikoVise && trenutniTim.size()==kolikoClanova+1) ||
                (kojiTim > kolikoVise  && trenutniTim.size()==kolikoClanova  )) {
                    timovi.push_back(trenutniTim);
                    kojiTim++;
                    trenutniTim.clear();
                }
            std::shared_ptr<Dijete> prije = prvo;
            while(prije->sljedeci != trenutno)
                prije = prije->sljedeci;
            if(brDjece==1 && prvo==zadnje) {
                //delete trenutno;
                trenutno ->sljedeci = nullptr;
                trenutno = nullptr;
                prvo = nullptr;
                zadnje = nullptr;
                prije = nullptr;
                break;
            }
            else if(trenutno==zadnje) {
                prije->sljedeci= prvo;
                zadnje = prije;
                //delete trenutno;
                trenutno = zadnje;
                
            }
            else if(trenutno==prvo) {
                prvo = trenutno->sljedeci;
                zadnje->sljedeci = prvo;
                //delete trenutno;
                trenutno = zadnje;
            }
            else {
                prije ->sljedeci = trenutno ->sljedeci;
                //delete trenutno;
                trenutno = prije;
            }
            for(int i=0;i<dijete.length();i++)
                if( IsCharOrDigit(dijete[i]))
                    k++;
            for(int i=0;i<k;i++)
                trenutno = trenutno->sljedeci; 
            k=0;
            brDjece--;
        }
    return timovi;
}
int main ()
{
    std::vector<std::string> imena;
    int n;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::string x = "";
    std::cin.ignore(10000,'\n');
    for(int i=0;i<n;i++) {
        std::getline(std::cin,x);
        imena.push_back(x);
    }
    std::cout<<"Unesite broj timova: ";
    int p;
    std::cin>>p;
    auto timovi = Razvrstavanje(imena,p);
    for(int i(0);i<p;i++) {
        std::cout<<"Tim "<< i+1<<": ";
        for(auto it=timovi[i].begin();it!=timovi[i].end();it++) {
            auto tmp = it;
            tmp++;
            if(tmp==timovi[i].end())
                std::cout<<*it;
            else std::cout<<*it<<", ";
        }
        std::cout<<std::endl;
    }
	return 0;
}