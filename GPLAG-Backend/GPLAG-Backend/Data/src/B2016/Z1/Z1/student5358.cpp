#include <iostream>
#include <vector>
std::vector<int> IzdvojiGadne(std::vector<int> a,bool t){
	std::vector<int> opaki,odvratni;
	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<a.size();j++){
			if(a[i]==a[j]){
				a.erase(a.begin() + j);
				j--;
			}
		}
	}
	for(int i=0;i<a.size();i++){
		int dap=a[i];
		if(a[i]<0)a[i]*=-1;
		//if(a[i]==1 || a[i]==2)
		int br0(0),br1(0),br2(0);
		if(a[i]==0)br0++;
		for(;;){
			if(a[i]==0)break;
			if(a[i]%3==0)br0++;
			else if(a[i]%3==1)br1++;
			else br2++;
			a[i]/=3;
		}
		if(br0%2==0 && br1%2==0 && br2%2==0) opaki.push_back(dap);
		else if((br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0 || br2==0))odvratni.push_back(dap);
	}
	if(t)return opaki;
	else return odvratni;
}
int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int n;
	std::vector<int>a;
	for(;;){
		std::cin>>n;
		if(n==0)break;
		a.push_back(n);
	}
	std::vector<int>opaki=IzdvojiGadne(a,true);
	std::vector<int>odvratni=IzdvojiGadne(a,false);
	std::cout<<"Opaki: ";
	for(int x : opaki) std::cout<<x<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	for(int x : odvratni)std::cout<<x<<" ";
	return 0;
}