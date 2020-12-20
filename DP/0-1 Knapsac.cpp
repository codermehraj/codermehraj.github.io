// In the Name of Allah—the Most Compassionate, Most Merciful.

#include <bits/stdc++.h>

using namespace std;

#define debg  0

int main() {

	int n, W;
	// n = number of items
	// W = capacity
	cin >> n >> W;
	
	int ojon[n], daam[n];
	int napsac[100][100];

	for(int i=0;i<n;i++){
		cin >> ojon[i] >> daam[i];
	}

	// making table
	cout << "\nKnapsac table : \n";
	for(int i=0;i<=n;i++){
		for(int j=0;j<=W;j++){
			if(i==0 || j==0) napsac[i][j] = 0;
			else if(j >= ojon[i-1]) 
				napsac[i][j] = max(napsac[i-1][j], daam[i-1]+napsac[i-1][j-ojon[i-1]]);
			else napsac[i][j] = napsac[i-1][j];
			cout << napsac[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\nMaximum price = " << napsac[n][W] << endl;

	stack < pair < int , int > > items;
	// ojon, price

	int y_pos = W, tmpPrice, tmpOjon;
	for(int i=n;i>=0;i--){
		tmpPrice = napsac[i][y_pos];
		if(tmpPrice == 0) break;
		if(napsac[i-1][y_pos]!=tmpPrice){
			y_pos -= ojon[i-1];
			items.push({ojon[i-1],daam[i-1]});
		}
	}

	cout << "\nItems taken : " << items.size() << "\n";
	while(!items.empty()){
		cout << items.top().first << " kg ~ " << items.top().second << " taka\n";
		items.pop();
	}
	return 0;
}

/*
	Input format:
	n W
	n bar : ojon[i] price[i]

	sample: 
	4 7
	1 1
	3 4
	4 5
	5 7
	
	For :
	n = 4 and W = 7
	ojon price = 1 1 , 3 4, 4 5, 5 7
	
	(n+1)x(W+1) matrix
	set first row with zeros

    total price =>   
        0  1  2  3  4  5  6  7
	0   0  0  0  0  0  0  0  0
	1   0  1  1  1  1  1  1  1
	2   0  1  1  4  5  5  5  5
	3   0  1  1  4  5  6  6  9
	4   0  1  1  4  5  7  8  9

*/
