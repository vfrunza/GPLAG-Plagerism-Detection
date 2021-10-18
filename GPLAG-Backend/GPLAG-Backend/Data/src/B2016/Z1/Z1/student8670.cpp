/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <vector>
#include <iostream>

std::vector<int> IzbaciDuple(std::vector<int> br)
{
	for(int i=0; i < br.size(); i++){
		for(int j=i+1; j < br.size(); j++)
		{
			if (br[i] == br[j]) {
				br.erase(br.begin()+j);
				j--;}
		}}
		
		
		return br;
}
std::vector<int> Pretvori(int v) 
{
	std::vector<int> a;
	int c;
	long long int b= v;
	if(b<0) b*=(-1);
		
		do{
			c=b%3;
			a.push_back(c);
			b/=3;
		} while(b!=0);
	
	return a;
}
std::vector<int> IzdvojiGadne (std::vector<int> c, bool F) 
{
	std::vector<int> opaki;
	std::vector<int> odvratni;
	std::vector<int> pomocni;
	std::vector<int> cijeli=IzbaciDuple(c);
	
	for(int j=0; j<cijeli.size();j++){
		pomocni=Pretvori(cijeli[j]);
		int br0(0), br1(0), br2(0);
	for(int i=0; i < pomocni.size(); i++){
		if(pomocni[i] == 0) br0++;

		else if(pomocni[i] == 1) 	br1++;
		
		else 
		br2++;
	}
	
	if (br0 % 2 == 0 && br1 % 2 == 0 && br2 % 2 == 0) opaki.push_back(cijeli[j]);
		else if((br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0 || br2==0)) odvratni.push_back(cijeli[j]);
		
	}
	if(F)	return opaki;
	else return odvratni;
	
}
	
int main (){
	std::vector<int> b;
	int n;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do 
	{
		std::cin >> n;
		if(n!=0) b.push_back(n);
	} while (n!=0);
	

std::vector<int> v2;
std::vector<int> v3;
v2 = IzdvojiGadne(b, true);
std::cout << "Opaki: ";
for (int i=0; i < v2.size(); i++)	std::cout <<  v2[i]<<" ";
v3 = IzdvojiGadne(b, false);
std::cout <<  std::endl;
std::cout << "Odvratni: " ;
for (int i=0; i < v3.size(); i++)	std::cout << v3[i] <<" ";


	return 0;
}