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

bool DaLiSeNalaziUVektoru(std::vector<int> vektor, int broj)
{
	for(int i=0;i<vektor.size();i++)
	{
		if(vektor[i]==broj) return true;
	}
	return false;
}

std::vector<int> PretvoriUBazuTri(int a){
	if(a<0) a*=-1;
	std::vector<int> cifre;
	while(a!=0){
		if(a/3!=0)
		{
			cifre.push_back(a%3);
			a/=3;
		}
		else
		{
		cifre.push_back(a);
		a/=3;
		}
	}
	return cifre;
}
bool Opak(int broj){
    int jedinica=0,dvica=0,nula=0;
    std::vector<int> broj_u_bazi_3(PretvoriUBazuTri(broj));
    for(int i =0 ; i<broj_u_bazi_3.size();i++)
    {
    	if(broj_u_bazi_3[i]==0) nula++;
    	else if(broj_u_bazi_3[i]==1) jedinica++;
    	else dvica++;
    }
    
    if(nula%2==0 && jedinica%2==0 && dvica%2==0) return true;
    else return false;
}
bool Odvratan(int broj)
{
	int nula=0,jedinica=0,dvica=0;
	std::vector<int> broj_u_bazi_3(PretvoriUBazuTri(broj));
	   for(int i =0 ; i<broj_u_bazi_3.size();i++)
    {
    	if(broj_u_bazi_3[i]==0) nula++;
    	else if(broj_u_bazi_3[i]==1) jedinica++;
    	else dvica++;
    }
    
	if((nula%2==1 || nula==0) && (jedinica%2==1||jedinica==0) && (dvica%2==1 || dvica==0)) return true;
	else return false;
}
std::vector<int> IzdvojiGadne(std::vector<int> v, bool tacnost)
{
	
	std::vector<int> v3;
	std::vector<int> v4;

	if(tacnost)	
	{ //vrati opake
		
		for(int i=0;i<v.size();i++)
		{
		 if(Opak(v[i]) && !DaLiSeNalaziUVektoru(v3,v[i])) v3.push_back(v[i]);
		
		}
	}
	else 
	{ //vrati odvratne
		for(int i=0;i<v.size();i++)
		{
			if(Odvratan(v[i])&& !DaLiSeNalaziUVektoru(v4,v[i])) v4.push_back(v[i]);
		}
	}
	if(tacnost) return v3;
	else return v4;
}
int main ()
{ 
	std::vector<int> v;
	int broj;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>broj;
		if(broj!=0) v.push_back(broj);
	} 
	while(broj!=0); 
	std::vector<int> v2;
	std::vector<int> opaki(IzdvojiGadne(v,true));
	std::vector<int> odvratni(IzdvojiGadne(v,false));
	std::cout<<"Opaki: ";
	for(int i=0;i<opaki.size();i++){
		std::cout<<opaki[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i=0;i<odvratni.size();i++){
		std::cout<<odvratni[i]<<" ";
	} 
	
	
	
	return 0;
}