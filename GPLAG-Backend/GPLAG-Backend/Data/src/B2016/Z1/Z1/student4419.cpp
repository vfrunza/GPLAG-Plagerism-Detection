/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
	

bool DaLiJeOpak (int broj)
{
    int	br=abs(broj);
	std::vector<int>cifre;
	std::vector<int>brojaci(3,0);
	int opak(0);
	while(br!=0)
	{
		cifre.push_back(br%3);
		br/=3;
		
	}
	
	
	for(int i=0; i<cifre.size(); i++)
	{
		brojaci[cifre[i]]++;
	}

	
    for(int j=0; j<3; j++)
    {
    	if(brojaci[j]%2==0) opak++;
    }
	
	if(opak==3)  return true;
	else return false;
	
}

bool DaLiJeOdvratan (int broj){
	
	int br=abs(broj);
	std::vector<int>cifre;
	std::vector<int>brojaci(3,0) ;
    int	odvratan(0);
	while(br!=0)
	{
		cifre.push_back(br%3);
		br/=3;
		
	}

	
	for(int i=0; i<cifre.size(); i++)
	{
		brojaci[cifre[i]]++;
	}

	
    for(int j=0; j<3; j++)
    {
    
    	if(brojaci[j]%2!=0 || brojaci[j]==0) odvratan++;
    	
    }
    if(odvratan==3) return true;
    else return false;
	
}

std::vector<int> IzdvojiGadne (std::vector<int> v, bool a) {
	
	std::vector<int>noviVektor ;
	int isti_opaki(0), isti_odvratni(0);
	
	if(a==true) 
	{
	
		for(int i=0; i<v.size(); i++) 
		{
				for(int j=0; j<noviVektor.size(); j++){
				if(v[i]==noviVektor[j]) isti_opaki=1;
		        
				}
			if( DaLiJeOpak(v.at(i)) && isti_opaki==0 ) noviVektor.push_back(v.at(i));
			isti_opaki=0;
		}
	};
		if(a==false)
		{
			for(int i=0; i<v.size(); i++)
			{
				for(int j=0; j<noviVektor.size(); j++){
				if(v[i]==noviVektor[j]) isti_odvratni=1;
				}
				if( DaLiJeOdvratan(v.at(i)) && isti_odvratni==0 ) noviVektor.push_back(v.at(i));
				isti_odvratni=0;
			}
     	};
	
	return noviVektor;
};
int main ()
{
	std::vector<int>vektor;
	int a;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for(;;)
	{
		std::cin>>a;
		if(a!=0) vektor.push_back(a);
		else break;
	}
    std::vector<int>Opaki;
    std::vector<int>Odvratni ;
	
	Opaki=IzdvojiGadne(vektor, true);
	std::cout << "Opaki: ";
	for(int i=0; i<Opaki.size(); i++)
	std::cout<<Opaki.at(i) << " ";
	
	std::cout << std::endl;
	
	Odvratni=IzdvojiGadne(vektor, false);
	std::cout << "Odvratni: ";
	for(int i=0; i<Odvratni.size(); i++)
	std::cout << Odvratni.at(i) << " ";
	
	return 0;
}





