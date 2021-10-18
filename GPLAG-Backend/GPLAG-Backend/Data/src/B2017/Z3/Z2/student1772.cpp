#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

typedef map<string,vector<string>> Knjiga;

map<string,set<tuple<string,int,int>>> KreirajIndeksPojmova(Knjiga k){
    
}

PretraziIndeksPojmova(string str,map<string,set<tuple<string,int,int>>> indeksPojmova){
    
}

void IspisiIndeksPojmova(map<string,set<tuple<string,int,int>>> indexPojmova){
    
}

int main()
{
    string nazivPoglavlja;
    getline(cin,nazivPoglavlja);
    for(;;) {
        cout<<"Unesite naziv poglavlja: ";
        string nazivPoglavlja;
        getline(cin,nazivPoglavlja);
        cin.ignore(1000,'\n');
        if(nazivPoglavlja=='.')break;
        for(int i(0);; i++) {
            cout<<"Unesite sadrzaj stranice "<<i+1<<": ";
            string sadrzajStranice;
            getline(cin,sadrzajStranice);
            cin.ignore(1000,'\n');
            if(sadrzajStranice=='.')break;
            
        }
    }
    return 0;
}