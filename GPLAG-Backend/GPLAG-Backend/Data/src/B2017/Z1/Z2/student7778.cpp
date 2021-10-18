/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;
// Kreira matricu sa zadanim brojem redova i kolona
Matrica KreirajMatricu(int br_redova, int br_kolona) {
 return Matrica(br_redova, std::vector<double>(br_kolona));
}
int BrojRedova(Matrica m) {
 return m.size();
}
int BrojKolona(Matrica m) {
 return m.at(0).size();
}


Matrica UnesiMatricu(int br_redova, int br_kolona) {
 auto m(KreirajMatricu(br_redova, br_kolona));
 for(int i = 0; i < br_redova; i++)
 for(int j = 0; j < br_kolona; j++) {
 std::cin >> m.at(i).at(j);
 }
 return m;
}





void NajvecaPlaninaMatrice(Matrica m){
    
double max=0;
int n=m.at(0).size();
for(int i = 0; i < BrojRedova(m); i++) {
 for(int j = 0; j < BrojKolona(m); j++){
  if(n!=m.at(i).size())throw std::domain_error("Matrica nije korektna");
  }
 }

if(BrojKolona(m)<3 && BrojRedova(m)<3 && BrojRedova(m)!=0 && BrojKolona(m)!=0){
    for(int i = 0; i < BrojRedova(m); i++) {
 for(int j = 0; j < BrojKolona(m); j++){
   
  
 if(m.at(i).at(j)>max)max=m.at(i).at(j);


 }

 if(n!=m.at(i).size())throw std::domain_error("Matrica nije korektna");

}
if(BrojKolona(m)==0 || BrojRedova(m)==0) max=0 ;
 std::cout << std::setw(6) << max;
 std::cout << std::endl;

}
else  {
 for(int i = 1; i < BrojRedova(m); i++) {
 for(int j = 1; j < BrojKolona(m); j++){

  std::cout << std::setw(6) << m.at(i).at(j);
  
 }
 std::cout << std::endl;
}
}


}




int main ()
{
 try 
 {
       int m,n;
typedef std::vector<std::vector<double>> Matrica;
Matrica a(std::vector<double>);

std::cout<<"Unesite dimenzije matrice (m i n): ";
   std::cin>>m>>n;
   if(m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";
   else {
       std::cout<<"Unesite elemente matrice: ";
      auto A(UnesiMatricu(m, n));
      
     
      
      std::cout<<"\nNajveca planina unesene matrice je: \n";


      NajvecaPlaninaMatrice(A);
}

    

   } catch(std::domain_error IZUZETAK)
   {
    std::cout <<"Izuzetak: "<< IZUZETAK.what() << std::endl;
   }


	return 0;
}
