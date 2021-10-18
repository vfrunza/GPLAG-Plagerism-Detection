
#include<iostream>
#include<vector>
#include <cmath>
//Pretvaranje broja iz dekadnog u terarni
std::vector<int> PretvaranjeUTerarni(int n){
	int i(0);
	std:: vector<int> terarni;
	int a=abs(n);
	do{
		int p;
		p=a%3;
		terarni.push_back(p);
		a/=3;
		i++;
	} while(a!=0);
	return terarni;}
//odredjivanje da li je broj odvratan ili opak, ako je opak vraća 1, ako je odvratan vraća 0, a ako nije ni opak ni odvratan vraća 3, što nam ustvari i ne treba
int tip_broja(std::vector<int>a, int n){
	int i,br0(0),br1(0),br2(0);
	a=PretvaranjeUTerarni(abs(n));
	for(i=0;i<a.size();i++){
		if(a[i]==0) br0++;
		if(a[i]==1) br1++;
		if(a[i]==2) br2++;
  }
  if(br0%2==0 && br1%2==0 && br2%2==0) return 1;
  if((br1%2!=0 || br1==0)  && (br0%2!=0 || br0==0) && (br2%2!=0 || br2==0)) return 0;
  else return 3;
  
}
//provjerava da li se broj nalazi u vektoru
bool NeNalaziSe(std::vector<int>x,int n){
	int i;
	for( i=0;i<x.size();i++){
		if(x[i]==n) return false;
	}
	return true;
}
std::vector<int> IzdvojiGadne(std::vector<int> a, bool tip){
	std::vector<int> gadni;
	int i;
	if(tip==true){
		for(i=0;i<a.size();i++){
			if(tip_broja(PretvaranjeUTerarni(a[i]),a[i])==1 && NeNalaziSe(gadni,(PretvaranjeUTerarni(a[i]),a[i]))==true) gadni.push_back(a[i]);
		}
	}
	if(tip==false){
		for(i=0;i<a.size();i++){
			if(tip_broja(PretvaranjeUTerarni(a[i]),a[i])==0 && NeNalaziSe(gadni,(PretvaranjeUTerarni(a[i]),a[i]))==true) gadni.push_back(a[i]);
		}
	}
	return gadni;
}

int main ()
{ int n,i;
std::vector<int>a;

std::cout<<"Unesite brojeve (0 za prekid unosa): ";
do{ std::cin>>n;
if(n!=0) a.push_back(n);}
while(n!=0);
std::cout<<"Opaki: ";
for(i=0;i<IzdvojiGadne(a,true).size();i++){
	std::cout<<IzdvojiGadne(a,true)[i]<<" ";
}
std::cout<<"\nOdvratni: ";
for(i=0;i<IzdvojiGadne(a,false).size();i++){ 	std::cout<<IzdvojiGadne(a,false)[i]<<" ";
}
	
	return 0;
}