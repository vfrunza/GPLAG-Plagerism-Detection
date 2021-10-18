/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
long int stepen(int n){
	long int pom=10;
	if(n==0) return 1;
	for(int i=1; i<n; i++ ){
		pom*=10;
	}
	return pom;
}
int br_cifara(int n){
	int br=0;
	if(n==0) return 1; 
	while(n!=0){
		n/=3;
		br++;
	}
	return br;
}
long int DekUTer(int n){
	long int t=0;
	int pom=n;
	if(n<0) pom=-n;
	int m,k=br_cifara(pom);
	for(int i=0; i<k; i++){
		m=pom%3;
		pom/=3;
		t+=m*stepen(i);
	}
	if(n<0) t=-t;
	return t;
}
int Gadni(int n){
	long int t=DekUTer(n);
	int b0=0,b1=0,b2=0,pom, k=br_cifara(n);
	for(int i=0; i<k; i++){
		pom=t%10;
		t/=10;
		if(pom==2) b2++;
		else if(pom==1) b1++;
		else if(pom==0) b0++;
	}
	
	if(b2%2==0 && b1%2 ==0 && b0%2==0) return 1;
	if( (b2%2==1 && b1%2==1 && b0==0) || (b2%2==1 && b0%2==1 && b1==0) || (b1%2==1 && b0%2==1 && b2==0) || (b1%2==1 && b2%2==1 && b0%2==1)) return 2;
	if((b0%2==1 && b1==0 && b2==0) || (b1%2==1 && b0==0 && b2==0) || (b2%2==1 && b0==0 && b1==0)) return 2;
	return 0;
}
std::vector<int>IzdvojiGadne(std::vector<int> v, bool t){
	std::vector<int> nv;
	for(int i=0; i<v.size()-1; i++){
		if(Gadni(v[i])==0) continue;
		if(t==true && Gadni(v[i])==1) nv.push_back(v[i]);
		if(t==false && Gadni(v[i])==2) nv.push_back(v[i]);
	}
	int n=nv.size(),j,k,i;
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(nv[i]==nv[j]){
				for(k=j; k<n-1; k++){
					nv[k]=nv[k+1];
				}
				n--;
				j--;
			}
		}
	}
	nv.resize(n);

	return nv;
}
int main ()
{
	std::vector<int> vektor; 
	int broj; 
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin >> broj;
		vektor.push_back(broj);
	}while(broj!=0);
	std::vector<int> opaki=IzdvojiGadne(vektor,true);
	std::vector<int> odvratni=IzdvojiGadne(vektor,false);
	std::cout << "Opaki: ";
	int k=opaki.size();
	for(int i=0; i<k; i++) std::cout << opaki[i]<<" ";
	k=odvratni.size();
	std::cout << std::endl<< "Odvratni: ";
	for(int i=0; i<k; i++) std::cout << odvratni[i]<<" ";
	
	return 0;
}