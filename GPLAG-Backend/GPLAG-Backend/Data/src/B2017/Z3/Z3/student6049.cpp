#include<iostream>
#include<iomanip>
#include<stdexcept>
#include<deque>
#include<new>
template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    try {
        mat.elementi=new TipElemenata*[br_redova];
        for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
        try {
            for(int i=0; i<br_redova; i++) mat.elementi[i]=new TipElemenata[br_kolona];
        } catch (std::bad_alloc) {
            UnistiMatricu(mat);
            throw;
        }
    } catch(std::bad_alloc) {
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0; i<m3.br_redova; i++) {
        for(int j=0; j<m3.br_kolona; j++) m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    }
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto proizvod(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            TipElemenata suma {};
            for(int k=0; k<m1.br_kolona; k++) suma+=m1.elementi[i][k]*m2.elementi[k][j];
            proizvod.elementi[i][j]=suma;
        }
    }
    return proizvod;
}
template <typename TipElemenata>
Matrica<TipElemenata> PomnoziMatricuSkalarom(const Matrica<TipElemenata> &mat, int broj)
{
    auto m(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) m.elementi[i][j]=mat.elementi[i][j]*broj;
    }
    return m;
}
template <typename TipElemenata, typename Tip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &matA, int n, Tip it)
{
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(matA.br_kolona!=matA.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> m,tmp,vr_mat_p;
    try {
        vr_mat_p=StvoriMatricu<TipElemenata>(matA.br_redova,matA.br_kolona);
        for(int i=0; i<vr_mat_p.br_redova; i++) {
            for(int j=0; j<vr_mat_p.br_kolona; j++) {
                if(i==j) vr_mat_p.elementi[i][j]=1;
                else vr_mat_p.elementi[i][j]=0;
            }
        }
        int step(0);
        try {
            auto cuvaj=StvoriMatricu<TipElemenata>(matA.br_redova,matA.br_kolona);
            try {
                tmp=StvoriMatricu<TipElemenata>(matA.br_redova,matA.br_kolona);
                for(int i=0; i<tmp.br_redova; i++) {
                    for(int j=0; j<tmp.br_kolona; j++) tmp.elementi[i][j]=matA.elementi[i][j];
                }
                try {
                    m=StvoriMatricu<TipElemenata>(matA.br_redova,matA.br_kolona);
                    for(int i=0; i<m.br_redova; i++) {
                        for(int j=0; j<m.br_kolona; j++) m.elementi[i][j]=matA.elementi[i][j];
                    }
                    while(step<=n) {
                        if(step==0) {
                            cuvaj=vr_mat_p;
                            vr_mat_p=PomnoziMatricuSkalarom(vr_mat_p,*it);
                            UnistiMatricu(cuvaj);
                        } else if(step==1) {
                            cuvaj=tmp;
                            tmp=PomnoziMatricuSkalarom(tmp,*it);
                            UnistiMatricu(cuvaj);
                            cuvaj=vr_mat_p;
                            vr_mat_p=ZbirMatrica(vr_mat_p,tmp);
                            UnistiMatricu(cuvaj);
                        } else {
                            try {
                                cuvaj=m;
                                m=ProduktMatrica(m,matA);
                                UnistiMatricu(cuvaj);
                                cuvaj=tmp;
                                tmp=PomnoziMatricuSkalarom(m,*it);
                                UnistiMatricu(cuvaj);
                                cuvaj=vr_mat_p;
                                vr_mat_p=ZbirMatrica(vr_mat_p,tmp);
                                UnistiMatricu(cuvaj);
                            } catch(std::domain_error) {
                                UnistiMatricu(tmp);
                                UnistiMatricu(m);
                                UnistiMatricu(vr_mat_p);
                                UnistiMatricu(cuvaj);
                                throw;
                            }
                        }
                        it++;
                        step++;
                    }
                } catch(std::bad_alloc) {
                    UnistiMatricu(tmp);
                    throw;
                }
            } catch(std::bad_alloc) {
                UnistiMatricu(cuvaj);
                throw;
            }
        } catch (std::bad_alloc) {
            UnistiMatricu(vr_mat_p);
            throw;
        }
    }
    catch(...) {
        throw;
    }
    UnistiMatricu(tmp);
    UnistiMatricu(m);
    return vr_mat_p;
}
int main ()
{
    
    Matrica<int> matrica;
    int dimenzija;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>dimenzija;
    std::cout<<"Unesite elemente matrice A: "<<std::endl;
    matrica=StvoriMatricu<int>(dimenzija,dimenzija);
    UnesiMatricu('A',matrica);
    int n;
    std::cout<<"Unesite red polinoma: ";
    std::cin>>n;
    std::deque<int> koeficijenti(n+1);
    std::cout<<"Unesite koeficijente polinoma: ";
    for(int i=0; i<koeficijenti.size(); i++) std::cin>>koeficijenti[i];
    IspisiMatricu(MatricniPolinom<int>(matrica,n,koeficijenti.begin()),10,6,true);
    UnistiMatricu(matrica); 
    return 0;
}
