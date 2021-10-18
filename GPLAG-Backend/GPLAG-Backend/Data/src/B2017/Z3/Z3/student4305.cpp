/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipEl>
    struct Matrica {
        int br_redova, br_kolona;
        TipEl** elementi = nullptr;
    };
    
template <typename TipEl>
    void UnistiMatricu(Matrica<TipEl> mat) {
        if (!mat.elementi) return;
        for (int i = 0 ; i < mat.br_redova ; i++)
            delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi = nullptr;
    } 

template <typename TipEl>
    Matrica<TipEl> StvoriMatricu (int br_redova, int br_kolona) {
        Matrica<TipEl> mat;
        mat.br_redova = br_redova;
        mat.br_kolona = br_kolona;
        try {
            mat.elementi = new TipEl*[br_redova];
            for (int i = 0 ; i < br_redova ; i++) mat.elementi[i] = nullptr;
                try {
                    for (int i = 0 ; i < br_redova ; i++)
                        mat.elementi[i] = new TipEl[br_kolona];
                }
                catch(std::bad_alloc) {
                    UnistiMatricu(mat);
                    throw;
                }
        }
        catch (std::bad_alloc) {
            delete[] mat.elementi;
            throw;
        }
       
        return mat;
    }
    
template <typename TipEl>
    void UnesiMatricu (char ime_matrice, Matrica<TipEl> &mat) {
        for (int i = 0 ; i < mat.br_redova ; i++) {
            for (int j = 0 ; j < mat.br_kolona ; j++) {
                std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
        }
    } 
    
template <typename TipEl>
    void IspisiMatricu (const Matrica<TipEl> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
        for (int i = 0 ; i < mat.br_redova ; i++) {
            for (int j = 0 ; j < mat.br_kolona ; j++) {
                std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
            }
            std::cout << std::endl;
        }
        if (treba_brisati == true) {
            UnistiMatricu(mat);
        }
    }
    
template <typename TipEl>
    Matrica<TipEl> ZbirMatrica (const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
        if (m1.br_redova !=  m2.br_redova || m1.br_kolona != m2.br_kolona)
            throw std::domain_error ("Matrice nemaju jednake dimenzije!");
        try {
            auto m3 = StvoriMatricu<TipEl>(m1.br_redova, m1.br_kolona);
            for (int i = 0 ; i < m1.br_redova ; i++) 
                for (int j = 0 ; j < m1.br_kolona ; j++) 
                    m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
            return m3;
        } catch (std::bad_alloc) {
            throw;
        }
    }
  
  
template <typename TipEl>
    Matrica<TipEl> ProduktMatrica (const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
        if (m1.br_kolona != m2.br_redova)
            throw std::domain_error ("Matrice nisu saglasne za mnozenje");
            Matrica<TipEl> m3;
        try {
            m3 = StvoriMatricu<TipEl>(m1.br_redova, m2.br_kolona);
            for(int i = 0; i < m3.br_redova; i++)
                for(int j = 0; j < m3.br_kolona; j++)
                    m3.elementi[i][j] = decltype(m1.elementi[0][0] * m2.elementi[0][0])();
            
            for(int i = 0; i < m1.br_redova; ++i)
                for(int j = 0; j < m2.br_kolona; ++j)
                for(int k = 0; k < m1.br_kolona; ++k) {
                        m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
                }
        }
        
         catch (std::bad_alloc) {
            throw;
        }
       
        return m3;
    }
    
template <typename TipEl, typename TipBroj>
    Matrica<TipEl> PomnoziBrojSaMatricom (const Matrica<TipEl> &m1, TipBroj broj) {
        Matrica<TipEl> m2;
        try {
            m2 = StvoriMatricu<TipEl>(m1.br_redova, m1.br_kolona);
            for (int i = 0 ; i < m1.br_redova ; i++) {
            for (int j = 0 ; j < m1.br_kolona ; j++) {
                m2.elementi[i][j] = broj * m1.elementi[i][j];
            }
        }
        } catch (std::bad_alloc) {
            throw;
        }
        
        return m2;
    } 
    
template<typename TipEl>
Matrica<TipEl> MatricniPolinom(const Matrica<TipEl> &A, std::vector<double> koeficijenti) {
    if (koeficijenti.size() < 0)
        throw std::domain_error("Neispravan stepen polinoma");
    if (A.br_redova != A.br_kolona)
        throw std::domain_error("Matrica mora biti kvadratna");
    
    //jedinicna matrica za nulti stepen  
    Matrica<TipEl> I = StvoriMatricu<TipEl>(A.br_redova, A.br_kolona);
    for (int i = 0 ; i < A.br_redova ; i++)
        for (int j = 0 ; j < A.br_kolona ; j++)
            if (i != j)
                I.elementi[i][j] = 0;
            else 
                I.elementi[i][j] = 1;
    Matrica<TipEl> rezultat = PomnoziBrojSaMatricom(I, koeficijenti[0]);
    //da odmah dealocira memoriju za jedinicnu
    UnistiMatricu(I);
    if (koeficijenti.size() == 1) 
        return rezultat;
        
    Matrica<TipEl> prviClan = PomnoziBrojSaMatricom(A, koeficijenti[1]);
    //Matrica<TipEl> temp = rezultat;
    rezultat = ZbirMatrica(rezultat, prviClan);
    //dealokacija matrica
    //UnistiMatricu(temp);
    //UnistiMatricu(prviClan);
    if (koeficijenti.size() == 2) 
        return rezultat;
    
    for (int i = 2; i < koeficijenti.size(); i++) {
        Matrica<TipEl> stepenovana = StvoriMatricu<TipEl>(A.br_redova, A.br_kolona);
        for (int k = 0; k < A.br_redova; k++)
            for (int l = 0; l < A.br_kolona; l++)
                stepenovana.elementi[k][l] = A.elementi[k][l];
        for (int j = 1; j < i; j++) {
            Matrica<TipEl> temp = stepenovana;
            stepenovana = ProduktMatrica(stepenovana, A);
            UnistiMatricu(temp);
        }
        Matrica<TipEl> pomnozenaSaBrojem = PomnoziBrojSaMatricom(stepenovana, koeficijenti[i]);
        UnistiMatricu(stepenovana);
        
        Matrica<TipEl> temp1 = rezultat;
        rezultat = ZbirMatrica(rezultat, pomnozenaSaBrojem);
        UnistiMatricu(pomnozenaSaBrojem);
        UnistiMatricu(temp1);
    }
    
    return rezultat;
}



int main ()
{
    Matrica<int> a;
    try {
        std::cout << "Unesite dimenziju kvadratne matrice: ";
        int dimenzija;
        std::cin >> dimenzija;
        a = StvoriMatricu<int>(dimenzija, dimenzija);
        std::cout << "Unesite elemente matrice A:" << std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        int red;
        std::cin >> red;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> koef;
        for (int i = 0 ; i <= red ; i++) {
            double element;
            std::cin >> element;
            koef.push_back(element);
        }
        Matrica<int> polinom = MatricniPolinom(a, koef);
        IspisiMatricu(polinom, 10);
        UnistiMatricu(a);
        UnistiMatricu(polinom);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema memorije!";
        UnistiMatricu(a);
    }
    
	return 0;
}
