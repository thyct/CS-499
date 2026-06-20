// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <limits> // For std::numeric_limits

int main()
{
	std::cout << "Buffer Overflow Example" << std::endl;

	/*
	--- ASSUMPTIONS ---
	
	1. Only textual input is expected, input may include spaces
	
	2. Excessively long input will be shortened safety

	3. account_number is immediately declared before the buffer

	4. The program assumes the user may attempt to exceed buffer size.

	*/

	// Constant account number that cannot be modified
	const std::string account_number = "CharlieBrown42";

	// Fixed-size buffer for user input
	char user_input[20];

	std::cout << "Enter a value (19 characters max): ";

	// Use getline to safely read user input into the fixed-size buffer
	std::cin.getline(user_input, sizeof(user_input));

	// Check if the value is over 19 characters
	if (std::cin.fail()) {
		std::cin.clear(); // Clear the error flags
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard characters after 19
		std::cout << "*Warning* \n Input is too long, only the first 19 characters were accepted." << std::endl;
	}

	std::cout << "You entered: " << user_input << std::endl;
	std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
