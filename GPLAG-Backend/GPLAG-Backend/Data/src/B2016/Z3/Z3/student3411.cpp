/B2016/2017: Zadaća 3, Zadatak 3
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
 void IspisiMatricu( Matrica<TipElemenata> mat,int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++){
 std::cout << std::setw(sirina_ispisa)<<std::setprecision(preciznost) << mat.elementi[i][j];
 }
 std::cout << std::endl;
 }
 if(treba_brisati) UnistiMatricu(mat);
 }
 template <typename TipElemenata>
 Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> matrica1, Matrica<TipElemenata> matrica2){
    if(matrica1.br_kolona!=matrica2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    try{
     auto matrica3(StvoriMatricu<TipElemenata>(matrica1.br_redova,matrica2.br_kolona));
     for(int i=0; i<matrica1.br_redova; i++){
         for(int j=0; j<matrica2.br_kolona; j++){
             matrica3.elementi[i][j]=0;  //postavljanje vrijednosti nove matrice na 0
         }
     }
     for(int i=0; i<matrica1.br_redova; i++){
         for(int j=0; j<matrica2.br_kolona; j++){
             for(int k=0; k<matrica1.br_kolona; k++){
                 matrica3.elementi[i][j]+=matrica1.elementi[i][k]*matrica2.elementi[k][j];
             }
         }
    }
    return matrica3;
    }
    catch(...){
        throw;
    }
 }
 template <typename TipElemenata>
 Matrica<TipElemenata> Jedinicna(Matrica<TipElemenata> matrica){
     try{
     auto matrica1(StvoriMatricu<TipElemenata>(matrica.br_redova,matrica.br_kolona));
     for(int i=0; i<matrica.br_redova; i++){
         for(int j=0; j<matrica.br_kolona; j++){
             if(i==j) matrica1.elementi[i][j]=1;
             else matrica1.elementi[i][j]=0;
         }
     }
     return matrica1;
     }
     catch(...){ //hvatanje i prosljedjivanje izuzetka ukoliko je bačen prilikom stvaranja nove matrice
         throw;
     }
}
 template <typename TipElemenata>
 Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> matrica,std::vector<double> v){
     if(matrica.br_kolona!=matrica.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
     try{
     auto matrica1(StvoriMatricu<TipElemenata>(matrica.br_redova,matrica.br_redova));
     for(int i=0; i<matrica.br_redova; i++){ //postavljanje svih elemenata matrice na 0
        for(int j=0; j<matrica.br_kolona; j++)
            matrica1.elementi[i][j]=0;
         }
    if(v.size()==0){  //uslov ako se radi o praznom vektoru, da se vrati nula matrica;
         return matrica1;
     }
     try{
        for(int i=0; i<v.size(); i++){
        if(i==0) { //poseban uslov ukoliko je rijec o jedinicnoj matrici
            try{
                auto pomocna(Jedinicna(matrica)); //stvaranje jedinicne matrice
                for(int j=0; j<matrica.br_redova; j++){
                    for(int k=0; k<matrica.br_kolona; k++){
                        pomocna.elementi[j][k]*=v[i]; //mnozenje svih elemenata matrice odgovarajucim koeficijentom
                    }
                }
                for(int j=0; j<matrica.br_redova; j++){
                    for(int k=0; k<matrica.br_kolona; k++){
                        matrica1.elementi[j][k]+=pomocna.elementi[j][k];
                    }
                }
                UnistiMatricu(pomocna);
            }
            catch(std::bad_alloc){ 
                throw;
            }
        }
        else{
            try{//2.
                auto pomocna(StvoriMatricu<TipElemenata>(matrica.br_redova, matrica.br_kolona));
                try{//3. brisi pomocnu
                    Matrica<TipElemenata> *niz1[1000];
                    for(int j=0; j<1000; j++) niz1[j]=nullptr;
                    try{//4. brisi niz1
                       auto pomocna1(StvoriMatricu<TipElemenata>(matrica.br_redova, matrica.br_kolona));
                       for(int j=0; j<matrica.br_redova; j++){ //dodjeljivanje pomocnoj1 vrijednost matrice
                           for(int k=0; k<matrica.br_kolona; k++){ 
                               pomocna1.elementi[j][k]=matrica.elementi[j][k];
                           }
                       }
                       try{//5. brisi pomocna1
                            for(int j=0; j<i/2; j++){
                                auto pomocna2=(ProduktMatrica<TipElemenata>(pomocna1,pomocna1));
                                niz1[j]=&pomocna2;
                                if(j>0){
                                    auto pomocna4(ProduktMatrica<TipElemenata>(pomocna2,pomocna2));
                                    niz1[j]=&pomocna4;
                               }
                           }
                           if(i%2==0){
                               for(int j=0; j<matrica.br_redova; j++){
                                   for(int k=0; k<matrica.br_kolona; k++){
                                       pomocna.elementi[j][k]=niz1[i/2-1]->elementi[j][k];
                                   }
                               }
                           }
                           else if(i==1){
                               for(int j=0; j<matrica.br_redova; j++){
                                   for(int k=0; k<matrica.br_kolona; k++){
                                       pomocna.elementi[j][k]=pomocna1.elementi[j][k];
                                   }
                               }
                           }
                           else if(i%2!=0 && i>1){
                               for(int j=0; j<matrica.br_redova; j++){
                                   for(int k=0; k<matrica.br_kolona; k++){
                                       pomocna.elementi[j][k]=niz1[i/2-1]->elementi[j][k];
                                   }
                               }
                               try{//6. brisi pomocna 2
                                  auto pomocna3(ProduktMatrica<TipElemenata>(pomocna,pomocna1));
                                  for(int j=0; j<matrica.br_redova; j++){
                                      for(int k=0; k<matrica.br_kolona; k++){
                                          pomocna.elementi[j][k]=pomocna3.elementi[j][k];
                                      }
                                  }
                                  UnistiMatricu(pomocna3);
                               }
                               catch(std::bad_alloc){
                                    throw;
                               }
                           }
                       
                       }
                       catch(std::bad_alloc){//5. brisem pomocna1
                          UnistiMatricu(pomocna1);
                          throw;
                       }
                       UnistiMatricu(pomocna1); //brisanje pomocna1
                    }
                    catch(std::bad_alloc){//4. brisanje niza1
                        for(int j=0; j<i/2; j++) { 
                            if(!niz1[j]->elementi) break;
                            for(int k = 0; k < niz1[j]->br_redova; k++) delete[] niz1[j]->elementi[k];
                            delete[] niz1[j]->elementi;
                            niz1[j]->elementi = nullptr;
                            
                        }
                        throw;
                    }
                    for(int j=0; j<i/2; j++) { 
                        if(!niz1[j]->elementi) break;
                        for(int k = 0; k < niz1[j]->br_redova; k++) delete[] niz1[j]->elementi[k];
                        delete[] niz1[j]->elementi;
                        niz1[j]->elementi = nullptr;
                        
                    } //brisanje niza1 jer više ne treba
                    }
                catch(std::bad_alloc){// treba brisat pomocnu jer se ne stigne dodijelti nizu
                   UnistiMatricu(pomocna);
                   throw;
                }
                for(int j=0; j<matrica.br_redova; j++){
                    for(int k=0; k<matrica.br_kolona; k++){
                        pomocna.elementi[j][k]*=v[i];
                    }
                }
                for(int j=0; j<matrica.br_redova; j++){
                    for(int k=0; k<matrica.br_kolona; k++){
                        matrica1.elementi[j][k]+=pomocna.elementi[j][k];
                    }
                }
                UnistiMatricu(pomocna); //brisem pomocnu jer nam više ne treba
            }
            catch(std::bad_alloc){//2. catch treba obrisat niz i nj. elemente
                throw;
            }
        }
        
     } 
     }
     catch(std::bad_alloc){ //catch ako ne uspije alokacija niza pokazivaca
         UnistiMatricu(matrica1);
         throw;
     }
    return matrica1;
    }
    catch(std::bad_alloc){ //catch ukoliok ne uspije alokacija prvodefinisane matrice
        throw;
    }
 }
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
 const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }

int main() {
 Matrica<double> a, c; // AUTOMATSKA INICIJALIZACIJA!!!
 int m, n;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m ;
 try {
 a = StvoriMatricu<double>(m, m);
 //b = StvoriMatricu<double>(m, n);
 std::cout << "Unesite elemente matrice A: \n";
 UnesiMatricu('A', a);
 //std::cout << "Unesi matricu B:\n";
 //UnesiMatricu('B', b);
 std::cout << "Unesite red polinoma: ";
 std::cin>>n;
 std::cout<<"Unesite koeficijente polinoma: ";
 std::vector<double> v(n+1);
 for(int i=0; i<n+1; i++){
     std::cin>>v[i];
 }
 //c=StvoriMatricu<double>(m,m);
 c=MatricniPolinom(a,v);
 IspisiMatricu(c,10,6);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 UnistiMatricu(a);  UnistiMatricu(c);
 return 0;
}
