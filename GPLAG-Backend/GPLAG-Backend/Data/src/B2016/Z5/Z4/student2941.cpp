/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>    
#include <type_traits>
#include <iomanip>

using namespace std;

template <typename T>
class GMatrica {
    int br_red=0, br_kol=0;
    T mat[4][4];                                                   
    public:
    
    GMatrica() {br_red=0; br_kol=0; };
    GMatrica(int BrojRedova, int BrojKolona, T vrijednost=0);   
    template<typename T1>
    GMatrica(GMatrica<T1> &mat1) { br_red=mat1.DajBrojRedova(); br_kol=mat1.DajBrojKolona(); for(int i(0);i<mat1.DajBrojRedova();i++) for(int j(0);j<mat1.DajBrojKolona();j++) mat[i][j]=mat1(i+1,j+1); }                                         
    GMatrica(T niz[4][4]);                                           
    GMatrica(vector<vector<T> > mat);                               
    GMatrica(initializer_list<initializer_list<T> > i_lista);                           
    int DajBrojRedova() const  { return br_red; };
    int DajBrojKolona() const  { return br_kol; };
    template <typename T1,typename T2,typename T3>
    friend GMatrica<T1> operator +(const GMatrica<T2> &mat1, const GMatrica<T3> &mat2);
    template <typename T1,typename T2,typename T3>
    friend GMatrica<T1> operator -(const GMatrica<T1> &mat1, const GMatrica<T1> &mat2);
    template <typename T1,typename T2,typename T3>
    friend GMatrica<T1> operator *(const GMatrica<T1> &mat1, const GMatrica<T1> &mat2);
    template <typename T1,typename T2,typename T3>
    friend GMatrica<T1> operator *(const GMatrica<T2> &mat1, T3 n);
    template <typename T1,typename T2,typename T3>
    friend GMatrica<T1> operator *(T2 n, const GMatrica<T3> &mat1);
    GMatrica &operator +=(const GMatrica &mat);
    GMatrica &operator -=(const GMatrica &mat);
    GMatrica &operator *=(const GMatrica &mat);
    GMatrica &operator *=(T broj);
    bool operator ==(const GMatrica &mat);
    bool operator !=(const GMatrica &mat);
    T& operator ()(int i, int j);
    T* operator [](int i) { return mat[i]; };
    template<typename T1>
    friend ostream &operator <<(ostream &tok, const GMatrica<T1> &m);
    template<typename T1>
    friend istream &operator >>(istream &tok, const GMatrica<T1> &m);
};

    template <typename T>
    GMatrica<T>::GMatrica(int BrojRedova, int BrojKolona, T vrijednost) {
        if(BrojKolona<0 || BrojKolona>4 || BrojRedova<0 || BrojRedova>4) throw logic_error ("Ilegalan format matrice");
        br_kol=BrojKolona;
        br_red=BrojRedova;
        for(int i(0);i<BrojRedova;i++) {
            for(int j(0);j<BrojKolona;j++) {
                mat[i][j]=vrijednost;
            }
        }
    }
    template <typename T>
    GMatrica<T>::GMatrica(T niz[4][4]) {
        br_kol=4;
        br_red=4;
        for(int i(0);i<br_red;i++) 
            for(int j(0);j<br_kol;j++)
                mat[i][j]=niz[i][j];
    }
    template <typename T>
    GMatrica<T>::GMatrica(vector<vector<T> > mat1) {
        if(mat1.size()>4 || mat1[0].size()>4) throw logic_error ("Ilegalan format matrice");
        for(int i(1);i<mat1.size();i++) if(mat1[0].size()!=mat1[i].size()) throw logic_error ("Ilegalan format matrice");
        br_kol=mat1[0].size();
        br_red=mat1.size();
        for(int i(0);i<mat1.size();i++) {
            for(int j(0);j<mat1[0].size();j++) {
                mat[i][j]=mat1[i][j];
            }
        }
    }
    template <typename T>
    GMatrica<T>::GMatrica(initializer_list<initializer_list<T> > i_lista) {
        if(i_lista.size()>4 || i_lista.begin()->size()>4)  throw logic_error ("Ilegalan format matrice");
        for(auto i=i_lista.begin();i<i_lista.end();i++) if(i->size() != i_lista.begin()->size())  throw logic_error ("Ilegalan format matrice");
        int k=0, l=0;
        br_red=i_lista.size();
        br_kol=i_lista.begin()->size();
        for(auto i=i_lista.begin();i<i_lista.end();i++) {
            l=0;
            for(auto j = i->begin() ; j<i->end() ;j++) {
                mat[k][l]=*j;
                l++;
            }
            k++;
        }
    }
    template <typename T,typename T1>
    auto operator +(GMatrica<T> &mat1, GMatrica<T1> &mat2) -> GMatrica<decltype(mat1(1,1)+mat2(1,1)) > {
        if(mat1.DajBrojKolona()!=mat2.DajBrojKolona() || mat1.DajBrojRedova()!=mat2.DajBrojRedova()) throw domain_error ("Nedozvoljena operacija");
        GMatrica<decltype(mat1(1,1)+mat2(1,1)) > m(mat1.DajBrojRedova(),mat1.DajBrojKolona());
        for(int i(1);i<=mat1.DajBrojRedova();i++) {
            for(int j(1);j<=mat1.DajBrojKolona();j++) {
                m(i,j)=mat1(i,j)+mat2(i,j);
            }
        }
        return m;
    }
    template <typename T,typename T1>
    auto operator -(GMatrica<T> &mat1, GMatrica<T1> &mat2) -> GMatrica<decltype(mat1(1,1)-mat2(1,1)) > {
        if(mat1.DajBrojKolona()!=mat2.DajBrojKolona() || mat1.DajBrojRedova()!=mat2.DajBrojRedova()) throw domain_error ("Nedozvoljena operacija");
        GMatrica<decltype(mat1(1,1)+mat2(1,1))> m(mat1.DajBrojRedova(),mat1.DajBrojKolona());
        
        for(int i(1);i<=mat1.DajBrojRedova();i++) {
            for(int j(1);j<=mat1.DajBrojKolona();j++) {
                m(i,j)=mat1(i,j)-mat2(i,j);
            }
        }
        return m;
    }
    template <typename T,typename T1>
    auto operator *(GMatrica<T> &mat1, GMatrica<T1> &mat2) -> GMatrica<decltype(mat1(1,1)*mat2(1,1)) > {
        if(mat1.DajBrojKolona()!= mat2.DajBrojRedova()) throw domain_error ("Nedozvoljena operacija");
        GMatrica<decltype(mat1.mat[0][0]*mat2.mat[0][0]) > m(mat1.DajBrojRedova(),mat2.DajBrojKolona());
        
        decltype(mat1.mat[0][0]*mat2.mat[0][0]) suma=0;
        for(int i(1);i<=m.br_red;i++) {
            for(int j(1);j<=m.br_kol;j++) {
                suma=0;
                for(int k(1);k<=mat1.DajBrojKolona();k++) {
                    suma=suma + mat1(i-1,k-1)*mat2(k-1,j-1);
                }
                m(i,j)=suma;
            }
        }
        return m;
    }
    template <typename T,typename T1>
    auto operator *(GMatrica<T> &mat1, T1 n) -> GMatrica<decltype(mat1(1,1)*n)> {
        GMatrica<decltype(mat1(1,1)*n)> m(mat1.DajBrojRedova(),mat1.DajBrojKolona());
        for(int i(1);i<=m.DajBrojRedova();i++) {
            for(int j(1);j<=m.DajBrojKolona();j++) {
                m(i,j)=mat1(i,j)*n;
            }
        }
        return m;
    }
    template <typename T, typename T1>
    auto operator *(T1 n, GMatrica<T> &mat1) -> GMatrica<decltype(mat1(1,1)*n)> {
        GMatrica<decltype(mat1(1,1)*n)> m(mat1.DajBrojRedova(),mat1.DajBrojKolona());
        for(int i(1);i<=m.DajBrojRedova();i++) {
            for(int j(1);j<=m.DajBrojKolona();j++) {
                m(i,j)=mat1(i,j)*n;
            }
        }
        return m;
    }
    template<typename T>
    GMatrica<T> &GMatrica<T>::operator +=(const GMatrica<T> &mat1) {
        if(br_kol!=mat1.DajBrojKolona() || br_red!=mat1.DajBrojRedova()) throw domain_error ("Nedozvoljena operacija");
        for(int i(0);i<br_red;i++) {
            for(int j(0);j<br_kol;j++) {
                mat[i][j]=mat[i][j]+mat1.mat[i][j];
            }
        }
        return *this;
    }
    template<typename T>
    GMatrica<T> &GMatrica<T>::operator -=(const GMatrica<T> &mat1) {
        if(br_kol!=mat1.DajBrojKolona() || br_red!=mat1.DajBrojRedova()) throw domain_error ("Nedozvoljena operacija");
        for(int i(0);i<br_red;i++) {
            for(int j(0);j<br_kol;j++) {
                mat[i][j]=mat[i][j]-mat1.mat[i][j];
            }
        }
        return *this;
    }
    template<typename T>
    GMatrica<T> &GMatrica<T>::operator *=(const GMatrica<T> &mat1) {
        if(mat1.DajBrojKolona()!= br_red) throw domain_error ("Nedozvoljena operacija");
        GMatrica<T> m(*this);
        m.br_red=br_kol;
        m.br_kol=mat1.DajBrojRedova();
        int suma=0;
        for(int i(0);i<m.br_red;i++) {
            for(int j(0);j<m.br_kol;j++) {
                suma=0;
                for(int k(0);k<mat1.DajBrojKolona();k++) {
                    suma+= m.mat[i][k]*mat1.mat[k][j];
                }
                m.mat[i][j]=suma;
            }
        }
        *this=m;
        return *this;
    }
    template<typename T>
    GMatrica<T> &GMatrica<T>::operator *=(T n) {
        for(int i(0);i<br_red;i++) {
            for(int j(0);j<br_kol;j++) {
                mat[i][j]*=n;
            }
        }
        return *this;
    }
    template<typename T>
    bool GMatrica<T>::operator ==(const GMatrica<T> &mat1) {
        if(br_kol!=mat1.DajBrojKolona() || br_red!=mat1.DajBrojRedova()) return false;
        for(int i(0);i<br_red;i++) {
            for(int j(0);j<br_kol;j++) {
                if(mat[i][j]!= mat1.mat[i][j]) return false;
            }
        }
        return true;
    }
    template<typename T>
    bool GMatrica<T>::operator !=(const GMatrica<T> &mat1) {
        if(br_kol!=mat1.DajBrojKolona() || br_red!=mat1.DajBrojRedova()) return true;
        for(int i(0);i<br_red;i++) {
            for(int j(0);j<br_kol;j++) {
                if(mat[i][j]!= mat1.mat[i][j]) return true;
            }
        }
        return false;
    }
    template<typename T>
    T& GMatrica<T>::operator ()(int i, int j) {
        if(i>br_red || i<0 || j<0 || j>br_kol) throw range_error ("Nedozvoljen indeks");
        return mat[i-1][j-1];
    }
    template<typename T>
    ostream &operator <<(ostream &tok,const GMatrica<T> &m) {
        int n=6;
        if(tok.width()>6) n=tok.width();
        for(int i(0);i<m.br_red;i++) {
            for(int j(0);j<m.br_kol;j++) {
                tok<<setw(n)<<m.mat[i][j];
            }
            tok<<endl;
        }
        return tok;
    }
    template<typename T>
    istream &operator >>(istream &tok, GMatrica<T> &m) {
        char znak;
        if(tok.peek()!= '[')  tok.setstate(std::ios::failbit);
        tok>>std::ws;
        tok>>znak;
        T broj;
        vector<T> pom;
        vector<vector<T> > mat;
        while(znak!=']') {
            znak='*';
            while((znak!=';' && znak!=']') || znak==',') { tok>>broj; pom.push_back(broj); tok>>znak; if(znak!=';' && znak!=']' && znak!=',') tok.setstate(std::ios::failbit); }
            mat.push_back(pom);
            pom.resize(0);
            
        }
        GMatrica<T> pommat(mat);
        m=pommat;
        return tok;
        
    }
                                                                                            //[1,2;3,4]
int main ()
{
   GMatrica<double> m1({{1, 2,3}, {3, 4,5}});
   GMatrica<int> m2(m1);
   m1+=m2;
   std::cout <<setw(10)<< m1 << std::endl;
   GMatrica<double> m4({{1, 2}, {3, 4}});
   //auto m5 = m3-m4;
   //std::cout << m5 << std::endl;
	return 0;
}