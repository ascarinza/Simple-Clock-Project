#include <iostream>
#include <string>
using namespace std;

// I created a class for time and all the fuctions within for organization and ease of
// using the getters and settes and tracking h, m, and s
class Time {
public:
	unsigned int h;
	unsigned int m;
	unsigned int s;

	// Created new object Time with passed variables
	Time(unsigned hours, unsigned minutes, unsigned seconds) {
		h = hours;
		m = minutes;
		s = seconds;
	}

	// Gets hours
	int getHour() {
		return h;
	}
	// Sets hours
	void setHour(int hour) {
		h = hour;
	}
	// Gets Minutes
	int getMinute() {
		return m;
	}
	// Sets Minutes
	void setMinute(int minute) {
		m = minute;
	}
	// Gets seconds
	int getSecond() {
		return s;
	}
	// Sets seconds
	void setSecond(int second) {
		s = second;
	}

	// Created a string of chars the length of n
	string nCharString(size_t n, char c) {
		string clockLines;
		for (int i = 0; i < n; i++) {
			clockLines += c;
		}
		return clockLines;
	}

	// Prints the menu bar from an array of strings, number of string, and decided width
	void printMenu(string strings[], unsigned int numStrings, unsigned char width) {
		int spaces = 0;

		// Top boarder of display menu
		cout << nCharString(width, '*') << endl;

		// Loop that prints out menu decisions with correct neat formatting
		for (int i = 0; i < numStrings; i++) {
			/* I had orginaly tried calling ncharStrings with width-1 and ' ' to
			 * create the spaces but this then created too many spaces from the left
			 * as it didn't take the letter output into account so I had to subtract
			 * the letters from string[i] from width as well as 8 (from the * i -) and
			 * final * in order to get the proper spacing
			 */
			int spaces = width - strings[i].length() - 8;
			cout << "* " << i + 1 << " - " << strings[i] << nCharString(spaces, ' ')
				<< " " << "*" << endl;
			// Will add an endl to output instead of a space when its the last option
			if (i < numStrings - 1) {
				cout << endl;
			}
		}
		// Creates bottom boarder of menu
		cout << nCharString(width, '*') << endl;
	}

	// Converts ints to strings to make formating time functions easier
	string twoDigitString(unsigned int n) {
		string digitAsString;
		// If the time is greater than 10 it gets converted as is
		if (n >= 10) {
			digitAsString = to_string(n);
		}
		// If time is less than 10 a leading 0 gets attached
		else if (n < 10) {
			digitAsString = "0" + to_string(n);
		}
		// returns the time value as a string
		return digitAsString;
	}

	// Makes sure that the input from the menu is a valid choice
	// Makes sure the input is postive and less than the max number of choices
	unsigned int getMenuChoice(unsigned int maxChoice) {
		int userChoice;
		cin >> userChoice;
		// Loops until a valid choice is picked
		while (userChoice < 1 || userChoice > maxChoice) {
			cin >> userChoice;
		}
		// returns the valid choice made by the user
		return userChoice;
	}

	// Formats the time in hours, minutes, and second (h:m:s) using 24 hour clock
	string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
		string twentyFourTime;

		// Calls twoDigitString to turn ints to strings and join them as a single string
		twentyFourTime = twoDigitString(h) + ":" + twoDigitString(m) +
			":" + twoDigitString(s);
		// Returns string as proper time
		return twentyFourTime;
	}

	// Formats the time in hours, minutes, and second (h:m:s) using 12 hour clock
	string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
		string twelveTime;
		string timeOfDay;
		int adjustedHours = h;
		// If hours is less than 12 AM gets added to time as per 12 hour clock
		if (h < 12) {
			timeOfDay = "A M";
		}
		// If in the afternoon or >12, PM is added to time
		else {
			timeOfDay = "P M";
			adjustedHours = h - 12;
		}
		// makes sure 12 in the A M is 0 and 12 in the P M is 12
		if (adjustedHours == 0) {
			adjustedHours = 12;
		}

		// Calls twoDigitString to turn ints to strings and join them as a single string
		twelveTime = twoDigitString(adjustedHours) + ":" + twoDigitString(m) +
			":" + twoDigitString(s) + " " + timeOfDay;
		// returns string as proper time
		return twelveTime;
	}

	// Displays the clock and time in a neat design
	void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
		// Printing for borders, spaces, headings, and formatted time
		cout << nCharString(27, '*') << nCharString(3, ' ');
		cout << nCharString(27, '*') << endl;
		cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ');
		cout << "*" << nCharString(3, ' ');
		cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ');
		cout << "*" << endl;
		cout << endl;
		cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s);
		cout << nCharString(7, ' ') << "*" << nCharString(3, ' ');
		cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s);
		cout << nCharString(9, ' ') << "*" << endl;
		cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*');
		cout << endl;
	}

	// When called will add 1 to hours and will reset hours to 0 and AM PM when hours
	// clicks over past 24
	void addOneHour() {
		if (getHour() <= 22) {
			setHour(getHour() + 1);
		}
		else {
			setHour(0);
		}
	}

	// When called will add 1 to minutes. When minutes clicks over 60 add hour will be called
	void addOneMinute() {
		if (getMinute() <= 58) {
			setMinute(getMinute() + 1);
		}
		else {
			setMinute(0);
			addOneHour();
		}
	}

	// When called will add 1 to minutes. When seconds clicks over 60 add minute will be called
	void addOneSecond() {
		if (getSecond() <= 58) {
			setSecond(getSecond() + 1);
		}
		else {
			setSecond(0);
			addOneMinute();
		}
	}
};

void originalTime(int& h, int& m, int& s) {
	cout << "Enter the hour: ";
	cin >> h;
	cout << endl;
	cout << "Enter the minute: ";
	cin >> m;
	cout << endl;
	cout << "Enter the seconds: ";
	cin >> s;
	cout << endl;
}

// Main fucnion
int main() {
	// Create varibles
	int h;
	int m;
	int s;
	int userSelection = 1;
	// Create menu needed for print menu function
	string myStrings[] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };
	// will collect users initial data for time
	originalTime(h, m, s);

	// Creates usertime object
	Time usertime = Time(h, m, s);
	usertime.displayClocks(h, m, s);

	// A loop that will run until the user exits by pressing 4
	while (userSelection != 4) {
		usertime.printMenu(myStrings, 4, 57);
		// given that choices are either 1,2 or 3. 3 is the max choice.
		userSelection = usertime.getMenuChoice(4);
		if (userSelection == 1) {
			usertime.addOneHour();
		}
		else if (userSelection == 2) {
			usertime.addOneMinute();
		}
		else if (userSelection == 3){
			usertime.addOneSecond();
		}
		// Used when user selected to exit so that clock isnt displayed upon exit
		else {
			break;
		}

		// Used the get methods to update the h, m, and s
		h = usertime.getHour();
		m = usertime.getMinute();
		s = usertime.getSecond();

		// Displays the clocks for the newly updated times
		usertime.displayClocks(h, m, s);

	}
	return 0;
}