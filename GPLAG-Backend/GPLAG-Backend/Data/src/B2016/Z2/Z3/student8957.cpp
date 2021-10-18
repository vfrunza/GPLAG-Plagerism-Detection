/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>

int SumaCifara(int broj){
	int suma(0);
	if (broj>0){
		while (broj!=0){
			suma+=broj%10;
			broj/=10;
		}
	}
	else {
		while (broj!=0){
			suma+=-(broj%10);
			broj/=10;
		}
	}
	return suma;
}

long long int SumaDjelilaca(int broj){
	long long int suma(0);
	if (broj>0){
		for (int i=1;i<=broj;i++){
			if (broj%i==0)
				suma+=i;
		}
	}
	else {
		for (long long int i=broj;i<0;i++){
			if (broj%i==0)
				suma+=-i;
		}
	}
	return suma;
}
	
long long int BrojProstihFaktora(int broj){
	int broj_prostih(0);
	if (broj>0){
		for (int i=2;i<=broj;i++){
			if (broj%i==0){
				broj_prostih++;
				broj/=i;
				i--;
			}
		}
	}
	else {
		for (long long int i=broj;i<-1;i++){
			if(broj%i==0){
				broj_prostih++;
				broj/=i;
				i--;
			}
		}
	}
	return broj_prostih;
}

bool DaLiJeSavrsen (int broj){
	int suma(0);
	for (int i=1;i<broj;i++){
		if (broj%i==0)
			suma+=i;
	}
	if (suma==broj) return true;
	return false;
}

long long int BrojSavrsenihDjelilaca(int broj){
	int broj_savrsenih(0);
	for (int i=2;i<=broj;i++){
		if (broj%i==0 && DaLiJeSavrsen(i))
			broj_savrsenih++;
	}
	return broj_savrsenih;
}

template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>
	auto UvrnutiPresjek(Tip1 p1,Tip1 p2, Tip2 p3, Tip2 p4, Tip3 f (Tip4)) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
		Tip1 temp1(p1);
		Tip2 temp3(p3);
		std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>povratna;
		int k(0);
		while (temp1!=p2){
			temp3=p3;
			while (temp3!=p4){
				if(f(*temp1)==f(*temp3)){
						povratna.resize(povratna.size()+1);
						povratna[k].resize(3);
						povratna[k][0]=*temp1;
						povratna[k][1]=*temp3;
						povratna[k][2]=f(*temp1);
						k++;
				}
				temp3++;
			}
			temp1++;
		}
		sort (povratna.begin(),povratna.end(),[](std::vector<typename std::remove_reference<decltype(*p1)>::type>v1, std::vector<typename std::remove_reference<decltype(*p1)>::type>v2){return ((v1[2]<v2[2]) || ((v1[2]==v2[2]) && (v1[0]<v2[0])) || ((v1[0]==v2[0]) && (v1[2]==v2[2]) && (v1[1]<v2[1])));});
		return povratna;
	}

template <typename Tip1, typename Tip2>
	auto UvrnutiPresjek(Tip1 p1,Tip1 p2, Tip2 p3, Tip2 p4) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
		Tip1 temp1(p1);
		Tip2 temp3(p3);
		std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>povratna;
		int k(0);
		while (temp1!=p2){
			temp3=p3;
			while (temp3!=p4){
				if(*temp1==*temp3){
						povratna.resize(povratna.size()+1);
						povratna[k].resize(3);
						povratna[k][0]=*temp1;
						povratna[k][1]=0;
						povratna[k][2]=0;
						k++;
				}
				temp3++;
			}
			temp1++;
		}
		sort (povratna.begin(),povratna.end(),[](std::vector<typename std::remove_reference<decltype(*p1)>::type>v1, std::vector<typename std::remove_reference<decltype(*p1)>::type>v2){ return v1[0]<v2[0]; });
		return povratna;
	}
	
template <typename Tip1, typename Tip2, typename Tip3,typename Tip4>
	auto UvrnutaRazlika (Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 f(Tip4))-> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
		Tip1 temp1(p1);
		Tip2 temp3(p3);
		std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>povratna;
		temp1=p1;
		temp3=p3;
		int k(0);
		while (temp1!=p2){
			temp3=p3;
			while(temp3!=p4){
				if (f(*temp1)==f(*temp3))
					break;
				temp3++;
			}
			if (temp3==p4){
				povratna.resize(povratna.size()+1);
				povratna[k].resize(2);
				povratna[k][0]=*temp1;
				povratna[k][1]=f(*temp1);
				k++;
			}
			temp1++;
		}
		temp1=p1;
		temp3=p3;
		while (temp3!=p4){
			temp1=p1;
			while(temp1!=p2){
				if (f(*temp1)==f(*temp3))
					break;
				temp1++;
			}
			if (temp1==p2){
				povratna.resize(povratna.size()+1);
				povratna[k].resize(2);
				povratna[k][0]=*temp3;
				povratna[k][1]=f(*temp3);
				k++;
			}
			temp3++;
		}
	sort (povratna.begin(),povratna.end(),[](std::vector<typename std::remove_reference<decltype(*p1)>::type>v1, std::vector<typename std::remove_reference<decltype(*p1)>::type>v2){return ((v1[0]>v2[0]) || ((v1[0]==v2[0]) && v1[1]>v2[1]));});
	return povratna;
	}
	
template <typename Tip1, typename Tip2>
	auto UvrnutaRazlika (Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4)-> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
		Tip1 temp1(p1);
		Tip2 temp3(p3);
		std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>povratna;
		temp1=p1;
		temp3=p3;
		int k(0);
		while (temp1!=p2){
			temp3=p3;
			while(temp3!=p4){
				if (*temp1==*temp3)
					break;
				temp3++;
			}
			if (temp3==p4){
				povratna.resize(povratna.size()+1);
				povratna[k].resize(2);
				povratna[k][0]=*temp1;
				povratna[k][1]=0;
				k++;
			}
			temp1++;
		}
		temp1=p1;
		temp3=p3;
		while (temp3!=p4){
			temp1=p1;
			while(temp1!=p2){
				if (*temp1==*temp3)
					break;
				temp1++;
			}
			if (temp1==p2){
				povratna.resize(povratna.size()+1);
				povratna[k].resize(2);
				povratna[k][0]=*temp3;
				povratna[k][1]=0;
				k++;
			}
			temp3++;
		}
	sort (povratna.begin(),povratna.end(),[](std::vector<typename std::remove_reference<decltype(*p1)>::type>v1, std::vector<typename std::remove_reference<decltype(*p1)>::type>v2){return v1[0]>v2[0];});
	return povratna;
	}
int main ()
{
	int n1;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int>dek1;
	int pomocni,broj(0);
	for (int i=0;i<n1;i++){
		std::cin>>pomocni;
		broj=0;
		for (int j=0;j<dek1.size();j++){
			if (pomocni==dek1[j]){
				i--;
				break;
			}
			broj++;
		}
		if (broj==dek1.size()){
			dek1.push_back(pomocni);
		}
	}
	broj=0;
	int n2;
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int> dek2;
	for (int i=0;i<n2;i++){
		std::cin>>pomocni;
		broj=0;
		for (int j=0;j<dek2.size();j++){
			if (pomocni==dek2[j]){
				i--;
				break;
			}
			broj++;
		}
		if (broj==dek2.size()) 
			dek2.push_back(pomocni);
	}
	
	std::vector<std::vector<int>> presjek(UvrnutiPresjek(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),SumaCifara));
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for (int i=0;i<presjek.size();i++){
			std::cout<<std::setw(6)<<presjek[i][0]<<std::setw(7)<<presjek[i][1]<<std::setw(7)<<presjek[i][2];
			std::cout<<std::endl;
	}
	
	std::vector<std::vector<int>>razlika(UvrnutaRazlika(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),BrojProstihFaktora));
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	for (int i=0;i<razlika.size();i++){
			std::cout<<std::setw(6)<<razlika[i][0]<<std::setw(7)<<razlika[i][1];
			std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}