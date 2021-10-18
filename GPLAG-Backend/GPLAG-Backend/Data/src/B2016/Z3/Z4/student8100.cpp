/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <list>
#include <iterator>

typedef std::vector<std::string> spisak;
typedef std::vector<std::set<std::string>> skup;

void Ispisi(skup raspored){
    for(int i(0); i<raspored.size(); i++){
        std::cout << "Tim " << i+1 << ": ";
        auto it(raspored[i].begin());
        while(it != --raspored[i].end()){
            //if()
            std::cout << *it << ", ";
            it++;
        }
        std::cout << *it << std::endl;
    }
}

int BrojSlova(std::string ime){
    int brojac(0);
    //std::cout << ime << std::endl;
    for(int i(0); i<ime.length(); i++)
        if((ime[i]>='a' && ime[i]<='z') || (ime[i]>='A' && ime[i]<='Z') || (ime[i]>='0' && ime[i]<='9')) brojac++;
    return brojac-1;
}

skup Razvrstavanje(spisak imena, int br_tim){
    if(br_tim<1 || br_tim>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    skup krajnji;
    std::list<std::string> lista;
    auto it1(imena.begin());
    while(it1!=imena.end()){
        auto it2(lista.begin());
        while(it2!=lista.end()) it2++;
        lista.insert(it2, *it1);
        it1++;
    }
    auto it2=lista.begin();
    int broj(imena.size());
    int pomocni1 = broj%br_tim;
    int pomocni2 = broj/br_tim;
    int slova(0);
    while(br_tim>0){
        while(slova!=0){
            slova--;
            it2++;
            if(it2==lista.end()) it2=lista.begin();
        }
        std::set<std::string> strskup;
        strskup.insert(*it2);
        slova = BrojSlova(*it2);
        it2 = lista.erase(it2);
        if(it2==lista.end()) it2=lista.begin();
        int temp = pomocni2-1;
        if(pomocni1!=0){
            while(slova!=0){
                slova--;
                it2++;
                if(it2==lista.end()) it2=lista.begin();
            }
            strskup.insert(*it2);
            slova=BrojSlova(*it2);
            it2 = lista.erase(it2);
            if(it2 == lista.end()) it2 = lista.begin();
            pomocni1--;
        }
        while(temp!=0){
            while(slova!=0){
                slova--;
                it2++;
                if(it2==lista.end()) it2=lista.begin();
            }
            strskup.insert(*it2);
            slova=BrojSlova(*it2);
            it2 = lista.erase(it2);
            if(it2 == lista.end()) it2 = lista.begin();
            temp--;
        }
        krajnji.push_back(strskup);
        br_tim--;
    }
    return krajnji;
}

int main (){
    int djeca;
    std::cout << "Unesite broj djece: ";
    std::cin >> djeca;
    std::cin.ignore(10000, '\n');
    spisak imena;
    std::cout << "Unesite imena djece: " << std::endl;
    for(int i(0); i<djeca; i++){
        std::string temp;
        std::getline(std::cin, temp);
        imena.push_back(temp);
    }
    int timovi;
    std::cout <<"Unesite broj timova: ";
    std::cin >> timovi;
    try{
        skup kraj(Razvrstavanje(imena, timovi));
        Ispisi(kraj);
    }
    catch(std::logic_error belaj){
        std::cout << "Izuzetak: " << belaj.what();
        return 0;
    }
	return 0;
}