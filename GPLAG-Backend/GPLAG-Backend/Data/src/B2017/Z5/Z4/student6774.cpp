/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include<memory>

int main ()
{
    auto d=std::make_shared<int>(5);
    auto e=d.get();
    if(d.get()==e)std::cout << "rekt" << std::endl;
    
    std::shared_ptr<int> c=d;
    std::cout << *c << std::endl;
	return 0;
}
