/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <map>
#include <string>   
#include <vector>
#include <tuple>

using namespace std;

typedef map<string, vector<string>> Knjiga;

typedef map<string, tuple<string, double, double>> IndeksPojmova;

bool DaLiJeSlovo(string s){
    
    if(s >=48 && s <= 57 || s >= 65 && s <= 90 || s >= 97 && s <= 122) return true;
    
    return false;
}

string PretvoriUMala(string s){
    
    for(int i = 0; i < s.size; i++)
        if(s[i] >= 65 && s[i] <= 90) s[i] = s[i] - ('A' - 'a');
        
    return s;
}

IndeksPojmova KreirajIndeksPojmova(Knjiga k){
    
    for(int i = 0; i < k.first.size(); i++){
        
        if(!DaLiJeSlovo(k.first[i])) do { i++} while(!DaLiJeSlovo(k.first[i]) && i < k.first.size());
    }
    
}
int main ()
{
	return 0;
}
