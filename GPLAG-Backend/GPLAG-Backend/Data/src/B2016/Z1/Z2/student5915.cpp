#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica (Matrica a){
    for(int i = 1; i < a.size(); i++){
        if(a[0].size() != a[i].size())  throw std::domain_error("Matrica nije korektna");
        
    }
    Matrica h (a) , v, hv;
    Matrica b(a);
    b.resize(a.size() * 3);
    for(int i = 0; i < b.size(); i++)
        b[i].resize(a[0].size() * 3);
    if(a.size() == 0) return b;
    for(int i = 0; i < a.size(); i++){
        int br_kol(a.at(0).size() - 1);
        for(int j = 0; j < a.at(0).size(); j++){
            h[i][j] = a[i][br_kol];
            br_kol--;
        }
    }
    for(int i = a.size() - 1; i >= 0; i--){
        v.push_back(a[i]);
        hv.push_back(h[i]);
    }
    h.resize(b.size());
    v.resize(b.size());
    hv.resize(b.size());
    for(int i = 0; i < b.size(); i++){
        h[i].resize(b[i].size());
        v[i].resize(b[i].size());
        hv[i].resize(b[i].size());
    }
    
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a.at(0).size(); j++){
        h[i][j + a[0].size()] = h[i][j];
        h[i][j + 2 * a[0].size()] = h[i][j];
        h[i + a.size()][j] = h[i][j];
        h[i + 2 * a.size()][j] = h[i][j];
        h[i + a.size()][j + a[0].size()] = h[i][j];
        h[i + a.size()][j + 2 * a[0].size()] = h[i][j];
        h[i + 2 * a.size()][j + a[0].size()] = h[i][j];
        h[i + 2 * a.size()][j + 2 * a[0].size()] = h[i][j];
        
        v[i][j + a[0].size()] = v[i][j];
        v[i][j + 2 * a[0].size()] = v[i][j];
        v[i + a.size()][j] = v[i][j];
        v[i + 2 * a.size()][j] = v[i][j];
        v[i + a.size()][j + a[0].size()] = v[i][j];
        v[i + a.size()][j + 2 * a[0].size()] = v[i][j];
        v[i + 2 * a.size()][j + a[0].size()] = v[i][j];
        v[i + 2 * a.size()][j + 2 * a[0].size()] = v[i][j];
        
        hv[i][j + a[0].size()] = hv[i][j];
        hv[i][j + 2 * a[0].size()] = hv[i][j];
        hv[i + a.size()][j] = hv[i][j];
        hv[i + 2 * a.size()][j] = hv[i][j];
        hv[i + a.size()][j + a[0].size()] = hv[i][j];
        hv[i + a.size()][j + 2 * a[0].size()] = hv[i][j];
        hv[i + 2 * a.size()][j + a[0].size()] = hv[i][j];
        hv[i + 2 * a.size()][j + 2 * a[0].size()] = hv[i][j];
    }
    }
    
 for(int i = 0; i < b.size(); i++){
     for(int j = 0; j < b.at(0).size(); j++){
         if((i < a.size() || i >= 2 * a.size()) && (j < a[0].size() || j >= 2 * a[0].size())) 
         b[i][j] = hv[i][j];
         
         else if (j >= a[0].size() && j < 2 * a[0].size() && !(i >= a.size() && i < 2* a.size()))
         b[i][j] = v[i][j];
         
         else if (i >= a.size() && i < 2 * a.size() && !(j >= a[0].size() && j < 2 * a[0].size()))
         b[i][j] = h[i][j];
         
         else
         b[i][j] = a[i - a.size()][j - a[0].size()];
     }
 }
   return b; 
}

int main () {
  try{
    int m, n;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin >> m >> n;
    if(m < 0 || n < 0){
     std::cout << "Dimenzije matrice moraju biti nenegativne!";
       return 0;
    }
    Matrica a(m, std::vector<double>(n));
    std::cout << "Unesite elemente matrice: ";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
          std::cin >> a[i][j];
    }
    std::cout << std::endl << "Rezultantna matrica: "<< std::endl;
    Matrica b;
    b = OgledaloMatrica(a);
    for(int i = 0; i < b.size();i++){
        for (int j = 0; j < b[0].size(); j++){
            std::cout << std::setw(4) << b[i][j];
        }
        std::cout << std::endl;
    }
    
  }
  catch (std::domain_error izuzetak){
      std::cout << izuzetak.what() << std::endl;
  }
return 0;

}


















