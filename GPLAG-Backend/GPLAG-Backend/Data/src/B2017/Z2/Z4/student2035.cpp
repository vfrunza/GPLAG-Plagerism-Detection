#include <functional>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <type_traits>
#include <algorithm>
#include <deque>
#include <string>

//bool kriterijTP1(std::string a,std::string b)
//{
  // return a<b;
//}
//std::string funkcijaTP1(std::string a,std::string b){
  // return a+b;
//}

/*bool kriterijTP1(int a,int b) {
    return a<b;
}
long int funkcijaTP1(int a,int b) {
    return -2*a+b;
}
*/
template <typename iteratoski_tip>
void RazmijeniOnoStoJeU2Iteratora(iteratoski_tip it1, iteratoski_tip it2) {
      if(*it1!=*it2) {
            auto temp(*it1); 
            *it1=*it2; 
            *it2=temp; 
      }      
}

template <typename it_tip1,typename it_tip2,typename it_tip3,typename el_tip12,typename el_tip3>
void SortirajPodrucjeVrijednosti(it_tip1 pocetak1, it_tip1 iza_kraja1, it_tip2 pocetak2,
      it_tip3 pocetak3, el_tip3 f(el_tip12 x1, el_tip12 y1), bool kriterij_za_sort(el_tip12 x2, el_tip12 y2))
{
      std::sort(pocetak1, iza_kraja1, kriterij_za_sort); 
      std::sort(pocetak2, pocetak2+(iza_kraja1-pocetak1), kriterij_za_sort); 
      
      int i(0); 
      int n(iza_kraja1-pocetak1);
     // for(int j=0; j<n; j++) std::cout << pocetak1[i] << " " << pocetak2[i] << std::endl; 
      while(pocetak1!=iza_kraja1) {
            auto potencijalni(std::find(pocetak3, pocetak3+n, f((*pocetak1), (*pocetak2))));
            if(potencijalni==(pocetak3+n)) {
       //     std::cout << "Nisam nasao vrijednost" << *pocetak1 << " " << *pocetak2; 
            throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena"); }
            RazmijeniOnoStoJeU2Iteratora(pocetak3+i, potencijalni);   
            i++; 
            pocetak1++;
            pocetak2++; 
        
      }

}

int SumaCifara1(int a){
	if(a==0) return 0;
	return std::abs(a%10)+SumaCifara1(a/10);
}
//bool kriterijTP1(int a,int b)
//{
//	if(SumaCifara1(a)==SumaCifara1(b)) return a<b;
//	return SumaCifara1(a)<SumaCifara1(b);
//}
//int funkcijaTP1(int x,int y){
//	return x+2*y;
//}

bool DaLiJeProst(int x) { //provjeri logiku ovog
      for(int i=2; i<fabs(x); i++)
      if(x%i==0) return false; 
      return true; 
}

bool VeciPoBrojuProstihFaktora(int x, int y) { //provjeri logiku ovog
      int brojac_x(0), brojac_y(0); 
       //     std::cout << x << " " << y; 
      int kopijax(x), kopijay(y); 
      for(int i=2; i<=fabs(x); i++)
      if(x%i==0 && DaLiJeProst(i)) {brojac_x++; x=x/i; i=1; 
      }
      for(int i=2; i<=fabs(y); i++)
      if(y%i==0 && DaLiJeProst(i)) { brojac_y++; y=y/i; i=1; }
 //     std::cout << " broj faktora  " << brojac_x << " broj faktora  " << brojac_y << std::endl;
      if(brojac_x!=brojac_y) return brojac_x>brojac_y; 
  //    std::cout << "brojevi " << x << " i " << y <<  "isti im je broj faktora " << brojac_x << " " << brojac_y << std::endl; 
      return kopijax>kopijay; 
      
}

bool kriterijTP1(int a,int b) {
   return a<b;
}
long int funkcijaTP1(int a,int b) {
  return -2*a+b;
}

int main () { 
    std::cout << "Unesite broj elemenata: "; 
      int n; 
      std::cin >> n; 
      std::vector<int> v(n), z(n), u(n), rang(n);
      int x; 
      std::cout << "Unesite elemente prvog vektora: "; 
      for(int i=0; i<n; i++) {
            std::cin >> x; 
            if(std::count(v.begin(), v.begin()+i, x)==0) { v[i]=x; } 
            else i--;
      }
      
      std::cout << "Unesite elemente drugog vektora: "; 
      for(int i=0; i<n; i++) {
            std::cin >> x; 
            if(std::count(z.begin(), z.begin()+i, x)==0) { z[i]=x; } 
            else i--;
      }
      
      std::cout << "Unesite elemente treceg vektora: "; 
      for(int i=0; i<n; i++) {
            std::cin >> x; 
            if(std::count(u.begin(), u.begin()+i, x)==0) { u[i]=x; } 
            else i--;
      }
      
      try {
      
      SortirajPodrucjeVrijednosti(v.begin(), v.end(), z.begin(), u.begin(), funkcijaTP1, VeciPoBrojuProstihFaktora); 
      std::cout << "\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke:" << std::endl;
      for(int i=0; i<n; i++) {
            std::cout<<"f("<<v[i]<<", "<<z[i]<<") = "<<u[i]<<std::endl;
      } }
      
      catch(std::logic_error e) {
     //       for(int i=0; i<n; i++) std::cout << v[i] << " " << z[i] << std::endl;
           std::cout << std::endl << "Izuzetak: " << e.what(); 
      }
      

	 /*try {
        std::vector<int> v1;
        std::vector<int> v2;
        std::vector<long int> v3 {1,2,3};
        SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),
        +[] (int a,int b)->long int {return -2*a+b;},
        +[] (int a,int b) {return a<b;});

        for(int i=0; i<v3.size(); i++) {
            std::cout<<v3[i]<<std::endl;
        }

    }
    catch(std::logic_error e) {
                std::cout<<e.what();
    }
    catch(...){
        std::cout<<"Pogresan tip izuzetka!";
    }
    
    try {
	
		std::vector<int> v1 {1};
        std::vector<int> v2 {1};
        std::vector<long int> v3 {-1};
		SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),
		+[] (int a,int b)->long int {return -2*a+b;},
		+[] (int a,int b) {return a<b;});

		for(int i=0; i<v3.size(); i++) {
			std::cout<<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v3[i]<<std::endl;
		}

	}
    catch(std::logic_error e) {
    	        std::cout<<e.what();
    }
    catch(...){
    	std::cout<<"Pogresan tip izuzetka!";
    }
    
    try {
 		std::deque<double> v1 {0.6, 0.5, 0.75};
 		std::vector<double> v2 {2, 1, 3};
 		std::array<double, 3> v3 {{1.5, 2.6, 3.75}};
 		SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(), 
 		+[] (double a, double b)->double {return a + b;},
        +[] (double a, double b) {return a < b;});

		for(int i=0; i<v3.size(); i++) {
			std::cout<<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v3[i]<<std::endl;
		}

	}
    catch(std::logic_error e) {
    	        std::cout<<e.what();
    }
    catch(...){
    	std::cout<<"Pogresan tip izuzetka!";
    }
*/
      return 0; 
}