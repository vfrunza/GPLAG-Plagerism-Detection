/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
using namespace std;

template <typename TipElemenata> 
    struct Matrica {
        int br_redova, br_kolona;
        TipElemenata **elementi {nullptr};
};

template <typename TipElemenata>
    void UnistiMatricu (Matrica<TipElemenata> mat){
        if(!mat.elementi) return;
        for(int i{0}; i<mat.br_redova; i++  ) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi = nullptr;
}

template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
        Matrica<TipElemenata> mat;
        mat.br_redova = br_redova; mat.br_kolona = br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        try{
            for(int i{0}; i<br_redova; i++){
                mat.elementi[i] = new TipElemenata[br_kolona];
            }
        } catch (...){
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
    
template <typename TipElemenata>
    void UnesiMatricu( char ime_matrice, const Matrica<TipElemenata> &mat ){
        for(int i{0}; i<mat.br_redova; i++){
            for( int j{0}; j<mat.br_kolona; j++){
                cout<< ime_matrice <<"("<<i+1<<","<<j+1<<") = ";
                cin>>mat.elementi[i][j];
            }
        }
    }

template<typename TipElemenata>
    void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati = false){
        for(int i{0}; i<mat.br_redova; i++){
            for(int j{0}; j<mat.br_kolona; j++){
                cout<<setw(sirina_ispisa)<<setprecision(preciznost)<<mat.elementi[i][j];
            }
            cout<<endl;
        }
        if(treba_brisati) UnistiMatricu( mat );
    }

template<typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica ( const Matrica<TipElemenata> & m1,
    const Matrica<TipElemenata> &m2){
        if(m1.br_kolona != m2.br_kolona || m1.br_redova != m2.br_redova){
            throw domain_error ("Matrice nemaju jednake dimenzije!");
        }
        auto m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
        for(int i {0}; i<m1.br_redova; i++)
            for(int j {0}; j<m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
    }
    
template <typename TipElemenata>
    TipElemenata SkalarniProizvod ( const vector<TipElemenata> &kolona, const vector <TipElemenata> &red  ){
        TipElemenata proizvod{0};
        //Sad cemo pronaci skalarni proizvod ova dva vektora!
        for(int i{0}; i<kolona.size(); i++)
                proizvod += kolona[i] * red[i];
        //Taj skal proizvod je upravo jedan element matrice ProduktMatrica
        return proizvod;
    }

template<typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica( const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
        if(m1.br_kolona != m2.br_redova ) throw domain_error("Matrice nisu saglasne za mnozenje");
        
        auto m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
        
        for(int i{0}; i< m1.br_redova; i++){
            for(int j{0}; j<m2.br_kolona; j++){
                
                
                //Sad uzimanje vektora reda prve i kolone druge matrice
                vector<TipElemenata> kolona, red;
                for(int po_redu{0}; po_redu < m1.br_kolona; po_redu++) kolona.push_back(m1.elementi[i][po_redu]);
                for(int po_koloni{0}; po_koloni < m2.br_redova; po_koloni++) red.push_back(m2.elementi[po_koloni][j]);
                
                m3.elementi[i][j] = SkalarniProizvod ( kolona, red );
                
            }
        } 
        return m3;
    }

template<typename TipElemenata>
    Matrica<TipElemenata> SkalarxMat (const Matrica<TipElemenata> &mat, TipElemenata x){
        Matrica<TipElemenata> pomocna = StvoriMatricu<TipElemenata> (mat.br_redova, mat.br_kolona );
        for(int i{0}; i<mat.br_redova; i++)
            for(int j{0}; j<mat.br_kolona; j++)
                pomocna.elementi [i][j] = mat.elementi[i][j] * x;
                
        return pomocna;
    }
template<typename TipElemenata>
    Matrica <TipElemenata> StepMatrica ( const Matrica<TipElemenata> &mat, int stepen){
        Matrica<TipElemenata> pomocna = StvoriMatricu<TipElemenata>(mat.br_kolona, mat.br_redova);
        for(int i{0}; i<pomocna.br_redova; i++) for (int j{0}; j<mat.br_kolona; j++) pomocna.elementi[i][j] = mat.elementi[i][j];
        for(int i {0}; i<stepen; i++){
            auto brisac = pomocna;
            pomocna = ProduktMatrica(pomocna,mat);
            UnistiMatricu(brisac);
        }
        return pomocna;
    }

template<typename TipElemenata, typename tipKoef>
    Matrica<TipElemenata> MatricniPolinom ( const Matrica<TipElemenata> &mat,
    vector<tipKoef> koef){
         Matrica<TipElemenata> c;
         if( mat.br_redova != mat.br_kolona) throw domain_error("Matrica mora biti kvadratna");
         int format {mat.br_kolona};
         //Stvaranje jedinicne matrice radi konvencije
         auto jedinicna = StvoriMatricu<TipElemenata>(format,format);
         for(int i{0}; i<format; i++) 
            for (int j{0}; j<format; j++) 
                if(i==j) jedinicna.elementi[i][j] = 1;
                else jedinicna.elementi[i][j] = 0;
                
            auto pomic_za_brisanje = jedinicna;
            
        jedinicna = SkalarxMat<TipElemenata>(jedinicna, koef[0]);
        UnistiMatricu(pomic_za_brisanje);
        
        //Stvaranje pomocne koju cemo zapravo vratiti
        auto m3 = StvoriMatricu<TipElemenata>(format, format);
        
        int n {(int)koef.size()};
        //A sad sumiranje
        auto polinomka = StvoriMatricu<TipElemenata>(format, format);
        try{
        //Dodatni uslovi zbog jedinicne matrice
        //Ona se posebno tretira i pri racunu i pri vracanju iz funkcije
        if (n==0){
            for(int i{0}; i<format; i++)
                for(int j{0}; j<format; j++)
                    jedinicna.elementi[i][j] = 0;
                   
            return jedinicna;
        } 
        auto pomocnik = m3;
        m3 = ZbirMatrica(jedinicna, c=SkalarxMat<TipElemenata>(mat,koef[1]));
        UnistiMatricu(pomocnik);
        if(n==1) return m3;
        
       
        for(int i{0}; i<format; i++)
            for(int j{0}; j<format; j++)
                polinomka.elementi[i][j] = mat.elementi[i][j];
        
        for (int k{1}; k<n-1; k++){
            
            
            //for(int l{0}; l<k; l++){
                auto pom_za_bris1 = polinomka;
               
                polinomka = StepMatrica( mat, k );
                UnistiMatricu(pom_za_bris1);
            //} 
            auto pom_za_bris = polinomka;
            polinomka = SkalarxMat<TipElemenata>(polinomka, koef[k+1]);
            UnistiMatricu(pom_za_bris);
            
            
            auto pom_bris_m3 = m3;
            m3 = ZbirMatrica(m3, polinomka);
            UnistiMatricu(pom_bris_m3);
            
        }
        UnistiMatricu(jedinicna); UnistiMatricu(polinomka); UnistiMatricu(c);
        return m3;
        } catch (...) {
            UnistiMatricu(jedinicna); UnistiMatricu(m3); UnistiMatricu(polinomka); UnistiMatricu(c);
            throw;
        }
     
       
        
    }
    


int main (){
    cout << "Unesite dimenziju kvadratne matrice: ";
    int n;
    cin>>n;
    
    
    Matrica<int> M, polinomka;
    try{
    M = StvoriMatricu<int>(n,n);
    
    cout << "Unesite elemente matrice A: "<<endl;
    UnesiMatricu( 'A', M);
    
    vector<int> koef;
    cout << "Unesite red polinoma: ";
    int red;
    cin>>red;
    cout << "Unesite koeficijente polinoma: ";
    for(int i{0}; i<=red; i++) {
        int koeficijent;
        cin>>koeficijent;
        koef.push_back(koeficijent);
    }
    
    
    polinomka = MatricniPolinom( M, koef );
    IspisiMatricu(  polinomka, 10, 6, true );
    
    } catch(...) {
        cout<<"Problemi s memorijom...";
        
    }
    UnistiMatricu(M);
    
    
    
	return 0;
}