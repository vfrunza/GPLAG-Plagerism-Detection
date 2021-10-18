#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
#include <functional>
#include <exception>
#include <set>

// Some kinda useful macros (the C programmer in me will never die).
#define FIRST_POINT (points.begin())
#define LAST_POINT (points.end() - 1)
#define EPSILON 1e-10

// A single global variable to keep track of when the second function gets called.
bool secondFuncGotCalled(false);

// Used for comparing floating-point numbers.
bool areEqual(const double &x, const double &y) 
{
	if ((x < 0 && y > 0) || (x > 0 && y < 0))
		return false;
	
	return (std::fabs(x - y) <= EPSILON);
}

// The comp function that gets used in std::sort and elsewhere.
bool comp(const std::pair<double, double> &p1, const std::pair<double, double> &p2) 
{
	return (p1.first < p2.first && !areEqual(p1.first, p2.first)); 
}

// Test function, in this case it's y(x) = x^2 + sin(x).
double g(double x) 
{ 
	return x * x + std::sin(x); 
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> &points)
{
	// If the second funtion gets called, then we don't have to check for errors,
	// for we already know that the vector of points is competely valid, ie the 
	// elements are already sorted in ascending order and there are no duplicates.
	if (!secondFuncGotCalled)
	{
		// Check whether two or more points have the same x-coordinate.
		std::set<double> xCoordinates;
		for (int i(0); i < points.size(); i++)
			xCoordinates.insert(points.at(i).first);
		if (xCoordinates.size() != points.size())
			throw std::domain_error("Neispravni cvorovi\n");

		std::sort(points.begin(), points.end(), comp);
	}
	secondFuncGotCalled = false;

	// The function that does the actual interpolation.
	return [&points](double x)
	{
		// Special case.
		if (areEqual(x, LAST_POINT->first))
			return LAST_POINT->second;

		// Check whether X is in range.
		if ((x < FIRST_POINT->first && !areEqual(x, FIRST_POINT->first)) || x > LAST_POINT->first)
			throw std::range_error("Argument izvan opsega\n");

		std::vector<std::pair<double, double>>::iterator low, upp;
		low = std::lower_bound(points.begin(), points.end(), std::make_pair(x, 0.), comp);
		upp = std::upper_bound(points.begin(), points.end(), std::make_pair(x, 0.), comp);

		if (upp - low == 1)
			// This is the case in which X is equal to some X_i in the vector of points.
			return low->second;
		else if (upp - low == 0)
		{
			// This is the case in which X is inbetween some X_i and X_(i + 1) in the vector of points.
			low--;
			return (low->second + ((upp->second - low->second) / (upp->first - low->first)) * (x - low->first));
		}
	};
}

std::function<double(double)> LinearnaInterpolacija(double f(double), double min, double max, double delta)
{
	// Check whether the parameters are valid or not.
	if ((min > max && !areEqual(min, max)) || delta <= 0)
		throw std::domain_error("Nekorektni parametri\n");
	
	// Has to be static because it's gonna be passed by reference to the first function.
	static std::vector<std::pair<double, double>> points;
	for (int j(0); (min <= max || areEqual(min, max)); min += delta, j++)
		points.push_back(std::make_pair(min, f(min)));

	secondFuncGotCalled = true;
	return LinearnaInterpolacija(points);
}

int main(void)
{
	int option;
	std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
	std::cin >> option;

	int n;
	double min, max, delta;
	std::function<double(double)> f;
	std::vector<std::pair<double, double>> points;
	
	try
	{
		if (option == 1)
		{
			std::cout << "Unesite broj cvorova: ";
			std::cin >> n;
			points.resize(n);
			std::cout << "Unesite cvorove kao parove x y: ";
			for (int i(0); i < n; i++)
				std::cin >> points.at(i).first >> points.at(i).second;
			f = LinearnaInterpolacija(points);
		}
		else if (option == 2)
		{
			std::cout << "Unesite krajeve intervala i korak: ";
			std::cin >> min >> max >> delta;
			f = LinearnaInterpolacija(g, min, max, delta);
		}	
	}
	catch (std::domain_error d)
	{
		std::cout << d.what();
		return 1; 
	}

	for (;;)
	{
		double arg;
		std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
		std::cin >> arg;
		if (!std::cin)
			break;

		try
		{
			if (option == 1)
				std::cout << "f(" << arg << ") = " << f(arg) << std::endl;
			else if (option == 2)
				std::cout << "f(" << arg << ") = " << g(arg) << " fapprox(" 
				          << arg << ") = " << f(arg) << std::endl;
		}
		catch(std::range_error r)
		{
			std::cout << r.what();
		}
	}		

	return 0;
}