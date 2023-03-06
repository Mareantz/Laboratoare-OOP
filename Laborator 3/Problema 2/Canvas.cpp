#include "Canvas.h"
#include <cstring>
#include <iostream>
#include <stdlib.h>

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	this->c = (char**)(malloc(height * sizeof(char*)));
	for (int i = 0; i < height; i++)
		this->c[i] = (char*)(malloc(width * sizeof(char)));
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			this->c[i][j] = ' ';
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	if (left < 0 || right < 0 || top < 0 || bottom < 0)
		return;
	for (int i = left; i <= right; i++)
		this->c[i][bottom] = ch;
	for (int i = left; i <= right; i++)
		this->c[i][top] = ch;
	for(int i = bottom; i <= top; i++)
		this->c[left][i] = ch;
	for (int i = bottom; i <= top; i++)
		this->c[right][i] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	if (left < 0 || right < 0 || top < 0 || bottom < 0)
		return;
	for (int i = top; i >= bottom; i--)
		for (int j = left; j <= right; j++)
			this->c[i][j] = ch;
}

void Canvas::Print()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
			std::cout << this->c[i][j];
		std::cout << std::endl;
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < this->height; i++)
		for (int j = 0; j < this->width; j++)
			this->c[i][j] = ' ';
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if(x<0||y<0)
		return;
	this->c[x][y] = ch;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	if (x < 0 || y < 0 || x < ray || y < ray)
		return;
	for (int i = ray+x; i >= ray-x; i--)
		for (int j = ray-x; j <= ray+x; j++)
		{
			if ((((i - x) * (i - x) + (j - y) * (j - y)) >= ray * (ray - 1)) && (((i - x) * (i - x) + (j - y) * (j - y)) <= ray * (ray + 1)))
				this->c[i][j] = ch;
		}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = ray + x; i >= ray - x; i--)
		for (int j = ray - x; j <= ray + x; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
				this->c[i][j] = ch;
		}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int sx = x1 < x2 ? 1 : -1;
	int dy = -abs(y2 - y1);
	int sy = y1 < y2 ? 1 : -1;
	int error = dx + dy;
	int e2;
	while (true)
	{
		c[x1][y1] = ch;
		if (x1 == x2 && y1 == y2)
			break;
		e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x1 == x2)
				break;
			error = error + dy;
			x1 = x1 + sx;
		}
		if (e2 <= dx)
		{
			if (y1 == y2)
				break;
			error = error + dx;
			y1 = y1 + sy;
		}

	}
}
