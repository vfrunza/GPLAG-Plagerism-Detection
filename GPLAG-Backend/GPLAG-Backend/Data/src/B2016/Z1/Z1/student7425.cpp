#include <iostream>
#include <vector>

using namespace std;

vector<int> IzdvojiGadne(vector<int> v, bool a) {
	vector<int> v1;
	for(int i=0;i<v.size();i++) {
		for(int j=i+1;j<v.size();j++) {
			if(v[i]==v[j]) {
				for(int k=j;k<v.size()-1;k++)
					v[k]=v[k+1];
				j--;
				v.resize(v.size()-1);
			}
		}
	}
	for(int i=0;i<v.size();i++) {
		int b=v[i];
		if(b<0) b=-b;
		int br0=0, br1=0, br2=0;
		while(b!=0) {
			int c=b%3;
			if(c==0) br0++;
			else if(c==1) br1++;
			else br2++;
			b/=3;
		}
		if(a==true && br0%2==0 && br1%2==0 && br2%2==0) v1.push_back(v[i]);
		if(a==false &&((br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0 || br2==0))) v1.push_back(v[i]);
	}
	return v1;
}

int main ()
{
	vector<int> v;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;) {
		int a;
		cin>>a;
		if(!cin) {
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		if(a==0) break;
		else v.push_back(a);
	}
	vector<int> v1=IzdvojiGadne(v, true);
	cout<<"Opaki: ";
	for(int i=0;i<v1.size();i++)
		cout<<v1[i]<<" ";
	cout<<endl<<"Odvratni: ";
	vector<int> v2=IzdvojiGadne(v, false);
	for(int i=0;i<v2.size();i++)
		cout<<v2[i]<<" ";
	return 0;
}