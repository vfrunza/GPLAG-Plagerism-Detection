/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <set>
#include <utility>
using namespace std;

map<string,set<int>> KreirajIndeksPojmova(string &tekst){
    string novi(tekst);
    map<string,set<int>> ipojmovi;
    set<int> indeks;
    int ind(0);
    for(int i(0);i<tekst.size();i++){
        tekst[i]=tolower(tekst[i]);
            while((tekst[i]>'a' and tekst[i]<'z') or (tekst[i]>'0' and tekst[i]<'9')){
                string podstr=tekst.substr(ind,i-ind);
                
                ind=i+1;
            }
        }
    }
    
    
}
int main ()
{
	return 0;
}