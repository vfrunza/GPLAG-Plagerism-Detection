/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>

bool Provera(std::string s)
{
    for(int i(0); i < s.length(); i++)
    {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || 
           (s[i] >= '0' && s[i] <= '9') || s[i] == ' ' || s[i] == '-' || s[i] == 39) continue;
        else return false;
    }
    return true;
}

int main ()
{
    std::string s("'Yđoko-943535545");
    std::cout << Provera(s);
	return 0;
}