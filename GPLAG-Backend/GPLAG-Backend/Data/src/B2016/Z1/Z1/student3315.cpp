#include <iomanip>
#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne(std::vector<int> p,bool m){
	
	if(p.size()==0 && m==true)
	{return p;}
	
	else if(p.size()==0 && m==false)
	return p;
	
	std::vector<int> opaki;
	std::vector<int> odvratni;
	std::vector<int> vectori;
	
	
	int x;
	int broj;
	for(int i=0;i<p.size();i++){
		x=p[i];
		while(x!=0){
		broj=x%3;
		vectori.push_back(broj);
		x=x/3;
		}
	
	
	int nule=0;
	int jedinice=0;
	int dvice=0;
	for(int i=0;i<vectori.size();i++){
		
		if(vectori[i]==0)
		nule++;
	
		if(vectori[i]==1)
		jedinice++;
		
		if(vectori[i]==2)
		dvice++;
		
	}
	   
	
    if(nule%2==0 && jedinice%2==0 && dvice%2==0){
	opaki.push_back(p[i]);                                 
	}
	else if((nule==0 || nule%2!=0) && (jedinice==0 || jedinice%2!=0) && (dvice==0 || dvice%2!=0)){        
	odvratni.push_back(p[i]);
	}
	    
	    
	    vectori.clear();
	}
	    
	    
	    
	for(int i=0;i<opaki.size();i++){
		for(int j=i+1;j<opaki.size();j++){
			if(opaki[j]==opaki[i]){
				opaki.erase(opaki.begin()+j);
				j--;
				
			}
		}
	}
				
				
	for(int i=0;i<odvratni.size();i++){
		for(int j=i+1;j<odvratni.size();j++){
			if(odvratni[j]==odvratni[i]){
				odvratni.erase(odvratni.begin()+j);
				j--;
			}
		}
	}			

	if(m)
	return opaki;
	else
	return odvratni;
	
}



int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int>p;

	int k;
	do{
		std::cin>>k;
		
		if(k!=0)
		p.push_back(k);
		else break;
		
	} while(1);
	
	std::vector<int> opaki1;
	std::vector<int> odvratni1;
	
	opaki1=(IzdvojiGadne(p,true));
	odvratni1=(IzdvojiGadne(p,false));

    std::cout<<"Opaki: ";
	for(int i=0;i<opaki1.size();i++){
		std::cout<<opaki1[i]<<" ";
	}
	
	std::cout<<std::endl;
	
	std::cout<<"Odvratni: ";
	for(int i=0;i<odvratni1.size();i++){
		std::cout<<odvratni1[i]<<" ";
	}
    std::cout<<std::endl;
    
    
    
    return 0;
}