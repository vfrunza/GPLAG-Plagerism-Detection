#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <ctgmath>
#include <cmath>
bool Prost (int a)
{
    
    for(int i=2;i<=trunc(std::sqrt(a));i++){
        if(a%i==0) return false;
    }
    return true;
}

bool Simetrija(std::deque<int> Sim)
{
    int i;
    bool simetrican;
    simetrican = true;
    i=0;
    while ((i<=trunc(Sim.size()/2)-1) && simetrican) {
      simetrican = Sim.at(i)==Sim.at(Sim.size()-i-1);
      i ++;
    }
    return simetrican;
}

bool Clan(std::vector<int> Vek, int k)
{
    int i=0;
    bool tu_je=false;
    while(i<Vek.size() && !tu_je){
        tu_je = k == Vek.at(i);
        i++;
    };
    return tu_je;
}

std::deque<int> Ternarni(int n)
{
    std::deque<int> vek;
    do{
        int p;
        p=n%3;
        vek.push_front(p);
        n/=3;
        }while(n!=0);


return vek;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> V, bool N) 
{
  std::vector<int> v1;
  bool ispunjen_uslov;
  
  for(int i=0;i<V.size();i++){
      
      ispunjen_uslov = (
                        (Prost(V.at(i)) && Simetrija(Ternarni(V.at(i))) && N)
                        ||
                        (!Prost(V.at(i)) && Simetrija(Ternarni(V.at(i))) && !N)
                       )
                       && !Clan(v1, V.at(i));
                       
      if (ispunjen_uslov) {
          v1.push_back(V.at(i));
      }
                        
  }
      
  return v1;
 }


int main ()
{
 int n;
 std::vector<int> VEKTOR;
 std::cout<<"Unesite elemente vektora (-1 za kraj): ";
    std::cin>>n;
    while(n!=-1){
        VEKTOR.push_back(n);
        std::cin>>n;
        }
    
    std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    int k;
    std::cin>>k;
    while(k!=0 && k!=1){
        std::cout<<"Neispravan unos! Unesite ponovo: ";
        std::cin>>k;
        }
    
    if (k==1){
        std::vector<int> Prosti(IzdvojiSimetricneTernarne(VEKTOR,true));
        if (Prosti.size() == 0) { 
        std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
            
        }
        else{
                std::cout<<"Prosti simetricni brojevi iz vektora su: ";
                for(int i=0;i<Prosti.size();i++){
                    std::cout<<Prosti.at(i);
                    if (i < Prosti.size()-1) std::cout<<", "; 
                    else std::cout<<".";
                }
             
            }
    }
    
    else if (k==0){
        std::vector<int> Slozeni(IzdvojiSimetricneTernarne(VEKTOR,false));
        
        if (Slozeni.size() == 0) { 
        std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
            
        }
        else{
                std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
                for(int i=0;i<Slozeni.size();i++){
                    std::cout<<Slozeni.at(i);
                    if (i < Slozeni.size()-1) std::cout<<", "; 
                    else std::cout<<".";
                }
             
            }
    }
    
    
	return 0;
}