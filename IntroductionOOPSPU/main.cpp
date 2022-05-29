#include<iostream>
using namespace std;

//Создаем стуктуру
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//    Constructor

	//Point()
	//{
	//	//int() значение по умолчанию для типа данных
	//	//cout << int() << endl;
	//	x = y = double();
	//	cout << "DefaultConstructor:\t" << this << endl;
	//}
	//Point(double x)
	//{
	//	// single-Agrument - конструктор с одним параметром
	//	this->x = x;
	//	this->y = 0;
	//	cout << "1argConstructor:\t" << this << endl;
	//}
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//  OPerators
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigmenr:\t\t" << this << endl;
		return *this;
	}

	//        Methods:
	double distance(const Point& other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}
	void print()
	{
		cout << "x=" << x << "\ty=" << y << endl;
	}
};
Point operator+(const Point& left, const Point& right)
{
	Point result;

}

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(pow(x_distance, 2) + pow(y_distance, 2));
}

//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTOR_CHECK
//define COPY_ASSIGNMENT_1
//define COPY_ASSIGNMENT_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//Создаем объект
	int a;
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A;//Создаем указатель на 'POINT'
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE

	Point A;
	A.set_x(2);
	A.set_y(3);
	//cout<<A.get_x()<<"\t"<<A.get_y()<<endl;
	A.print();
	Point B;
	B.set_x(7);
	B.set_y(8);
	//cout<<B.get_x()<<"\t"<<B.get_y()<<endl;
	B.print();
	cout << "\n----------------\n";
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << "\n----------------\n";
	cout << "Растояние от точки В до точки А: " << B.distance(A) << endl;
	cout << "\n----------------\n";
	cout << "Расстояние между точками А и В: " << distance(A, B) << endl;
	cout << "\n----------------\n";
	cout << "Расстояние между точками В и А: " << distance(B, A) << endl;
	cout << "\n----------------\n";
#endif // DISTANCE

#ifdef CONSTRUCTOR_CHECK
	Point A;
	A.print();

	Point B = 5;// single-Agrument - конструктор с одним параметром
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;
	D.print();
#endif // CONSTRUCTOR_CHECK

#ifdef COPY_ASSIGNMENT_1
	Point A(2, 3);
	Point B = A;  //Copy Constructor
	Point C;
	C = B;  //CopyAssignment  
#endif // COPY_ASSIGNMENT_1

#ifdef COPY_ASSIGNMENT_2
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << "\t" << endl;

	Point A, B, C;
	cout << "\n-------------\n";
	A = B = C = Point(2, 3);
	cout << "\n-------------\n";
#endif // COPY_ASSIGNMENT_2

	Point A(2, 3);
	Point B(7, 8);
	A.print();
	B.print();
	Point C = A + B;
	C.print();
}