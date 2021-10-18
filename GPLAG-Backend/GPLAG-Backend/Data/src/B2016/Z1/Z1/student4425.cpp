#include <iostream>
#include <vector>
#include <stdexcept>
//soIcantest
bool IsEvil(int num) {
	if (num == 0) return false;
	int count0(0), count1(0), count2(0), res(0);
	while (num != 0) {
		res = num % 3;
		if (res == 0) count0++;
		else if (res == 1 || res == -1) count1++;
		else if (res == 2 || res == -2) count2++;
		num /= 3;
	}
	int sum(count0 + count1 + count2);
	if (count0 % 2 == 0 && count1 % 2 == 0 && count2 % 2 == 0 && sum!=0) return true; //it's evil
	else if (
		(count1!=0 && count2!=0 && count0!=0 && count1%2==1 && count2%2==1 && count0%2==1) ||
		(count1==0 && count2!=0 && count0!=0 && count2%2==1 && count0%2==1) ||
		(count1!=0 && count2==0 && count0!=0 && count1%2==1 && count0%2==1) ||
		(count1!=0 && count2!=0 && count0==0 && count1%2==1 && count2%2==1) ||
		(count1==0 && count2==0 && count0!=0 && count0%2==1) ||
		(count1!=0 && count2==0 && count0==0 && count1%2==1) ||
		(count1==0 && count2!=0 && count0==0 && count2%2==1)
		) return false; //it's odious - like this condition >.<
	else throw std::domain_error("Nije ni evil ni odious!");
}

std::vector<int> IzdvojiGadne(std::vector<int> vec, bool evil) {
	std::vector<int> ItIsMeYouWant;
	for (int x : vec) {
		try {
			if (evil == IsEvil(x)) {
				bool IsIn(false);												 //or bool IsIn = false ?
				for (int y : ItIsMeYouWant) {
					if (y==x) {
						IsIn = true;
						break;
					}
				}
				if (!IsIn) ItIsMeYouWant.push_back(x);
			}
		}
		catch (...) {
			continue;
		}
	}
	return ItIsMeYouWant;
}

int main () {
	
	std::vector<int> vec;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for(;;) {
		int num;
		std::cin >> num;
		if (num == 0) break;
		else vec.push_back(num);
	}

	std::vector<int> opaki(IzdvojiGadne(vec, true)), odvratni(IzdvojiGadne(vec, false));
	
	std::cout << "Opaki: ";
	for (int x : opaki) std::cout << x << " ";
	std::cout << std::endl << "Odvratni: ";
	for (int x : odvratni) std::cout << x << " ";
	
	return 0;
}