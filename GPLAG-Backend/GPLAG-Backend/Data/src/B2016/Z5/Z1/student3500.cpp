/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
int main ()
{
    
    int n;
    //std::cin>>n;
    std::vector<int> v;
    n=60*90*84*96;
    for(int i(1);i<=n;i++){
        v.push_back(i);
    }
    for(auto a:v) std::cout<<a<<std::endl;
	return 0;
}