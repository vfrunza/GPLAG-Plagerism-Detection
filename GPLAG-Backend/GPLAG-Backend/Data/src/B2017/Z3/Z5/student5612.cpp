#include <iostream>

enum Boje {
    Pik, Tref, Herc, Karo
};

struct Karta {
    Boje boja;
    std::string vrijednost;
};
¸
struct Cvor {
    Karta karta;
    Cvor *sljedeci;
};
Cvor *KreirajSpil() {
    
}
int main ()
{
    return 0;
}
