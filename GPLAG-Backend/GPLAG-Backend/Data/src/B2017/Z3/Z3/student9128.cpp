#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>

using std::cout;
using std::cin;

template <typename NekiTip> 
struct Matrica {
    int redovi, kolone;
    NekiTip **elementi=nullptr;
};

template <typename NekiTip> 
void IspisiMatricu(const Matrica<NekiTip> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    
    for(int i=0; i<mat.redovi; i++) {
        for(int j=0; j<mat.kolone; j++) {
            cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
        cout<<"\n";
    }
    
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename NekiTip>
void UnistiMatricu(Matrica<NekiTip> mat) {
    if(!mat.elementi) return;
    for(int i=0; i<mat.redovi; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename NekiTip, typename DrugiTip>
void PomnoziSkalarom(Matrica<NekiTip> &mat, DrugiTip skalar) {
    for(int i=0; i<mat.redovi; i++) {
        for(int j=0; j<mat.kolone; j++) {
            mat.elementi[i][j]*=skalar;
        }
    }
}

template <typename NekiTip>
void DodijeliMatrice(Matrica<NekiTip> &m1, const Matrica<NekiTip> &m2) {
    if(m1.redovi!=m2.redovi || m1.kolone!=m2.kolone) throw std::domain_error("Matrice ne mogu biti dodijeljene");
    
    for(int i=0; i<m1.redovi; i++) {
        for(int j=0; j<m1.kolone; j++) {
            m1.elementi[i][j]=m2.elementi[i][j];
        }
    }
}

template <typename NekiTip>
Matrica<NekiTip> KreirajMatricu(int br_red, int br_kolona, NekiTip vrijednost=NekiTip{}) {
    if(br_kolona<0 || br_red<0) throw std::logic_error("Neispravne dimenzije!");
    Matrica<NekiTip> povratna;
    povratna.redovi=br_red;
    povratna.kolone=br_kolona;
    try {
        povratna.elementi=new NekiTip*[br_red];
    } catch(...) {
        throw std::domain_error("Matrica ne moze biti kreirana!");
    } 
    for(int i=0; i<br_red; i++) povratna.elementi[i]=nullptr;
    
    try {
        for(int i=0; i<br_red; i++) {
            povratna.elementi[i]= new NekiTip[br_kolona];
        }
    } catch(...) {
        UnistiMatricu(povratna);
        throw std::domain_error("Matrica ne moze biti kreirana!");
    }
    
    for(int i=0; i<br_red; i++) {
        for(int j=0; j<br_kolona; j++) {
            povratna.elementi[i][j]=vrijednost;
        }
    }
    
    return povratna;
}

template <typename NekiTip> 
void UnesiMatricu(char ime_matrice, Matrica<NekiTip> &mat) {
    for(int i=0; i<mat.redovi; i++) {
        for(int j=0; j<mat.kolone; j++) {
            cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            cin>>mat.elementi[i][j];
        }
    }
}

template <typename NekiTip>
Matrica<NekiTip> JedinicnaMatrica(int redovi, int kolone) {
    if(redovi!=kolone) throw std::domain_error("Matrica nije kvadratna");
    Matrica<NekiTip> mat;
    try {
        mat=KreirajMatricu<NekiTip>(redovi, kolone);
    } catch(...) {
        throw std::domain_error("Greska pri kreiranju jedinicne matrice!");
    }
    for(int i=0; i<redovi; i++) {
        for(int j=0; j<kolone; j++) {
            if(i==j) mat.elementi[i][j]=1;
        }
    }
    return mat;
}

template <typename NekiTip>
Matrica<NekiTip> ZbirMatrica (const Matrica<NekiTip> &m1, const Matrica<NekiTip> &m2) {
    if(m1.redovi!=m2.redovi || m1.kolone!=m2.kolone) throw std::domain_error("Matrice nemaju jednake dimenzije");
    Matrica<NekiTip> m3;
    try {
        m3=KreirajMatricu<NekiTip>(m1.redovi, m1.kolone);
    } catch(...) {
        throw;
    }
    
    for(int i=0; i<m3.redovi; i++) {
        for(int j=0; j<m3.kolone; j++) {
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
}

template <typename NekiTip>
Matrica<NekiTip> ProduktMatrica(const Matrica<NekiTip> &m1, const Matrica<NekiTip> &m2) {
    if(m1.kolone!=m2.redovi) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<NekiTip> m3;
    try {
        m3=KreirajMatricu<NekiTip>(m1.redovi, m1.kolone);
    } catch(...) {
        throw;
    }
    
    for(int i=0; i<m1.redovi; i++) {
        for(int j=0; j<m2.kolone; j++) {
            for(int k=0; k<m1.kolone; k++) {
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    return m3;
}

template <typename NekiTip, typename DrugiTip>
Matrica<NekiTip> MatricniPolinom(const Matrica<NekiTip> &mat, int n, DrugiTip pocetak_bloka) {

    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(mat.redovi!=mat.kolone) throw std::domain_error("Matrica mora biti kvadratna");
    
    std::vector<Matrica<NekiTip>> stepeni_mat;
    try {
        stepeni_mat.resize(n+1);
    } catch(...) {
        throw std::logic_error("Greska pri kreiranju vektora!");
    }
    
    Matrica<NekiTip> pomocna;
    
    try {
        pomocna=KreirajMatricu<NekiTip>(mat.redovi, mat.kolone);
    } catch(...) {
        throw;
    }
    
    Matrica<NekiTip> jedinicna;
    try {
        jedinicna=JedinicnaMatrica<NekiTip>(mat.redovi, mat.kolone);
    } catch(...) {
        UnistiMatricu(pomocna);
        throw;
    }
    
    Matrica<NekiTip> pomocna2;
    
    for(int i=0; i<=n; i++) {
        DodijeliMatrice(pomocna, jedinicna);
        for(int j=0; j<i; j++) {
            try {
                pomocna2=ProduktMatrica(pomocna, mat);
            } catch(...) {
                UnistiMatricu(pomocna); UnistiMatricu(jedinicna);
                throw;
            }
            DodijeliMatrice(pomocna, pomocna2);
            UnistiMatricu(pomocna2);
        }
        if(i==0) {
            try {
                pomocna2=JedinicnaMatrica<NekiTip>(mat.redovi, mat.kolone);
            } catch(...) {
                UnistiMatricu(pomocna); UnistiMatricu(jedinicna);
                throw;
            }
            try {
                stepeni_mat[i]=KreirajMatricu<NekiTip>(mat.redovi, mat.kolone);
            } catch(...) {
                for(int j=0; j<i; j++) UnistiMatricu(stepeni_mat[j]);
                UnistiMatricu(jedinicna); UnistiMatricu(pomocna); UnistiMatricu(pomocna2);
                throw;
            }
            DodijeliMatrice(stepeni_mat[i], pomocna2);
            UnistiMatricu(pomocna2);
        } else {
            try {
                stepeni_mat[i]=KreirajMatricu<NekiTip>(mat.redovi, mat.kolone);
            } catch(...) {
                for(int j=0; j<i; j++) UnistiMatricu(stepeni_mat[j]);
                UnistiMatricu(jedinicna); UnistiMatricu(pomocna); UnistiMatricu(pomocna2);
                throw;
            }
            DodijeliMatrice(stepeni_mat[i], pomocna);
        }
    }
    
    UnistiMatricu(pomocna);
    UnistiMatricu(jedinicna);
    
    try {
        pomocna=KreirajMatricu<NekiTip>(mat.redovi, mat.kolone);
    } catch(...) {
        for(int i=0; i<=n; i++) UnistiMatricu(stepeni_mat[i]);
        throw;
    }
    
    Matrica<NekiTip> pomocna3;
    
    for(int i=0; i<=n; i++) {
        PomnoziSkalarom(stepeni_mat[i], *pocetak_bloka);
        try {
            pomocna3=ZbirMatrica(pomocna, stepeni_mat[i]);
        } catch(...) {
            UnistiMatricu(pomocna);
            for(int i=0; i<=n; i++) UnistiMatricu(stepeni_mat[i]);
            throw;
        }
        DodijeliMatrice(pomocna, pomocna3);
        UnistiMatricu(pomocna3);
        pocetak_bloka++;
    }
    
    for(int i=0; i<=n; i++) {
        UnistiMatricu(stepeni_mat[i]);
    }
    return pomocna;
}

int main ()
{
    int n;
    cout<<"Unesite dimenziju kvadratne matrice: ";
    cin>>n;
    
    Matrica<double> mat;
    try {
        mat=KreirajMatricu<double>(n, n);
    } catch(const std::exception& ex) {
        cout<<ex.what();
        return 0;
    }
    
    cout<<"Unesite elemente matrice A:\n";
    UnesiMatricu('A', mat);
    
    int red;
    std::vector<double> polinom;
    cout<<"Unesite red polinoma: ";
    cin>>red;
    polinom.resize(red+1);
    cout<<"Unesite koeficijente polinoma: ";
    for(int i=0; i<=red; i++) {
        cin>>polinom[i];
    }
    
    Matrica<double> rezultat;
    try {
        rezultat=MatricniPolinom(mat, red, polinom.begin());
    } catch(const std::exception& ex) {
        cout<<ex.what();
        return 0;
    }
    
    IspisiMatricu(rezultat, 10);
    
    UnistiMatricu(rezultat);
    UnistiMatricu(mat);
    
	return 0;
}
