#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>
std::list<std::string> VektorUListu(const std::vector<std::string> &v){
    std::list<std::string> lista;
    for(int i=0;i<v.size();i++)lista.push_back(v[i]);
    return lista;
}
int DuzinaString(std::string s){
    int br(0);
    for(int i=0;i<s.length();i++)if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9'))br++;
    return br;
}
std::vector<std::set<std::string>> Razvrstavanje(const std::vector<std::string> &v,int k){
    if(k<0 && k>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista(VektorUListu(v));
    std::vector<std::set<std::string>> timovi(k);
    auto it=lista.begin();
    timovi[0].insert(*it);
    int s(DuzinaString(*(lista.begin())));
    it=lista.erase(it);
    for(int l=0;l<k;){
        for(int j=0;j<s;j++){
            if(it==lista.end()){
                it=lista.begin();
                j--;
            }
            it++;
        } 
        timovi[l].insert(*it);
        s=DuzinaString(*it);
        it=lista.erase(it);
        if(l<v.size()%k)if(timovi[l].size()==(v.size()%k+1))l++;
        else if(l>=v.size()%k && l<v.size())if(timovi[l].size()==v.size()%k)l++;
    }    
    return timovi;
}
void Ispisi(const std::vector<std::set<std::string>> &v){
    for(int i=0;i<v.size();i++){
        std::cout<<"Tim "<<i+1<<": ";
        for(auto j=v[i].begin();j!=--v[i].end();j++)std::cout<<*j<<" ,";
        std::cout<<*(--v[i].end())<<std::endl;
    }
}
int main (){
    try{
        std::cout<<"Unesite broj djece: ";
        int br;
        std::cin>>br;
        std::vector<std::string> v(br);
        std::cin.ignore(100,'\n');
        std::cout<<"Unesite imena djece: ";
        for(int i=0;i<br;i++)
            std::getline(std::cin,v[i]);
    
        std::cout<<"Unesite broj timova: ";
        std::cin>>br;
        std::vector<std::set<std::string>> s=Razvrstavanje(v,br);
        Ispisi(s);
    }
    catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}