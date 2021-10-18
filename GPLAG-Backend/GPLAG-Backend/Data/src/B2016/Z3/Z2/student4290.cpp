/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stdexcept>
#include <iterator>
void IspisSkupa1(const std::set<int> &s){
    for(auto i=s.begin();i!=--s.end();i++){
        std::cout<<*i<<",";
    }
    std::cout<<*(s.rbegin());
    std::cout<<std::endl;
}
void IspisSkupa2(const std::set<int> &s){
    for(auto i=s.begin();i!=s.end();i++)
        std::cout<<*i<<" ";
    std::cout<<std::endl;
}
bool SlovoCifra(char c){
    if((c>='a' && c<='z') || (c>='0' && c<='9'))return true;
    return false;
}
std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string,std::set<int>> index;
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z')s[i]+=32;
    }
    for(int i=0;i<s.size();i++){
        if(SlovoCifra(s[i])){
            int p=i;
            while(i<s.size() && SlovoCifra(s[i]))i++;
            int k=i;
            index[s.substr(p,k-p)].insert(p);
        }
    }
    return index;
}
std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>> index){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z')s[i]+=32;
    }
    auto it(index.find(s));
    if(it==index.end())throw std::logic_error("Pojam nije nadjen");
    else return it->second;
}
void IspisiIndeksPojmova(const std::map<std::string,std::set<int>> &index){
    for(auto i=index.begin();i!=index.end();i++){
        std::cout<<i->first<<": ";
        IspisSkupa1(i->second);
    }
}
int main (){
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,s);
    std::map<std::string,std::set<int>> index=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(index);
    std::string rijec;
    while(rijec!=std::string(".")){
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        if(rijec==std::string("."))break;
        try{
            IspisSkupa2(PretraziIndeksPojmova(rijec,index));
        }
        catch(...){
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
	return 0;
}