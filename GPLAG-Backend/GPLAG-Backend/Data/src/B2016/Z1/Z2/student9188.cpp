#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
using namespace std;

vector<vector<double>> Horizontalno(vector<vector<double>> mat)
{

    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[i].size()/2;j++)
        {
            double temp=mat[i][j];
            mat[i][j]=mat[i][mat[i].size()-1-j];
            mat[i][mat[i].size()-1-j]=temp;
        }

    }
    return mat;
}

vector<vector<double>> Vertikalno(vector<vector<double>>mat)
{

    for(int i=0;i<mat.size()/2;i++)
    {
        vector<double> temp=mat[i];
        mat[i]=mat[mat.size()-1-i];
        mat[mat.size()-1-i]=temp;
    }

    return mat;
}


vector<vector<double>> OgledaloMatrica(vector<vector<double>> mat)
{

         vector<vector<double>> H,V,O;
         vector<vector<double>> ExpMat(mat.size()*3,vector<double>(mat[0].size()*3));

           H=Horizontalno(mat);
           V=Vertikalno(mat);
           O=Vertikalno(Horizontalno(mat));

            for(int i=0;i<ExpMat.size();i++)
            {
                for(int j=0;j<ExpMat[i].size();j++)
                {
                    if(i<ExpMat.size()/3 && j<ExpMat[i].size()/3)
                        ExpMat[i][j]=O[i][j];
                    else if(i>ExpMat.size()/2 && j<ExpMat[i].size()/3)
                        ExpMat[i][j]=H[ExpMat.size()-1-i][j];
                    else if(i>ExpMat.size()/2 && j>mat.size()+ExpMat[i].size()/3)
                        ExpMat[i][j]=mat[ExpMat.size()-1-i][ExpMat[i].size()-1-j];
                    else if(i<ExpMat.size()/3 && j>mat.size()+ExpMat[i].size()/3)
                        ExpMat[i][j]=V[i][ExpMat[i].size()-1-j];
                    else if(i<ExpMat.size()/3 && (j>=ExpMat[i].size()/3 && j<=mat.size()+ExpMat[i].size()/3))
                        ExpMat[i][j]=O[i][mat.size()+ExpMat[i].size()/2-1-j];
                    else if(i>ExpMat.size()/3+1 && (j>=ExpMat[i].size()/3 && j<=mat.size()+ExpMat[i].size()/3))
                        ExpMat[i][j]=H[ExpMat.size()-1-i][mat.size()+ExpMat[i].size()/2-1-j];
                    else if(j<ExpMat[i].size()/3 && (i>=ExpMat.size()/3 && i<=mat.size()+ExpMat[i].size()/3))
                        ExpMat[i][j]=O[ExpMat.size()/2-i][j];
                    else if(j>mat.size()+ExpMat[i].size()/3 && (i>=ExpMat.size()/3 && i<=mat.size()+ExpMat[i].size()/3))
                       ExpMat[i][j]=V[ExpMat.size()/2-i][ExpMat[i].size()-1-j];
                    else ExpMat[i][j]=O[ExpMat.size()/2-i][mat.size()+ExpMat[i].size()/2-1-j];
                }
            }



    return ExpMat;
}

int main() {

        int Red,Kolone;

        cout<<"Unesite broj redova i kolona ";
        cin>>Red>>Kolone;

        vector<vector<double>> Mat(Red);



       for(int i=0;i<Mat.size();i++)
            Mat[i].resize(Kolone);


         for(int i=0;i<Mat.size();i++)
            {
                for(int j=0;j<Mat[i].size();j++)
                    {
                            cin>>Mat[i][j];
                    }
            }



        vector<vector<double>> EMat=OgledaloMatrica(Mat);

        for(int i=0;i<EMat.size();i++)
            {
                for(int j=0;j<EMat[i].size();j++)
                    {
                            cout<<EMat[i][j]<<" ";
                    }
                 cout<<endl;

            }

        return 0;
}

