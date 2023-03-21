#include "Time_.h"

Time_::Time_()
{
	hour = 0;
	minutes = 0;
	seconds = 0;
	format = false;
}

Time_::Time_(int hour, int minutes, int seconds, bool format)
{
	this->hour = hour;
	this->minutes = minutes;
	this->seconds = seconds;
	this->format = format;
}

Time_::Time_(const Time_& obj)
{
	this->hour = obj.hour;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;
	this->format = obj.format;
}

Time_& Time_::operator=(const Time_& obj)
{
	this->hour = obj.hour;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;
	this->format = obj.format;
	return *this;
}

Time_::~Time_()
{

}

void Time_::setHour(int hour)
{
	this->hour = hour;
}

int Time_::getHour() const
{
	return hour;
}

void Time_::setMinutes(int minutes)
{
	this->minutes = minutes;
}

int Time_::getMinutes() const
{
	return minutes;
}

void Time_::setSeconds(int seconds)
{
	this->seconds = seconds;
}

int Time_::getSeconds() const
{
	return seconds;
}

void Time_::setFormat(bool* format)
{
	this->format = format;
}

bool Time_::getFormat() const
{
	return format;
}

bool Time_::valid() const
{
	if (hour >= 0 && hour < 24 && minutes >= 0 && minutes <= 59 && seconds >= 0 && seconds <= 59)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Time_::tickTime()
{
	if (seconds == 59)
	{
		minutes++;
		seconds = 0;
	}
	if (minutes == 59)
	{
		hour++;
		minutes = 0;
	}
	if (seconds == 59 && minutes == 59)
	{
		hour++;
		minutes = 0;
		seconds = 0;
	}
	if (seconds == 59 && minutes == 59 && hour < 23)
	{
		hour = 0;
		minutes = 0;
		seconds = 0;
	}
}

void Time_::untickTime()
{
	if (seconds < 0)
	{
		minutes--;
		seconds = 59;
	}
	if (minutes < 0)
	{
		hour--;
		minutes = 59;
	}
	if (seconds < 0 && minutes < 0)
	{
		hour--;
		minutes = 59;
		seconds = 59;
	}
	if (seconds < 0 && minutes < 0 && hour < 0)
	{
		hour = 23;
		minutes = 59;
		seconds = 59;
	}
}

void Time_::showTime() const
{
	cout << hour / 10 << hour % 10 << ":" << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10 << endl;
}

bool Time_::operator==(const Time_& obj) const&
{
	if (this->seconds == obj.seconds && this->minutes == obj.minutes && this->hour == obj.hour)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Time_::operator!=(const Time_& obj) const&
{
	return !(*this == obj);
}

bool Time_::operator>(const Time_& obj) const&
{
	if (hour > obj.hour)
	{
		return true;
	}
	else if (hour == obj.hour && minutes > obj.minutes)
	{
		return true;
	}
	else if (hour == obj.hour && minutes == obj.minutes && seconds > obj.seconds)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Time_::operator<(const Time_& obj) const&
{
	return !(*this > obj) && (*this != obj);
}

bool Time_::operator>=(const Time_& obj) const&
{
	return (*this > obj) || (*this == obj);
}

bool Time_::operator<=(const Time_& obj) const&
{
	return (*this < obj) || (*this == obj);
}

Time_& Time_::operator+=(int s)
{
	for (int i = 0; i < s; i++)
	{
		tickTime();
	}
	return*this;
}

Time_& Time_::operator-=(int s)
{
	for (int i = 0; i < s; i++)
	{
		untickTime();
	}
	return*this;
}

Time_& Time_::operator+=(float minutes)
{
	this->minutes += minutes;
	if (minutes > 12)
	{
		hour += hour / 12;
		minutes = (this->minutes % 12);
	}
	return *this;
}

Time_& Time_::operator-=(float minutes)
{
	this->minutes -= minutes;
	if (minutes < 1)
	{
		hour -= abs(minutes) / 12;
		minutes = 12 + (this->minutes % 12);
	}
	return *this;
}

Time_& Time_::operator+=(long hours)
{
	hour += hours;
	if (minutes > 59)
	{
		minutes = 0;
	}
	return *this;
}

Time_& Time_::operator-=(long hours)
{
	hour -= hours;
	if (minutes = 0)
	{
		minutes = 59;
	}
	return *this;
}

Time_ Time_::operator+(int s) const&
{
	Time_ tmp = *this;
	for (int i = 0; i < s; i++)
	{
		tmp.tickTime();
	}
	return tmp;
}

Time_ Time_::operator-(int s) const&
{
	Time_ tmp = *this;
	for (int i = 0; i < s; i++)
	{
		tmp.untickTime();
	}
	return tmp;
}

Time_ Time_::operator+(float minutes) const&
{
	Time_ tmp = *this;
	tmp.minutes += minutes;
	if (tmp.minutes > 12)
	{
		tmp.hour += tmp.minutes / 12;
		tmp.minutes += (tmp.minutes % 12);
	}
	return tmp;
}

Time_ Time_::operator-(float minutes) const&
{
	Time_ tmp = *this;
	tmp.minutes -= minutes;
	if (tmp.minutes < 1)
	{
		tmp.hour += (abs(tmp.minutes / 12) + 1);
		tmp.minutes += 12 + (tmp.minutes % 12);
	}
	return tmp;
}

Time_ Time_::operator+(long hour) const&
{
	Time_ tmp = *this;
	tmp.hour += hour;
	if (minutes > 59)
	{
		tmp.minutes = 0;
	}
	return tmp;
}

Time_ Time_::operator-(long hour) const&
{
	Time_ tmp = *this;
	tmp.hour -= hour;
	if (minutes > 0)
	{
		tmp.minutes = 59;
	}
	return tmp;
}

Time_& Time_::operator--()
{
	this->untickTime();
	return *this;
}

Time_ Time_::operator--(int n)
{
	Time_ tmp = *this;
	this->untickTime();
	return tmp;
}

Time_& Time_::operator++()
{
	this->tickTime();
	return *this;
}

Time_ Time_::operator++(int n)
{
	Time_ tmp = *this;
	this->tickTime();
	return tmp;
}

Time_ operator+(int n, Time_ a)
{
	for (int i = 0; i < n; i++)
	{
		a.tickTime();

	}
	return a;
}

Time_ operator-(int n, Time_ a)
{
	for (int i = 0; i < n; i++)
	{
		a.untickTime();
	}
	return a;
}

ostream& operator<<(ostream& os, const Time_& t)
{
	os << t.seconds / 10 << t.seconds % 10 << "." << t.minutes / 10 << t.minutes % 10 << "." << t.hour;
	return os;
}

istream& operator>>(istream& is, Time_& t)
{
	do
	{
		cout << ": ";
		is >> t.seconds >> t.minutes >> t.hour;
	} while (!t.valid());
	return is;
}
