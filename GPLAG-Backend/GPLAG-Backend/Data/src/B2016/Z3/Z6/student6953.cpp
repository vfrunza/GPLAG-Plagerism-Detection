#include <iostream>
#include <list>
#include<set>
#include<vector>
#include<stdexcept>
#include<memory>
struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};
std::vector<std::set<std::string>>Razvrstavanje(std::vector<std::string> imena, int n)
{
    if(n<1 || n>imena.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> timovi;
    std::vector<int> brojclanova;
    for(int i=0; i<imena.size()%n; i++) {
        brojclanova.push_back((imena.size()/n)+1);
    }
    for(int i=0; i<n-imena.size()%n; i++) {
        brojclanova.push_back(imena.size()/n);
    }
    std::shared_ptr<Dijete> pocetak=nullptr; std::shared_ptr<Dijete> prethodni;
    for(int i=0; i<imena.size(); i++) {
        std::shared_ptr<Dijete>novi( new Dijete); // Kreiranje novog čvora
        novi->ime = imena[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak = novi; // Prvi čvor...
        else prethodni->sljedeci = novi; // Svi osim prvog...
        prethodni = novi;
    }
    prethodni->sljedeci=pocetak;
    auto it1=pocetak;
    int broj=0;
    int brojponavljanja=0;
    std::shared_ptr<Dijete> it=pocetak;
    std::shared_ptr<Dijete>it15=pocetak;
    for(int j=0;j<n; j++) {
        std::set<std::string>tim;
        while(brojclanova[j]!=tim.size() && j<n ) { 
        if(brojponavljanja>0){ for(int k=1; k<=brojponavljanja-1; k++) it= it->sljedeci;}
              broj=0;
            for(int p=0; p<(it->ime).length(); p++) {
                if(!(((it->ime)[p]>='a'&&(it->ime)[p]<='z')|| ((it->ime)[p]>='A'&&(it->ime)[p]<='Z') || ((it->ime)[p]>='0'&&(it->ime)[p]<='9'))) broj++;
            }
            brojponavljanja=(it->ime).length()-broj;
            tim.insert(it->ime);
            for(;;){
                if(it15->sljedeci==it)break; 
                it15=it15->sljedeci; 
            }
            if(it15->sljedeci==it->sljedeci)it15->sljedeci=nullptr;
          else { it15->sljedeci = it->sljedeci;}
             it=nullptr;
           if(it15!=it) it=it15->sljedeci; 
        }
        timovi.push_back(tim);
    }
    return timovi;
}
int main ()
{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cin.ignore(1000, '\n');
    std::vector<std::string> v;
    std::cout<<"Unesite imena djece: ";
    for(int i=0; i<n; i++) {
        std::string s;
        std::getline(std::cin, s);
        v.push_back(s);
    }
    std::cout<<"\nUnesite broj timova: ";
    int m;
    std::cin>>m;
    std::cin.ignore(1000, '\n');
    try {
        std::vector<std::set<std::string>> imena=Razvrstavanje(v, m);
        for(int i=0; i<imena.size(); i++) {
            std::cout<<"Tim "<<i+1<<": ";
            auto it=(imena[i]).begin();
            while(it!=--(imena[i]).end()) {
                std::cout << *it << ", ";
                it++;

                if(it==--(imena[i]).end()) break;
            }
            std::cout<<*it;
            std::cout<<std::endl;
        }

    } catch(std::logic_error iz) {
        std::cout<<"Izuzetak: "<<iz.what();
    }
    return 0;
}