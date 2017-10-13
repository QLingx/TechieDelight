#include <bits/stdc++.h>
using namespace std;

// M x N matrix
#define M 5
#define N 5

int main()
{
	int mat[M][N] = 
	{
		{0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 1, 1, 0, 0}		
	};
	
unordered_set<unsigned> set;

	// do for each row i
	for (int i = 0; i < M; i++)
	{
		unsigned decimal = 0;
		
		// convert binary row i into its decimal equivalent
		for (int j = 0; j < N; j++)
			decimal += mat[i][j] * pow(2, j);

		// if decimal value is seen before
		if (set.find(decimal) != set.end())
			cout << "Duplicate row found : Row# " << i + 1 << endl;
		else
			set.insert(decimal);
	}

	return 0;
}
