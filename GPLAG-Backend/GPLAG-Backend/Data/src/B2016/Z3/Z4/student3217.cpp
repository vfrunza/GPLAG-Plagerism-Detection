/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <iterator>
#include <stdexcept>

bool JeLiOdvojeno(char &a ){
    if(a<'0' || (a>'9' && a<'A') || (a>'Z' && a<'a') || a>'z' ) return true;     //testira da li je razmak, ovo sluzi kao pomocna fja da ustanovi kako da posmatra pojedino ime
    return false;
}

int brojiSlova(std :: string s ){
    int i(0), brojac(0);
    while(s[i]!='\0'){
        if(JeLiOdvojeno(s[i])== false) brojac ++; 
        i++;
    }
    
    return brojac;
        
}


std :: vector<int> vektorTimova(int djeca, int timovi){  //fja koja stvara vektor broja clanova u timu
    std :: vector< int> vektor;
    int n(0);
    
    if(djeca%timovi==0) for(int i(0); i<djeca/timovi; i++) vektor.push_back(djeca/timovi);
    
    if(djeca%timovi!=0){
        for(int i(0); i<djeca%timovi; i++) vektor.push_back(djeca/timovi+1);
        n=timovi-djeca%timovi;
        for(int i(0); i<n ; i++) vektor.push_back(djeca/timovi);
    }
    
    if(djeca/timovi==1) for(int i(0); i<timovi; i++) vektor.push_back(djeca/timovi);  //specijalni slucajevi, kada u svakom timu ima po 2 ili kada u svakom timu ima jedno
    if(djeca/timovi==2) for(int i(0); i<timovi; i++) vektor.push_back(djeca/timovi); 
    
    return vektor;
    
}

void IspisiSkup(std :: set<std :: string> skup){ 
    std :: vector<std :: string > pomocni;
    for(auto x: skup) pomocni.push_back(x);
    int n=pomocni.size();
    for(int i(0); i<pomocni.size()-1; i++){
        std :: cout << pomocni[i] << ", ";
    }
    std :: cout << pomocni[n-1];
}

std::vector<std :: set<std :: string>> Razvrstavanje(std :: vector < std :: string > djeca, int timovi){
    
    if(timovi<1 || timovi>djeca.size() ) throw std :: logic_error ("Izuzetak: Razvrstavanje nemoguce ");
    
    std :: vector<std :: set<std :: string>> FormiraniTimovi;
    std :: set<std :: string > SkupDjece;
    std :: list<std :: string> lista;
    int broj_djece=djeca.size()-1;
    std :: vector<int> VektorTimovi=vektorTimova(broj_djece, timovi);
   
    
    for(int i(0); i< djeca.size(); i++){
        lista.push_back(djeca[i]);
    
    }
    
    std :: list<std :: string> :: iterator pocetak(lista.begin());
    
    std :: string pomocni;
    int i(0);
    
    while(pocetak!=lista.end()){
        
        pomocni=*pocetak;

        int broj=brojiSlova(pomocni);
        if(pocetak== --lista.end()) broj++;  //ako se iterator nalazi na mjestu posljednjeg imena u listi onda ovdje u uslovu poveca 
                                               //broj za jedan jer bi se u suprotnom for petlja za jedan manje broj puta izvrsila
                                                 // zato sto nas iterator uzima u obzir i lista.end()
        pocetak=lista.erase(pocetak);
            
        for(int k(0); k<broj-1; k++){
        pocetak++; 
        if(pocetak==lista.end())
        pocetak=lista.begin();
        }
            
        if(broj!=0) SkupDjece.insert(pomocni);
        
        if(SkupDjece.size()==VektorTimovi[i]){           //kada se skup napuni do broja jednog tima ona ubacujem skup u vektor skupova i 
                                                             // 'resetiram' skup, zbog ustede 
            FormiraniTimovi.push_back(SkupDjece);
            SkupDjece.clear();
            i++;
        }
        
        if(pocetak==lista.end())  pocetak=lista.begin();
            
    }
    
    return FormiraniTimovi;
    
    
}

int main ()
{
    std :: vector<std :: string> djeca;
    std :: string ime;
    int n, timovi;
    
    std :: cout << "Unesite broj djece: ";
    std :: cin >> n;
    
    std :: cout << "Unesite imena djece: ";
    
    int i(0);
    
    while(i<=n){
        std :: getline(std :: cin, ime);
        djeca.push_back(ime);
        i++;
    }
    
    std :: cout << "\nUnesite broj timova: ";
    std :: cin >> timovi;
    
    try{
    
    std :: vector<std ::set<std :: string>> team=Razvrstavanje(djeca, timovi);
    
    for(int i(0); i<team.size(); i++){
        std :: cout << "Tim " << i+1 << ": ";
        IspisiSkup(team[i]);
        std :: cout << std :: endl;
    }
    
    } 
    catch(std :: logic_error IZUZETAK){
        std :: cout << IZUZETAK.what() << std :: endl;
    }
    
	return 0;
}