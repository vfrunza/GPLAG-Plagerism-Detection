/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> matrica;

matrica Pravljenjematrice(int brojredova, int brojkolona)
{
	return matrica(brojredova,std::vector<double>(brojkolona));
}

int Brojredova (matrica Matrica)
{
	return Matrica.size();
}

int Brojkolona (matrica Matrica)
{
	return Matrica.at(0).size();
}
matrica Unos(int brojredova, int brojkolona)
{
	matrica Matrica(Pravljenjematrice(brojredova,brojkolona));
	for(int i=0;i<brojredova;i++)
	{
		for(int j=0;j>brojkolona;j++)
		{
			std::cin>>Matrica.at(i).at(j);
		}
	}
	return Matrica;
}

 int NadiSrednjiElement(matrica Matrica)
 {
 	int c,d;
 	
 	for(int i=0;i<Brojredova(Matrica);i++)
 	{
 		for(int j=0;j<Brojkolona(Matrica);j++)
 		{
 			if(i==j && (i+j==(Brojredova(Matrica))-1))
 			{c=i;
 			d=j;
 			}
 			
 		}
 		
 	}
 	return Matrica.at(c).at(d);
 	
 }
 
 int Suma(matrica Matrica)
 {  std::vector<int>v;
 int n;
 	for(int i=0;i<Brojredova(Matrica);i++)
 	{
 		for(int j=0;j<Brojkolona(Matrica);j++)
 		{
 		
 if((i==((Brojredova(Matrica)/2)-1) && (j==(Brojkolona(Matrica)/2)-1 || j==(Brojkolona(Matrica)/2) || j==((Brojkolona(Matrica)/2)+1))) || (i==(Brojredova(Matrica)/2) && (j==((Brojkolona(Matrica)/2)-1) || j==(Brojkolona(Matrica)/2)+1 ))|| ((i=(Brojredova(Matrica)/2)+1) && (j==(Brojkolona(Matrica)/2)-1 || j==Brojkolona(Matrica)/2 || j==((Brojkolona(Matrica)/2)+1))))
 		   {
 		   	  n=Matrica.at(i).at(j);
 		   	  v.push_back(n);
 		   }
 			
 			
 		}   
 			
 		}
 		
 		int suma=0;
 		for(int i=0;i<v.size();i++)
 		{
 			suma+=v.at(i);
 		}
 		
 		return suma;
 	}
 


int main ()

{   int m,n;
	
	std::cout<<"Unesite dimenzije matrice: ";
	std::cin >> m;
	std::cin>>n;
	std::cout<<"Unesite elemente matrice : ";
	auto Matrica(Unos(m,n));
	int d;
	d=NadiSrednjiElement(Matrica);
	std::cout<<d;
	int k;
	k=Suma(Matrica);
	std::cout<<k;
	return 0;
}