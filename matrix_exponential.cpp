#include <bits/stdc++.h>

using namespace std;

const int mod = 1234;

struct matrix {
	int row , col;
	int mat[50][50];
	matrix () {}
	matrix operator * (const matrix &b) const {
        assert (col == b.row);
        matrix res;
        res.row = row;
        res.col = b.col;
        for (int i = 0; i < res.row; i++) {
            for (int j = 0; j < res.col; j++) {
                int sum = 0;
                for (int k = 0; k < col; k++) {
                    sum += mat[i][k] * b.mat[k][j];
                    sum %= mod;
                }
                res.mat[i][j] = sum;
            }
        }
        return res;
	}
};

matrix expo (matrix a , int p) {
	assert (p >= 1);
	if (p == 1) return a;
	if (p % 2 == 0) {
		matrix ret = expo (a , p / 2);
		return ret * ret;
	}
	else return a * expo (a , p - 1);
}

int main () {
	matrix bm;
	bm.row = bm.col = 2;
	bm.mat[0][0] = bm.mat[0][1] = 1;
	bm.mat[1][0] = 1; bm.mat[1][1] = 0;
	int n; cin >> n;
	matrix ans = expo (bm , n - 2);
	cout << (ans.mat[0][0] + ans.mat[0][1]) % mod << endl;
	main ();
}
