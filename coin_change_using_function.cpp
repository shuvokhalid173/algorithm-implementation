#include <bits/stdc++.h>

using namespace std;


#define limit 1000

long long n , coin[limit];
long long save[limit][limit];
long long value;

long long ways (long long index , long long amount)
{
	/// base case----------------
	if (index >= n){/// sob coin nea hoe gese
		if (amount == value){ /// jodi coin gula dia value ta banano jay taile return 1
			return 1;
		}
		else{ /// tasara return 0;
			return 0;
		}
	}
    /// dynamic programming memozition technique -------------
	if (save[index][amount]!=-1){ /// save array te jodi kono valu thake taile valuta return korbo;
		return save[index][amount]; //// aki calculation bar bar korar kono dorkar nai;
	}	
	
	long long process1 = 0;
	long long process2 = 0;
	/// je je coin gula nibo segular jogfol kono somoyi value er besi houa jabe na 
	if (coin[index] + amount <= value)
	{
		process1 = ways (index , amount + coin[index]);
		/// ekhane jehetu amra aki coin barbar use korte parbo 
		/// tai porer ta na nie amra age agerta niei try korbo
		/// and protikhetre oi coin tar amount jog kore dibo 
	}
	else{
		process1 = 0;
		/// otherwise process 0
	}
	
	process2 = ways (index + 1 , amount);
	
	long long ans;
	ans = process1 + process2;
	save[index][amount] = ans;
	
	return save[index][amount];
}

int main ()
{
	memset (save , -1 , sizeof (save));
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> coin[i];
	}
	cin >> value;
	cout << ways (0 , 0) << endl;
	main ();
}
