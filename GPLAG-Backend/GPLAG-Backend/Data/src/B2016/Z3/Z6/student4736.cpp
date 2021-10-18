/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <set>
#include <stdexcept>
#include<memory>

using namespace std;


int duzinaImena(string ime){
    
    int brojac=0;
    for (int i = 0; i < ime.size(); i++) {
        if( (ime[i]>='a'&&ime[i]<='z') || (ime[i]>='A'&&ime[i]<='Z') || (ime[i]>='0'&&ime[i]<='9')){
            brojac++;
        }
    }
    
    return brojac;
}

struct Dijete{
    string ime;
    shared_ptr<Dijete> sljedeci;
};

vector<multiset<string>> Razvrstavanje( vector<string> imena, int brojTimova){
    if(brojTimova<1 ||brojTimova>imena.size()) throw logic_error("Razvrstavanje nemoguce");
    
    
    vector< multiset<string> >  rezultat (brojTimova);
    
    
       shared_ptr<Dijete> pocetak=nullptr,trenutni;
    
    
    for (int i = 0; i < imena.size(); i++) {
        
        shared_ptr<Dijete> novo = make_shared< Dijete>();
        novo->ime = imena[i];
        if(pocetak==nullptr){
            pocetak=novo;
        }
        else{
            trenutni->sljedeci=novo;
        }
        trenutni=novo;
        novo->sljedeci=pocetak;
    }
    
    
    int redniBrojTima=0;
    int brojUbaceneDjece=0;
    int brojDjece = imena.size(); 
    int visakDjeca = brojDjece%brojTimova;
    int regularanTim = brojDjece/brojTimova;
    
    
    vector<int> kapaciteti;
    for (int i = 0; i < brojTimova; i++) {
        int visak=0;
        if(visakDjeca>0){
            visakDjeca--;
            visak=1;
        }
        kapaciteti.push_back(regularanTim+visak);
    }
    
    
    shared_ptr<Dijete> tr = pocetak;
    shared_ptr<Dijete> pr = pocetak;
    while(pr->sljedeci!=pocetak){
        pr=pr->sljedeci;
    }
   
    do{
        rezultat[redniBrojTima].insert(tr->ime);
        brojUbaceneDjece++;
        if(brojUbaceneDjece==kapaciteti[redniBrojTima]){
            brojUbaceneDjece=0;
            redniBrojTima++;
        }
        int duzina = duzinaImena(tr->ime);
      
        pr->sljedeci=tr->sljedeci;
        tr = pr->sljedeci;
        
      
        for (int i = 0; i < duzina-1; i++) {
            
           tr=tr->sljedeci;
           pr=pr->sljedeci;
        }
        
    }while(tr->sljedeci!=tr);
    
    rezultat[rezultat.size()-1].insert(tr->ime);
    tr->sljedeci=nullptr;
    tr=nullptr;
    
    return rezultat;
}


int main ()
{
    try{
       
        cout<<"Unesite broj djece: ";
        int brojDjece;
        cin>>brojDjece;
        
        
        cout<<"Unesite imena djece: "<<endl;
        std::vector<string>imenaDjece(brojDjece) ;
        for (int i = 0; i < brojDjece; i++) {
              cin>>ws;
            getline(cin,imenaDjece[i]);
          
        }
       
        cout<<"Unesite broj timova: ";
        int brojTimova;
        cin>>brojTimova;
        
        std::vector<multiset<string>> timovi = Razvrstavanje(imenaDjece,brojTimova);
       
       for (int i = 0; i < timovi.size(); i++) {
             cout<<"Tim "<<i+1<<": ";  
             auto it = timovi[i].begin();
             cout<<*it++;
            for(; it!=timovi[i].end();it++){
                cout<<", "<<*it;
            }
            cout<<endl;
       }
    }
    catch(logic_error e){
        cout<<e.what()<<endl;
    }
	return 0;
}