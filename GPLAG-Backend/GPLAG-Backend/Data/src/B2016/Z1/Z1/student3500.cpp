#include <iostream>
#include <vector>
typedef std::vector<int> vektor;

bool Opak(int t){   
	if(t<0) t*=-1;
	int b0(0), b1(0), b2(0);
	do{                            
		
		if(t%3==0) b0++;
		else if(t%3==1) b1++;
		else if(t%3==2) b2++;
		t/=3;
	}while(t!=0);
	if((b0%2==0)&&(b1%2==0)&&(b2%2==0)) return true;
	else return false;
}

bool Odvratan(int t){
	if(t<0) t*=-1;
	int b0(0), b1(0), b2(0);
	do{
		if(t%3==0) b0++;
		else if(t%3==1) b1++;
		else if(t%3==2) b2++;
		t/=3;
	}while(t!=0);
	if(((b0%2!=0)||(b0==0))&&((b1%2!=0)||(b1==0))&&((b2%2!=0)||(b2==0))) return true;
	else return false;
}

vektor IzdvojiGadne(vektor v, bool T){                                             
	vektor V;
	V=v;
	if(T){
		for(int i(0);i<V.size();i++){
			if(!Opak(V[i])) { 
				V.erase(V.begin()+i);
				i--;
			}
	   }
	}
	else if(!T){
		for(int i(0);i<V.size();i++){
			if(!Odvratan(V[i])) {
				V.erase(V.begin()+i);
				i--;
			}
	   }
	}
	if(V.size()!=0){
		for(int i(0);i<V.size()-1;i++){                 
		   for(int j(i+1);j<V.size();j++){
			 if(V[j]==V[i]){
				V.erase(V.begin()+j);
				j--;
			   }
		   }   
		}
	}
	return V;	
}


int main ()
{
	vektor v;
	bool T, nT;
	T=true;
	nT=false;
	int n;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";

	do{
		std::cin>>n;
		if(n!=0) v.push_back(n);
		
	}while(n!=0);
	std::cout<<"Opaki: ";
	vektor Op;
	Op=IzdvojiGadne(v,T);
	for(int i(0);i<Op.size();i++){
		std::cout<<Op[i]<<" ";
	}
	std::cout<<std::endl<<"Odvratni: ";
	vektor Od;
	Od=IzdvojiGadne(v,nT);
	for(int i(0);i<Od.size();i++){
		std::cout<<Od[i]<<" ";
	}
	return 0;
}