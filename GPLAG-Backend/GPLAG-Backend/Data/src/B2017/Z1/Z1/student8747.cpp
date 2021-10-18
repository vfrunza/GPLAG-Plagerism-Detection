/*B 2017/2018, Zadaća 1, Zadatak 1
	
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
#include <cmath>

bool DaLiJeProst(int n)
{
	if(n<=1) return false;
	int brojac(0);
	for (int i = 1; i <= sqrt(n); i++)
		if(n%i==0)
		{
			brojac++;
			if(brojac==2) return false;
		}
	return true;
}

int Ternarni(int a)
{
	if(a==0) return 0;
	bool neg(false);
	int pomocna(0), brojac(0), nova(0);
	std::vector<int> vektor;
	if (a<0) neg=true;
	if (neg==true) a=abs(a);
	for(brojac=0;;brojac++)
	{
		pomocna=pow(3,brojac);
		if(a/pomocna==0 && (a-pomocna)<0) break;
		//std::cout << "pozvana"<<std::endl;
	}
	//std::cout<< pomocna << std::endl;
	pomocna=0;
	for(int i = brojac; i > 0; i--)
	{
		if(a<=2) break;
		//pomocna=pow(3,i);
		nova=a/pow(3,i);
		vektor.push_back(nova);
		pomocna=a-pow(3,i)*nova;
		a=pomocna;
	}
	//std::cout<<nova<<std::endl;
	pomocna=0;
	for(auto i : vektor)
	{
		pomocna+=pow(10,brojac)*i;
		brojac--;
	}
	pomocna+=a;
	if(neg==true) return -pomocna;
	return pomocna;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> vektor, bool tacno)
{
	std::vector<int>novi,pomocni;
	int pomocna(0),nova(0),kraj(0),pocetak(0);
	if(vektor.size()==0) return novi;
	bool test(true);
	for(auto i : vektor)
	{
		pomocna = Ternarni(i);
		//nova=pomocna;
		for(;;)
        {
            if( abs(pomocna) < 10) {pomocni.push_back(pomocna); break;}
            else if(pomocna%10!=pomocna)
            {  
                nova=abs(pomocna%10);
                pomocni.push_back(nova);
                pomocna/=10;
                //std::cout<< testna <<std::endl << i << std::endl << nova << std::endl;
            }
        }
        kraj=0;
        pocetak=0;
        for(int i =0; i < pomocni.size()/2; i++)
	    {
	        kraj=pomocni.at(pomocni.size()-i-1);
	        pocetak=pomocni.at(i);
	        if(pocetak!=kraj) test=false;
	    }
	    if(test==true){
		if(tacno==true)
		{
			if(DaLiJeProst(i))
			novi.push_back(i);
		}
	    //}
	    else if(tacno==false) if(!DaLiJeProst(i)) novi.push_back(i);}
	    test=true;
	    pomocni.clear();
	}
	
	
	return novi;
}

int main ()
{

	std::vector<int> vektor;
	int a(0);
	bool test(true),vajl(false);
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	while(std::cin>>a)
	{
		if(a==-1)
		{
			std::cout<< "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
			vajl=true;
			test=false;
		}
		if(vajl==false)
		{
			vektor.push_back(a);
		}
		if(vajl==true&&test==true) 
		{
			if(a==1 || a==0)
			{
				test=a; 
				break;
			}
			else std::cout << "Neispravan unos! Unesite ponovo: ";
		}
		test=true;
	}
	std::vector<int> novi;
	novi=IzdvojiSimetricneTernarne(vektor,test);
	int brojac(0);
	if(novi.size()!=0)
	{
		if (test==true) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(auto i : novi)
		{
			std::cout << i;
			if(brojac!=novi.size()-1) std::cout<< ", ";
			if(brojac==novi.size()-1) std::cout<<".";
			brojac++;
		}
	}
	else 
	{
		if(test==false) std::cout<< "Nema slozenih simetricnih brojeva u vektoru.";
		else std::cout<< "Nema prostih simetricnih brojeva u vektoru.";
	}
		
	return 0;
}