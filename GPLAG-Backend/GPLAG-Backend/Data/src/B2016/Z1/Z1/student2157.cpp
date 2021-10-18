#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne(std::vector<int> A, bool T){
	
	std::vector<int> Op;
	std::vector<int> Og;
	int suma0(0), suma1(0), suma2(0);
	for(int x: A){
		suma0=0;
		suma1=0;
		suma2=0;
		int c=x;
	while(x!=0){
		if(abs(x)%3==0)				suma0++;
		else if(abs(x)%3==1)		suma1++;
		else if(abs(x)%3==2)		suma2++;
		x/=3;
	}
	if( (suma0==0 || suma0%2==0 ) && ( suma1==0 || suma1%2==0) && (suma2==0 || suma2%2==0) ) Op.push_back(c);
	else if((suma0==0 || suma0%2!=0) && (suma1==0 || suma1%2!=0 ) && ( suma2==0 || suma2%2!=0 ) ) Og.push_back(c);
	
}
 for(int i =0; i<Op.size()-1; i++){
      for(int j=i+1; j< Op.size(); j++){
         if(Op.at(i)==Op.at(j)){
            Op.erase(Op.begin() + j);
            j--;
         }
      }
   }
   
    for(int i =0; i<Og.size()-1; i++){
      for(int j=i+1; j< Og.size(); j++){
         if(Og.at(i)==Og.at(j)){
            Og.erase(Og.begin() + j);
            j--;
         }
      }
   }
if(T) return Op;
else return Og;
}
int main ()
{
	std::vector<int> A;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int a(1);
	while(a!=0){
		std::cin>>a;
		if(a!=0)
		A.push_back(a);
	}
	bool T=true;
	std::vector<int> Op(IzdvojiGadne(A, T));
	 T=false;
	std::vector<int> Og(IzdvojiGadne(A, T));
	std::cout<<"Opaki: ";
	for(int i=0; i<Op.size(); i++){
		std::cout<<Op[i]<<" ";
	}
	std::cout<<"\nOdvratni: ";
	for(int i=0; i<Og.size(); i++){
		std::cout<<Og[i]<<" ";
	}
	return 0;
}