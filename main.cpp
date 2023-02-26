#include <iostream>
#include <compare>
#include "math.h."

void GCD(int& num, int& denom) {
	int temp_num = abs(num);
	int temp_denom = abs(denom);
	
	while (temp_num != 0 && temp_denom != 0) {
		if (temp_num > temp_denom) {
			temp_num %= temp_denom;
		}
		else {
			temp_denom %= temp_num;
		}
	}

	int GCD = temp_num + temp_denom;
	num /= GCD;
	denom /= GCD;
}

class Fraction
{
public:
	Fraction() : numerator_(1), denominator_(1) {}
	Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {}
	~Fraction() = default;
	double division() { return static_cast<double>(numerator_) / static_cast<double>(denominator_); }
	auto operator<=>(Fraction& other) {
		return division() <=> other.division();
	}
	bool operator==(Fraction& other) {
		return operator<=>(other) == 0;
	}
	Fraction& operator+(Fraction& other) {
		int new_num = (numerator_ * other.denominator_) + (other.numerator_ * denominator_);
		int new_denom = denominator_* other.denominator_;
		
		GCD(new_num, new_denom);

		Fraction temp(new_num, new_denom);

		return temp;
	}
	Fraction& operator-(Fraction& other) {
		int new_num = (numerator_ * other.denominator_) - (other.numerator_ * denominator_);
		int new_denom = denominator_ * other.denominator_;

		GCD(new_num, new_denom);

		Fraction temp(new_num, new_denom);

		return temp;
	}
	Fraction& operator*(Fraction& other) {
		int new_num = numerator_ * other.numerator_;
		int new_denom = denominator_ * other.denominator_;

		GCD(new_num, new_denom);

		Fraction temp(new_num, new_denom);

		return temp;
	}
	Fraction& operator/(Fraction& other) {
		int new_num = numerator_ * other.denominator_;
		int new_denom = denominator_ * other.numerator_;

		GCD(new_num, new_denom);

		Fraction temp(new_num, new_denom);

		return temp;
	}
	Fraction& operator-() {
		Fraction temp(numerator_ * -1, denominator_);

		return temp;
	}
	Fraction& operator++() { 
		numerator_ = numerator_ + denominator_;

		return *this;
	}
	Fraction operator++(int) { 
		Fraction oldValue(numerator_, denominator_);
		numerator_ = numerator_ + denominator_; 

		return oldValue;
	}
	Fraction& operator--() { 
		numerator_ = numerator_ - denominator_; 

		return *this;
	}
	Fraction operator--(int) { 
		Fraction oldValue(numerator_, denominator_);
		numerator_ = numerator_ - denominator_; 

		return oldValue;
	}
	friend std::ostream& operator<<(std::ostream& output, Fraction& frac);
	friend std::istream& operator>>(std::istream& input, Fraction& frac);
private:
	int numerator_;
	int denominator_;
};

std::ostream& operator<<(std::ostream& output, Fraction& frac) {
	output << frac.numerator_ << "/" << frac.denominator_;

	return output;
}

static int ctr = 1;

std::istream& operator>>(std::istream& input, Fraction& frac) {
	std::cout << "Введите числитель дроби " << ctr << ":";
	input >> frac.numerator_;

	std::cout << "Введите знаменатель дроби " << ctr << ":";
	input >> frac.denominator_;

	ctr++;

	return input;
}

int main()
{
	Fraction one(3, 4);
	Fraction two(4, 5);

	std::cin >> one;
	std::cin >> two;
	
	std::cout << one << " + " << two << " = " << one + two << std::endl;
	std::cout << one << " - " << two << " = " << one - two << std::endl;
	std::cout << one << " * " << two << " = " << one * two << std::endl;
	std::cout << one << " / " << two << " = " << one / two << std::endl;

	std::cout << "++" << one << " * " << two << " = " << ++one * two << std::endl;
	std::cout << "Значение дроби 1: " << one << std::endl;

	std::cout << one << "--" << " * " << two << " = " << one-- * two << std::endl;
	std::cout << "Значение дроби 1: " << one << std::endl;

	return 0;
}