/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
enum class Boje{"Pik", "Tref", "Herc", "Karo"};
struct Karta{
    Boje boja;
    std:: string vrijednost;
};
struct Cvor{
    Karta karta;
    Cvor* sljedeci;
};
int main ()
{
	return 0;
}
