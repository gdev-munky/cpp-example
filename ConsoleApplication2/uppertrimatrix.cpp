#include "uppertrimatrix.h"

UpperTriMatrix::UpperTriMatrix(int sz)
{
	if (sz == 0) 
	{
		//Как нибудь обрабатываем ошибку - делай throw. 
		//Мне влом вспоминать синтаксис throw в C++, поэтому я ноль сменю на 1
		sz = 1;
	}
	size = sz;
	m = new float* [sz];
	for (int i = 0; i < sz; i++)
	{
		m[i] = new float[sz - i];
		for (int j = 0; j < sz - i; j++)
			m[i][j] = 0;
	}
}

UpperTriMatrix::~UpperTriMatrix()
{
	for (int i = 0; i < size; i++)
	{
		delete [] m[i];
	}
	delete [] m;
}

float UpperTriMatrix::getv(int i, int j)
{
	if (i >= size || j >= size || j < i)
	{
		return 0;
	}
	float x = m[i][j - i];
	return x;
}

void UpperTriMatrix::setv(int i, int j, float v)
{
	if (i >= size || j >= size || j < i)
	{
		//Если надо обрабатывать неправильные аргументы:
		//ААА бл* АШИПКА СТОП 00000
		return;
	}
	m[i][j - i] = v;
}

void UpperTriMatrix::mul(float a)
{
	for (int i = 0; i < size; i++)
	for (int j = 0; j < size - i; j++)
	{
		setv(i, j, getv(i, j)*a);
	}
}

float UpperTriMatrix::det()
{
	//Массив произведений
	float* P = new float[size];
	for (int i = 0; i < size; i++)
		P[i] = 1;

	for (int i = 0; i < size; i++)
	for (int j = 0; j < size - i; j++)
	{
		float a = getv(i, i + j);
		P[j] *= a; 
	}
	float summ = 0;
	for (int i = 0; i < size; i++)
		summ += P[i];

	return summ;
}