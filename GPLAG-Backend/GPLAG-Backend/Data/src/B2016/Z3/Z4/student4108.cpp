/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>
#include <iterator>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int n){
    if(n<1 || n>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    for(int i=0;i<imena.size();i++) lista.push_back(imena[i]);             //kopiranje imena djece u listu 
    std::set<std::string> tim;
    std::vector<std::set<std::string>> timovi;
    std::list<std::string>::iterator it(lista.begin());
    int zajedanveci=(imena.size())%n;                //broj timova koji imaju za 1 clan vise
    int brclanova=imena.size()/n;                    
    int ostali=n-zajedanveci;                         //br timova koji imaju br clanova odredjen po formuli
    for(int i=0;i<zajedanveci;i++){                               //pravljenje onoliko timova koliko ih ima za jedan clan vise
        for(int k=0;k<brclanova+1;k++){                           //ubacivanje tacno brclanova+1 imena u "tim"
            std::string ime=*it;
            tim.insert(ime);
            it=lista.erase(it);                      //iterator ce pokazivati iza obrisanog
            if(it==lista.end()) it=lista.begin();
            int velicina(0);
            for(int a=0;a<ime.size();a++){                  //velicinu imena odredjuju slova i cifre...
                if((ime[a]>='A' && ime[a]<='Z') || (ime[a]>='a' && ime[a]<='z') || (ime[a]>='0' && ime[a]<='9')) velicina++;
            }
            for(int j=0;j<velicina-1;j++) {
                it++;                                     //pomjeranje iteratora za onoliko mjesta kolika je "velicina" imena umanjeno za 1 jer it vec pokazuje iza obrisanog
                if(it==lista.end()) it=lista.begin(); 
            }
            if(tim.size()==brclanova+1) {                          //ako tim ima odgovarajuci broj clanova, dodajemo ga u vektor i "cistimo", da varijablu tim mozemo koristiti i za sljedece iteracije petlje i   
                timovi.push_back(tim);
                tim.clear();
            }
        }
    }
    for(int i=0;i<ostali;i++){                                  //isti postupak i za timove koji imaju br clanova odredjen po formuli
        for(int k=0;k<brclanova;k++){
            std::string ime=*it;
            tim.insert(ime);
            it=lista.erase(it);
            if(it==lista.end()) it=lista.begin();
            int velicina(0);
            for(int a=0;a<ime.size();a++){
                if((ime[a]>='A' && ime[a]<='Z') || (ime[a]>='a' && ime[a]<='z') || (ime[a]>='0' && ime[a]<='9')) velicina++;
            }
            for(int j=0;j<velicina-1;j++){
                it++;
                if(it==lista.end()) it=lista.begin();
                
            }
            if(tim.size()==brclanova){
                timovi.push_back(tim);
                tim.clear();
            }
        }
    }
    return timovi;
}

int main ()
{   
    std::string ime;
    std::vector<std::string> v;
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::cin.ignore(1000,'\n');
    for(int i=0;i<n;i++){
        std::getline(std::cin,ime);
        v.push_back(ime);
    }
    std::cout<<"Unesite broj timova: ";
    int br;
    std::cin>>br;
    try{
        auto timovi=Razvrstavanje(v,br);
        for(int i=0;i<timovi.size();i++){
        std::cout<<"Tim "<<i+1<<": ";
            for(auto it=timovi[i].begin(); it!=timovi[i].end();it++){
                if(it==(--timovi[i].end())) std::cout<<*it;
                else std::cout<<*it<<", ";
            }
        std::cout<<std::endl;
        }
    }
    catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}