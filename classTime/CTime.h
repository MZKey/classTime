#pragma once
#include <string>

class CTime
{
public:
	static const int ExceptionIvalidArgument = -1;

	CTime(char h, char m, char s);
	CTime();

	unsigned short getSeconds() const;
	unsigned short getMinutes() const;
	unsigned short getHours() const;
	std::string toString(std::string spacer = ":") const;

	unsigned timeToSeconds() const;
	float timeToMinutes() const;
	float timeToHours() const;
	
	void setSeconds(char s);
	void setMinutes(char m);
	void setHours(char h);
	void setTime(char h, char m, char s);

	void addSeconds(unsigned s);
	void addMinutes(unsigned m);
	void addHours(unsigned h);

	void subSeconds(int s);
	void subMinutes(int m);
	void subHours(int h);

	CTime operator +(const CTime& other);
	CTime operator -(const CTime& other);

private:
	char hours = 0;
	char minutes = 0;
	char seconds = 0;
};

