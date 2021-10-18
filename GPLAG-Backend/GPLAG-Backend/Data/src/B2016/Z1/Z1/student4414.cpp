/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>



/*long long*/ int PretvoriUTernarni(int n) {
	/*long long*/ int d=1, c;
	/*long long*/ int broj(0);
	if(n<0) n=fabs(n);
	while(n!=0) {
		c=n%3;
		broj+=d*c;
		
		n/=3;
		d*=10;
	}
	
	return broj;
}

std::vector</*long long */int> IzdvojiGadne(std::vector</*long long */int> v1, bool vrijednost) {
	std::vector</*long long */int> v2;
	
	if(v1.size()==0) {
		v1.resize(0);
		return v1;
	}
	

	if(vrijednost) {
		for(int i=0; i<v1.size(); i++) {
			long long int a=0, b=0, c=0;
				long long int pom=PretvoriUTernarni(v1[i]);
					while(pom!=0) {
						if(pom%10==0) a++;
						if(pom%10==1) b++;
						if(pom%10==2) c++;
						pom/=10;
					}
					if(v1[i]==0) continue;
				
				
				if(((a%2==0) || (a==0)) && ((b%2==0) || (b==0)) && ((c%2==0) || (c==0))) v2.push_back(v1[i]);
				else continue;
					
					
			
		}
		
		for(int i=0; i<v2.size(); i++) {
			for(int j=i+1; j<v2.size(); j++) {
				if(v2[i]==v2[j]) v2.erase(v2.begin()+j);
			}
		}
		
		
				return v2;
}

	else {
		for(int i=0; i<v1.size(); i++) {
			/*long long */int a=0, b=0, c=0;
			/*long long */int pom=PretvoriUTernarni(v1[i]);
			while(pom!=0) {
				if(pom%10==0) a++;
				if(pom%10==1) b++;
				if(pom%10==2) c++;
				pom/=10;
			}
			if(v1[i]==0) continue;
			if(((a%2==1) || (a==0)) && ((b%2==1) || (b==0)) && ((c%2==1) || (c==0))) v2.push_back(v1[i]);
			else continue;
		}
		
		for(int i=0; i<v2.size(); i++) {
			for(int j=i+1; j<v2.size(); j++ ) {
				if(v2[i]==v2[j]) v2.erase(v2.begin()+j);
			}
		}
		
		return v2;
	}

}

int main ()
{
	std::vector</*long long */int> v1;
	std::vector</*long long */int> v2;
	std::vector</*long long */int> v3;
	/*long long */int n;
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	
	for(;;) {
		std::cin>>n;
		if(n==0) break;
		v1.push_back(n);
	}
	
	v2=IzdvojiGadne(v1,true);
	
	
	for(int i=0; i<v2.size(); i++) {
		for(int j=i+1; j<v2.size(); j++) {
			if(v2[i]==v2[j]) v2.erase(v2.begin()+j);
		}
	}
	
	std::cout<<"Opaki: ";
	for(int i=0; i<v2.size(); i++) {
		std::cout<<v2[i]<<" ";	
		}
		
		v3=IzdvojiGadne(v1,false);
	
	
	for(int i=0; i<int(v3.size()); i++) {
		for(int j=i+1; j<v3.size(); j++) {
			if(v3[i]==v3[j]) v3.erase(v3.begin()+j);
		}
	}
	

	 
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i=0; i<v3.size(); i++) {
		std::cout<<v3[i]<<" ";	
	}
	
	return 0;
}