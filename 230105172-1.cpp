#include <iostream>



class Date{
	int year_;
	int month_;
	int day_;

	public:
	void setZero(){
		year_ = 0;
		month_ = 0;
		day_ = 0;
	}
	void errHandler(const char *s){
		std::cout << "Error: "<< s << std::endl;
		setZero();
	}
	int maxDay(){
		int ret;
		if((month_ < 8 && month_ % 2 == 1) || (month_ >= 8 && month_ % 2 == 0))
			ret = 31;
		else{
			if(month_ == 2){
				bool flag = true;
				if(year_ % 4 == 0){
					if(year_ % 100 == 0 && year_ % 400 != 0)
						flag = false;
				} else flag = false;
				if ( flag ) ret = 29;
				else  ret = 28;
			}
			else ret = 30;
		}
		return ret;
	}

	void setDate(int year, int month, int date){
		year_ = year;

		//month check
		if( 0 < month && month < 13){
			month_ = month;
		}else {
			errHandler("month");
			return;
		}

		//date check
		if ( date < 1){ 
			errHandler("date");
			return;
		}
		if((month < 8 && month % 2 == 1) || (month >= 8 && month % 2 == 0)){
			if(date < 32) day_ = date;
			else {
				errHandler("date");
				return;
			}
		}
		else{
			if ( date <=  maxDay() )
				day_ = date;
			else {
				errHandler("date");
				return;
			}
		}
	}
	void addDay(int inc){
		while(inc > 0 ){
			int max = maxDay();
			if ( day_ + inc > max){
				if(month_ == 12) {year_++; month_ = 1;}
				else month_ += 1;
				inc -= max-day_+1;
				day_ = 1;
			} else{
				day_ += inc;
				inc = 0;
			}
		}
	}
	void addMonth(int inc){
		month_ += inc%12;
		if(month_ > 12){
			month_ = month_ - 12;
			year_ += 1;
		}
		year_ += inc/12;
	}
	void addYear(int inc){
		year_ += inc;
		int max = maxDay();
		if(day_ > max) day_ = max;
	}

	void showDate(){
		std::cout << "================================" << std::endl;
		std::cout << "year : " << year_ << std::endl;
		std::cout << "month : " << month_ << std::endl;
		std::cout << "day : " << day_ << std::endl;
		std::cout << "================================" << std::endl;
	}
};

int main(){
	Date instance;
	instance.setZero();
	int year; int month; int day;
	int num_check; bool flag = true;
	for(;flag;){
	std::cout << "1. setDate" <<std::endl;
	std::cout << "2. addDay" <<std::endl;
	std::cout << "3. addMonth" <<std::endl;
	std::cout << "4. addYear" <<std::endl;
	std::cout << "5. showDate" <<std::endl;
	std::cout << "0. quit" <<std::endl;

	std::cout << "menu num : ";
	std::cin >> num_check;

	int inc;
	
	switch(num_check){
		case 0:
			flag = false;
			break;
		case 1:
			std::cout << "year : ";
			std::cin >> year; 
			std::cout << "month : ";
			std::cin >> month; 
			std::cout << "day : ";
			std::cin >> day; 
			instance.setDate(year, month,  day);
			break;
		case 2:
			std::cout << "inc : ";
			std::cin >> inc;
			instance.addDay(inc);
			break;
		case 3:
			std::cout << "inc : ";
			std::cin >> inc;
			instance.addMonth(inc);
			break;
		case 4:
			std::cout << "inc : ";
			std::cin >> inc;
			instance.addYear(inc);
			break;
		case 5:
			instance.showDate();
			break;

	}
	}

}
