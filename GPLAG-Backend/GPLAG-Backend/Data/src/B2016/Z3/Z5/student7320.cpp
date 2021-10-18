/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <stdexcept>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
struct Dijete {
  std::string ime;
  Dijete *sljedeci;
};
bool ValidnoSlovo(char c) {
  return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}
int Duzina(std::string x) {
  int ret = 0;
  for (int i = 0; i < x.length(); i++)
    if (ValidnoSlovo(x[i])) ret++;
  return ret;
}
void ObrisiDijete(std::string x, Dijete *&pocetak) {
  Dijete *trazeni = pocetak, *prethodni{}, *naredni{};
  while (1) {
    if (trazeni -> sljedeci -> ime == x) prethodni = trazeni;
    trazeni = trazeni -> sljedeci;
    if (trazeni -> ime == x) break;
  }
  naredni = trazeni -> sljedeci;
  prethodni -> sljedeci = naredni;
  if (trazeni == pocetak) pocetak = pocetak -> sljedeci;
  delete trazeni; //trazeni = nullptr;
}
std::vector<std::set<std::string> > Razvrstavanje(std::vector<std::string> vect, int k) {
  if (k < 1 || k > vect.size()) throw std::logic_error("Razvrstavanje nemoguce");
  Dijete *pocetak = nullptr;
  Dijete *prethodni;
    
  for (int i = 0; i < vect.size(); i++) {
    Dijete *novi = new Dijete{};
    novi -> ime = vect[i]; novi -> sljedeci = nullptr;
    if (!pocetak) pocetak = novi;
    else prethodni->sljedeci = novi;
    prethodni = novi;
    //delete novi;
  }
  prethodni -> sljedeci = pocetak;
  
  // PROBA KRUZNE LISTE
  /*auto testni = pocetak;
  for (int i = 0; i < 50; i++) {
  	std::cout << testni -> ime << " ";
  	testni = testni -> sljedeci;
  }
  std::cout << "\n";
  DO OVE LINIJE JE SVE DOBRO!
  */
  auto x = pocetak;
  int n = vect.size();
  std::set<std::string> redam;
  std::vector<std::set<std::string> > ret;
  // ako je n % k == 0 redamo po n/k elemenata
  // inace redamo n % k sa n/k + 1 clanova, ostali n/k
  if (n % k == 0) {
    int unesenih = 0;
    int vel_liste = n;
    while (vel_liste--) {
      int len = Duzina(x -> ime);
      unesenih++; redam.insert(x -> ime);
      if (unesenih == n / k) {
        ret.pb(redam);
        redam.clear();
        unesenih = 0;
      }
      ObrisiDijete(x -> ime, pocetak); 
      while (len--) {
        x = x -> sljedeci;
      }
    }
  }
  else {
    int unesenih = 0;
    int vel_liste = n;
    while (vel_liste--) {
    	//std::cout << "NASE TRENUTNO DIJETE JE: " << x -> ime << "\n";
      int len = Duzina(x -> ime);
      unesenih++; redam.insert(x -> ime);
      if (unesenih == (n / k) + 1 && ret.size() < n % k) {
        ret.pb(redam);
        redam.clear();
        unesenih = 0;
      }
      else if (unesenih == n / k && ret.size() >= n % k) {
        ret.pb(redam);
        redam.clear();
        unesenih = 0;
      }
      //std::cout << x -> ime << " ";
      //ObrisiDijete(x -> ime, pocetak); 
	    //std::cout << "Prodji s njima ispod duge: ";
	    auto y = x;
	    while (len--) {
	    	//std::cout << x -> ime << " ";
	    	if (x == y) x = x -> sljedeci;
	      x = x -> sljedeci;
	    }
	    ObrisiDijete(x -> ime, pocetak);
    }
    if (redam.size()) ret.pb(redam);
  }
  return ret;
}
// 0 5 3 1 6
int main () {
  std::vector<std::string> vect;
  int n; std::string tmp;
  std::cout << "Unesite broj djece: "; std::cin >> n;
  std::cout << "Unesite imena djece: \n";
  std::cin.clear(); std::cin.ignore(10000, '\n');
  for (int i = 0; i < n; i++) {
    std::getline(std::cin, tmp);
    vect.pb(tmp);
  }
  int k; std::cout << "Unesite broj timova: ";
  std::cin >> k;
  try {
    auto x = Razvrstavanje(vect, k);
  	for (int i = 0; i < x.size(); i++) {
  	  std::cout << "Tim " << i + 1 << ": ";
  	  int vel = x[i].size() - 1;
  	  for (auto y = x[i].begin(); y != x[i].end(); y++, vel--) {
  	    std::cout << *y;
  	    if (vel != 0) std::cout << ", ";
  	  }
  	  std::cout << "\n";
  	}
  }
  catch (std::logic_error c) {
    std::cout << "Izuzetak: " << c.what();
  }
	return 0;
}