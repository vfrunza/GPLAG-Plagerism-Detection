/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>
#include <algorithm>


using std::cout;
using std::cin;
using std::vector;

bool Savrsen(long long int x){
	int suma(0);
	for(long long int i=1;i<x;i++)
		if(x%i == 0)
			suma += i;
	if(suma == x) return true;
	return false;
}
int SumaDjelilaca(long long int x){
	int suma(0);
	for(long long int i=1; i < x+1; i++)
		if(x%i == 0)
			suma += i;
	return suma;
}
int BrojProstihFaktora(long long int x){
	int br(0);
//	bool lo(true);
	for(long long int i=2; i <= x; i++){
		if(x%i == 0){
			br++;
			x = x/i;
			i = 1;
		}
	}
	return br;
}
int BrojSavrsenihDjelilaca(long long int x){
	int br(0);
	for(long long int i=1; i < x+1; i++)
		if(x%i == 0 && Savrsen(i))
			br++;
	return br;
}
int SumaCifara(long long int x){
	int suma(0);
	int cifra;
	while(x!=0){
		cifra = x%10;
		suma+=cifra;
		x/=10;
	}
	return suma;
}

template <typename IterTip1, typename IterTip2, typename Tip1, typename Tip2>
auto UvrnutiPresjek(IterTip1 p1, IterTip1 p2, IterTip2 q1, IterTip2 q2, Tip1 (*fun)(Tip2)) ->  vector<vector<typename std::remove_reference<decltype(p1[0])>::type>>{
	vector<vector<typename std::remove_reference<decltype(p1[0])>::type>> mat;
	vector<typename std::remove_reference<decltype(p1[0])>::type> pomocni(3);
	for(int i=0;i<p2-p1;i++){
		for(int j=0;j<q2-q1;j++){
			if(fun(p1[i]) == fun(q1[j])){
				pomocni = {p1[i], q1[j], fun(p1[i])};
				mat.push_back(pomocni);
				}
			}
		}
	std::sort(mat.begin(), mat.end(), [] (vector<typename std::remove_reference<decltype(p1[0])>::type> x1,	vector<typename std::remove_reference<decltype(p1[0])>::type> x2) -> bool{
				if(x1[2] < x2[2])
					return true;
				return false;
	} 	
	);
	std::sort(mat.begin(), mat.end(), [] (vector<typename std::remove_reference<decltype(p1[0])>::type> x1,	vector<typename std::remove_reference<decltype(p1[0])>::type> x2) -> bool{
				if(x1[2] == x2[2] && x1[0] < x2[0])
					return true;
				return false;
	} 	
	);
	std::sort(mat.begin(), mat.end(), [] (vector<typename std::remove_reference<decltype(p1[0])>::type> x1,	vector<typename std::remove_reference<decltype(p1[0])>::type> x2) -> bool{
				if(x1[2] == x2[2] && x1[0] == x2[0] && x1[1] < x2[1])
					return true;
				return false;
	} 	
	);
		return mat;
	}
	
template <typename IterTip1, typename IterTip2>
auto UvrnutiPresjek(IterTip1 p1, IterTip1 p2, IterTip2 q1, IterTip2 q2) ->  vector<vector<typename std::remove_reference<decltype(p1[0])>::type>>{
	vector<vector<typename std::remove_reference<decltype(p1[0])>::type>> mat;
	vector<typename std::remove_reference<decltype(p1[0])>::type> pomocni(3);
	for(int i=0;i<p2-p1;i++){
		for(int j=0;j<q2-q1;j++){
			if(p1[i] == q1[j]){
				pomocni = {p1[i], 0, 0};
				mat.push_back(pomocni);
				}
			}
		}
	return mat;
	}

template <typename IterTip1, typename IterTip2, typename Tip1, typename Tip2>
auto UvrnutaRazlika(IterTip1 p1, IterTip1 p2, IterTip2 q1, IterTip2 q2, Tip1 (*fun)(Tip2)) ->  vector<vector<typename std::remove_reference<decltype(p1[0])>::type>>{
	vector<vector<typename std::remove_reference<decltype(p1[0])>::type>> mat;
	vector<typename std::remove_reference<decltype(p1[0])>::type> pomocni(2);
	bool lo;
	for(int i=0;i<p2-p1;i++){
		lo = true;
		for(int j=0;j<q2-q1;j++)
			if(fun(p1[i]) == fun(q1[j]))
					lo = false;
					
		pomocni = {p1[i], fun(p1[i])};
		if(lo) mat.push_back(pomocni);		
	}
	for(int i=0;i<q2-q1;i++){
		lo = true;
		for(int j=0;j<p2-p1;j++)
			if(fun(q1[i]) == fun(p1[j]))
					lo = false;
					
		pomocni = {q1[i], fun(q1[i])};
		if(lo) mat.push_back(pomocni);		
	}
	std::sort(mat.begin(), mat.end(), [] (vector<typename std::remove_reference<decltype(p1[0])>::type> x1,	vector<typename std::remove_reference<decltype(p1[0])>::type> x2) -> bool{
				if(x1[0] > x2[0])
					return true;
				return false;
	} 	
	);
	std::sort(mat.begin(), mat.end(), [] (vector<typename std::remove_reference<decltype(p1[0])>::type> x1,	vector<typename std::remove_reference<decltype(p1[0])>::type> x2) -> bool{
				if(x1[0] == x2[0] && x1[1] > x2[1])
					return true;
				return false;
	} 	
	);
	return mat;
		
	}	

int main ()
{
	int brel, x;
	std::deque<int> dek1;
	std::deque<int> dek2;
	cout << "Unesite broj elemenata prvog kontejnera: ";
	cin >> brel; 
	cout << "Unesite elemente prvog kontejnera: "; 
	for(int i=0;i<brel;i++){ 
		cin >> x; 
		if(std::count(dek1.begin(), dek1.end(), x) == 0)
			dek1.push_back(x);
		else brel++;
	} 
	cout << "Unesite broj elemenata drugog kontejnera: "; 
	cin >> brel; 
	cout << "Unesite elemente drugog kontejnera: ";  
	for(int i=0;i<brel;i++){ 
		cin >> x;
		if(std::count(dek2.begin(), dek2.end(), x) == 0)
			dek2.push_back(x);
		else brel++;
	}
 	vector<vector<int>> mat(UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara));
 	cout << "Uvrnuti presjek kontejnera: \n";
 	for(int i=0;i<mat.size();i++){
 		for(int j=0;j<mat[i].size();j++){
 			cout << std::setw(6) << std::right << mat[i][j] << " ";
 		}
 		cout << "\n";
 	}
 	mat = UvrnutaRazlika(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), BrojProstihFaktora);
 	cout << "Uvrnuta razlika kontejnera: \n";
 	for(int i=0;i<mat.size();i++){
 		for(int j=0;j<mat[i].size();j++){
 			cout << std::setw(6) << std::right << mat[i][j] << " ";
 		}
 		cout << "\n";
 	}
 	cout << "Dovidjenja!";
	return 0;
}