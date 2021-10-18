/B2016/2017: Zadaća 3, Zadatak 5

#include <iostream>
#include <vector>
#include<set>
#include<string>
#include<stdexcept>
using std:: cin;
using std:: cout;
using std:: string;
using std:: vector;
struct Dijete {
    string ime;
    Dijete* sljedeci;
};
vector<std:: set<string>> Razvrstaj(vector<string> djeca, int tim){
    if(tim<1 || tim> djeca.size()) throw std:: logic_error ("Razvrstavanje nemoguce") ;
    vector<int> brclanova;
    for(int i=0; i<djeca.size()%tim; i++)
        brclanova.push_back((djeca.size()/tim) +1);
    for(int i=djeca.size()%tim; i<tim; i++)
        brclanova.push_back(djeca.size()/tim);
        
        Dijete *pocetak(nullptr), *prethodni;
        
    try{
    vector<std:: set<string>> v(tim);
    for( int i=0; i<djeca.size(); i++) {
        Dijete *novi(new Dijete);
        novi->ime=djeca[i];
        novi->sljedeci=nullptr; 
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    
    int j(0);
    Dijete *p(pocetak);
    while(prethodni!=nullptr){
        
        string s(p->ime);
        int br(0);
        for(int i=0; i<s.length(); i++){
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9') ) br++;
        }
        v[j].insert(p->ime);
        if(v[j].size()==brclanova[j]) j++;
        if(p==prethodni){ delete p; prethodni=nullptr;}
        else{
            prethodni->sljedeci=p->sljedeci;
            Dijete*p2(p);
            p=p->sljedeci;
            delete p2;
            for(int i=0; i<br-1; i++){
            p=p->sljedeci;
            prethodni=prethodni->sljedeci;
          }
    
        }
    }
    return v;}
    catch(std:: bad_alloc){
        while(pocetak!=prethodni){
            auto p(pocetak);
            pocetak=pocetak->sljedeci;
            delete p;
        }
        prethodni=nullptr;
        delete pocetak;
        throw  ("Problemi sa memorijom");
    }
}
int main ()
{
    try{
    cout << "Unesite broj djece: ";
    int n;
    cin >> n;
    cin.ignore(1000, '\n');
    vector<string> v;
    cout << "Unesite imena djece: " << std:: endl;
    for( int i=0; i<n; i++){
        string s; 
        std::getline(cin, s);
        v.push_back(s);
        
    }
    cout << "Unesite broj timova: ";
    int t; 
    cin>> t;
    cin.ignore(1000, '\n');
    vector<std:: set<string>> timovi(Razvrstaj(v, t));
    for(int i=0; i<timovi.size(); i++){
        cout << "Tim "<< i+1 << ": ";
        int br(0);
       for(const auto & s: timovi[i]){
            br++;
            cout << s;
            if(br==timovi[i].size()) break;
        cout << ", ";
        }
        cout << std:: endl;
       
    }
    }
    catch(std:: logic_error e){
        cout << "Izuzetak: "<<e.what();
    }
   
	return 0;
}