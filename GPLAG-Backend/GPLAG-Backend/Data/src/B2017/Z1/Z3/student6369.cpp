#include <iostream>
#include <deque>
#include <vector>
typedef std::deque<std::vector<int>> Matrica;
          enum Smjer {Rastuci=true, Opadajuci=false};

bool JeLiNegativan(int n){
     if(n<0) return true;
      return false;
}
bool JeLiStepenDvojke(int n){
     
     
     
     
     if(n!=0 || n==1 || n==2 || n%4==0) return true;
     return false;
}
/*
std::vector<int> Izbaci(std::vector<int> m){
     std::vector<int> rez;
     for(int i=0;i<m.size();i++){
     if(!(JeLiStepenDvojke(m.at(i))))
     m.erase(m.begin()+i);
     }
     rez=m;
     return rez;
}*/
/*
std::vector<int> IzbaciN(std::vector<int> m){
     std::vector<int> rez;
     for(int i=0;i<m.size();i++){
     if(JeLiNegativan(m.at(i)))
     m.erase(m.begin()+i);
     }
     r
     
}*/

Matrica OpadajuciPodnizovi(std::vector<int> niz){
     Matrica m;
     if(niz.size()==0)
     return m;
     int i=0,p=0,q=0,j=0;
     do{
          if((i<niz.size()-1) && (niz.at(i)>=niz.at(i+1))){
               p=i;
               while((i<niz.size()-1) && (niz.at(i)>=niz.at(i+1))){
                    i++;
               }
               q=i;
               if(p!=q){
                    m.push_back(std::vector<int>());
                    for(;p<=q;p++){
                         if(JeLiStepenDvojke(niz.at(p)) && !(JeLiNegativan(niz.at(p))))
                  m.at(j).push_back(niz.at(p));
                  else 
                  p++;}
               }
               j++;
               q=0;
               p=0;
          }i++;
         } while(i<niz.size()-1);
         for(int i=0;i<m.size();i++)
          for(int j=0;j<m.at(i).size();j++)
          if(m.at(i).size()<2) m.erase(m.begin()+i);
         return m;
     
     
}

Matrica RastuciPodnizovi(std::vector<int> niz){
     Matrica m;
     if(niz.size()==0)
     return m;
     int i=0,p=0,q=0,j=0;
     do{
          if((i<niz.size()-1) && (niz.at(i)<=niz.at(i+1))){
               p=i;
               while((i<niz.size()-1) && (niz.at(i)<=niz.at(i+1))){
                    i++;
               }
               q=i;
               if(p!=q){
                    m.push_back(std::vector<int>());
                    for(;p<=q;p++){
                         if(JeLiStepenDvojke(niz.at(p)) && !(JeLiNegativan(niz.at(p))))
                  m.at(j).push_back(niz.at(p));
                  else 
                  p++;}
               }
               j++;
               q=0;
               p=0;
          }i++;
         } while(i<niz.size()-1);
         for(int i=0;i<m.size();i++)
          for(int j=0;j<m.at(i).size();j++)
          if(m.at(i).size()<2) m.erase(m.begin()+i);
         return m;
     }
     
  Matrica  MaksimalniPodnizoviStepenaDvojke(std::vector<int> v,Smjer s){
        Matrica rez;
        //std::deque<int> a;
        //for(int i=0;i<v.size();i++){
          //   a.push_back(v[i]);
             
       // }
          if (!s){ rez=OpadajuciPodnizovi(v);
               
          }
          else if (s){
               rez=RastuciPodnizovi(v);
          }
          return rez;
     }
     
     


int main(){
    std::cout<<"Unesite broj elemenata vektora: ";
    int n;
  //  Smjer b;
    std::cin>>n;
    std::vector<int> a(n);
    std::cout<<"Unesite elemente vektora: ";
    for(auto &x: a) std::cin>>x;
    std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    int s;
    std::cin>>s;
    if(s==1){
     //    b=rastuci;
         std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
     Matrica rez1(MaksimalniPodnizoviStepenaDvojke(a, Smjer(Rastuci)));
     for(int i=0;i<rez1.size();i++) {
          for(auto y: rez1.at(i)){
               std::cout<<y<<" ";
          }
     std::cout<<std::endl;
     }
    }
    if(s==2){
       //  b=opadajuci;
         std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
     Matrica rez2(MaksimalniPodnizoviStepenaDvojke(a,Smjer(Opadajuci)));
     
     for(auto x: rez2){
          for(auto y: x){
               std::cout<<y<<" ";
          }
     std::cout<<std::endl;
     }
    
         
    }
    
    
    return 0;
}