#include<iostream>
#include<vector>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::pow;

vector<int>IzdvojiGadne(vector<int>a,bool b){
	int x,suma(0),brojac(0);
	bool parni=0,neparni=0;
	vector<int>emina;
	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<a.size();j++){
			if(a[i]==a[j]){
				for(int k=j;k<a.size()-1;k++)
					a[k]=a[k+1];
					a.resize(a.size()-1);
					j--;
			}
		}
	}
	for(int i=0;i<a.size();i++){
		suma=0;
		brojac=0;
		vector<int>w(3);
		int pomocna=a[i];
		if(a[i]<0) a[i]=-a[i];
		while(a[i]!=0){
		x=fabs(a[i]%3);
		w[x]++;
		a[i]/=3;
		suma=suma+x*pow(10,brojac);
		brojac++;
		}
		parni=0;
		neparni=0;
		for(int j=0;j<3;j++){
			if(w[j]%2==0 && w[j]!=0)parni=true;
			else if(w[j]%2==1) neparni=true;
	
		}
		if(b==true && parni==true && neparni==false)emina.push_back(pomocna);
		if(b==false && parni==false && neparni==true)emina.push_back(pomocna);
		}
		return emina;
}

int main ()
{
	vector<int>a;
	long int broj;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		cin>>broj;
		if(broj!=0) a.push_back(broj);
	}while(broj!=0);
	vector<int>z;
	z=IzdvojiGadne(a,true);
	cout<<"Opaki: ";
	for(int i=0;i<z.size();i++)cout<<z[i]<<" ";
	cout<<endl;
	z=IzdvojiGadne(a,false);
	cout<<"Odvratni: ";
	for(int i=0;i<z.size();i++)cout<<z[i]<<" ";
	return 0;
}