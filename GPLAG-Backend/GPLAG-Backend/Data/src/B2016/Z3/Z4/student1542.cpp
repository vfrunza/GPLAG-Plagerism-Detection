/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <stdexcept>
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v,int br_tim) {
    if(br_tim<1 || br_tim>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    std::list<std::string>pom_lista;
    std::list<std::string>::iterator it;
    std::vector<std::string> razvrstani;
    for(int i=0;i<v.size();i++) {
        lista.push_back(v[i]);
    }
    int n=lista.size();
    int k=br_tim;
    int a=n%k;
    int b=n/k;
    std::vector<int>pomocni;
    if(a!=0) {
        for(int i=0;i<a;i++) {
            pomocni.push_back(b+1);
        }
    }
    int c=k-a;
    if(a==0) {
        for(int i=0;i<c;i++)  pomocni.push_back(b);
    }
    else {
        for(int i=0;i<c;i++) pomocni.push_back(b);
        
    }

    it=lista.begin();
    int br_slova(0);
    while(lista.size()!=0) {
        std::string ime=*it;
        br_slova=0;
        razvrstani.push_back(*it);
        for(int i=0;i<ime.size();i++) {
            if((ime[i]>='a' && ime[i]<='z')||(ime[i]>='A' && ime[i]<='Z') || (ime[i]>='0' && ime[i]<='9')) br_slova++;
        }
        it=lista.erase(it);
        if(it==lista.end()) it=lista.begin();
        for(int i=0;i<br_slova-1;i++) {
                it++;
                if(it==lista.end()) it=lista.begin();
        }
    }
    std::vector<std::set<std::string>> krajnji;
    int br=0;
    for(int i=0;i<pomocni.size();i++) {
        std::set<std::string> skup;
        for(int j=0;j<pomocni[i];j++) {
            skup.insert(razvrstani[br]);
            br++;
        }
        krajnji.push_back(skup);
    }
    return krajnji; 
}
int main ()
{
    int br_djece,br_tim;
    std::cout<<"Unesite broj djece: ";
    std::cin>>br_djece;
    std::cin.ignore(10000,'\n');
    std::cout<<"Unesite imena djece: \n";
    std::vector<std::string> v;
    for(int i=0;i<br_djece;i++) {
        std::string s;
        std::getline(std::cin,s);
        v.push_back(s);
    }
    std::cout<<"Unesite broj timova: ";
    std::cin>>br_tim;
    std::vector<std::set<std::string>> vektor ;
    try {
        vektor=Razvrstavanje(v,br_tim);
        for(int i=0;i<vektor.size();i++) {
            int brojac(1);
            std::cout<<"Tim "<<i+1<<": ";
            std::set<std::string> skup=vektor[i];
            for(auto x:skup) {
                if(brojac<skup.size()) {
                    std::cout<<x<<", ";
                    brojac++;
                }
                else std::cout<<x;
            }
            std::cout<<std::endl;
        }
    }
    catch (std::logic_error poruka) {
        std::cout<<"Izuzetak: "<<poruka.what();
    }
    
	return 0;
}
