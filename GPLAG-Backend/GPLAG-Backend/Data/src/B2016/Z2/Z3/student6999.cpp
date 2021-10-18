#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <iomanip>
#include <cmath>
int SumaCifara(long long int arg){
	int suma=0;
	if (arg == 0) return 1;
	while(arg){
		suma+=arg%10;
		arg/=10;
	}
	return suma;
}
bool savrsen(long long int arg){
	//savrseni broj je jednak sumi svih svojih djelilaca ne racunajuci njega samog
	long long int suma=0;
	for(int i=1; i<=arg/2; i++){
		if(arg%i == 0)
			suma+=i;
	}
	if(suma == arg) return true;
	return false;
}
int SumaDjelilaca(long long int arg){
	int suma=0;
	for(int i=1;i<=arg;i++){
		if(arg%i == 0) suma+=i;
	}
	return suma;
}
int BrojProstihFaktora(long long int arg){
	int brojac=0,j=2;
	while(arg!=1){
		if(arg%j==0){
			brojac++;
			arg/=j;
		} else j++;
	}
	return brojac;
}
int BrojSavrsenihDjelilaca(long long int arg){
	int brojac=0;
	for(int i=1; i<=arg;i++)
		if(savrsen(i) && arg%i == 0) brojac++;	// i je sigurno savrsen broj i djelioc je od arg
	return brojac;
}
template<typename t1, typename t2, typename t3, typename t4>
auto UvrnutiPresjek(t1 it1, t1 it2, t2 it3, t2 it4, t3 fja(t4))
->std::vector<std::vector<typename std::remove_reference<decltype(*it1+*it3)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*it1+*it3)>::type>> izlaz;
	//napravljena je izlazna matrica
	//koristiti sort za sortiranje
izlaz.resize(0);
int velicina1=(int)(it2-it1);
int velicina2=(int)(it4-it3);
int brojacredova=0;
for(int i=0;i<velicina1;i++){
	for(int j=0;j<velicina2;j++){
		if(fja(it1[i]) == fja(it3[j])){
			izlaz.resize(izlaz.size()+1);
			izlaz.at(brojacredova).push_back(it1[i]); //šutaj vrijednost x
			izlaz.at(brojacredova).push_back(it3[j]); //šutaj vrijednost y
			izlaz.at(brojacredova).push_back(fja(it1[i])); //šutaj vrijednost funkcije
			brojacredova++;
		}
	}
}
std::sort(izlaz.begin(),izlaz.end(),[](std::vector<typename std::remove_reference<decltype(*it1+*it3)>::type> v1, 
std::vector<typename std::remove_reference<decltype(*it1+*it3)>::type> v2){
	return(v1[2]<v2[2] ||(v1[2]==v2[2] && v1[0]<v2[0]) || (v1[2]==v2[2]&&v1[0]==v2[0] && v1[1]<v2[1]));
});
//prije returna pomoću sort funkcije sortiraj sve
return izlaz;
}
template<typename t1, typename t2, typename t3, typename t4>
auto UvrnutaRazlika(t1 it1, t1 it2, t2 it3, t2 it4, t3 fja(t4))
->std::vector<std::vector<typename std::remove_reference<decltype(*it1+*it3)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*it1+*it3)>::type>> izlaz;
	//oni elementi koji nemaju svog para u suprotnom skupu
izlaz.resize(0);
int velicina1=(int)(it2-it1);
int velicina2=(int)(it4-it3);
int brojacredova=0;
for(int i=0;i<velicina1;i++){
	bool vecima=false;
	auto trenutni = fja(it1[i]);
	for(int j=0;j<velicina2;j++){
		if(fja(it3[j]) == trenutni) vecima=true;
	}
	if(vecima) continue;
	else{
		izlaz.resize(izlaz.size()+1);
		izlaz.at(brojacredova).push_back(it1[i]);
		izlaz.at(brojacredova).push_back(trenutni);
		brojacredova++;
	}
}
for(int i=0;i<velicina2;i++){
	bool vecima=false;
	auto trenutni = fja(it3[i]);
	for(int j=0;j<velicina1;j++){
		if(fja(it1[j]) == trenutni) vecima=true;
	}
	if(vecima) continue;
	else{
		izlaz.resize(izlaz.size()+1);
		izlaz.at(brojacredova).push_back(it3[i]);
		izlaz.at(brojacredova).push_back(trenutni);
		brojacredova++;
	}
}
//na kraju sortiraj opadajućim redoslijedom
std::sort(izlaz.begin(),izlaz.end(),[](std::vector<typename std::remove_reference<decltype(*it1+*it3)>::type> v1, 
std::vector<typename std::remove_reference<decltype(*it1+*it3)>::type> v2){
	return(v1[0]>v2[0] ||(v1[0]==v2[0] && v1[1]>v2[1]));
});
return izlaz;
}
int main ()
{
std::vector<int> ul1;
std::vector<int> ul2;
std::cout<<"Unesite broj elemenata prvog kontejnera: ";
int brojel1;
std::cin>>brojel1;
std::cout<<"Unesite elemente prvog kontejnera: ";
	while(1){
		if(ul1.size()==brojel1) break;
		bool vecima=false;
		int temp;
		std::cin>>temp;
		for(int j=0;j<ul1.size();j++){ if(ul1[j]==temp){ vecima=true; break;}}
		if(vecima) continue;
		else(ul1.push_back(temp));
	}
std::cout<<"Unesite broj elemenata drugog kontejnera: ";
int brojel2;
std::cin>>brojel2;
std::cout<<"Unesite elemente drugog kontejnera: ";
	while(1){
		if(ul2.size() == brojel2) break;
		bool vecima=false;
		int temp;
		std::cin>>temp;
		for(int j=0;j<ul2.size();j++){ if(ul2[j]==temp){ vecima=true; break;}}
		if(vecima) continue;
		else(ul2.push_back(temp));
	}
std::cout<<"Uvrnuti presjek kontejnera:\n";
std::vector<std::vector<int>> izlaz; 
izlaz = UvrnutiPresjek(ul1.begin(),ul1.end(),ul2.begin(),ul2.end(),SumaCifara);
for(int i=0;i<izlaz.size();i++){
	for(int j=0;j<izlaz[i].size();j++){
		std::cout<<std::setw(6)<<izlaz[i][j]<<" ";
	}
	std::cout<<std::endl;
}
std::cout<<"Uvrnuta razlika kontejnera:\n";
std::vector<std::vector<int>> izlaz1;
izlaz1 = UvrnutaRazlika(ul1.begin(),ul1.end(),ul2.begin(),ul2.end(),BrojProstihFaktora);
for(int i=0;i<izlaz1.size();i++){
	for(int j=0;j<izlaz1[i].size();j++){
		std::cout<<std::setw(6)<<izlaz1[i][j]<<" ";
	}
	std::cout<<std::endl;
}
std::cout<<"Dovidjenja!";
	return 0;
}