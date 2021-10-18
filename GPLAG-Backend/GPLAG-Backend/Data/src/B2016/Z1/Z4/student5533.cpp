#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cctype>

typedef long long ll;

int find(std::string a, std::string b, int idx = 0) {
	if (b.size() + idx > a.size()) return -1;
	
	for (int i = idx; i + b.size() <= a.size(); i++) {
		bool isti = true;
		
		for (int j = 0; j < b.size(); j++) {
			isti &= a[i + j] == b[j];
			if (!isti) break;
		}
		
		if (isti) return i;
	}
	
	return -1;
}

std::string ObrniFraze(std::string str, std::vector<std::string> fraze) {
	for (int i = 0; i < fraze.size(); i++) {
		int st(0);
		
		while ((st = find(str, fraze[i], st)) != -1) {
			int en = st + fraze[i].size() - 1;
			for(int j = 0; j < fraze[i].size() / 2; j++) {
				char tmp = str[st + j];
				str[st + j] = str[en - j];
				str[en - j] = tmp;
			}
			st++;
		}
	}
	
	return str;
}

bool unutra(std::vector<std::string>* rijeci, std::string str) {
	for(int i = 0; i < rijeci->size(); i++) {
		if ((*rijeci)[i] == str) return true;
	}
	
	return false;
}

std::string IzmijeniUPigLatin(std::string str, std::vector<std::string> rijeci) {
	for (int i = 0; i < rijeci.size(); i++)
		for (int j = 0; j < rijeci[i].size(); j++)
			if (!std::isalpha(rijeci[i][j])) throw std::domain_error("Nekorektan izbor rijeci");
			
	//std::sort(rijeci.begin(), rijeci.end()); // izmijeni jer nije radjeno
	
	int i(0);
	while(i < str.size()) {
		while(!std::isalpha(str[i]) && i < str.size()) i++;
		if (i >= str.size()) break;
		
		int prev(i);
		std::string tmp;
		while(std::isalpha(str[i]) && i < str.size()) tmp += str[i++];
		
		if (rijeci.empty()) {
			str = str.substr(0, prev) + str.substr(prev + 1, i - prev - 1) + str[prev] + "ay" + str.substr(i); 
			i += 3;
		}
		//else if (std::binary_search(rijeci.begin(), rijeci.end(), tmp)) {
		else if (unutra(&rijeci, tmp)) {
			str = str.substr(0, prev) + str.substr(prev + 1, i - prev - 1) + str[prev] + "ay" + str.substr(i);
			i += 3;
		}
	}
	
	return str;
}

int main () {
	std::cout << "Unesite recenicu: ";
	
	std::string str;
	std::getline(std::cin, str);
	
	std::cout << "Unesite fraze: ";
	std::string tmp;
	std::vector<std::string> fraze;
	
	while(std::getline(std::cin, tmp)) {
		fraze.push_back(tmp);
	}
	
	try {
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(str, fraze) << std::endl;
	}
	catch(std::domain_error e) {
		std::cout << "Izuzetak: " << e.what() << std::endl;
	}
	
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(str, fraze) << std::endl;
	
	return 0;
}