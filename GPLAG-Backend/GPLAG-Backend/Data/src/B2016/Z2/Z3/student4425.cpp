#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <type_traits>
#include <cmath>

bool Prime (long long int n) { //ok
	if (n==2) return true;
	if (n<=1 || n%2==0) return false;
	for (int i = 3; i*i <= n; i++) if (n%i == 0) return false;
	return true;
}

int SumaCifara(long long int num) { //ok
	int sum(0);
	while(num!=0) {
		sum+=(std::abs(num%10));
		num/=10;
	}
	return sum;
}

int SumaDjelilaca(long long int num) { //ok
	int sum(0);
	for (int i = 1; i <= std::abs(num); i++) {
		if (num%i == 0) sum+=i;
		if (num == i) break;
	}
	return sum;
}

bool Perfect (long long int n) {
	int sum(0);
	for (int i = 1; i < n; i++) {
		if (n%i == 0) sum+=i;
		if (n-1==i) break;
	}
	return sum == n;
}

int BrojProstihFaktora(long long int num) { //ok
	if (num==0) return 0;
	int count(0);
	for (int i = 2; i <= num; i++) {
		if (num%i==0) {
			if (Prime(i)) {
				count++;
				long long int tmp(num);
				tmp/=i;
				if (tmp*i!=num) continue;
				while (tmp%i==0 && tmp!=0) {
					count++;
					long long int ltmp = tmp;
					tmp/=i;
					if (tmp*i!=ltmp) break;
				}
			}
		}
		if (i == num) break;
	}
	return count;
}

int BrojSavrsenihDjelilaca(long long int num) {
	if (num==0) return 0;
	int count(0);
	for (int i = 1; i <= num; i++) {
		if (num%i==0) {
			if (Perfect(i)) count++;
		}
		if (i==num) break;
	}
	return count;
}
template <typename Typ1, typename Typ2> 
	auto UvrnutiPresjek (Typ1 start1, Typ1 end1, Typ2 start2, Typ2 end2) -> std::vector<std::vector<typename std::remove_reference<decltype(*start1)>::type>> {
		typedef std::vector<std::vector<typename std::remove_reference<decltype(*start1)>::type>> Tip;
		typedef std::vector<typename std::remove_reference<decltype(*start1)>::type> Type;
		typedef typename std::remove_reference<decltype(*start1)>::type T1;
		Typ1 begin1(start1), finish1(end1);
		Typ2 begin2(start2), finish2(end2);
		Tip vrati;
		int vel(0);  
		
		while (start1!=end1) {
			T1 x = *start1;
			while (start2!=end2) {
				T1 y = *start2;
				if(x==y) {
					bool in(false);
					for (int i = 0; i<vel; i++) {
						if (vrati[i][0]==*start1 && vrati[i][1]==0 && vrati[i][2]==0) in = true;
					}
					if (!in) {
						vel++;
						vrati.resize(vel);
						vrati.at(vel-1).push_back(*start1);
						vrati.at(vel-1).push_back(0);
						vrati.at(vel-1).push_back(0);
					}
				}
				start2++;
			}
			start2=begin2;
			start1++;
		}
		
		std::sort(vrati.begin(), vrati.end(),
				  [] (Type val1, Type val2) {
				  	return val1[0] < val2[0];
				  });
		
		return vrati;
	}

template <typename Typ1, typename Typ2, typename T1, typename T2> 
	auto UvrnutiPresjek (Typ1 start1, Typ1 end1, Typ2 start2, Typ2 end2, T1 f(T2)) -> std::vector<std::vector<typename std::remove_reference<decltype(*start1)>::type>> {
		typedef std::vector<std::vector<typename std::remove_reference<decltype(*start1)>::type>> Tip;
		typedef std::vector<typename std::remove_reference<decltype(*start1)>::type> Type;
		Typ1 begin1(start1), finish1(end1);
		Typ2 begin2(start2), finish2(end2);
		
		Tip vrati;
		int vel(0);
		while (start1 != end1) {
			T1 x = f (*start1);
			while (start2!=end2) {
				T1 y = f(*start2);
				if (x == y) {
					
					bool in(false);
					for (int i = 0; i < vel; i++) {
						if (vrati[i][0]==*start1 && vrati[i][1]==*start2 && vrati[i][2]==x) in = true;
					}
					
					if (!in) {
						vel++;
						vrati.resize(vel);
						vrati.at(vel-1).push_back(*start1);
						vrati.at(vel-1).push_back(*start2);
						vrati.at(vel-1).push_back(x);
					}
				}
				start2++;
			}
			start2 = begin2;
			start1++;
		}
		
		std::sort(vrati.begin(), vrati.end(),
				  [] (Type val1, Type val2) {
				  	if (val1[2]!=val2[2]) return val1[2] < val2[2];
				  	else if(val1[0]!=val2[0]) return val1[0] < val2[0];
				  	else return val1[1] < val2[1];
				  });
		
		return vrati;
	}

template <typename Typ1, typename Typ2> 
	auto UvrnutaRazlika (Typ1 start1, Typ1 end1, Typ2 start2, Typ2 end2) -> std::vector<std::vector<typename std::remove_reference<decltype(*start1)>::type>> {
		typedef std::vector<std::vector<typename std::remove_reference<decltype(*start1)>::type>> Tip;
		typedef std::vector<typename std::remove_reference<decltype(*start1)>::type> Type;
		typedef typename std::remove_reference<decltype(*start1)>::type T1;
		Typ1 begin1(start1), finish1(end1);
		Typ2 begin2(start2), finish2(end2);
		
		Tip vrati;
		int vel(0);
		while (start1!=end1) {
			T1 x = *start1;
			while (start2!=end2) {
				T1 y = *start2;
				if (x==y) break;
				start2++;
			}
			if (start2==end2) {
				bool in(false);
					for (int i = 0; i < vel; i++) {
						if (vrati[i][0] == *start1 && vrati[i][1]==0) in = true;
					}
				if (!in) {
					vel++;
					vrati.resize(vel);
					vrati.at(vel-1).push_back(*start1);
					vrati.at(vel-1).push_back(0);
				}
			}
			
			start2 = begin2;
			start1++;
		}
		
		start1 = begin1; end1=finish1;
		start2 = begin2; end2=finish2;
		
		while (start2!=end2) {
			T1 x = *start2;
			while (start1!=end1) {
				T1 y = *start1;
				if (x==y) break;
				start1++;
			}
			if (start1==end1) {
				bool in(false);
					for (int i = 0; i < vel; i++) {
						if (vrati[i][0]==*start2 && vrati[i][1]==0) in=true;
					}
				if(!in) {
					vel++;
					vrati.resize(vel);
					vrati.at(vel-1).push_back(*start2);
					vrati.at(vel-1).push_back(0);
				}
			}
			start1 = begin1;
			start2++;
		}
		
		std::sort (vrati.begin(), vrati.end(), [] (Type val1, Type val2) {return val1[0]>val2[0];});
		return vrati;
	}

template <typename Typ1, typename Typ2, typename T1, typename T2>
	auto UvrnutaRazlika (Typ1 start1, Typ1 end1, Typ2 start2, Typ2 end2, T1 f(T2)) -> std::vector<std::vector<typename std::remove_reference<decltype(*start1)>::type>> {
		typedef std::vector<std::vector<typename std::remove_reference<decltype(*start1)>::type>> Tip;
		typedef std::vector<typename std::remove_reference<decltype(*start1)>::type> Type;
		Typ1 begin1(start1), finish1(end1);
		Typ2 begin2(start2), finish2(end2);
		
		Tip vrati;
		int vel(0);
		while (start1 != end1) {
			T1 x = f(*start1);
			while(start2!=end2) {
				T1 y = f(*start2);
				if (x == y) break;
				start2++;
			}
			if (start2==end2) {
				bool in(false);
					for (int i = 0; i < vel; i++) {
						if (vrati[i][0]==*start1 && vrati[i][1]==x) in = true;
					}
				
				if (!in) {
					vel++;
					vrati.resize(vel);
					vrati.at(vel-1).push_back(*start1);
					vrati.at(vel-1).push_back(x);
				}
			}

			start2 = begin2;
			start1++;
		}
		start1 = begin1; end1=finish1;
		start2 = begin2; end2=finish2;
		
		while (start2!=end2) {
			T1 x = f(*start2);
			while (start1!=end1) {
				T1 y = f(*start1);
				if (x==y) break;
				start1++;
			}
			if (start1==end1) {
				bool in(false);
					for (int i = 0; i < vel; i++) {
						if (vrati[i][0]==*start2 && vrati[i][1]==x) in = true;
					}
				if(!in) {
					vel++;
					vrati.resize(vel);
					vrati.at(vel-1).push_back(*start2);
					vrati.at(vel-1).push_back(x);
				}
			}
			start1 = begin1;
			start2++;
		}

		std::sort(vrati.begin(), vrati.end(),
				  [] (Type val1, Type val2) {
				  	if (val1[0]!=val2[0]) return val1[0]>val2[0];
				  	else return val1[1]>val2[1];
				  });
		
		return vrati;
		
	}
	
int main () {
	
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int n1;
	std::cin >> n1;
	std::deque<int> dek1(n1);
	std::cout << "Unesite elemente prvog kontejnera: ";
	for (int i = 0; i < n1; i++) {
		int tmp;
		std::cin>>tmp;
		bool in (false);
		for (int j = 0; j < i; j++) if (dek1.at(j)==tmp) {
			in = true;
			i--;
		}
		if (!in) dek1.at(i) = tmp;
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	int n2;
	std::cin >> n2;
	std::deque<int> dek2(n2);
	std::cout << "Unesite elemente drugog kontejnera: ";
	for (int i = 0; i < n2; i++) {
		int tmp;
		std::cin >> tmp;
		bool in(false);
		for (int j = 0; j < i; j++) if (dek2.at(j)==tmp) {
			in = true;
			i--;
		}
		if (!in) dek2.at(i) = tmp;
	}
	
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	auto presjek = UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara);
	for (int i = 0; i < presjek.size(); i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << std::setw(6) << presjek.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	auto razlika = UvrnutaRazlika(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), BrojProstihFaktora);
	for (int i = 0; i < razlika.size(); i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << std::setw(6) << razlika.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "Dovidjenja!";
	return 0;
}