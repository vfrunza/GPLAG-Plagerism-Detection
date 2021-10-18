#include <iostream>
#include <map>
#include <string>   
#include <vector>
#include <tuple>

using namespace std;

typedef map<string, vector<string>> Knjiga;

typedef multimap<string, tuple<string, int, int>> IndeksPojmova;

typedef vector<tuple <string,int,int>> VT;

bool DaLiJeSlovo(char s){
    
    if((s >=48 && s <= 57) || (s >= 65 && s <= 90) || (s >= 97 && s <= 122)) return true;
    
    return false;
}

void PretvoriUMala(string &s){
    
    for(int i = 0; i < s.size(); i++)
        if(s[i] >= 65 && s[i] <= 90) s[i] = s[i] - ('A' - 'a');
    
}



IndeksPojmova KreirajIndeksPojmova(Knjiga k){
    
    auto it = k.begin();
    
    IndeksPojmova ind;
    
    
    if(it == k.end()) return ind;
    
    for(int i = 0; i < it->second.size(); i++){
        
        PretvoriUMala(it->second[i]);
        
        for(int j = 0; j < it->second[i].size(); j++){
        
            if(!DaLiJeSlovo(it->second[i][j])) 
                do {
                    j++; 
                } while(!DaLiJeSlovo(it->second[i][j]) && j < it->second[i].size());
        
            if(DaLiJeSlovo(it->second[i][j])) { 
            
                string rijec;
                int br(0);
            
                do {
                    rijec.push_back(it->second[i][j]); br++; j++; 
                } while(DaLiJeSlovo(it->second[i][j]) && j < it->second[i].size()); 
        
                tuple <string, int, int> t{it->first, i + 1, j - br};
                ind.insert({rijec,t});
            
            }
        }
    }
    
    return ind;
    
}

void IspisiIndeksPojmova(IndeksPojmova i){
    
    vector <string> ispisane;
    
    for(auto it = i.begin(); it != i.end();it++ ){
        bool a(false);
        
        for(int k = 0; k < ispisane.size(); k++)
            if(ispisane[k] == it->first) a=true;
            
        if(a == false){
            cout<<it->first<<": "<<get<0>(it->second)<<"/"<<get<1>(it->second)<<"/"<<get<2>(it->second);
            ispisane.push_back(it->first);
            it++;
            if(it == i.end()) { cout<<endl; break; }
            
            auto it1 = it;
            it--;
            
            if(it1->first == it->first)
                while(1){
                    cout<<", "<<get<0>(it1->second)<<"/"<<get<1>(it1->second)<<"/"<<get<2>(it1->second);
                    it1++;
                    if(it1 == i.end() || it1->first != it->first) break; 
                }
            
            cout<<endl;
        }
    }
}

VT PretraziIndeksPojmova(string s, IndeksPojmova ind){
    
    VT t;
    
    for(auto it = ind.begin(); it != ind.end(); it++)
        if(s == it->first) {
            tuple<string,int,int> temp{get<0>(it->second), get<1>(it->second), get<2>(it->second)};
            t.push_back(temp);
        }
        
    if(t.size() == 0) throw logic_error("Unesena rijec nije nadjena!");
    
    return t;
}


int main ()
{
    
    Knjiga k;
    
    do{
        cout<<"Unesite naziv poglavlja: ";
    
        string p;
    
        getline(cin,p);
        if(p == ".") break;
    
        vector<string> rijeci;
    
        for(int i = 1;;i++){
        
            string rijec;
            cout<<"Unesite sadrzaj stranice "<<i<<": "; 
            getline(cin,rijec);
        
            if(rijec == ".") break;
        
            rijeci.push_back(rijec);    
        
        }
    
        k.insert({p,rijeci});
    
    } while(1);
    
    IndeksPojmova ind;
    ind = KreirajIndeksPojmova(k);
    
    cout<<endl<<"Kreirani indeks pojmova:"<<endl;
    IspisiIndeksPojmova(ind);
    
    while(1){
        string rijec;
        cout<<"Unesite rijec: ";    
        getline(cin, rijec);
        
        if(rijec == ".") break;
    
        try{
            VT t = PretraziIndeksPojmova(rijec, ind);
        
            for(int i = 0; i < t.size();i++)
                cout<<get<0>(t[i])<<"/"<<get<1>(t[i])<<"/"<<get<2>(t[i])<<" ";
        
            cout<<endl;
        }
        catch(logic_error e){
         
            cout<<e.what()<<endl;
        }
    
    }
    
	return 0;
}

