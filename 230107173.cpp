#include <iostream>

class Date{
	int year_;
	int month_;
	int day_;

	public:
	void setDate(int year, int month, int date);
	void addDay(int inc);
	void addMonth(int inc);
	void addYear(int inc);

	int getCurrentMonthTotalDays(int year, int month);

	void showDate();
};
void Date::setDate(int year, int month, int day){
	year_ = year;
	month_ = month;
	day_ = day;
}

int Date::getCurrentMonthTotalDays(int year, int month) {
	static int month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(month != 2){
		return month_day[month-1];
	}else if (year % 4 == 0 && year % 100 != 0) {
		return 29;
	} else {
		return 28;
	}
}

void Date::addDay(int inc){
	while(true){
		int current_month_total_days = getCurrentMonthTotalDays(year_, month_);
		if(day_ + inc <= current_month_total_days) {
			day_ += inc;
			return;
		} else{
			inc -= (current_month_total_days - day_ + 1);
			day_ = 1;
			addMonth(1);
		}
	}
}
void Date::addMonth(int inc){
	addYear((inc + month_ -1) /12);
	month_ = month_ + inc % 12;
	month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::addYear(int inc) { year_ += inc;}

void Date::showDate(){
	std::cout << "오늘은" << year_ << " 년 " << month_ << " 월 " << day_ << "일 입니다. " << std::endl;
}

int main(){
	Date day;
	day.setDate(2022, 1, 7);
	day.showDate();

	day.addDay(30);
	day.showDate();

	day.addDay(2000);
	day.showDate();

	day.setDate(2024, 1, 31);
	day.addDay(29);
	day.showDate();

	day.setDate(2022, 2, 10);
	day.addDay(2500);
	day.showDate();
	return 0;
}
