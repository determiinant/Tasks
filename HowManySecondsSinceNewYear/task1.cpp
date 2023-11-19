#include <iostream>
#include <map>
using namespace std;

int year, month, day, hour, minute, second;
enum MONTH
{
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};
map<int, int> m = { {JANUARY, 31}, {FEBRUARY, 28}, {MARCH, 31}, {APRIL, 30}, {MAY, 31}, {JUNE, 30}, {JULY , 31}, {AUGUST, 31},
	{SEPTEMBER, 30}, {OCTOBER, 31}, {NOVEMBER, 30}, {DECEMBER, 31}
};

bool isRightDayinMonth(int day, int month) {
	if (month == FEBRUARY) {
		if (year % 400 == 0 || (year % 4 == 0 && year % 4 != 0)) 
			m[month] = 28;
		if (day > m[month])
			return false;
	}
	if (day > m[month])
		return false;
	return true;
}

int howManySeconds(int year, int month, int day, int hour, int minute, int second) {
	int tmp_res = 0;
	int count_day_of_the_month = 0;
	int tmp_days = 0;

	for (int i = 1; i <= month; ++i) {
		if (month == 1)
			break;
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			count_day_of_the_month = 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			count_day_of_the_month = 30;
		else if (i == 2 && year % 4 == 0)
			count_day_of_the_month = 29;
		else if (i == 2 && year % 4 != 0)
			count_day_of_the_month = 28;
		tmp_days += count_day_of_the_month;
		if (i == month) {
			int diff = count_day_of_the_month - day;
			tmp_days -= diff;
			tmp_days -= 1;
		}
	}
	cout << tmp_days << " days" << endl;
	tmp_res = second + minute * 60 + hour * 60 * 60 + tmp_days * 24 * 60 * 60;
	return tmp_res;
}
void enterData() {
	while (true)
	{
		cout << "Enter the year: ";
		cin >> year;
		if (year < 1)
			cout << "Please enter the valid year" << endl;
		else
			break;
	}
	while (true) {
		cout << "Enter the month: ";
		cin >> month;
		if (month <= 0 || month > 12)
			cout << "Please, enter the valid month" << endl;
		else
			break;
	}
	while (true)
	{
		cout << "Enter the day: ";
		cin >> day;
		if ((day <= 0 || day > 31))
			cout << "Please, enter the valid day" << endl;
		else {
			if (isRightDayinMonth(day, month))
				break;
			else
				cout << "This month cannot have that many days" << endl;
		}
	}
	while (true)
	{
		cout << "Enter the hour: ";
		cin >> hour;
		if (hour < 0 || hour > 23)
			cout << "Please, enter the valid hour" << endl;
		else
			break;
	}
	while (true)
	{
		cout << "Enter the minute: ";
		cin >> minute;
		if (minute < 0 || minute > 59)
			cout << "Please, enter the valid minute" << endl;
		else
			break;
	}
	while (true)
	{
		cout << "Enter the second: ";
		cin >> second;
		if (second < 0 || second > 59)
			cout << "Please, enter the valid second" << endl;
		else
			break;
	}
}

int main() {
	enterData();
	cout << "Your date is: " << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << endl;
	int sel;
	cout << "[1] Yes\n[2] No" << endl;
	cin >> sel;
	switch (sel)
	{
	case 1:
		cout << howManySeconds(year, month, day, hour, minute, second) << " seconds"; break;
	case 2:
		enterData(); break;
	default:
		break;
	}
	return 0;
}