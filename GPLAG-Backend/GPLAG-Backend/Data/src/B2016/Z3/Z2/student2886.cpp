#include <iostream>
#include<map>
#include<string>
#include<iterator>
#include<algorithm>
#include<stdexcept>
#include<set>
#include<vector>
bool DaLiJeSlovo(char znak){
    if((znak>='A'&&znak<='Z')||(znak>='a'&&znak<='z'))
    return true;
    else
    return false;
}
bool DaLiJeCifra(char znak){
    if((znak>='0'&&znak<='9'))
    return true;
    else
    return false;
}
std::string PromijeniUMalaSlova(std::string s){
    for(int i=0;i<s.size();i++)
    if(s[i]<='Z'&&s[i]>='A')
    s[i]=s[i]+32;
    return s;
}
std::map<std::string,std::set<int>>KreirajIndeksPojmova(std::string tekst){
    std::string::iterator it1(tekst.begin());
     std::string::iterator it2(tekst.begin());
     std::string s;
     int i=0;
    std::map<std::string,std::set<int>>IndeksPojmova;
    while(it1!=tekst.end()&&it2!=tekst.end()){
    while((!DaLiJeSlovo(*it1)&&!DaLiJeCifra(*it1))&&it1!=tekst.end())
    it1++;
    it2=it1;
    while((DaLiJeSlovo(*it2)||DaLiJeCifra(*it2))&&it2!=tekst.end())
    it2++;
    s.resize(it2-it1);
    std::copy(it1,it2,s.begin());
    s=PromijeniUMalaSlova(s);
    i=it1-tekst.begin();
    IndeksPojmova.insert(std::make_pair(s,std::set<int>()));
    IndeksPojmova[s].insert(i);
    it1=it2;
    }
    return IndeksPojmova;
}
std::set<int>PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>>IndeksPojmova){
    if(!IndeksPojmova.count(s)) throw std::logic_error("Unesena rijec nije nadjena!");
    return IndeksPojmova[s];
}
void IspisiSet(std::set<int> s){
    for(int x : s)
   std::cout<<x<<" "; 
}
void IspisiIndeksPojmova(std::map<std::string,std::set<int>>IndeksPojmova){
    for(auto it =IndeksPojmova.begin(); it !=IndeksPojmova.end(); it++){
 std::cout << it->first <<": ";
 int logicka=1;
for(int x : it->second){
    if(logicka){
        logicka=0;
std::cout<<x; }
else
   std::cout<<","<<x; 
}
std::cout<<std::endl;}
}
int main ()
{
    std::string s;
    std::string s1;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,s);
    std::map<std::string,std::set<int>>IndeksPojmova(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(IndeksPojmova);
     std::cout<<"Unesite rijec: ";
    std::getline(std::cin,s1);
    while(s1!="."){
        if(s1==".")break;
        try{
        IspisiSet(PretraziIndeksPojmova(s1,IndeksPojmova));}
        catch(std::logic_error izuzetak){
            std::cout<<izuzetak.what();
        }
        std::cout<<std::endl;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,s1);
        }
	return 0;
}