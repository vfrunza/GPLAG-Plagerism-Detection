#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>

using namespace std;

void IspisiIndeksPojmova(map <string, set<int>> index) {
    for(auto x: index) {
        cout<<x.first<<": ";
        int br=0, vel=distance(x.second.begin(),x.second.end());
        for(auto y: x.second) {
            br++;
            if(br==vel) cout<<y;
            else cout<<y<<",";
        }
        cout<<"\n";
    }
}

set <int> PretraziIndeksPojmova(string rijec, map<string, set<int>> index) {
    if(!index.count(rijec)) throw logic_error("Unesena rijec nije nadjena!");
    return index[rijec];
}

map<string, set<int>> KreirajIndeksPojmova(string text) {
    map<string, set<int>> indexPojmova;
    set<int>pocetak {};
    for(int i=0;i<text.size();i++) {
        string temp=string();
        while(i!=text.size() && text[i]==' ') i++;
        int indeks=i;
        while(i!=text.size() && text[i]!=' ') {
            temp=temp+text[i];
            i++;
        }
        if(!indexPojmova.count(temp))indexPojmova.insert(make_pair(temp,pocetak));
        indexPojmova[temp].insert(indeks);
    }
    return indexPojmova;
}

int main() {
    cout<<"Unesite tekst: ";
    string text;
    getline(cin, text);
    IspisiIndeksPojmova(KreirajIndeksPojmova(text));
    while(1) {
        cout<<"Unesite rijec: ";
        string rijec;
        cin>>rijec;
        if(rijec==".")break;
        try{
            set<int>S=PretraziIndeksPojmova(rijec, KreirajIndeksPojmova(text));
            int br=0, vel=distance(S.begin(), S.end());
            for(auto x: S) {
                br++;
                if(br==vel) cout<<x;
                else cout<<x<<" ";
            }
            cout<<"\n";
        }
        catch (logic_error izuzetak) {
            cout<<izuzetak.what();
            cout<<"\n";
        }
    }
    return 0;
}