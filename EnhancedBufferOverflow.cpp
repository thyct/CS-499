// EnhancedBufferOverflow.cpp 
// This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <limits> // For std::numeric_limits
#include <string>

const size_t MAX_INPUT_LENGTH = 19;

// Constant account number that cannot be modified
const std::string account_number = "CharlieBrown42";

/*
--- ASSUMPTIONS ---

1. Only textual input is expected, input may include spaces

2. Excessively long input will be shortened safely

3. account_number is declared globally as a constant

4. The program assumes the user may attempt to exceed input limits

*/

/*
    Function: getUserInput
    Purpose: Safely collects user input using std::string
*/
std::string getUserInput()
{
	std::string input;

	std::cout << "Enter a value (19 characters max): ";
	std::getline(std::cin, input);

	return input;
}

/*
    Function: validateInput
    Purpose: Ensures input meets length and validity requirements
*/
std::string validateInput(std::string input)
{
	if (input.empty())
	{
		std::cout << "*Error* Input cannot be empty.\n";
		return "";
	}

	if (input.length() > MAX_INPUT_LENGTH)
	{
		std::cout << "*Warning* Input is too long, truncating to 19 characters.\n";
		input = input.substr(0, MAX_INPUT_LENGTH);
	}

	return input;
}

/*
    Function: displayOutput
    Purpose: Displays final processed values
*/
void displayOutput(const std::string& input)
{
	std::cout << "You entered: " << input << std::endl;
	std::cout << "Account Number = " << account_number << std::endl;
}

int main()
{
	std::cout << "Buffer Overflow Example (Enhanced Version)" << std::endl;

	/*
	--- PROGRAM FLOW ---

	1. Get user input safely using std::string

	2. Validate input for emptiness and length

	3. Display sanitized output along with account number
	*/

	std::string input;

	input = getUserInput();
	input = validateInput(input);

	if (!input.empty())
	{
		displayOutput(input);
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu