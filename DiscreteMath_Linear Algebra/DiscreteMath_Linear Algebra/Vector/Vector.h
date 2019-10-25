#pragma once

#include<string>
using namespace std;

class Vector
{
private:
	// Attiribute:
	int n_dim;
	double* arr_n_dim_vector;

public:
	// Getter:
	int get_dim();
	double* get_arr_vector();
	double get_at_arr_vector(int _i);

	// Constructor:
	Vector();

	// Destructor
	~Vector();

	// Overloading
	Vector& operator = (const Vector &);
	friend istream& operator >> (istream& in, Vector&);
	friend ostream& operator << (ostream& out, const Vector&);
	Vector& operator + (Vector &);
	Vector& operator * (int k);

	// Method
	void main_menu();

};

