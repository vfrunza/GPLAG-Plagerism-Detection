/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include<iomanip>

template<typename TipElementa>
//....STRUKTURA....
struct Matrica {
    int br_redova,br_kolona;
    TipElementa ** elementi = nullptr;
};
 

template<typename TipElementa>
//...F1
void UnistiMatricu (Matrica <TipElementa> mat ){

    if(!mat.elementi) return;
    //...BRISI ONO NA STA POKAZUJE DVOSTRUKI POKAZIVAC 
    for(int i (0); i < mat.br_redova; i++) delete[] mat.elementi[i];
    //....BRISI NIZ POKAZIVACA
    delete[] mat.elementi;
    //...POKAZIVAC STAVI NA NULL
    mat.elementi = nullptr;
} 

template<typename TipElementa>
//....F2
Matrica<TipElementa> StvoriMatricu (int br_redova,int br_kolona ){
    
    Matrica<TipElementa>mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    
    mat.elementi = new TipElementa * [br_redova];
    for(int i (0); i < br_redova;i++) mat.elementi[i] = nullptr ;
    
    try{
        for(int i (0); i < br_redova;i++)
            mat.elementi[i] = new TipElementa [br_kolona];
    }catch(...){
        UnistiMatricu(mat);
        throw;
    }
    
    
    return mat;
}

//...F3...
template<typename TipElementa>
void UnesiMatricu (char ime_matrice,Matrica<TipElementa> &mat){
    
    for(int i (0); i < mat.br_redova; i++){
        for(int j (0); j < mat.br_kolona; j++){
            
            std::cout<<ime_matrice << "(" << i + 1 << ","<< j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}


/*....F4
template<typename TipElementa>
void IspisiMatricu (const Matrica<TipElementa>&mat , int sirina_ispisa){
    
    for(int i (0); i < mat.br_redova;i++){
        for(int j (0); j < mat.br_redova;j++){
            std::cout<<std::setw(sirina_ispisa) << mat.elementi[i][j];
        }
        std::cout<<std::endl;
    }
}
*/

template<typename TipElementa>
void IspisiMatricu (Matrica<TipElementa>mat , int sirina_ispisa,int preciznost = 6, bool treba_brisati = false){
    
    if(mat.elementi == nullptr)
        return;
    
    for(int i (0); i < mat.br_redova;i++){
        for(int j (0); j < mat.br_kolona;j++){
            if(&mat.elementi[i] != nullptr) {
                std::cout<<std::setw(sirina_ispisa) <<std::setprecision(preciznost)<< mat.elementi[i][j];
            }
        }
        std::cout<<std::endl;
    }
    
    if(treba_brisati){ UnistiMatricu(mat);}
}

//...F5
template<typename TipElementa>
Matrica<TipElementa> ZbirMatrica (const Matrica<TipElementa> &m1, const Matrica <TipElementa> &m2){
    
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error ("Matrice nemaju jednake dimenzije !");
        
    auto m3 (StvoriMatricu<TipElementa>(m1.br_redova,m1.br_kolona));
    
    for(int i (0); i < m1.br_redova; i++){
        for(int j (0); j < m1.br_kolona;j++){
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    
    
    return m3;
}

//....f6
template<typename TipElementa>
Matrica<TipElementa> ProduktMatrica (const Matrica<TipElementa> &m1, const Matrica <TipElementa> &m2){
    //...SAGLASNE ZA MNOZENJE
    if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje\n");
    //...PRODUKT MATRICA PREDAVANJE 3A
auto m3 = StvoriMatricu<TipElementa>(m1.br_redova,m2.br_kolona);

    for(int i (0); i < m1.br_redova; i++){
        for(int j (0); j < m2.br_kolona;j++){
              for(int k = 0; k < m2.br_redova; k++){
                m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }
  
    return m3;
}

template<typename TipElementa>
Matrica<TipElementa> PomnoziSkalarom(double skalar,const Matrica <TipElementa> &mat){

    auto m3 = StvoriMatricu<TipElementa>(mat.br_redova,mat.br_kolona);
    for(int i (0); i < mat.br_redova;i++){
        for(int j (0); j < mat.br_kolona; j++){
            m3.elementi[i][j] = skalar * mat.elementi[i][j];
        }
    }
    
    return m3;
}


template<typename TipElementa>
Matrica <TipElementa> MatricniPolinom ( const Matrica<TipElementa> &mat,std::vector<double>&koeficijenti){
    
    if(mat.br_redova != mat.br_kolona)
        throw std::domain_error("Matrica mora biti kvadratna\n");
        
    //..UKOLIKO JE VEKTOR PRAZAN FUNKCIJA VRACA MATRICU ISTOG FORMATA KAO I A CIJI SU ELEMENTI SVE NULE
    if(koeficijenti.size() == 0){
        auto nula = StvoriMatricu<TipElementa>(mat.br_redova,mat.br_kolona);
        for(int i (0); i < nula.br_redova; i++){
            for(int j (0); j < nula.br_kolona; j++){
                nula.elementi[i][j] = 0;
            }
        }
        
        return nula;
        //.... UNISTI NULA MATRICU......... TJ UNISITI MATRICU KOJA SE VRATI KAO REZULTAT FUNKCIJE

    }
  //  std::cout<<"koe"<<koeficijenti.size();
    //... STVARA JEDINICNU MATRICU I UNISTI JE 
    Matrica<TipElementa> jedinicna  = StvoriMatricu<TipElementa> (mat.br_redova,mat.br_kolona);
    for(int i (0); i < jedinicna.br_redova; i++){
        for(int j (0); j < jedinicna.br_kolona;j++){
            if( i == j ) {jedinicna.elementi[i][j] = 1;}
            else {jedinicna.elementi[i][j] = 0;}
        }
    }
    
      //std::cout<<"Ispisi jedinicnu matricu:\n";
      // IspisiMatricu(jedinicna,7);
    
    
    Matrica<TipElementa> polinom = StvoriMatricu<TipElementa>(mat.br_redova,mat.br_kolona);
    //...UNISTI STEPEN MATRICU 
    auto stepen = StvoriMatricu<TipElementa> (jedinicna.br_redova,jedinicna.br_kolona); 
    //...PREUSMJERI POKAZIVACE SA STEPEN NA JEDINICNU MATRICU...
    //  stepen = jedinicna; PLITKA KOPIJA
        stepen = jedinicna;
    //.....
    
    
    Matrica<TipElementa> a, b;
    
    
    polinom = PomnoziSkalarom<TipElementa>(koeficijenti[0],jedinicna);
    for(int i (1); i < koeficijenti.size(); i++){
      
        polinom = ZbirMatrica<TipElementa>(polinom,a = PomnoziSkalarom<TipElementa>(koeficijenti[i], b = ProduktMatrica<TipElementa>(stepen,mat)));
         stepen = ProduktMatrica <TipElementa>(stepen,mat);
         
      
        
    }
    
    
    UnistiMatricu(a); UnistiMatricu(b),UnistiMatricu(stepen);UnistiMatricu(jedinicna);
    return polinom;
}

int main ()
{
    /*
    Matrica<double> a,b,produkt,jedinicna,nula,polinom,skalarmatrica;
    int m , n;
    std::cout<<"Unesite broj redova i broj kolona za matrice:\n";
    std::cin >> m >> n;
    
    
    try{
        a = StvoriMatricu<double>(m,n);
        b = StvoriMatricu<double>(m,n);
        
        std::cout<<"Unesi matricu A:\n";
        UnesiMatricu('A',a);
        
       std::cout<<"Unesi matricu B:\n";
        UnesiMatricu('B',b);
        
       std::cout<<"Zbir ove dvije matrice je:\n";
        IspisiMatricu( ZbirMatrica(a,b), 7,true);
        
        std::cout<<"Produkt ove dvije matrice je:\n";
        IspisiMatricu((produkt = ProduktMatrica(a,b)),7,2,false);
        
        
        std::cout<<"Pomnozeno skalarom:\n";
        skalarmatrica = PomnoziSkalarom(2,a);
        IspisiMatricu(skalarmatrica,7);
        
        */
   
    Matrica<double> a,b;
    int m;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    
    try{
        a = StvoriMatricu<double>(m,m);
        
        std::cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A',a);
       
        std::cout<<"Unesite red polinoma: ";
        int red;
        std::cin >> red;
        
        
        std::vector<double>k;
        if(red > 0){ 
            std::cout<<"Unesite koeficijente polinoma: ";
            
        
            for(int i (0); i < red + 1; i++){
                int l;
                std::cin >> l;
                k.push_back(l);
            }
        }
      
        
         // IspisiMatricu(c = ProduktMatrica(a,a),7);
         //  MatricniPolinom(a,k);
    
    IspisiMatricu(b = MatricniPolinom(a,k),10);
        
    }catch(std::bad_alloc){
        std::cout<<"Nedovoljno memorije!\n";
    }
    
    
    UnistiMatricu(a); UnistiMatricu(b);
   // UnistiMatricu(c); UnistiMatricu(produkt);UnistiMatricu(skalarmatrica);UnistiMatricu(jedinicna);UnistiMatricu(polinom);UnistiMatricu(nula);
    
    return 0;
}