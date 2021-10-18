#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
typedef std::deque<int> Dek ;
typedef std::vector<int> Vektor ;
enum Smjer {Rastuci=1, Opadajuci=2};
bool Stepen_Dvojke (int n){
	int k=0,cifra=1;
	if (n<0) return 0;
 while (cifra<=n){
	cifra=pow(2,k);
	if (n==cifra)
	return 1;
	k++ ;}
	return 0;
}
Dek MaksimalniPodnizoviStepenaDvojke (Vektor v,Smjer n){
	Dek povratni;
	switch (n){
	case Rastuci:{
		for (int i=1; i<v.size();i++){
			if (i==1 && v.at(0)<v.at(i)&& Stepen_Dvojke(v.at(0))&& Stepen_Dvojke(v.at(1))) povratni.push_back(v.at(0));
			if (i!=(v.size()-1)&&((v.at(i-1)<v.at(i) && Stepen_Dvojke(v.at(i-1))&& Stepen_Dvojke(v.at(i)))|| (v.at(i)<v.at(i+1)&& Stepen_Dvojke(v.at(i))&& Stepen_Dvojke(v.at(i+1))))) povratni.push_back(v.at(i)); 
			else if (i==(v.size()-1)&& v.at(i)>v.at(i-1)&& Stepen_Dvojke(v.at(i))&& Stepen_Dvojke(v.at(i-1))) 
			povratni.push_back(v.at(i));
		}
		break;
	}
	case  Opadajuci:{
		for (int i=1; i<v.size(); i++){
			if (i==1 && v.at(0)>v.at(1)&& Stepen_Dvojke(v.at(0))&& Stepen_Dvojke(v.at(1)) ) povratni.push_back (v.at(0)); 
		    if (i!=(v.size()-1)&& ((v.at(i-1)>v.at(i) && Stepen_Dvojke(v.at(i-1))&& Stepen_Dvojke(v.at(i)))|| (v.at(i)>v.at(i+1)&& Stepen_Dvojke(v.at(i))&& Stepen_Dvojke(v.at(i+1))))) povratni.push_back(v.at(i));
	         else if (i==(v.size()-1)&& (v.at(i)<v.at(i-1)&& Stepen_Dvojke(v.at(i))&& Stepen_Dvojke(v.at(i-1))))
				povratni.push_back(v.at(i));
			} break; } }
	return povratni;
}
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	Vektor a;
	for (int i=0;i<n;i++){
		int cifra;
		std::cin>>cifra;
		a.push_back(cifra);
	}
	int s;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>s;
	Smjer b=static_cast <Smjer>(s);
	Dek maxpodniz;
	if (b==1){
		std:: cout<<"Maksimalni rastuci podnizovi: \n";
		maxpodniz=MaksimalniPodnizoviStepenaDvojke(a,Rastuci);
		if (maxpodniz.size()==0) return 0;
		int j=0,novi_red=0;
		while(a.at(j)!=maxpodniz.at(0)) j++;
		j++;
		for (int i=1; i<maxpodniz.size();i++){
			if (i==1) std::cout<<maxpodniz.at(0)<<" ";
			if (a.at(j)!=maxpodniz.at(i)){
				for (int f=j; f<a.size();f++){
					if (a.at(f)==maxpodniz.at(i)) { novi_red=1; j=f; break;}
				}}
				if (novi_red==1 || maxpodniz.at(i)<maxpodniz.at(i-1)) std:: cout<<"\n";
				std::cout<<maxpodniz.at(i)<<" ";
				novi_red=0; j++;
		}
	} else if(b==2){
		std::cout<<"Maksimalni opadajuci podnizovi: \n";
		maxpodniz=MaksimalniPodnizoviStepenaDvojke(a,Opadajuci);
		if (maxpodniz.size()==0) return 0;
		int j=0,novi_red=0;
		while (a.at(j)!=maxpodniz.at(0)){
			j++;
		} j++;
		for (int i=1;i<maxpodniz.size();i++){
			if (i==1) std::cout<<maxpodniz.at(0)<<" ";
			if (a.at(j)!=maxpodniz.at(i)){
				for (int f=j;f<a.size();f++){
				if (a.at(f)==maxpodniz.at(i)){ novi_red=1; j=f; break; }}
			} 
			if (novi_red==1 || maxpodniz.at(i)>maxpodniz.at(i-1)) std::cout<<"\n";
			std::cout<<maxpodniz.at(i)<<" ";
		novi_red=0; j++;
	} }
	return 0;
}