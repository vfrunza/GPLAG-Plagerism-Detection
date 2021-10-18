#include<iostream>
#include<vector>
#include<algorithm>
long int brojic (long int n) {
	 long int a=1;
	long int suma(0);
	long int cifra(0);
	while (n!= 0) {
		
	cifra=std::abs(n%3);
	cifra=cifra*a;
	a=a*10;
	suma+=cifra;
	n=n/3;
		
		
	}
	
	return suma;	
}

std::vector<int> DaLiJeGadan (std::vector<int> vektor) {
std::vector<int> vektorb;	
	for (int i=0; i<vektor.size(); i++)
	{
	long int a = brojic(vektor[i]);
	int brojac1(0),brojac2(0),brojac3(0);
do  {
 	
 	if(a%10==1) brojac1++;
 	if(a%10==2) brojac2++;
 	if(a%10==0) brojac3++;
 	
 	a=a/10;
 	
 }while (a != 0);
 
 if(brojac1%2 == 0 && brojac2%2 == 0 && brojac3%2==0) vektorb.push_back(vektor[i]);
if ((brojac1%2 == 1 || brojac1==0) && (brojac2%2 == 1 || brojac2==0) && (brojac3%2 == 1 || brojac3==0)) vektorb.push_back(vektor[i]);

}
return vektorb;
}

bool JeLiGadan (long int n) {
	
	long int a = brojic(n);
	int brojac1(0),brojac2(0),brojac3(0);
 do {
 	
 	if(a%10==1) brojac1++;
 	if(a%10==2) brojac2++;
 	if(a%10==0) brojac3++;
 	
 	a=a/10;
 	
 } while (a != 0);
 
 if(brojac1%2 == 0 && brojac2%2 == 0 && brojac3%2==0) return true;
 if ((brojac1%2 == 1 || brojac1==0) && (brojac2%2 == 1 || brojac2==0) && (brojac3%2 == 1 || brojac3==0)) return false;

}

std::vector<int> IzdvojiGadne (std::vector<int> vektor, bool gadan) {
std::vector<int>vektorb;

for (int i=0; i<vektor.size(); i++) { 
	for (int j=i+1; j<vektor.size(); j++ )
	{
	if (vektor[i]==vektor[j]) {
	
vektor.erase(vektor.begin() + j);
	j--;
	}
	}
}
	for (int i=0; i<vektor.size(); i++)
	{
	long int a = brojic(vektor[i]);
	int brojac1(0),brojac2(0),brojac3(0);
 while (a != 0) {
 	
 	if(a%10==1) brojac1++;
 	if(a%10==2) brojac2++;
 	if(a%10==0) brojac3++;
 	
 	a=a/10;
 	
 }
 
 if(brojac1%2 == 0 && brojac2%2 == 0 && brojac3%2==0) vektorb.push_back(vektor[i]);
if ((brojac1%2 == 1 || brojac1==0) && (brojac2%2 == 1 || brojac2==0) && (brojac3%2 == 1 || brojac3==0)) vektorb.push_back(vektor[i]);

}
std::vector<int> vektorc;
if (gadan)
for (long int x : vektorb) {
	
	if(JeLiGadan(x))
	vektorc.push_back(x);
	
	}
	
	if (!gadan)
	for (long int x : vektorb) {
		
		if(!JeLiGadan(x))
		vektorc.push_back(x);
		
	}
	
for (int i=0; i<vektorc.size(); i++) { 
	for (int j=i+1; j<vektorc.size(); j++ )
	{
	if (vektorc[i]==vektorc[j]) {
	
vektorc.erase(vektorc.begin() + j);
	j--;
	}
	}
}	

	return vektorc;
	
}


int main ()
{
std::vector<int>vektorcic;
std::cout<<"Unesite brojeve (0 za prekid unosa): ";
long int n;

do  {
	
	std::cin>>n;
	if (n != 0)vektorcic.push_back(n);
}while(n != 0);


std::vector<int>b;
std::vector<int>c;

b=IzdvojiGadne(DaLiJeGadan(vektorcic),true);
c=IzdvojiGadne(DaLiJeGadan(vektorcic),false);



	std::cout<<"Opaki: ";
for (int x : b) std::cout<< x <<" ";
std::cout<<std::endl;
std::cout<<"Odvratni: ";
for ( int x : c) std::cout<< x <<" ";

	return 0;
}