/*
    Mehrajul Islam
    SUST SWE 19
    2019831074
*/

#include <bits/stdc++.h>

using namespace std;

#define eps 0.00001

// used to sort the rows by the number of leading zeros in each step
void row_shift(vector<vector<double>> &mat)
{
    bool flag = 0;
    vector<int> zeros; // list of zeros
    int cnt = mat.size();
    /// making zero count array by iterating ~ For row shifting
    for (auto rows : mat)
    {
        cnt = 0;
        for (auto elements : rows)
        {
            if (fabs(elements) > eps)
                break;
            cnt++;
        }
        zeros.push_back(cnt);
    }

    /// row sorting or row shifting using bubble sort
    cnt = mat.size();
    for (int i = 0; i < cnt; i++)
    {
        for (int j = i + 1; j <= cnt; j++)
        {
            if (zeros[i] > zeros[j])
            {
                flag = 1; // using flag to track if any row is being shifted or not
                swap(zeros[i], zeros[j]);
                swap(mat[i], mat[j]);
            }
        }
    }
    // If any row shifting happens then printing the step
    if (flag)
    {
        cout << "\nROW SHIFTING :\n--------------------------------------------\n";
        for (auto lol : mat)
        {
            for (auto lool : lol)
                cout << lool << " ";
            cout << endl;
        }
        cout << "--------------------------------------------\n";
    }
}

void echelon(vector<vector<double>> &mat)
{
    double a, b;
    int cnt = mat.size();
    bool flag;

    row_shift(mat); // first of all sorting the rows before working

    /// collumn shifting and row reduction after sorting the row by number of zeros
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j <= cnt; j++)
        {
            // if any non-zero element is found we start working
            // we dont need to collumn shift because the matrix is already sorted in each step
            if (fabs(mat[i][j]) > eps)
            {
                flag = 0;
                a = mat[i][j]; // top element by which row reduction will happen
                for (int k = i + 1; k < cnt; k++)
                {
                    b = mat[k][j]; // bottom element by which row reduction will happen

                    // checking if the row reduction is needed or not
                    if (fabs(b) > eps)
                    {
                        flag = 1;
                        // doing row reduction by the top and bottom coefficint
                        for (int p = j; p <= cnt; p++)
                        {
                            mat[k][p] = (a * mat[k][p]) - (b * mat[i][p]);
                        }
                    }
                }

                // Printing the step
                if(flag){
                     cout << "\nRow Reduction\n--------------------------------------------\n";
                     for (auto lol : mat)
                     {
                         for (auto lool : lol)
                            cout << lool << " ";
                         cout << endl;
                     }
                    cout << "--------------------------------------------\n";
                }

                row_shift(mat);
                break;
            }
        }
    }
}

int main()
{
    int n;
    double x;

    cout << "Enter the dimention of the matrix  (n x n)" << endl;
    cout << "Enter the value of n : ";
    cin >> n;

    vector < vector < double > > mat(n);

    cout << "\n\tNow give a ( " << n << " x " << n+1 << " ) matrix : \n\n";

    // taking a n x (n+1) matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> x;
            mat[i].push_back(x);
        }
    }

    echelon(mat); // making echelon

    cout << "\nEchelon form\n--------------------------------------------\n";
    for (auto lol : mat)
    {
        for (auto lool : lol)
            cout << lool << " ";
        cout << endl;
    }
    cout << "--------------------------------------------\n";

    return 0;
}

/*
2 -1 3 15
4 -2 2 42
1 1 -1 9

1 2 3 1
4 5 6 2
7 8 9 3
*/
