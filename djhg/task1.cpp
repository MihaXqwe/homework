#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	cout << "Task 1 — enter a character: ";
	string s;
	if (!getline(cin, s) || s.empty()) {
		cout << "No input provided.\n";
		return 0;
	}
	unsigned char c = static_cast<unsigned char>(s[0]);
	if (isdigit(c)) cout << "is a digit.\n";
	else if (isupper(c)) cout << "uppercase letter.\n";
	else if (islower(c)) cout << "lowercase letter.\n";
	else cout << "another symbol.\n";
}
