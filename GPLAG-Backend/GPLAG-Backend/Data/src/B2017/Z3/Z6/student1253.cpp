/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <map>
#include <tuple>
#include <functional>
#include <utility>

int main ()
{
    /*std::multimap<int, int> m;
    m.insert({1, 1});
    m.insert({2, 4});
    m.insert({3, 9});
    auto it(m.begin());
    m.erase(it);
    std::cout<<it->first<<" ";
    for(auto i = m.begin(); i!=m.end(); i++) std::cout<<i->first<<" ";*/
    /*std::tuple<int, int, int> t;
    std::get<0>(t) = 1;
    std::get<1>(t) = 1;
    std::get<2>(t) = 1;
    std::cout<<std::get<0>(t);
    */
    /*std::map<int, int> mapa;
    
    mapa.insert({2,3});
    auto it3(mapa.begin());
    std::cout<<(*it3).second;
    std::function<int(int)> f([](int x){return x*2;});
    std::cout<<"\n"<<f(2); */
    std::multimap<std::string, int> mm;
    mm.insert({"tref",3});
    mm.insert({"herc",5});
    mm.insert({"pik",3});
    mm.insert({"karo",6});
    mm.insert({"herc", 5});
    /*std::string s("karo");
    int broj(6);*/
    auto it3(mm.find("karo"));
    if(it3==mm.end()) std::cout<<"uslo";
    while(it3!=mm.end()) {
        mm.erase(it3);
        it3 = mm.find("karo");
    }

    for(auto it= mm.begin(); it!=mm.end(); it++) {
        std::cout<<it->first<<" ";
        std::cout<<it->second<<" -";
    }
    
	return 0;
}
