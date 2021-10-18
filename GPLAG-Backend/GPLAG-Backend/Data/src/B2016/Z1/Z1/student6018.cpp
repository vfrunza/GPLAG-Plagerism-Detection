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

using namespace std;

long long int bazatri(int broj)
{	long long int suma(0);
	int n(0);
	int ostatak;
	if(broj<0) broj=-broj; 
	while(broj!=0)
	{
		ostatak=broj%3;
		broj=broj/3;
		suma=suma+ostatak*pow(10,n);
		n++;
	}
	return suma;
}

vector<int> IzdvojiGadne(vector<int>v,bool l)
{
	vector<int>a,b;
	
	if(v.size()==0)
	return a;
	int brojacnula(0),brojacjedinica(0),brojacdvojki(0); 
	
	
	for(int i=0;i<v.size();i++)
	{
		for(int j=i+1;j<v.size();j++)
		{
			if(v[i]==v[j]){
			v.erase(v.begin()+j);						//brise one koji su isti	
			j--;
			}
		}
	}
	vector<long long int>v3;					// kreira vektor u bazi 3
	for(int i=0;i<v.size();i++)
	{
		long long int c=bazatri(v[i]);			
		v3.push_back(c);
	}
	int ostatak;
	for(int i=0;i<v3.size();i++)
	{
		
		brojacnula=0;
		brojacjedinica=0;				//vraca brojace na nula za svaki broj
		brojacdvojki=0;
		
		if(v3[i]==0)
		brojacnula++;
		while(v3[i]!=0)
		{
			ostatak=v3[i]%10;
			v3[i]=v3[i]/10;
			if(ostatak==0)
			brojacnula++;
			else if(ostatak==1)
			brojacjedinica++;				// prebrojava cifre
			else 
			brojacdvojki++;
		}
		if((brojacnula%2==0 || brojacnula==0) && (brojacjedinica%2==0 || brojacjedinica==0) && (brojacdvojki%2==0 || brojacdvojki==0))
		a.push_back(v[i]);
		else if((brojacnula%2!=0 || brojacnula==0) && (brojacjedinica%2!=0 || brojacjedinica==0) && (brojacdvojki%2!=0 || brojacdvojki==0))
		b.push_back(v[i]);
		// ovdje vektor punim sa onim početnim koji je u bazi 10, jer se brojevi u vektoru v3 i v nalaze na istoj poziciji; 
		// dakle nema potrebe za promjenom brojeva u bazu 10, jer su u vektoru u bazi 10, ne punimo više vektore a i b vektorom v3 nego v
		
	}
	if(l)
	return a;
	return b;
	
}

int main ()
{
	vector<int>unos;
	int a;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(int i=0;;i++)
	{
		cin>> a;
		if(a==0)
		break;
		unos.push_back(a);
	}
	
	vector<int>a1=IzdvojiGadne(unos,true);
	vector<int>a2=IzdvojiGadne(unos,false);
	cout<<"Opaki: ";
	for(int c:a1)
		cout<<c<<" ";
	cout<<endl;
	cout<<"Odvratni: ";
	for(int c:a2)
		cout<<c<<" ";
	cout<<endl;

	
	
	return 0;
}