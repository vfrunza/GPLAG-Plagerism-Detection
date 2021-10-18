/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
using namespace std;
 
bool DaLiJeArmstrong(int broj) {
  int suma = 0;
  // sumu uporedjujemo sa temp varijablom jer
  // varijablu broj mijenjamo pri razlaganju na cifre
  int temp = broj;
  int tekuca_cifra = 0;
 
  // rastavljanje na cifre
  while (broj > 0) {
    // magija rastavljanja brojeva na cifre "452 % 10=2"
    tekuca_cifra = broj % 10;
    // na sumu dodajemo kub cifre
    suma += tekuca_cifra * tekuca_cifra * tekuca_cifra;
    // na kraju dijelimo broj sa 10 jer nam ta cifra vise ne treba
    // 452/10=45 i onda opet na pocetak
    broj /= 10;
  }
  if (suma == temp) {
    return true;
  } else
    return false;
}
 
int main() {
  int broj;
 
  cout << "Unesite broj za provjeru: " << endl;   cin >> broj;
  if (broj < 1) {
    cout << "Broj mora biti >0 " << endl;
  } else {
    if (DaLiJeArmstrong(broj)) {
      cout << "Uneseni broj je Armstrongov broj" << endl;
    } else {
      cout << "Uneseni broj nije Armstrongov broj" << endl;
    }
  }
 
  system("Pause");
  return 0;
}