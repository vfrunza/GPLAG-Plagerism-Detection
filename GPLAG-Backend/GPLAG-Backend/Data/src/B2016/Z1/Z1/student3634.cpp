/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

bool opakiILIgadni(int broj)
{
	broj=abs(broj);
	std::vector<int> brojaci(3);
	while(broj>0)
	{
		brojaci[broj%3]++;
		broj/=3;
	}
	
	for(int i(0);i<brojaci.size();i++)
		if(brojaci[i]%2!=0 && brojaci[i]!=0) return false;
		
	return true;
}

bool odvrataILIgadni(int broj)
{
	broj=abs(broj);
	std::vector<int> brojaci(3);
	while(broj>0)
	{
		brojaci[broj%3]++;
		broj/=3;
	}
	
	for(int i(0);i<brojaci.size();i++)
		if(brojaci[i]%2==0 && brojaci[i]!=0) return false;
		
	return true;
}

std::vector<int> IzdvojiGadne(std::vector<int>v, bool a) {
	std::vector<int>v_opaki;
	std::vector<int>v_gadni;
	
	for(int i(0);i<v.size();i++)
	{
		if(opakiILIgadni(v[i]))
		{
			int c(0);
			for(int j(0);j<v_opaki.size();j++)
			{
				if(v_opaki[j]==v[i]) c=1;
			}
			if(c==0) v_opaki.push_back(v[i]);
		}else if(odvrataILIgadni(v[i]))
		{
			int c(0);
			for(int j(0);j<v_gadni.size();j++)
			{
				if(v_gadni[j]==v[i]) c=1;
			}
			if(c==0) v_gadni.push_back(v[i]);
		}
	}
	if(a) return v_opaki; else return v_gadni;
	
}

int main ()
{
	int n;
	std::vector<int>v;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for(;;) {
		std::cin >> n;
		if(n==0) break;
		v.push_back(n);
	}
/*	IzdvojiGadne(v, a);
	std::cout << "Opaki: " << std::endl;
	std::cout << "Odvratni: ";*/
	std::vector<int>rezO(IzdvojiGadne(v,true));
	std::vector<int>rezG(IzdvojiGadne(v,false));
	std::cout<<"Opaki: ";
	for(int i(0);i<rezO.size();i++)
	std::cout<<rezO[i]<<" ";
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i(0);i<rezG.size();i++)
	std::cout<<rezG[i]<<" ";
	return 0;
}