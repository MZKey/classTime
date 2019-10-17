#include "CTime.h"

CTime::CTime(char h, char m, char s)
{
	try {
		setTime(h, m, s);
	}
	catch (short e)
	{
		throw e;
	}
}

CTime::CTime(){}

unsigned short CTime::getSeconds() const
{
	return seconds;
}

unsigned short CTime::getMinutes() const
{
	return minutes;
}

unsigned short CTime::getHours() const
{
	return hours;
}

std::string CTime::toString(std::string spacer) const
{
	std::string str = std::to_string(getHours()) + spacer + std::to_string(getMinutes()) + spacer + std::to_string(getSeconds());
	return str;
}

unsigned CTime::timeToSeconds() const
{
	return seconds + (minutes * 60) + (hours * 3600);
}

float CTime::timeToMinutes() const
{
	return float((hours * 60.0f) + minutes + (seconds / 60.0f));
}

float CTime::timeToHours() const
{
	return float(hours + (minutes / 60.0f) + (seconds / 3600.0f));
}

void CTime::setSeconds(char s)
{
	if (s >= 0 && s < 60)
	{
		seconds = s;
	}
	else throw -3;
}

void CTime::setMinutes(char m)
{
	if (m >= 0 && m < 60)
	{
		minutes = m;
	}
	else throw -2;
}

void CTime::setHours(char h)
{
	if (h >= 0 && h < 24)
	{
		hours = h;
	}
	else throw ExceptionIvalidArgument;
}

void CTime::setTime(char h, char m, char s)
{
	try 
	{
		setHours(h);
		setMinutes(m);
		setSeconds(s);
	}
	catch (short e)
	{		
		setHours(0);
		setMinutes(0);
		setSeconds(0);
		throw e;
	}
}

void CTime::setTime(const CTime& time)
{
	try
	{
		setHours(time.hours);
		setMinutes(time.minutes);
		setSeconds(time.seconds);
	}
	catch (short e)
	{
		setHours(0);
		setMinutes(0);
		setSeconds(0);
		throw e;
	}
}

void CTime::addSeconds(unsigned s)
{
	if (s > 0)
	{
		if (s >= 60)
		{
			addMinutes(s / 60);
			s = s % 60;
		}
			
		if ((unsigned)seconds + s > 60)
		{
			s = s - (60 - seconds);
			seconds = 0;
			seconds += s - 1;
			addMinutes(1);
		}
		else if ((unsigned)seconds + s == 60)
		{
			seconds = 0;
			addMinutes(1);
		}
		else seconds += s;
	}
	else throw - 6;
}

void CTime::addMinutes(unsigned m)
{
	if (m > 0)
	{
		if (m >= 60)
		{
			addHours(m / 60);
			m = m % 60;
		}

		if ((unsigned)minutes + m > 60)
		{
			m = m - (60 - minutes);
			minutes = 0;
			minutes += m - 1;
			addHours(1);
		}
		else if ((unsigned)minutes + m == 60)
		{
			minutes = 0;
			addHours(1);
		}
		else minutes += m;
	}
	else throw -5;
}

void CTime::addHours(unsigned h)
{
	if (h > 0)
	{
		if (h >= 24) h = h % 24;
		if ((unsigned)hours + h > 24)
		{
			h = h - (24 - hours);
			hours = 0;
			hours += h - 1;
		}
		else if ((unsigned)hours + h == 24) hours = 0;
		else hours += h;
	}
	else throw -4;
}

void CTime::subSeconds(int s)
{
	if (s > 0)
	{
		if (s >= 60)
		{
			subMinutes(s / 60);
			s = s % 60;
		}

		if ((int)seconds - s < 0)
		{
			s = s - seconds;
			seconds = 60;
			seconds -= s;
			subMinutes(1);
		}
		else if ((unsigned)seconds - s == 0) seconds = 0;
		else seconds -= s;
	}
	else throw -7;
}

void CTime::subMinutes(int m)
{
	if (m > 0)
	{
		if (m >= 60)
		{
			subHours(m / 60);
			m = m % 60;
		}
		
		if ((int)minutes - m < 0)
		{
			m = m - minutes;
			minutes = 60;
			minutes -= m;
			subHours(1);
		}
		else if ((unsigned)minutes - m == 0) minutes = 0;
		else minutes -= m;
	}
	else throw -8;
}

void CTime::subHours(int h)
{
	if (h > 0)
	{
		if (h >= 24) h = h % 24;

		if ((int)hours - h < 0)
		{
			h = h - hours;
			hours = 24;
			hours = hours - h;
		}
		else hours -= h;
	}
	else throw -9;
}

CTime CTime::operator+(const CTime& other)
{
	CTime temp;
	temp.addHours(this->getHours() + other.getHours());
	temp.addMinutes(this->getMinutes() + other.getMinutes());
	temp.addSeconds(this->getSeconds() + other.getSeconds());
	return temp;
}

CTime CTime::operator-(const CTime& other)
{
	CTime temp;
	temp.setTime((char)this->getHours(), (char)this->getMinutes(), (char)this->getHours());
	temp.subHours(other.getHours());
	temp.subMinutes(other.getMinutes());
	temp.subSeconds(other.getSeconds());
	return temp;
}
