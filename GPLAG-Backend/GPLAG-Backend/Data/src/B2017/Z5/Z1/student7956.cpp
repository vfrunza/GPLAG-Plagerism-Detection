/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>

using namespace std;

bool DaLiJePetocifren (int broj)
{
   int brojac = 0;
   while (broj > 0)
   {
       broj = broj / 10;
       brojac ++;
   }
   if (brojac == 5) return true;
   return false;
}

class Student 
{
    int broj_indexa;
    string godina_studija, ime_i_prezime, adresa_studenta, broj_telefona;
public:
    Student (int brojIndexa, string godinaStudija, string imePrezime, string adresaStudenta, string brojTelefona)
        {
            if (DaLiJePetocifren(brojIndexa)) 
                this->broj_indexa = brojIndexa;
            
        }
};

int main ()
{
	return 0;
}
