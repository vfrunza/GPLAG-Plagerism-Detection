/*	ADDING HOTFIXES | TESTED LOCALLY	*/
#include <iostream>
#include <stdexcept>
#include <complex>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <limits>
#include <cstdlib>

// 	Types for output	//
enum class CustomException 	{TackaEx, PoljeEx, PotezEx};
enum class InputType 		{None, Text, Number, Empty, Mine, Field};

enum class Status 			{NijeKraj, KrajPoraz, KrajPobjeda};
enum class Smjerovi 		{GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Polje 			{Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Komande 			{PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};
enum class KodoviGresaka 	{PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
//	Types of Inputs, Errors and a bit of everythings	//
std::vector<std::string> 	MOVE_TYPE 		{"GL", "G", "GD", "D", "DoD", "Do", "DoL", "L"};
std::vector<std::string> 	INPUT_COMMANDS 	{"P1", "P>", "B", "D", "PO", "Z", "K"};
std::vector<InputType> 		INPUT_VALUE_TYPE 	{InputType::Text, InputType::Number, InputType::Number, InputType::Number, 
											InputType::Empty, InputType::Empty, InputType::Empty};
std::vector<Komande> 		INPUT_COMMAND_TYPE 	{Komande::PomjeriJednoMjesto, Komande::PomjeriDalje, Komande::Blokiraj, Komande::Deblokiraj, 
											Komande::PrikaziOkolinu, Komande::ZavrsiIgru, Komande::KreirajIgru};
std::vector<std::string> 	GRESKE_TEXT {
	"Nerazumljiva komanda!", 
	"Komanda trazi parametar koji nije naveden!", 
	"Zadan je suvisan parametar nakon komande!",
	"Parametar komande nije ispravan!"
};
using Tabla 		= 	std::vector<std::vector<Polje>>;
using Red 		=	std::vector<Polje>;
struct Tacka	{int x, y; };
constexpr int SIZE_CHECK_MATRIX {1};
/*	Lambda one-liners 	*/
bool PointInTable	(const Tacka &t, const int &x, const int &y) { return (t.x >= 0 && t.y >= 0 && t.x < x && t.y < y); }
bool PointInTable	(const Tacka &t, const Tabla &polja) { return (t.x >= 0 && t.y >= 0 && t.x < polja.size() && t.y < polja.at(t.x).size()); }
auto clearMatrix 	= 	[](Tabla &polja) {std::fill(polja.begin(), polja.end(), Red(polja.size(), Polje::Prazno));};
auto PrijaviGresku 	= 	[](const KodoviGresaka &greska) -> void {std::cout << GRESKE_TEXT.at(static_cast<int>(greska) - static_cast<int>(KodoviGresaka::PogresnaKomanda)) << std::endl; };
auto CharNotDigit	= 	[](const char &c) { return !std::isdigit(c); };
auto isStrNumber	=	[](const std::string &str) -> bool { return (!str.empty() && (std::find_if(str.begin(), str.end(), CharNotDigit) == str.end())); };
auto TekucaPozicija = 	[](const int &x, const int &y) -> void {std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")\n";};
auto RetEmptyCode 	= 	[](KodoviGresaka &kod) -> bool { kod = KodoviGresaka::SuvisanParametar; return false; };
void finishGame(Tabla &polja) {
	clearMatrix(polja);
	throw std::runtime_error("Igra zavrsena");
}
bool printExitValues(Tabla &polja, Status _value) {
	if (_value == Status::KrajPoraz) std::cout << "Nagazili ste na minu" << std::endl;
	else if (_value == Status::KrajPobjeda) std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
	else return false;
	finishGame(polja);
	return true;
}
/*	function to convert string to number	*/
bool StrToNumber(const std::string &str, int &outputNum) {
	if(((str.at(0) == '-' && isStrNumber(str.substr(1))) ||  isStrNumber(str)) 
		&& str.length() < 14 && str.length() > 0) {
		long num(std::atol(str.c_str()));
		
		if (static_cast<long>(std::numeric_limits<int>::max()) >= num) {
			outputNum = static_cast<int>(num);
			return true;
		}
	}
	return false;
}
/*		USER DEFINED FUNCTIONS 			*/
/* 		increase enum field value 		*/
template <typename IEnumType>
inline void IncreaseEnumValue(IEnumType &_field, const IEnumType &upperBound, int _value = int()) {
	_field = static_cast<IEnumType>((std::abs(static_cast<int>(_field) + _value)) % (static_cast<int>(upperBound) + 1));
}
/* 	check validity of table 		*/
bool LegalnaTabla(const Tabla &polja) {
	size_t dimenzija {polja.size()};
	for(auto red:polja) 
		if(red.size() != dimenzija) 
			return false;
	return true;
}
/* 	custom exception handling 	*/
void Exception(const Tabla &polja, const int &x, const int &y, CustomException _value = CustomException::TackaEx) {
	switch(_value) {
		case CustomException::TackaEx: 
			if(!PointInTable({x, y}, polja))	 	throw std::domain_error(std::string{"Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji"});
		break;
		case CustomException::PoljeEx:
			if(!LegalnaTabla(polja))				throw std::domain_error("Ilegalna velicina polja");
		break;		
		case CustomException::PotezEx:
			if(!PointInTable({x, y}, polja))	 	throw std::out_of_range("Izlazak van igrace table");
		break;
	}
}
/* 	function to sum number of mines around (x,y) location 	*/
int 	SumBySizeField(const Tabla &polja, const int &x, const int &y) {
	int _suma {0};
	for(int i{x-SIZE_CHECK_MATRIX}; i <= x+SIZE_CHECK_MATRIX; ++i)
		for(int j{y-SIZE_CHECK_MATRIX}; j <= y+SIZE_CHECK_MATRIX; ++j)
			if((i != x || j != y) && PointInTable({ i, j }, polja) 
				&& (polja.at(i).at(j) == Polje::Mina)) 
				++_suma;
	return _suma;
}
/* 	function to get words from given string 	*/
/* 	funkcija zapravo pretvori 	*/
std::vector<std::string> StringToWords(std::string input) {
	std::vector<std::string> output{};
	size_t size{0}, len{0}, start{0};
	bool _set {false};
	for(int i{0};i < input.length(); ++i) {
		if(isspace(input.at(i))) {
			if(_set) {
				if(size++ < 3) output.push_back(input.substr(start, len));
				else {
					input.erase(input.begin(), input.begin() + start); 
					output.push_back(input); 
					return output; 
				} 
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
	if(_set && size <= 3) output.push_back(input.substr(start, len));
	return output;
}
/* 	print specific matrix 	*/
template <typename T>
void printTable(const std::vector<std::vector<T>> &polja){
   	for(auto red:polja) {
     	for(auto clan:red) std::cout << int(clan) << " ";
          std::cout << std::endl;
     }
}
/*	function to read valid number		*/
template <typename T, typename funkT>
void UnosBroja(std::string promptText, std::string errorMessage, InputType type, 
			funkT checkFunction, bool &checkValue, T upperBound,
		 	T &var1, T &var2) {
		 		
     std::cout << promptText;
     for(;;) {
	     std::string input;
	     getline(std::cin, input);
	     if(type == InputType::Field) {
	     	std::vector<std::string> words = StringToWords(input);
		     int _num (0);
		     if(words.size() != 1 || !StrToNumber(words.at(0), _num) || _num <= 0)
		     	std::cout << errorMessage << std::endl << promptText;
		     else {
	     		var1 = _num;
	     		checkValue = true;
	     		return;
		     }
	     }
	     else if(type == InputType::Mine) {
	     	char charCheck {'\0'};
	     	int INPUT_NUM {std::sscanf(input.c_str(), "(%d,%d) %c", &var1, &var2, &charCheck)};
		     if(input != "." && ((INPUT_NUM != 2 && INPUT_NUM != 3)  || int(charCheck) != 0 || 
		     		!checkFunction(var1) || !checkFunction(var2) || var1 >= upperBound || var2 >= upperBound || var1 < 0 || var2 < 0)) {
		     	std::cout << errorMessage << std::endl;
		     } 
		     else {
			     if(input == ".") checkValue = true;
			     return;
		     }
	     }
     }
}
/*									*/
/* 	Minesweeper functions to implement 	*/
/*									*/
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	// error check		//
	if (std::find_if(mine.begin(), mine.end(), [](const std::vector<int> &mina) { return mina.size() != 2; }) != mine.end())
		throw std::domain_error("Ilegalan format zadavanja mina");
	if (std::find_if(mine.begin(), mine.end(), [n](const std::vector<int> &mina) { return !PointInTable({ mina.at(0), mina.at(1) }, n, n); }) != mine.end())
		throw std::domain_error("Ilegalne pozicije mina");
	if(n <= 0) 	
		throw std::domain_error("Ilegalna velicina");
	// 	initialise table	//
	Tabla outputField;
	try { outputField = Tabla(n, Red(n, Polje::Prazno)); }
	catch(...) { throw std::domain_error("Ilegalna velicina"); }
	// 	set values and return	//
	std::for_each(mine.begin(), mine.end(), [&outputField](const std::vector<int> &mina) {
		outputField.at(mina.at(0)).at(mina.at(1)) = Polje::Mina;	
	});
	return outputField;
}
/*	show surrouding function 	*/
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) { 
	std::vector<std::vector<int>> outputMatrix(3, std::vector<int>(3, 0));
	if (polja.empty()) return outputMatrix;
	Exception(polja, x, y, CustomException::TackaEx);
	// fill matrix with data	//
	for(int i{ x - SIZE_CHECK_MATRIX }; i <= x + SIZE_CHECK_MATRIX; ++i) {
		std::vector<int> tempRow(3, 0);
		for(int j{ y - SIZE_CHECK_MATRIX }; j <= y + SIZE_CHECK_MATRIX; ++j) 
			tempRow.at(std::abs(j - y + SIZE_CHECK_MATRIX)) = SumBySizeField(polja, i, j);
		outputMatrix.at(std::abs(i - x + SIZE_CHECK_MATRIX)) = tempRow;
	}
	return outputMatrix;
}
/*	block specific position	*/
void BlokirajPolje(Tabla &polja, int x, int y) {
	Exception(polja, x, y, CustomException::TackaEx);
	
	if(polja.at(x).at(y) >= Polje::BlokiranoPrazno) return;
	IncreaseEnumValue<Polje>(polja.at(x).at(y), Polje::BlokiranoMina, static_cast<int>(Polje::BlokiranoPrazno));
}
/*	unblock specific position	*/
void DeblokirajPolje(Tabla &polja, int x, int y) {
	Exception(polja, x, y, CustomException::TackaEx);
	
	if(polja.at(x).at(y) < Polje::BlokiranoPrazno) return;
	IncreaseEnumValue<Polje>(polja.at(x).at(y), Polje::BlokiranoMina, -static_cast<int>(Polje::BlokiranoPrazno));
}
/*	goto specific position on table with 5 parameters	*/
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	// 	handle exceptions
	Exception(polja, novi_x, novi_y, CustomException::PotezEx);
	if(polja.at(novi_x).at(novi_y) >= Polje::BlokiranoPrazno) 
		throw std::logic_error("Blokirano polje");
	// 	Exception(polja, x, y, CustomException::TackaEx); // CHECK IF REALLY NEEDED
	//	GameOver	//
	if(polja.at(novi_x).at(novi_y) == Polje::Mina) {
		clearMatrix(polja);
		return Status::KrajPoraz;
	}
	if (PointInTable({ x, y}, polja))
		polja.at(x).at(y) = Polje::Posjeceno;
	x = novi_x;
	y = novi_y;
	for(int i (0); i < polja.size(); ++i) 
		for(int j (0); j < polja.at(i).size(); ++j)
			if((i != x || j != y) && polja.at(i).at(j) == Polje::Prazno)
				return Status::NijeKraj;
	return Status::KrajPobjeda;
}
/* 	goto specific position on table with 4 parameters	*/
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	Tacka point ({x, y});
	if(smjer <= Smjerovi::GoreDesno) 									point.x += -1;
	else if(!(smjer == Smjerovi::Lijevo || smjer == Smjerovi::Desno)) 		point.x += 1;
	
	if(smjer >= Smjerovi::DoljeLijevo || smjer == Smjerovi::GoreLijevo)		point.y += -1;
	else if(!(smjer == Smjerovi::Gore || smjer == Smjerovi::Dolje)) 			point.y += 1;
	
	return Idi(polja, x, y, point.x, point.y);
}
/*	function to do certain command	*/
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int & y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	try {
		if(komanda == Komande::PomjeriJednoMjesto) {
			Status retCode (Idi(polja, x, y, p_smjer));		
			TekucaPozicija(x, y);
			printExitValues(polja, retCode);
		}
		else if(komanda == Komande::PomjeriDalje) {	
			Status retCode (Idi(polja, x, y, p_x, p_y));		
			TekucaPozicija(x, y);
			printExitValues(polja, retCode);
		}
		else if(komanda == Komande::Blokiraj)		BlokirajPolje(polja, p_x, p_y);
		else if(komanda == Komande::Deblokiraj)		DeblokirajPolje(polja, p_x, p_y);
		else if(komanda == Komande::PrikaziOkolinu)	printTable(PrikaziOkolinu(polja, x, y));
		else if(komanda == Komande::ZavrsiIgru) 	finishGame(polja);
		else if(komanda == Komande::KreirajIgru) {
			int n, _notdef;
			bool checkValue {false};
			std::vector<std::vector<int>> mine;
			
			UnosBroja<int>("Unesite broj polja: ", "Greska, unesite ponovo!", InputType::Field,
				[](int num) { return (num > 0); }, checkValue, std::numeric_limits<int>::max(), n, _notdef);
			
			checkValue = false;
			std::cout << "Unesite pozicije mina: ";
			for(;!checkValue;) {
				std::vector<int> par(2);
				UnosBroja<int>("", "Greska, unesite ponovo!", InputType::Mine,
					[](int num) { return (num >= 0); }, checkValue, n, par.at(0), par.at(1));
				if(!checkValue && std::find(mine.begin(), mine.end(), par) == mine.end()) 
					mine.push_back(par);
			}
			polja = KreirajIgru(n, mine);
			x = 0; y = 0;
		}
	}
	catch(std::runtime_error) { throw; }
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
/*	function to read user game command		*/
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string input;
	InputType _setType{InputType::None};
	
	std::getline(std::cin, input);
	std::vector<std::string> words = StringToWords(input);
	//	wrong command exception		//
	auto it = std::find(INPUT_COMMANDS.begin(), INPUT_COMMANDS.end(), words.at(0));
	if(it != INPUT_COMMANDS.end()) 	_setType = INPUT_VALUE_TYPE.at((it - INPUT_COMMANDS.begin()));
	else {
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	// 	missing parameter exception 	//
	if(words.size() == 1 && _setType != InputType::Empty) {
		greska = KodoviGresaka::NedostajeParametar;
		return false;
	}
	else if(_setType == InputType::Empty && words.size() > 1)	return RetEmptyCode(greska);
	// 	invalid parameter exception	//
	if(_setType == InputType::Text) {
		auto iter = std::find(MOVE_TYPE.begin(), MOVE_TYPE.end(), words.at(1));
		if(iter != MOVE_TYPE.end()) {
  			if(words.size() > 2) return RetEmptyCode(greska);
			smjer = static_cast<Smjerovi>((iter - MOVE_TYPE.begin()) + static_cast<int>(Smjerovi::GoreLijevo));
		}
		else {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
	}
	else if(_setType == InputType::Number) {
		int _checkNum[2];
		if(!StrToNumber(words.at(1), _checkNum[0]) || !StrToNumber(words.at(2), _checkNum[1])) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		else {
  			if(words.size() > 3) return RetEmptyCode(greska);
  			x = _checkNum[0];
  			y = _checkNum[1];
 		}
	}
	//	update the command 		//
	komanda = INPUT_COMMAND_TYPE.at(it - INPUT_COMMANDS.begin());
	return true;
}
/* main function logic */
int main () {
	Komande komanda;
	Smjerovi smjer;
	Tabla polja;
	int x{0}, y{0}, p_x{0}, p_y{0};
	KodoviGresaka greska;
	for(;;) {
		try {
			std::cout << "Unesite komandu: ";
			if(UnosKomande(komanda, smjer, p_x, p_y, greska))
				IzvrsiKomandu(komanda, polja, x, y, smjer, p_x, p_y);
			else PrijaviGresku(greska);
		}
		catch(std::runtime_error) {
			std::cout << "Dovidjenja!";
			return 0;
		}
		catch(...) {
			return -1;
		}
	}
	return 0;
}