#include <iostream>
#include <deque>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::deque;
enum Smjer {Rastuci, Opadajuci};
int DaLiJeStepen2(int n){
    for(int i=1;i<=n;i*=2)
    if(i==n)
    return 1;
        
      return 0;  
    }
    deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> vektor,Smjer a){

    deque<vector<int>>rezultat;
    int j(0);
   
    int broj_redova(0);
    if(a==Rastuci){
        for(int i=0;i<vektor.size(); ){
            
         vector<int>pomocni(0);
             int brojac(0);
            int kontrola(0);
            if(i==int(vektor.size())-1)
            break;
          while((i<=int(vektor.size())-2) && DaLiJeStepen2(vektor.at(i)) && DaLiJeStepen2(vektor.at(i+1)) && vektor.at(i)<vektor.at(i+1)){
              int b(i+1);
              if(brojac==0){
              pomocni.push_back(vektor.at(i));
              }
              pomocni.push_back(vektor.at(b));
              brojac++;
              i++;
             
            kontrola=1;
          }
          if(kontrola){ broj_redova++;
          rezultat.resize(broj_redova);
          rezultat.at(j)=pomocni;
          j++;
          }
          i++;
        }
    }
    
   else{  for(int i=0;i<vektor.size();){
            
          vector<int>pomocni(0);
            int brojac(0);
            int kontrola(0);
            if(i==int(vektor.size())-1)
            break;
          while((i<=int(vektor.size())-2) && DaLiJeStepen2(vektor.at(i)) && DaLiJeStepen2(vektor.at(i+1)) && vektor.at(i)>vektor.at(i+1)){
              if(brojac==0){
              pomocni.push_back(vektor.at(i));
             }
              pomocni.push_back(vektor.at(i+1));
              i++;
              brojac++;
            kontrola=1;
          }
          if(kontrola){ broj_redova++;
          rezultat.resize(broj_redova);
          rezultat.at(j)=pomocni;
          j++;
          }
          i++;
        }
        
   }
    
    return rezultat;
    
}

int main ()
{
    cout<<"Unesite broj elemenata vektora: ";
    int n;
    cin>>n;
    cout<<"Unesite elemente vektora: ";
    vector<int> elementi(n);
    for(int i=0;i<n;i++)
    cin>>elementi.at(i);
    vector<int>vektor;
    cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    int a;
    cin>>a;
    
    Smjer varijabla;
    if(a==1) varijabla=Rastuci;
    else varijabla=Opadajuci;
    deque<vector<int>> v;
    v=MaksimalniPodnizoviStepenaDvojke(elementi,varijabla);
   int vel(v.size());
   if(a==1)
         cout<<"Maksimalni rastuci podnizovi: ";
         else cout<<"Maksimalni opadajuci podnizovi: ";
 cout<<endl;
   if(vel>0){
         int something;
        for(int k=0;k<vel;k++){
            something=v.at(k).size();
            for(int j=0;j<something;j++)
            cout<<v.at(k).at(j)<<" ";
          
          cout<<endl;  
        }
   }
    
    
   
    
	return 0;
}