/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	121 15451 15 179 777
*/
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
std::vector<int> IzdvojiGadne(std::vector<int>a, bool b){
		std::deque<int> dek;
		int cifra;
		
		for(int i=0; i<a.size(); i++){
			for(int j=i+1; j<a.size(); j++){
				if(a[i]==a[j]){
					while(j<a.size()-1){
						a[j]=a[j+1];j++;
					} 
					a.resize(a.size()-1);i--;}
			}
		} 
		
		for(int i=0; i<a.size(); i++){
			dek.clear();
			long int broj=a[i];
			if(broj<0)broj*=-1; 
			while(broj>0){
				cifra=broj%3;
				broj/=3;
				dek.push_front(cifra);
			}
			if(dek.size()==0)dek.push_front(a[i]);
			int brojac=0;
			for(int j=0; j<dek.size(); j++){
				for(int z=0; z<dek.size(); z++){
					if(dek[j]==dek[z])brojac++;
				}
				if(b==true && brojac%2!=0){
					int m=i;
					while(m<a.size()-1){a[m]=a[m+1];m++;}
					a.resize(a.size()-1);
					i--;
					break;
				}
				if(b==false && brojac%2==0){
					int m=i;
					while(m<a.size()-1){a[m]=a[m+1];m++;}
					a.resize(a.size()-1);
					i--;
					break;
				}
				brojac=0;
			}
		}
		
	return a;
}
int main ()
{
	std::vector<int> a;
	int b;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>b;
		if(b!=0)a.push_back(b);
	}while(b!=0);
	std::vector<int> v=IzdvojiGadne(a,true);
	std::cout<<"Opaki: ";
	for(int i=0; i<v.size(); i++)std::cout<<v[i]<<" ";
	std::vector<int> c=IzdvojiGadne(a,false);
	std::cout<<std::endl<<"Odvratni: ";
	for(int i=0; i<c.size(); i++)std::cout<<c[i]<<" ";
	return 0;
}