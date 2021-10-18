/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

    std::vector<int>IzdvojiGadne (std::vector<int> v, bool opaki) {
    
    std::vector<int>kopija(v);
    std::vector<int>rezultat;
    bool ima(0);
    
    for (int i=0; i<v.size(); i++) {
    	std::vector<bool> A;
    	if (opaki==true) {
    		std::vector<int>pomocni;
    	
    		do {
    			pomocni.push_back( v[i]%3);
    			v[i]=v[i]/3;
    		} while (v[i]!=0);
    		
    		for (int m=0; m<pomocni.size(); m++) {
    			A.push_back(false);
    		}
    		bool opakBroj (true);
    		for (int j=0; j<pomocni.size(); j++) {
    			if (A[j]==false) {
    				int brojac=1;
    			A[j]=true;
    			
    		
    			for (int k=j+1; k<pomocni.size(); k++) {
    				if (A[k]==false && pomocni[j]==pomocni[k]) {
    					brojac++;
    					A[k]=true;
    				}
    			}
    			if (brojac%2!=0) {
    				opakBroj=false;
    				break;
    			}
    		}
    	}	
    		if (opakBroj==true) {
    			ima=0;
    			for (int n=0; n<rezultat.size(); n++) {
    				if (kopija[i]==rezultat[n])
    				ima=1;
    			}
    			if (ima==0)
    		rezultat.push_back(kopija[i]);
    		}
    			}
    		else {
    		
    		
    			std::vector<int>pomocni;
    	
    		do {
    			pomocni.push_back( v[i]%3);
    			v[i]=v[i]/3;
    		} while (v[i]!=0);
    		
    		for (int m=0; m<pomocni.size(); m++) {
    			A.push_back(false);
    		}
    		bool odvratanBroj (true);
    		for (int j=0; j<pomocni.size(); j++) {
    			if (A[j]==false) {
    				int brojac=1;
    			A[j]=true;
    			
    		
    			for (int k=j+1; k<pomocni.size(); k++) {
    				if (A[k]==false && pomocni[j]==pomocni[k]) {
    					brojac++;
    					A[k]=true;
    				}
    			}
    			if (brojac%2==0 && brojac!=0) {
    				odvratanBroj=false;
    				break;
    			}
    		}
    	}	
    		if (odvratanBroj==true) {
    			ima=0;
    			for (int n=0; n<rezultat.size(); n++) {
    				if (kopija[i]==rezultat[n])
    				ima=1;
    			}
    			if (ima==0)
    		rezultat.push_back(kopija[i]);
    		}
    			}
    }
    	return rezultat;
    }


int main () {
	
	std::vector<int> v;
	int n;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for (;;) {
      std::cin>>n;
      if (n==0) break;
	v.push_back(n);
	}
	
	std::vector<int>v1(IzdvojiGadne(v, true));
	std::cout<<"Opaki: ";
	for (int i=0; i<v1.size(); i++) 
		
		std::cout<<v1[i]<<" ";
	
	std::vector<int>v2(IzdvojiGadne(v, false));
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for (int i=0; i<v2.size(); i++) 
		
		std::cout<<v2[i]<<" ";

	return 0;
}



