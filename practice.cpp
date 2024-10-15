#include<iostream>
#include <string>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256

void search(string pat, string txt, int q)
{
	int M = pat.size();
	int N = txt.size();
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;
    int count = 0;
	//h = pow(d, M-1)%q
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	// Calculating hash value of pattern and first window of text
	for (i = 0; i < M; i++){
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}
		
    // Checking and Shifting
	for(i = 0;i <= N-M;i++){

		if(p == t){
			//Check for characters one by one
			for(j =0;j < M;j++) 
                if(txt[i+j] != pat[j]) break;

			if(j == M) count++;
		}

		// Calculate hash value for next window of text
		if(i < N-M){
			t = (d * (t - txt[i] * h) + txt[i+M]) % q;
		}
	}
    cout << count << endl;
}

int main()
{
	string pat,txt;
    cin >> txt >> pat;

	int q = 100000001;

	// Function Call
	search(pat, txt, q);
	return 0;
}