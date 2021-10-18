#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

using std::vector;

typedef vector<vector<double>> Matrica;

void Popuni(Matrica *m, Matrica n, int r, int c, int tip) {
    if (tip == 1) { /* h */
        for (int i = 0; i < n.size(); i++) {
            for (int j = 0; j < n[0].size() / 2; j++) {
                double tmp = n[i][j];
                n[i][j] = n[i][n[0].size() - j - 1];
                n[i][n[i].size() - j - 1] = tmp;
            }
        }
    }
    else if (tip == 2) { /* v */
        for (int i = 0; i < n.size() / 2; i++) {
            vector<double> tmp = n[i];
            n[i] = n[n.size() - i - 1];
            n[n.size() - i - 1] = tmp;
        }
    }
    else if (tip == 3) { /* hv */
         for (int i = 0; i < n.size(); i++) {
            for (int j = 0; j < n[0].size() / 2; j++) {
                double tmp = n[i][j];
                n[i][j] = n[i][n[0].size() - j - 1];
                n[i][n[0].size() - j - 1] = tmp;
            }
        }
        
        for (int i = 0; i < n.size() / 2; i++) {
            vector<double> tmp = n[i];
            n[i] = n[n.size() - i - 1];
            n[n.size() - i - 1] = tmp;
        }
    }
    
    for (int i = 0; i < n.size(); i++) {
        for (int j = 0; j < n[i].size(); j++) {
            (*m)[i + r][j + c] = n[i][j];
        }
    }
}

Matrica OgledaloMatrica(Matrica m) {
    if (m.size() == 0) return m;
    
	for(int i = 1; i < m.size(); i++)
	    if (m[i].size() != m[0].size()) throw std::domain_error("Matrica nije korektna");
	    
	Matrica r(m.size() * 3, vector<double>(m[0].size() * 3));
    
    Popuni(&r, m, 0, 0, 3);
    Popuni(&r, m, 0, m[0].size(), 2);
    Popuni(&r, m, 0, m[0].size() * 2, 3);
    Popuni(&r, m, m.size(), 0, 1);
    Popuni(&r, m, m.size(), m[0].size(), 0);
    Popuni(&r, m, m.size(), m[0].size() * 2, 1);
    Popuni(&r, m, m.size() * 2, 0, 3);
    Popuni(&r, m, m.size() * 2, m[0].size(), 2);
    Popuni(&r, m, m.size() * 2, m[0].size() * 2, 3);
    
    return r;
}

int main ()
{
    int r, c;
    std::cout << "Unesite dimenzije matrice (m n): ";
    std::cin >> r >> c;
    
    if (r < 0 || c < 0) {
        std::cout << "Dimenzije matrice moraju biti nenegativne!\n";
        return 0;
    }
    
    Matrica m(r, vector<double>(c));
    
    std::cout << "Unesite elemente matrice:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cin >> m[i][j];
        }
    }
    
    std::cout << "Rezultantna matrica:\n";
    Matrica smor = OgledaloMatrica(m);
    for (int i = 0; i < smor.size(); i++) {
        for (int j = 0; j < smor[i].size(); j++) {
            std::cout << std::setw(4) << smor[i][j];
        }
        std::cout << std::endl;
    }
    
	return 0;
}