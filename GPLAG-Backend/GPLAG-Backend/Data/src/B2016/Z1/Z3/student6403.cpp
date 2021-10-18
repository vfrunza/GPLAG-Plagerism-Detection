/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v)
{
   Matrica m;

   for(int i(0); i<v.size(); i++) {
      if(i==v.size()-1) break;
      if(v.at(i)<=v.at(i+1)) {
         int j(i);
         std::vector<double> podniz;
         podniz.push_back(v.at(j));
         
          while(v.at(j)<=v.at(j+1) && j<v.size()) {
            j++;
            podniz.push_back(v.at(j));
            if(j==v.size()-1) break;
         }

         i=j;
         if(podniz.size()>=2) {
            m.resize(m.size()+1);
            m.at(m.size()-1).resize(podniz.size());
            for(int k(0); k<podniz.size(); k++)
               m.at(m.size()-1).at(k)=podniz.at(k);

         }
      }
      
   }
   return m;
}

Matrica OpadajuciPodnizovi(std::vector<double> v)
{
   Matrica m;

   for(int i(0); i<v.size(); i++) {
      if(i==v.size()-1) break;
      if(v.at(i)>=v.at(i+1)) {
         int j(i);
         std::vector<double> podniz;
         podniz.push_back(v.at(j));
         while(v.at(j)>=v.at(j+1) && j<v.size()) {
            j++;
            podniz.push_back(v.at(j));
            if(j==v.size()-1) break;
         }

         i=j;
         if(podniz.size()>=2) {
            m.resize(m.size()+1);
            m.at(m.size()-1).resize(podniz.size());
            for(int k(0); k<podniz.size(); k++)
               m.at(m.size()-1).at(k)=podniz.at(k);

         }
      }
   }
   return m;
}

void IspisiMatricu(Matrica m) {
	for(int i(0);i<m.size();i++) {
		for(int j(0);j<m.at(i).size();j++) {
			std::cout<<m.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
}


int main() {
   int n;
   std::cout<<"Unesite broj elemenata vektora: ";
   std::cin>>n;
   std::vector<double> niz(n);
   std::cout<<"Unesite elemente vektora: ";
  for(int i(0);i<niz.size();i++) {
     double x;
     std::cin>>x;
     niz.at(i)=x;
  }
   Matrica mat1(RastuciPodnizovi(niz));
   Matrica mat2(OpadajuciPodnizovi(niz));
   std::cout<<"Maksimalni rastuci podnizovi:"<<std::endl;
   IspisiMatricu(mat1);
   std::cout<<"Maksimalni opadajuci podnizovi:"<<std::endl;
   IspisiMatricu(mat2);
   
   return 0;
}
