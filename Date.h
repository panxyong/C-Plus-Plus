/* 2016.1.10 panxyong */

#ifndef __DATE_H__
#define __DATE_H__

#include <iostream>

class Date;
void CreatePoints(Date dates[], int N);
void Sort(Date dates[], int N);


class Date
{
public:
	Date(int y = 1980, int m = 1, int d = 1) :year(y), month(m), day(d) {};

	Date& operator = (const Date& x);
	/*
	int  getyear()  const {return year;};
	int  getmonth() const {return month;};
	int  getday()   const {return day;};
	*/
	bool operator  > (const Date& x) const;
	bool operator  < (const Date& x) const;
	bool operator == (const Date& x) const;
	void print() const {std::cout << year << "-" << month << "-" << day <<std::endl;};

	/* data */
private:
	int year;
	int month;
	int day;
};


inline bool
Date::operator > (const Date& x) const
{
	if(this->year > x.year ||
		(this->year == x.year && this->month > x.month)||
		(this->year == x.year && this->month ==x.month && this->day > x.day))
		return true;
	return false;
}


inline bool
Date::operator < (const Date& x) const
{
	if(this->year < x.year ||
		(this->year == x.year && this->month < x.month)||
		(this->year == x.year && this->month ==x.month && this->day < x.day))
		return true;
	return false;
}

inline bool
Date::operator == (const Date& x) const
{
	if(this->year == x.year && this->month ==x.month && this->day == x.day)
		return true;
	return false;
}

inline Date& 
Date::operator = (const Date& x) 
{
	this->year = x.year;	//x.year之所以能够直接取数据的一个解释：同Class的不同object互为friend.
	this->month = x.month;
	this->day = x.day;

	return *this;
}


static bool isLeapYear(int year)
{
	return (year%4 == 0 && year % 100 != 0) || year%400 == 0;
}
static int randday(int year, int month, int randnum)
{
	int table[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},
						{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	return (randnum % table[isLeapYear(year)][month]) + 1;
}

void CreatePoints(Date dates[], int N)
{
	srand((unsigned)time(0));  
    for (int i = 0; i < N; ++i)
    {
    	int y = rand()%100 + 1980;
    	int m = rand()%12 + 1;
    	int d = randday(y, m, rand());

    	dates[i] = Date(y,m,d);
    }
}

void Sort(Date dates[], int N)
{
	for (int i = 1; i < N; ++i)
	{
		int j = i-1;
		
		Date tmp = dates[i];

		while(j >= 0 && tmp < dates[j])
		{
			dates[j+1] = dates[j];
			j--;
		}	

		dates[j+1] = tmp;
		
	}
}

#endif //__DATE_H__