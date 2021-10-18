#include <iostream>
#include <vector>
#include <stdexcept>
#include <new>
#include <iomanip>
#include <algorithm>

template <typename Tip1, typename Tip2>
bool ProstiFaktori(Tip1* prviBlok, Tip2* drugiBlok) {
    
}

template <typename Tip1, typename Tip2, typename Tip3>
Tip3 ProstiFaktori1(Tip1 prviBlok, Tip2 drugiBlok) {
    return 3;
}
template <typename Tip1, typename Tip2, typename Tip3>
void SortirajPodrucjeVrijednosti(Tip1* pocetak, Tip1* kraj, Tip2* p2, Tip3* p3, Tip3 (*f)(Tip1, Tip2), bool (*funkcija)(Tip1*, Tip2*)) {
    funkcija(pocetak, p2);
}


int main ()
{
    int *p, *p1, *p2, *p3;
    SortirajPodrucjeVrijednosti(p, p1, p2, p3, ProstiFaktori1, ProstiFaktori);
	return 0;
}