#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

struct Korisnik
{
    string ime;
    string prezime;
    string adresa;
    string telefon;
};

class Knjiga
{
    string naslov;
    string autor;
    string zanr;
    int godina;
    Korisnik* kodkog;
    
    public:
    
    Knjiga(string nas, string aut, string zn, int god)
    {
        naslov=nas;
        autor=aut;
        zanr=zn;
        godina=god;
    }
};

int main ()
{
	return 0;
}