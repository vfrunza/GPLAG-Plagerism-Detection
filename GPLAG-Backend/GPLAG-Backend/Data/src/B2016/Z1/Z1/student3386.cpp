#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

vector<int> IzdvojiGadne(vector <int> v ,bool provjera)
{
	vector <int> novi;
	vector <int> cifre;
	for(long long x:v)
	{
		cifre.resize(0);
		int baza(3);
		long long broj=x;
		int c=broj%baza;
		if(c<0)
			c=-c;
		cifre.push_back(c);
		broj/=baza;
		if(broj<0)
			broj=-broj;
		while(broj)
		{
			cifre.push_back(broj%baza);
			broj/=baza;
		}
		bool parni=true,neparni=true;
		for(int i=0; i<3; i++)
		{
			int brojac(0);
			for(int y:cifre)
			{
				if(y==i)
					brojac++;
			}
			if(brojac==0)
				continue;
			if(brojac%2==0)
				neparni=false;
			else if(brojac%2!=0)
				parni=false;
		}
		bool novibr=true;
		for(int j:novi)
			if(j==x)
				novibr=false;
		if(parni and provjera and novibr)
			novi.push_back(x);
		if(neparni and !provjera and novibr)
			novi.push_back(x);
	}
	return novi;

}

int main ()
{
	vector <int> v;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;)
	{
		int n;
		cin>>n;
		if(n==0)
			break;
		v.push_back(n);
	}
	vector <int> v1;
	v1=IzdvojiGadne(v,true);
	vector <int> v2;
	v2=IzdvojiGadne(v,false);
	cout<<"Opaki: ";
	for(int x:v1)
		cout<<x<<" ";
	cout<<"\n";
	cout<<"Odvratni: ";
	for(int x:v2)
		cout<<x<<" ";
	cout<<"\n";

	return 0;
}