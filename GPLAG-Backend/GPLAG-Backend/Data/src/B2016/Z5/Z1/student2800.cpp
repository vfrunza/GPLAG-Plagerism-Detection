/B16/17 (Zadaća 5, Zadatak 1)
//Autostudent2800ovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autostudent2800ove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>

using namespace std;

template<typename Tip>
class Genericka {
    private:
        Tip privatni;
        string ime;
    public:
        Genericka(string ime) : ime(ime) { cout << "gello "<<ime<<endl; }
    
        template<typename Tip2>
        Genericka(const Genericka<Tip2>& k) {
            ime = k.ime;
            cout << "povezujem "<<k.privatni;
        }
        
        Tip dajPrivatni() const { return privatni; }
        void postaviPrivatni(Tip p) { privatni = p; }
        
        friend class Genericka<float>;    
};

int main ()
{
    Genericka<int> g1("prva");
    g1.postaviPrivatni(14);
    Genericka<string> g2("druga");
    g2.postaviPrivatni("jes");
    Genericka<float> g3(g2);
    
	return 0;
}