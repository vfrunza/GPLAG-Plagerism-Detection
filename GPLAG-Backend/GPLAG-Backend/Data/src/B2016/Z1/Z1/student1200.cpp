/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<cmath>
#include<vector>
int stepen(int baza,int expo){
	int rez=1;
	for(int i=1;i<=expo;i++) rez*=baza;
	
	return rez;
}
std::vector<int> IzbaciDuple(std::vector<int> v)
{
	
	for(int i(0); i <v.size() -1 ; i++)
{
	for(int j(i+1);j<v.size();j++){
		if(v[i]==v[j]){
			for(int k(j);k<v.size()-1;k++){
				v[k]=v[k+1];
				
			}
			v.resize(v.size()-1);
			
		}

	}
	
}
	return v;
}
std::vector<int> Tercarna(int n)
{
	int cifra;
	n = fabs(n);
	std::vector<int> v;
	 do 
	{
		cifra = n % 3;
		n = n / 3;
		v.push_back(cifra);
	}while(n > 0);
	
	return v;
}
//opak je sa parnim ciframa od kojih se sastoji taj broj
bool DaLiJeOpak(int broj){
	int brojac0(0),brojac1(0),brojac2(0);
	for(auto x : Tercarna(broj))
	{
		if(x == 2) brojac2++;
		else if(x == 1) brojac1++;
		else if(x == 0) brojac0++;
	}
	if(brojac0 % 2 == 0 && brojac1 % 2 == 0  && brojac2 % 2 == 0) return true;
	else if(brojac0 % 2 == 0 && brojac1 % 2 == 0 && brojac2 == 0) return true;
	else if(brojac0 == 0 && brojac1 % 2 == 0 && brojac2 % 2 == 0) return true;
	else if(brojac0 % 2 ==  0 && brojac1 == 0 && brojac2 % 2 == 0) return true;
	else if(brojac0 == 0 && brojac1 == 0 && brojac2 % 2 ==0 )return true;
	else if(brojac0 % 2 == 0 && brojac1 == 0 && brojac2 == 0) return true;
	else if(brojac0 == 0 && brojac1 % 2 == 0 && brojac2 == 0) return true;
	else return false;
	
}

bool DaLiJeOdvratan(int broj){
	int brojac0(0),brojac1(0),brojac2(0);
	for(auto x : Tercarna(broj))
	{
		if(x == 2) brojac2++;
		else if(x == 1) brojac1++;
		else if(x == 0) brojac0++;
	}
	if(brojac0 % 2 != 0 && brojac1 % 2 != 0  && brojac2 % 2 != 0) return true;
	else if(brojac0 % 2 != 0 && brojac1 % 2 != 0 && brojac2 == 0) return true;
	else if(brojac0 % 2 != 0 && brojac1 == 0 && brojac2 % 2 != 0) return true;
	else if(brojac0 ==  0 && brojac1 % 2 != 0 && brojac2 % 2 != 0) return true;
	else if(brojac0 == 0 && brojac1 == 0 && brojac2 % 2 !=0 )return true;
	else if(brojac0 % 2 != 0 && brojac1 == 0 && brojac2 == 0) return true;
	else if(brojac0 == 0 && brojac1 % 2 != 0 && brojac2 == 0) return true;
	else return false;
}
std::vector<int> IzdvojiGadne(std::vector<int> v, bool a){
	std::vector<int>novi;
	v=IzbaciDuple(v);
	for(int i(0) ; i < v.size() ; i++){
		if(a){
			if(DaLiJeOpak(v[i]))novi.push_back(v[i]);
		}
		else{
			if(DaLiJeOdvratan(v[i]))novi.push_back(v[i]);
		}
	}
	return IzbaciDuple(novi);
}

int main(){
	int broj;
	std::vector<int> v;
	std::vector<int> opaki;
	std::vector<int> odvratni;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>> broj;
		v.push_back(broj);
		
	}while(broj != 0);
	for(int i (0); i < v.size() -1; i++)
	{
		if(DaLiJeOpak(v[i]))
		{
			opaki.push_back(v[i]);
		
		}
		else if(DaLiJeOdvratan(v[i]))
		{
			odvratni.push_back(v[i]);
		
		}
	}
	opaki = IzbaciDuple(opaki);
	odvratni = IzbaciDuple(odvratni);
	std::cout<<"Opaki: ";
	for(int i(0); i < opaki.size(); i++)
	{
		std::cout<<opaki[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i(0); i < odvratni.size(); i++)
	{
		std::cout<<odvratni[i]<<" ";
	}

return 0;
}