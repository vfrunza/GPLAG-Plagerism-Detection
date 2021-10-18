/*B 2017/2018, Zadaća 1, Zadatak 1.	*/
#include <iostream>
#include<vector>
#include<iomanip>
#include<cmath>


//ISTI//
bool ImaLiIstih(std::vector<int> x, int y)
     {
         for(int i=0;i<x.size();i++)
             {
                 if (x.at(i) == y)
                 return true;
             }
        return false;
     }
//PREBACIVANJE//
 std::vector<int> PrebaciUTernarni(int n)
     {   
         std::vector<int> m;
         do{
             m.push_back(n%3);
             n/=3;
         } while(n!=0);
         
         return m;
      }
      //SIMETRIJA//
bool SimetricniTernarni(int n)
     {
        std::vector<int> a;
        a=PrebaciUTernarni(n);
        for(int i=0;i<a.size();i++)
        {
            if (a.at(i)!=a.at(a.size()-1-i))
            return false;
        }
        return true;
     }
//JEL PROST//
bool Prostbroj(int n)
         {
         	int i;
         	for(i=2;i<n;i++)
         	    {
         	     if(n%i==0)
         	      return false;     
         	    }
          return true;
         }
//MORA BIT POZITIVAN //
std::vector<int> PrebUPoz(std::vector<int> n)
     {
         for(int i=0;i<n.size();i++)
            {
                if(n.at(i)<0)
                   {
                       n.at(i)=n.at(i)*(-1);
                   }
            }
    return n;
     }
  
//GLAVNA FUNK//
std::vector<int>IzdvojiSimetricneTernarne(std::vector <int> x,bool a) 
            {
            std::vector<int> temp;
            x=PrebUPoz(x);
            
            if (a==true)
            {
            for(int i=0;i<x.size();i++) 
            	{
            
            	    if (SimetricniTernarni (x.at(i)) && !ImaLiIstih(temp,x.at(i)) && Prostbroj(x.at(i))) temp.push_back(x.at(i));
            	     
                }
            }
            else if (a==false)
            {
            for(int i=0;i<x.size();i++) 
            	{
            	    if (Prostbroj (x.at(i))==false)
            	    {
            	        if (SimetricniTernarni(x.at(i))==true && ImaLiIstih(temp,x.at(i))==false) temp.push_back(x.at(i));
            	    }
                }
             }
             return temp;
            }

int main ()
{
    int p;
    std::vector<int> v;
        std::cout<<"Unesite elemente vektora (-1 za kraj): ";
        for(;;){
            int broj;
            std::cin>>broj;
            if(broj==-1)break;
            v.push_back(broj);
        }
             std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
             do{
                std::cin>>p;
                if(p!=1 && p!=0)std::cout<<"Neispravan unos! Unesite ponovo: ";
             }while(p!=1 && p!=0);
             auto g(IzdvojiSimetricneTernarne(v,bool(p)));
             
             if(p== true && g.size()!=0)
                {
                    std::cout<<"Prosti simetricni brojevi iz vektora su: ";
                    for(int i=0;i<g.size();i++)
                        {
                          if(i!=g.size()-1) std::cout<<g.at(i)<<", ";
                          else std::cout<<g.at(i)<<".";
                        }
                }
               else if(p== false && g.size()!=0)
                {
                    std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
                    for(int i=0;i<g.size();i++)
                        {
                          if(i!=g.size()-1) std::cout<<g.at(i)<<", ";
                          else std::cout<<g.at(i)<<".";
                        }
                }
                else if(p== true && g.size()==0)
                     {
                         std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
                     }
                else if(p== false && g.size()==0)
                     {
                         std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
                     }
                

         return 0;
}