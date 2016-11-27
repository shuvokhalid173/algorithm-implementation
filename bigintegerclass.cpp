/**
	simple biginteger class in c++;
	my code .................
**/
#include <bits/stdc++.h>

#define loop(i,n) for(i=1;i<=n;i++)
#define rloop(i,n) for(i=n;i>=1;i--)
#define aloop(i,n) for(i=0;i<n;i++)
#define arloop(i,n) for(i=n-1;i>=0;i--)
template < typename T > T gcd (T a , T b){if (b == 0) return a;return gcd (b , a % b);}
template < typename T > bool check_bit (T n , T position){return (bool) (n & (1 << position));}
template < typename T > T set_bit (T n , T position){return n = n | (1 << position);}
template < typename T > T mod (T number , T power , T divisor){if (power == 0){return 1;}
else if (power == 1){return number;}else if (power % 2 == 0){T F;F = mod (number , power / 2 , divisor);
return ((F % divisor) * (F % divisor)) % divisor;}else{T Q;Q = mod (number , power - 1 , divisor);
return ((number % divisor) * (Q % divisor)) % divisor;}}
template < typename T > T E_PHI (T n){if (n == 1){return n;}T val;val = n;
if (n % 2 == 0){val =val - val / 2;while (n % 2 == 0){n /= 2;}}T i;for (i = 3; i <= sqrt (n); i += 2)
{if (n % i == 0){val -= val / i;while (n % i == 0) {n /= i;}}}if (n > 1){val -= val / n;}return val;}
template < typename T > T sqr (T n) { return n * n; };
template < typename T > T No_Of_Divisors (T n){T c = 0;while (n % 2 == 0){c++;n /= 2;}
T i , counter = 1;counter *= c + 1;for (i = 3; i <= sqrt (n); i += 2){T c2 = 0;
while (n % i == 0){c2++;n /= i;}if (c2)counter *= c2 + 1;}if (n!=1) counter *= 2;return counter;}
bool is_char (char cc){if ((cc >= 'a' && cc <= 'z') || (cc >= 'A' && cc <= 'Z'))return true;else return false;}
bool is_upper (char cc){if (cc >= 'A' && cc <= 'Z') return true;else return false;}
/************************************************************************************/

using namespace std;

#define limit 1200

struct BigInteger{
	
	/// addition //
	
	/// BigInteger addition started ///
	string add (string f_num , string s_num){
	    string res;
		int firstnumber[1200];
		int secondnumber[1200];
		int result[1200];
		memset (firstnumber , 0 , sizeof (firstnumber));
		memset (secondnumber , 0 , sizeof (secondnumber));
		int flength = f_num.length();
		int slength = s_num.length();
		reverse (f_num.begin() , f_num.end());
		reverse (s_num.begin() , s_num.end());
		for (int i = 0; i < flength; i++)
		firstnumber[i] = f_num[i] - '0';
		for (int i = 0; i < slength; i++)
		secondnumber[i] = s_num[i] - '0';
		int maxlength = max (flength , slength);

		int ii , sum , carry = 0 , cnt = 0;
		for (ii = 0; ii < maxlength; ii++){
			sum = firstnumber[ii] + secondnumber[ii] + carry;
			result[ii] = sum % 10;
			carry = sum / 10;
			cnt++;
		}
		while (carry){
			result[ii++] = carry % 10;
			carry /= 10;
			cnt++;
		}
		for (int i = cnt - 1; i >= 0; i--)
		res += (result[i] + '0');
		return res;
	}
	/// BigInteger addition finished //
	
	/// multiply ///
	
	/// BigInteger multiplication started ///
	string multiply (string f_num , string s_num){
        string result__;
        int first_number[1000];
        int second_number[1000];
        memset (first_number , '0' , sizeof (first_number));
        memset (second_number , '0' , sizeof (second_number));
        int temp[1000];
        int res[1000];
        memset (temp , 0 , sizeof (temp));
        memset (res , 0 , sizeof (res));
        int length1 , length2 , l;
        length1 = f_num.length();
        length2 = s_num.length();
        reverse (f_num.begin() , f_num.end());
        reverse (s_num.begin() , s_num.end());
        for (int i = 0; i < length1; i++)
        first_number[i] = f_num[i] - '0';
        for (int i = 0; i < length2; i++)
        second_number[i] = s_num[i] - '0';
        int i , j , k;
        int x , y = 0 , p , px = 0;
        for (i = 0; i < length1; i++){
            int counter = 0;
            int carry = 0;
            for (p = 0; p < y; p++){
                temp[p] = 0;
                counter++;
            }
            for (j = 0; j < length2; j++){
                //temp[i + j] += ((first_number[i] - '0') * (second_number[j] - '0')) % 10;
                //temp[i + j + 1] += ((first_number[i] - '0') * (second_number[j] - '0')) / 10;
                x = (first_number[i] * second_number[j]) + carry;
                temp[j + p] = x % 10;
                carry = x / 10;
                counter++;
            }
            while (carry){
                temp[j + p++] = carry % 10;
                carry = carry / 10;
                counter++;
            }
            int no;
            int carry2 = 0;
            for (k = 0; k < counter; k++){
                no = res[k] + temp[k] + carry2;
                res[k] = no % 10;
                carry2 = no / 10;
                //counter++;
            }
            while (carry2){
                res[k++] = carry2 % 10;
                carry2 /=10;
                counter++;
            }
            px = counter;
            y++;
            memset (temp , 0 , sizeof temp);
        }
        int fix = 0;
        for (l = px - 1; l >=0; l--){
            if (res[l] == 0){
                fix++;
            }
            else{
                break;
            }
        }
        if (px - fix == 0){
            return "0";
        }
        for (l = px - fix - 1; l >= 0; l--)
            result__ += (res[l] + '0');
        return result__;
    }
    string make_string (int n){
    	int arr[100];
    	int i = 0;
    	string ss;
    	while (n){
        	arr[i] = n % 10;
        	n /= 10;
        	i++;
    	}
    	for (int ii = i - 1; ii >= 0; ii--)
       	ss += (arr[ii] + '0');
       	return ss;
	}
	
	/// substraction and compare ///
	
	/// this function removes leading zeros ///
	int neg_zero (string str){
		int len = str.length();
		int i;
		int cf = 0;
		for (i = 0; i < len; i++){
			if (str[i] == '0'){
				cf++;
			}
			else break;
		}
		return cf;
	}
	
    /// compare two big number ///
    
	bool cmp (string f_num , string s_num){
		int flen , slen;
		flen = f_num.length();
		slen = s_num.length();
		int fpos , spos;
		fpos = neg_zero (f_num);
		spos = neg_zero (s_num);
		int nflen , nslen;
		nflen = flen - fpos;
		nslen = slen - spos;
		int first_number[nflen + 1];
		int second_number[slen + 1];
		memset (first_number , 0 , sizeof (first_number));
		memset (second_number , 0 , sizeof (second_number));
		for (int p = fpos; p < flen; p++)
		first_number[p - fpos] = f_num[p] - '0';
		for (int p = spos; p < slen; p++)
		second_number[p - spos] = s_num[p] - '0';
		if (nflen > nslen)
		return 1;
		else if (nflen < nslen)
		return 0;
		else{
			int y;
			bool ok = false;
			for (y = 0; y < nflen; y++){
				if (first_number[y] > second_number[y]){
					return 1;
					ok = true;
					break;
				}
				else if (first_number[y] < second_number[y]){
					return 0;
					ok = true;
					break;
				}
			}
			if (!ok) return 1;
		}
	}
	
	/// substraction ///

	string subtract (string f_num , string s_num){
		int result[limit];
		string rres;
		int flen , slen;
		flen = f_num.length();
		slen = s_num.length();
		int fpos , spos;
		fpos = neg_zero (f_num);
		spos = neg_zero (s_num);
		int nflen , nslen;
		nflen = flen - fpos;
		nslen = slen - spos;
		int first_number[nflen + 1];
		int second_number[nflen + 1];
		memset (first_number , 0 , sizeof (first_number));
		memset (second_number , 0 , sizeof (first_number));
		for (int p = fpos; p < flen; p++)
		first_number[p - fpos] = f_num[p] - '0';
		for (int p = spos; p < slen; p++)
		second_number[p - spos] = s_num[p] - '0';
		reverse (first_number , first_number + nflen);
		reverse (second_number , second_number + nslen);
		int i , j = 0, x;
		int carry = 0;
		for (i = 0; i < nflen; i++){
			second_number[i] += carry;
			if (first_number[i] < second_number[i])
			first_number[i] += 10;
			x = first_number[i] - second_number[i];
			carry = first_number[i] / 10;
			result[j++] = x;
		}
		int l , c = 0;
		for (l = j - 1; l >= 0; l--){
			if (result[l] == 0){
				c++;
			}
			else break;
		}
		if (c == j)
		return "0";

		for (l = j - c - 1; l >= 0; l--)
		rres += (result[l] + '0');
		return rres;
	}
};

int main (){
	BigInteger result;
	string n , m;
	cout << "insert two big number" << endl;
	cin >> n >> m;
	cout << "addition result       --> " << result.add(n , m) << endl; puts("");
	cout << "multiplication result --> " << result.multiply(n , m) << endl;puts("");
	cout << "substraction result   --> ";
	if (result.cmp(n , m)) {
		cout << result.subtract(n , m) << endl; puts("");
		cout << n << " is Big" << endl; 
	}
	else {
		cout << "-" << result.subtract(m , n) << endl; puts("");
		cout << m << " is Big " << endl;
	}
	puts(""); puts("do it again  .... Y/N");
	char ch; cin >> ch;
	if (ch == 'Y') {
		puts(""); main (); 
	}
	else return 0;
}

