/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <iterator>

int BrojRijeci(std::string rijec){
    int n(0);
    for(int i=0; i<rijec.size(); i++){
        if((rijec.at(i)>='0' && rijec.at(i)<='9') || (rijec.at(i)>='a' && rijec.at(i)<='z') || (rijec.at(i)>='A' && rijec.at(i)<='Z')) n++;
    }
    return n;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int n_timova){
    std::list<std::string> lista_imena;             //Ignore
    for(auto x: imena) lista_imena.push_back(x);    //Ini
    bool pocetak(true);                             //cija
    std::vector<std::set<std::string>> timovi;      //liza
    std::set<std::string> trenutni_tim;             //cija
    
    std::vector<int> n_igraca;
    for(int i=0; i<imena.size()%n_timova; i++) n_igraca.push_back(imena.size()/n_timova +1);            //Broj timova kalkulacija
    for(int i=imena.size()%n_timova; i<imena.size(); i++) n_igraca.push_back(imena.size()/n_timova);
    for(auto n: n_igraca) std::cout << n<< ", " ;
    std::cout << std::endl;
    int brojac(0), n;
    for(auto it=lista_imena.begin(); it!=lista_imena.end();){
        if(pocetak){
            trenutni_tim.insert(*it);
            n=BrojRijeci(*it);
            std::cout <<"poc "<< *it << std::endl;
            std::cout << n << std::endl;
            it = lista_imena.erase(it);
            pocetak = false;
            
        }
        else{
            if(trenutni_tim.size()<n_igraca.at(brojac)){
                trenutni_tim.insert(*it);
                n=BrojRijeci(*it);
                std::cout <<"normala "<< *it << std::endl;
                it = lista_imena.erase(it);
                std::cout << n << std::endl;
            }
            else {
                timovi.push_back(trenutni_tim);
                trenutni_tim.clear();
                brojac++;
                pocetak = true;
                continue;
            }
        }
        for(int i=0; i<n; i++){
            i++;
            if(it==lista_imena.end()) it = lista_imena.begin();
            if(lista_imena.empty()) it=lista_imena.end();
        }
    }
    return timovi;
}

int main ()
{
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite imena djece: "<< std::endl;
    std::vector<std::string> imena(n);
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    for(int i=0; i<n; i++){
        std::getline(std::cin, imena.at(i));
    }
    std::cout << "Unesite broj timova: ";
    std::cin >> n;
    std::vector<std::set<std::string>> razvrstano(Razvrstavanje(imena, n));
    for(int i=0; i<razvrstano.size(); i++){
        std::cout << "Tim "<< i+1 << ": ";
        for(auto it=razvrstano.at(i).begin(); it!=razvrstano.at(i).end(); it++){
            if(it == razvrstano.at(i).end()--) std::cout << std::cout << *it;
            else std::cout << *it<<", ";
        }std::cout << std::endl;
    }
	return 0;
}