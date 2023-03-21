#pragma once
#include<iostream>
#include<ctime>
using namespace std;
class Time_
{
	int hour;
	int minutes;
	int seconds;
	bool format;
public:
	Time_();
	Time_(int hour, int minutes, int seconds, bool format = true);
	Time_(const Time_& obj);
	Time_& operator = (const Time_& obj);
	~Time_();

	void setHour(int hour);
	int getHour()const;
	void setMinutes(int minutes);
	int getMinutes()const;
	void setSeconds(int seconds);
	int getSeconds()const;
	void setFormat(bool* format);
	bool getFormat()const;

	bool valid()const; //time check
	void tickTime(); //every tick add one second
	void untickTime(); //every tick remove one second
	void showTime()const; //show time by the format

	//--------- Comparison operators ---------
	bool operator == (const Time_& obj)const&;
	bool operator != (const Time_& obj)const&;
	bool operator > (const Time_& obj)const&;
	bool operator < (const Time_& obj)const&;
	bool operator >= (const Time_& obj)const&;
	bool operator <= (const Time_& obj)const&;

	//--------- Assignment operators ---------	
	Time_& operator += (int s);		// add seconds
	Time_& operator -= (int s);
	Time_& operator += (float minutes);	// add minutes
	Time_& operator -= (float minutes);
	Time_& operator += (long hours);	// add hours
	Time_& operator -= (long hours);

	//--------- Arithmetic operators ---------
	Time_ operator + (int s)const&;	// add seconds
	Time_ operator - (int s)const&;
	Time_ operator + (float minutes)const&; // add minutes
	Time_ operator - (float minutes)const&;
	Time_ operator + (long hour)const&; // add hours
	Time_ operator - (long hour)const&;

	Time_& operator -- ();
	Time_ operator -- (int n);
	Time_& operator ++ ();
	Time_ operator ++ (int n);

	friend Time_ operator + (int n, Time_ a);
	friend Time_ operator - (int n, Time_ a);

	friend ostream& operator << (ostream& os, const Time_& t);
	friend istream& operator >> (istream& is, Time_& t);
};