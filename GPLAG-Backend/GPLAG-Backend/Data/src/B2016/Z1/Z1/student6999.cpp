/*B 2016/2017, Zadaća 1, Zadatak 1
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
*/
#include <iostream>
#include <vector>
#include <cmath>
std::vector<int> IzdvojiGadne(std::vector<int> v, bool logy){
	if(v.size() == 0) return {};
	std::vector<int> rezultat;
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(v[i] == v[j]){
				// izbacivanje istih elemenata iz vektora
				int k=j;
				while(k+1<v.size()){
					v[k]=v[k+1];
					k++;
				}
				int novaduz=v.size()-1;
				v.resize(novaduz);
				j--;
			}
		}
	}
	if(logy){
		int brojnula=0,brojjedinica=0,brojdvica=0;
		for(int i=0;i<v.size();i++){
			if(v[i] == 0) continue;
			int temp = v[i];
			long long temputri=0;
			brojnula=0;brojjedinica=0;brojdvica=0;
			while(temp){
				temputri=std::abs(temp)%3;
				if(temputri == 0) brojnula++;
				else if(temputri == 1) brojjedinica++;
				else brojdvica++;
				temp/=3;
			}
			if((brojnula%2==0)&&(brojjedinica%2==0)&&(brojdvica%2==0)) rezultat.push_back(v[i]);
		}
	}
	else{
		for(int i=0;i<v.size();i++){
			if(v[i]==1 || v[i]==2){ rezultat.push_back(v[i]);
			continue;}
			int temp = v[i];
			long long temputri=0;
			long long k=1;
			while(temp){
				temputri+=std::abs(temp%3)*k;
				k*=10;
				temp/=3;
			}
			int brojnula=0,brojjedinica=0,brojdvica=0;
			while(temputri){
				int pri=temputri%10;
				if(pri == 0) brojnula++;
				else if(pri== 1) brojjedinica++;
				else brojdvica++;
				temputri/=10;
			}
			/*if((brojnula%2!=0)&&(brojjedinica%2!=0)&&(brojdvica%2!=0)) rezultat.push_back(v[i]);
			else if((brojnula%2!=0) && (brojjedinica%2!=0) && (brojdvica==0)) rezultat.push_back(v[i]);
			else if((brojnula%2!=0) && (brojjedinica==0) && (brojdvica%2!=0)) rezultat.push_back(v[i]);
			else if((brojnula==0) && (brojjedinica%2!=0) &&(brojdvica%2!=0)) rezultat.push_back(v[i]);
			else if((brojnula==0) && (brojjedinica%2!=0) &&(brojdvica==0)) rezultat.push_back(v[i]);
			else if((brojnula==0) && (brojjedinica==0) &&(brojdvica%2!=0)) rezultat.push_back(v[i]);
			else if((brojnula%2!=0) && (brojjedinica==0) &&(brojdvica==0)) rezultat.push_back(v[i]);
				*/  /*Ovo ostavljam namjerno da se mogu podsjetiti koliko sam bio "posebnan" momak dok nisam razmislio glavom...*/
			if((brojnula%2==1 || brojnula == 0) &&(brojjedinica%2==1 || brojjedinica==0) &&(brojdvica%2 == 1 || brojdvica==0))
			rezultat.push_back(v[i]);
			
		}
		
	}
return rezultat;
}

int main ()
{
try{
std::vector<int> ulaz;
std::cout<< "Unesite brojeve (0 za prekid unosa): ";
int broj=1;
while(broj!=0){
	std::cin>>broj;
	if(!broj) break;
	ulaz.push_back(broj);
}
std::vector<int> rezparni;
std::vector<int> rezneparni;
rezparni = IzdvojiGadne(ulaz, true);
rezneparni = IzdvojiGadne(ulaz,false);
std::cout<<"Opaki: ";
for(int i:rezparni) std::cout<<i<<" ";
std::cout<<std::endl;
std::cout<<"Odvratni: ";
for(int i:rezneparni) std::cout<<i<<" ";
}
catch(char const a[]){
	std::cout<<a;
}
return 0;
}