/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
//STRUKTURA MATRICA
template <typename TipElemenata>
    struct Matrica {
        int br_redova,br_kolona;
        TipElemenata **elementi=nullptr;
    };
//FUNKICJA KOJA UNISTAVA MATRICU
template <typename TipElemenata>
    void UnistiMatricu (Matrica<TipElemenata> mat) {
        if (!mat.elementi) return;
        for (int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
//FUNKCIJA KOJA STVARA MATRICU
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu (int br_redova, int br_kolona) {
        Matrica<TipElemenata> mat;
        mat.br_redova=br_redova;
        mat.br_kolona=br_kolona;
        mat.elementi= new TipElemenata*[br_redova];
        for (int i=0; i<br_redova; i++)
            mat.elementi[i]=nullptr;
        try {
            for (int i=0; i<br_redova; i++)
                mat.elementi[i]= new TipElemenata[br_kolona];
        }
        catch (...) {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
//FUNKCIJA KOJA SLUZI ZA UNOS ELEMENATA MATRICE
template <typename TipElemenata>
    void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat) {
        for (int i=0; i<mat.br_redova; i++)
            for (int j=0; j<mat.br_kolona; j++) {
                std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                std::cin>>mat.elementi[i][j];
            }
    }
//FUNKCIJA ZA ISPIS MATRICE NA EKRAN
template <typename TipElemenata>
    void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
        for (int i=0; i<mat.br_redova; i++) {
            for (int j=0; j<mat.br_kolona; j++)
                std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
            std::cout<<std::endl;
        }
        if (treba_brisati) UnistiMatricu(mat);
    }
//FUNKCIJA SABIRA DVIJE MATRICE
template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if (m1.br_kolona != m2.br_kolona || m1.br_redova != m2.br_redova) throw std::domain_error("Matrice nisu jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
        for (int i=0; i<m1.br_redova; i++) 
            for (int j=0; j<m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        UnistiMatricu(m1);
        return m3;
    }
//FUNKCIJA MNOZI DVIJE MATRICE
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if (m1.br_kolona!=m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
        for (int i=0; i<m1.br_redova; i++)
            for (int j=0; j<m2.br_kolona; j++) {
                TipElemenata suma=0;
//std::cout<<"\n"<<suma<<" suma\n";
                for (int k=0; k<m2.br_redova; k++) {
                    suma+=(m1.elementi[i][k])*(m2.elementi[k][j]);
//std::cout<<"\n"<<suma<<" suma\n";
                }
                m3.elementi[i][j]=suma;
                suma=0;
            }
        return m3;
    }
//funkcija koja mnozi matricu sa nekim brojem
template <typename TipElemenata>
    Matrica<TipElemenata> Matrica_x_broj (double broj, Matrica<TipElemenata> A) {
        for (int i=0; i<A.br_redova; i++)
            for (int j=0; j<A.br_kolona; j++)
                A.elementi[i][j]=A.elementi[i][j]*broj;
        return A;
    }
    
template <typename TipElemenata>
    void Prekopiraj_elemente (const Matrica<TipElemenata> &C, Matrica<TipElemenata> A) {
        for (int i=0; i<A.br_redova; i++)
            for (int j=0; j<A.br_kolona; j++)
                C.elementi[i][j]=A.elementi[i][j];
    }

//FUNKCIJA KOJA RACUNA POLINOM MATRICE
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> A, std::vector<double> koef) {
        if (A.br_kolona!=A.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
        auto P(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
        auto I(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
        for (int i=0; i<A.br_redova; i++)
            for (int j=0; j<A.br_kolona; j++) {
                if (i==j) I.elementi[i][j]=1;
                else I.elementi[i][j]=0;
            }
//        Prekopiraj_elemente(P,I);
        auto C(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
//        Prekopiraj_elemente(C,I);
        for (int k=0; k<koef.size(); k++) {
            Prekopiraj_elemente(C,A);
 //IspisiMatricu(A,10,6);
            if (k==0) {
                I=Matrica_x_broj(koef[k],I);
                Prekopiraj_elemente(P,I);
            }
            else {
                if (k!=1)
                for (int a=2; a<=k; a++) {
                    auto B=ProduktMatrica(C,A);
                    Prekopiraj_elemente(C,B);
                    UnistiMatricu(B);
                }
//IspisiMatricu(C,10,6); std::cout<<"druga\n"; }
//                C=Matrica_x_broj(koef[k],C);
//std::cout<<" matrica C "<<k<<std::endl;
                P=ZbirMatrica(P,Matrica_x_broj(koef[k],C));
    //            Prekopiraj_elemente(P,K);
    //            UnistiMatricu(K);
//std::cout<<" P: ";IspisiMatricu(P,10,6);
            }
        }
        UnistiMatricu(I);
        UnistiMatricu(C);
        return P;
    }

int main ()
{
    Matrica<double> A,pol;
    int m;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    try {
        A=StvoriMatricu<double>(m,m);
        std::cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A',A);
        int red_polinoma;
        std::cout<<"Unesite red polinoma: ";
        std::cin>>red_polinoma;
        std::vector<double> koeficijenti;
        std::cout<<"Unesite koeficijente polinoma: ";
        double k;
        for (int i=0; i<=red_polinoma; i++) {
            std::cin>>k;
            koeficijenti.push_back(k);
        }
        IspisiMatricu(pol=MatricniPolinom(A,koeficijenti),10,6);
    }
    catch (std::domain_error a) {
        std::cout<<a.what();
    }
    catch (std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(A);
    UnistiMatricu(pol);
	return 0;
}

//ispraviti funkciju koja mnozi matrice