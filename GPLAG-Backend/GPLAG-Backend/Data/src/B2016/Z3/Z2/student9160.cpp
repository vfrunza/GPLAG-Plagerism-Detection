/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using std::cin;
using std::cout;
bool DioRijeci(const char c)
{
    if((c>='a' && c<='z')||(c>='A' && c<='Z')||(0<=c && c<=9)||c=='?'||c=='!'||c=='.')return true;
    return false;
}
std::map<std::string,std::set<int>>KreirajIndeksPojmova(std::string s)
{
    std::map<std::string,std::set<int>> mapa;
    std::vector<std::string> rijeci;
    //trazimo rijeci
    for(int i(0);i<s.length();i++)
    {
        std::string pomocni;
        while(DioRijeci(s.at(i)))
        {
            pomocni.push_back(s.at(i));
            if(i==s.length()-1)break;
            i++;
        }
        rijeci.push_back(pomocni);
    }
 /*   for(int i(0);i<rijeci.size();i++) {
        std::set<int>skup_indexa;
        for(int j(0);j<rijeci.size();j++)
        {
            if(j==i)continue;
            if(s.at(j)==s.at(i))skup_indexa.insert(j+1);
        }
        mapa.insert(std::make_pair(rijeci.at(i),skup_indexa));
    }*/
    for(int i(0);i<rijeci.size();i++)
    {
        //neam pojma kako ovo
    }
    
    return mapa;
}
int main ()
{
   /* cout<<"Unesite tekst: ";
    std::string s;
    cin.ignore(10,'\n');
    std::getline(cin,s);
    auto mapa(KreirajIndeksPojmova(s));
    for(auto it(mapa.begin());it!=mapa.end();it++)
    {
        cout<<it->first<<": ";
        //for(auto x : it)cout;
        cout<<std::endl;
    }*/
    //at 5
     std::map<std::string, std::set<int>> m = KreirajIndeksPojmova("abc cde def ghi ghi def cde abc");
    for (const auto &i : m)
    {
     
        std::cout << i.first<<" ";
           for (const auto &j : i.second)
            std::cout << j << " ";
        std::cout<<std::endl;    
    }
	return 0;
}