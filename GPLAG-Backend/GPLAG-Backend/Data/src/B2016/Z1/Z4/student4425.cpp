#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
// 2/19 fail.
// 1 memory error, 1 wrong result 
// wr: new line should be added out of exception msg like std::endl, exception msg should be exact & intact
// me: dunno
bool IsItALetter(char a) {
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')) return true;
	else return false;
}

std::string ObrniFraze(std::string sentence, std::vector<std::string> phrases) {
	if (sentence.length()==0) return sentence;
	//
	/*bool valid(false);
	for (int i = 0; i < sentence.length(); i++) {
		if (IsItALetter(sentence[i])) {
			valid = true;
			break;
		}
	}
	if (!valid) return sentence;
	*/
	int num_of_phrases(phrases.size()), sentence_len(sentence.size());
	for (int i = 0; i < num_of_phrases; i++) {
		std::string a_phrase(phrases[i]);
		int a_phrase_len(a_phrase.size());
		
		if (a_phrase_len > sentence.size()) continue; //genius...
		
		for (int j = 0; j < sentence_len - a_phrase_len+1; j++) { //+1 (29.3)
			std::string potential_substring(sentence.substr(j, a_phrase_len));
			//std::cout << potential_substring << "@@" << a_phrase << "@@" << std::endl; ////
			if (potential_substring == a_phrase) {
				//reverse
				for (int k = 0; k < (a_phrase_len) / 2; k++) {
					char tmp = sentence[j+k];
					sentence[j+k] = sentence[j+a_phrase_len-1-k];
					sentence[j+a_phrase_len-1-k] = tmp;
				}
				//
			}
		}
	}
	return sentence;
}

std::string IzmijeniUPigLatin(std::string sentence, std::vector<std::string> words) {
	if (sentence.length()==0) return sentence;
	//
	bool valid(false);
	for (int i = 0; i < sentence.length(); i++) {
		if(IsItALetter(sentence[i])) {
			valid = true;
			break;
		}
	}
	
	
	bool allwords(false);
	std::vector<std::string> empty;
	
	if (words.size()==0) {
		//sve riječi
		allwords=true;
		int woerter(0);
		//prebroji rijeci
		bool IsSeparator(true);
		for (int i = 0; i < sentence.length(); i++) {
			if (!((sentence[i]>='A' && sentence[i]<='Z') || (sentence[i]>='a' && sentence[i]<='z'))) IsSeparator = true;
			else if (IsSeparator) {
				IsSeparator = false;
				int start = i;
				while (((sentence[i]>='A' && sentence[i]<='Z')||(sentence[i]>='a' && sentence[i]<='z')) && i < sentence.length()) i++;
				std::string add_word = sentence.substr(start, i-start);
				//std::cout << "Word added >>" << add_word << "<<" << std::endl; //////////////////////////////////////////////
				words.resize(woerter+1);
				words[woerter] = add_word;
				woerter++;
				i--;
			}
		}
		
		goto idiuelse;
		
	} else {
		idiuelse: 
		//provjeri uslov za riječi
		for (int i = 0; i < words.size(); i++) {
			std::string s=words[i];
			for (int j = 0; j < words[i].size(); j++) {
				if (!((s[j] >= 'A' && s[j] <='Z') || (s[j] >= 'a' && s[j] <='z'))) throw std::domain_error("Nekorektan izbor rijeci\n");
			}
		}
		
		if (!valid) return sentence;
		
		for (int i = 0; i < words.size(); i++) {
			std::string a_word(words[i]);
			int a_word_len(a_word.size());
			
			if (a_word_len > sentence.size()) continue;
			
			for (int j = 0; j < sentence.size()-a_word_len; j++) {
				std::string potential_word(sentence.substr(j, a_word_len));
					std::string space(" "), before(" "), after(" ");
					
					if (j==0) {
						after[0] = sentence[j+a_word_len];
						if (IsItALetter(after[0])) continue; //nije rijec;
					} else {
						before[0] = sentence[j-1];
						after[0] = sentence[j+a_word_len];
						//std::cout << "before >>" << before << "   after >>" << after << std::endl;
						if (IsItALetter(after[0]) || IsItALetter(before[0])) continue; //nije rijec
					}
					
					//std::cout << ">>>>>>>" << potential_word << "<<<<<<<"<< a_word << "!!!" << sentence.size() << std::endl;///////////////////////////
				if (potential_word == a_word) {
					//piglatiniziraj riječ
					std::string first_letter("X");
					first_letter[0] = sentence[j];
					std::string tmp = sentence.substr(j+1, a_word_len-1) + first_letter + "ay";
					//std::cout << "prije:" << sentence.size() << std::endl; ///////////////////////////////
					for (int k = 0; k < a_word_len; k++) {
						sentence.erase(sentence.begin()+j);
						//std::cout << "brisanje " << k+1 << " :" << sentence.size() << std::endl;
					}
					for (int k = 0; k < tmp.size(); k++) {
						sentence.insert(sentence.begin()+j+k, tmp[k]);
						//std::cout << "dodavanje " << k+1 << " :" << sentence.size() << std::endl;
					}
				}
				
				//
			}
		}
		
		//posljednja rijec - 'cause it doesn't fit to the above alg.
		//if (words.size()!=0) {
			int end = sentence.length()-1;
			while (!((sentence[end]>='A' && sentence[end]<='Z') || (sentence[end]>='a' && sentence[end]<='z'))) end--;
			int start = end;
			while (((sentence[start]>='A' && sentence[start]<='Z') || (sentence[start]>='a' && sentence[start]<='z'))) start--;
			start++;
			std::string forcheck = sentence.substr(start, end-start+1);
			//int last_position = words.size() - 1;
			//std::cout << forcheck<< words[last_position] << std::endl; //////////////////////////////
			
			for (int s = 0; s < words.size(); s++) {
				if (forcheck == words[s]) {
					std::string foradd = sentence.substr(start+1, end-start+1) + sentence[start] + "ay";
					for (int k = 0; k < foradd.size()-2; k++) sentence.erase(sentence.begin()+start);
					for (int k = 0; k < foradd.size(); k++) sentence.insert(sentence.begin()+start+k, foradd[k]);
					break;
				}
			}
		//}
	}
	if (allwords) words = empty;
	return sentence;
}

int main () {
	
	std::cout << "Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	
	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze, empty;
	
	int brojac(0);
	while(1) {
		std::string tmp, empt;
		std::getline(std::cin, tmp);
		if (tmp[0]=='\n' || tmp.size()==0) {
			std::getline(std::cin, tmp);
			if (tmp[0]=='\n' || tmp.size()==0) break;
			else {
				brojac++;
				fraze.resize(brojac);
				fraze[brojac-1]=tmp;
				tmp=empt;
			}
		} else {
			brojac++;
			fraze.resize(brojac);
			fraze[brojac-1]=tmp;
			tmp=empt;
		}
	}
	
	try {
		std::string trans1(IzmijeniUPigLatin(recenica, fraze));
		std::cout << "Recenica nakon PigLatin transformacije: " << trans1 << std::endl;
	} catch(std::domain_error err) {
		std::cout << "Izuzetak: " << err.what();
	}
	
	std::string trans2(ObrniFraze(recenica, fraze));
	std::cout << "Recenica nakon obrtanja fraza: " << trans2;
	
	return 0;
}