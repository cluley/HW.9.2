#include <iostream>
#include <compare>

class Fraction
{
public:
	Fraction() : numerator_(1), denominator_(1) {}
	Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {}
	double division() { return static_cast<double>(numerator_) / static_cast<double>(denominator_); }
	auto operator<=>(Fraction& other) {
		return division() <=> other.division();
	}
	bool operator==(Fraction& other) {
		return operator<=>(other) == 0;
	}
	Fraction operator+(Fraction& other) {
		int new_num = (numerator_ * other.denominator_) + (other.numerator_ * denominator_);
		int new_denom = denominator_* other.denominator_;
		
		bool temp = 0;
		do {
			temp = false;
			for (int i = 9; i > 1; --i) {
				if ((new_num % i == 0) && (new_denom % i == 0))
				{
					new_num = new_num / i;
					new_denom = new_denom / i;
					temp = true;
				}
			}
		} while (temp);

		return Fraction(new_num, new_denom);
	}
	Fraction operator-(Fraction& other) {
		int new_num = (numerator_ * other.denominator_) - (other.numerator_ * denominator_);
		int new_denom = denominator_ * other.denominator_;

		bool temp = 0;
		do {
			temp = false;
			for (int i = 9; i > 1; --i) {
				if ((new_num % i == 0) && (new_denom % i == 0))
				{
					new_num = new_num / i;
					new_denom = new_denom / i;
					temp = true;
				}
			}
		} while (temp);

		return Fraction(new_num, new_denom);
	}
	Fraction operator*(Fraction& other) {
		int new_num = numerator_ * other.numerator_;
		int new_denom = denominator_ * other.denominator_;

		bool temp = 0;
		do {
			temp = false;
			for (int i = 9; i > 1; --i) {
				if ((new_num % i == 0) && (new_denom % i == 0))
				{
					new_num = new_num / i;
					new_denom = new_denom / i;
					temp = true;
				}
			}
		} while (temp);

		return Fraction(new_num, new_denom);
	}
	Fraction operator/(Fraction& other) {
		int new_num = numerator_ * other.denominator_;
		int new_denom = denominator_ * other.numerator_;

		bool temp = 0;
		do {
			temp = false;
			for (int i = 9; i > 1; --i) {
				if ((new_num % i == 0) && (new_denom % i == 0))
				{
					new_num = new_num / i;
					new_denom = new_denom / i;
					temp = true;
				}
			}
		} while (temp);

		return Fraction(new_num, new_denom);
	}
	Fraction operator-() {
		return Fraction(-numerator_, denominator_);
	}
	Fraction& operator++() { 
		numerator_ = numerator_ + denominator_;

		return *this;
	}
	Fraction& operator++(int) { 
		numerator_ = numerator_ + denominator_; 

		return *this;
	}
	Fraction& operator--() { 
		numerator_ = numerator_ - denominator_; 

		return *this;
	}
	Fraction& operator--(int) { 
		numerator_ = numerator_ - denominator_; 

		return *this;
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
	Fraction one;
	Fraction two;

	std::cin >> one;
	std::cin >> two;
	
	Fraction result = one + two;
	std::cout << one << " + " << two << " = " << result << std::endl;

	result = one - two;
	std::cout << one << " - " << two << " = " << result << std::endl;

	result = one * two;
	std::cout << one << " * " << two << " = " << result << std::endl;

	result = one / two;
	std::cout << one << " / " << two << " = " << result << std::endl;

	std::cout << "++" << one << " * " << two << " = "; 
	result = ++one * two; 
	std::cout << result << std::endl;
	std::cout << "Значение дроби 1: " << one << std::endl;

	std::cout << one << "--" << " * " << two << " = ";
	result = one-- * two; 
	std::cout << result << std::endl;
	std::cout << "Значение дроби 1: " << one << std::endl;

	return 0;
}