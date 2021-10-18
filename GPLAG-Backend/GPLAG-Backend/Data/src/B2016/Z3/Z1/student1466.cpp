#include <iostream>
#include <vector>
#include <cmath>
#include <functional>


int min(int n,int d, int i) {
    int min;

        if (i < (n - d)) min = i;
        else min = n-d;
        
        
    return min;
}


int max(int d, int i) {
    int max;

        if (1 > (i - d)) max = 1;
        else max = i-d;
        
    return max;
}


double tezinskikoeficijenti (int d, int i,std::vector<std::pair<double,double>> vektor) {
    double suma(0);
   int n = vektor.size();

for (int k=max(d,i); k <= min(n,d,i); k++) {
        int stepen=pow(-1, k-1);
        double proizvod(1);
        proizvod*=stepen;
      for (int j = k; j <= k+d; j++) {
          
        if (j != i) proizvod=proizvod*(1/(vektor[i-1].first-vektor[j-1].first));

      } 
         
            suma+=proizvod;
     }
     
    return suma;
    
}


std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double,double>> vektor, int d) {

if (d<0 or d>=vektor.size()) throw std::domain_error ("Nedozvoljen red");
for (int i = 0; i < vektor.size(); i++) {
    
  for (int j = i+1; j< vektor.size(); j++)
  
{
    
 if (vektor[i].first == vektor[j].first ) throw std::domain_error("Neispravni cvorovi");   
    
    
}  

    
}
int n=vektor.size();
    
    return[vektor,d,n] (double x) {
        double a(0);
            double b(0);

        for (int i = 1; i <= vektor.size(); i++) {
    if ( x != vektor[i-1].first)  {

    a += ((tezinskikoeficijenti(d,i,vektor) /  (x-vektor[i-1].first)) * vektor[i-1].second);
        b+=(tezinskikoeficijenti(d,i,vektor) / (x - vektor[i-1].first));    

    }
         else  return vektor[i-1].second;
 }
 return a/b;
};
}


std::function<double(double)> BaricentricnaInterpolacija( double f(double), double xmin, double xmax, double deltax, int d) {

if (xmin > xmax or deltax<=0) throw std::domain_error("Nekorektni parametri");

std::vector<std::pair<double,double>> vektor;
   for(double a=xmin; a<=xmax; a+=deltax) {
      
      std::pair <double,double> cvoric;

cvoric.first=(a);


cvoric.second=f(a);




      vektor.push_back(cvoric);
      
   }
   auto fun=BaricentricnaInterpolacija(vektor,d);
   return fun;
 }
 
 double f (double x)  {
    
    return x*x + sin(x);
}

int main ()
{
 try {
  int opcija;
   std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
   std::cin>>opcija;

  if (opcija==1) { 
   int broj;
   std::cout<<"Unesite broj cvorova: ";
   std::cin>>broj;
   
   
   std::vector<std::pair<double,double>> vektor;
   std::cout<<"Unesite cvorove kao parove x y: ";
   for (int i = 0; i < broj; i++) {
      
      std::pair <double,double> cvoric;
      std::cin>>cvoric.first;
      std::cin>>cvoric.second;
      vektor.push_back(cvoric);
      
   }
       std::cout<<"Unesite red interpolacije: ";
      int d;
      std::cin>>d;
      double broj2;
      std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";

      std::cin>>broj2;
     auto fun = BaricentricnaInterpolacija(vektor,d);
while (std::cin) {
       std::cout<<"f("<<broj2<<") = "<<fun(broj2)<<std::endl;

      std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
    if(!std::cin) break;
      std::cin>>broj2;

       }
      
}

if(opcija == 2) {
  double pocetak,kraj,korak;
  std::cout<<"Unesite krajeve intervala i korak: ";
  
  std::cin>>pocetak;
  std::cin>>kraj;
  std::cin>>korak;
   std::cout<<"Unesite red interpolacije: ";
   int d;
   std::cin>>d;
   
   double broj2;
      std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
 
 
          auto fun1 = BaricentricnaInterpolacija(f,pocetak,kraj,korak,d);


      std::cin>>broj2;

while (std::cin) {
       std::cout<<"f("<<broj2<<") = "<<broj2*broj2+sin(broj2)<<" ";
             std::cout<<"fapprox("<<broj2<<") = "<<fun1(broj2)<<std::endl;

      std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
    if(!std::cin) break;
      std::cin>>broj2;

       }

}
}

catch (std::domain_error e) {
    
    std::cout<<e.what();
}
        
return 0;
}