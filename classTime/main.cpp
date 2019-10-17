#include "CTime.h"
#include <iostream>

using namespace std;

int main()
{
	CTime time4(22, 14, 15);
	cout << time4.toString(":") << endl;
	time4.addHours(2);
	cout << time4.toString(":") << endl;
	time4.addMinutes(46);
	cout << time4.toString(":") << endl;
	time4.addSeconds(45);
	cout << time4.toString(":") << endl;

	time4.subHours(1);
	cout << time4.toString(":") << endl;
	time4.subMinutes(20);
	cout << time4.toString(":") << endl;
	time4.subSeconds(21);
	cout << time4.toString(":") << endl;
	time4.subSeconds(39);
	cout << time4.toString(":") << endl;

	cout << endl;

	CTime time( 23,59,30 );
	time.subSeconds(30);
	time.subHours(23);
	cout << time.toString(":") << endl;

	cout << endl;
	CTime time2;
	time2 = CTime( 10,10,10 )+CTime( 10,10,10 )+CTime(10,10,10);
	cout << time2.toString(":") << endl;

	cout << endl;
	CTime time3;
	time3 = CTime{}-time2;
	cout << time3.toString(":") << endl;

	cout << endl;
	CTime time5( 23,59,59 );
	cout << time5.toString(":") << endl;
	time5.addSeconds(1);
	cout << time5.toString(":") << endl;
	time5.addSeconds(3600);
	cout << time5.toString(":") << endl;

	//CTime time5;
	//cout << time5.getTimeString(":") << endl;


	//cout << "Time in seconds: " << time4.timeToSeconds() << endl;
	//cout << "Time in minutes: " << time4.timeToMinutes() << endl;
	//cout << "Time in hours: " << time4.timeToHours() << endl;

	//time4.setTime(23, 59, 59);
	//cout << "Time in seconds: " << time4.timeToSeconds() << endl;
	//cout << "Time in minutes: " << time4.timeToMinutes() << endl;
	//cout << "Time in hours: " << time4.timeToHours() << endl;

	try {
		CTime time6( 25,1,1 );
	}
	catch (int e)
	{
		cout << "Invalid argument: " << e << endl;
	}


	return 0;
}