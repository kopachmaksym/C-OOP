#include <iostream>
#include <cmath>
using namespace std;



class square
{
private:
	int x1, y1, x2, y2;
public:
	square() { x1 = y1 = x2 = y2 = 0; }
	square(int PointX1, int PointY1, int PointX2, int PointY2) { x1 = PointX1; y1 = PointY1; x2 = PointX2; y2 = PointY2;}
	~square() {}
	int getPointX1() { return x1; }
	int getPointY1() { return y1; }
	int getPointX2() { return x2; }
	int getPointY2() { return y2; }

	void setX1(int PointX1) {
		x1 = PointX1;
	}

	void setY1(int PointY1) {
		y1 = PointY1;
	}

	void setX2(int PointX2) {
		x2 = PointX2;
	}

	void setY2(int PointY2) {
		y2 = PointY2;
	}

	void print(void);
	double diag_dist(square& obj);
	double stor_dist(square& obj);
	double area(square& obj);
	double perimeter(square& obj);
	bool operator<(square& obj);
	square operator-(square obj);
};

/*void square::print(void) {
	cout << x1 << " " << y1 << endl;
}*/

double square::diag_dist(square& obj)
{
	return (sqrt(pow((double)x1 - obj.getPointX2(), 2) + pow((double)y1 - obj.getPointY2(), 2)));

}

double square::stor_dist(square& obj)
{
	return (sqrt(pow((double)x1 - obj.getPointX2(), 2) + pow((double)y1 - obj.getPointY2(), 2)) / sqrt(2));
}

double square::area(square& obj)
{
	return (pow(sqrt(pow((double)x1 - obj.getPointX2(), 2) + pow((double)y1 - obj.getPointY2(), 2)) / sqrt(2), 2));
}

double square::perimeter(square& obj)
{
	return (sqrt(pow((double)x1 - obj.getPointX2(), 2) + pow((double)y1 - obj.getPointY2(), 2)) / sqrt(2) * 2);
}

/*bool  square::operator<(square& obj)
{
	bool p;
	p = x < obj.x&& y < obj.y;
	return p;
};*/

square square::operator-(square obj)
{
	square p;
	p.x1 = x1 - obj.x1;
	p.y1 = y1 - obj.y1;
	p.x2 = x2 - obj.x2;
	p.y2 = y2 - obj.y2;
	return p;
}

int main() {
	square obj1_1(0, 0, 1, 1);
	square obj1_2;
	square obj1;
	obj1_2.setX1(1);
	obj1_2.setY1(1);
	square obj2;

	//obj1 = obj1_1 - obj1_2;
	//bool obj3 = obj1 < obj1_2;
	int x, y;
	//cout << obj3 << endl;
	x = obj1.getPointX1();
	y = obj1.getPointY1();

	cout << "Point1:";
	cout << x << " " << y << endl;
	cout << "Point2:";
	obj2.print();

	cout << "Diagonal: " << obj1.diag_dist(obj2) << endl;
	cout << "Distance: " << obj1.stor_dist(obj2) << endl;
	cout << "Area: " << obj1.area(obj2) << endl;
	cout << "Perimeter: " << obj1.perimeter(obj2) << endl << endl;

	obj2.setX2(6);

	obj2.setY2(5);

	cout << "Point2: ";

	obj2.print();

	cout << "New diagonal: " << obj1.diag_dist(obj2) << endl;
	cout << "New distance: " << obj1.stor_dist(obj2) << endl;
	cout << "New area: " << obj1.area(obj2) << endl;
	cout << "New perimeter: " << obj1.perimeter(obj2) << endl;

	return 0;

}
