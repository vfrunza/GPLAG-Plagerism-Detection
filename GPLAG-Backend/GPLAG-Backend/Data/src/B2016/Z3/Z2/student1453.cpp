/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <stdexcept>
typedef std::map<std::string,std::set<int>> Objekat;

int BrojSlova(std::string s, int index){
    int brojac(0);
    for(int i=index;i<s.length();i++){
        if((s[i]<'A'&& s[i]>'9') || (s[i]>'Z'&&s[i]<'a') || s[i]>'z' || s[i]<'0') break;
        brojac++;
    }
    return brojac;
}

Objekat KreirajIndeksPojmova(std::string s){
    Objekat mapa;
    for(int i=0;i<s.length();i++){
        if((s[i]<'A'&& s[i]>'9') || (s[i]>'Z'&&s[i]<'a') || s[i]>'z' || s[i]<'0') continue;
        else{
            std::string s2(s.substr(i,BrojSlova(s,i)));
            std::transform(s2.begin(),s2.end(),s2.begin(),::tolower);
            mapa[s2].insert(i);
            i+=BrojSlova(s,i)-1;
        }
    }
    return mapa;
}
std::set<int> PretraziIndeksPojmova(std::string s, Objekat mapa){
    for(auto it=mapa.begin(); it!=mapa.end();it++){
        if(it->first==s) return mapa[it->first];
    } // provjerit moze li pretrazivat sa velikim slovima
    throw std::logic_error("Pojam nije nadjen");
}
void IspisiIndeksPojmova(Objekat mapa){
    for(auto it=mapa.begin();it!=mapa.end();it++){
        std::cout << it->first << ": ";
        int brojac(0);
        for(auto x:mapa[it->first]){
            if(brojac== (mapa[it->first]).size()-1) std::cout<< x;
            else std::cout << x << ",";
            brojac++;
        }
        std::cout<<std::endl;
    }
}
int main (){
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin,s);
    Objekat mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    
    do{
        std::cout<<"Unesite rijec: ";
        std::string s2;
        std::getline(std::cin,s2);
        if(s2==".") break;
        try{
        for(auto x:PretraziIndeksPojmova(s2,mapa)) std::cout << x << " ";
        }
        catch(std::logic_error e){
            std::cout << "Unesena rijec nije nadjena!";
        }
        std::cout<<std::endl;
    }while(1);
    
	return 0;
}