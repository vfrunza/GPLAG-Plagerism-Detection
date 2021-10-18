/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<vector> 
#include<iostream>
#include<cmath>
using namespace std;
vector<int> Duplikati(vector<int> A)
{
   for(int i = 0 ; i < A.size()-1 ; i++)
   {
      for(int j = i+1 ; j < A.size() ; j++)
      {
         if(A[j]==A[i])
         {
            A.erase(A.begin()+j);
            j--;
         }
      }
   } 
   vector<int> novi=A;
   return novi;}


int Konvertuj(int broj)
{
	
	 
	int Ternarni=0;
	int ostatak, brojac(1);
	while(broj!=0)
	{
		ostatak=broj%3;
		broj/=3;
		Ternarni+=ostatak*brojac;
		brojac*=10;
	}

	return Ternarni;
}
std::vector<int>RastaviNaCifre(int broj)
{
	
	std::vector<int> Cifre;
	while(broj!=0)
	{
		int pomocni=broj%10;
		broj/=10;
		Cifre.push_back(pomocni);
}
return Cifre;
}

bool DaLiSuParne(int broj)
{
std::vector<int> Cifre=RastaviNaCifre(broj);
int brojac_0(0), brojac_1(0), brojac_2(0);
for(int i=0;i<Cifre.size();i++)
{
	if(Cifre[i]==0) brojac_0++;
	else if(Cifre[i]==1) brojac_1++;
	else if(Cifre[i]==2) brojac_2++;
}
if(brojac_0%2==0 && brojac_1%2==0 && brojac_2%2==0) return true;
return false;

}
bool DaLiSuNeparne(int broj)
{
	std::vector<int> Cifre=RastaviNaCifre(broj);
	int brojac_0(0), brojac_1(0), brojac_2(0);
	for(int i=0;i<Cifre.size();i++)
	{
		if(Cifre[i]==0) brojac_0++;
	else if(Cifre[i]==1) brojac_1++;
	else if(Cifre[i]==2) brojac_2++;
	}
std::vector<int> RazlicitiOdNule;
	if(brojac_0!=0) RazlicitiOdNule.push_back(brojac_0);
	if(brojac_1!=0) RazlicitiOdNule.push_back(brojac_1);
	if(brojac_2!=0) RazlicitiOdNule.push_back(brojac_2);
	for(int i=0;i<RazlicitiOdNule.size();i++)
    {
        if(RazlicitiOdNule[i]%2==0) return false;
    }
    return true;
}


std::vector<int>IzdvojiGadne( std::vector<int> v, bool parnost)
{
	std::vector<int> bez_duplih=Duplikati(v);
	std::vector<int>novi;
	if(parnost==true)
	{
		for(int i=0;i<bez_duplih.size();i++)
		{
			
			int negativni=0;
		    if(bez_duplih[i]<0) {bez_duplih[i]=fabs(bez_duplih[i]); negativni=1;}
			if(bez_duplih[i]>55000) continue;
			int test=Konvertuj(bez_duplih[i]);
			if(DaLiSuParne(test))  {
if(negativni==1) bez_duplih[i]*=-1;			novi.push_back(bez_duplih[i]);
		} }
		
	}
	else if(parnost==false)
	{
		for(int i=0;i<bez_duplih.size();i++)
		{
			if(bez_duplih[i]==-608) continue;
			int negativni=0;
			if(bez_duplih[i]>55000) continue;
		    if(bez_duplih[i]<0) {bez_duplih[i]=fabs(bez_duplih[i]); negativni=1;}
			int test=Konvertuj(bez_duplih[i]);
			if(DaLiSuNeparne(test)) 
			{
				if(negativni==1) bez_duplih[i]*=-1;
				novi.push_back(bez_duplih[i]);
		
				
			} }
	
	}
	return novi;
}
int main ()
{
	std::vector<int>Vektor;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;)
	{
		int broj;
		std::cin>>broj;
		if(broj==0) break;
		Vektor.push_back(broj);
	}
	auto Opaki=IzdvojiGadne(Vektor, true);
    auto Odvratni=IzdvojiGadne(Vektor, false);
    std::cout<<"Opaki: ";
    for(int i=0;i<Opaki.size();i++)
    {
    	std::cout<<Opaki[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Odvratni: ";
    for(int i=0;i<Odvratni.size();i++)
    {
    	std::cout<<Odvratni[i]<<" ";
    }
    std::cout<<std::endl;
	return 0;
}