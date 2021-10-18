#include <iostream>
#include <stdexcept>
template <typename Tip>
class GMatrica {
    Tip m[4][4];
    int br_redova, br_kolona;
public:
GMatrica (): br_redova(0),br_kolona(0){};
GMatrica(int x, int y, Tip a=Tip()){
    if(x<0 || y<0 || x>4 || y>4) throw std::logic_error("Ilegalan format matrice");
    br_redova=x;
    br_kolona=y;
    for (int i=0;i<x;i++)
    for (int j=0;j<y;j++)
    m[i][j]=a;
}

     
};
int main ()
{  try{GMatrica<int> m(4,4);}
catch(std::logic_error e){
    std::cout<<e.what();
    
}
	return 0;
}