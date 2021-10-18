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


using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::abs;

vector<int> IzdvojiGadne(vector<int> v, bool vrijednost)
{
	
	vector<int> opaki;
	vector<int> odvratni;
	
	for(int i=0; i<v.size(); i++)
	{
		pocetak: 
		
		if(i==v.size()) break;
		int brojac0(0), brojac1(0), brojac2(0);
		
		
		bool postoji(false);
		if(opaki.size()!=0)
		{
			for(int j=0; j<opaki.size(); j++)
			{
				if(opaki[j]==v[i])
				{
					postoji=true;
					break;
				}
			}
		}
		
		if(i<v.size() && postoji)
		{
			i++;
			goto pocetak;
		}
		
		postoji=false;
		if(odvratni.size()!=0)
		{
			for(int j=0; j<odvratni.size(); j++)
			{
				if(odvratni[j]==v[i])
				{
					postoji=true;
					break;
				}
			}
		}
		
		if(i<v.size() && postoji)
		{
			i++;
			goto pocetak;
		}
		
		int temp((v[i]));
		if(v[i]<0) temp=-temp;
		do
		{
			if(temp%3==0) brojac0++;
			else if(temp%3==1) brojac1++;
			else brojac2++;
			
			temp=temp/3;
			if(temp==0) break;
		}while(temp!=0);
		
		if(brojac0%2==0 && brojac2%2==0 && brojac1%2==0) opaki.push_back(v[i]);
		
		else if((brojac0%2!=0 || brojac0==0) && (brojac1%2!=0 || brojac1==0) && (brojac2==0 || brojac2%2!=0)) odvratni.push_back(v[i]);
		
		
		
	}
	
	if(vrijednost) return opaki;
	else return odvratni; 
}


int main ()
{
	vector<int> v;
	cout << "Unesite brojeve (0 za prekid unosa): ";
	int broj;
	cin >> broj;
	do
	{
		v.push_back(broj);
		cin >> broj;
		if(broj==0) break;
	}while(broj!=0);
	
	vector<int> opaki(IzdvojiGadne(v,true));
	vector<int> odvratni(IzdvojiGadne(v, false));
	
	cout << "Opaki: ";
	for(int x : opaki) cout << x << " ";
	
	cout << endl;
	cout << "Odvratni: ";
	for(int x : odvratni) cout << x << " ";
	
	
	
	return 0;
}