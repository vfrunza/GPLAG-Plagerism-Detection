/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne (std::vector<int> v, bool vrijednost)
{
	int i,j,k,l,cifra,n,a,z;
	std::vector<int> v1,v2,v3;
	for(i=0;i<v.size();i++)
	{ 
	
		for(l=i+1;l<v.size();l++)
		{ 
			if(v[i]==v[l]) 
	     	{
			a=l;
			break;
			} 
			
		}
		if (i==a ) continue;
		else {
		
		n=v[i];
		if(n<0) {
			cifra=n%3;
			if(cifra<0) cifra=cifra*(-1);
			n/=3;
			n=n*(-1);
			v1.push_back(cifra);
		}
		//pretvoriti u ternarni zapis
		while(n>0)
		{
			cifra=n%3;
			n=n/3;
			v1.push_back(cifra);
		}
		int brojac_parni=0,brojac_neparni=0;
	
		for(j=0;j<v1.size();j++)
		{
			int brojac=1;
			
			for(k=j+1;k<v1.size();k++)
			{
				if(v1[j]==v1[k]) 
			
				brojac++;
			}
			int brojac2=1;
			for(z=j-1;z>=0;z--)
			{
				if(v1[j]==v1[z])
				brojac2++;
			}
			if(brojac2==1){
			if(brojac%2==0) brojac_parni++;
			else if(brojac%2!=0) brojac_neparni++;
			}
			
		}
	
	if(brojac_parni!=0 && brojac_neparni==0) v2.push_back(v[i]);
	else if(brojac_neparni!=0 && brojac_parni==0) v3.push_back(v[i]);
	}
	}
	if(vrijednost == true) return v2;
	else return v3;
	
}

int main ()
{
	std::vector <int> v,v2,v3;
	int i,broj;
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;)
	{
		std::cin>>broj;
		if(broj!=0) v.push_back(broj);
		else break;
		
	}
	v2=IzdvojiGadne(v,1);
	

	std::cout<<"Opaki: ";
	for(i=0;i<v2.size();i++)
	{
		std::cout<<v2[i]<<" ";
	}
	
	v3=IzdvojiGadne(v,0);
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(i=0;i<v3.size();i++)
	{
		std::cout<<v3[i]<<" ";
	}
	return 0;
}