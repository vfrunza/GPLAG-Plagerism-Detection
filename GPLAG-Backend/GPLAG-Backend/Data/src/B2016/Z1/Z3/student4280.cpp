#include <iostream>
#include <vector>
#include <iomanip>


std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v1)
{
   std::vector<std::vector<double>> rezultat1 ;

   for(int i=0; i<v1.size()-1; i++) {

      std::vector<double> vektor1;

      if(v1[i]<=v1[i+1]) {
         while(v1[i]<=v1[i+1] && v1[i]<v1.size()-1) {

            if(i==v1.size()-1) break;

            vektor1.push_back(v1[i]);
            vektor1.push_back(v1[i+1]);
            i+=2;
         }
      } else {
         while(v1[i]>=v1[i+1]) {
            if(i==v1.size()-1) break;
            i++;
         }
      }
      rezultat1.push_back(vektor1);
   }
   return rezultat1;
}


std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v2)
{
   std::vector<std::vector<double>> rezultat2 ;

   for(int i=0; i<v2.size()-1; i++) {

      std::vector<double> vektor2;

      if(v2[i]>=v2[i+1]) {
         while(v2[i]>=v2[i+1] && v2[i]>v2.size()-1) {

            if(i==v2.size()-1) break;

            vektor2.push_back(v2[i]);
            vektor2.push_back(v2[i+1]);
            i+=2;
         }
      } else {
         while(v2[i]<=v2[i+1]) {
            if(i==v2.size()-1) break;
            i++;
         }
      }
      rezultat2.push_back(vektor2);
   }
   return rezultat2;
}


int main ()
{
   std::cout << "Unesite broj elemenata vektora: ";
   int n;
   std::cin >> n;

   std::cout << "Unesite elemente vektora: ";
   std::vector<double> A(0);

   while(n-->0) { /*Dio unosa*/
      double v;
      std::cin>>v;
      if(v==0.0) break;
      A.push_back(v);
   }

   std::vector< std::vector<double>> Matrica1;
   Matrica1 = RastuciPodnizovi(A);

   std::cout << "Maksimalni rastuci podnizovi:\n";
   for (unsigned int i = 0; i < Matrica1.size(); i++) {
      for (unsigned int j = 0; j < Matrica1[i].size(); j++) {
         std::cout << Matrica1[i][j];
         if(j!=Matrica1.size()-1) std::cout << " ";
         j++;
      }
      if(i!=Matrica1.size()) std::cout << " ";
      i++;
   }

   std::vector< std::vector<double>> Matrica2;
   Matrica2 = OpadajuciPodnizovi(A);

   std::cout << "\nMaksimalni opadajuci podnizovi: ";
   for (unsigned int i = 0; i < Matrica2.size(); i++) {
      for (unsigned int j = 0; j < Matrica2[i].size(); j++) {
         std::cout << Matrica2[i][j] ;
         if(j!=Matrica2.size()-1) std::cout << " ";
         j++;
         
      }
      if(i!=Matrica2.size()) std::cout << " ";
      i++;
   }

   return 0;
}

