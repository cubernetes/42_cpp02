#pragma once

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& fixed);
	~Fixed();
	Fixed& operator=(const Fixed& fixed);

	int getRawBits(void) const;
	void setRawBits(int const raw);
private:
	int _value;
	static const int point;
};
