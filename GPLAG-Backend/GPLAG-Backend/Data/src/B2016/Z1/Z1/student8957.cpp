/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

bool DaLiSeCifreJavljajuNeParanBrojPuta(int broj){
	std::vector<int>v(10);
	int cifra;
	if (broj==0) return true;
	while (broj!=0){
		cifra=broj%10;
		v[cifra]++;
		broj/=10;
	}
	for (int i=0;i<v.size();i++)
		if (v[i]>0 && v[i]%2==0) return false;
	return true;
}

bool DaLiSeCifreJavljajuParanBrojPuta(int broj){
	std::vector<int>v(10);
	int cifra;
	if (broj==0) return false;
	while (broj!=0){
		cifra=broj%10;
		v[cifra]++;
		broj/=10;
	}
	for (int i=0;i<10;i++)
		if (v[i]>0 && v[i]%2!=0) return false;
	return true;
}

std::vector<int> PoTernanrnomBrojnomSistemu (std::vector<int>v){
	std::vector<int>v1;
	int trenutni,novi,ostatak,pomocni,a(0),konacni,temp,nule(0);
	for (int i=0;i<v.size();i++){
		nule=0;
		temp=v[i];
		if (temp==0) v1.push_back(0);
		else {
			if (temp<0) temp*=-1;
			while(temp-(int(temp/3)*3)==0){
				nule++;
				temp/=3;
			}
			trenutni=v[i];
			if (trenutni<0) trenutni*=-1;
			a=0;novi=0;
			while(trenutni!=0){
				pomocni=trenutni/3;
				ostatak=trenutni-(pomocni*3);
				novi=(a+ostatak)*10;
				a=novi;
				trenutni/=3;
			}
			novi/=10;
			a=0;pomocni=0;
			while (novi!=0){
				pomocni=novi%10;
				konacni=(a+pomocni)*10;
				a=konacni;
				novi/=10;
			}
			konacni=konacni/10;
			for (int i=0;i<nule;i++)
				konacni*=10;
			v1.push_back(konacni);
		}
	}
	return v1;
}

std::vector<int> IzdvojiGadne (std::vector<int>v, bool logicka){
	for (int i=0;i<v.size();i++){
		for (int j=i+1;j<v.size();j++){
			if (v[i]==v[j]){
				for (int k=j;k<v.size()-1;k++){
					v[k]=v[k+1];
				}
				v.resize(v.size()-1);
				j--;
			}
		}
	}
	
	std::vector<int>v1(PoTernanrnomBrojnomSistemu(v));
	std::vector<int>v2;
	if (logicka){
		for (int i=0;i<v.size();i++){
			if (DaLiSeCifreJavljajuParanBrojPuta(v1[i])){
				v2.push_back(v[i]);
			}
		}
	}
	
	else if(logicka==false){
		for (int i=0;i<v.size();i++){
			if (DaLiSeCifreJavljajuNeParanBrojPuta(v1[i]))
				v2.push_back(v[i]);
		}
	}
	return v2;
}
int main ()
{
	int broj;
	std::vector<int>v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>broj;
		if (broj==0) break;
		v.push_back(broj);
	}while (broj!=0);
	
	std::cout<<"Opaki: ";
	for (int x : IzdvojiGadne(v,true))
		std::cout<<x<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	for (int x : IzdvojiGadne(v, false))
		std::cout<<x<<" ";		
	
	return 0;
}