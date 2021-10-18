/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stdexcept>

struct Dijete{
    std::string ime;
    Dijete* sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int n){
    if(n<1 || n>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    Dijete *pocetak(nullptr), *prethodni,*novi,*zadnji;
    for(int i=0;i<imena.size();i++){
        novi=new Dijete;
        novi->ime=imena[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
        if(i==imena.size()-1) {
            prethodni->sljedeci=pocetak; 
            zadnji=prethodni;
        }
    }
    Dijete* trenutni(pocetak),*preth(zadnji),*tempt;
    std::set<std::string> tim;
    std::vector<std::set<std::string>> timovi;
    int zajedanveci=(imena.size())%n;
    int brclanova=imena.size()/n;
    int ostali=n-zajedanveci;
    for(int i=0;i<zajedanveci;i++){                       //pravljenje timova koji imaju broj clanova za jedan veci
        for(int k=0;k<brclanova+1;k++){         
            std::string ime=trenutni->ime;
            tim.insert(ime);
            tempt=trenutni;                                 //temp sluzi da bi mogli zapamtiti onaj koji trebamo obrisati 
            preth->sljedeci=trenutni->sljedeci;             //preusmjeravanje prethodnog da pokazuje na onaj nakon trenutnog
            trenutni=trenutni->sljedeci;                    //pomjeranje trenutnog za jedno mjesto unaprijed, jer u narednom koraku brisemo temp(koji je ustvari nas trenutni)
            tempt->sljedeci=nullptr; delete tempt;
            int velicina(0);
            for(int a=0;a<ime.size();a++){                //ime se sastoji od slova i cifara...
                if((ime[a]>='A' && ime[a]<='Z') || (ime[a]>='a' && ime[a]<='z') || (ime[a]>='0' && ime[a]<='9')) velicina++;
            }
            for(int j=0;j<velicina-1;j++) {               //pomjeranje trenutnog i prethodnog za broj znakova imena-1 - jer smo vec jednom pomjerili, da bi mogli izbrisati 
                trenutni=trenutni->sljedeci;
                preth=preth->sljedeci;
            }
            if(tim.size()==brclanova+1){                //ako je tim popunjen sa onoliko clanova koliko je potrebno, dodajemo ga u vektor timova i cistimo
                timovi.push_back(tim);
                tim.clear();
            }
        }
    }
    for(int i=0;i<ostali;i++){                    //isti postupak i za ostale timove - koji imaju br clanova odredjen po formuli
        for(int k=0;k<brclanova;k++){
            std::string ime=trenutni->ime;
            tim.insert(ime);
            if(i==ostali-1 && k==brclanova-1){                //uslov za posljednje preostalo dijete
               trenutni->sljedeci=nullptr;
               delete trenutni;
            }
            else{
                tempt=trenutni;
                preth->sljedeci=trenutni->sljedeci;
                trenutni=trenutni->sljedeci;
                tempt->sljedeci=nullptr; delete tempt;
                int velicina(0);
                for(int a=0;a<ime.size();a++){
                    if((ime[a]>='A' && ime[a]<='Z') || (ime[a]>='a' && ime[a]<='z') || (ime[a]>='0' && ime[a]<='9')) velicina++;
                }
                for(int j=0;j<velicina-1;j++) {
                    trenutni=trenutni->sljedeci;
                    preth=preth->sljedeci;
                }
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
{   std::string ime;
    std::vector<std::string> v;
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::cin.ignore(10000,'\n');
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
            for(auto it=timovi[i].begin();it!=timovi[i].end();it++){
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