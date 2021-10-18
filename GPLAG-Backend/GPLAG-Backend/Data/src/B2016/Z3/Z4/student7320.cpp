/B2016/2017: Zadaća 3, Zadatak 4
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
bool ValidnoSlovo(char c) {
  return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}
int Duzina(std::string x) {
  int ret = 0;
  for (int i = 0; i < x.length(); i++)
    if (ValidnoSlovo(x[i])) ret++;
  return ret;
}
std::vector<std::set<std::string> > Razvrstavanje(std::vector<std::string> vect, int k) {
  if (k < 1 || k > vect.size()) throw std::logic_error("Razvrstavanje nemoguce");
  std::vector<std::set<std::string> > ret;
  std::list<std::string> lista;
  for(int i = 0; i < vect.size(); i++) lista.pb(vect[i]);
  
  auto x = lista.begin();
  int n = lista.size();
  std::set<std::string> redam;
  // ako je n % k == 0 redamo po n/k elemenata
  // inace redamo n % k sa n/k + 1 clanova, ostali n/k
  if (n % k == 0) {
    int unesenih = 0;
    while (!lista.empty()) {
      int len = Duzina(*x);
      unesenih++; redam.insert(*x);
      if (unesenih == n / k) {
        ret.pb(redam);
        redam.clear();
        unesenih = 0;
      }
      bool tacno = 0;
      if (x == --lista.end()) tacno = 1;
      x = lista.erase(x); len--;
      if (tacno) x = lista.begin();
      while (len--) {
        x++;
        if (x == lista.end()) x = lista.begin();
      }
    }
  }
  else {
    int unesenih = 0;
    while (!lista.empty()) {
      int len = Duzina(*x);
      unesenih++; redam.insert(*x);
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
      bool tacno = 0;
      if (x == --lista.end()) tacno = 1;
      x = lista.erase(x); len--;
      if (tacno) x = lista.begin();
      while (len--) {
        x++;
        if (x == lista.end()) x = lista.begin();
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