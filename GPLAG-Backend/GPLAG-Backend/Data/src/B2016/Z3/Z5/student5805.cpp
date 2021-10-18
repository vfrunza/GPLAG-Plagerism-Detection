#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string>v, int m)
{
    if(m<0) throw std::logic_error ("Izuzetak: Razvrstavanje nemoguce");
}

int main ()
{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite imena djece: ";
    std::vector<std::string> v;
    for (int i=0; i!=n+1; i++)
    {
        std::string s;
        std::getline(std::cin, s);
        v.push_back(s);
    }
    std::cout<<std::endl;
    std::cout<<"Unesite broj timova: ";
    int m;
    try{
        std::cin>>m;
        if (m>n) throw std::logic_error ("Izuzetak: Razvrstavanje nemoguce");
        std::vector<std::set<std::string>> k;
        k=Razvrstavanje(v, m);
    }
    catch(std::logic_error izuzetak)
    {
        std::cout<<"Izuzetak: Razvrstavanje nemoguce";
    }
	return 0;
}