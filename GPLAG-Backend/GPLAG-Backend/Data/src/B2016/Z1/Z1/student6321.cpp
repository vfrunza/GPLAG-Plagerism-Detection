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
enum gadni {odvratni,opaki,nista};

gadni provjera(int k){
	
	std::vector<int> p(3,0);

	
	
	
	unsigned int n(std::abs(k));
	
	for(;;)
	{
	 	int a;
		a=n%3;
		n=n/3;
	
		
		for(int i=0;i<=2;i++){
			if(a==i) p[i]++;
		}
		
		
		
		if(n==0) break;

		
	}


	gadni m;
	
	if(p[0]%2==0 && p[1]%2==0 && p[2]%2==0){
		m=opaki;
	}else
	{
		for(int i=0;i<p.size();i++){
			if(p[i]==0) p[i]++;
			if(p[i]%2==0) {
				m=nista;
			}
	
		}
		
		if(p[0]%2!=0 && p[1]%2!=0 && p[2]%2!=0){
			m=odvratni;
		}
	}
	return m;
	
}

std::vector<int> IzdvojiGadne(std::vector<int> vec, bool tf){
	
std::vector<int> x;
	for(int i=0;i<=int(vec.size())-1;i++){
		
		gadni d(provjera(vec[i]));
		if(d==2) continue;
		if(tf==d){
			x.push_back(vec[i]);
		}
		
		if(i==int(vec.size())-1) break;
		
	}
	
	if(x.size()!=0){
	for(int i=0;i<=int(x.size())-2;i++){
		
		for(int j=i+1;j<=int(x.size())-1;j++){
			
			if(x[i]==x[j]){
				x.erase(x.begin()+j);
				j--;
			}
		
		
		if(j==int(x.size())-1) break;
		}

		if(i==int(x.size())-2) break;
	}
}


	
	
	return x;
	
}


int main ()

{
	std::vector<int> test;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		int n;
		std::cin>>n;
		
		if(n==0) break;
		test.push_back(n);
	
		
	}
	std::cout<<"Opaki: ";
	std::vector<int> rjesenje1(IzdvojiGadne(test,true));
	for(int i=0;i<rjesenje1.size();i++){
		std::cout<<rjesenje1[i]<<" "
		;
	}
	
	std::cout<<std::endl<<"Odvratni: ";
	std::vector<int> rjesenje2(IzdvojiGadne(test,false));
	for(int i=0;i<rjesenje2.size();i++){
		std::cout<<rjesenje2[i]<<" ";
	}
	



	

	return 0;
}