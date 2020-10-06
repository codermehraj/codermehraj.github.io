#include <bits/stdc++.h>

using namespace std;

int det(vector<vector<int>> MAT, int dimension)
{
    if (dimension == 2)
        return ((MAT[0][0] * MAT[1][1]) - (MAT[0][1] * MAT[1][0]));
    else
    {
        int ans = 0;
         vector<vector<int>> MATT;
        for (int i = 0; i < dimension; i++)
        {
            MATT.resize(dimension-1);
            for (int j = 1; j < dimension; j++)
            {
                for (int k = 0; k < dimension; k++)
                {
                    if (k == i)
                        continue;
                    else{
                        MATT[j - 1].push_back(MAT[j][k]);
                    }
                }
            }
            if (i % 2)
                ans -= MAT[0][i]*det(MATT, dimension - 1);
            else
                ans += MAT[0][i]*det(MATT, dimension - 1);
            MATT.clear();
        }
        return ans;
    }
}

int main()
{
    int n, x;

    cout << "Enter the dimention of the matrix  (n x n)" << endl;
    cout << "Enter the value of n : ";
    cin >> n;

    vector<vector<int>> mat(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            mat[i].push_back(x);
        }
    }

    cout << det(mat, n) << endl;

    return 0;
}
