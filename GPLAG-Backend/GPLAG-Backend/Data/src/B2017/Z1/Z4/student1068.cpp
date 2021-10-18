#include <iostream>
#include <string>
#include <vector>
#include <cctype>

bool isIndependentWord(std::string s, int begin, int end)
{
	if (begin > 0 && end < s.size() - 1 && (isalpha(s.at(begin - 1)) || isalpha(s.at(end + 1))))
		return false;
	else if (begin == 0 && end == s.size() - 1)
		return true;
	else if (begin == 0 && isalpha(s.at(end + 1)))
		return false;
	else if (end == s.size() - 1 && isalpha(s.at(begin - 1)))
		return false;
	
	return true;
}

int findMatch(std::string sentence, std::vector<std::string> target_words, int *i, int *current_word)
{
	int len(0);
	while (len < target_words.at(*current_word).size() && *i < sentence.size())
	{
		if (sentence.at(*i) == target_words.at(*current_word).at(len))
		{
			len++;
			(*i)++;
		}
		else
		{
			(*i) -= len;
			break;
		}
	}
	
	return len;
}
	
std::string NapraviPalindrom(std::string sentence, std::vector<std::string> target_words)
{
	for (int current_word(0); current_word < target_words.size(); current_word++)
	{
		for (int i(0); i < sentence.size(); i++)
		{
			int len(findMatch(sentence, target_words, &i, &current_word));
			if (len == target_words.at(current_word).size() && isIndependentWord(sentence, i - len, i - 1))
			{
				int p(sentence.size() - 1);
				sentence.resize(sentence.size() + len);
				for (; p >= i; p--)
					sentence.at(p + len) = sentence.at(p);
				
				for (int e(target_words.at(current_word).size() - 1); e >= 0; e--, i++)
					sentence.at(i) = target_words.at(current_word).at(e);
			}
		}
	}
	
	return sentence;
}
 
std::string NapraviPoluPalindrom(std::string sentence, std::vector<std::string> target_words)
{
	for (int current_word(0); current_word < target_words.size(); current_word++)
	{
		for (int i(0); i < sentence.size(); i++)
		{
			int len((findMatch(sentence, target_words, &i, &current_word)));
			if (len == target_words.at(current_word).size() && isIndependentWord(sentence, i - len, i - 1))
				for (int j(i - len), e(i - 1); j < e; j++, e--)
						sentence.at(e) = sentence.at(j);
		}
	}
	
	return sentence;
}	
	
int main (void)
{
	std::string sentence, temp;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, sentence);
	
	std::vector<std::string> target_words;
	std::cout << "Unesite fraze: ";
	while (std::getline(std::cin, temp))
	{
		if (!temp.empty())
			target_words.push_back(temp);
		if (std::cin.peek() == '\n')
			break;
	}
	
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(sentence, target_words)
			  << "\nRecenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(sentence, target_words);
	
	return 0;
}