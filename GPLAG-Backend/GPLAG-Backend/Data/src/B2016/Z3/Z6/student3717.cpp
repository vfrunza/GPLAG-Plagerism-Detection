/B2016/2017: Zadaća 3, Zadatak 6
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<stdexcept>
#include<cmath>
#include<memory>

struct Dijete{
      std::string ime;
      std::shared_ptr<Dijete> sljedeci;
    };

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> s, int k){
    if(k<1 || k>s.size())
        throw std::logic_error("Razvrstavanje nemoguce");
    int n(s.size()%k);
    int n1((s.size()/k)+1);
    int n2(s.size()/k);
    std::vector<std::set<std::string>> v;
    //kreiranje povezane liste
    std::shared_ptr<Dijete> pocetak(nullptr), prethodni;
    for(int i=0; i<s.size(); i++){
        std::shared_ptr<Dijete> novi(std::make_shared<Dijete>());
        novi->ime=s.at(i); //postavljanje imenaa u listu
        novi->sljedeci=nullptr;
        if(!pocetak)
            pocetak=novi;
        else 
            prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak; //kraj pokazuje na pocetak(kruzna lista)
    std::set<std::string> skup1;
    std::set<std::string> skup2;
    int brojac(s.size());
    while(brojac>0){
        std::string pomocna(pocetak->ime);
        if(v.size()<n){
            if(skup1.size()<n1)
                skup1.insert(pomocna);
            if(skup1.size()==n1){
                v.push_back(skup1);
                skup1.clear();
            }        
        }
        else{
            if(skup2.size()<n2)
                skup2.insert(pomocna);
            if(skup2.size()==n2){
                v.push_back(skup2);
                skup2.clear();
            }
        }
        //brisanje ubacenog elementa i vracanje iteratora za jedno polje unazad
        auto temp(pocetak), temp1(pocetak);
        while(temp->sljedeci!=pocetak)
            temp=temp->sljedeci;
        pocetak=pocetak->sljedeci;
        temp->sljedeci=pocetak;
        if(brojac>1){
            for(int i=1; i<pomocna.size(); i++)
                if(pomocna[i]!=' ')
                    pocetak=pocetak->sljedeci;
        }
        else if(brojac==1)
            pocetak->sljedeci=nullptr;
        brojac--;
    }
    return v;
}
int main (){
    int n(0), k;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::cin.ignore(1000, '\n');
    std::cin.clear();
    std::vector<std::string> v;
    std::cout<<"Unesite imena djece: ";
    for(int i=0; i<n; i++){
        std::string ime;
        std::getline(std::cin, ime);
        v.push_back(ime);
    }
    std::cout<<std::endl;
    std::cout<<"Unesite broj timova: ";
    std::cin>>k;
    try{
        std::vector<std::set<std::string>> timovi(Razvrstavanje(v,k));
        for(int i=0; i<timovi.size(); i++){
            std::cout<<"Tim "<<i+1<<": ";
            auto it=timovi[i].begin();
            for(; it!=--timovi[i].end(); it++)
                std::cout<<*it<<", ";
            std::cout<<*it<<std::endl;
        }
    }
    catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}