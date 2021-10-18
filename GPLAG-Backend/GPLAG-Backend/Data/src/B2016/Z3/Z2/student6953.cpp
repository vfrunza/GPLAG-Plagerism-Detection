#include<iostream>
#include<string>
#include<map>  
#include<set>
std::map<std::string, std::set<int>>KreirajIndeksPojmova(std::string s){
    for(int i=0; i<s.length(); i++) {
        if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+32;
    }
    std::map<std::string, std::set<int>>mapa;
    for(int i=0; i<s.length(); i++) {
        std::string rijec;
        std::set<int> skup;
        if(((s[i]>='a' && s[i]<='z')|| (s[i]>='0' && s[i]<='9')) && (i==0 || !((s[i-1]>='a' && s[i-1]<='z')|| (s[i-1]>='0' && s[i-1]<='9')))) {
            int poc=i;
            skup.insert(i);
            while(((s[i]>='a' && s[i]<='z')|| (s[i]>='0' && s[i]<='9'))&& i!=s.length()) {
                rijec.push_back(s[i]);
                i++;
            }
            for(auto it=mapa.begin(); it!=mapa.end(); it++) {
                if(it->first==rijec) (it->second).insert(i-rijec.length());
            }
            mapa.insert(std::make_pair(rijec, skup));
            i=poc+rijec.length();
        }
    }
    return mapa;
}
std::set<int>PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa){
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        if(s==it->first) return it->second;
    }
    throw std::logic_error("Pojam nije nadjen");
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa)
{
    for (auto  it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout<<it->first<<": ";
        auto it1=(it->second).begin();
        while(it1!=(it->second).end()) {
            if(it1==--(it->second).end()) break;
            std::cout << *it1 << ",";
            it1++;
        }
        std::cout << *it1;
        std::cout<<std::endl;
    }
}
int main (){
    std::cout<<"Unesite tekst: "; 
    std::string s; 
    std::getline(std::cin, s); 
    std::map<std::string, std::set<int>> mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    for(;;) {
        std::cout<<"Unesite rijec: ";
        std::string k;
        std::getline(std::cin, k);
        if(k==".") break;
        try {
            std::set<int> rez=PretraziIndeksPojmova(k, mapa);
            for(int x: rez) std::cout<<x<<" ";
            std::cout<<std::endl;
        } 
        catch(std::logic_error) {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
    return 0;
}