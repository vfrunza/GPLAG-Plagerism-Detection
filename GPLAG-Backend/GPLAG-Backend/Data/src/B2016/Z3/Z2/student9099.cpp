/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <set>
#include <utility>
#include <map>

using namespace std;
typedef map<string,set<int>> mapa;
mapa KreirajIndeksPojmova(string s){
    mapa indekspojmova;
    int i=0, p(s.size());
    int indeks;
    while(i<p){
        while(i<p&&s[i]==' ') i++;
        if(i>=p) break;
        string word;
        indeks=i;
        while(i<p&&s[i]!=' ') word.push_back(s[i++]);
        indekspojmova[word].insert(indeks);
    }
    return indekspojmova;
}
set<int> PretraziIndeksPojmova(string word, mapa indekspojmova){
    for(auto &x:indekspojmova)
    if(x.first==word) return x.second;
    throw logic_error("Unesena rijec nije nadjena!");
}
void IspisiIndeksPojmova(mapa indekspojmova){
    for(auto &x:indekspojmova){
        cout<<x.first<<": ";
        for(auto z=x.second.begin();;){
            cout<<*z;
            if(++z==x.second.end()) 
            break;
            cout<<",";
        }
        cout<<endl;
    }
}

int main ()
{
    string S;
    cout<<"Unesite tekst: ";
    getline(cin,S);
    auto indekspojmova=KreirajIndeksPojmova(S);
    IspisiIndeksPojmova(indekspojmova);
    for(;;){
        string word;
        cout<<"Unesite rijec: ";
        cin>>word;
        if(word==".") break;
        try{
            auto vektor=PretraziIndeksPojmova(word,indekspojmova);
            for(auto x:vektor) 
            cout<<x<<" ";
            cout<<endl;
        }
        catch(logic_error e){
            cout<<e.what()<<endl;
        }
    }
	return 0;
}