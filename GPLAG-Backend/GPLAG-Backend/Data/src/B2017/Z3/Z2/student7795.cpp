/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <iterator>

typedef std::tuple<std::string, int, int> DATA;
typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::vector<DATA>> Pojmovi;
typedef std::map<std::string, bool> Rijeci;

/*   function to return lowercased string      */
auto StringToLower = [](std::string _input) {
     std::transform(_input.begin(), _input.end(), _input.begin(), ::tolower);
     return _input;
};
/*   function to print word data in a specific format    */
void PrintData(const DATA& _data, std::string _end = "") {
     std::cout << std::get<0>(_data) << "/" << std::get<1>(_data) << "/" << std::get<2>(_data) << _end;
}
/*   create map of unique words in a string       */
Rijeci StringToUniqueWords(const std::string& input) {
	Rijeci output;
	int len(0), start(0);
	bool _set (false);
	for(int i (0); i < input.length(); ++i) {
		if(!std::isalnum(input.at(i))) {
			if(_set) {
			     output[StringToLower(input.substr(start, len))] = true;
				_set = false;
			}
		}
		else if(!_set) {
			_set 	= true;
			start 	= i;
			len 		= 0;
		} 
		len++;
	}
	if(_set) output[StringToLower(input.substr(start, len))] = true;
	return output;
}
/*                            */
/*   functions to implement   */
/*                            */
Pojmovi KreirajIndeksPojmova(const Knjiga& _book) {
     Pojmovi _outputMap;
     for(const auto& _chapter : _book) {
          int _naStranici(1);
          /*   search for unique words      */
          for(auto _page : _chapter.second) {
               Rijeci _uniqueWords (StringToUniqueWords(_page = StringToLower(_page)));
               /*   start adding of each     */
               for(const auto& _word : _uniqueWords) {
                    std::vector<DATA> _data;
                    size_t _pos (_page.find(_word.first, 0));
                    for(;_pos != std::string::npos;) {
                         _data.push_back(std::make_tuple(_chapter.first, _naStranici, _pos));
                         _pos = _page.find(_word.first, _pos+1);
                    }
                    // check if the given word exists
                    if(_outputMap.find(_word.first) == _outputMap.end())
                         _outputMap.insert(std::make_pair(_word.first, _data));
                    else 
                         std::copy(_data.begin(), _data.end(), std::back_inserter(_outputMap[_word.first]));
               }
               ++_naStranici;
          }
     }
     return _outputMap;
}
/*   search map for a specific term     */
std::vector<DATA> PretraziIndeksPojmova(std::string _word, const Pojmovi& _phrases) {
     _word = StringToLower(_word); 
     if(_phrases.find(_word) == _phrases.end()) 
          throw std::logic_error("Pojam nije nadjen");
          
     return _phrases.at(_word); /// [] - not working for const map (due to the ability to edit map)
}

/*   print all phrases/termps      */
void IspisiIndeksPojmova(const Pojmovi& _phrases) {
     for(const auto& _data : _phrases) {
          std::cout << StringToLower(_data.first) << ": ";
          for(int i (0); i < _data.second.size() - 1; ++i)
               PrintData(_data.second.at(i), ", ");
          if(!_data.second.empty())
               PrintData(_data.second.at(_data.second.size() - 1));
          std::cout << std::endl;
     }
}

/*   main program logic  */
int main () {
     // input
     Knjiga ulaz;
     for(;;) {
          int _page (1);
          std::string _chapter;
          std::vector<std::string> _pages;
          std::cout << "Unesite naziv poglavlja: "; std::cin >> _chapter;
          std::cin.ignore(10000, '\n');
          if(_chapter == ".") break;
          
          for(;;) {
               std::string _pageText;
               std::cout << "Unesite sadrzaj stranice " << _page++ << ": "; getline(std::cin, _pageText);
               if(_pageText == ".") break;
               _pages.push_back(_pageText);
          }
          ulaz[_chapter] = _pages; 
     }
     
     // print
     Pojmovi _pojmovi(KreirajIndeksPojmova(ulaz));
     std::cout << std::endl << "Kreirani indeks pojmova: " << std::endl;
     IspisiIndeksPojmova(_pojmovi);
     
     // search
     for(;;) {
          std::string _word, _check;
          std::cout << std::endl << "Unesite rijec: "; getline(std::cin, _word);
          std::copy_if(_word.begin(), _word.end(), std::back_inserter(_check), [](const char& _c) { return _c != ' '; });
          if(_check == ".") break;
          
          try {
               std::vector<DATA> _searched (PretraziIndeksPojmova(_word, _pojmovi));
               for(const auto& _data : _searched)
                    PrintData(_data, " ");
          }
          catch (std::logic_error) {
               std::cout << "Unesena rijec nije nadjena!";
          } 
          catch (std::exception &e) {
               std::cout << "Izuzetak: " << e.what();
          }
     }
	return 0;
}