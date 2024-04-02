#ifndef SPEC_H
#define SPEC_H

#include <iostream>

class Shape
{
public:
	Shape();
	Shape(int a);
	Shape(int a, int b);
	Shape(int a, int b, int c);
	void spec();
	~Shape();

private:
	int line1, line2, line3;
};


#endif // !SPEC_H

