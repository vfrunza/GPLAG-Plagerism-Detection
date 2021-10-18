#include <iostream>
#include <vector>
#include <cmath>

int Obrni (int broj)
{
	int n(broj);
	int suma(0);
	
	while(n!=0)
	 {
	 	suma=suma+(n%10);
	 	suma*=10;
	 	n/=10;
	 }
	
	suma/=10;
	
	return suma;
}

int KonvertujUTer(int broj)
{
	if(broj<0) broj=fabs(broj);
	int n(broj);
	int suma(0);
	
	while(n!=0)
	 {
	  suma+=(n%3);
	  suma*=10;
	  
	  if(suma==0)
	   {
	   	suma+=10;
	   	n/=3;
	   	 while(n!=0)
	   	  {
	   	  	suma+=(n%3);
	   	  	suma*=10;
	   	  	n/=3;
	   	  }
	  
	   	 suma=Obrni(suma);
	   	 suma/=10;
	   	 suma*=10;

	   	 return suma;
	   }
	  
	  n=n/3;
	 }

	 suma=Obrni(suma);
	
	 return suma;
}

int KolikoCifri(int broj, int cifra)
{
	int brojac(0);
	int n(broj);
	
	while(n!=0)
	 {
	 	if(n%10 == cifra) brojac++;
	 	n/=10;
	 }
	return brojac;
}

std::vector<int> IzdvojiGadne(std::vector<int> vek, bool JelOpak)
{
	std::vector<int> v;
   
   for(int i=0;i<vek.size();i++)
    { 
       if(vek[i]==0) continue;
       
       int KonvBr(KonvertujUTer(vek[i]));
       
       int Nula(KolikoCifri(KonvBr,0)); 
       int Jedinica(KolikoCifri(KonvBr,1));
       int Dvica(KolikoCifri(KonvBr,2));
       
       if(JelOpak)
        {
        	if(Nula%2==0 && Jedinica%2==0 && Dvica%2==0)
        	 v.push_back(vek[i]);
        }
       
       else
        { 
           if((Nula%2!=0 && Jedinica%2!=0 && Dvica%2!=0) || (Nula==0 && Jedinica%2!=0 && Dvica%2!=0) 
          || (Nula%2!=0 && Jedinica==0 && Dvica%2!=0) || (Nula%2!=0 && Jedinica%2!=0 && Dvica==0)) 	
           v.push_back(vek[i]);
        }
    }
    
    
    for(int i=0;i<v.size();i++)
	 {
	 	for(int j=i+1;j<v.size();j++)
	 	 {
	 	 	if(v[i]==v[j]) v.erase(v.begin()+j);
	 	 }
	 	 
	 }
	
	for(int i=0;i<v.size();i++)
	 {
	 	for(int j=i+1;j<v.size();j++)
	 	 {
	 	 	if(v[i]==v[j]) v.erase(v.begin()+j);
	 	 }
	 	 
	 }
    
    
    return v;
}


int main ()
{
	
		/*std::vector<int>v1 {56,656,20,61,552,-6384,223,8979,80812,26937,240801,15,3608,5904,56,656,20,61,552,-6384,223,0};
    bool Opak(true);
	bool Odvratan(false);
	std::vector<int> v2 (IzdvojiGadne(v1,Opak));
	std::cout<<"Opaki: ";
	
	for(int i=0;i<v2.size();i++)
	 {
	 	std::cout<<v2[i]<<" ";
	 }
	 std::cout<<std::endl;
	 std::cout<<"Odvratni: ";
	 
	 std::vector<int> v3 (IzdvojiGadne(v1,Odvratan));
	 for(int i=0;i<v3.size();i++)
	 {
	 	std::cout<<v3[i]<<" ";
	 }
  */  
    std::vector<int>v1;//{56,656,20,61,552,-6384,223,8979,80812,26937,240801,15,3608,5904,56,656,20,61,552,-6384,223,0};
	bool Opak(true);
	bool Odvratan(false);
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	
	for(;;)
	{
	 int br(1);
	 std::cin>>br;
	 v1.push_back(br);
	 if(br==0) break;
	}
	
	
	std::vector<int> v2 (IzdvojiGadne(v1,Opak));
	std::cout<<"Opaki: ";
	
	for(int i=0;i<v2.size();i++)
	 {
	 	std::cout<<v2[i]<<" ";
	 }
	 std::cout<<std::endl;
	 std::cout<<"Odvratni: ";
	 
	 std::vector<int> v3 (IzdvojiGadne(v1,Odvratan));
	 for(int i=0;i<v3.size();i++)
	 {
	 	std::cout<<v3[i]<<" ";
	 }

	return 0;
}