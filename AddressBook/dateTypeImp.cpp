//Implementation file date
#include <iostream>
#include "dateType.h"
using namespace std;
//further defines each method in the dateType class.
void dateType::setDate(int month, int day, int year)
{
	dMonth = month;
	dDay = day;
	dYear = year;
}
int dateType::getDay() const
{
	return dDay;
}
int dateType::getMonth() const
{
	return dMonth;
}
int dateType::getYear() const
{
	return dYear;
}
void dateType::printDate() const
{
	cout << dMonth << "-" << dDay << "-" << dYear;
}
//constructor with parameters
dateType::dateType(int month, int day, int year)
{
	dMonth = month;
	dDay = day;
	dYear = year;
}