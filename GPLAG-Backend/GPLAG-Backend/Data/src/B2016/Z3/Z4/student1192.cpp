/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include<list>
#include<set>
#include<string>
#include<stdexcept>
using std:: cin;
using std:: cout;
using std:: string;
using std:: vector;
vector<std:: set<string>> Razvrstaj(vector<string> djeca, int tim){
    if(tim<1 || tim> djeca.size()) throw std:: logic_error ("Razvrstavanje nemoguce") ;
    vector<int> brclanova;
    for(int i=0; i<djeca.size()%tim; i++)
        brclanova.push_back((djeca.size()/tim) +1);
    for(int i=djeca.size()%tim; i<tim; i++)
        brclanova.push_back(djeca.size()/tim);
    std:: list<string> lista; 
    vector<std:: set<string>> v(tim);
    for( int i=0; i<djeca.size(); i++) lista.push_back(djeca[i]);
    auto it(lista.begin());
    int j(0);
    while(lista.size()!=0){
        if(it== lista.end()) it=lista.begin();
        string s(*it);
        int br(0);
        for(int i=0; i<s.length(); i++){
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9') ) br++;
        }
        v[j].insert(*it);
        if(v[j].size()==brclanova[j]) j++;
        it=lista.erase(it);
        for(int i=0; i<br-1; i++){
            if(it==lista.end()) it= lista.begin();
            it++;
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
        cout <<"Izuzetak: "<< e.what();
    }
	return 0;
}