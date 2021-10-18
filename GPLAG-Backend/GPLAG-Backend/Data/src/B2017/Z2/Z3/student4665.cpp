#include <iostream>
#include <vector>
#include <stdexcept>
#include <new>
#include <iomanip>
#include <algorithm>

template <typename Tip>
Tip **AlocirajFragmentirano(const std::vector<Tip> &v, int koliko_puta) {
    Tip **p(nullptr);
    if (!(v.size())) throw "Prazan vektor!";
    int period(1);
	for(int i = 1; i < v.size(); i++) if(v[i] == v[0]) period = i;
    Tip max(*std::max_element(&v[0], &v[period]));
    try {
        p = new Tip*[period*koliko_puta];
        for (int i = 0; i < period*koliko_puta; i++) p[i] = nullptr;
        for (int i = 0; i < koliko_puta; i++)
            for(int j = 0; j < period; j++) {
                p[i*period + j] = new Tip[v[j]];
                for (int k = 0; k < v[j] ; k++) {
                    p[i*period + j][v[j] - 1 -k] = max - k;
                }
            }
    } catch(...) {
        if (p) 
        for (int i = 0; i < period*koliko_puta; i++) delete[] p[i];
        delete[] p;
        throw;
    }
    return p;
}

template <typename Tip>
Tip **AlocirajKontinualno(const std::vector<Tip> &v, int koliko_puta) {
	Tip **p(nullptr);
	if(v.size() == 0) throw "Prazan vektor!";
	int period(1);
	for(int i = 1; i < v.size(); i++) if(v[i] == v[0]) period = i;
	try {
	p = new Tip*[(v.size())*koliko_puta];
    p[0] = nullptr;
        int br_el(0);
        for (int i = 0; i < period; i++) br_el += v[i];
        p[0] = new Tip[br_el*koliko_puta];
        for (int i = 1; i < period; i++) p[i] = p[i - 1] + v[i-1];
        for (int k = 1; k < koliko_puta; k++) {
            p[k*period] = p[k*period -1] + v[period - 1];
            for (int i = 1; i < period; i++) p[k*period + i] = p[k*period + i - 1] + v[i-1];
        }
        for (int i = 0; i < koliko_puta; i++)
        for (int j = 0; j < period; j++) {
            for (int l = 0; l < v[j] ; l++) {
                p[i*period + j][l] = v[j] - l;
            }
        }
	} catch(...){
		if (p) 
        for (int i = 0; i < period*koliko_puta; i++) delete[] p[i];
        delete[] p;
        throw;
	}
	return p;
}

template <typename Tip>
Tip **Kreiraj(std::vector<Tip> &v, bool fragmentirano, int &koliko_puta) {
      Tip **pokic(nullptr);
      if (!(v.size())) throw "Prazan vektor!";

      for (int i = 0; i < v.size(); i++) if(v[i] <= 0) throw std::domain_error("Neispravan vektor!");

          koliko_puta = 1;
          for (int i = 1; i < v.size(); i++) {
              bool indikator = false;
              if (v[i] == v[0]){
                  if (i == v.size() - 1)  {
                      int j(1);
                      while(v[j] != v[0]) {
                          v.push_back(v[j]);
                          j++;
                      }
                      koliko_puta++;
                      indikator = true;
                  } else{
                      int j(i);
                      while(v[j] != v[0] && j != v.size() - 1) {
                          j++;
                      }
                      if(v[j] == v[0]) {
                          koliko_puta++;
                      } else {
                          if(j == v.size() - 1) {
                              koliko_puta++;
                              indikator = true;
                          }
                      }
                  }
                  
              }
              if(indikator) i = v.size();
          }

      if(koliko_puta == 1) {
          int j = v.size();
          for(int i = 0; i < j; i++) v.push_back(v[i]);
          koliko_puta++;
      }
      try {
      if (fragmentirano) pokic = AlocirajFragmentirano(v, koliko_puta);
      else pokic = AlocirajKontinualno(v, koliko_puta);
      }
      catch(...) {
            throw;
      }
      return pokic;
}
int main ()
{
	try {
        int n;
        std::cout << "Unesite broj elemenata vektora: ";
        std::cin >> n;
        std::vector<int> v(n);
        std::cout << "Unesite elemente vektora: ";
        for (int i = 0; i < n; i++) std::cin >> v[i];
        bool fragmentirano;
        std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
        std::cin >> fragmentirano;
        int koliko_puta;
        int **p(Kreiraj(v, fragmentirano, koliko_puta));
        std::cout << "Dinamicki alocirana matrica:" << std::endl;
        int k(0);
         int period(1);
	     for(int i = 1; i < v.size(); i++) if(v[i] == v[0]) period = i;
        for(int i = 0; i < period*koliko_puta; i++) {
            if (k == period) k = 0;
            for(int j = 0; j < v[k]; j++) std::cout << std::setw(3) << std::left << p[i][j];
            std::cout << std::endl;
            k++;
        }
        
        if (p) {
            if(fragmentirano) for (int i = 0; i < period*koliko_puta; i++) delete[] p[i];
            else delete[] p[0];
        }
        delete[] p;
    } 
    catch(const char poruka[]) {
        std::cout << "Izuzetak: " << poruka << std::endl;
    }
    catch(std::domain_error e) {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    catch(...) {
        std::cout << "Izuzetak: ";
    }
    return 0;
}