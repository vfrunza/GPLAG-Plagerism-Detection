/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <iterator>
#include <stdexcept>

std::vector<std::set<std::string>>Razvrstavanje(std::vector<std::string>djeca1,int br_timova){
    std::list<std::string>lista;
    int br_djece(0);
    for(int i=0;i<djeca1.size();i++){
        lista.push_back(djeca1[i]);
        br_djece++;
    }
    if(br_timova<1 || br_timova>br_djece)throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    std::list<std::string> lista1;
    std::list<std::string>::iterator it(lista.begin());
    while(!lista.empty()){
        std::string ime(*it);
        int a(0);
        for(int i=0;i<ime.length();i++){
            if((ime[i]>='a' && ime[i]<='z') || (ime[i]>='A' && ime[i]<='Z') || (ime[i]>='0' && ime[i]<='9'))
            a++;
        }lista1.push_back(ime);
        it=lista.erase(it);
        if(it==lista.end()){
            it=lista.begin();
        }for(int i=1;i<a;i++){
            if(it!=lista.end()){
                it++;
                if(it==lista.end()){
                    it=lista.begin();
                }
            }else if(it==lista.end()){
                it=lista.begin();
            }
        }
        
    }
    std::list<std::string>::iterator it1(lista1.begin());
    std::vector<std::set<std::string>>v;
    for(int i=0;i<br_djece%br_timova;i++){
        std::set<std::string>skup;
        for(int i=0;i<((br_djece/br_timova)+1);i++){
            skup.insert(*it1);
            it1=lista1.erase(it1);
        }
        v.push_back(skup);
    }
    for(int i=br_djece%br_timova;i<br_timova;i++){
        std::set<std::string>skup;
        for(int i=0;i<br_djece/br_timova;i++){
            skup.insert(*it1);
            it1=lista1.erase(it1);
        }
        v.push_back(skup);
    }
    return v;
}

int main ()
{
    try{
    int br_djece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>br_djece;
    std::vector<std::string> vektor;
    std::string djeca;
    std::cout<<"Unesite imena djece:\n";
    std::cin.ignore(1000,'\n');
    for(int i=0;i<br_djece;i++){
       std::getline(std::cin,djeca);
       vektor.push_back(djeca);
    }
    int br_timova;
    std::cout<<"Unesite broj timova: ";
    std::cin>>br_timova;
        
    std::vector<std::set<std::string>> vek;
    vek=Razvrstavanje(vektor,br_timova);
    std::set<std::string>pomocni1;
    for(int i=0;i<vek.size();i++){
        pomocni1=vek[i];
        std::cout<<"Tim "<<i+1<<": ";
        auto it(pomocni1.begin());
        while(it!=pomocni1.end()){
            std::cout<<*it;
            it++;
            if(it!=pomocni1.end()){
            std::cout<<", ";
            }
        }std::cout<<std::endl;
    }
    }catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what();
    }
	return 0;
}