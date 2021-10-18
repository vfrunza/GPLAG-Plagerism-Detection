/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <stdexcept>
#include <memory> 

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
struct Dijete {
  std::string ime;
  std::shared_ptr<Dijete> sljedeci;
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
void ObrisiDijete(std::string x, std::shared_ptr<Dijete> &pocetak, int n) {
  
  std::shared_ptr<Dijete> trazeni = pocetak, prethodni, naredni;
  if (n == 1) {
    //trazeni -> sljedeci = nullptr;
    trazeni = nullptr;
    return;
  }
  while (1) {
    if (trazeni -> sljedeci -> ime == x) prethodni = trazeni;
    trazeni = trazeni -> sljedeci;
    if (trazeni -> ime == x) break;
  }
  naredni = trazeni -> sljedeci;
  prethodni -> sljedeci = naredni;
  if (trazeni == pocetak) pocetak = pocetak -> sljedeci;
  trazeni = nullptr; 
}
std::vector<std::set<std::string> > Razvrstavanje(std::vector<std::string> vect, int k) {
  if (k < 1 || k > vect.size()) throw std::logic_error("Razvrstavanje nemoguce");
  std::shared_ptr<Dijete> pocetak = nullptr;
  std::shared_ptr<Dijete> prethodni;
    
  for (int i = 0; i < vect.size(); i++) {
    std::shared_ptr<Dijete> novi = std::make_shared<Dijete>();
    novi -> ime = vect[i]; novi -> sljedeci = nullptr;
    if (!pocetak) pocetak = novi;
    else prethodni->sljedeci = novi;
    prethodni = novi;
    novi = nullptr;
  }
  prethodni -> sljedeci = pocetak;
  
  
  std::shared_ptr<Dijete> x = pocetak;
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
      ObrisiDijete(x -> ime, pocetak, vel_liste); 
      while (len--) {
        //std::cout << x->ime << " ";
        x = x -> sljedeci;
      }
    }
  }
  else {
    int unesenih = 0;
    int vel_liste = n;
    while (vel_liste--) {
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
      ObrisiDijete(x -> ime, pocetak, n); 
      while (len--) {
        x = x -> sljedeci;
      }
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