#include <iostream>
#include <string>
#include <vector>


std::string ObrniString(std::string s1)
{
	std::string s2;

	for(int i = s1.length() - 1; i >= 0; i--) {
		s2.push_back(s1.at(i));
	}

	return s2;
}

std::string NapraviPalindrom (std::string s, std::vector<std::string> v)
{
	std::string original_string = s;
	for(int i = 0; i < v.size(); i++) {
		std::string pomocni = v.at(i);

		for(int j = 0; j < original_string.length(); j++) {

			if(original_string.at(j) == pomocni.at(0)) {

				if(j != 0) {

					if(original_string.at(j-1) == ' ' &&
					        original_string.substr(j,pomocni.length()) == pomocni) {

						if((j+pomocni.length()) < original_string.length() - 1) {


							if(original_string.at(j+pomocni.length()) == ' ' ||
							        (original_string.at(j + pomocni.length()) < 'A' ||
							         (original_string.at(j + pomocni.length()) > 'Z' &&
							          original_string.at(j + pomocni.length()) < 'a') ||
							         original_string.at(j+pomocni.length()) > 'z')) {

								//POCETAK OBRADE
								original_string.insert(j+pomocni.length(),ObrniString(pomocni));
								j = j+pomocni.length();
								//KRAJ OBRADE
							}


						} else if(j + pomocni.length() == original_string.length()) {
							//POCETAK OBRADE
							original_string.insert(j + pomocni.length(), ObrniString(pomocni));
							j = j + pomocni.length();
							//KRAJ OBRADE
						}

					}

				} else {
					if(original_string.substr(j,pomocni.length()) == pomocni) {
						if(j+pomocni.length() < original_string.length() - 1 &&
						        original_string.at(j + pomocni.length()) == ' ') {
							//POCETAK OBRADE
							original_string.insert(j+pomocni.length(), ObrniString(pomocni));
							j = j+pomocni.length();
							//KRAJ OBRADE

						} else if(j + pomocni.length() == original_string.length() - 1) {
							//POCETAK OBRADE
							original_string.insert(j + pomocni.length(), ObrniString(pomocni));
							j = j + pomocni.length();
							//KRAJ OBRADE
						}

					}
				}
			}
		}
	}
	return original_string;
}

std::string NapraviPoluPalindrom (std::string s, std::vector<std::string> v)
{
	std::string original_string = s;

	for(int i = 0; i < v.size(); i++) {
		std::string pomocni = v.at(i);

		for(int j = 0; j < original_string.length(); j++) {
			if(original_string.at(j) == pomocni.at(0)) {

				if(j != 0) {

					if(original_string.at(j-1) == ' ' &&
					        original_string.substr(j,pomocni.length()) == pomocni) {

						if((j + pomocni.length()) < original_string.length() - 1) {

							if(original_string.at(j + pomocni.length()) == ' ' ||
							        (original_string.at(j + pomocni.length()) < 'A' ||
							         (original_string.at(j + pomocni.length()) > 'Z' &&
							          original_string.at(j + pomocni.length()) < 'a') ||
							         original_string.at(j + pomocni.length()) > 'z')) {

								//POCETAK OBRADE
								char *pocetak = &original_string.at(j);
								char *kraj = &original_string.at(j + pomocni.length() - 1);

								while(pocetak != kraj) {
									*kraj = *pocetak;
									pocetak++;
									if(pocetak == kraj) break;
									kraj--;
								}

								j = j + pomocni.length();
								//KRAJ OBRADE
							}

						} else if(j + pomocni.length() == original_string.length()) {
							//POCETAK OBRADE
							char *pocetak = &original_string.at(j);
							char *kraj = &original_string.at(j + pomocni.length() - 1);

							while(pocetak != kraj) {
								*kraj = *pocetak;
								pocetak++;
								if(pocetak == kraj) break;
								kraj--;
							}
							j = j + pomocni.length();
							//KRAJ OBRADE
						}


					}

				} else {
					if(original_string.substr(j,pomocni.length()) == pomocni) {
						if(j + pomocni.length() < original_string.length() - 1 &&
						        original_string.at(j + pomocni.length()) == ' ') {

							//POCETAK OBRADE

							char *pocetak = &original_string.at(j);
							char *kraj = &original_string.at(j + pomocni.length() - 1);

							while(pocetak != kraj) {
								*kraj = *pocetak;
								pocetak++;
								if(pocetak == kraj) break;
								kraj--;
							}
							j = j + pomocni.length();
							//KRAJ OBRADE

						} else if(j + pomocni.length() == original_string.length()) {
							//POCETAK OBRADE
							char *pocetak = &original_string.at(j);
							char *kraj = &original_string.at(j + pomocni.length() - 1);

							while(pocetak != kraj) {
								*kraj = *pocetak;
								pocetak++;
								if(pocetak == kraj) break;
								kraj--;
							}
							j = j + pomocni.length();
							//KRAJ OBRADE
						}
					}
				}
			}
		}
	}
	return original_string;
}

int main ()
{

	std::string recenica;
	std::vector<std::string> a;
	std::string str;


	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);

	std::cout << "Unesite fraze: ";

	while(1) {
		std::getline(std::cin, str);
		if(str.length() == 0) break;
		a.push_back(str);
	}

	std::string novi1 = NapraviPalindrom(recenica, a);

	std::cout << "Recenica nakon Palindrom transformacije: "<< novi1 << std::endl;

	std::string novi2 = NapraviPoluPalindrom(recenica, a);

	std::cout << "Recenica nakon PoluPalindrom transformacije: "<< novi2;


	return 0;
}