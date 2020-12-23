#ifndef MINUTE_H
#define MINUTE_H

struct Minute {
	int		hour;
	int		minute;

	Minute::Minute()
	{
		hour	= 0;
		minute	= 0;
	}
	Minute::Minute(int value, int delta = 1)
	{
		hour	= value / 100;
		minute	= value - hour * 100;
		if (minute >= 60) {
			minute -= 60;
			if (delta > 0) {
				hour++;
			} else if (delta < 0) {
				hour--;
			}
		}
	}
	Minute::Minute(const Minute &right)
	{
		hour	= right.hour;
		minute	= right.minute;
	}
	Minute &operator=(int value)
	{
		return Minute::operator=(Minute(value));
	}
	Minute &operator=(const Minute &right)
	{
		hour	= right.hour;
		minute	= right.minute;
		return *this;
	}
	Minute operator +(int value)
	{
		return Minute::operator+(Minute(value));
	}
	Minute operator +(const Minute &right)
	{
		Minute ret;
		ret.hour	= this->hour + right.hour;
		ret.minute	= this->minute + right.minute;
		if (ret.minute >= 60) {
			ret.hour++;
			ret.minute -= 60;
		}
		return ret;
	}
	Minute operator -(int value)
	{
		return Minute::operator-(Minute(value));
	}
	Minute operator -(const Minute &right)
	{
		Minute ret;
		ret.hour	= this->hour - right.hour;
		ret.minute	= this->minute - right.minute;
		if (ret.minute < 0) {
			ret.hour--;
			ret.minute += 60;
		}
		return ret;
	}
	Minute &operator+=(int value)
	{
		return Minute::operator+=(Minute(value));
	}
	Minute &operator+=(const Minute &right)
	{
		Minute::operator=(*this + right);
		return *this;
	}
	Minute &operator-=(int value)
	{
		return Minute::operator-=(Minute(value));
	}
	Minute &operator-=(const Minute &right)
	{
		Minute::operator=(*this - right);
		return *this;
	}
	int value() const
	{
		return hour * 100 + minute;
	}
};

#endif // MINUTE_H
