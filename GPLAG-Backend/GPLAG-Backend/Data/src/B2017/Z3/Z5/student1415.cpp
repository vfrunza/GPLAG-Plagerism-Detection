/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>

int main ()
{
	return 0;
}

void VratiPrvihNKarata (Spil &karte, RedParova &red, int n)
{
if (n > red.size()) throw std::range_error("Nedovoljno karata u redu!");
if(n < 1) throw std::domain_error ("Broj n je besmislen!");

    for(int i = 0; i < n; i++) {
        karte.insert(std::make_pair(Boje(fin),red.pop().second), std::find_if (karte.begin(), karte.end(), [red](std::pair<Boje,std::string> x) {
            auto y (red.pop());
            std::vector<std::string> NaziviBojaKarata {"Pik", "Tref", "Herc", "Karo"};
            std::vector<std::string> moguce { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
            return (int(x.first) < (find(NaziviBojaKarata.begin(), NaziviBojaKarata.end(), y.first) - NaziviBojaKarata.begin()) &&
                    x.second < (find(moguce.begin(), moguce.end(), y.second) - moguce.begin()));

        });
    }
}