#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> IzdvojiGadne(vector<int> vec,bool iv){
	std::vector<unsigned long long int>vektor1(vec.size(),0);
	vector<int> opaki,odvratni;
	for(int i=0; i<vec.size(); i++){
		int priv(vec[i]);
		int broj(0);
		do{
			int priv1;
			priv1 = abs(priv) % 3 ;
			vektor1[i]*=priv1*pow(10,broj);
			priv=priv/3;
			broj++;
			
		}while(priv != 0);
		
		int bra(0),brb(0),brc(0);
		long long int privt(vektor1[i]);
		do{
			int a(0),b(1),c(2);
			int priv1;
			priv1=privt%10;
			if(priv1==a) bra++;
			else if(priv1==b) brb++;
			else if(priv1==c) brc++;
			privt/=10;
			}while(privt != 0);
			
		if (bra%2==0 && brb%2==0 && brc%2==0){
			int brojac(0);
			for(int j=i-1; j>=0; j--)
				if(vec[i]==vec[j]) broj++;
				if(brojac==0) opaki.push_back(vec[i]);
			}
			else if ((bra%2!=0 && brb%2!=0 && brc!=0) || (bra==0 && brb%2!=0 && brc%2!=0) || (bra%2!=0 && brb==0 && brc%2!=0) || (bra%2!=0 && brb%20!=0 && brc==0) ||
			(bra%2!=0 && brb==0 && brc==0) || (bra==0 && brb==0 && brc%2!=0) || (bra==0 && brb%2!=0 && brc==0)){
				int br1(0);
				for (int j=i-1; i>=0; i--)
					if(vec[i]==vec[j]) br1++;
			
				if (br1==0) odvratni.push_back(vec[i]);
			}
			else continue;
		} if (iv==true) return opaki;
		else odvratni;
	
}

int main ()
{
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	vector<int> vektor;
	int n;
	do{
		cin>>n;
		if(n==0) continue;
		vektor.push_back(n);
	}while(n!=0);
	
	vector<int> opaki(IzdvojiGadne(vektor,true)), odvratni(IzdvojiGadne(vektor,false));
	cout<<"Opaki: ";
	for (int i=0; i<opaki.size(); i++)
		cout<<opaki[i]<<" ";
		cout<<endl<<"Odvratni: ";
		for(int i=0; i<odvratni.size(); i++) cout<<odvratni[i]<<" ";
	
	
	return 0;
}