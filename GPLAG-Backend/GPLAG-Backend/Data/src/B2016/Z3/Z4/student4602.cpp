/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <set>
using namespace std;

int BrojSlova(string s){
    int b=0;
    for(int i=0; i<s.length(); i++){
        
        b++;
    }
    return b;
}

vector<set<string>>Razvrstavanje(vector<string>v1, int k){
    if(k<1 || k>v1.size()) throw logic_error("Razvrstavanje nemoguce");
    
    list<string>l;
    set<string>s;
    int a=v1.size()%k;
    int b=v1.size()/k;
    vector<set<string>>v;
    vector<int>BrojDjece;
    for(int i=0; i<a; i++){
        BrojDjece.push_back(1+b);
    }
    while(BrojDjece.size()!=k){
        BrojDjece.push_back(b);
    }
    copy(v1.begin(), v1.end(), back_inserter(l));
    auto it=l.begin();
    int br=int(it->size())-1;
    s.insert(*it);
    it=l.erase(it);
    if(it==l.end()) it=l.begin();
    if(s.size()==BrojDjece[0]){
        v.push_back(s);
        BrojDjece.erase(BrojDjece.begin());
        s.clear();
    }
    while(l.size()!=0){
        for(int i=0; i<br; i++){
            it++;
            if(it==l.end()) it=l.begin();
        }
        s.insert(*it);
        br=int(it->size())-1;
        it=l.erase(it);
        if(it==l.end()) it=l.begin();
        if(s.size()==BrojDjece[0]){
            v.push_back(s);
            s.clear();
            BrojDjece.erase(BrojDjece.begin());
        }
    }
    if(s.size()) v.push_back(s);
    
    return v;
}


int main ()
{
    string s;
    vector<string>v;
    cout<<"Unesite broj djece: ";
    int n;
    cin>>n;
    cout<<"Unesite imena djece: \n";
    cin.ignore(10000,'\n');
    while(n!=0){
        getline(cin, s);
        if(s.size()!=0) v.push_back(s);
        n--;
    }
    cout<<"Unesite broj timova: ";
    int k;
    try{
    cin>>k;
    vector<set<string>>v2=Razvrstavanje(v, k);
    
    for(int i=0; i<v2.size(); i++){
        cout<<"Tim "<<i+1<<": ";
        auto it=v2[i].begin();
        while(it!=--(v2[i].end())){
            cout<<*it<<", ";
            it++;
        }
        cout<<*it<<" ";
        cout<<endl;
    }
    }
    catch(logic_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
    }
    
    
	return 0;
}