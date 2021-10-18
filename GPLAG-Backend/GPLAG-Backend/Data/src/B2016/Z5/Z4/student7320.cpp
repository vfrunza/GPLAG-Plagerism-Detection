/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <iomanip>

template<typename T>
class GMatrica {
  T mat[4][4];
  int br_red, br_kol;
public:
  GMatrica();
  GMatrica(int red, int kol, T val);
  template<typename T2>
  GMatrica(GMatrica<T2> &matrix) {
    for (int i = 0; i < matrix.br_red; i++) for (int j = 0; j < matrix.br_kol; j++) mat[i][j] = matrix.mat[i][j];
  }
  template<typename T2>
  GMatrica(std::vector<std::vector<T2> > vect) {
    if (vect.size() > 4) throw std::logic_error("Ilegalan format matrice");
    for (int i = 0; i < vect.size(); i++) 
      if (vect[i].size() != vect[0].size()) throw std::logic_error("Ilegalan format matrice");
    for (int i = 0; i < vect.size(); i++)
      for (int j = 0; j < vect.at(0).size(); j++)
        mat[i][j] = vect[i][j];
  }
  GMatrica(std::initializer_list<std::initializer_list<T> > lista) {
    br_red = lista.size();
    int i = 0, j = 0;
    for (auto x = lista.begin(); x != lista.end(); x++) {
      br_kol = x -> size();
      for (auto y = x->begin(); y != x->end(); y++)
        mat[i][j++] = *y;
      j = 0;
      i++;
    }
  }
  int DajBrojRedova() { return br_red; }
  int DajBrojKolona() { return br_kol; }
  template<typename T2>
  friend GMatrica<T2> operator + (const GMatrica<T2> &g1, const GMatrica<T2> &g2);
  template<typename T2>
  friend GMatrica<T2> operator - (const GMatrica<T2> &g1, const GMatrica<T2> &g2);
  template<typename T2>
  friend GMatrica<T2> operator * (const GMatrica<T2> &g1, const T2 &val);
  template<typename T2>
  friend GMatrica<T2> operator * (const T2 &val, const GMatrica<T2> &g1);
  template<typename T2>
  friend GMatrica<T2> operator += (GMatrica<T2> &g1, const GMatrica<T2> &g2);
  template<typename T2>
  friend GMatrica<T2> operator -= (GMatrica<T2> &g1, const GMatrica<T2> &g2);
  template<typename T2>
  friend GMatrica<T2> operator *= (GMatrica<T2> &g1, const T2 &val);
  template<typename T2>
  friend bool operator == (const GMatrica<T2> &g1, const GMatrica<T2> &g2);
  template<typename T2>
  friend bool operator != (const GMatrica<T2> &g1, const GMatrica<T2> &g2);
  template <typename T2>
  friend std::ostream &operator << (std::ostream &tok, const GMatrica<T2> &x);
  template <typename T2>
  friend std::istream &operator >> (std::istream &tok, GMatrica<T2> &x);
  
  class Red {
		friend class GMatrica;
		public: 
			T &operator[](int col) const {
				return parent.mat[red][col];
			}
		private:
			Red(GMatrica &parent_, int red_) : parent(parent_), red(red_) {}
			GMatrica &parent;
			int red;
	};
  Red operator[](int red) { return Red(*this, red); }
	T &operator ()(int jedan, int dva) { return mat[jedan - 1][dva - 1]; }
	T operator ()(int jedan, int dva) const { return mat[jedan - 1][dva - 1]; }
};
template<typename T>
GMatrica<T>::GMatrica() { br_red = br_kol = 0; for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) mat[i][j] = 0; }
template<typename T>
GMatrica<T>::GMatrica(int red, int kol, T val) {
  if (red > 4 || kol > 4 || red < 0 || kol < 0) throw std::logic_error("Ilegalan format matrice");
  br_red = red; br_kol = kol;
  for (int i = 0; i < br_red; i++) for (int j = 0; j < br_kol; j++) mat[i][j] = val;
}
/*template<typename T2>
GMatrica<T2>::GMatrica(GMatrica<T2> &matrix) {
  for (int i = 0; i < matrix.br_red; i++) for (int j = 0; j < matrix.br_kol; j++) mat[i][j] = matrix.mat[i][j];
}*/

template<typename T2>
GMatrica<T2> operator + (const GMatrica<T2> &g1, const GMatrica<T2> &g2) {
  if (g1.br_red != g2.br_red || g1.br_kol != g2.br_kol) throw std::domain_error("Nedozvoljena operacija");
  GMatrica<T2> ret (g1.br_red, g1.br_kol, 0);
  for (int i = 0; i < ret.br_red; i++)
    for (int j = 0; j < ret.br_kol; j++)
      ret.mat[i][j] = g1.mat[i][j] + g2.mat[i][j];
  return ret;
}
template<typename T2>
GMatrica<T2> operator - (const GMatrica<T2> &g1, const GMatrica<T2> &g2) {
  if (g1.br_red != g2.br_red || g1.br_kol != g2.br_kol) throw std::domain_error("Nedozvoljena operacija");
  GMatrica<T2> ret (g1.br_red, g1.br_kol, 0);
  for (int i = 0; i < ret.br_red; i++)
    for (int j = 0; j < ret.br_kol; j++)
      ret.mat[i][j] = g1.mat[i][j] - g2.mat[i][j];
  return ret;
}
template <typename T2>
std::ostream &operator << (std::ostream &tok, const GMatrica<T2> &x) {
	int e = tok.width();
	if (e < 6) e = 6;
	for(int i = 0; i < x.br_red; i++) {
		for(int j = 0; j < x.br_kol; j++) {
			tok << std::setw(e) << x.mat[i][j];
		}
		tok << std::endl;
	}
	return tok;
}
template <typename T2>
std::istream &operator >> (std::istream &tok, GMatrica<T2> &x) {
  char c = 'a';
  int brojacRedova = 0, brojacKolona = 0;
  std::vector<int> glbrkol;
  tok >> c;
  while (1) {
    if (c == ']') break;
    //c = tok.peek();
    if (c == ';') {
      brojacRedova++;
      glbrkol.push_back(brojacKolona);
      brojacKolona = 0;
    }
    {
      tok >> x.mat[brojacRedova][brojacKolona];
      //std::cout << "Element (" << brojacRedova + 1 << "," << brojacKolona + 1 << ") = " << x.mat[brojacRedova][brojacKolona] << "\n";
      brojacKolona++;
    }
    tok >> c;
  }
  for (int i = 0; i < glbrkol.size(); i++)
    if (glbrkol[i] != glbrkol[0]) tok.setstate(std::ios::failbit);
  brojacKolona = glbrkol[0];
  x.br_kol = brojacKolona;
  x.br_red = brojacRedova + 1;
  return tok; 
}
template<typename T2>
GMatrica<T2> operator * (const GMatrica<T2> &g1, const T2 &val) {
  GMatrica<T2> ret(g1);
  for (int i = 0; i < ret.br_red; i++) for (int j = 0; j < ret.br_kol; j++) ret.mat[i][j] *= val;
  return ret;
}
template<typename T2>
GMatrica<T2> operator * (const T2 &val, const GMatrica<T2> &g1) {
  GMatrica<T2> ret(g1);
  for (int i = 0; i < ret.br_red; i++) for (int j = 0; j < ret.br_kol; j++) ret.mat[i][j] *= val;
  return ret;
}
template<typename T2>
GMatrica<T2> operator += (GMatrica<T2> &g1, const GMatrica<T2> &g2) {
  if (g1.br_red != g2.br_red || g1.br_kol != g2.br_kol) throw std::domain_error("Nedozvoljena operacija");
  for (int i = 0; i < g1.br_red; i++) for (int j = 0; j < g1.br_kol; j++) g1.mat[i][j] += g2.mat[i][j];
  return g1;
}
template<typename T2>
GMatrica<T2> operator -= (GMatrica<T2> &g1, const GMatrica<T2> &g2) {
  if (g1.br_red != g2.br_red || g1.br_kol != g2.br_kol) throw std::domain_error("Nedozvoljena operacija");
  for (int i = 0; i < g1.br_red; i++) for (int j = 0; j < g1.br_kol; j++) g1.mat[i][j] -= g2.mat[i][j];
  return g1;
}
template<typename T2>
GMatrica<T2> operator *= (GMatrica<T2> &g1, const T2 &val) {
  for (int i = 0; i < g1.br_red; i++) for (int j = 0; j < g1.br_kol; j++) g1.mat[i][j] *= val;
  return g1;
}
template<typename T2>
bool operator == (const GMatrica<T2> &g1, const GMatrica<T2> &g2) {
  if (g1.br_red != g2.br_red || g1.br_kol != g2.br_kol) return 0;
  for (int i = 0;i < g1.br_red; i++)
    for (int j = 0; j < g1.br_kol; j++)
      if (g1.mat[i][j] != g2.mat[i][j]) return 0;
  return 1;
}
template<typename T2>
bool operator != (const GMatrica<T2> &g1, const GMatrica<T2> &g2) {
  return !(g1 == g2);
}
int main() {
  GMatrica<int> m1({{1, 2}, {3, 4}});
   std::cout << m1(1,1) << std::endl;
   std::cout << m1[1][1] << std::endl;
	return 0;
}