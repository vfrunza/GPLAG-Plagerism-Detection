#include <iostream>
#include <vector>

using namespace std;

double IzracunajSumu(vector<vector<double>> mat,int p,int q,int br)
{
    double suma=0;
    if(p-br>0 && p+br<mat.size() && q-br>0 && q+br<mat[0].size())
        for(int i=p-br;i<=p+br;i++)
        {
            for(int j=q-br;j<=q+br;j++)
            {
                if(i!=p || j!=q)
                    suma+=mat[i][j];
            }
        }
    else return 0;

    return suma;

}

void PlaninaMatrice(vector<vector<double>> mat)
{

     for(int i=1;i<mat.size()-1;i++)
     {
        for(int j=1;j<mat[i].size()-1;j++)
        {


                 double suma=IzracunajSumu(mat,i,j,2)-IzracunajSumu(mat,i,j,1);
                 cout<<mat[i][j]<<"->"<<suma<<" ";



        }
        cout<<endl;
     }



}


int main()
{
    vector<vector<double>> mat={{0,0,0,15,12,6},{1,25,1,5,2,9},{1,1,20,15,10,5},{3,2,19,130,14,8},{90,6,20,12,17,2},{12,3,5,1,8,4}};

        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
                cout<<mat[i][j]<<" ";
            cout<<endl;
        }

    PlaninaMatrice(mat);

    return 0;
}