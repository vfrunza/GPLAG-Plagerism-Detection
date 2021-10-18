#include<iostream> 
#include<vector>
#include <cmath>

std::vector<int> IzdvojiGadne(std::vector<int>v,bool a){
	
	std::vector<int>v1;
	
	if(a==true){
	    for(int i=0;i<v.size();i++){
	    	
	    	int broj=v[i];
	    	int a(0);
	    	std::vector<int>p;
	    	
	    	for(;;){
	    		a=std::abs(broj%3);
	    		p.push_back(a);
	    		broj/=3;
	    		if(broj==0) break;
	    	}
	    	//	std::vector<int>opaki;
	    		int br0(0);
	    		int br1(0);
	    		int br2(0);
	    	for(int j=0;j<p.size();j++){
	    	//	int br0(0);
	    	//	int br1(0);
	    	//	int br2(0);
	    		
	    		
	    		 if(p[j]==0) br0++; 
	    		 else if(p[j]==1) br1++;
	    		 else br2++;
	    		 
	    		 
	    		
	    	}
	    	if(br0%2==0 && br1%2==0 && br2%2==0) {
	    		bool sadrzan=false;
	    		for(int k=0;k<v1.size();k++){
	    			if(v1[k]==v[i]){
	    				sadrzan=true;
	    				break;
	    			}
	    		}
	    		if(sadrzan==false){
	    				v1.push_back(v[i]);
	    			}
	    	}
	    }
	    
	}
	else{
		
		for(int i=0;i<v.size();i++){
			
			int broj=v[i];
			int a(0);
			std::vector<int>l;
			
			for(;;){
				
				a=std::abs(broj%3);
				l.push_back(a);
				broj/=3;
				if(broj==0) break;
			}
			
			//std::vector<int>odvratni;
			int jedan(0);
				int dva(0);
				int nula(0);
			for(int j=0;j<l.size();j++){
			//	int jedan(0);
			//	int dva(0);
			//	int nula(0);
				
				if(l[j]==0) nula++;
				else if(l[j]==1) jedan++;
				else dva++;
				
			}
			std::vector<int>brojevi;
			bool odvratan;
			odvratan=true;
		
			brojevi.push_back(nula);
			brojevi.push_back(jedan);
			brojevi.push_back(dva);
			
			for(int k=0;k<brojevi.size();k++){
				if(brojevi[k]==0) continue;
				if(brojevi[k]%2==0) odvratan=false;
				
			}
			
			
			if(odvratan==true){
					bool sadrzan=false;
	    		for(int k=0;k<v1.size();k++){
	    			if(v1[k]==v[i]){
	    				sadrzan=true;
	    				break;
	    			}
	    		}
	    		if(sadrzan==false){
	    				v1.push_back(v[i]);
	    			}
				}
			
		
		}
	
	}
	
	return v1;
}


int main ()

{
	
	std::vector<int>vektor;
	int x;
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::cin>>x;
	while(x!=0){
		vektor.push_back(x);
		std::cin>>x;
	}
	
	std::vector<int> a;
	a=IzdvojiGadne(vektor,true);
	
	std::vector<int> b;
	b=IzdvojiGadne(vektor,false);
	
	std::cout<<"Opaki: ";
	for(int i=0;i<a.size();i++){
		std::cout<<a[i]<<" ";
	}
	std::cout<<std::endl;
	
	std::cout<<"Odvratni: ";
	for(int i=0;i<b.size();i++){
		std::cout<<b[i]<<" ";
	}
	
	return 0;
}