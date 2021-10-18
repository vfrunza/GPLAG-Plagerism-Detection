#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool a) {
	std::vector<int> b;
	std::vector<int> c;
	
	std::vector<int> brojaci{0, 0, 0};
	
	for(int i=0; i<v.size()-1; i++) {
		if(v[i]==0) v.erase(v.begin()+i);
		for(int j=i+1; j<v.size(); j++) {
			if(v[j]==0) v.erase(v.begin()+j);
			if(v[i]==v[j]) {
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	for(int i=0; i<v.size(); i++) {
		long int broj=abs(v[i]);
		while(broj!=0) {
		
			if(broj%3==0) brojaci[0]++;
			else if(broj%3==1) brojaci[1]++;
			else if(broj%3==2) brojaci[2]++;
			broj=broj/3;
			
		}
	
		if(brojaci[0]%2==0 && brojaci[1]%2==0 && brojaci[2]%2==0) b.push_back(v[i]);
		else if((brojaci[0]%2!=0 || brojaci[0]==0) && (brojaci[1]%2!=0 || brojaci[1]==0) && (brojaci[2]%2!=0 || brojaci[2]==0)) c.push_back(v[i]);
	
		brojaci={0,0,0};
		
	}
	if(a==true) return b;
	else if(a==false) return c;
}

int main() {
    
	std::vector<int> a;
	int n;
    std::cout << "Unesite brojeve (0 za prekid unosa): ";
	
	for(;;) {
		std::cin >> n;
		if(n==0) break;
		a.push_back(n);
	} 
	
    std::vector<int> c;
    c=IzdvojiGadne(a, true);
    
    std::cout << "Opaki: ";
    for(int i=0; i<c.size(); i++) {
    	std::cout << c[i] << " ";
    }
    std::cout << std::endl;
    
    std::vector<int> e;
    e=IzdvojiGadne(a, false);
    
    std::cout << "Odvratni: ";
    for(int i=0; i<e.size(); i++) {
    	std::cout << e[i] << " ";
    }
   
    return 0;
}