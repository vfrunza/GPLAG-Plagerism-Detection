/*B 2017/2018, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include <vector>
#include <deque>
enum Smjer {Rastuci, Opadajuci};
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int>v, Smjer smjer )
{
	int broj,broj2;
	std::deque<std::vector<int>> dek ;
	bool stependvojke1,stependvojke2;
	if(/*smjer==1*/ smjer==Rastuci) {
		int duzinadeka(0);
		dek.resize(duzinadeka+1);
		int i(0);
		while(i<v.size()-1){
			if(v.at(i)==0){
				i++;
				continue;
			}
			broj=v.at(i);
			broj2=v.at(i+1);
			while(broj%2==0 && broj!=1){
				broj=broj/2;
			}
			if(broj==1) stependvojke1=1;
			else stependvojke1=0;
			while (broj2%2==0 && broj2!=1) {
				broj2=broj2/2;
			}
			if(broj2==1) stependvojke2=1;
			else stependvojke2=0;
			
			std::vector<int> pomocni;
			int k=i;
			
			while(i<v.size()-1&&stependvojke2&&stependvojke1&&v.at(i)<v.at(i+1)){
				i++;
			}
			
			if(i!=k /*&& (i-k)>1*/){
				int pomoc;
				for(int j=k;j<=i;j++){
					pomoc=v.at(j);
					while(pomoc%2==0&&pomoc!=1){
						pomoc=pomoc/2;
					}
					if(pomoc==1){
					pomocni.push_back(v.at(j));}
					else break;
				}
			
				for(int k=0;k<pomocni.size();k++){
					dek[duzinadeka].push_back(pomocni.at(k));
				}
					duzinadeka++;
				dek.resize(duzinadeka+1);
			}
			i++;
		}
		
	}
	if(/*smjer==2*/ smjer==Opadajuci) {
		int duzinadeka(0);
		dek.resize(duzinadeka+1);
		int i(0);
		while(i<v.size()-1){
			if(v.at(i)==0){
				i++;
				continue;
			}
			broj=v.at(i);
			broj2=v.at(i+1);
			while(broj%2==0 && broj!=1){
				broj=broj/2;
			}
			if(broj==1) stependvojke1=1;
			else stependvojke1=0;
			
			while (broj2%2==0 && broj2!=1) {
				broj2=broj2/2;
			}
			if(broj2==1) stependvojke2=1;
			else stependvojke2=0;
			
			std::vector<int> pomocni;
			int k=i;
			
			while(i<v.size()-1&&stependvojke2&&stependvojke1&&v.at(i)>v.at(i+1)){
				i++;
			}
			
			if(i!=k/* && (i-k)>1*/){
				int pomoc2;
				for(int j=k;j<=i;j++){
					pomoc2=v.at(j);
					while(pomoc2%2==0&&pomoc2!=1){
						pomoc2=pomoc2/2;
					}
					if(pomoc2==1){
					pomocni.push_back(v.at(j));}
					else break;
				}
				
				for(int k=0;k<pomocni.size();k++){
					dek[duzinadeka].push_back(pomocni.at(k));
				}
				duzinadeka++;
				dek.resize(duzinadeka+1);
				
			}
			i++;
		}
		
	}
	return dek;
}
int main ()
{
	std::deque<std::vector<int>> dek ;
	std::vector<int> v;

	int n,broj,smjer;
	

	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin>>broj;
		v.push_back(broj);
	}
	//std::cin.ignore(10000,'\n');
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>smjer;
	if(smjer==1){
		dek=MaksimalniPodnizoviStepenaDvojke(v,Rastuci);
	}
	else if(smjer==2){
	dek=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);	
	}
	if(smjer==1) std::cout <<"Maksimalni rastuci podnizovi: ";
	else std::cout <<"Maksimalni opadajuci podnizovi: ";
	std::cout <<std::endl;

	for(int j=0; j<dek.size(); j++) {
		for(int k=0; k<dek[j].size(); k++) {
			std::cout<<dek[j][k]<<" ";
		}
		std::cout <<std::endl;
	}

	return 0;
}
/*std::deque<std::vector<int>> dek;
	std::vector<int>probrani;
	std::vector<int>finalp;
	int bio;
	if(Smjer==1) {
		int broj,broj2;
		int x=0,y=0,k=0;
		dek.resize(k+1);


		for(int i=0; i<v.size()-1; i++) {
			broj=v.at(i);
			broj2=v.at(i+1);
			if(i==v.size()) break;
			while(broj%2==0&&broj!=1) {
				broj=broj/2;
			}
			if(broj==1) x=0;

			else x=1;
			while(broj2%2==0&&broj2!=1){
				broj2=broj2/2;
			}
			if(broj2==1) y=0;
			else y=1;
			if(i>0 && bio==0 && v[i]<v[i-1] && v[i]>v[i+1]) continue;
			if(x==0&&y==0&& (i+1)==v.size()-1){
				dek[k].push_back(v.at(i));
				dek[k].push_back(v.at(i+1));
				break;
			}
			if(x==0&&y==0&&v.at(i)<v.at(i+1)) {
				dek[k].push_back(v.at(i)); }

			if(x==0 && y==1 && v.at(i)<v.at(i+1) && bio==1|| (x==0 && v.at(i)>v.at(i+1))){
				dek[k].push_back(v[i]);
				k++;
				dek.resize(k+1);
			}
			//if(x==0&&y==1) dek[k].push_back(v[i]);


			bio=x;
		}

	}

	else if(Smjer==2){
			int broj,broj2;
		int x=0,y=0,k=0;
		dek.resize(k+1);

		//int bio;
		for(int i=0; i<v.size()-1; i++) {
			broj=v.at(i);
			broj2=v.at(i+1);
		//	if(i==v.size()) break;

			while(broj%2==0&&broj!=1) {
				broj=broj/2;
			}
			if(broj==1) x=0;

			else x=1;
			while(broj2%2==0&&broj2!=1){
				broj2=broj2/2;
			}
			if(broj2==1) y=0;
			else y=1;
			if(i>0 /*&& bio==0 && v[i]>v[i-1] && v[i]<v[i+1]) continue;
			if(x==0&&y==0&& (i+1)==v.size()-1){
				dek[k].push_back(v.at(i));
				dek[k].push_back(v.at(i+1));
				break;
			}
			if(x==0&&y==0&&v.at(i)>v.at(i+1)) {
				dek[k].push_back(v.at(i)); }
		//	bio=1; -- neincijalizovano !!!!!!
			if(x==0 && y==1 && v.at(i)>v.at(i+1) || (x==0 && v.at(i)<v.at(i+1) && bio==0)){
				dek[k].push_back(v[i]);
				k++;
				dek.resize(k+1);
			}



			bio=x;
		}


	}
		return dek;
}*/
