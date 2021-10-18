/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <list>
#include <iterator>

typedef std::vector<std::string> spisak;
typedef std::vector<std::set<std::string>> skup;

struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};

void Ispisi(skup raspored){
    for(int i(0); i<raspored.size(); i++){
        std::cout << "Tim " << i+1 << ": ";
        auto it(raspored[i].begin());
        while(it != --raspored[i].end()){
            std::cout << *it << ", ";
            it++;
        }
        std::cout << *it << std::endl;
    }
}

void Ispisicvor(Dijete *pocetak, int br){
    for(int i(0); i<br; i++, pocetak=pocetak->sljedeci)
        std::cout << pocetak->ime << " ";
    std::cout << std::endl;
}

int BrojSlova(std::string ime){
    int brojac(0);
    for(int i(0); i<ime.length(); i++)
        if((ime[i]>='a' && ime[i]<='z') || (ime[i]>='A' && ime[i]<='Z') || (ime[i]>='0' && ime[i]<='9')) brojac++;
    return brojac-1;
}

skup Razvrstavanje(spisak imena, int br_tim){
    if(br_tim<1 || br_tim>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    skup krajnji;
    auto it1(imena.begin());
    Dijete *pocetak(nullptr), *prethodni;
    while (it1!=imena.end()){
        Dijete *novi(new Dijete);
        if(it1 == --imena.end()){
            novi->ime = *it1; novi->sljedeci=pocetak;
            prethodni->sljedeci = novi; prethodni = novi;
            break;
        }
        novi->ime = *it1; novi->sljedeci=nullptr;
        if(!pocetak) pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
        it1++;
    }
    int broj(imena.size());
    int pomocni1 = broj%br_tim;
    int pomocni2 = broj/br_tim;
    int slova(0);
    Dijete *p = pocetak, *prije_p = prethodni;
    //Ispisicvor(p);
    while(br_tim>0){
        while(slova!=0){
            slova--;
            p=p->sljedeci;
            prije_p=prije_p->sljedeci;
        }
        std::set<std::string> strskup;
        strskup.insert(p->ime);
        slova = BrojSlova(p->ime);
        Dijete *temp1 = p;
        prije_p->sljedeci=p->sljedeci;
        p=p->sljedeci;
        delete temp1;
        //temp1=nullptr;
        //Ispisicvor(p, broj);
        int temp = pomocni2-1;
        if(pomocni1!=0){
            while(slova!=0){
                slova--;
                p=p->sljedeci;
                prije_p=prije_p->sljedeci;
            }
            strskup.insert(p->ime);
            slova=BrojSlova(p->ime);
            Dijete *temp1 = p;
            prije_p->sljedeci=p->sljedeci;
            p=p->sljedeci;
            delete temp1;
            //temp1 = nullptr;
            //Ispisicvor(p, broj);
            pomocni1--;
        }
        while(temp!=0){
            while(slova!=0){
                slova--;
                p=p->sljedeci;
                prije_p=prije_p->sljedeci;
            }
            strskup.insert(p->ime);
            slova=BrojSlova(p->ime);
            Dijete *temp1 = p;
            prije_p->sljedeci=p->sljedeci;
            p=p->sljedeci;
            delete temp1;
            //temp1 = nullptr;
            //Ispisicvor(p, broj);
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