/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template<typename TipElemenata>
    struct Matrica
    {
        int br_redova, br_kolona;
        TipElemenata **elementi=nullptr;
    };

template<typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> mat)
    {
        if (!mat.elementi) return;
        for (int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }

template<typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
    {
        Matrica<TipElemenata> mat;
        mat.br_redova=br_redova; mat.br_kolona=br_kolona;
        mat.elementi=new TipElemenata *[br_redova];
        for (int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
        try
        {
            for (int i=0; i<br_redova; i++) mat.elementi[i]=new TipElemenata[br_kolona];
        }
        catch(...)
        {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
    
template<typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
    {
        for (int i=0; i<mat.br_redova; i++)
        {
            for (int j=0; j<mat.br_kolona; j++)
            {
                std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
        }
    }
    
template<typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
    {
        for (int i=0; i<mat.br_redova; i++)
        {
            for (int j=0; j<mat.br_kolona; j++) 
            {
                std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
            }
            std::cout << std::endl;
        }
        if (treba_brisati) UnistiMatricu(mat);
    }
    
template<typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
    {
        if (m1.br_redova!=m2.br_redova or m1.br_kolona!= m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije");
        Matrica<TipElemenata> m3;
        try
        {
            m3=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
        }
        catch(std::bad_alloc)
        {
            throw;
        }
        for (int i=0; i<m1.br_redova; i++)
        {
            for (int j=0; j<m1.br_kolona; j++) m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
        return m3;
    }
    
template<typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
    {
        if (m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
        Matrica<TipElemenata> m3;
        try
        {
            m3=StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
        }
        catch(std::bad_alloc)
        {
            throw;
        }
        for (int i=0; i<m1.br_redova; i++)
        {
            for (int j=0; j<m2.br_kolona; j++)
            {
                double suma(0);
                for (int k=0; k<m2.br_redova; k++) suma+=m1.elementi[i][k]*m2.elementi[k][j];
                m3.elementi[i][j]=suma;
            }
        }
        return m3;
    }
    
template<typename TipElemenata>
    Matrica<TipElemenata> PrepisiElemente(const Matrica<TipElemenata> &nova, Matrica<TipElemenata> stara)
    {
        for (int i=0; i<nova.br_redova; i++)
        {
            for (int j=0; j<nova.br_kolona; j++) stara.elementi[i][j]=nova.elementi[i][j];
        }
        return stara;
    }

template<typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &M, std::vector<double> v)
    {
        if (M.br_kolona!=M.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
        if (v.size()==0)
        {
            Matrica<TipElemenata> m;
            try
            {
                m=StvoriMatricu<TipElemenata>(M.br_redova, M.br_kolona);
            }
            catch(std::bad_alloc)
            {
                throw;
            }
            for (int i=0; i<m.br_redova; i++)
            {
                for (int j=0; j<m.br_kolona; j++) m.elementi[i][j]=0;
            }
            return m;
        }
        
        //Kreiranje jedinicne matrice i matrice M na nulti stepen
        Matrica<TipElemenata> J, stepena;
        try
        {
            J=StvoriMatricu<TipElemenata>(M.br_redova, M.br_kolona);
            stepena=StvoriMatricu<TipElemenata>(M.br_redova, M.br_kolona);
        }
        catch(std::bad_alloc)
        {
            throw;
        }
        for (int i=0; i<J.br_redova; i++)
        {
            for (int j=0; j<J.br_kolona; j++)
            {
                if (i==j) J.elementi[i][j]=1, stepena.elementi[i][j]=1;
                else J.elementi[i][j]=0, stepena.elementi[i][j]=0;
            }
        }
        //Anuliranje rezultujuce matrice i matrice sume
        Matrica<TipElemenata> rezultujuca, suma;
        try
        {
            rezultujuca=StvoriMatricu<TipElemenata>(M.br_redova, M.br_kolona);
            suma=StvoriMatricu<TipElemenata>(M.br_redova, M.br_kolona);
        }
        catch(std::bad_alloc)
        {
            throw;
        }
        for (int i=0; i<rezultujuca.br_redova; i++)
        {
            for (int j=0; j<rezultujuca.br_kolona; j++) rezultujuca.elementi[i][j]=0, suma.elementi[i][j]=0;
        }
        //Racunanje matricnog polinoma
        for (int i=0; i<v.size(); i++)
        {
            if (i==0)
            {
                for (int j=0; j<J.br_redova; j++)
                {
                    for (int k=0; k<J.br_kolona; k++) rezultujuca.elementi[j][k]=v[i]*J.elementi[j][k];
                }
            }
            else 
            {
                try
                {
                    auto visak=ProduktMatrica(stepena, M);
                    stepena=PrepisiElemente(visak, stepena);
                    UnistiMatricu(visak);
                    for (int j=0; j<stepena.br_redova; j++)
                    {
                        for (int k=0; k<stepena.br_kolona; k++) rezultujuca.elementi[j][k]=v[i]*stepena.elementi[j][k];
                    }
                }
                catch(...)
                {
                    UnistiMatricu(stepena); UnistiMatricu(rezultujuca);
                    UnistiMatricu(suma); UnistiMatricu(J);
                    throw;
                }
            }
            try
            {
                auto visak=ZbirMatrica(rezultujuca, suma);
                suma=PrepisiElemente(visak, suma);
                UnistiMatricu(visak);
            }
            catch(...)
            {
                UnistiMatricu(suma); UnistiMatricu(rezultujuca);
                UnistiMatricu(J); UnistiMatricu(stepena);
                throw;
            }
        }
        UnistiMatricu(J); UnistiMatricu(rezultujuca); UnistiMatricu(stepena);
        return suma;
    }

int main ()
{
    Matrica<double> A;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int dimenzija;
    std::cin >> dimenzija;
    try
    {
        A=StvoriMatricu<double>(dimenzija, dimenzija);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A', A);
        std::cout << "Unesite red polinoma: ";
        int red;
        std::cin >> red;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> koeficijenti(red+1);
        for (int i=0; i<=red; i++) std::cin >> koeficijenti[i];
        auto mat=MatricniPolinom(A, koeficijenti);
        IspisiMatricu(mat, 10, 6, true);
    }
    catch(std::bad_alloc)
    {
        std::cout << "Nema dovoljno memorije!" << std::endl;
    }
    UnistiMatricu(A);
	return 0;
}