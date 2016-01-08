#include <iostream>

using std::string;
using std::cin;
using std::cout;

struct Line {
	const static int vertex = 2;
	const static int edge = 1;
	float length;
};

struct Angles {
	float degree1;
	float degree2;
	float degree3;
	float degree4;
};

class Shape {
	public:
		Shape() {}
		virtual ~Shape() {
			delete sides;
		}

		void setSides(int i) {sides = new Line[i];}
		
		virtual void setLength (float f) {sides->length = f;}
		virtual float getLength() {return sides->length;}

	protected:
		Line * sides;
};

class TwoD : public Shape {
	public:
		TwoD() {}
		virtual void calculateArea() =0;
		virtual void calculatePerimeter() =0;
};

class Polygon : public TwoD {
	public:
		Polygon() {}
		Polygon(int i){
			setSides(i);
			num = i;
		}
		
		void calculatePerimeter() {
			float perimeter = 0.00;
			for (int i=0; i < num; i++) {
				perimeter = perimeter + sides[i].length;
			}
			cout << "perimeter of the polygon is " << perimeter << "\n";
		}

		void printSides(){
			for (int i=0; i < num; i++) {
				cout << "Side " << i+1 << " length is " << sides[i].length << "\n"; 
			}
		}
	protected:
		int num;
};

class Quadrilateral : public Polygon {
	public:
		Quadrilateral() {setSides(4); num = 4;}
		Quadrilateral(float s1, float s2, float s3, float s4){
			setSides(4);
			sides[1].length = s1;
			sides[2].length = s2;
			sides[3].length = s3;
			sides[4].length = s4;
			num = 4;
		}
		
		void setWidth (float f) {width->length = f;}
		float getWidth() {return width->length;}

		void setLength (float f) {length->length = f;}
		float getLength() {return length->length;}
		
		void calculateArea() {
			float area;
			area = width->length * length->length;
			cout << "area of the quadrilateral is " << area << "\n";}

		virtual void setAngles (float a1, float a2, float a3, float a4) {
			if ((a1+ a2 + a3 + a4) != 360)
				cout << "Quadrilateral constructor error: angles must = 360 degrees\n";
			else
				a->degree1 = a1; 
				a->degree2 = a2; 
				a->degree3 = a3; 
				a->degree4 = a4; 
		}
		
		void printAngles(){
			cout << "The shape's angles are: ";
			cout << a->degree1 << ", "
				<< a->degree2 << ", "
				<< a->degree3 << ", "
				<< a->degree4 << "\n";
		}

		void box () {
			a->degree1 = 90.0; 
			a->degree2 = 90.0; 
			a->degree3 = 90.0; 
			a->degree4 = 90.0;
		}
		
	protected:
		Line * width;
		Line * length;
		Angles * a = new Angles();
};

class Parallelogram : public Quadrilateral {
	public:
		Parallelogram() {}
		Parallelogram(float s1, float s2, float s3, float s4, float a1, float a2){
			if (2 *(a1 + a2) != 360)
				cout << "Quadrilateral constructor error: angles must = 360 degrees\n";
			else if ((a1 + a2) != 180)
				cout << "Parallelogram constructor error: adjacent angles must be equal to 180 degrees\n";
			else {
				a->degree1 = a1; 
				a->degree2 = a2; 
				a->degree3 = a1; 
				a->degree4 = a2; 
		
				sides[1].length = s1;
				sides[2].length = s2;
				sides[3].length = s3;
				sides[4].length = s4;
			}
		}	
};

class Rectangle : public Parallelogram {
	public:
		Rectangle() {box();}
		Rectangle(float s1, float s2) {
			sides[1].length = s1;
			sides[3].length = s2;
			sides[2].length = s1;
			sides[4].length = s2;
			box();
		}
};

class Square : public Rectangle {
	public:
		Square(float s){
			for (int i=0; i < num; i++){
				sides[i].length = s;
			}
		}
};

int main() {

	Square square = Square(5);
	square.printAngles();
	square.printSides();
	square.calculatePerimeter();
	square.setSides(5);
	square.printSides();
	return 0;
}