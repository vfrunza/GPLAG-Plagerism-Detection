/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <deque>
//PRIMJER 1 PRVOG PARCIJALNOG SA C2
/*
bool jelKub (int broj){
 
   int br=sqrt(broj);
   for (int i=0; i<br; i++){
       if (i*i*i==broj) return true;
   }
   
    return false;
}


std::vector<bool> funkcija (std::vector<int> vek){
    std::vector<bool> vrati;
    
    for (int i=0; i<vek.size(); i++){
        if (vek.at(i)<0) throw std::domain_error ("Ne valja");
        
        vrati.push_back(jelKub(vek.at(i)));
    }
    
    return vrati;
}


int main ()
{
    std::vector <int> vek={53,656,216,27,3,1234};
    
    std::vector<bool> v = funkcija (vek);
    for (int i=0; i<v.size(); i++){
        std::cout<<v[i]<<" ";
    }
	return 0;
}
*/
/*
int fun (int broj){
    return broj*broj;
}

template <typename tip1, typename tip2>

 auto PopuniPoKriteriju (tip1 p1, tip1 p2, tip2 p3, tip2 p4, int f(int))->decltype (p1){
        tip1 pok=p1;
        int br=0;
        while (pok!=p2) {
            br++; pok++;
        }
        for (int i=br; i>0; i--){
            p2[i]=fun(p1[i]);
            p2++;
            p1++;
        }
    }


int main(){
    std::vector<int> vek={1,2,3};
    std::deque<int> dek;
    
    PopuniPoKriteriju(vek.begin(),vek.end(),std::begin(dek), std::end(dek), fun);
    
    for (int x : dek) std::cout<<x<<" ";
    
    
    return 0;
}
*/