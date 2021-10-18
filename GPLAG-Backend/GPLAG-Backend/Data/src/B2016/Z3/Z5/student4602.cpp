#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <set>
using namespace std;
struct Dijete{
    string ime;
    Dijete *slijedeci;
};


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