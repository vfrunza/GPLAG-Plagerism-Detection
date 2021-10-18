/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
using std::cin;
using std::cout;


std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string tekst){
    std::map<std::string,std::set<int>> mapa;
    int i(0);
    int j(0);
    while(i<tekst.size()){
        while(!((tekst[j]>='A' && teskt[j]<='Z')||(tekst[j]>='a' || tekst[j]<='z')||(teskt[j]>='0' && tekst[j]<='9')) && j<tekst.size())
            j++;
        i=j;
        while((tekst[i]>='A' && teskt[i]<='Z')||(tekst[i]>='a' || tekst[i]<='z')||(teskt[i]>='0' && tekst[i]<='9')) i++;
        
        
    }
}


int main ()
{
	return 0;
}