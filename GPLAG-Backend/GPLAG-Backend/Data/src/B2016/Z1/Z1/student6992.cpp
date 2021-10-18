/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
std::vector<int> IzdvojiGadne(std::vector<int> v, bool tvrdnja){
	std::vector<int> v1,v2,vpomocni;
	bool p2;
	for(int i=0;i<v.size();i++){
		p2=true;
		for(int j=0;j<vpomocni.size();j++){
			if(v[i]==vpomocni[j]){
				p2=false;
				break;
			}
		}
		if(p2) 
		vpomocni.push_back(v[i]);
	}
	int a0(0),a1(0),a2(0);
	int helpy(0), helpy2;
	for(int i=0;i<vpomocni.size();i++){
		a0=a1=a2=0;
		helpy=0;
		helpy2=vpomocni[i];
		if(helpy2 < 0) helpy2 = -helpy2;
		while(helpy2!=0){
			helpy=helpy2%3;
			helpy2/=3;
			if(helpy==0) a0++;
			else if(helpy==1) a1++;
			else a2++;
		}
		if(a0%2==0 && a1%2==0 && a2%2==0)
		v1.push_back(vpomocni[i]);
		else if((a0==0 || a0%2 == 1) && (a1==0 || a1%2==1) && (a2==0||a2%2==1))
		v2.push_back(vpomocni[i]);
	}
	vpomocni.resize(0);
	if(tvrdnja) return v1;
	else 
	return v2;
}

int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int k;
	std::vector<int> v1;
	while(std::cin>>k)
	{
		if(k==0) break;
		v1.push_back(k);
	}
	std::vector<int> v2,v3;
	v2=IzdvojiGadne(v1,true);
	v3=IzdvojiGadne(v1,false);
	std::cout<<"Opaki: ";
	for(int i=0;i<v2.size();i++)
	std::cout<<v2[i]<<" ";
	std::cout<<"\nOdvratni: ";
	for(int i=0;i<v3.size();i++)
	std::cout<<v3[i]<<" ";
	return 0;
}