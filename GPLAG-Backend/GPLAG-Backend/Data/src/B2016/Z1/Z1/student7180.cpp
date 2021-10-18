/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> Ternarni(int n)
{
	if(n<0) n=-n;
	std::vector<int> a;
	while(n!=0)
	{
	    a.push_back(n%3);
	    n/=3;
	}
	return a;
}

int Brojac (int n)
{
    int br0=0; 
    int br1=0;
    int br2=0;
    std::vector<int>a=Ternarni(n);
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]==0) br0++;
        if(a[i]==1) br1++;
        if(a[i]==2) br2++;
        
    }
    if(br0%2==0 && br1%2==0 && br2%2==0) return 1; //Vraca da je broj Opaki 
    else if((br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0 || br2==0)) return 2; //Vraca da je broj Odvratan
    else return 3; //ako brojevi nisu ni Opaki ni Odvratni
}

std::vector<int> PonavljanjeElemenata(std::vector<int>Novi) 
{
    for(int i=0; i<Novi.size()-1; i++)
   {
       if(Novi.size()==0) break;
       for(int j=i+1; j<Novi.size(); j++)
       if(Novi[i]==Novi[j])
       {
           for(int k=j; k<Novi.size()-1; k++) 
           {
               Novi[k]=Novi[k+1];
           }
           Novi.resize(Novi.size()-1);
           j--;
       }
   }
   return Novi;
}

std::vector<int> IzdvojiGadne (std::vector<int> v, bool Opaki_Odvratni)
{
    std::vector<int>Opaki;
    std::vector<int>Odvratni;
    
    std::vector<int>NoviVektor=PonavljanjeElemenata(v);
    
    for(int i=0; i<NoviVektor.size(); i++)
    {
      if(Brojac(NoviVektor[i])==1) Opaki.push_back(NoviVektor[i]);
      if(Brojac(NoviVektor[i])==2) Odvratni.push_back(NoviVektor[i]);
   }
   
   if(Opaki_Odvratni==true) return Opaki;
   else if(Opaki_Odvratni==false) return Odvratni;
}

int main()
{   
    std::vector<int> Opaki;
    std::vector<int> Odvratni;
    std::vector<int> Glavni;
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
    while(1==1)
    {   
        int n;
        std::cin>>n;
        if(n==0) break;
        Glavni.push_back(n);
    }
    
    Opaki=IzdvojiGadne(Glavni,true);
    Odvratni=IzdvojiGadne(Glavni, false);
	
	std::cout<<"Opaki: ";
	for(int i=0; i<Opaki.size(); i++)
	{
	   std::cout<<Opaki[i]<<" ";
	}
	
	std::cout<<std::endl;
	
	std::cout<<"Odvratni: ";
	for(int i=0; i<Odvratni.size(); i++)
	{
	   std::cout<<Odvratni[i]<<" ";
	}
	
    return 0;
}
