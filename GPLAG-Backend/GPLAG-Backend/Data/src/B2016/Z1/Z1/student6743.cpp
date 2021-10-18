#include<iostream>
#include<vector>

std::vector<int> IzdvojiGadne (std::vector<int> vec, bool akigol){
	
 std::vector<int> opaki, odvratni,V,v;
 
 for(int x: vec){
 	
 	if(v.size()==0){
 		 v.push_back(x);
         continue;
 	}
 	
 	 bool T(true);
 	for(int y: v){
 		if(x==y) { T=false; break; }
 	}
 	if(T==false) continue;
 	v.push_back(x);
 }
   	



	for(int x: v){
		
		int broj(x);
        if(broj<0) broj*=-1;
	long int ternarnibroj(0);
	long int cifra,i(1);
		
		while (broj!=0) {
			
			cifra=(broj%3)*i;
			ternarnibroj+=cifra;
			i*=10;
			broj/=3;
			
		}
		
		int kaunter0(0), kaunter1(0), kaunter2(0);
		
		while(ternarnibroj!=0){
			
			if(ternarnibroj%10==0) kaunter0++;
			
			else if(ternarnibroj%10==1) kaunter1++;
			
			else if(ternarnibroj%10==2) kaunter2++;
			
			ternarnibroj/=10;
			
		}
		
		if(kaunter0%2==0 && kaunter1%2==0 && kaunter2%2==0) opaki.push_back(x);
		
		if((kaunter0%2!=0 || kaunter0==0) && (kaunter1%2!=0 || kaunter1==0) && (kaunter2%2!=0 || kaunter2==0)) 
		
		odvratni.push_back(x);
		
		
		
	}
	
	if(akigol==true) V=opaki;
		 else V=odvratni;
		 
		 return V;
      }



int main ()
{

  std::vector<int> v,v1,v2;
//v={333,715}	;

	int y;
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	
	do{
		std::cin>>y;
		if(y==0) break;
		v.push_back(y);

	}while(1);
	std::cout<<"Opaki: ";

	v1=IzdvojiGadne(v,true);
	
	for(int x: v1) std::cout<<x<<" ";
	
	v2=IzdvojiGadne(v,false);
	
	std::cout<<std::endl<<"Odvratni: ";
	
	for(int x: v2) std::cout<<x<<" ";
	
	return 0;
}