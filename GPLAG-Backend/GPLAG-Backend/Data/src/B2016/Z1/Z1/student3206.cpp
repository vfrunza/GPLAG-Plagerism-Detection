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

using std::cin;
using std::cout;

int Provjeri(int x){
	int temp=x;
	std::vector<int>b(0);
	do{
		b.push_back(temp%3);
		temp=temp/3;
	}while(temp!=0);
	std::vector<int>brojaci(3,0);
	for(int x:b){
		for(int i=0;i<brojaci.size();i++)
		if(i==abs(x))
		brojaci[i]++;
	}
	bool opaki(true);
	for(int i=0;i<3;i++){
		if(brojaci[i]%2!=0 && brojaci[i]!=0){
			opaki=false;
			break;
		}
	}
	bool odvratni(true);
	for(int i=0;i<3;i++){
		if(brojaci[i]%2==0 && brojaci[i]!=0){
			odvratni=false;
			break;
		}
	}
	if(opaki)
	return 2;
	else if(odvratni)
	return 1;
	else
	return 0;
}
std::vector<int> IzdvojiGadne(std::vector<int> v,bool t){
	std::vector<int> opaki;
	std::vector<int> odvratni;
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(v[i]==v[j]){
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	for(int x:v){
		int k=Provjeri(x);
		if(k==2)
		opaki.push_back(x);
		else if(k==1)
		odvratni.push_back(x);
	}
	if(t)
	return opaki;
	else
	return odvratni;
}
int main ()
{
	int n;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	while(cin>>n,n!=0){
		v.push_back(n);
	}
	cout<<"Opaki: ";
	std::vector<int> op=IzdvojiGadne(v,true);
	for(int i=0;i<op.size();i++){
		cout<<op[i]<<" "; 
	}
	cout<<"\n";
	cout<<"Odvratni: ";
	std::vector<int> od=IzdvojiGadne(v,false);
	for(int i=0;i<od.size();i++){
		cout<<od[i]<<" ";
	}
	return 0;
}