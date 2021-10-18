#include <iostream>
#include<map>
#include<set>
#include<stdexcept>
using std::endl;
using std::logic_error;
using std::cin;
using std::cout;
using std::string;
using std::set;
using std::map;


map<string,set<int>> KreirajIndeksPojmova(string s)
{
    map<string,set<int>> mapa;
    

    
    for(int i=0; i<s.size(); i++) {
        int k=0;
        string pom;
        if(i<s.size() && ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))){
        while(i<s.size() && ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))) {
            if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+'a'-'A';
            pom.push_back(s[i]);
            i++;
        }
        k=i-pom.size();
        
        set<int> skup;
        if(!mapa.count(pom)) mapa[pom].insert(k);
        else {
            for(auto it=mapa.begin(); it!=mapa.end(); it++) {
                if(pom==(it->first)) (it->second).insert(k);
                
            }
        }
        }
    while(i<s.size() && s[i]<'A' && s[i]>'Z' && s[i]<'a' && s[i]>'z' && s[i]<'1' && s[i]>'9') i++;

    }
    
    return mapa;
}

set<int> PretraziIndeksPojmova(string pom, map<string,set<int>> mapa){
    for(int i=0;i<pom.size();i++)
        if(pom[i]>='A' && pom[i]<='Z') pom[i]=pom[i]+'a'-'A';
    
    set<int> skup;
    int brojac=0;
    for(auto it=mapa.begin();it!=mapa.end();it++){
        if(pom==it->first) brojac++;
    }
    if(!brojac) throw logic_error("Pojam nije nadjen");
    
    for(auto it=mapa.begin();it!=mapa.end();it++){
        if(pom==it->first) return it->second;
    }
    
    
}

void IspisiIndeksPojmova(map<string, set<int>> mapa){
    
    for(auto it=mapa.begin();it!=mapa.end();it++){
        cout<<it->first<<": ";
        auto itt=(it->second).begin();
        for(int i=0;i<distance((it->second).begin(),(it->second).end())-1;i++){ cout<<*itt<<",";itt++;}
        cout<<*itt;
        cout<<endl;
    }
    
}

int main ()
{
    string s;
    cout<<"Unesite tekst: ";
    getline(cin, s);
    IspisiIndeksPojmova(KreirajIndeksPojmova(s));
    for(;;){
        cout<<"Unesite rijec: ";
        string s1;
        getline(cin, s1);
        if(s1==".") break;
        try{
        auto skup=PretraziIndeksPojmova(s1, KreirajIndeksPojmova(s));
        auto it=skup.begin();
        for(int i=0;i<distance(skup.begin(), skup.end())-1;i++){ cout<<*it<<" ";
        it++;
        }
        cout<<*it;
        
        cout<<endl;
        }
        catch(logic_error izuzetak){
            cout<<"Unesena rijec nije nadjena!"<<endl;
        }
        
    }
    return 0;
}