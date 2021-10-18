/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stdexcept>

bool DaLiJeSlovoIliCifra (char znak){
    return ((znak>='a' && znak<='z') || (znak>='A' && znak<='Z') || (znak>='0' && znak<='9'));
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (const std::string &str){
    std::string s(str);
    for(int i=0; i<s.length(); i++)
      if(s[i]>='A' && s[i]<='Z')
        s[i]+='a' - 'A';
    std::map<std::string, std::set<int>> mapa;
    for(int i=0; i<s.length(); i++){
        if(DaLiJeSlovoIliCifra(s[i]) && (i==0 || !DaLiJeSlovoIliCifra(s[i-1]))){
            int poc(i), pok(i), kraj(i);
            while(i<s.length() && DaLiJeSlovoIliCifra(s[i]))
              i++;
            if(i==s.length() || !DaLiJeSlovoIliCifra(s[i])){
                kraj = i;
                std::string pomocni;
                while(poc!=kraj){
                    pomocni.push_back(s[poc]);
                    poc++;
                }
                poc = pok;
                for(int c=0; c<pomocni.length(); c++){
                    if(pomocni[c]>='A' && pomocni[c]<='Z')
                       pomocni[c]+=32;
                }
                auto it(mapa.find(pomocni));
                if(it==mapa.end()){
                    std::set<int> skup;
                    
                    skup.insert(poc);
                   
                    mapa.insert(std::make_pair(pomocni, skup));
                }
                else{
                    it->second.insert(poc);
                }
            }
        }
    }
return mapa;
}

std::set<int> PretraziIndeksPojmova (const std::string &str, const std::map<std::string, std::set<int>> &mapa){
    std::string s(str);
    for(auto &x : s){
        if(x>='A' && x<='Z')
          x+='a' - 'A';
    }
    auto it(mapa.find(s));
    if(it==mapa.end())
      throw std::logic_error ("Pojam nije nadjen");
    return it->second;
}

void IspisiIndeksPojmova (const std::map<std::string, std::set<int>> &mapa){
    for(auto it= mapa.begin(); it!=mapa.end(); it++){
        std::cout<<it->first<<": ";
        auto q(it->second.end());
        q--;
        for(auto p = it->second.begin(); p!=it->second.end(); p++){
            std::cout<<*p;
            if(p!=q)
              std::cout<<",";
        }
        std::cout<<std::endl;
    }
}


int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    auto mapa = KreirajIndeksPojmova(s);
	IspisiIndeksPojmova(mapa);
	std::string rijec;
	do{
	    std::cout<<"Unesite rijec: ";
	    std::getline(std::cin, rijec);
	    if(rijec==".") break;
	    try{
	        auto s(PretraziIndeksPojmova(rijec, mapa));
	        for(auto p = s.begin(); p!=s.end(); p++)
	          std::cout<<*p<<" ";
	    }
	    catch(std::logic_error e){
	        std::cout<<"Unesena rijec nije nadjena!";
	    }
	    std::cout<<std::endl;
	}while(rijec!=".");
	return 0;
}