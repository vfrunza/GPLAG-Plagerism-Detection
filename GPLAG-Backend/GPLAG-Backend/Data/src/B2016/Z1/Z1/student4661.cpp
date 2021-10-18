/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<int> vector;

vector IzdvojiGadne(vector v, bool T){
	vector v1;
	int brojac1(0),brojac2(0),brojac3(0);
	if(T==true){
	for(int i(0); i<v.size(); i++){
		brojac1=0;
		brojac2=0;
		brojac3=0;
	int n,temp;
		n=v[i];
		if(n<0) n=n*(-1);
		
	do{
		temp=n%3;
		if(temp==2)	brojac1++;
		else if(temp==1) brojac2++;
		else brojac3++;
		
		n=n/3;
		
	}while(n!=0);
	

	if((brojac1%2==0 && brojac2%2==0 && brojac3%2==0) || (brojac1%2==0 && brojac2%2==0 && brojac3==0) || (brojac1==0 && brojac2%2==0 && brojac3%2==0) || (brojac1%2==0 && brojac2==0 && brojac3%2==0) || (brojac1%2==0 && brojac2==0 && brojac3==0) || (brojac1==0 && brojac2%2==0 && brojac2==0) || (brojac1==0 && brojac2==0 && brojac3%2==0)){
		v1.push_back(v[i]);
	}
	 
   }
      for(int k=0; k<v1.size(); k++){
		for(int l=k+1; l<v1.size(); l++){
		if(v1[k]==v1[l]){ 
		v1.erase(v1.begin()+l);
		k--;
		break;}
	  }
      }
	return v1;
	}
	
	else {
	for(int i(0); i<v.size(); i++){
	int n,temp;
		n=v[i];
		if(n<0) n=n*(-1);
		brojac1=0;
		brojac2=0;
		brojac3=0;
	do{
		temp=n%3;
		if(temp==2)	brojac1++;
		else if(temp==1) brojac2++;
		else brojac3++;
		
		n=n/3;
		
	}while(n!=0);
	
	if((brojac1%2!=0 && brojac2%2!=0 && brojac3%2!=0) || (brojac1%2!=0 && brojac2%2!=0 && brojac3==0) || (brojac1==0 && brojac2%2!=0 && brojac3%2!=0) || (brojac1%2!=0 && brojac2==0 && brojac3%2!=0) || (brojac1%2!=0 && brojac2==0 && brojac3==0) || (brojac1==0 && brojac2%2!=0 && brojac2==0) || (brojac1==0 && brojac2==0 && brojac3%2!=0))
	v1.push_back(v[i]);
	} 
	for(int k=0; k<v1.size(); k++){
		for(int l=k+1; l<v1.size(); l++){
		if(v1[k]==v1[l]){
			
		 v1.erase(v1.begin()+l);
		k--;
		break;}
	}
	}
	return v1;
	}
}
int main ()
{
	vector v;
	int a;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(int i=0; i<10000; i++){
		std::cin>>a;
		if(a==0) break;
		v.push_back(a);
	}
	vector v1(IzdvojiGadne(v,true)), v2(IzdvojiGadne(v,false));
	
	
	std::cout<<"Opaki: ";
	for(int i: v1){
		std::cout<<i<<" ";
	} std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i: v2){
		std::cout<<i<<" ";
	}

	return 0;
}