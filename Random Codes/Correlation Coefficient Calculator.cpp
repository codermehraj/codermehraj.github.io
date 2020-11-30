#include<bits/stdc++.h>

using namespace std;

#define show(x) cout << #x << " = " << x << endl;

vector < double > X , Y;
int n;
double x, xbar, ybar, xiyi, xi2, yi2;

void cal_xbar(){
    double sum = 0;
    for(auto lol : X) sum += lol;
    xbar = sum / n;
}

void cal_ybar(){
    double sum = 0;
    for(auto lol : Y) sum += lol;
    ybar = sum / n;
}

void cal_xi_yi(){
    double sum = 0;
    for(int i=0;i<n;i++){
        sum += X[i]*Y[i];
    }
    xiyi = sum;
}

void cal_xi2(){
    double sum = 0;
    for(auto lol : X) sum += lol*lol;
    xi2 = sum;
}

void cal_yi2(){
    double sum = 0;
    for(auto lol : Y) sum += lol*lol;
    yi2 = sum;
}

double getCOV(){
    cal_xbar(); //show(xbar);
    cout << "\n\n\t Mean of x , Xbar = " << xbar << endl;
    cal_ybar(); //show(ybar);
    cout << "\t Mean of y , Ybar = " << ybar << endl;
    cal_xi_yi(); //show(xiyi);
    cout << "\t Sum of XiYi , " << (char)228 << "XiYi= " << xiyi << endl;
    cal_xi2(); //show(xi2);
    cout << "\t sum of Xi^2 , " << (char)228 << "(Xi^2) = " << xi2 << endl;
    cal_yi2(); //show(yi2);
    cout << "\t sum of Yi^2 , " << (char)228 << "(Yi^2) = " << yi2 << endl;

    double ansA = 0.0, ansB = 0.0;
    ansA = xiyi - ((double)n * xbar * ybar);
    ansB = (xi2 - (n*xbar*xbar))*(yi2 - (n*ybar*ybar));
    ansB = sqrt(ansB);
    return ansA / ansB;
}

int main(){

    double cov, sx, sy;

    cout << "\n\n\tEnter the value of n : ";
    cin >> n;


    cout << "Enter " << n << " values of X separated by space...\n\t>> ";
    for(int i=0;i<n;i++){
        cin >> x;
        X.push_back(x);
    }

    cout << "Enter " << n << " values of Y separated by space...\n\t>> ";
    for(int i=0;i<n;i++){
        cin >> x;
        Y.push_back(x);
    }

    cov = getCOV();
    cout << "\n\n\tCOV(X,Y) = " << cov << endl;
    return 0;
}
