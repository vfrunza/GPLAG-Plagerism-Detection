#include <iostream>
#include <deque>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <type_traits>

int SumaDjelilaca( long long int x){
	int suma(0);
	for(long long int i = 1; i <= x; i++){
		if(x%i == 0)
			suma += i;
	}
	return suma;
}
int SumaCifara(long long int x){
	int suma(0);
	while(x != 0){
		suma += x%10;
		x /= 10;
	}
	return suma;
}
int BrojProstihFaktora(long long int x){
	int num(0); long long int max(x);
	for(long long int i = 2; i < max; i++){
		long long int tmp = SumaDjelilaca(i);
		if(tmp == i + 1 && x%i == 0){
			num++;
			x /= i;
			i = 1;
		}
		if(i + 1 >= max){
			num++;
			break;
		}
		if(i>x) break;
		if( x == 2){
			num++;
			break;
		} 
		
	}
	return num;
}
int BrojSavrsenihDjelilaca(long long int x){
	long long int suma(0);
	for(long long int i = 1; i <= x; i++){
		if(SumaDjelilaca(i)-i == i && x%i == 0)
			suma++;
	}
	return suma;
}

int x(int y){
	return y;
}
template<typename t1, typename t2, typename ret, typename arg>
auto UvrnutaRazlika(t1 start1, t1 end1, t2 start2, t2 end2, ret f(arg) )->
std::vector<typename std::vector<typename std::remove_reference<decltype(*start1)>::type>>{
	typedef std::vector<typename std::remove_reference<decltype(*start1)>::type> array;
	std::vector<array> mat;
	array tmp;
	t2 iter2 = start2;
	t1 iter1 = start1;
	while(iter1 != end1){
		bool nema(true);
		while(iter2 != end2){
			if(f(*iter1) == f(*iter2))
				nema = false;
			iter2++;
		}
		if(nema){
			tmp.push_back(*iter1);
			tmp.push_back(f(*iter1));
			mat.push_back(tmp);
			tmp.resize(0);
		}
		iter2 = start2;
		iter1++;
	}
	iter2 = start2;
	 iter1 = start1;
	while(iter2 != end2){
		bool nema = true;
		while(iter1 != end1){
			if(f(*iter1) == f(*iter2))
				nema = false;
			iter1++;
		}
		if(nema){
			tmp.push_back(*iter2);
			tmp.push_back(f(*iter2));
			mat.push_back(tmp);
			tmp.resize(0);
		}
		iter2++;
		iter1 = start1;
	}
	std::sort(mat.begin(), mat.end(), [] (array x, array y){
		if(x[0] != y[0]) return x[0] > y[0];
		return x[1] > y[1];
	});
	return mat;
	
}

template<typename t1, typename t2, typename ret, typename arg>
auto UvrnutiPresjek(t1 start1, t1 end1, t2 start2, t2 end2, ret f(arg))->
std::vector<typename std::vector<typename std::remove_reference<decltype(*start1)>::type>>{
	typedef std::vector<typename std::remove_reference<decltype(*start1)>::type> array;
	std::vector<array> mat;
	array tmp;
	t1 iter1 = start1; t2 iter2 = start2;
	while(iter1 != end1){
		while(iter2 != end2){
				if(f(*iter1) == f(*iter2)){
					tmp.push_back(*iter1);
					tmp.push_back(*iter2);
					tmp.push_back(f(*iter1));
					mat.push_back(tmp); tmp.resize(0);
				}
			iter2++;
		}
		
		iter2 = start2;
		iter1++;
	}
	std::sort(mat.begin(), mat.end(), [] (array x, array y){
		if(x[2] != y[2]) return x[2] < y[2];
		if(x[0] != y[0]) return x[0] < y[0];
		return x[1] < y[1];
	});
	return mat;
}
template <typename odeargod>
odeargod vrati(odeargod x){
	return x;
}

template<typename t1, typename t2>
auto UvrnutiPresjek(t1 start1, t1 end1, t2 start2, t2 end2)->
std::vector<typename std::vector<typename std::remove_reference<decltype(*start1)>::type>>{
	typedef typename std::remove_reference<decltype(*start1)>::type primi;
	return UvrnutiPresjek(start1, end1, start2, end2, vrati<primi>);
}

bool vecIma(std::deque<int> &d, int x){
	for(int i = 0; i < d.size(); i++) if(d[i] == x) return true;
	return false;
}
int main2(){
	return 0;
}
int main(){
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int n,tmp;
	std::cin >> n;
	std::deque<int> v(n);
	std::cout << "Unesite elemente prvog kontejnera: ";
	for(int i = 0; i < n;)
		if(std::cin >> tmp, !vecIma(v,tmp)) v[i++] = tmp;
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n;
	std::deque<int> v2(n);
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i = 0; i < n; ) 
		if(std::cin >> tmp, !vecIma(v2,tmp)) v2[i++] = tmp;
	std::cout << "Uvrnuti presjek kontejnera:\n";
	auto blah(UvrnutiPresjek(v.begin(),v.end(),v2.begin(),v2.end() ,SumaCifara));
	for(int i = 0; i < blah.size(); i++){
		for(int j = 0; j < blah[i].size(); j++)
			std::cout << std::setw(6) << blah[i][j];
		std::cout << " " << std::endl;
	}
	//blah
	std::cout << "Uvrnuta razlika kontejnera:\n";
	blah = UvrnutaRazlika(v.begin(), v.end(), v2.begin(), v2.end(),BrojProstihFaktora);
	for(int i = 0; i < blah.size(); i++){
		for(int j = 0; j < blah[i].size(); j++)
			std::cout << std::setw(6) << blah[i][j];
		std::cout << " " <<  std::endl;
	}
	std::cout << "Dovidjenja!";
	return 0;
}