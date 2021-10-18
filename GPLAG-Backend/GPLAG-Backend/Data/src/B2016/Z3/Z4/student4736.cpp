/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <stdexcept>

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

vector<multiset<string>> Razvrstavanje( vector<string> imena, int brojTimova){
    if(brojTimova<1 ||brojTimova>imena.size()) throw logic_error("Razvrstavanje nemoguce");
    
    
    vector< multiset<string> >  rezultat (brojTimova);
    
    list<string> listaImena;
    
    for (int i = 0; i < imena.size(); i++) {
        listaImena.push_back(imena[i]);
    }
    
    /*for(auto it=listaImena.begin();it!=listaImena.end();it++){
        cout<<*it<<endl;
    }*/
    
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
    
    
    auto it = listaImena.begin();
   
    do{
        rezultat[redniBrojTima].insert(*it);
        brojUbaceneDjece++;
        if(brojUbaceneDjece==kapaciteti[redniBrojTima]){
            brojUbaceneDjece=0;
            redniBrojTima++;
        }
        int duzina = duzinaImena(*it);
        it = listaImena.erase(it);
        if(it==listaImena.end()){
            it=listaImena.begin();
        }
        for (int i = 0; i < duzina-1; i++) {
            
            it++;
            if(it==listaImena.end()){
                it=listaImena.begin();
            }
        }
        
    }while(listaImena.size()!=0);
    
    
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