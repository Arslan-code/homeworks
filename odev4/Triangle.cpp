#include "Triangle.h"
#include "Point.h"
#include <math.h>
#include <iostream>
#include <stdexcept>

Triangle::Triangle(const Point& a, const Point& b, const Point& c, const Color& color)
{
	setA(a);
	setB(b);
	setC(c);
	
	this->color = color;
}

Triangle::Triangle(const vector<Point>& pts, const Color& color)
{
	setA(pts[0]);
	setB(pts[1]);
	setC(pts[2]);

	this->color = color;
}

Triangle::Triangle(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	setA(pts[0]);
	setB(pts[0]);
	setC(pts[0]);

	this->color = color;
}

Point Triangle::getA() const noexcept
{
	return pts[0];
}

Point Triangle::getB() const noexcept
{
	return pts[1];
}

Point Triangle::getC() const noexcept
{
	return pts[2];
}

Triangle::Color Triangle::getColor() const noexcept
{
	return (color); // rengin degerini döndürür
}

string Triangle::getColorAsString() const noexcept
{
	return Triangle::colorToStringMap.at(color); // rengin degerine karsýlýk biz ne string yazdýysak o döner
}

double Triangle::getPerimeter() const noexcept // kenarlarýn uzunlugunu hesaplar
{
	double ab_k = sqrt((pts[0].x - pts[1].x) * (pts[0].x - pts[1].x) + (pts[0].y - pts[1].y) * (pts[0].y - pts[1].y));
	double bc_k = sqrt((pts[1].x - pts[2].x) * (pts[1].x - pts[2].x) + (pts[1].y - pts[2].y) * (pts[1].y - pts[2].y));
	double ac_k = sqrt((pts[0].x - pts[2].x) * (pts[0].x - pts[2].x) + (pts[0].y - pts[2].y) * (pts[0].y - pts[2].y));

	return a_b + b_c + a_c;
}

bool Triangle::setA(const Point& pt)
{
	pts[0].x = pt.x;
	pts[0].y = pt.y;

	return false;
}

bool Triangle::setB(const Point& pt)
{
	pts[1].x = pt.x;
	pts[1].y = pt.y;

	return false;
}

bool Triangle::setC(const Point& pt)
{
	pts[2].x = pt.x;
	pts[2].y = pt.y;

	return false;
}

bool Triangle::isValid() const
{
	try {
		double a_b = sqrt((pts[0].x - pts[1].x) * (pts[0].x - pts[1].x) + (pts[0].y - pts[1].y) * (pts[0].y - pts[1].y));
		double b_c = sqrt((pts[1].x - pts[2].x) * (pts[1].x - pts[2].x) + (pts[1].y - pts[2].y) * (pts[1].y - pts[2].y));
		double a_c = sqrt((pts[0].x - pts[2].x) * (pts[0].x - pts[2].x) + (pts[0].y - pts[2].y) * (pts[0].y - pts[2].y));

		if (a_b + b_c > a_c&& a_b + a_c > b_c&& a_c + b_c > a_b&& a_b - b_c < a_c && a_b - a_c < b_c && b_c - a_c < a_b && a_b>0 && b_c> 0 && a_c>0) {
			return true;
		}
		else {
			throw invalid_argument("Girdiginiz degerler ucgen belirtmiyor..."); // hatayý fýrlatýr
		}
	}
	catch (const std::invalid_argument & ia) {  // yakalar
		std::cerr << "Invalid argument: " << ia.what() << endl;
	}
	return false;
}

double Triangle::printInfo() const noexcept // bilgileri basar
{
	std::cout << "Ucgen" << endl;
	std::cout << "Kose Sayisi : 3" << endl;
	std::cout << "Koseler;" << endl;
	std::cout << "(" << pts[0].x << ", " << pts[0].y << ")";
	std::cout << "(" << pts[1].x << ", " << pts[1].y << ")";
	std::cout << "(" << pts[2].x << ", " << pts[2].y << ")" << endl;

	std::cout << "Cevre: " << Triangle::getPerimeter() << endl;
	std::cout << "Renk:" << Triangle::colorToStringMap.at(color) << endl;

	return 0;
}
