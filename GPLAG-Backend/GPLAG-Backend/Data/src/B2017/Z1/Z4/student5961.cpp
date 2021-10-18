#include <iostream>
#include <string>
#include <vector>
#include <cctype>

/* user predefined */
using std::string;
using std::size_t;
using StrArr = std::vector<string>;

/* structure definition and condition */
struct locEdit {
     size_t pos;
     string word;
};

/* check if exists in array */
inline bool containsWord(const std::vector<locEdit> &zaProvjeru, const string &searchingWord) {
     for(size_t i{0}; i < zaProvjeru.size(); ++i)
          if(zaProvjeru.at(i).word == searchingWord)
               return true;
               
     return false;
}

/* reverse string */
string ObrniStringJerSigurnoNisamSmioKoristitiFunkcijuReverse(string input) {
     size_t j {input.length()-1}, i {0};
     char temp;
     for(;i < j;) {
          temp = input.at(i);
          input.at(i) = input.at(j);
          input.at(j) = temp;
          ++i;
          --j;
     }
     
     return input;
}

/* creating search function */
size_t TrazenjePodstringaJerNisamSmioKoristitiBiblotecnuFunkcijuFind(const string &text, 
          const string &param, size_t pos) {
               
     size_t index{string::npos};
     size_t currentPos{0};
     for(size_t i{pos}; i < text.length(); ++i) {
          if(text.at(i) == param.at(currentPos)) {
               if(currentPos == 0)
                    index = i;
               ++currentPos;
               
               if(currentPos == param.length())
                    return index;
          }
          else 
               currentPos = 0;
     }
     /* default output */
     return (string::npos);
}

/* replace part of string within a string */
void IzmjenaDijelaStringaJerNisamSmioKoristitiBibliotecnuFunkcijuReplace(string &input, size_t pos, 
          size_t len, const string &editStr) {
               
     for(size_t i {0}; i < len; i++)
          input.at(i+pos) = editStr.at(i); 
}

/* add string to a string */
void DodajStringUStringJerNisamSmioKoristitiBibliotecnuFunkcijuInsert(string &input, size_t pos, 
          const string &addStr) {
               
     string _cutted = input.substr(pos, input.length());
     input.resize(input.length() + addStr.length());
     
     IzmjenaDijelaStringaJerNisamSmioKoristitiBibliotecnuFunkcijuReplace(input, pos + addStr.length(), _cutted.length(), _cutted);
     IzmjenaDijelaStringaJerNisamSmioKoristitiBibliotecnuFunkcijuReplace(input, pos, addStr.length(), addStr);
}

/* sort an array from min to max */
void SortirajArrayJerPretpostavljamDaNeSmijemKoristitiNiFunkcijuSortIzAlgoritmBiblioteke(std::vector<locEdit> &inputArray) {
     if(inputArray.size() <= 1) return;
               
     locEdit temp;
     for(size_t i{0}; i < inputArray.size()-1; ++i) {
          for(size_t j{i+1}; j < inputArray.size(); ++j) {
               /* swap elements */
               if(inputArray.at(i).pos > inputArray.at(j).pos) {
                    temp = inputArray.at(i);
                    inputArray.at(i) = inputArray.at(j);
                    inputArray.at(j) = temp;
               }
          }
     } 
}

//////////////////////////////
/* kreiraj vektor strukturu */
std::vector<locEdit> createStructureVector(const string &inputStr, const StrArr &inputArray) {
     std::vector<locEdit> zaProvjeru;
     
     /* find all strings */
     for(int i{0}; i < inputArray.size(); ++i) {
          /* check if exists in vector struct */
          if(!containsWord(zaProvjeru, inputArray.at(i)) && inputArray.at(i).length() > 0) {
               /* search for matching */
               size_t pos{TrazenjePodstringaJerNisamSmioKoristitiBiblotecnuFunkcijuFind(inputStr, inputArray.at(i), 0)};
               
               bool _validity{false};
               size_t _newpos{0};
               for(;pos != string::npos;) {
                    
                    _validity = false;
                    _newpos = pos + inputArray.at(i).length();
                    
                    /* check if really a word | WORD SOMEWHERE IN THE MIDDLE OF TEXT, AT THE BEGGINING, OR AT THE END*/
                    if(pos > 0 && _newpos < inputStr.length()) {
                         if(!isalnum(inputStr.at(pos-1)) && !isalnum(inputStr.at(_newpos)))
                              _validity = true;
                    }
                    else if(pos == 0) {
                         if(_newpos < inputStr.length()) {
                              if(!isalnum(inputStr.at(_newpos)))
                                   _validity = true;
                         }
                         else _validity = true;
                    }
                    else {
                         if(!isalnum(inputStr.at(pos-1)))
                              _validity = true;
                    }
                    
                    if(_validity) zaProvjeru.push_back({pos, inputArray.at(i)}); // add to stack if really a word
                    pos = TrazenjePodstringaJerNisamSmioKoristitiBiblotecnuFunkcijuFind(inputStr, inputArray.at(i), pos+1);
               }
          }
     }
     
     /* sort structure by metaID / position */
     SortirajArrayJerPretpostavljamDaNeSmijemKoristitiNiFunkcijuSortIzAlgoritmBiblioteke(zaProvjeru);
     return zaProvjeru;
}

/* Napravi Palindrom funkcija */
string NapraviPalindrom(const string &inputStr, const StrArr &inputArray) {
     /* create vector string  */
     std::vector<locEdit> zaProvjeru{createStructureVector(inputStr, inputArray)};
 
     /* now start editing first string */
     string outputStr{inputStr};
     size_t _shift{0};
     string stringToAdd;
     for(size_t i{0}; i < zaProvjeru.size(); ++i) {
          _shift += zaProvjeru.at(i).word.length();
          stringToAdd = ObrniStringJerSigurnoNisamSmioKoristitiFunkcijuReverse(zaProvjeru.at(i).word);
          DodajStringUStringJerNisamSmioKoristitiBibliotecnuFunkcijuInsert(outputStr, zaProvjeru.at(i).pos + _shift, stringToAdd);
     }
     
     return outputStr;
}

/* Napravi PoluPalindrom funkcija */
string NapraviPoluPalindrom(const string &inputStr, const StrArr &inputArray) {
     /* create vector string  */
     std::vector<locEdit> zaProvjeru{createStructureVector(inputStr, inputArray)};
 
     /* now start editing first string */
     string outputStr{inputStr};
     int o{0};
     size_t _shift{0};
     
     for(size_t i{0}; i < zaProvjeru.size(); ++i) {
          string half {(zaProvjeru.at(i).word)};
          
          o = static_cast<int>(half.length() % 2);
          half = ObrniStringJerSigurnoNisamSmioKoristitiFunkcijuReverse(half.substr(0, half.length()/2));
          _shift = half.length();
     
          /* replace part of the string */
          IzmjenaDijelaStringaJerNisamSmioKoristitiBibliotecnuFunkcijuReplace(outputStr,
               zaProvjeru.at(i).pos + _shift + o, _shift, half); 
     }
      
     return outputStr;
}


/* main function */
int main () {
     /* input */
     string input;
     StrArr fraze;
     
     std::cout << "Unesite recenicu: ";
     getline(std::cin, input);
     std::cout << "Unesite fraze: ";
     string line;
     for(;;) {
          getline(std::cin, line);
          if(line.length() == 0) break;
          fraze.push_back(line);
     }
     
     /* output */
     std::cout << "Recenica nakon Palindrom transformacije: ";
     std::cout << NapraviPalindrom(input, fraze) << std::endl;
     
     std::cout << "Recenica nakon PoluPalindrom transformacije: ";
     std::cout << NapraviPoluPalindrom(input, fraze) << std::endl;
	return 0;
}