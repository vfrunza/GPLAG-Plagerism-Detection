#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
       int br_redova, br_kolona;
       TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
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
     mat.br_redova = br_redova; mat.br_kolona = br_kolona;
      mat.elementi = new TipElemenata*[br_redova];
            for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
            try {
                 for(int i = 0; i < br_redova; i++)
                 mat.elementi[i] = new TipElemenata[br_kolona];
            } catch(...) {
                UnistiMatricu(mat);
                    throw;
            }
      
    return mat;
      
}  

       
       
 
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
     for(int i = 0; i < mat.br_redova; i++){
         for(int j = 0; j < mat.br_kolona; j++) {
             std::cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
             std::cin >> mat.elementi[i][j];
         }
     }     
 }
 
template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
     for(int i = 0; i < mat.br_redova; i++) {
         for(int j = 0; j < mat.br_kolona; j++){  std::cout << std::setw(sirina_ispisa)<<std::setprecision(preciznost)<< mat.elementi[i][j];}
         std::cout << std::endl;
        
     }
     if(treba_brisati) UnistiMatricu(mat);   
 }


template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
     if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)  throw std::domain_error("Matrice nemaju jednake dimenzije!");
     try {
         auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
         for(int i = 0; i < m1.br_redova; i++){
            for(int j = 0; j < m1.br_kolona; j++){
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
            } 
         }    
         return m3;
     } catch(...){
         throw;
     }
 }
 
 
 template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata>&m2) {
    if(m1.br_kolona!=m2.br_redova)  throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    try{
        auto produkt(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        for(int i=0; i<produkt.br_redova; i++){
            for(int j=0; j<produkt.br_kolona; j++){
                TipElemenata suma(0);
                for( int k=0; k<m1.br_kolona; k++){
                    suma+=m1.elementi[i][k]*m2.elementi[k][j];
                }
            produkt.elementi[i][j]=suma;    
            }   
        }
    return produkt;
    } catch(...){
        throw;
    }
}
template <typename TipElemenata>
Matrica <TipElemenata> MnoziSaKoeficijentom (const Matrica<TipElemenata> &m, double koeficijent){
    try{
        auto pomnozena(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
        for(int i=0; i<pomnozena.br_redova; i++){
            for(int j=0; j<pomnozena.br_kolona; j++){
            pomnozena.elementi[i][j]=koeficijent*m.elementi[i][j];
            }
        }
        return pomnozena;
    }catch(...){
        throw;
    }
}    


template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &m, std::vector<double> koeficijenti){
    //testira izuzetak
    if(m.br_kolona!=m.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
    //matrica koju vracas odma se prvi da semoze vratiti nula matrica ako je vetor prazan
    try{
        auto rezultat(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona)); 
        try{
            auto stepen(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
            
        // sa jedinicnom mnozi
            for(int j=0; j<m.br_redova; j++){
                for(int k=0; k<m.br_kolona; k++){
                    stepen.elementi[j][k]=m.elementi[j][k];
                    if(j==k)  rezultat.elementi[j][k]=koeficijenti[0];
                    else rezultat.elementi[j][k]=0;
                }
            }
            int brojac(1);
            for(int i=1; i<koeficijenti.size(); i++){
            if(brojac<i){
               // auto temp2(stepen);
                stepen=ProduktMatrica(stepen,m);
                 //UnistiMatricu(temp2);
                brojac++;
            }
            auto pomnozena=MnoziSaKoeficijentom(stepen, koeficijenti[i]);
            //auto temp(rezultat);
            rezultat=ZbirMatrica(rezultat,pomnozena); 
            //UnistiMatricu(temp);
            UnistiMatricu(pomnozena);
            }
            UnistiMatricu(stepen);
    } catch(...){
        throw;
        
    }
    return rezultat;        
    }catch(...){
        throw;
    }
}    



int main() {
 Matrica<double> A; // AUTOMATSKA INICIJALIZACIJA!!!
 int dimenzije;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >>dimenzije;
 try {
     A = StvoriMatricu<double>(dimenzije, dimenzije);
 }catch(std:: bad_alloc){
     std::cout<<" Nema dovoljno memorije!\n";
     return 0;
     
 }
     std::cout << "Unesite elemente matrice A:\n";
     UnesiMatricu('A', A);
     int red;
     std::cout << "Unesite red polinoma: ";
     std::cin>>red;
     std::cout<<"Unesite koeficijente polinoma: ";
     std::vector<double>koeficijenti(red+1);
     
     for(int i=0; i<=red; i++) std::cin>>koeficijenti[i];
try{     
     IspisiMatricu(MatricniPolinom(A,koeficijenti),10,6,true);
          
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 return 0;
}
