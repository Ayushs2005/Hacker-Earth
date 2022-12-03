#include<bits/stdc++.h>
using namespace std;

void count(string &S, vector <int> &F)
{
	for(int i = 0; i < S.size(); i++)
	{
		if('a' <= S[i] && S[i] <= 'z')
		{
			F[S[i] - 'a']++;
		}
	}
}

void solve()
{
	int length;
    string S, T; 
	cin >> length >> S >> T;

	const int NO_OF_ALPHABETS = 26; 
	vector <int> frequency_S(NO_OF_ALPHABETS, 0);
	count(S, frequency_S);

	vector <int> frequency_T(NO_OF_ALPHABETS, 0);
	count(T, frequency_T);

	int question_marks = 0;
	for(int i = 0; i < S.size(); i++)
	{
		question_marks += (S[i] == '?');
	}

	int possible = true, needed_question_marks = 0;
	for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
	{
		if(frequency_S[alpha] > frequency_T[alpha])
		{
			possible = false;
		}

		if(frequency_T[alpha] > frequency_S[alpha])
		{
			needed_question_marks += frequency_T[alpha] - frequency_S[alpha];
		}
	}
	cout << (possible && needed_question_marks == question_marks ? "Yes" : "No") << "\n";
}

int main() 
{
    int no_of_test_cases; 
    cin >> no_of_test_cases; 

    while(no_of_test_cases--)
        solve();

    return 0;
}
