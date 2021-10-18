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

int Terarni(int broj)
{
	std::vector<int> vec;
	int ter(0),obrnuto(0);
	int temp=broj;
	vec.clear();
	do
	{
		ter=temp%3;
		temp/=3;
		vec.push_back(ter);
	}while(temp!=0);
	
	for(int i=vec.size()-1;i>=0;i--)
	{
		obrnuto=obrnuto*10+vec.at(i);
	}
	return obrnuto;
}

bool Simetrican(int broj)
{
	int temp;
	temp=broj;
	std::vector<int> vec;
	int sim(0);
	int obrnuto(0);
	do
	{
		sim=temp%10;
		temp/=10;
	}while(temp!=0);
	

	
	return(sim==broj);
}

bool Prost(int broj)
{
	unsigned int temp=broj;
	if(temp<=1) return false;
	for(unsigned int i=2;i<=temp/2;++i)
	{
		if(temp%i==0)
		{
			return false;
			break;
		}
	}
return true;	
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int>brojevi,bool pr)
{
	std::vector<int> vec;
	
	for(int i=0;i<int(brojevi.size());i++)
	{
		for(int j=0;j<int(brojevi.size());j++)
		{
			if(brojevi.at(i)==brojevi.at(j) && i!=j)
			{
				brojevi.erase(brojevi.begin()+j);
				j--;
			}
		}
	}
	bool predznak(false);
	for(int i=0;i<brojevi.size();i++)
	{
		predznak=false;
		if(brojevi.at(i)<0) 
		{
			brojevi.at(i)*=-1;
			predznak=true;
		}
		int broj=Terarni(brojevi.at(i));
		if(pr)
		{
			if(Prost(brojevi.at(i)))
			{
				if(Simetrican(broj))
				{
					if(predznak) brojevi.at(i)*=-1;
					vec.push_back(brojevi.at(i));
				}
			}
		}
		else
		{
			if(!Prost(brojevi.at(i)))
			{
				if(Simetrican(broj))
				{
					if(predznak) brojevi.at(i)*=-1;
					vec.push_back(brojevi.at(i));
				}
			}
		}
	}
	return vec;
}

int main ()
{
	int broj,n;
	bool pr;
	std::vector<int> vec;
	std::cout <<"Unesite elemente vektora (-1 za kraj): ";
	
	do
	{
		std::cin>>broj;
		if(broj==-1)break;
		vec.push_back(broj);
	}while(1);
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do
	{
		std::cin>>n;
		if(n==0 || n==1)
		{
			pr=n;
			break;
		}
		else std::cout<<"Neispravan unos! Unesite ponovo: ";
	}while(1);
	
	std::vector<int>ter(IzdvojiSimetricneTernarne(vec,pr));
	if(ter.size()>0)
	{
		if(pr) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		else if(!pr) std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<int(ter.size());i++)
		{
			std::cout<<ter.at(i);
			if(i!=ter.size()-1) std::cout<<", ";
			else std::cout<<".";
		}
	}
	else 
	{
		if(pr) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else  std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	}
	
	return 0;
}