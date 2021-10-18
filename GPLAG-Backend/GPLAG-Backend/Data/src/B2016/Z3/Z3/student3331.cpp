/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>



template <typename TipElemenata>
 struct Matrica {
 int br_redova, br_kolona;
 TipElemenata **elementi = nullptr; 
 };

template <typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat) {
 if(!mat.elementi) return;
 for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
 delete[] mat.elementi;
 mat.elementi = nullptr;
 }

template <typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
 Matrica<TipElemenata> mat;
 mat.br_redova = br_redova; 
 mat.br_kolona = br_kolona;
 mat.elementi = new TipElemenata*[br_redova];
 for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
 try {
 for(int i = 0; i < br_redova; i++)
 mat.elementi[i] = new TipElemenata[br_kolona];
 }
 catch(...) {
 UnistiMatricu(mat);
 throw;
 }
 return mat;
 }

template <typename TipElemenata>
 void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
 for(int i = 0; i < mat.br_redova; i++)
 for(int j = 0; j < mat.br_kolona; j++) {
 std::cout << ime_matrice
 << "(" << i + 1 << "," << j + 1 << ") = ";
 std::cin >> mat.elementi[i][j];
 }
 }

template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa , int preciznost = 6, bool treba_brisati = false) { // il nije podrazumijevano 10
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
 std::cout << std::endl;
 }
 if (treba_brisati == true) UnistiMatricu(mat);
 }

template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }
 

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if( m1.br_kolona != m2.br_redova ) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto mat( StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona) );
    
    for(int i = 0; i < m1.br_redova; i++) 
        for(int j = 0; j < m2.br_kolona; j++) {
            double suma = 0;
            for(int k = 0; k < m2.br_redova; k++) suma += m1.elementi[i][k] * m2.elementi[k][j];
            mat.elementi[i][j] = suma;
        }
        
       
        
        return mat;
}

/*bool jelKvadratna(const Matrica<double> &m) {
    for(int i = 0; i < m.br_redova; i++) if(m.br_redova != m.br_kolona) return false; //wtf kako provjerit
    return true;
}*/
template <typename TipElemenata>
void JedinicnaMat(Matrica<TipElemenata> &jedinicna) {
    for(int i = 0; i < jedinicna.br_redova; i++) 
    for(int j = 0; j < jedinicna.br_kolona; j++) {
        if(i == j) jedinicna.elementi[i][j] = 1;
        else jedinicna.elementi[i][j] = 0;
    }
}

template <typename TipElemenata, typename TipKoeficijenta>
Matrica<TipElemenata> PomnoziSKoeficijentom(TipKoeficijenta koef ,const Matrica<TipElemenata> &m) {
    auto mat ( StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int i = 0; i < m.br_redova; i++)
    for(int j = 0; j < m.br_kolona; j++) {
        mat.elementi[i][j] = m.elementi[i][j]*koef;
    }
    return mat;
}

template <typename TipElemenata>
Matrica<TipElemenata> Prepisi(const Matrica<TipElemenata> &m) {
    auto mat (StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    
    for(int i = 0; i < m.br_redova; i++) {
    for(int j = 0; j < m.br_kolona; j++)
    mat.elementi[i][j] = m.elementi[i][j];
    }
    
    return mat;
}


template <typename TipElemenata, typename TipKoeficijenta>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, std::vector<TipKoeficijenta> koeficijenti) {
    if(A.br_kolona != A.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    
    auto jedinicna( StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona) );
    JedinicnaMat(jedinicna);
    
    Matrica<TipElemenata> pomocna,pomocna1,unisti,uni,mat;
   
    
    
    pomocna = PomnoziSKoeficijentom(koeficijenti[0],jedinicna);
    if(koeficijenti.size() > 1) {
    unisti = PomnoziSKoeficijentom(koeficijenti[1],A); 
    mat  = ZbirMatrica(unisti, pomocna);
    UnistiMatricu(unisti);
    UnistiMatricu(jedinicna);
    UnistiMatricu(pomocna);
    pomocna = Prepisi(A);
    }
    else {
    mat = Prepisi(pomocna);
    UnistiMatricu(jedinicna);    
    }
    
    
   
     for(int sabrat = 2; sabrat < koeficijenti.size(); sabrat++) {
         uni = ProduktMatrica(pomocna,A);
         pomocna1 = PomnoziSKoeficijentom(koeficijenti[sabrat],uni);
         
         UnistiMatricu(pomocna);
         
         unisti = ZbirMatrica(pomocna1,mat);
         
         pomocna = Prepisi(uni);
         
         UnistiMatricu(uni);
         UnistiMatricu(pomocna1);
         UnistiMatricu(mat);
         
         mat = Prepisi(unisti);
         
         UnistiMatricu(unisti);
    }
    UnistiMatricu(pomocna);
    
    
   
    
    return mat;
}
 


int main ()
{
    Matrica<double> mat;
    try{
        std::cout<<"Unesite dimenziju kvadratne matrice: ";
        int dimenzija;
        std::cin>>dimenzija;
        std::cout<<"Unesite elemente matrice A: "<<std::endl;
        
        mat = StvoriMatricu<double>(dimenzija,dimenzija);
        UnesiMatricu('A',mat);
        std::cout<<"Unesite red polinoma: ";
        int red;
        std::cin>>red;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> koeficijentiP;
        double broj;
        for(int i = 0; i < red+1; i++) {
            std::cin>>broj;
            koeficijentiP.push_back(broj);
        }
        
        auto ma = MatricniPolinom(mat, koeficijentiP);
        IspisiMatricu(ma,10,6,true);
       
      
        
    }catch(std::domain_error d) {
        std::cout << d.what() << std::endl;
    }catch(std::bad_alloc b) {
        std::cout << b.what() << std::endl;
    }
    UnistiMatricu(mat);
    
   
    
  
    
	return 0;
}