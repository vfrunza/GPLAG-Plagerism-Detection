#include <iostream>
#include <vector>
#include <cmath>

// Less typing.
typedef std::vector<int> v_int;

bool isPrime(int n)
{
	if (n < 0)
		n = -n;
		
	if (n == 1 || n == 0)
		return false;
	
	for (int i(2); i <= std::sqrt(n); i++)
		if (n % i == 0)
			return false;
			
	return true;
}

v_int getTernaryRepresentation(int n)
{
	if (n < 0)
		n = -n;
	
	v_int ternary_representation;
	do
	{
		ternary_representation.push_back((n % 3));
		n /= 3;
	} while (n != 0);
	
	return ternary_representation;
}

bool isTernarySymmetrical(v_int ternary_representation)
{
	// One-digit numbers are given a default value of true.
	if (ternary_representation.size() == 1)
		return true;
	
	for (int i(0), j(ternary_representation.size() - 1); i < j; i++, j--)
			if (ternary_representation.at(i) != ternary_representation.at(j))
				return false;
	
	return true;
}

v_int IzdvojiSimetricneTernarne(v_int v, bool b)
{
	bool skip(false);
	v_int ternaries;
	
	for (int i(0); i < v.size(); i++)
	{
		// Checks for instances of the same number.
		for (int j(0); j < ternaries.size(); j++)
			if (v.at(i) == ternaries.at(j))
			{
				// The value at v[i] is one that has already been stored in the vector ternaries,
				// so, having no need to store it again, we set skip to "true", so that we might
				// skip to the next iteration of the for-loop, i.e. move on to the next integer candidate.
				skip = true;
				break;
			}
		
		if (skip)
		{
			skip = false;
			continue;
		}
		
		if (isTernarySymmetrical(getTernaryRepresentation(v.at(i))))
			if (b)
			{
				// Prime number case.
				if (isPrime(v.at(i)))
					ternaries.push_back(v.at(i));
			}
			else
			{
				// Composite number case.
				if (!isPrime(v.at(i)))
					ternaries.push_back(v.at(i));
			}	
	}
	
	return ternaries;
}

int main (void)
{
	int input;
	v_int v_input;
	
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	for (;;)
	{
		std::cin >> input;
		if (input == -1)
			break;
	
		v_input.push_back(input);
	}
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for (;;)
	{
		std::cin >> input;
		if (input != 0 && input != 1)
			std::cout << "Neispravan unos! Unesite ponovo: ";
		else
			break;
	}
	
	v_int v(IzdvojiSimetricneTernarne(v_input, input));
	if (v.size() == 0)
		std::cout << "Nema " << ((input) ? "prostih " : "slozenih ") << "simetricnih brojeva u vektoru.";
	else
	{
		if (input)
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
		else
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		
		for (int i(0); i < v.size(); i++)
				if (i == v.size() - 1)
					std::cout << v.at(i) << ".";
				else
					std::cout << v.at(i) << ", ";
	}
	
	return 0;
}