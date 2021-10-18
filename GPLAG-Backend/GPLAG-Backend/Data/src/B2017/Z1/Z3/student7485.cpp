#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::deque;

enum Smjer {Rastuci=true, Opadajuci=false};

bool StepenDvojke(int broj)
{
	if (broj==0 || broj<0)
		return false;
	if (broj==1)
		return true;
	while(broj!=0)
	{
		if (broj%2!=0)
			return false;
		broj/=2;
		if (broj==1)
			break;
	}
	return true;
}

deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> v, Smjer p)
{
	deque<vector<int>> vracaj;
	
	if (p==Rastuci)
	{
		vector<int> pomocni;
		for(int i=0; i<v.size(); i++)
		{
			if (StepenDvojke(v.at(i)))
				pomocni.push_back(v.at(i));
			else
				pomocni.push_back(3);
		}
		pomocni.push_back(3);
		vector<int> vektor;
		for(int i=0; i<pomocni.size()-1; i++)
		{
			if (pomocni.at(i)!=3 && pomocni.at(i+1)!=3 && pomocni.at(i)<=pomocni.at(i+1))
				vektor.push_back(pomocni.at(i));
			else if (pomocni.at(i)!=3 && pomocni.at(i)>pomocni.at(i+1) && vektor.size()!=0)
			{
				vektor.push_back(pomocni.at(i));
				vracaj.push_back(vektor);
				vektor.clear();
			}
			else if (pomocni.at(i)!=3 && pomocni.at(i+1)==3 && vektor.size()!=0)
			{
				vektor.push_back(pomocni.at(i));
				vracaj.push_back(vektor);
				vektor.clear();
			}
		}
	}
	
	else if (p==Opadajuci)
	{
		vector<int> pomocni;
		for(int i=0; i<v.size(); i++)
		{
			if (StepenDvojke(v.at(i)))
				pomocni.push_back(v.at(i));
			else 
				pomocni.push_back(3);
		}
		pomocni.push_back(3);
		vector<int> vektor;
		for(int i=0; i<pomocni.size()-1; i++)
		{
			if (pomocni.at(i)!=3 && pomocni.at(i+1)!=3 && pomocni.at(i)>=pomocni.at(i+1))
				vektor.push_back(pomocni.at(i));
			else if (pomocni.at(i)!=3 && pomocni.at(i)<pomocni.at(i+1) && vektor.size()!=0)
			{
				vektor.push_back(pomocni.at(i));
				vracaj.push_back(vektor);
				vektor.clear();
			}
			else if (pomocni.at(i)!=3 && pomocni.at(i+1)==3 && vektor.size()!=0)
			{
				vektor.push_back(pomocni.at(i));
				vracaj.push_back(vektor);
				vektor.clear();
			}
		}
	}
	
	return vracaj;
}


int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int br_el;
	cin>>br_el;
	vector<int> v;
	int broj;
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<br_el; i++)
	{
		cin>>broj;
		v.push_back(broj);
	}
	int trazeno;
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin>>trazeno;
	deque<vector<int>> vraceni;
	if (trazeno==1)
	{
		vraceni=MaksimalniPodnizoviStepenaDvojke(v,Rastuci);
		cout<<"Maksimalni rastuci podnizovi: \n";
		for(int i=0; i<vraceni.size(); i++)
		{
			for(int j=0; j<vraceni[i].size(); j++)
				cout<<vraceni[i][j]<<" ";
			cout<<"\n";	
		}
	}	
	else if(trazeno==2)
	{
		vraceni=MaksimalniPodnizoviStepenaDvojke(v, Opadajuci);
		cout<<"Maksimalni opadajuci podnizovi: \n";
		for(int i=0; i<vraceni.size(); i++)
		{
			for(int j=0; j<vraceni[i].size(); j++)
				cout<<vraceni[i][j]<<" ";
			cout<<"\n";	
		}
	}	
	

	return 0;
}