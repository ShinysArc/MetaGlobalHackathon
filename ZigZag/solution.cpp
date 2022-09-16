#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int grid[9][9];

char cell;

bool isPresentInZig(int row, int col, int num)
{
	if (grid[row][col] == num)
		return true;

	int i = row;
	int j = col;
	while (i >= 0)
	{
		if (j < 0)
			j = 8;
		if (grid[i][j] == num)
			return true;
		i--;
		j--;
	}

	i = row;
	j = col;

	while (i < 9)
	{
		if (j > 8)
			j = 0;
		if (grid[i][j] == num)
			return true;
		i++;
		j++;
	}

	return false;
}

bool isPresentInZag(int row, int col, int num)
{
	if (grid[row][col] == num)
		return true;

	int i = row;
	int j = col;
	while (i < 9)
	{
		if (j < 0)
			j = 8;
		if (grid[i][j] == num)
			return true;
		i++;
		j--;
	}

	i = row;
	j = col;

	while (i >= 0)
	{
		if (j > 8)
			j = 0;
		if (grid[i][j] == num)
			return true;
		i--;
		j++;
	}

	return false;
}

bool isPresentInBox(int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row+boxStartRow][col+boxStartCol] == num)
				return true;
	return false;
}

void print_grid(int grid[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << grid[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

bool findEmptyPlace(int &row, int &col)
{
	for (row = 0; row < 9; row++)
		for (col = 0; col < 9; col++)
			if (grid[row][col] == 9)
				return true;
	return false;
}

bool isValidPlace(int row, int col, int num)
{
	return !isPresentInZig(row, col, num) && !isPresentInZag(row, col, num) && !isPresentInBox(row - row%3,
			col - col%3, num);
}

bool solveZigZag(int grid[9][9])
{
	int row, col;
	if (!findEmptyPlace(row, col))
		return true;
	for (int num = 0; num < 9; num++)
	{
		if (isValidPlace(row, col, num))
		{
			grid[row][col] = num;
			if (solveZigZag(grid))
				return true;
			grid[row][col] = 9;
		}
	}
	return false;
}

int solve() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> cell;
			if (cell == '.')
				grid[i][j] = 9;
			else
				grid[i][j] = cell - '0';
		}
	}
	cout << "\n\n";
	solveZigZag(grid);
	print_grid(grid);
	//cout << isPresentInZag(6, 2, 0) << endl;
	return grid[0][0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	int ans = 0;
	for (int t = 1; t <= tc; t++) {
		// cout << "Case #" << t << ": ";
		ans += solve();
	}

	cout << ans;
}
