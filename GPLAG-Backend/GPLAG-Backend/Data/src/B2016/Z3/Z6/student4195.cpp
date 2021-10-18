#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::shared_ptr;

typedef vector<std::set<string>> VektTimova;


struct Dijete{
  string ime;
  shared_ptr<Dijete> sljedeci;
};

typedef shared_ptr<Dijete> dij_Dijete;

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
    dij_Dijete izbaceni(nullptr), prethodni(nullptr);
    try{
        for(int i=0; i<imena.size(); i++){
            dij_Dijete novi(std::make_shared<Dijete>());
            novi->ime=imena.at(i); 
            if(i==int(imena.size()-1)) novi->sljedeci=izbaceni;
            else novi->sljedeci=nullptr;
            if(!izbaceni) izbaceni=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
        }
    }
    catch(std::bad_alloc){
        auto pomocna(izbaceni);
        for(auto p=izbaceni; p!=nullptr; p=pomocna){
            pomocna=p->sljedeci;
            p->sljedeci=nullptr; //Unistavanjem lokalnih varijabli, unistit ce se svi pokazivaci preostali na cvorove i nema curenja memorije
        }
        throw;
    }
    int min_broj_clanova=imena.size()/broj_timova;
    int broj_vecih=imena.size()%broj_timova;
    for(int i=0; i<broj_timova; i++){
        int brojac;
        if(i<broj_vecih) brojac = min_broj_clanova+1;
        else brojac=min_broj_clanova;
        std::set<string> tim;
        while(brojac>0){
            tim.insert(izbaceni->ime);
            int br_slova(BrojSlova(izbaceni->ime));
            if(brojac==1 and i==broj_timova-1){
                izbaceni->sljedeci=nullptr; //3 pokazivaca imaju na preostali cvor, prethodni, izbaceni i sam na sebe
                izbaceni=nullptr; 
                prethodni=nullptr;
                break;
            }
            else{
                prethodni->sljedeci=izbaceni->sljedeci;
                izbaceni->sljedeci=nullptr;
                izbaceni=prethodni->sljedeci;
                br_slova--; //Vec smo se pomjerili jedno mjesto
            }
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