#include "CTime.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	const int n = 5;
	CTime* time7;

	string fileName = "text.txt";
	string str;
	ofstream file;
	ifstream file2;

	try
	{
		time7 = new CTime(23, 15, 45);
	}
	catch (int e)
	{
		cout << "Invalid argument: " << e << endl;
	}

	//cout << time7->toString() << endl;

	vector<CTime> timeArr;
	timeArr.resize(n);

	for (unsigned i = 0; i < timeArr.size(); i++)
	{
		timeArr[i].setTime(i, i, i);
		cout << timeArr[i].toString() << endl;
	}
	cout << endl;
	vector<CTime*> timeArr2;
	timeArr2.resize(5);
	
	for (unsigned i = 0; i < timeArr2.size(); i++)
	{
		timeArr2[i] = new CTime(i * 2, i * 2, i * 2);
		cout << timeArr2[i]->toString() << endl;
	}

	CTime time8(14, 54, 12);
	CTime time9;

	file.open(fileName);
	file << time8.getHours() << endl;
	file << time8.getMinutes() << endl;
	file << time8.getSeconds() << endl;

	file.close();

	
	file2.open(fileName);
	getline(file2, str);
	time9.setHours(stoi(str));
	getline(file2, str);
	time9.setMinutes(stoi(str));
	getline(file2, str);
	time9.setSeconds(stoi(str));

	cout << time9.toString() << endl;
	file2.close();
	for (int a = 0; a < 5; a++)
	{

	}
	for (int a = 0; a < 6; a++)
	{

	}

	/*
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
	cout << time2.toString() << endl;

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
		CTime time6( 23,1,1 );
	}
	catch (int e)
	{
		cout << "Invalid argument: " << e << endl;
	}
	*/

	return 0;
}