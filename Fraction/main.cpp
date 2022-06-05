#include <iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer; //Целая часть
	int numerator; //Числитель
	int denominator;//Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//        CONSTRUCTORS
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout<<"Constructor:\t\t"<<this<<endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	
	//      OPERATORS
	Fraction& operator =(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t\t" << this << endl;
		return*this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		/*int a = 2;
		int b = 3;
		a *= b;
		a = a * b;*/
		return *this = *this*other;

	}
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}
	//        Increment/Decrement
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	//          Type - cast operators :
	explicit operator int()const
	{
		return integer;
	}
	operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//        METODS
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;
		return inverted;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		if (!integer && !numerator)cout << 0;
		cout << endl;
	}
};


Fraction operator*( Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	return result;*/
	return Fraction// явно вызываем конструктор
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	).to_proper();//для вреенного безымянного объекта вызываем метод to_proper
}
Fraction operator /(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
bool operator==(Fraction left, Fraction right)
{
	//left.to_improper();
	//right.to_improper();
	//return left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator();
	return left == right;
}
bool operator!=(const Fraction&left, const Fraction& right)
{
	return (left == right);
}
bool operator>(Fraction left,Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator()*right.get_denominator() >
		right.get_numerator()*left.get_denominator();
	//return (double)left > right;
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator()*right.get_denominator() <
		right.get_numerator()*left.get_denominator();
}
bool operator>=(const Fraction&left, const Fraction& right)
{
	//return left > right || left == right;
	return!(left < right);
}
bool operator<=(const Fraction&left, const Fraction& right)
{
	return left < right || left == right;
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())cout << "(";
		cout << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())cout << ")";
	}
	if (!obj.get_integer() && !obj.get_numerator())cout << 0;
	return os;
}
std::istream& operator>>(std::istream& is,  Fraction& obj)
{
	/*int integer, numerator, denominator;
	cin >> integer >> numerator >> denominator;
	obj(integer, numerator, denominator);*/
	const int SIZE = 256;
	char sz_buffer[SIZE]{};
	//cin >> sz_buffer;
	is.getline(sz_buffer, SIZE);
	char* sz_numbers[3] = {};
	char sz_delimiters[] = "() /";
	int n = 0;//Индек элементов в массиве с подстроками(токенами) sz_numbers
	for (char* pch = strtok(sz_buffer, sz_delimiters); pch; pch = strtok(NULL, sz_delimiters))
	{
		sz_numbers[n++] = pch;
	}
	//for (int i = 0; i < n; i++)cout << sz_numbers[i] << "\t"; cout << endl;
	obj = Fraction();
	switch (n)
	{
	case 1: obj.set_integer(atoi(sz_numbers[0])); break;
	case 2: 
		obj.set_numerator(atoi(sz_numbers[0]));
		obj.set_denominator(atoi(sz_numbers[1])); break;
	case 3:
		obj(atoi(sz_numbers[0]),atoi(sz_numbers[1]),atoi(sz_numbers[2]));
	}

	return is;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHETICAL
//define COMPARISON
//#define CONVERSION_TO_CLASS_TO_OTHER


void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	Fraction F;
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHETICAL
	Fraction A(2, 3, 4);
	A.print();
	/*A.to_improper();
	A.print();
	A.to_proper();
	A.print();*/
	Fraction B(3, 4, 5);
	B.print();


	Fraction C = A * B;
	C.print();
	(A / B).print();
	A *= B;
	A.print();

	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.print();
	}
#endif // ARITHETICAL
#ifdef COMPARISON

	cout << (Fraction(1, 2) >= Fraction(5, 11)) << endl;
#endif // COMPARISON

#ifdef CONVERSION_TO_CLASS_TO_OTHER
	Fraction C(1, 2);
	cout << C << endl;

	Fraction A(2, 3, 4);
	int a = (int)A;
	cout << a << endl;
	double b = A;
	cout << b << endl;

	cout << (Fraction(1, 2) == Fraction(5, 11)) << endl;
#endif // CONVERSION_TO_CLASS_TO_OTHER

	Fraction A;
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;

}