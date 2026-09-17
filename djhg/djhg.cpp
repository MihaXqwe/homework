#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <cctype>

using namespace std;



int task1()
{
	std::cout << "Task 1 — enter a character: ";
	std::string s;
	if (!std::getline(std::cin, s) || s.empty()) {
		std::cout << "No input provided.\n";
		return 0;
	}
	unsigned char c = static_cast<unsigned char>(s[0]);
	if (std::isdigit(c)) std::cout << "The character is a digit.\n";
	else if (std::isupper(c)) std::cout << "The character is an uppercase letter.\n";
	else if (std::islower(c)) std::cout << "The character is a lowercase letter.\n";
	else std::cout << "The character is another symbol.\n";
	return 0;
}

int task2()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 100);
	int a = dist(gen);
	int b = dist(gen);
	int c = dist(gen);
	std::cout << "Generated numbers: " << a << ", " << b << ", " << c << "\n";
	int arr[3] = {a, b, c};
	std::sort(arr, arr+3);
	std::cout << "Sorted ascending: " << arr[0] << ", " << arr[1] << ", " << arr[2] << "\n";
	return 0;
}

// Helper: read a yes/no answer. Returns true for yes, false for no.
bool read_yes_no()
{
	while (true) {
		std::string line;
		if (!std::getline(std::cin, line)) return false;
		if (line.empty()) continue;
		char ch = line[0];
		if (ch == 'y' || ch == 'Y' || ch == 'u' || ch == 'U') return true; // accept 'y' and also Ukrainian 'у' might be typed as 'u'
		if (ch == 'n' || ch == 'N' || ch == 'p' || ch == 'P') return false; // accept 'n' and Ukrainian 'п' as 'p'
		std::cout << "Please answer with 'y' (yes) or 'n' (no): ";
	}
}

int task3()
{
	std::cout << "Think of a number between 1 and 16 (inclusive). I will ask yes/no questions.\n";
	int low = 1, high = 16;
	int questions = 0;
	while (low < high) {
		int mid = (low + high) / 2;
		std::cout << "Is your number <= " << mid << "? (y/n): ";
		bool ans = read_yes_no();
		++questions;
		if (ans) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	std::cout << "Your number is " << low << ". Guessed in " << questions << " questions.\n";
	return 0;
}

int main()
{
	while (true) {
		std::cout << "\nSelect task:\n";
		std::cout << "1 - character group\n";
		std::cout << "2 - generate & sort three random numbers\n";
		std::cout << "3 - guess number 1..16 with yes/no questions\n";
		std::cout << "0 - exit\n";
		std::cout << "Choice: ";
		std::string choice;
		if (!std::getline(std::cin, choice)) break;
		if (choice.empty()) continue;
		if (choice == "0") break;
		if (choice == "1") task1();
		else if (choice == "2") task2();
		else if (choice == "3") task3();
		else std::cout << "Unknown choice.\n";
	}
	std::cout << "Bye.\n";
	return 0;
}
