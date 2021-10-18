/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template<typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};
/*template<typename TipElemenata>
void UnistiMatricu(const Matrica<TipElemenata> &mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
}*/
template<typename TipElemenata>
void UnistiMatricu(const Matrica<TipElemenata> &mat)
{
   // if(mat.elementi==nullptr) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
}
template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi=nullptr;
    try {
        mat.elementi = new TipElemenata*[br_redova];
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = nullptr;
        try {
            for(int i = 0; i < br_redova; i++)
                mat.elementi[i] = new TipElemenata[br_kolona];
        } catch(...) {
            for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;

            throw;
        }
    } catch(...) {
        for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;

        throw;
    }
    return mat;
}
template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati)
        UnistiMatricu(mat);

}
template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
        Matrica<TipElemenata> m3;
    try{
     m3=StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}
catch(...){
    UnistiMatricu(m3);
    throw;
}
}
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> a, Matrica<TipElemenata> b)
{
    if(a.br_kolona != b.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<double> c ;
    try {

        c= StvoriMatricu<TipElemenata>(a.br_redova, b.br_kolona);
        for(int i = 0; i < c.br_redova; i++)
            for(int j = 0; j < c.br_kolona; j++)
                c.elementi[i][j] = 0;
        for(int i = 0; i < a.br_redova; i++)
            for(int j = 0; j < b.br_kolona; j++)
                for(int k = 0; k < a.br_kolona; k++)
                    c.elementi[i][j] += a.elementi[i][k] * b.elementi[k][j];

    } catch(...) {
        UnistiMatricu(c);
        throw;
    }
    return c;
}
template<typename TipElemenata>
Matrica<TipElemenata> mnozenjeSkalarom(double x, Matrica<TipElemenata> a)
{

    Matrica<TipElemenata> b ;
    try {
        b= StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona);

        for(int i = 0; i < b.br_redova; i++)
            for(int j = 0; j < b.br_kolona; j++)
                b.elementi[i][j] = x * a.elementi[i][j];

    } catch(...) {
        UnistiMatricu(b);
        throw;
    }
    return b;
}
template<typename TipElemenata>
Matrica<TipElemenata> StvoriJedinicnu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    try {
        mat.elementi = new TipElemenata*[br_redova];
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = nullptr;
        try {
            for(int i = 0; i < br_redova; i++)
                mat.elementi[i] = new TipElemenata[br_kolona];
            for(int i = 0; i < mat.br_redova; i++)
                for(int j = 0; j < mat.br_kolona; j++) {
                    if(i == j)
                        mat.elementi[i][j] = 1;
                    else
                        mat.elementi[i][j] = 0;
                }
        } catch(...) {
            UnistiMatricu(mat);
            throw;
        }
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }

    return mat;
}
template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> a, std::vector<double> koef)
{
    if(a.br_kolona != a.br_redova)
        throw std::domain_error("Matrica mora biti kvadratna");
    if(koef.size() == 0) {
        Matrica<TipElemenata> b ;
        try {
             b= StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona);
            for(int i = 0; i < b.br_redova; i++)
            for(int j = 0; j < b.br_kolona; j++)
                b.elementi[i][j] = 0;
           
        } catch(...) {
            UnistiMatricu(b);
            throw;
        }
        
        return b;
    }
    Matrica<TipElemenata> b, povratna;
    try{
    povratna = StvoriJedinicnu<TipElemenata>(a.br_redova, a.br_kolona);
    b = mnozenjeSkalarom(koef[0], povratna);
    UnistiMatricu(povratna);
    povratna = b;
    //b.elementi = nullptr;
    b.br_redova = 0;
    b.br_kolona = 0;
    Matrica<TipElemenata> c;
    }
    catch(...){
         UnistiMatricu(povratna);
        UnistiMatricu(b);
    }
    try{
        b = StvoriJedinicnu<TipElemenata>(a.br_redova, a.br_kolona);
    for(int i = 1; i < koef.size(); i++) {
        Matrica<TipElemenata> pomocna;
        Matrica<TipElemenata> c;
        try{
        pomocna= ProduktMatrica(b, a);
        
        UnistiMatricu(b);
        b = pomocna;
        UnistiMatricu(b);
        pomocna.elementi = nullptr;
        pomocna = mnozenjeSkalarom(koef[i], b);
        c = ZbirMatrica(pomocna, povratna);
        UnistiMatricu(povratna);
        UnistiMatricu(pomocna);
        povratna = c;
        c.elementi = nullptr;
        UnistiMatricu(c);
        }
        catch(...){
            UnistiMatricu(povratna);
            UnistiMatricu(c);
            UnistiMatricu(pomocna);
            throw;
        }
        }
        
        
    }
    catch(...){
        UnistiMatricu(b);
        throw;
    }


    return povratna;
}
int main ()
{
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int m;
    std::cin >> m;
    Matrica<double> a;
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A:\n";
    UnesiMatricu('A', a);
    std::cout << "Unesite red polinoma: ";
    std::cin >> m;
    std::cout << "Unesite koeficijente polinoma: ";
    double x;
    std::vector<double> v;
    for(int i = 0; i < m; i++) {
        std::cin >> x;
        v.push_back(x);
    }
    IspisiMatricu(MatricniPolinom(a, v), 7, 6, true);
    //UnistiMatricu(a);
    for(int i = 0; i < m; i++) {
        std::cin >> x;
        v.push_back(x);
    }
    IspisiMatricu(MatricniPolinom(a, v), 7, 6, true);
    
	return 0;
}