/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector> 
#include <iomanip>

template<typename _Ty>
class GMatrica
{
    _Ty mat[4][4];
    int bk, br;
public:
    GMatrica();
    
    int DajBrojRedova()const
    {
        return br;
    }
    
    int DajBrojKolona()const
    {
        return bk;
    }
    
    GMatrica(int x, int y, _Ty el = _Ty {});
    
    template<typename _Ty1>
    GMatrica(const GMatrica<_Ty1>&);
    
    template<typename _Ty1>
    GMatrica(const std::vector<std::vector<_Ty1>>&);
    
    template<typename _Ty1>
    GMatrica(const _Ty1 n[4][4]);
    
    template<typename _Ty1>
    GMatrica(std::initializer_list<std::initializer_list<_Ty1>> lista);
    
    template<typename _Ty1, typename _Ty2>
    friend auto operator*=(GMatrica<_Ty1>& g, const GMatrica<_Ty2>& m) -> GMatrica<decltype(g[0][0] * m[0][0])>;
    
    _Ty* operator[](int i)
    {
        return mat[i];
    }
    
    const _Ty* operator[](int i) const
    {
        return mat[i];
    }
    
    _Ty& operator()(int r, int k)
    {
        if(r < 1 || r > br || k < 1  || k> bk)
            throw std::range_error("Nedozvoljen indeks");
        return mat[r -1][k - 1];
    }
    
    _Ty operator()(int r, int k) const
    {
        if(r < 1 || r > br || k < 1  || k> bk)
            throw std::range_error("Nedozvoljen indeks");
        return mat[r -1][k - 1];
    }
    
}; /// Kraj klase GMatrica


template<typename _Ty1, typename _Ty2>
auto operator+=(GMatrica<_Ty1>& g, const GMatrica<_Ty2>& m) -> GMatrica<decltype(g[0][0] + m[0][0])>
{
    if(g.DajBrojKolona() != m.DajBrojKolona() || g.DajBrojRedova() != m.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    for(int i= 0; i < g.DajBrojRedova(); ++i)
        for(int j = 0; j < g.DajBrojKolona(); ++j)
            g[i][j] += m[i][j];
    return g;
}

template<typename _Ty1, typename _Ty2>
auto operator-=(GMatrica<_Ty1>& g, const GMatrica<_Ty2>& m) -> GMatrica<decltype(g[0][0] - m[0][0])>
{
    if(g.DajBrojKolona() != m.DajBrojKolona() || g.DajBrojRedova() != m.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    for(int i= 0; i < g.DajBrojRedova(); ++i)
        for(int j = 0; j < g.DajBrojKolona(); ++j)
            g[i][j] -= m[i][j];
    return g;
}

template<typename _Ty1, typename _Ty2>
auto operator*=(GMatrica<_Ty1>& g, const GMatrica<_Ty2>& m) -> GMatrica<decltype(g[0][0] * m[0][0])>
{
    if(g.DajBrojKolona() !=  m.DajBrojRedova())
        throw std::domain_error("Nedozvoljena operacija");
    auto p = g;
    g.bk = m.bk;
    for(int i= 0; i < p.DajBrojRedova(); ++i)
    {
        for(int j = 0; j < m.DajBrojKolona(); ++j)
        {
            _Ty1 s {};
            for(int k = 0; k < p.DajBrojKolona(); ++k)
                s+= p[i][k] * m[k][j];
            g[i][j] = s;
        }
    }
    return g;
}

template<typename _Ty1, typename _Ty2>
auto operator*=(GMatrica<_Ty1>& g, const _Ty2& m) -> GMatrica<decltype(g[0][0] * m)>
{
    for(int i= 0; i < g.DajBrojRedova(); ++i)
        for(int j = 0; j < g.DajBrojKolona(); ++j)
            g[i][j] *= m;
    return g;
}



template<typename _Ty>
GMatrica<_Ty>::GMatrica() : bk(0), br(0) {}

template<typename _Ty>
template<typename _Ty1>
GMatrica<_Ty>::GMatrica(const std::vector<std::vector<_Ty1>>& vv)
{
    
    if(vv.size() == 0)
    {
        br = bk = 0;
        return;
    }
    if(vv.size() > 4)
        throw std::logic_error("Ilegalan format matrice");
    for( int i = 1; i < vv.size(); ++i)
        if(vv[i].size() != vv[0].size() && vv[i].size() > 4)
            throw std::logic_error("Ilegalan format matrice");
    br = vv.size();
    bk = vv[0].size();
    for(int i = 0; i < br ; ++i)
        for(int j = 0; j < bk; ++j)
            mat[i][j] = vv[i][j];
}

template<typename _Ty>
template<typename _Ty1>
GMatrica<_Ty>::GMatrica(const _Ty1 n[4][4]) : bk(4), br(4)
{
    for(int i = 0; i < br ; ++i)
        for(int j = 0; j < bk; ++j)
            mat[i][j] = n[i][j];
}

template<typename _Ty>
template<typename _Ty1>
GMatrica<_Ty>::GMatrica(std::initializer_list<std::initializer_list<_Ty1>> lista)
{
  br = lista.size();
  bk = lista.begin()->size();
  if(bk > 4 || br > 4)
    throw std::logic_error("Ilegalan format matrice");
  int r = 0, k = 0;
  for(auto i(lista.begin()); i != lista.end(); i++) {
    k = 0;
    for(auto j(i->begin()); j != (i->end()); j++) {
      if(bk != i->size())
        throw std::logic_error("Ilegalan format matrice");
      mat[r][k] = (*j);
      k++;
    }
    r++;
  }
}

template<typename _Ty>
GMatrica<_Ty>::GMatrica(int x, int y, _Ty el) : bk(x), br(y)
{
    if(x < 1 || y < 1 || x > 4 || y > 4)
        throw std::logic_error("Ilegalan format matrice");
    for(int i = 0; i < br ; ++i)
        for(int j = 0; j < bk; ++j)
            mat[i][j] = el;
}

template<typename _Ty>
template<typename _Ty1>
GMatrica<_Ty>::GMatrica(const GMatrica<_Ty1>& m) : bk(m.DajBrojKolona()), br(m.DajBrojRedova())
{
    for(int i = 0; i < br; ++i)
        for(int j = 0; j < bk; ++j)
            mat[i][j] = m[i][j];
}

template<typename _Ty1, typename _Ty2>
auto operator+(const GMatrica<_Ty1>& g, const GMatrica<_Ty2>& m) -> GMatrica<decltype(g[0][0] + m[0][0])>
{
   auto p = g;
   p+=m;
   return p;
}

template<typename _Ty1, typename _Ty2>
auto operator-(const GMatrica<_Ty1>& g, const GMatrica<_Ty2>& m) -> GMatrica<decltype(g[0][0] - m[0][0])>
{
   auto p = g;
   p-=m;
   return p;
}

template<typename _Ty1, typename _Ty2>
auto operator*(const GMatrica<_Ty1>& g, const GMatrica<_Ty2>& m) -> GMatrica<decltype(g[0][0] * m[0][0])>
{
   auto p = g;
   p*=m;
   return p;
}

template<typename _Ty1, typename _Ty2>
auto operator*(const GMatrica<_Ty1>& g, const _Ty2& m) -> GMatrica<decltype(g[0][0] * m)>
{
    auto p =g;
    p*=m;
    return p;
}

template<typename _Ty1, typename _Ty2>
auto operator*(const _Ty2& m, const GMatrica<_Ty1>& g) -> GMatrica<decltype(m * g[0][0])>
{
    auto p =g;
    p*=m;
    return p;
}

template<typename _Ty1, typename _Ty2>
bool operator==(const GMatrica<_Ty1>& g, const GMatrica<_Ty2>& m)
{
    if(g.DajBrojKolona() != m.DajBrojKolona() || g.DajBrojRedova() != m.DajBrojRedova())
        return false;
     for(int i = 0; i < g.DajBrojRedova(); ++i)
        for(int j = 0; j < g.DajBrojKolona(); ++j)
            if(g[i][j] != m[i][j])
                return false;
    return true;
}

template<typename _Ty1, typename _Ty2>
bool operator!=(const GMatrica<_Ty1>& g, const GMatrica<_Ty2>& m)
{
    return !(g == m);
}

template<typename _Ty>
std::ostream& operator <<(std::ostream& os, const GMatrica<_Ty>& m)
{
  auto sirina = (os.width() < 6 ? 6 : os.width());
  
  for(int i(0); i < m.DajBrojRedova(); i++) {
    for(int j(0); j < m.DajBrojKolona(); j++)
      os << std::setw(sirina) << m[i][j];
    os << "\n";
  }
  return os;
}

template<typename _Ty>
std::istream& operator >>(std::istream& is, GMatrica<_Ty>& m1)
{
  char c;
  is >> c;
  if(c != '[') {
    is.setstate(std::ios::failbit);
    return is;
  }
  _Ty broj; int red = 0;
  std::vector<std::vector<_Ty>> v;
  v.push_back(std::vector<_Ty>());
  while(c != ']' || c == EOF) {
    is >> broj >> c;
    v[red].push_back(broj);
    if(c == ';') {
      red++;
      v.push_back(std::vector<_Ty>());
    }
    if(!is.good())
      return is;
  }
  if(c != ']') {
    is.setstate(std::ios::failbit);
    return is;
  }
  GMatrica<_Ty> temp(v);
  m1 = temp;
  return is;

}

int main()
{
	try {
		//test transponiranja
		std::cout << "Unesite matricu dimenzija 3x3:\n";
		GMatrica<double> m1 (3, 3);
		std::cin >> m1;
		GMatrica<double> test = {{m1 (1, 1), m1 (2, 1), m1 (3, 1) },
			{m1 (1, 2), m1 (2, 2), m1 (3, 2) },
			{m1 (1, 3), m1 (2, 3), m1 (3, 3) }
		};
		//test konstruktora sa inicijalizacionom listom
		GMatrica<int> m2 {{11, 22, 33}, {55, 66, 77}, {88, 99, 26}};
		std::cout.width (5);
		std::cout << "Inicijalizaciona lista\n" << std::setw (7) <<  m2 << std::endl;
		test =  {{m1 (1, 1) + m2 (1, 1), m1 (1, 2) + m2 (1, 2), m1 (1, 3) + m2 (1, 3) },
			{m1 (2, 1) + m2 (2, 1), m1 (2, 2) + m2 (2, 2), m1 (2, 3) + m2 (2, 3) },
			{m1 (3, 1) + m2 (3, 1), m1 (3, 2) + m2 (3, 2), m1 (3, 3) + m2 (3, 3) }
		};
		//test operator +
		auto* pom = new GMatrica<double> (m1 + m2);
		if (*pom == test) {
			std::cout << "Sabiranje uredu!\n";
			std::cout.width (5);
			std::cout << *pom << std::endl;
			delete pom;
		}
		test =  {{m1 (1, 1) - m2 (1, 1), m1 (1, 2) - m2 (1, 2), m1 (1, 3) - m2 (1, 3) },
			{m1 (2, 1) - m2 (2, 1), m1 (2, 2) - m2 (2, 2), m1 (2, 3) - m2 (2, 3) },
			{m1 (3, 1) - m2 (3, 1), m1 (3, 2) - m2 (3, 2), m1 (3, 3) - m2 (3, 3) }
		};
		//test operatora -
		pom = new GMatrica<double> (m1 - m2);
		if (*pom == test) {
			std::cout << "Oduzimanje uredu!\n";
			std::cout.width (5);
			std::cout << *pom << std::endl;
			delete pom;
		}
		//test operatora * i GMatrica*=GMatrica
		GMatrica<int> aaaa {{1, 2}, {3, 4}};
		GMatrica<int> bbbb {{1, 1}, {2, 2}};
		auto* oo = new GMatrica<int> (aaaa * bbbb);
		test = {{5, 5}, {11, 11}};
		aaaa *= bbbb;
		if (test == *oo && test == aaaa) {
			std::cout << "Test operatora * i GMatrica*=GMatrica radii\n";
			std::cout << std::setw (10) << std::setprecision (3) << *oo << std::endl;
			std::cout << std::setw (10) << std::setprecision (3) << aaaa << std::endl;
			delete oo;
		}
		//test ctor koji inicijalizuje matricu matricom drugog tipa
		GMatrica<double> m3 (m2);
		if (m3 == m2)
			std::cout << "Ctor koji prima matricu drugacijeg tipa i inicijalizuje matricu tom proslijedjenom matricom! RADIII!\n\n";
		//test operatora +=
		test =  {{m1 (1, 1) + m3 (1, 1), m1 (1, 2) + m3 (1, 2), m1 (1, 3) + m3 (1, 3) },
			{m1 (2, 1) + m3 (2, 1), m1 (2, 2) + m3 (2, 2), m1 (2, 3) + m3 (2, 3) },
			{m1 (3, 1) + m3 (3, 1), m1 (3, 2) + m3 (3, 2), m1 (3, 3) + m3 (3, 3) }
		};
		m3 += m1;
		if (m3 == test) {
			std::cout << "Operator += radii!\n";
			std::cout.width (5);
			std::cout << m3;
		}
		test =  {{m2 (1, 1) - m1 (1, 1), m2 (1, 2) - m1 (1, 2), m2 (1, 3) - m1 (1, 3) },
			{m2 (2, 1) - m1 (2, 1), m2 (2, 2) - m1 (2, 2), m2 (2, 3) - m1 (2, 3) },
			{m2 (3, 1) - m1 (3, 1), m2 (3, 2) - m1 (3, 2), m2 (3, 3) - m1 (3, 3) }
		};
		//test operatora -=
		m2 -= m1;
		if (m2 == test) {
			std::cout << "Operator -= radii!\n";
			std::cout.width (5);
			std::cout << m2;
		}
		//test konmstruktora koji prima vektor vektora i inicijalizuje matricu njime
		std::vector<std::vector<int>> vv (3);
		for (int i {0}; i < 3; i++)
			vv[i].resize (3);
		for (int i {0}; i < int (vv.size() ); i++)
			for (int j {0}; j < int (vv[i].size() ); j++)
				vv[i][j] = i * 2.;
		GMatrica<int>F (vv);
		bool isti (true);
		for (int i {0}; i < int (vv.size() ); i++)
			for (int j {0}; j < int (vv[i].size() ); j++)
				if (F[i][j] != vv[i][j]) {
					isti = false;
					break;
				}
		if (isti) {
			//test const operatora []
			std::cout << "Konstruktor vektor vektora u matricu radii\n";
			const auto gg (F);
			for (int i {0}; i < gg.DajBrojRedova(); i++) {
				for (int j {0}; j < gg.DajBrojKolona(); j++)
					std::cout << std::setprecision (5) << std::setw (8) << gg[i][j] << ' ';
				std::cout << std::endl;
			}
		}
		//test operator Matrica*=broj
		test =  {{ - m1 (1, 1), - m1 (1, 2), - m1 (1, 3) },
			{ - m1 (2, 1), - m1 (2, 2), - m1 (2, 3) },
			{ - m1 (3, 1), - m1 (3, 2), - m1 (3, 3) }
		};
		m1 *= -1.;
		if (m1 == test) {
			std::cout << "Operator matrica*=broj radii!\n";
			std::cout.width (5);
			std::cout << m1 << std::endl;
		}
		//test operatora Matrica * broj
		test =  {{5 * m1 (1, 1) , 5 * m1 (1, 2), 5 * m1 (1, 3) },
			{ 5 * m1 (2, 1), 5 * m1 (2, 2), 5 * m1 (2, 3) },
			{ 5 * m1 (3, 1), 5 * m1 (3, 2), 5 * m1 (3, 3) }
		};
		pom = new GMatrica<double> (m1 * 5);
		if (*pom == test) {
			std::cout << "Operator matrica * broj radii \n";
			std::cout.width (5);
			std::cout << *pom << std::endl;
			delete pom;
		}
		//test operatora broj * Matrica
		pom = new GMatrica<double> (5 * m1);
		if (*pom == test) {
			std::cout << "Operator broj * matrica radii \n";
			std::cout.width (5);
			std::cout << *pom << std::endl;
			delete pom;
		}
		//test opratora ==   !=   !
		GMatrica<int> g(2, 2);
		GMatrica<int> h;
		if (g == h)
			std::cout << "ISTE" << std::endl;
		else
			std::cout << "NISU ISTE" << std::endl;
		if (g != h)
			std::cout << "RAZLICITE" << std::endl;
		else
			std::cout << "ISTE" << std::endl;
		
		//test operatora () const i ne const
		g (1, 1) = 5;
		g (1, 2) = 6;
		g (2, 1) = 56;
		g (2, 2) = 15;
		test =  {{5 , 6,}, {56, 15} };
		if (test == g) {
			std::cout << "operator () const i ne const radii\n\n";
			const auto hh (g);
			for (int i {1}; i <= hh.DajBrojRedova(); i++) {
				for (int j {1}; j <= hh.DajBrojKolona(); j++)
					std::cout << hh (i, j) << "   ";
				std::cout << std::endl;
			}
		}
		//test operatora [] ne const
		h[0][0] = 11; h[0][1] = 1; h[0][2] = 2; h[0][3] = 3;
		h[1][0] = 9; h[1][1] = 6; h[1][2] = 7; h[1][3] = 6;
		test =  {{11 , 1, 2, 3}, {9, 6, 7, 6} };
		if (test == h)
			std::cout << "operator [] ne const radii\n\n";
		std::cout.width (5);
		std::cout << h << std::endl;
		//test jos jednog ctora
		GMatrica<double> u (g);
		GMatrica<int> o ({{1, 1}, {2, 2}});
		test =  {{1, 1}, {2, 2}};
		if (test == o)
			std::cout << "konstruktor koji prima inicijalizacionu list u pretvara u vektor i poziva ctor sa vektorom vektora! Radii\n";
	} catch (std::range_error r) {
		std::cout << r.what();
	} catch (std::domain_error e) {
		std::cout << e.what();
	}catch (std::logic_error e) {
		std::cout << e.what();
	}catch (...) {
		std::cout << "Doslo je do bacanja izuzetka";
	}
}
