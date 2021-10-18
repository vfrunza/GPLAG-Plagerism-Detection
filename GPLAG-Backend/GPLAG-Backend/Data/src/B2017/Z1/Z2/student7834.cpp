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
#include <vector>
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;

Matrica NajvecaPlaninaMatrice(Matrica matr)
{
 std::vector<double> vek;
 int broj_redova(matr.size());
 int broj_kolona(matr.at(0).size());
 Matrica najveca;
 if(broj_redova==0 && broj_kolona==0) return najveca;
 for(int i(1);i<broj_redova;i++) 
 {
  if(matr.at(i).size()!=broj_kolona) throw std::domain_error("Matrica nije korektna");
 }
 int max(matr.at(0).at(0));
 for(int i(1);i<broj_redova;i++)
 {
  if(i==broj_redova) break;
  for(int j(1);i<broj_kolona;j++)
  {
   if(j==broj_kolona) break;
   if(matr.at(i).at(j)>max) 
   {
    max=matr.at(i).at(j);
   }
  }
 }
 int srednji_element((broj_redova/broj_kolona)/2);
 vek.push_back(max);
 for(int i(0);i<matr.size();i++)
 {
  if(i==matr.size()) break;
  if(i==srednji_element) najveca.push_back(vek); 
 }
 
 
 
 return najveca;
}

int main ()
{
 int m,n;
 Matrica mat;
 Matrica a;
 std::cout << "Unesite dimenzije matrice (m i n): ";
 std::cin >> m >> n;
 if(m<0 || n<0) 
 {
  std::cout << "Dimenzije matrice moraju biti nenegativne!";
  return 0;
 }
 std::cout << "Unesite elemente matrice:";
 std::cout << std::endl;
 mat.resize(m);
 for(int i(0);i<mat.size();i++) mat.at(i).resize(n);
 for(int i(0);i<m;i++)
 {
  for(int j(0);j<n;j++)
  {
   std::cin >> mat.at(i).at(j);
  }
 }
 try
 {
  a=NajvecaPlaninaMatrice(mat);
 }
 catch(std::domain_error izuzetak)
 {
  std::cout << izuzetak.what();	
 }
 std::cout << "Najveca planina unesene matrice je:";
 std::cout << std::endl;
 for(int i(0);i<a.size();i++)
 {
  for(int j(0);j<a.at(i).size();j++)
  {
   std::cout << std::setw(6) <<a.at(i).at(j);
  }
  std::cout << std::endl;
 }
	return 0;
}