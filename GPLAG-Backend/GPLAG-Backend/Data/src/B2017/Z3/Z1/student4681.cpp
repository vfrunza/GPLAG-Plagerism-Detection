/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <sstream>
#include <functional>
#include <cmath>

double fac(double x) {
    return pow(x,2) + sin(x);
}

bool krajcheck(std::string kraj) {
    for(int i = 0; i < kraj.size(); i++) 
        if((kraj.at(i) < 48 || kraj.at(i) > 57) && kraj.at(i) != '.') 
        return false;
    return true;
}

double interpolation(double yi, double xi, double yi1, double xi1, double x) {
    return yi + ((float)(yi1-yi) / (float)(xi1-xi)) * (x - xi);
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<int, int>> nodes) {
    
        //vector sort(x) 
        for(int i = 0; i < nodes.size(); i++)
            for(int j = i; j < nodes.size(); j++) 
                if(std::get<0>(nodes.at(i)) > std::get<0>(nodes.at(j))) {
                    std::sort(nodes.begin(), nodes.end());
                    break;
                } else if(i != j && std::get<0>(nodes.at(i)) == std::get<0>(nodes.at(j))) throw std::domain_error("Neispravni cvorovi");
    
    return [=] (double x) -> double {
        //check x with nodes
        if(x < std::get<0>(nodes.at(0)) || x > std::get<0>(nodes.at(nodes.size()-1))) throw std::range_error("Argument izvan opsega");
        //find suitable points
        for(int i = 1; i < nodes.size(); i++)
            if(x >= std::get<0>(nodes.at(i-1)) && x < std::get<0>(nodes.at(i)))
                return interpolation(std::get<1>(nodes.at(i-1)), std::get<0>(nodes.at(i-1)), std::get<1>(nodes.at(i)), std::get<0>(nodes.at(i)), x);
            return (double)std::get<1>(nodes.at(nodes.size()-1));
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> function, double min, double max, double step) {
    if(min > max || step <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<double> nodes, nodesX;
    for(int i = 0;;i++) {
        double current = function(min + i*step), currentX = min + i * step;
        if(current >= max) {
            nodes.push_back(max);
            nodesX.push_back(max);
            break;
        }
        nodes.push_back(current);
        nodesX.push_back(currentX);
    }
    return [nodes, nodesX, function] (double x)  -> double {
        if(x < nodesX.at(0) || x > nodesX.at(nodes.size()-1)) throw std::range_error("Argument izvan opsega");
        for(int i = 1; i < nodes.size(); i++)
            if(x >= nodesX.at(i - 1) && x < nodesX.at(i)) 
                return interpolation(nodes.at(i-1), nodesX.at(i-1), nodes.at(i), nodesX.at(i), x);
        return function(x);
    };
}

int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int sta;
    std::cin >> sta;
    std::string kraj;
    std::function<double(double)> f;
    if(sta == 1) {
        std::cout << "Unesite broj cvorova: ";
        int nodesize;
        std::cin >> nodesize;
        std::cout << "Unesite cvorove kao parove x y: ";
        std::vector<std::pair<int, int>> nodes;
        for(int i = 0; i < nodesize; i++) {
            std::pair<int, int> node;
            std::cin >> std::get<0>(node) >> std::get<1>(node);
            nodes.push_back(node);
        }
        try { f = LinearnaInterpolacija(nodes); } catch(std::domain_error e) {std::cout << e.what() << std::endl; return 0;} 
            catch(std::range_error e) {std::cout << e.what() << std::endl; return 0;} 
        
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        
        for(;;) {
            std::cout << "Unesite argument (ili \"\kraj\"\ za kraj): ";
            std::getline(std::cin, kraj);
            if(krajcheck(kraj)) try { std::cout << "f("<< std::stod(kraj) << ") = " << f(std::stod(kraj)) << std::endl; }
            catch(std::domain_error e) {std::cout << e.what() << std::endl;} 
            catch(std::range_error e) {std::cout << e.what() << std::endl;} 
            else return 0;
        }
    } else if(sta == 2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        double min, max, del;
        std::cin >> min >> max >> del;
        
        try { f = LinearnaInterpolacija([](double x) {return std::pow(x,2) + std::sin(x);}, min, max, del); } catch(std::domain_error e) {std::cout << e.what() << std::endl; return 0;} 
            catch(std::range_error e) {std::cout << e.what() << std::endl; return 0;} 
        
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        
        for(;;) {
            std::cout << "Unesite argument (ili \"\kraj\"\ za kraj): ";
            std::getline(std::cin, kraj);
            if(krajcheck(kraj)) try { std::cout << "f("<< std::stod(kraj) << ") = " << fac(std::stod(kraj))
            << " fapprox(" << std::stod(kraj) << ") = " << f(std::stod(kraj)) << std::endl; } catch(std::domain_error e) {std::cout << e.what() << std::endl;} 
            catch(std::range_error e) {std::cout << e.what() << std::endl;}  
            else return 0;
        }
    }
    
	return 0;
}
