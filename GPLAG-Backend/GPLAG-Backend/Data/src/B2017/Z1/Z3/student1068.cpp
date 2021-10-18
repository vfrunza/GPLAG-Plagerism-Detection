#include <iostream>
#include <vector>
#include <deque>

typedef std::vector<int> vInt;
typedef std::deque<vInt> dvInt;
enum Smjer{Rastuci, Opadajuci};

bool isPowerOfTwo(int n)
{
	if (n <= 0)
		return false;
		
	return (n & (n - 1)) == 0;
}

dvInt MaksimalniPodnizoviStepenaDvojke(vInt array, Smjer direction)
{
	dvInt sequences;
	if (array.size() == 0)
		return sequences;
	
	if (direction == Rastuci)
	{
		for (int i(0); i < array.size() - 1; i++)
			if (isPowerOfTwo(array.at(i)) && (isPowerOfTwo(array.at(i + 1)) && array.at(i + 1) >= array.at(i)))
			{
				vInt new_sequence;
				new_sequence.push_back(array.at(i));
				new_sequence.push_back(array.at(i + 1));
				i += 2;
				while (i < array.size() && isPowerOfTwo(array.at(i)) && array.at(i) >= array.at(i - 1))
					new_sequence.push_back(array.at(i++));
				i--;
				
				sequences.push_back(new_sequence);
			}
	}
	else if (direction == Opadajuci)
	{
		for (int i(0); i < array.size() - 1; i++)
			if (isPowerOfTwo(array.at(i)) && (isPowerOfTwo(array.at(i + 1)) && array.at(i + 1) <= array.at(i)))
			{
				vInt new_sequence;
				new_sequence.push_back(array.at(i));
				new_sequence.push_back(array.at(i + 1));
				i += 2;
				while (i < array.size() && isPowerOfTwo(array.at(i)) && array.at(i) <= array.at(i - 1))
					new_sequence.push_back(array.at(i++));
				i--;
					
				sequences.push_back(new_sequence);
			}
	}
	
	return sequences;
}

int main(void)
{
	int n_elements;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n_elements;
	
	int n;
	vInt input_sequence;
	std::cout << "Unesite elemente vektora: ";
	for (int i(0); i < n_elements; i++)
	{
		std::cin >> n;
		input_sequence.push_back(n);
	}
	
	int direction_n;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> direction_n;
	
	Smjer direction;
	if (direction_n == 1)
	{
		std::cout << "Maksimalni rastuci podnizovi:\n";
		direction = Rastuci;
	}
	else if (direction_n == 2)
	{
		std::cout << "Maksimalni opadajuci podnizovi:\n";
		direction = Opadajuci;
	}
	
	dvInt sequences(MaksimalniPodnizoviStepenaDvojke(input_sequence, direction));
	for (int i(0); i < sequences.size(); i++)
	{
		for (int j(0); j < sequences.at(i).size(); j++)
			std::cout << sequences.at(i).at(j) << " ";
			
		std::cout << std::endl;
	}
	
	return 0;
}