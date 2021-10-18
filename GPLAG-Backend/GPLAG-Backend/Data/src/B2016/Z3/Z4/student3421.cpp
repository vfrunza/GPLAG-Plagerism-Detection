/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<string> djeca, int br_timova)
{
    if(br_timova < 1 || br_timova > djeca.size())
       throw std::logic_error("Razvrstavanje nemoguce");
       
    std::list<std::string> imena;
    std::vector<std::set<std::string>> nova(br_timova);
    for(int i = 0; i < djeca.size(); i++)
       imena.push_back(djeca.at(i));
    auto it = imena.begin();
    nova.push_back(djeca[0]);
    while(it != imena.end())
    {
        
    }
}
int main ()
{
	return 0;
}