#include <iostream>
#include <string>

using namespace std;


bool read_yes_no()
{
	while (true) {
		string line;
		if (!getline(cin, line)) return false;
		if (line.empty()) continue;
		unsigned char ch = static_cast<unsigned char>(line[0]);
	
		if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N') {
			return (ch == 'y' || ch == 'Y');
		}
		
		if (line[0] == '\u0443' || line[0] == '\u0423') return true;
		if (line[0] == '\u043F' || line[0] == '\u043F') return false;

		if (ch == 'u' || ch == 'U') return true;
		if (ch == 'p' || ch == 'P') return false;
		cout << "Please answer with 'y' (yes) or 'n' (no): ";
	}
}

int main()
{
	cout << "Think of a number between 1 and 16 (inclusive). I will ask yes/no questions.\n";
	int low = 1, high = 16;
	int questions = 0;
	while (low < high) {
		int mid = (low + high) / 2;
		cout << "Is your number <= " << mid << "? (y/n): ";
		bool ans = read_yes_no();
		++questions;
		if (ans) high = mid;
		else low = mid + 1;
	}
	cout << "Your number is " << low << ". Guessed in " << questions << " questions.\n";
}
