#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>

//7 21 33 66 97 12 14 82 7 22 71 50 93 55 12 60

void sortrows(std::deque<std::deque<int>>& matrix, int col) {    
    std::sort(matrix.begin(),
              matrix.end(),
              [col](const std::deque<int>& lhs, const std::deque<int>& rhs) {
                  return lhs[col] < rhs[col];
              });


}
template <typename tip, typename tip2, typename tip3, typename tip4>

auto UvrnutiPresjek(tip p1, tip2 p2, tip2 q1, tip2 q2, tip3 f(tip4 x) )  -> std::deque<std::deque<decltype(*p1 + *p1)> >  
{
  
 typedef std::deque<std::deque<decltype(*p1 + *p1)> > Matrica;
 Matrica m;
 tip2 pomocna=q1;
int g(1);

 while (p1 != p2) {
     
      while (q1 != q2) {
     
    if (f(*p1) == f(*q1) ) {
      m.resize(g);
    
    m[g-1].push_back(*p1);  
     m[g-1].push_back(*q1);  
          m[g-1].push_back(f(*q1));     
   g++;

        }
    q1++;
    
 }

p1++;
q1=pomocna;
}

sortrows(m,3);

sortrows(m,0);

sortrows(m,2);




return m;
    
}


template <typename tip, typename tip2, typename tip3, typename tip4>

auto UvrnutaRazlika(tip p1, tip2 p2, tip2 q1, tip2 q2, tip3 f(tip4 x) )  -> std::deque<std::deque<decltype(*p1 + *p1)> >  
{
  
 typedef std::deque<std::deque<decltype(*p1 + *p1)> > Matrica;
 Matrica m;
 tip pomocna=p1;
int g(1);

 while (q1 != q2) {
     
    while (p1 != p2) {
        
    if (f(*q1) == f(*p1)) {
        q1++;
        p1=pomocna;
break;
    }
    if (f(*q1) != f(*p1)) {
        while (f(*q1) != f(*p1) && p1 != p2) {
        p1++;
    if (p1==(p2-1)) {
     m.resize(g);
    
    m[g-1].push_back(*q1);  
          m[g-1].push_back(f(*q1));     
   g++;
   
    }
   
    }  
    q1++;
    p1=pomocna;
    break;
    
    }    
   
}

}
sortrows(m,1);

sortrows(m,0);

sortrows(m,2);




return m;
    
}








int SumaDjelilaca (long long int a) {
int suma(0);	
for (int i = 1; i <= a; i++) {

        if ((a % i) == 0) {
                suma=suma+i;
}
}
return suma;
}
int sumica (long long int a) {
int suma(0);

for (int i = 1; i < a; i++) {

        if ((a % i) == 0) {
                suma=suma+i;
}
}
return suma;
}
int BrojProstihFaktora (long long int a) {
   int brojac(0);     
   for (int i = 2; i <= a; i++) {

        if ((a % i) == 0 ) {
           if (i==2 || i==3) {
               brojac++;
           }
           else {
               for (int j = i-1; j >= 2; j--) { 
                if ((i % j) == 0) break;
                           if(j==2) brojac++;

               }



    }
                                            a=a/i;
                                            i--;

              }

   }
        
  return brojac;      
}

int BrojSavrsenihDjelilaca (long long int a) {
int brojac(0);	
for (int i = 2; i <= a; i++) {

        if ((a % i) == 0) {

if (i == sumica(i)){
brojac++; 

}            
   
}
}
return brojac;
}

int SumaCifara(long long int a) {
 int suma(0);
 
  while (a!=0) {
      
long long int broj=a%10;
suma=suma+broj;
a=a/10;
      
      
  }
  
    
  return suma;  
    
}




int main ()
{

std::cout<<"Unesite broj elemenata prvog kontejnera: ";
int x;
std::cin>>x;
int da=1;
std::cout<<"Unesite elemente prvog kontejnera: ";
std::deque<int> vektor;
for (int i = 0; i < x; i++) {
    da=1;
   int element;
   std::cin>>element;
    for (int j=0; j < vektor.size(); j++) {
        if (element == vektor[j]) da=0;
  }
            if(da==1)   vektor.push_back(element);

   
} 

std::cout<<"Unesite broj elemenata drugog kontejnera: ";
int y;
std::cin>>y;
std::deque<int> vektor2;
int ne=1;
std::cout<<"Unesite elemente drugog kontejnera: ";
  
for (int i = 0; i < y; i++) {
    ne=1;
   int element;
   std::cin>>element;
    for (int j=0; j < vektor2.size(); j++) {
        if (element == vektor2[j]) ne=0;
  }
            if(ne==1)   vektor2.push_back(element);

   
} 



std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
 std::deque<std::deque<int>> v1(UvrnutiPresjek(vektor.begin(), vektor.end(), vektor2.begin(), vektor2.end(), SumaCifara));
for ( int i = 0; i < v1.size(); i++ ) {
for (int j = 0; j < v1[0].size(); j++ ) {
    std::cout<<std::setw(6)<<v1[i][j]<<" "; 
}
std::cout<<std::endl;
}

std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
 std::deque<std::deque<int>> v2(UvrnutaRazlika(vektor.begin(), vektor.end(), vektor2.begin(), vektor2.end(), BrojProstihFaktora));
for ( int i = 0; i < v2.size(); i++ ) {
for (int j = 0; j < v2[0].size(); j++ ) {
    std::cout<<std::setw(6)<<v2[i][j]<<" "; 
}
std::cout<<std::endl;
}
std::cout<<"Dovidjenja!";
return 0;
}