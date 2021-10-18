/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <set>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string DajRijec(string s, int x){
    string s1;
    for(int i(x);i<s.length();i++){
        while((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')){s1.push_back(std::tolower(s[i]));i++;}
        if(!((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')))break;
    }
    return s1;
}


std::map<string,std::set<int>> KreirajIndeksPojmova(string s){
    std::map<string,std::set<int>> a;
    
    for(int i(0);i<s.length();i++){
        if(i==(s.length()-1))break;
        while(!((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9'))) {i++;if(i==(s.length()-1))break;}
        if(i==(s.length()-1))break;
        string s1(DajRijec(s,i));
        auto it(a.find(s1));
        if(it==a.end()){
                std::set<int> set1;
                set1.insert(i);
                a.insert(std::make_pair(s1,set1));
            
        }else{
            (it->second).insert(i);
        }
    
        i=i+s1.length();
        if(i==(s.length()-1))break;
    }
    return a;
}
template <typename NekiTip>
void IspisiSet(NekiTip a){
    int br(0);
    for(auto i(a.begin());i!=a.end();i++){
        if(br==(a.size())-1) cout<<*i;
        else
        cout<<*i<<",";
        br++;
    }
}

std::set<int> PretraziIndeksPojmova(string s, std::map<string, std::set<int>> a){
        string s1;
        for(int i(0);i<s.length();i++)
            s1.push_back(std::tolower(s[i]));
        auto it(a.find(s1));
        if(it==a.end()) throw std::logic_error ("Unesena rijec nije nadjena!");
        else return it->second;
}

void IspisiIndeksPojmova(const std::map<string,std::set<int>> &a){
   
    for( auto it = a.begin(); it != a.end(); it++){
         cout << it->first << ": "; 
         IspisiSet(it->second);
         cout<<endl;;
    }

    
}


int main ()
{   
    
    cout<<"Unesite tekst: ";
    string b;
    
    std::getline(cin, b);
    auto c(KreirajIndeksPojmova(b));
    IspisiIndeksPojmova(c);
    string s1;
    string zvr(".");
    do{
        cout<<"Unesite rijec: ";
        std::getline(cin,s1);
        if(s1==zvr) break;
        try{
            auto se(PretraziIndeksPojmova(s1,c));
            for(auto i(se.begin());i!=se.end();i++){
            
            cout<<*i<<" ";
            }
        cout<<endl;
        }catch(std::logic_error e){
            cout<<e.what()<<endl;
        }
        
    }while(s1!=zvr);
    
    
	return 0;
}