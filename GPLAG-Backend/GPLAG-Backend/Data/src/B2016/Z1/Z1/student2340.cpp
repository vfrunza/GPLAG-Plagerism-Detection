/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

std::vector<int>Cifre (int n){
	std::vector<int> h;
	int x;
	do{
		x=n%3;
		h.push_back(x);
		n/=3;
	} while(n!=0);
	
	return h;
}



bool Ponavljanje_cifara(std::vector<int> h){
	
	int brojacnula(0), brojacjedinica(0), brojacdvica(0);
	
	for(int i=0; i<h.size(); i++){
		if(h[i]==0) brojacnula++;
		if((h[i]==1) || (h[i]==-1)) brojacjedinica++;
		if((h[i]==2) || (h[i]==-2)) brojacdvica++;
		}

	if((brojacdvica%2==0 && brojacjedinica%2==0 && brojacnula%2==0) || (brojacnula==0 && brojacdvica%2!=0 && brojacjedinica%2!=0) 
	   ||(brojacdvica==0 && brojacjedinica%2!=0 && brojacnula%2!=0) || (brojacjedinica==0 && brojacdvica%2!=0 && brojacnula%2!=0) 
	   || (brojacdvica%2!=0 && brojacjedinica%2!=0 && brojacnula%2!=0)|| (brojacjedinica%2!=0 && brojacdvica==0 && brojacnula==0)
	   || (brojacdvica%2!=0 && brojacjedinica==0 && brojacnula==0) || (brojacnula%2!=0 && brojacdvica==0 && brojacjedinica==0)) return true;
	
	
	return false;
}

bool Ponavljanje_cifara2(std::vector<int> h){
	int brojacnula(0),brojacjedinica(0),brojacdvica(0);
	for(int i=0; i<h.size(); i++){
		if(h[i]==0) brojacnula++;
		if((h[i]==1) || (h[i]==-1)) brojacjedinica++;
		if((h[i]==2) || (h[i]==-2)) brojacdvica++;
		}

	if(brojacdvica%2==0 && brojacjedinica%2==0 && brojacnula%2==0) return true;
	else  return false;
}

std::vector<int> jedinstveni(std::vector<int> v){
	std::vector<int> novi; int i(0);int j(0);
	for(i=0; i<v.size();i++){
		for(j=0; j<i; j++){
			if(v[i]==v[j])
			break;
		}
		if(i==j) {novi.push_back(v[i]);
	  }
	}
return novi;
}

std::vector<int> IzdvojiGadne(std::vector<int> v,bool istinitost){
	v=jedinstveni(v);
	std::vector<int> b;
	std::vector<int> c;
	
	for(int i=0; i<v.size(); i++){
		
		//int a=;
		
		if(Ponavljanje_cifara(Cifre(v[i]))==true) {
			if(Ponavljanje_cifara2(Cifre(v[i]))==true) b.push_back(v[i]);
			else c.push_back(v[i]);
		}
	}
	if(istinitost==true) return b;
	else return c;
}

 


int main ()
{
	int n;
	std::vector<int> v;
	std::vector<int> h;
	//bool dupli(false);
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>n;
		v.push_back(n);
	} while(n!=0);
	

	
	std::vector<int> m = IzdvojiGadne(v,true);
	std::vector<int> l = IzdvojiGadne(v,false);
	
	
	std::cout<<"Opaki: ";
	if(m.size()!=0){
		for(int i=0; i<m.size(); i++){
			std::cout<<m[i]<<" ";
		}
	}
	
	std::cout<<std::endl<<"Odvratni: ";
	if(l.size()!=0){
		for(int i=0; i<l.size()-1; i++){
			std::cout<<l[i]<<" ";
		}
	}
	
	return 0;
}