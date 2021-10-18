/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <stdexcept>

    using std::cout;
    using std::cin;
    using std::endl;
    
    void PretvoriUMala(std::string &s){
        for(int i=0; i<s.length(); i++){
            if(s[i]>='A' && s[i]<='Z') s[i] += 'a'-'A';
        }
    }
    
    void Ispisi(std::set<int>skup){
        for(auto it = skup.begin(); it != skup.end(); it++){
            auto pom(it);
            pom++;
            if(pom == skup.end()) std::cout<<*it;
            else std::cout<<*it<<",";
        }
    }
    
    bool JesteSlovo(char s){
        if((s >='a' && s <='z') || (s >='A' && s <='Z') || (s >='0' && s<='9')) 
            return true;
        return false;
    }
    
    std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
        std::map<std::string,std::set<int>> mapa;
       /* std::vector<std::string>rijeci;
        PretvoriUMala(s);
        
        int pomocna(0);
        for(int i=0; i<s.length(); i++){
            if(!JesteSlovo(s[i])){
                rijeci.push_back(s.substr(pomocna, i-pomocna));
                pomocna = i+1;
            }
        }
        rijeci.push_back(s.substr(pomocna,s.length()-pomocna));
        
        //if(rijeci[0]==s.substr(rijeci[i].size()) && (!JesteSlovo(s[rijeci[0].size()])))
        
        for(int i=0; i<rijeci.size(); i++){
            std::set<int>skup;
            for(int j=0; j<s.length(); j++)
                if(j == 0 && rijeci[i]==s.substr(j,rijeci[i].size()) && (!JesteSlovo(s[j+rijeci[i].size()]))) skup.insert(j);
                else if(j>0 && rijeci[i]==s.substr(j,rijeci[i].size()) && (!JesteSlovo(s[j+rijeci[i].size()]))  && (!JesteSlovo(s[j-1])))
                    skup.insert(j);
            pojmovi.insert(std::make_pair(rijeci[i],skup));
            }
        
        */
        PretvoriUMala(s);
        int brojac(0),pomocna(0);
        std::string str;
        for(int i = 0; i<s.length(); i++){
            if(JesteSlovo(s[i])){
                brojac++;
                int j=i;
                while ((JesteSlovo(s[j]) && j<s.length())) j++; 
                if(brojac > 0){
                    pomocna +=i;
                    str = s.substr(i,j-i);
                    auto it(mapa.find(str));
                    if(it == mapa.end()){
                        std::set<int>skup;
                        skup.insert(pomocna);
                        mapa.insert(std::make_pair(str,skup));
                    }
                    else{
                        auto it(mapa.find(str));
                        it->second.insert(pomocna);
                    }
                    i = j;
                    pomocna = 0;
                }
            }
        }
        return mapa;
    }
    
    std::set<int> PretraziIndeksPojmova(const std::string p, std::map<std::string,std::set<int>>mapa){
        std::set<int>skup;
        auto trazi(mapa.find(p));
        if(trazi == mapa.end())
            throw std::logic_error("Pojam nije nadjen");
        for(auto x : trazi->second) skup.insert(x);
            return skup;
        
    }
    
    void IspisiIndeksPojmova(std::map<std::string,std::set<int>>pojmovi){
        for(auto it = pojmovi.begin(); it != pojmovi.end(); it++){
            cout<<it->first<<": ";
            Ispisi(it->second);
            cout<<endl;
        }
        
    }
    
int main (){
    cout<<"Unesite tekst: ";
    std::string unos;
    std::getline(cin,unos);
    auto p = KreirajIndeksPojmova(unos);
    IspisiIndeksPojmova(p);
    for(;;){
        std::string rijec;
        cout<<"Unesite rijec: ";
        std::getline(cin,rijec);
        if(rijec == ".") break;
        try{
            auto skup = PretraziIndeksPojmova(rijec,p);
            for(int x : skup) cout<<x<<" ";
            cout<<endl;
        }
        catch(std::logic_error){
            cout<<"Unesena rijec nije nadjena!"<<endl;
        }
    }

    /*auto m = KreirajIndeksPojmova("cvbkn34m5.n,34r67fgudbsc$%&/I()HVBNBn/&/&n///z&asdb23rgf87baew bfcQN3RCG3BR83O4NZTH");
    IspisiIndeksPojmova(m);
    auto skup = PretraziIndeksPojmova("n", m);
    for (const auto &c : skup) std::cout << c << " ";*/

	return 0;
}
