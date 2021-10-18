/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica ;

Matrica KreirajMatricu(int br_redova, int br_kolona) {
 return Matrica(br_redova, std::vector<double>(br_kolona));
}
Matrica UnesiMatricu(int br_redova, int br_kolona) {
 auto Matrica  (KreirajMatricu(br_redova, br_kolona));
 std::cout <<"Rezultantna matrica:"<<std::endl;
 for(int i = 0; i < br_redova; i++)
 for(int j = 0; j < br_kolona; j++) {
  
  
 
 std::cin >> Matrica[i][j];
 }
 
 return Matrica;
}

Matrica HorizontalnoOgledalo(Matrica m) {
 if (m.size() == 0) return m;
 int brKolona = m[0].size();
 int osa = brKolona / 2;
 
 for (int i = 0; i < osa; i++) {
  for (int j = 0; j < m.size(); j++) {
   double tmp = m[j][i];
   m[j][i] = m[j][brKolona - 1 - i];
   m[j][brKolona - 1 - i] = tmp;
  }
 }
 
 return m;
}

Matrica VertikalnoOgledalo(Matrica m) {
 int osa = m.size() / 2;
 
 // i ovdje oznacava redove
 for (int i = 0; i < osa; i++) {
  auto tmp = m[i];
  m[i] = m[m.size() - 1 - i];
  m[m.size() - 1 - i] = tmp;
 }
 
 return m;
}

Matrica KosoOgledalo (Matrica m) {
 return VertikalnoOgledalo(HorizontalnoOgledalo(m));
}

void PopuniMatricu(Matrica &dosad, Matrica cime, int red, int kolona)
{
 for (int j = 0; j < cime.size(); j++) {
  for (int k = 0; k < cime[0].size(); k++) {
   dosad[red + j][kolona + k] = cime[j][k];
  }
}
}

    Matrica OgledaloMatrica(Matrica a){
       if (a.size() == 0) {
        return a;
       }
        for (int i = 1; i < a.size(); i++) {
         if (a[i].size() != a[0].size()) {
          throw std::domain_error("Matrica nije korektna");
         }
        }
        
        int brRedova = a.size();
        int brKolona = a[0].size();
        
        Matrica sve(KreirajMatricu(a.size() * 3, a[0].size() * 3));
        
        auto h = HorizontalnoOgledalo(a), v = VertikalnoOgledalo(a), hv = KosoOgledalo(a);
        PopuniMatricu(sve, hv, 0, 0);
        PopuniMatricu(sve, v, 0, brKolona);
        PopuniMatricu(sve, hv, 0, 2 * brKolona);
        PopuniMatricu(sve, h, brRedova, 0);
        PopuniMatricu(sve, a, brRedova, brKolona);
        PopuniMatricu(sve, h, brRedova, 2 * brKolona);
        PopuniMatricu(sve, hv, 2 * brRedova, 0);
        PopuniMatricu(sve, v, 2 * brRedova, brKolona);
        PopuniMatricu(sve, hv, 2 * brRedova, 2 * brKolona);
        
        return sve;
        
    }

void IspisiMatricu(Matrica m) {
 for(int i = 0; i < m.size(); i++) {
 for(int j = 0; j < m[i].size(); j++)
 std::cout << std::setw(4) << m[i][j];
 std::cout << std::endl;
 }
}

int main(){
    int m, n;
    std::cout << "Unesite dimenzije matrice (m n): ";
    std::cin >> m >> n;
    if (m < 0 || n < 0) {
     std::cout << "Dimenzije matrice moraju biti nenegativne!";
     return 0;
    }
    std::cout << "Unesite elemente matrice:\n";
    auto mat (UnesiMatricu(m, n));
    std::vector<std::vector<double>>a;
    auto o(OgledaloMatrica(mat));
    IspisiMatricu(o);
   
    return 0;
}

	
	
	


