/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cctype>
#include <stdexcept>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::string;
using std::make_pair;
using std::logic_error;
using std::vector;



set<int> PretraziIndeksPojmova(string rijec, map<string, set<int>> IndexPojmova){
        for(char x : rijec) x=tolower(x);
        if(!IndexPojmova.count(rijec)) throw logic_error ("Pojam nije nadjen");
        else return IndexPojmova[rijec];
}


void IspisiIndeksPojmova(map<string,set<int>> IndexPojmova){
 
    for(auto i:IndexPojmova){
       // if(i.first.empty() ) continue;
        cout<< i.first << ": ";
        int b = i.second.size();
        int brojac = 0;
        for(auto j: i.second){
            cout << j;
            if(brojac != b - 1)
            cout << ',';
            brojac++;
            
        }
        cout<<endl;
        
    }

}

map<string,set<int>> KreirajIndeksPojmova(string tekst){
            vector<string> temp;
            vector<int> tempp;
            string temp1;
            
            for(auto &x : tekst) x=tolower(x); //treba referenca na x jer se nece mijenjat string
            
            for(int i=0; i<tekst.length(); i++){
                int brojac=0;
                while ( (i<tekst.length()) && ((tekst[i]>='0' && tekst[i]<='9') || (tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='A' && tekst[i]<='Z')) ){
                    brojac++;
                    i++;
                }
                    
                temp1=tekst.substr(i-brojac, brojac);
                temp.push_back(temp1);
                tempp.push_back(abs(i-temp1.length()));
            }
            vector<set<int>> brojpon(temp.size()); 
            
            for(int i=0;i<temp.size();i++){    //nema -1 kod temp.size
                brojpon[i].insert(tempp[i]);
                for(int j=i+1;j<temp.size();j++){
                    if(temp[i]==temp[j]){
                        brojpon[i].insert(tempp[j]);
                        temp.erase(temp.begin()+j);
                        tempp.erase(tempp.begin()+j);
                        j--;
                    }
                }
            }
            
            map<string,set<int>> IndexPojmova;
        
            for(int i=0; i<temp.size(); i++){           
                if (temp[i].empty()) i++;//nema -1 kod temp.size
                else IndexPojmova.insert(make_pair(temp[i], brojpon[i]));
            }
    
    return IndexPojmova;
}


int main (){
 
     
        cout<<"Unesite tekst: ";
        string tekst;
        getline(cin,tekst);
        auto IndexPojmova=KreirajIndeksPojmova(tekst);
        IspisiIndeksPojmova(IndexPojmova);
        string rijec;
        cout<<endl;
        while(1){
        cout<<"Unesite rijec: ";
        try{
        getline(cin,rijec);
        if(rijec==".") return 0;
        
        set <int> sets=PretraziIndeksPojmova(rijec, IndexPojmova);
        for(auto x: sets)cout<<x<<" ";
        cout<<endl;
        }catch(logic_error h){
            cout<<"Unesena rijec nije nadjena!"<<endl;
        }
    }
    
   
    
	return 0;
}