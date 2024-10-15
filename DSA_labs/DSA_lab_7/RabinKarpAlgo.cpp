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


	

    /*h is used to remove the leading character's contribution from the current hash when shifting the window in the text.*/
	for (i = 0; i < M - 1; i++){
		h = (h * d) % q; 
    }


    /*We are using this loop to calculate h which is equal to pow(d,M-1)*/

	// Calculating hash value of pattern and first window of text
	for (i = 0; i < M; i++){
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}
		
    // Checking and Shifting
    /*Logic--->>>The reason for this is that you can only slide the window of size M over the text until there's exactly enough text left to form one more complete window of size M. After this, the window would extend past the end of the text, which would be invalid.*/
	for(i = 0;i <= N-M;i++){

		if(p == t){
			//Check for characters one by one
			for(j =0;j < M;j++) 
                if(txt[i+j] != pat[j]) break;

			if(j == M) count++;
		}

		// Calculate hash value for next window of text

        /*By using Rolling Hash formula we calculate the hash value of the new window , and we do this by reusing the hash value of the previous window*/

        /*The main idea is to remove the contribution of the left most character and adding the contribution of the rightmost contribution*/

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