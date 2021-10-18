/B2016/2017: Zadaća 3, Zadatak 5

#include <iostream>
#include <vector>
#include<set>
#include<string>
#include<stdexcept>
#include<memory>
using std:: cin;
using std:: cout;
using std:: string;
using std:: vector;
struct Dijete {
    string ime;
   std::shared_ptr< Dijete> sljedeci;
};
vector<std:: set<string>> Razvrstaj(vector<string> djeca, int tim){
    if(tim<1 || tim> djeca.size()) throw std:: logic_error ("Razvrstavanje nemoguce") ;
    vector<int> brclanova;
    for(int i=0; i<djeca.size()%tim; i++)
        brclanova.push_back((djeca.size()/tim) +1);
    for(int i=djeca.size()%tim; i<tim; i++)
        brclanova.push_back(djeca.size()/tim);
        
        std::shared_ptr<Dijete >pocetak(nullptr), prethodni;
        
    
    vector<std:: set<string>> v(tim);
    for( int i=0; i<djeca.size(); i++) {
        std:: shared_ptr<Dijete>novi(new Dijete);
        novi->ime=djeca[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    
    int j(0);
    auto p(pocetak);
    while(prethodni!=nullptr){
        
        string s(p->ime);
        int br(0);
        for(int i=0; i<s.length(); i++){
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9') ) br++;
        }
        v[j].insert(p->ime);
        if(v[j].size()==brclanova[j]) j++;
        if(p==prethodni){p->sljedeci=nullptr; prethodni->sljedeci=nullptr; p=nullptr; prethodni=nullptr;}
        else{
            prethodni->sljedeci=p->sljedeci;
            auto p2(p);
            p=p->sljedeci;
            
            for(int i=0; i<br-1; i++){
            p=p->sljedeci;
            prethodni=prethodni->sljedeci;
          }
    
        }
    }
    return v;
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