/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

int  provjeri (int n){
	int br0{0}, br1{0}, br2{0};
	if (n>=0){
	do {
		if(n%3==0)br0++;
		if(n%3==1)br1++;
		if(n%3==2)br2++;
		n=n/3;
	}while (n!=0);
	} else {
	do {
		if(-n%3==0)br0++;
		if(-n%3==1)br1++;
		if(-n%3==2)br2++;
		n=n/3;
	}while (n!=0);
	}

	if ((br0==0 || br0%2==0) && (br1==0 || br1%2==0) && (br2==0 || br2%2==0)){
		return 0;
	} else if ((br0==0 || br0%2!=0) && (br1==0 || br1%2!=0) && (br2==0 || br2%2!=0)){
		return 1;
	} else {
		return 2;
	}
   
}

  std::vector<int> IzdvojiGadne (std::vector<int> v, bool n){
	std::vector<int> v_gadni;
	
	for(int i=0; i<int(v.size()); i++){
		if (n){
			if (provjeri(v[i])==0) v_gadni.push_back(v[i]);
		} else if (!n){
			if (provjeri(v[i])==1) v_gadni.push_back(v[i]);
		}
	}
	for (int i=0; i<int(v_gadni.size()); i++){
		for (int j=i+1; j<int(v_gadni.size()); j++){
			if (v_gadni[i]==v_gadni[j]){
				v_gadni.erase(v_gadni.begin()+j);
				j--;
			}
		}
	}
	return v_gadni;
 }

int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	int i{0};
	do {
		std::cin>>i;
		if (i!=0) v.push_back(i);
	} while (i!=0);
	
	std::cout<<"Opaki: ";
	for (int i: IzdvojiGadne(v,true)) std::cout<<i<<" ";
	std::cout <<std::endl;
	std::cout<<"Odvratni: ";
	for (int i: IzdvojiGadne(v,false)) std::cout<<i<<" ";
	
	
	return 0;
}