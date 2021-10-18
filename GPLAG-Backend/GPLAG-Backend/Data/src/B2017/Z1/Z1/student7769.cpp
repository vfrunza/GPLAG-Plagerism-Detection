#include <iostream>
#include <vector>
#include <cmath>

int KonverzijaUTernarni(int a)
{
    int ostatak,i=1;
    int ternarni=0;
    while(a!=0)
    {
        ostatak=a%3;
        a=a/3;
        ternarni=ternarni+(ostatak*i);
        i=i*10;
    }
    
    return ternarni;
}



bool DaLiJeTernarniSimetrican(int a)
{
    int pomocna, cifra, obrnuto=0;
    int b(KonverzijaUTernarni(a));
    pomocna=b;
    do
    {
        cifra=pomocna%10;
        obrnuto=(obrnuto*10)+cifra;
        pomocna=pomocna/10;
    }while(pomocna!=0);
    
    if(b==obrnuto) return true;
    else return false;
}

bool DaLiJeProst(int n)
{
   
    if(n<2) return false;
    for(int i=2;i<=std::sqrt(n);i++)
    {
        if(n%i==0)
        {
            return false;

        }
    }
    return true;
}



std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool a)
{
    std::vector<int> w;
    std::vector<int> x;
    if(a==true)
   {
       
       for(int i=0;i<v.size();i++)
       {
           if(DaLiJeProst(v.at(i))) w.push_back(v.at(i));
       }
      
       for(int j=0;j<w.size();j++)
       {
           if(DaLiJeTernarniSimetrican(w.at(j))) x.push_back(w.at(j));
       }
       
   }
   if(a==false)
   {
       for(int i=0;i<v.size();i++)
       {
           if(!(DaLiJeProst(v.at(i)))) w.push_back(v.at(i));
       }
      
       for(int j=0;j<w.size();j++)
       {
           if(DaLiJeTernarniSimetrican(w.at(j))) x.push_back(w.at(j));
       }
   }
   return x;
   
}



int main ()
{
    
    std::vector<int> v;
    std::cout<<"Unesite elemente vektora (-1 za kraj): ";
    int n;
    do
    {
        std::cin>>n;
        if(n!=-1)
            v.push_back(n);
    }while(n!=-1);
    std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    int a;
    std::cin>>a;
    if(a<0 || a>1)
    {
        std::cout<<"Neispravan unos! Unesite ponovo: ";
        std::cin>>a;
    }
    if(a==1){
    auto q((IzdvojiSimetricneTernarne(v,true)));
    if(q.empty()) 
    {
        std::cout<<"Nema prostih simetricnih brojeva u vektoru."; 
        return 2;
    }
    std::cout<<"Prosti simetricni brojevi iz vektora su: ";
        for(int i=0;i<q.size();i++)
        {
	        if(i==q.size()-1)
	            std::cout<<q.at(i)<<".";
	        else
	            std::cout<<q.at(i)<<", ";
        }
    }
    else if(a==0)
    {
    auto q((IzdvojiSimetricneTernarne(v,false)));
    if(q.empty())
    {
        std::cout<<"Nema slozenih simetricnih brojeva u vektoru."; 
        return 3;
    }
    std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
        for(int i=0;i<q.size();i++)
        {
	        if(i==q.size()-1)
	            std::cout<<q.at(i)<<".";
	        else
	            std::cout<<q.at(i)<<", ";
        }
    }
    
    
    return 0;
}