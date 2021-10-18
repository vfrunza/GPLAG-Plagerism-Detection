#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Mat;
Mat OgledaloMatrica(Mat m) {
    for(std::vector<double> red : m)
        if(m[0].size()!=red.size()) throw std::domain_error("Matrica nije korektna");
    if(m.size()==0) return m;
    Mat m2(3*m.size(), std::vector<double> (3*m[0].size()));
    Mat h_m(m.size()), v_m(m.size()), hv_m(m.size());
    
    for(int i(m.size()-1), k(0); i>=0 and k<m.size(); i--, k++)
            for(int j(0); j<m[k].size(); j++)
                v_m[k].push_back(m[i][j]);
    
    for(int i(0); i<m.size(); i++)
        for(int j(m[i].size()-1); j>=0; j--)
            h_m[i].push_back(m[i][j]);
            
    for(int i(m.size()-1), k(0); i>=0 and k<m.size(); i--, k++)
        for(int j(m[i].size()-1); j>=0; j--)
            hv_m[k].push_back(m[i][j]);
            
    for(int i(0); i < m2.size(); i++) {
        for(int j(0); j < m2[0].size(); j++) {
            
            if(i<m.size() and j<m[0].size()) {                                                  // hv(M)
                m2[i][j]=hv_m[i][j];
            } else if(i<m.size() and j>=2*m[0].size()) {
                m2[i][j]=hv_m[i][j-2*m[0].size()];
            } else if(i>=2*m.size() and j<m[0].size()) {
                m2[i][j]=hv_m[i-2*m.size()][j];
            } else if(i>=2*m.size() and j>=2*m[0].size())
                m2[i][j]=hv_m[i-2*m.size()][j-2*m[0].size()];
            
            if(i>=m.size() and i<2*m.size() and j>=m[0].size() and j<2*m[0].size())             // M
                m2[i][j]=m[i-m.size()][j-m[0].size()];
                
            if((i>=m.size() and i<2*m.size()) and j<m[0].size()) {                              // h(M)
                m2[i][j]=h_m[i-m.size()][j];
            } else if(i>=m.size() and i<2*m.size() and j>=2*m[0].size())
                m2[i][j]=h_m[i-m.size()][j-2*m[0].size()];
            
            if(i<m.size() and j>=m[0].size() and j<2*m[0].size()) {                             // v(M)
                m2[i][j]=v_m[i][j-m[0].size()];
            } else if(i>=2*m.size() and j>=m[0].size() and j<2*m[0].size())
                m2[i][j]=v_m[i-2*m.size()][j-m[0].size()];
        }
    }
    return m2;
}

int main () {
    try {
        int m, n;
        std::cout << "Unesite dimenzije matrice (m n): ";
        std::cin >> m >> n;
        if(m<0 or n<0) {
            std::cout << "Dimenzije matrice moraju biti nenegativne!";
            return 0;
        }
        Mat a(m, std::vector<double>(n));
        std::cout << "Unesite elemente matrice: ";
        for(int i(0); i<a.size(); i++)
            for(int j(0); j<a[i].size(); j++)
                std::cin >> a[i][j];
        Mat b(OgledaloMatrica(a));
        std::cout << std::endl;
        std::cout << "Rezultantna matrica: ";
        std::cout << std::endl;
        for(auto red : b) {
            for(auto x : red)
                std::cout << std::setw(4) << x;
                std::cout << std::endl;
        }
    }
	catch(std::domain_error a) {
	    std::cout << a.what() << std::endl;
	}
	return 0;
}