#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int n) {
    std::vector<std::set<std::string>> timovi;
    if(n < 1 || n > djeca.size()) throw std::domain_error("Razvrstavanje nemoguce");
    return timovi;
}

int main ()
{
	return 0;
}