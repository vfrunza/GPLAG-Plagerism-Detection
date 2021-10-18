/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
int main ()
{
    int n;
    std::cout << "Unesite broj djece: ";
    std::cin >> n;
    std::string s;
    std::cout << "Unesite imena djece: \n";
    do
    {
        std::getline(std::cin, s);
    }while (n);
	return 0;
}