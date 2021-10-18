/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>

enum class Boje {Pik, Tref, Herc, Karo};
int main ()
{
    std::string rijec(std::string(Boje::Pik));
    std::cout<<"Prvi element je: "<< rijec;
	return 0;
}
