/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <set>
#include <stdexcept>


using namespace std;


struct Dijete{
  string ime;
  Dijete* sljedeci;
    
};


int duzinaImena(string ime){
    int duzina=0;
    
    for (int i = 0; i < ime.size(); i++) {
        if((ime[i]>='a'&&ime[i]<='z')||(ime[i]>='A'&&ime[i]<='Z')||(ime[i]>='0'&&ime[i]<='9'))
            duzina++;
    }
    return duzina;
}

std::vector<multiset<string>> Razvrstavanje(std::vector<string> imenaDjece, int brojTimova){
    if(brojTimova<0 || brojTimova>imenaDjece.size()) throw logic_error("Razvrstavanje nemoguce");
    std::vector<multiset<string>>timoviDjece ;
    
    Dijete*pocetak=nullptr,*novi,*trenutni=nullptr,*prethodni=nullptr,*zadnje_dijete=nullptr;
    
    novi=new Dijete;
    pocetak=trenutni=novi;
    for (int i = 0; i < imenaDjece.size(); i++) {
        
        if(pocetak==nullptr){
            novi->ime=imenaDjece[i];
            novi->sljedeci=novi;
            trenutni=novi;
        }
        else{
            trenutni=imenaDjece[i];
            trenutni->sljedeci=novi;
        }
        
    }
    
    trenutni=zadnje_dijete;
    zadnje_dijete->sljedeci=pocetak;
    
    vector<int> kapacitetiTimova(brojTimova,imenaDjece.size()/brojTimova);
    
    int djecaBezTima = imenaDjece.size()%brojTimova;
    
    for (int i = 0; i < djecaBezTima; i++) {
        kapacitetiTimova[i]++;
    }
    
    
    multiset<string> tim; 
    int rednibrojTima=0;
 //   auto it = imenaLista.begin();
 //   tim.insert(*it);
 //   int duzina=duzinaImena(*it);
 //   it=imenaLista.erase(it);
    int br=0;
    prethodni=trenutni; //odavde provjeriti funkciju, da li su dobri pokazivaci i veze
    trenutni=pocetak;

    while(trenutni!=pocetak){ //da li je ovaj uslov dobar
        br++;
        if(br==duzina){ // Kako odrediti duzinu jednog ako ne koristim vise iterator?
            if(tim.size()==kapacitetiTimova[rednibrojTima]){
                rednibrojTima++;
                timoviDjece.push_back(tim);
                tim=multiset<string>();
            }     
            tim.insert(*trenutni); // ubaciti string iz ovog cvora a ne pok na vezu
            duzina=duzinaImena(*trenutni);
            prethodni->sljedeci = trenutni->sljedeci 
            delete trenutni;
            trenutni = prethodni->sljedeci;
            br=0;
            
        }
        else{
            trenutni=trenutni->sljedeci; 
            prethodni = prethodni->sljedeci;
        }
        
        
//        if(it==imenaLista.end()) it=imenaLista.begin();
    }
    if(tim.size()!=0)timoviDjece.push_back(tim);
    
    
    return timoviDjece;
}



int main ()
{
    try{
        int brojDjece;
        vector<string> imena;
        cout<<"Unesite broj djece: ";
        cin>>brojDjece;
        cout<<"Unesite imena djece: "<<endl;
        cin.ignore(1000,'\n');
        for (int i = 0; i < brojDjece; i++) {
            string ime;
            getline(cin,ime);
            imena.push_back(ime);
        }
        cout<<"Unesite broj timova: ";
        int brojTimova;
        cin>>brojTimova;
        std::vector<multiset<string>> timovi = Razvrstavanje(imena,brojTimova);
        
        
        for (int i = 0; i < timovi.size(); i++) {
            cout<<"Tim "<<i+1<<": ";
            auto it=timovi[i].begin();
            cout<<*it;
            it++;
            while(it!=timovi[i].end()){
              
                cout<<", "<<*it;
                it++;
            }
            cout<<endl;
        }
    }
    catch(logic_error e){
        cout<<e.what()<<endl;
    }
	return 0;
}