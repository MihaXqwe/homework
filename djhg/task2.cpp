#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 100);
	int a = dist(gen);
	int b = dist(gen);
	int c = dist(gen);
	cout << "Generated numbers: " << a << ", " << b << ", " << c << "\n";
	int arr[3] = {a, b, c};
	sort(arr, arr+3);
	cout << "Sorted ascending: " << arr[0] << ", " << arr[1] << ", " << arr[2] << "\n";
}
