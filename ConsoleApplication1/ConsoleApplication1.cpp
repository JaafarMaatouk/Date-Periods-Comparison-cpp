# include<iostream>
using namespace std;

struct stDate {

	short Day;
	short Month;
	short Year;
};

struct stPeriod {

	stDate StartDate;
	stDate EndDate;
};

short ReadDay() {

	short Day;
	cout << " Enter please A Day   : ";
	cin >> Day;

	return Day;
}

short ReadMonth() {

	short Month;
	cout << " Enter please A Month : ";
	cin >> Month;

	return Month;
}

short ReadYear() {

	short Year;
	cout << " Enter please A Year  : ";
	cin >> Year;

	return Year;
}

stDate ReadAllInfo() {

	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

stPeriod ReadPeriod() {

	stPeriod Period;
	cout << "\n Enter Start Date:\n\n";
	Period.StartDate = ReadAllInfo();
	cout << "\n Enter End Date  : \n\n";
	Period.EndDate = ReadAllInfo();

	return Period;
}

bool IsDate1BeforDate2(stDate Date1,stDate Date2) {

	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
		(Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {

	return (Date1.Day == Date2.Day && Date1.Month == Date2.Month && Date1.Year == Date2.Year);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2) {

	return (!IsDate1BeforDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enum enDateCompar{ Befor=-1,Equal=0,After=1};

enDateCompar ComparDate(stDate Date1,stDate Date2) {

	if (IsDate1BeforDate2(Date1, Date2)) {

		return enDateCompar::Befor;

	}
	
	if (IsDate1EqualDate2(Date1, Date2)) {

		return enDateCompar::Equal;
	}

	if (IsDate1AfterDate2(Date1, Date2)) {

		return enDateCompar::After;
	}
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2) {

	if (ComparDate(Period2.EndDate, Period1.StartDate) == enDateCompar::Befor
		|| ComparDate(Period2.StartDate, Period1.EndDate) == enDateCompar::After)
	{
		return false;

	}
	else
		return true;

}

int main() {

	cout << "\n Enter Period 1 :\n";
	cout << " ----------------\n";
	stPeriod Period1 = ReadPeriod();

	cout << "\n\n Enter Period 2 :\n";
	cout << " ----------------\n";
	stPeriod Period2 = ReadPeriod();

	if (IsOverlapPeriods(Period1, Period2)) {

		cout << "\n Yes , Periods Overlap :(\n";

	}
	else
	{
		cout << "\n No , Periods Not Overlap :)\n";
	}

}