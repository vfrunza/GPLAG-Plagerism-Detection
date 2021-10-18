/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int> Procisti (std::vector<int> v){
	for(int i=0; i<(int)v.size(); i++)
		for(int j=i+1; j<(int)v.size(); j++)
			if(v[i]==v[j]){
				int p=j;
				for(int k=j+1; k<(int)v.size(); k++){
					v[p]=v[k];
					p++;
				}
				v.resize(v.size()-1);
				j--;
			}
	return v;
}
//Treba vidjeti za manje od 0
int PromijeniZApis(int n){
	if(n<0)
		n*=-1;
	std::vector<int> v, t;
	t.resize(3);
	while(n!=0){
		v.push_back(n%3);
		n/=3;
	}
	for(int i=0; i<(int)v.size(); i++)
		t[v[i]%10]++;

	bool a{1};
	for(int i=0; i<3; i++)
		if(t[i]>0)
			if(t[i]%2!=0)
				a=0;
	if(a)
		return 1; //ovo je da su svi parni - OPAK broj
	else{
		a=1;
		for(int i=0;i<3;i++)
			if(t[i]>0)
				if(t[i]%2==0)
					a=0;
		if(a)
			return 0; //svi neparni - Odvratan broj
		else

			return 2; //nista nije
	}
}

std::vector<int> IzdvojiGadne(std::vector<int> v,bool p){
	std::vector<int> vrati;
	if(p) // Opaki
		for(int i=0; i<(int)v.size(); i++){
//			std::cout<<"\n"<<PromijeniZApis(v[i]);
			if(v[i]==0) // ************************** STAVIO SAM OVO RADI 2 AT********************//
				continue;
			if(PromijeniZApis(v[i])==1)
				vrati.push_back(v[i]);
		}
	else //Odvratni
		for(int i=0; i<(int)v.size(); i++){
			if(v[i]==0)
				continue;
			if(PromijeniZApis(v[i])==0)
				vrati.push_back(v[i]);
		}
	return Procisti(vrati);
}

int main (){
	std::vector<int> v,a,b;
	v.push_back(0);
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	while(1){
		int n;
		std::cin>>n;
		if(n==0)
			break;
		v.push_back(n);
	}
	a=IzdvojiGadne(v,1);
	std::cout<<"Opaki: ";
	for(int i=0; i<(int)a.size(); i++)
		std::cout<<a[i]<<" ";
	b=IzdvojiGadne(v,0);
	std::cout<<"\nOdvratni: ";
	for(int i=0; i<(int)b.size(); i++)
		std::cout<<b[i]<<" ";
	return 0;
}
