#include <iostream>
#include <vector>
#include <functional>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <cmath>

bool PrvojeraIspravnostiVektoraParova(const std::vector<std::pair<double, double>> &v) {
if(v.size()==0) return true; 
for(auto it1=v.begin(); it1<v.end(); it1++) {
//for(auto it2=it1+1; it2<v.end(); it2++) {
       if(std::binary_search(it1+1, v.end(), *it1, [](std::pair<double,double> x1, std::pair<double, double> x2){  return x1.first<x2.first ; })) {return false; }
  //    if(v[i].first==v[j].first) {return false; }//ovdje mozes i onu safe provjeru preko fabs uraditi cuz why not 
      }
      
return true;
}


std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> v) {
   //   if(!PrvojeraIspravnostiVektoraParova(v)) throw  std::domain_error("Neispravni cvorovi"); 
      // ubaci sada i za ono range error
      std::sort(v.begin(), v.end(), [](std::pair<double, double> x1, std::pair<double, double> x2) { return x1.first<=x2.first; }); 
     if(!PrvojeraIspravnostiVektoraParova(v)) throw std::domain_error("Neispravni cvorovi");
      return [v](double x) {
      if (v.size()==0) throw std::range_error("Argument izvan opsega"); 
      if(v[v.size()-1].first==x) return v[v.size()-1].second; 
      std::pair<double, double> kvazianonimni(x, 2.);
      auto j=std::lower_bound(v.begin(), v.end(), kvazianonimni);     
      //prvo se osiguraj da je ista nasao jer jbg ne mora uvijek sve biti servirano na pladnju
      if(j==v.end()) throw std::range_error("Argument izvan opsega"); //eh ne kontam sto ovo nece da radi onog zadnjeg da vrati i fino sve vec ovdje udje vraca iza kraja ako joj je proslijedjen zadnji element u sortiranom vektoru 
      if((*j).first==x)  {
             return (*j).second;}
      if(j==v.begin()) throw std::range_error("Argument izvan opsega"); 
      //osiguraj legalnost ovog dolje
      auto i(j-1);
      
      return (*i).second+(((*j).second-(*i).second)/((*j).first-(*i).first))*(x-(*i).first);
      };
      
}  


std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double x_min, double x_max, double delta) {
      if(x_min>x_max || delta<=0) throw std::domain_error("Nekorektni parametri"); 
      std::vector<std::pair<double, double>> v; 
      while(x_min<=x_max) {
            //da li mozda ima razlika slanja inicijalizione liste or not
            v.push_back(std::make_pair(x_min, f(x_min))); 
            x_min+=delta;
            }
        //    std::cout << "\n"; 
          //  for(int i=0; i<v.size(); i++)
      //      std::cout << v[i].first << " " << v[i].second << std::endl;
      return [v](double x){
      if(v.size()==0) throw std::range_error("Argument izvan opsega");
      if(v[v.size()-1].first==x) return v[v.size()-1].second;
            std::pair<double, double> kvazianonimni(x, 42); 
            auto j=std::lower_bound(v.begin(), v.end(), kvazianonimni);
            if(j==v.end()) throw std::range_error("Argument izvan opsega"); 
            //osiguraj legalnost ovdje
            if((*j).first==x) return (*j).second;
            if(j==v.begin()) throw std::range_error("Argument izvan opsega"); 
            //osiguraj legalnost ovdje
            auto i(j-1); 
            return (*i).second+(((*j).second-(*i).second)/((*j).first-(*i).first))*(x-(*i).first);
      }; }
      

int main ()
{
      std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
      int a;
      // sta ako unese 8
      std::cin >> a; 
      if(a==1) {
            std::cout << "Unesite broj cvorova: ";
            int n; 
            std::cin >> n; 
            std::cout << "Unesite cvorove kao parove x y: "; 
            double x, y;
            std::vector<std::pair<double, double>> v; 
            for(int i=0; i<n; i++) {
            std::cin >> x >> y; 
            v.push_back({x,y}); //ili anonimni par ako to postoji ili sama napravi or smt
            
            }
            double unos; 
            std::sort(v.begin(), v.end(), [](std::pair<double,double> x1, std::pair<double,double> x2) {return x1.first<x2.first;});
            while(1) {
                try {
                  if(!PrvojeraIspravnostiVektoraParova(v)) throw std::domain_error("Neispravni cvorovi"); 
                  std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                  if(!(std::cin >> unos)) break; //uradi safe unos 
                  try{
                  std::cout << "f(" << unos << ") = " << LinearnaInterpolacija(v)(unos) << std::endl; }
                  catch(std::domain_error e) {
                        std::cout << e.what() << std::endl; 
                  }
                  catch(std::range_error r) {
                        std::cout << r.what() << std::endl; 
                  }
            
            }
            
                  catch(std::domain_error asja) {
                        std::cout << asja.what();
                        return 0;
                  }
            }
            
            
            
      }
      if(a==2) {
            std::cout << "Unesite krajeve intervala i korak: "; 
            double x_min, x_max, delta; 
            std::cin >> x_min >> x_max >> delta; 
            double unos; 
            while(1) {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): "; 
            if(!(std::cin >> unos)) break;
            try {
            std::cout << "f(" << unos << ") = " << unos*unos+std::sin(unos) << " fapprox(" << unos << ") = " << LinearnaInterpolacija([](double x){return x*x+std::sin(x);}, x_min, x_max, delta)(unos) << std::endl; 
            } 
            catch(std::domain_error e) {
                  std::cout << e.what() << std::endl; 
                  throw;
            }
            catch(std::range_error r) {
                  std::cout << r.what() << std::endl; 
            }
            }
            
      }
     
      return 0;
}
