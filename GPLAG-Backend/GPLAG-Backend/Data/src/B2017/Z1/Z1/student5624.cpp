#include <iostream>
#include <cmath>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

bool Prosti(int broj)
{
	for(int i=2; i<=std::sqrt(broj); i++)
		if (broj%i==0)
			return false;
	return true;		
}

vector<int> IzdvojiSimetricneTernarne(vector<int> v, bool p)
{
	vector<int> vracaj;
	if (p==true)
	{
		for(int i=0; i<v.size(); i++)
		{
			int broj;
			broj=std::abs(v.at(i));
			bool postoji=false;
			for(int j=0; j<vracaj.size(); j++)
			{
				if (vracaj.at(j)==v.at(i))
				{
					postoji=true;
					break;
				}
			}
			if (postoji==true)
				continue;
				
			if (Prosti(broj))
			{
				vector<int> pomocni;
				while(broj!=0)
				{
					int ostatak;
					ostatak=broj%3;
					pomocni.push_back(ostatak);
					broj/=3;
				}
				bool simetricni=true;
				int k;
				k=pomocni.size()-1;
				for(int j=0; j<pomocni.size()/2; j++)
				{
					if (pomocni.at(j)!=pomocni.at(k))
					{
						simetricni=false;
						break;
					}	
					k--;
				}
				if (simetricni==true)
					vracaj.push_back(v.at(i));
			}
		}
	}
	else if (p==false)
	{
		for(int i=0; i<v.size(); i++)
		{
			int broj;
			broj=std::abs(v.at(i));
			bool postoji=false;
			for(int j=0; j<vracaj.size(); j++)
			{
				if (vracaj.at(j)==v.at(i))
				{
					postoji=true;
					break;
				}
			}
			if (postoji==true)
				continue;
			if(!(Prosti(broj)))
			{
				vector<int> pomocni;
				while(broj!=0)
				{
					int ostatak;
					ostatak=broj%3;
					pomocni.push_back(ostatak);
					broj/=3;
				}
				bool simetricni=true;
				int k;
				k=pomocni.size()-1;
				for(int j=0; j<pomocni.size()/2; j++)
				{
					if (pomocni.at(j)!=pomocni.at(k))
					{
						simetricni=false;
						break;
					}	
					k--;
				}
				if (simetricni==true)
					vracaj.push_back(v.at(i));
			}
		}
		
	}
	return vracaj;
}


int main ()
{
	vector<int> v;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	int broj;
	for(;;)
	{
		cin>>broj;
		if (broj==-1)
			break;
		v.push_back(broj);
	}
	int p;
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while(1)
	{
		cin>>p;
		if (p==1 || p==0)
			break;
		cout<<"Neispravan unos! Unesite ponovo: ";	
	}	
	vector<int> vraceni;
	if (p==1)
	{
		vraceni=IzdvojiSimetricneTernarne(v,true);
		if (vraceni.size()==0)
			cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else
		{
			cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<vraceni.size(); i++)
			{
				if (i!=vraceni.size()-1)
					cout<<vraceni.at(i)<<", ";
				else if (i==vraceni.size()-1)
					cout<<vraceni.at(i)<<".";
			}
		}	
	}	
	else if (p==0)
	{
		vraceni=IzdvojiSimetricneTernarne(v,false);
		if (vraceni.size()==0)
			cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else	
		{
			cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<vraceni.size(); i++)
			{
				if (i!=vraceni.size()-1)
					cout<<vraceni.at(i)<<", ";
				else if (i==vraceni.size()-1)
					cout<<vraceni.at(i)<<".";
			}
		}	
	}	
			
	return 0;
}