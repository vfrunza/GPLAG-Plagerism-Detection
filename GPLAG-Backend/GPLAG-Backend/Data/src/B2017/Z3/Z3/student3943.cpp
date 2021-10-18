#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <list>
#include <vector>


template<typename TipElemenata>
struct Matrica {
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};
template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;

    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata* [br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {

        for(int i=0; i<br_redova; i++) {

            mat.elementi[i]=new TipElemenata [br_kolona];

        }
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;

}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat)
{

    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout<< ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6, bool treba_obrisati=false)
{

    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++)

            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;

    }

    if(treba_obrisati) UnistiMatricu(mat);

}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
{

    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) {
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    }

    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona))   ;
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];

    return m3;
}

template <typename TipElemenata>

Matrica<TipElemenata>  ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("“Matrice nisu saglasne za mnozenje");

    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));

    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++) {
            double suma(0);
            for(int k=0; k<m2.br_redova; k++)
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            m3.elementi[i][j]=suma;
        }

    return m3;
}

template <typename TipElemenata,typename IterTip>
Matrica<TipElemenata>  MatricniPolinom( Matrica<TipElemenata> &mat,int n,IterTip it)
{

    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(mat.br_kolona!=mat.br_redova) throw std::domain_error("Matrica mora biti kvadratna");



    auto m3(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));

    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            if(i==j) m3.elementi[i][j]=*it;
            else {
                m3.elementi[i][j]=0;
            }
        }
    }
    it++;

    auto pomocna(mat) ;
    auto jedinicna(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
    auto pomocna2(mat);
    Matrica<TipElemenata> proizvod;


    for(int i=1; i<=n; i++) {

        for(int i=0; i<mat.br_redova; i++) {

            for(int j=0; j<mat.br_kolona; j++) {

                if(i==j)   {
                    jedinicna.elementi[i][j]=*it;
                } else {
                    jedinicna.elementi[i][j]=0;
                }



            }

        }
    try{
        proizvod=ProduktMatrica(pomocna,jedinicna);
          } catch(...) {
              UnistiMatricu(jedinicna);
              UnistiMatricu(pomocna);
              UnistiMatricu(m3);
              if(i!=1) {
                  UnistiMatricu(mat);
              }

              throw;
          } 


        auto pomocna1(m3);
try{
        m3=ZbirMatrica(m3,proizvod);
         } catch(...) {
              UnistiMatricu(proizvod);
              UnistiMatricu(jedinicna);
              UnistiMatricu(m3);
              UnistiMatricu(pomocna);
              if(i!=1) {
                  UnistiMatricu(mat);
              }

              throw;
          }
        

        UnistiMatricu(proizvod);
        UnistiMatricu(pomocna1);

if(i!=n)
{
    try{
        pomocna=ProduktMatrica(pomocna,mat);
           } catch(...) {


               UnistiMatricu(pomocna2);
               UnistiMatricu(m3);
               UnistiMatricu(jedinicna);
               if(i!=1) {
                   UnistiMatricu(mat);
               }

               throw;
           }
           

        if(i!=1) {
            UnistiMatricu(pomocna2);
        }

        pomocna2=pomocna;

        it++;

    }
}
UnistiMatricu(pomocna);
    UnistiMatricu(jedinicna);

    return m3;


}






int main()

{

    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int dimenzija;

    std::cin>>dimenzija;
    std::cout<<"Unesite elemente matrice A: "<<std::endl;
    Matrica<double> a,c;
    try {
        a=StvoriMatricu<double>(dimenzija,dimenzija);
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        int red_polinoma;
        std::cin>>red_polinoma;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::list<double> lista;
        for(int i=0; i<=red_polinoma; i++) {
            double x;
            std::cin>>x;
            lista.push_back(x);
        }
        auto it(lista.begin());



        IspisiMatricu(c=MatricniPolinom(a,red_polinoma,it),10);

        if(c.elementi!=nullptr) {
            UnistiMatricu(c);
        }


        UnistiMatricu(a);


    } catch(std::bad_alloc) {
        UnistiMatricu(a);
        UnistiMatricu(c);
        std::cout<<"Nedovoljno memorije!"<<std::endl;

    } catch(std::domain_error izuzetak) {
        UnistiMatricu(a);
        UnistiMatricu(c);
        std::cout<<izuzetak.what();

    }




    return 0;
}
