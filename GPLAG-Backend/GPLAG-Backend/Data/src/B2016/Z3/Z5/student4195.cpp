#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

typedef vector<std::set<string>> VektTimova;

struct Dijete{
  string ime;
  Dijete* sljedeci;
};

bool JesteSlovo(char karakter){
     if(karakter<'A' or (karakter>'Z' and karakter<'a') or karakter>'z')
        return false;
    return true;
}

bool JesteBroj(char karakter) {
    if(karakter>='0' and karakter <='9')
        return true;
    return false;
}

int BrojSlova(string ime){
    int brojac(0);
    for(int i=0; i<ime.size(); i++){
        if(JesteBroj(ime.at(i)) or JesteSlovo(ime.at(i))) brojac++;
    }
    return brojac;
}


VektTimova Razvrstavanje (vector<string> imena, int broj_timova){
    if(broj_timova<1 or broj_timova>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    VektTimova timovi(broj_timova);
    Dijete* pocetak(nullptr), *prethodni(nullptr);
    try{
        for(int i=0; i<imena.size(); i++){
            Dijete* novi(new Dijete);
            novi->ime=imena.at(i); 
            if(i==int(imena.size()-1)) novi->sljedeci=pocetak;
            else novi->sljedeci=nullptr;
            if(!pocetak) pocetak=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
        }
    }
    catch(std::bad_alloc){
        auto pomocna(pocetak);
        for(auto p=pocetak; p!=nullptr; p=pomocna){
            pomocna=p->sljedeci;
            delete p;
        }
        throw;
    }
    int min_broj_clanova=imena.size()/broj_timova;
    int broj_vecih=imena.size()%broj_timova;
    Dijete* izbaceni=pocetak; 
    for(int i=0; i<broj_timova; i++){
        int brojac;
        if(i<broj_vecih) brojac = min_broj_clanova+1;
        else brojac=min_broj_clanova;
        std::set<string> tim;
        while(brojac>0){
            tim.insert(izbaceni->ime);
            int br_slova(BrojSlova(izbaceni->ime));
            prethodni->sljedeci=izbaceni->sljedeci; //Izacujemo kariku "izbaceni" iz lanca djece
            Dijete* izbrisan=izbaceni; //Kreiramo pokazivac samo za brisanje
            izbaceni=izbaceni->sljedeci;
            delete izbrisan;
            if(brojac==1 and i==broj_timova-1) break;
            br_slova--; //Vec smo se pomjerili jedno mjesto
            while(br_slova>0){
                prethodni=prethodni->sljedeci;
                izbaceni=izbaceni->sljedeci;
                br_slova--;
            }
            brojac--;
        }  
        timovi.at(i)=tim;
    }
    return timovi;
}

int main ()
{
    cout<<"Unesite broj djece: ";
    int n,br_timova;
    cin>>n;
    cin.ignore(10000,'\n');
    vector<string> imena;
    cout<<"Unesite imena djece: "<<endl;
    for(int i=0; i<n; i++){
        string ime;
        getline(cin,ime);
        imena.push_back(ime);
    }
    cout<<"Unesite broj timova: ";
    cin>>br_timova;
    int brojac(1);
    try{
        auto timovi(Razvrstavanje(imena,br_timova));
        for(auto skup: timovi){
            cout<<"Tim "<<brojac<<": ";
            for(auto ime:skup){
                if(ime==*--skup.end()) cout<<ime;
                else cout<<ime<<", ";
            }
            cout<<endl;
            brojac++;
        }
    }
    catch(std::logic_error e){
        cout<<"Izuzetak: "<<e.what()<<endl;
    }
    catch(std::bad_alloc){
        cout<<"Problemi sa memorijom!"<<endl;
    }
	return 0;
}