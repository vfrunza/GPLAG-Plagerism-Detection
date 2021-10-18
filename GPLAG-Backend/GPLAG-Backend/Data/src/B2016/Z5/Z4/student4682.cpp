#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>

template <typename T>
class GMatrica{
    T matrica[4][4];
    int redovi,kolone;
    public:
    GMatrica();
    GMatrica(int red, int kolona, T inicijaliziraj = 0);
    template <typename T2>
    GMatrica(GMatrica<T2> mat);
    template <typename T2>
    GMatrica(T2 **mat);
    template <typename T2>
    GMatrica(std::vector<std::vector<T2>> mat);
    template <typename T2>
    GMatrica(std::initializer_list<std::initializer_list<T2>> lista);
    int DajBrojRedova() const { return redovi;}
    int DajBrojKolona() const { return kolone;}
    
    template <typename T2, typename T3>
    friend auto operator +(GMatrica<T2> mat1, GMatrica<T3> mat2) -> decltype(GMatrica<decltype(mat1[0][0]+mat2[0][0])>(mat1.DajBrojRedova(),mat2.DajBrojKolona(),mat1[0][0]+mat2[0][0]));
    template <typename T3>
    GMatrica &operator +=(GMatrica<T3> &mat2);
    template <typename T2, typename T3>
    friend auto operator *(GMatrica<T2> mat1, GMatrica<T3> mat2) -> decltype(GMatrica<decltype(mat1[0][0]*mat2[0][0])>(mat1.DajBrojRedova(),mat2.DajBrojKolona(),mat1[0][0]*mat2[0][0]));
    template <typename T2, typename T3>
    friend GMatrica<T3> operator *(T2 br, GMatrica<T3> mat2);
    template <typename T2, typename T3>
    friend GMatrica<T2> operator *(GMatrica<T2> mat1,T3 br);
    template < typename T3>
    GMatrica &operator *=(GMatrica<T3> &mat2);
    template < typename T3>
    GMatrica &operator *=(T3 broj);
    template <typename T2, typename T3>
    friend auto operator -(GMatrica<T2> mat1, GMatrica<T3> mat2) -> decltype(GMatrica<decltype(mat1[0][0]-mat2[0][0])>(mat1.DajBrojRedova(),mat2.DajBrojKolona(),mat1[0][0]-mat2[0][0]));
    template <typename T3>
    GMatrica &operator -=(GMatrica<T3> &mat2);
    T &operator ()(int i, int j);
    T *operator [](int i);
    constexpr T operator () (int i, int j);
    constexpr T *operator [] (int i);
    template <typename T3>
    friend std::ostream &operator <<(std::ostream &tok, GMatrica<T3> & mat1);
    template <typename T3>
    friend std::istream &operator >>(std::istream &tok, GMatrica<T3> & mat1);
};
template <typename T, typename T2>
bool operator ==(GMatrica<T> &mat1, GMatrica<T2> &mat2);
template <typename T, typename T2>
bool operator !=(GMatrica<T> &mat1, GMatrica<T2> &mat2);

int main ()
{
   GMatrica<int> m1;
   std::cin >> m1;
   std::cout << m1 << std::endl;
	return 0;
}
template <typename T>
GMatrica<T>::GMatrica(): redovi(0),kolone(0){}
template <typename T>
GMatrica<T>::GMatrica(int red, int kolona, T inicijaliziraj): redovi(red), kolone(kolona){
        if(red < 0 || red > 4 || kolona < 0 || kolona > 4)
            throw std::logic_error("Ilegalan format matrice");
        for(int i(0); i < red; i++)
            for(int j(0); j < kolona; j++)
                matrica[i][j] = inicijaliziraj;
    }
template <typename T>
template <typename T2>
GMatrica<T>::GMatrica(GMatrica<T2> mat): redovi(mat.redovi),kolone(mat.kolone){
        for(int i(0); i < redovi; i++)
            for(int j(0); j < kolone; j++)
                matrica[i][j] = mat[i][j];
    }
template <typename T>
template <typename T2>
GMatrica<T>::GMatrica(T2 **mat): redovi(4),kolone(4){
        for(int i(0); i < redovi; i++)
            for(int j(0); j < kolone; j++)
                matrica[i][j] = mat[i][j];
    }
template <typename T>
template <typename T2>
GMatrica<T>::GMatrica(std::vector<std::vector<T2>> mat): redovi(mat.size()),kolone(mat[0].size()){
        if(redovi < 0 || redovi > 4 || kolone < 0 || kolone > 4)
            throw std::logic_error("Ilegalan format matrice");
        for(int i(0); i < redovi; i++)
            if(mat[i].size() != mat[0].size())
                throw std::logic_error("Ilegalan format matrice");
            
        for(int i(0); i < redovi; i++)
            for(int j(0); j < kolone; j++)
                matrica[i][j] = mat[i][j];
}
template<typename T>
template<typename T2>
GMatrica<T>::GMatrica(std::initializer_list<std::initializer_list<T2>> mat){
    auto it(mat.begin());
    redovi = mat.size();
    kolone = (*it).size();
    if(mat.size() < 0 || mat.size() > 4 || (*it).size() < 0 || (*it).size() > 4)
            throw std::logic_error("Ilegalan format matrice");
        for(int i(0); i < redovi; i++)
            if((*(it+i)).size() != (*it).size())
                throw std::logic_error("Ilegalan format matrice");
                
        redovi = mat.size();
        kolone = (*it).size();
        
    int i(0),j(0);
    for(auto x: mat){
        for(auto y: x){
            matrica[i][j] = y;
            j++;
        }
        j = 0;
        i++;
    }
}
            

template <typename T2, typename T3>
auto operator +(GMatrica<T2> mat1, GMatrica<T3> mat2) -> decltype(GMatrica<decltype(mat1[0][0]+mat2[0][0])>(mat1.DajBrojRedova(),mat2.DajBrojKolona(),mat1[0][0]+mat2[0][0])){
    if(mat1.redovi != mat2.redovi || mat1.kolone != mat2.kolone)
        throw std::domain_error("Nedozvoljena operacija");
    
   decltype(GMatrica<decltype(mat1[0][0]+mat2[0][0])>(mat1.DajBrojRedova(),mat2.DajBrojKolona(),mat1[0][0]+mat2[0][0])) mat3(mat1);
    mat3 += mat2;
    return mat3;
}
template <typename T>
template <typename T3>
GMatrica<T> &GMatrica<T>::operator +=(GMatrica<T3> &mat2){
    if(redovi != mat2.redovi || kolone != mat2.kolone)
        throw std::domain_error("Nedozvoljena operacija");

        for(int i(0); i < redovi; i++)
            for(int j(0); j < kolone; j++)
                matrica[i][j] += mat2.matrica[i][j];
    return *this;
}

template <typename T2, typename T3>
auto operator -(GMatrica<T2> mat1, GMatrica<T3> mat2) -> decltype(GMatrica<decltype(mat1[0][0]-mat2[0][0])>(mat1.DajBrojRedova(),mat2.DajBrojKolona(),mat1[0][0]-mat2[0][0])){
    if(mat1.redovi != mat2.redovi || mat1.kolone != mat2.kolone)
        throw std::domain_error("Nedozvoljena operacija");
        
    decltype(GMatrica<decltype(mat1[0][0]-mat2[0][0])>(mat1.DajBrojRedova(),mat2.DajBrojKolona(),mat1[0][0]-mat2[0][0])) mat3(mat1);
    mat3 -= mat2;
    
    return mat3;
}
template <typename T>
template < typename T3>
GMatrica<T> &GMatrica<T>::operator -=(GMatrica<T3> &mat2){
    if(redovi != mat2.redovi || kolone != mat2.kolone)
        throw std::domain_error("Nedozvoljena operacija");
        
         for(int i(0); i < redovi; i++)
            for(int j(0); j < kolone; j++)
                matrica[i][j] -= mat2.matrica[i][j];
    return *this;
  
}
template <typename T2, typename T3>
auto operator *(GMatrica<T2> mat1, GMatrica<T3> mat2) -> decltype(GMatrica<decltype(mat1[0][0]*mat2[0][0])>(mat1.DajBrojRedova(),mat2.DajBrojKolona(),mat1[0][0]*mat2[0][0])){
     if(mat1.kolone != mat2.redovi) throw std::domain_error("Nedozvoljena operacija");
     decltype(GMatrica<decltype(mat1[0][0]*mat2[0][0])>(mat1.DajBrojRedova(),mat2.DajBrojKolona(),mat1[0][0]*mat2[0][0])) mat3(mat1);
     mat3 *= mat2;
     return mat3;
}
template <typename T>
template <typename T3>
GMatrica<T> &GMatrica<T>::operator *=(GMatrica<T3> &mat2){
    if(kolone != mat2.redovi) throw std::domain_error("Nedozvoljena operacija");
    
    GMatrica<T> treca(*this);  
        for(int i(0); i < treca.br_redova; i++)
            for(int j(0); j < mat2.br_kolona; j++)
            matrica[i][j] = 0; 
        
        for(int i(0); i < treca.br_redova; i++)
            for(int j(0); j < mat2.br_kolona; j++)
                for(int k(0); k <treca.br_kolona; k++)
                    matrica[i][j] += treca.matrica[i][k]*mat2.matrica[k][j];
    return *this;
}
template <typename T, typename T2>
bool operator ==(GMatrica<T> &mat1, GMatrica<T2> &mat2){
    if(mat1.DajBrojRedova() != mat2.DajBrojRedova() || mat1.DajBrojKolona() != mat2.DajBrojKolona())
        return false;
    for(int i(0); i < mat1.DajBrojRedova(); i++)
        for(int j(0); j < mat1.DajBrojKolona(); j++)
            if(mat1[i][j] != mat2[i][j])
                return false;
    return true;
}
template <typename T, typename T2>
bool operator !=(GMatrica<T> &mat1, GMatrica<T2> &mat2){
    return !(mat1 == mat2);
}
template <typename T>
T &GMatrica<T>::operator ()(int i, int j){
    if(i < 1 || i > redovi || j < 1 || j > kolone) throw std::range_error("Nedozvoljen indeks");
    return matrica[i-1][j-1];
}
template <typename T>
T *GMatrica<T>::operator [](int i){
    return matrica[i];
}
template <typename T>
constexpr T GMatrica<T>::operator ()(int i, int j){
    if(i < 1 || i > redovi || j < 1 || j > kolone) throw std::range_error("Nedozvoljen indeks");
    return matrica[i-1][j-1];
}
template <typename T>
constexpr T *GMatrica<T>::operator [](int i){
    return matrica[i];
}
template <typename T3>
std::ostream &operator <<(std::ostream &tok, GMatrica<T3> & mat1){
        int sirina(tok.width());
        if(sirina < 6) sirina = 6;
        for(int i(1); i < mat1.redovi+1; i++){
            for(int j(1); j < mat1.kolone+1; j++)
                tok << std::setw(sirina) << mat1(i,j);
            tok<<std::endl;
        }
    return tok;
    }
template <typename T3>
std::istream &operator >>(std::istream &tok, GMatrica<T3> &mat1){
        char znak;
        tok>>znak;
        if(znak == '['){
            ++mat1.redovi;
            ++mat1.kolone;
            for(int i(0); i < mat1.redovi; i++){
                for(int j(0); j < mat1.kolone; j++){
                    if(!(tok>>mat1[i][j]>>znak))
                        tok.setstate(std::ios::failbit);
                    if(znak == ',')
                        ++mat1.kolone;
                    if(znak != ',' && znak != ';')
                        tok.setstate(std::ios::failbit);
                }
                if(znak != ';')
                    tok.setstate(std::ios::failbit);
                if(znak == ';'){
                    ++mat1.redovi;
                    mat1.kolone = 1;
                }
            }
            if(znak != ']')
                tok.setstate(std::ios::failbit);
        }
        else tok.setstate(std::ios::failbit);
        return tok;
    }
template <typename T2, typename T3>
GMatrica<T3> operator *(T2 br, GMatrica<T3> mat2){
    for(int i(0); i < mat2.redovi; i++)
        for(int j(0); j < mat2.kolone; j++)
            mat2[i][j] *= br;
    return mat2;
}
template <typename T2, typename T3>
GMatrica<T2> operator *(GMatrica<T2> mat1,T3 br){
    mat1 *= br;
    return mat1;
}
template <typename T>
template < typename T3>
GMatrica<T> &GMatrica<T>::operator *=(T3 broj){
    for(int i(0); i < redovi; i++)
        for(int j(0); j < kolone; j++)
            matrica[i][j] *= broj;
    return *this;
}