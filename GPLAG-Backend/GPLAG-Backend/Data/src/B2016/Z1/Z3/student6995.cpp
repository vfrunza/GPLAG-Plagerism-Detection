#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;
Matrica RastuciPodnizovi(std::vector<double> v){
    Matrica m;
   if(v.size() < 2) return m;
   int redovi(0);
   for(int i(0);i < v.size()-1;i++){
       
       if(v[i] <= v[i+1]){
           redovi++;
           m.resize(redovi);
           
           while(i < v.size()-1 && v[i] <= v[i+1] ){
               
               m[redovi-1].push_back(v[i]);
               i++;
               
           }
           m[redovi-1].push_back(v[i]);
       }
       
   }   
       
    return m;
}
Matrica OpadajuciPodnizovi(std::vector<double> v){
    Matrica m;
   if(v.size() < 2) return m;
   int redovi(0);
   for(int i(0);i < v.size()-1;i++){
       
       if(v[i] >= v[i+1]){
           redovi++;
           m.resize(redovi);
           
           while(i < v.size()-1 && v[i] >= v[i+1]){
               
               m[redovi-1].push_back(v[i]);
               i++;
               
           }
           m[redovi-1].push_back(v[i]);
       }
       
   }   
       
    return m;
}


int main ()
{
  int n;
  double x;
  std::vector<double> v;
  std::cout << "Unesite broj elemenata vektora: ";
  std::cin >> n;
  std::cout << "Unesite elemente vektora: ";
  for(int i(0);i < n;i++){
      std::cin >> x;
      v.push_back(x);
  }
  
  std::cout << "Maksimalni rastuci podnizovi: \n";
  for(auto x : RastuciPodnizovi(v)){
      for(auto y : x) std::cout << y << " ";
      std::cout << std::endl;
  }  
  std::cout << "Maksimalni opadajuci podnizovi: \n";
  for(auto x : OpadajuciPodnizovi(v)){
      for(auto y : x) std::cout << y << " ";
      std::cout << std::endl;
  } 
    
	return 0;
}