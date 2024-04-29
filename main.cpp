#include <iostream>

class Fraction {
public:		
	Fraction(long long num, long long den){	
		try {
			if (den == 0) {
				throw std::exception("Error: Division by zero");
			}
			numerator = num;
			denominator = den;
		}

		catch (const std::exception& e) {
			std::cerr << "Error" << e.what() << std::endl;
		}

	}
	void Print_fraction() 
	{
		std::cout << numerator << '/' << denominator << std::endl;
	}
	void Proper_fraction()
	{
		if (numerator < denominator)
			std::cout << "Дробь правильная!" << '\n';
		else
			std::cout << "Дробь не правильная!" << '\n';
	}

	friend double real_number(const Fraction& Fraction_);	

	Fraction sum(const Fraction& other)const
	{
		long long num = (numerator * other.denominator) + (other.numerator * denominator);
		long long den = denominator * other.denominator;
		return Fraction(num, den);
	}
	Fraction sub(const Fraction& other) const
	{
		long long num = (numerator * other.denominator) - (other.numerator * denominator);
		long long den = denominator * other.denominator;
		return Fraction(num, den);
	}
	Fraction multiply(const Fraction& other) const
	{
		long long num = numerator * other.numerator;
		long long den = denominator * other.denominator;
		return Fraction(num, den);
	}
	Fraction devide(const Fraction& other) const
	{
		long long num = numerator * other.denominator;
		long long den = denominator * other.numerator;
		return Fraction(num, den);
	}
	Fraction sum(long long num_)
	{
		long long num = numerator + (num_ * denominator);
		return Fraction(num, denominator);
	}
	Fraction sub(long long num_)
	{
		long long num = numerator - (num_ * denominator);
		return Fraction(num, denominator);
	}
	Fraction multiply(long long num_)
	{
		long long num = numerator * num_;
		return Fraction(num, denominator);
	}
	Fraction devide(long long num_)
	{
		long long num = denominator * num_;
		return Fraction(num, denominator);
	}
	

private:
	long long numerator;
	long long denominator;
};

double real_number(const Fraction& Fraction_)
{
	return double(Fraction_.numerator) / Fraction_.denominator;
}

int main() {
	setlocale(LC_ALL, "ru");

	Fraction fraction_1(1, 2);
	Fraction fraction_2(3, 4);
	Fraction fraction_3(1, 0);

	Fraction sum = fraction_1.sum(fraction_2);
	Fraction sub = fraction_1.sub(fraction_2);
	Fraction multiply = fraction_1.multiply(fraction_2);
	Fraction devide = fraction_1.devide(fraction_2);

	std::cout << "Результаты работы с дробями: \n";
	sum.Print_fraction();
	sub.Print_fraction();
	multiply.Print_fraction();
	devide.Print_fraction();

	Fraction fraction_num1 = fraction_1.sum(2);
	Fraction fraction_num2 = fraction_2.sub(1);
	Fraction fraction_num3 = fraction_1.multiply(3);
	Fraction fraction_num4 = fraction_2.devide(2);



	std::cout << "Результаты работы дробей с целыми числами: \n";
	fraction_num1.Print_fraction();
	fraction_num2.Print_fraction();
	fraction_num3.Print_fraction();
	fraction_num4.Print_fraction();


	fraction_1.Proper_fraction();
	std::cout << "Дробь в виде действительного числа: " <<  real_number(fraction_3) << std::endl;

	
	return 0;
}