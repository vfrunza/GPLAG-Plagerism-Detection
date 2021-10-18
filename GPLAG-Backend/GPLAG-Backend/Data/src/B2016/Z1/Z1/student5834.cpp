/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>

std::vector<int> IzdvojiGadne(std::vector<int> v,bool a){
	int br0,br1,br2,r;
	
	std::vector<int> rez;
	if(v.size()!=0){
	for(int i=0;i<v.size();i++){
		r=v[i];
	//	n=abs(r);
		br0=0,br1=0,br2=0;
		while(r!=0){
			int c=abs(r%3);
			if(c==0) br0++;
			if(c==1) br1++;
			if(c==2) br2++;
			r/=3;
		}
	
	if(a==true && br0%2==0 && br1%2==0 && br2%2==0 && v[i]!=0) rez.push_back(v[i]);
	if((br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0 || br2==0) && a==false ) rez.push_back(v[i]);
	
	}
	if(rez.size()!=0){
	for(int i=0;i<rez.size()-1;i++){
		for(int j=i+1;j<rez.size();j++)
			if(rez[i]==rez[j]){
				rez.erase(rez.begin()+j);
				j--;
			}

	}
		
	}
	}
	return rez;
}
int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int>vektor ;
	int n;
	for(;;){
	std::cin >> n;
	if(n==0) break;
	vektor.push_back(n);
	}
	std::cout << "Opaki: " ;
	std::vector<int> rez=IzdvojiGadne(vektor,1) ;
	
	for(int i=0;i<rez.size();i++){
		std::cout << rez[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	std::vector<int> rez1=IzdvojiGadne(vektor,0) ;
	for(int i=0;i<rez1.size();i++){
		std::cout << rez1[i] << " ";
	}
	
	
	return 0;
}