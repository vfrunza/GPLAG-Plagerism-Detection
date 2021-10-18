/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>

using namespace std;

bool Gadna(int n)
{
	int br0=0,br1=0,br2=0;
	while(n!=0) {
		if(n%3==0) br0++;
		if(n%3==1) br1++;
		if(n%3==2) br2++;
		n/=3;
	}
	return(br0%2==0 && br1%2==0 && br2%2==0);
}

bool Odvratni(int n)
{
	int br0=0,br1=0,br2=0;
	while(n!=0) {
		if(n%3==0) br0++;
		if(n%3==1) br1++;
		if(n%3==2) br2++;
		n/=3;
	}
	return(br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0 || br2==0);
}

bool DaLiPostoji(vector<int>v,int n)
{
	for(int i=0; i<v.size(); i++) {
		if(v[i]==n)return true;
	}
	return false;
}

vector<int>IzdvojiGadne(vector<int>v,bool a)
{
	vector<int>v1;
	vector<int>v2;
	for(int i=0; i<v.size(); i++) {
		int broj=v[i];
		if(broj<0) broj*=-1;
		if(Gadna(broj) && !DaLiPostoji(v1,v[i])) v1.push_back(v[i]);
		if(Odvratni(broj) && !DaLiPostoji(v2,v[i])) v2.push_back(v[i]);
	}
	if(a==true) return v1;
	return v2;
}



int main ()
{
	int n;
	vector<int>a;
	vector<int>b;
	vector<int>c;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	while(1)  {
		cin>>n;
		if(n==0) break;
		a.push_back(n);
	}
	b=IzdvojiGadne(a,true);
	cout<<"Opaki: ";
	for(int i=0; i<b.size(); i++) {
		cout<<b[i]<<" ";
	}
	c=IzdvojiGadne(a,false);
	cout<<endl<<"Odvratni: ";
	for(int i=0; i<c.size(); i++) {
		cout<<c[i]<<" ";
	}

	return 0;
}