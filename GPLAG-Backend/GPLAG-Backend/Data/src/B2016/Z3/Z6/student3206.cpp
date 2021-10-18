#include <iostream>
#include <vector>
#include <new>
#include <set>
#include <string>
#include <stdexcept>
#include <memory>

using std::cin;
using std::cout;

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

int BrojSlova(std::string s){
    int brojac(0);
    for(int i=0;i<s.length();i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        brojac++;
    }
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca1,int brtimova){
    if(brtimova<1 || brtimova>djeca1.size())
    throw std::logic_error("Razvrstavanje nemoguce");
    std::shared_ptr<Dijete> pocetak(nullptr),prethodni;
    int n(djeca1.size());
    int prvi=n%brtimova;
    int brcl1=n/brtimova+1;
    int brcl2=n/brtimova;
    int brslova(0);
    for(int i=0;i<n;i++){
        auto novi=std::make_shared<Dijete>();
        novi->ime=djeca1[i];
        if(i==n-1)
        novi->sljedeci=pocetak;
        else
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    std::vector<std::set<std::string>> timovi(brtimova);
    for(int i=0;i<brtimova;i++){
        if(i<prvi){
            for(int j=0;j<brcl1;j++){
                if(i==0 && j==0){
                    timovi[i].insert(pocetak->ime);
                    brslova=BrojSlova(pocetak->ime);
                    prethodni->sljedeci=pocetak->sljedeci;
                    pocetak=prethodni->sljedeci;
                    j++;
                }
                for(int k=1;k<brslova;k++){
                    prethodni=prethodni->sljedeci;
                    pocetak=pocetak->sljedeci;
                }
                timovi[i].insert(pocetak->ime);
                brslova=BrojSlova(pocetak->ime);
                prethodni->sljedeci=pocetak->sljedeci;
                pocetak=prethodni->sljedeci;
            }
        }
        else{
            for(int j=0;j<brcl2;j++){
                for(int k=1;k<brslova;k++){
                    prethodni=prethodni->sljedeci;
                    pocetak=pocetak->sljedeci;
                }
                timovi[i].insert(pocetak->ime);
                brslova=BrojSlova(pocetak->ime);
                if(i==brtimova-1 && j==brcl2-1)
                prethodni->sljedeci=nullptr;
                else{
                prethodni->sljedeci=pocetak->sljedeci;
                if(prethodni!=pocetak)
                pocetak=prethodni->sljedeci;
                }
            }
        }
    }
    return timovi;
}

int main ()
{
    int n;
    cout<<"Unesite broj djece: ";
    cin>>n;
    cin.ignore(1000,'\n');
    std::vector<std::string> djeca(n);
    cout<<"Unesite imena djece: "<<std::endl;
    for(int i=0;i<n;i++){
        std::getline(cin,djeca[i]);
    }
    cout<<"Unesite broj timova: ";
    int brtimova;
    cin>>brtimova;
    std::vector<std::set<std::string>> timovi(brtimova);
    try{
    timovi=Razvrstavanje(djeca,brtimova);
    for(int i=0;i<brtimova;i++){
        cout<<"Tim "<<i+1<<": ";
        for(auto it=timovi[i].begin();it!=timovi[i].end();it++)
        if(it==--timovi[i].end())
        cout<<*it;
        else
        cout<<*it<<", ";
        cout<<std::endl;
    }
    }
    catch(std::logic_error iz){
        cout<<"Izuzetak: "<<iz.what();
    }
	return 0;
}
