#include "Quadrilateral.h"
#include <array>
#include <string>
#include <map>
#include "Point.h"
#include <iostream>
#include <stdexcept>



Quadrilateral::Quadrilateral(const Point& a, const Point& c, const Color& color)
{
	setA(a);
	setC(c);

	pts[1].x = c.x; // B noktasýnýn x deðeri c noktasýnýn x deðerine eþittir diðerleri de 0=a, 1=b, 2=c,3=d olacak þekilde atanmýþtýr  
	pts[1].y = a.y;

	pts[3].y = c.y;
	pts[3].x = a.x;

	this->color = color;
	isValid();
}

Quadrilateral::Quadrilateral(const Point& a, double width, double height, const Color& color)
{
	pts[0].x = a.x;

	pts[0].y = a.y;

	pts[1].x = a.x + width; // a noktasýnýn x degerine geniþlik eklendiðinde b kenarýnýn x'ine ulaþýlýr

	pts[1].y = a.y;

	pts[2].x = pts[1].x;

	pts[2].y = pts[1].y + height; // b noktasýnýn y'sine yükseklik eklendiðinde c noktasýnýn y'sine ulaþýlýr

	pts[3].x = a.x;

	pts[3].y = pts[2].y;

	this->color = color; // this ile private'daki colora iþaret ediyoruz 

	isValid();
}

Quadrilateral::Quadrilateral(const Point& a, const Point& b, const Point& c, const Point& d, const Color& color)
{
	pts[0].x = a.x;

	pts[0].y = a.y;

	pts[1].x = b.x;

	pts[1].y = b.y;

	pts[2].x = c.x;

	pts[2].y = c.y;

	pts[3].x = d.x;

	pts[3].y = d.y;

	this->color = color;

}

Quadrilateral::Quadrilateral(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	this->pts[0].x = pts[0].x;
	this->pts[0].y = pts[0].y;
	this->pts[1].x = pts[1].x;
	this->pts[1].y = pts[1].y;
	this->pts[2].x = pts[2].x;
	this->pts[2].y = pts[2].y;
	this->pts[3].x = pts[3].x;
	this->pts[3].y = pts[3].y;
	this->color = color;
	isValid();
}

Quadrilateral::Color Quadrilateral::getColor() const noexcept
{

	return (color); // rengin deðerini döndürür
}

string Quadrilateral::getColorAsString() const noexcept
{
	return Quadrilateral::colorToStringMap.at(color); // rengin bizim yazdýðýmýz string deðerini döndürür
}

double Quadrilateral::getPerimeter() const noexcept // kenar uzunluklarý hesaplanýyor
{
	double ab_k = sqrt((pts[0].x - pts[1].x) * (pts[0].x - pts[1].x) + (pts[0].y - pts[1].y) * (pts[0].y - pts[1].y));
	double ad_k = sqrt((pts[0].x - pts[3].x) * (pts[0].x - pts[3].x) + (pts[0].y - pts[3].y) * (pts[0].y - pts[3].y));
	double bc_k = sqrt((pts[1].x - pts[2].x) * (pts[1].x - pts[2].x) + (pts[1].y - pts[2].y) * (pts[1].y - pts[2].y));
	double cd_k = sqrt((pts[2].x - pts[3].x) * (pts[2].x - pts[3].x) + (pts[2].y - pts[3].y) * (pts[2].y - pts[3].y));

	return a_b * 2 + a_d * 2;
}

bool Quadrilateral::isValid() const
{
	double ab_k = sqrt((pts[0].x - pts[1].x) * (pts[0].x - pts[1].x) + (pts[0].y - pts[1].y) * (pts[0].y - pts[1].y));
	double ad_k = sqrt((pts[0].x - pts[3].x) * (pts[0].x - pts[3].x) + (pts[0].y - pts[3].y) * (pts[0].y - pts[3].y));
	double bc_k = sqrt((pts[1].x - pts[2].x) * (pts[1].x - pts[2].x) + (pts[1].y - pts[2].y) * (pts[1].y - pts[2].y));
	double cd_k = sqrt((pts[2].x - pts[3].x) * (pts[2].x - pts[3].x) + (pts[2].y - pts[3].y) * (pts[2].y - pts[3].y));

	try {
		if (a_b == c_d && a_d == b_c && a_b > 0 && a_d > 0 && b_c > 0 && c_d > 0) {
			return true;
		}
		else {
			throw "Girilen degerler dortgen belirtmiyor... "; // hatayý fýrlatýyor
		}
	}
	catch (const std::invalid_argument & ia) { // yakalýyor
		std::cerr << "Invalid argument: " << ia.what() << endl;
		return false;
	}
}

bool Quadrilateral::setA(const Point& pt)
{
	pts[0].x = pt.x; // a noktasýnýn koordinat degerleri b,c ve d de asagýda
	pts[0].y = pt.y;
	return false;
}

bool Quadrilateral::setB(const Point& pt)
{
	pts[1].x = pt.x;
	pts[1].y = pt.y;
	return false;
}

bool Quadrilateral::setC(const Point& pt)
{
	pts[2].x = pt.x;
	pts[2].y = pt.y;
	return false;
}

bool Quadrilateral::setD(const Point& pt)
{
	pts[3].x = pt.x;
	pts[3].y = pt.y;
	return false;
}

double Quadrilateral::printInfo() const noexcept // dörtgenin bilgilerini basar
{
	std::cout << "Dikdortgen" << endl;
	std::cout << "Kose Sayýsý : 4" << endl;
	std::cout << "Koseler;" << endl;
	std::cout << "(" << pts[0].x << ", " << pts[0].y << "),";
	std::cout << "(" << pts[1].x << ", " << pts[1].y << "),";
	std::cout << "(" << pts[2].x << ", " << pts[2].y << "),";
	std::cout << "(" << pts[3].x << ", " << pts[3].y << ")" << endl;
	std::cout << "Cevre: " << getPerimeter() << endl;
	std::cout << "Renk:" << Quadrilateral::colorToStringMap.at(color) << endl;
	return 0.0;
}

Point Quadrilateral::getA() const noexcept
{

	return pts[0];
}

Point Quadrilateral::getB() const noexcept
{
	return pts[1];
}

Point Quadrilateral::getC() const noexcept
{
	return pts[2];
}

Point Quadrilateral::getD() const noexcept
{
	return pts[3];
}
