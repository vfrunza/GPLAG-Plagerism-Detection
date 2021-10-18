#include <iostream>
#include <vector>


using std::cout;
using std::vector;
using std::cin;
using std::endl;

typedef vector<vector<double>> Matrica;


vector<int> IzdvojiGadne (vector<int> vek, bool s)
{
	vector<int> novi1;
	vector<int> novi2;
	int brojac0=0,brojac1=0,brojac2=0;
	long int n;
	
		for (int i=0; i<vek.size()-1; i++)
		{
			for (int z=i+1; z<vek.size(); z++)
			{
				if (vek[i]==vek[z]) 
				{
				vek.erase(vek.begin()+z);
				z--;
				}
				
			}
			
		}

for (int i=0; i<vek.size(); i++)
{
		n=vek[i];
		while (n!=0)
		{
			if (n<0) n=n*(-1);
			if (n%3==0) brojac0++;
			else if (n%3==1) brojac1++;
		    else brojac2++;
			n/=3;
		}
		if (brojac0%2==0 && brojac1%2==0 && brojac2%2==0) novi1.push_back(vek[i]);
		if ((brojac0%2!=0 || brojac0==0) && (brojac1%2!=0 || brojac1==0) && (brojac2%2!=0 || brojac2==0)) novi2.push_back(vek[i]);
		brojac0=0;
		brojac1=0;
 		brojac2=0;
		
	}
	if (s==true)
	{
		return novi1;
	}
	return novi2;

}
int main ()
{
	int n;
	vector<int> glavni_vektor;
	cout << "Unesite brojeve (0 za prekid unosa): ";
	do {
			cin >> n;
			if (n!=0) glavni_vektor.push_back(n);
		
		} while (n!=0);
		vector<int> parni;
		vector<int> neparni;
		
		parni=IzdvojiGadne(glavni_vektor,true);
		cout << "Opaki: ";
		for (int i=0; i<parni.size(); i++) {
		cout << parni[i] << " "; } cout << endl;
	
		neparni=IzdvojiGadne(glavni_vektor,false);
		cout << "Odvratni: ";
		for (int i=0; i<neparni.size(); i++) {
		cout << neparni[i] << " "; } cout << endl;
	return 0;
}