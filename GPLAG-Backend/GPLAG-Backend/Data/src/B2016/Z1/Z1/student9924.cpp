/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

std::vector<int>IzdvojiGadne(std::vector<int>vektor, bool izbor){
	//prebrojavanje broja cifara
	std::vector<int>novi_vektor;
	for(int i=0; i<vektor.size(); i++){
		int br0(0);
		int br1(0);
		int br2(0);
		int broj3;
		broj3=vektor[i];
		if(broj3==0)
			br0++;
		while(broj3!=0){
			if(broj3%3==0)
				br0++;
			if(broj3%3==1 || broj3%3==-1)
				br1++;
			if(broj3%3==2 || broj3%3==-2)
				br2++;
			broj3/=3;
		}
		if(br0%2==0 && br1%2==0 && br2%2==0 && izbor==true)
			novi_vektor.push_back(vektor[i]);
		if((br0%2==1 && br1%2==1 && br2%2==1 && izbor==false) || (br0%2==1 && br1%2==1 && br2==0 && izbor==false) || (br0%2==1 && br2%2==1 && br1==0 && izbor==false) || (br2%2==1 && br1%2==1 && br0==0 && izbor==false) || (br0%2==1 && br1==0 && br2==0 && izbor==false) || (br1%2==1 && br0==0 && br2==0 && izbor==false) || (br2%2==1 && br1==0 && br0==0 && izbor==false))
			novi_vektor.push_back(vektor[i]);
	}
	//vektor u kojem se elementi ne ponavljaju
	std::vector<int> vektor_salji;
	if(novi_vektor.size()!=0){
		vektor_salji.push_back(novi_vektor[0]);
		for(int i=1; i<novi_vektor.size(); i++){
			bool vec_ima(false);
			for(int j=0; j<vektor_salji.size(); j++){
				if(vektor_salji[j]==novi_vektor[i])
					vec_ima=true;
			}
			if(vec_ima)
				continue;
			else
				vektor_salji.push_back(novi_vektor[i]);
		}
	}
	return vektor_salji;
}

int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int n;
	std::vector<int>v;
	while(std::cin >> n && n!=0){
		if(n!=0)
			v.push_back(n);
	};
	std::cout << "Opaki: ";
	auto v1=IzdvojiGadne(v,true);
	for(int x: v1){
		std::cout << x << " ";
	}
	std::cout << "\nOdvratni: ";
	auto v2=IzdvojiGadne(v,false);
	for(int x: v2){
		std::cout << x << " ";
	}
	return 0;
}