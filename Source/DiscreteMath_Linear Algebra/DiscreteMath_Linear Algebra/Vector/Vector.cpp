#include "Vector.h"

#include<iostream>
#include<string>
#include<sstream>

// Methode using
using  std::cout;
using  std::cin;

// Sinh các getter của Object
int Vector::get_dim()
{
	return this->n_dim;
}

double* Vector::get_arr_vector()
{
	return this->arr_n_dim_vector;
}

double Vector::get_at_arr_vector(int _i)
{
	return this->arr_n_dim_vector[_i];
}

// Constructor Default
Vector::Vector()
{
	this->n_dim = -1;
}


// Overloading Operator =
Vector& Vector::operator=(const Vector& _v2)
{
	// TODO: insert return statement here
	if (this->arr_n_dim_vector != _v2.arr_n_dim_vector) {
		this->n_dim = _v2.n_dim;

		delete[] this->arr_n_dim_vector;
		arr_n_dim_vector = new double[this->n_dim];

		for (int i = 0; i < this->n_dim; i++) {
			arr_n_dim_vector[i] = _v2.arr_n_dim_vector[i];
		}
	}
	return *this;
}

// Overloading Operator >>
istream& operator>>(istream& in, Vector& v1)
{
	// TODO: insert return statement here
	cout << "__________________In Vector____________________" << endl;
	cout << "Enter dim of Vector V: ";
	in >> v1.n_dim;

	v1.arr_n_dim_vector = new double[v1.n_dim];

	cout << ">> Enter Vector V:" << endl;

	for (size_t i = 0; i < v1.n_dim; i++) {
		cout << "Value of dim " << i + 1 << ": ";
		in >> v1.arr_n_dim_vector[i];
	}

	cout << "Done !\n" << endl;

	return in;
}

// Overloading Operator <<
ostream& operator<<(ostream& out, const Vector& v1)
{
	// TODO: insert return statement here
	if (v1.n_dim == -1) {
		cout << "___________________Warnings_____________________" << endl;
		cout << "You must enter V1 before using this method !\n" << endl;

		return out;
	}

	out << "__________________Out Vector____________________" << endl;
	out << ">> [";

	int i;

	for (i = 0; i < v1.n_dim - 1; i++) {
		out << v1.arr_n_dim_vector[i] << ", ";
	}

	out << v1.arr_n_dim_vector[i];
	out << "]" << endl << endl;

	return out;
}

/*
Overloading +
Đầu ra: một Vector result = v1+v2
*/
Vector& Vector::operator+(Vector& v2)
{
	// TODO: insert return statement here
	if (this->n_dim == -1) {
		cout << "___________________Warnings_____________________" << endl;
		cout << "You must enter V1 before using this method !\n" << endl;

		cout << "Dim of V1: " << this->n_dim << endl;
		cout << "Dim of V2: " << v2.n_dim << endl << endl;
		return v2;
	}

	cin >> v2;

	if (v2.n_dim != this->n_dim) {
		cout << "___________________Warnings_____________________" << endl;
		cout << "Dim of two Vector are not similar !" << endl << endl;

		cout << "Dim of V1: " << this->n_dim << endl;
		cout << *this;

		cout << "Dim of V2: " << v2.n_dim << endl;
		return v2;
	}

	Vector *result = new Vector();
	result->n_dim = this->n_dim;
	result->arr_n_dim_vector = new double[this->n_dim];

	for (int i = 0; i < this->n_dim; i++) {
		result->arr_n_dim_vector[i] = this->arr_n_dim_vector[i] + v2.arr_n_dim_vector[i];
	}
	
	return *result;
}

Vector& Vector::operator*(int k)
{
	// TODO: insert return statement here
	if (this->n_dim == -1) {
		cout << "___________________Warnings_____________________" << endl;
		cout << "You must enter V1 before using this method !\n" << endl;

		return *this;
	}

	for (int i = 0; i < this->n_dim; i++) {
		this->arr_n_dim_vector[i] *= k;
	}

	return *this;
}

// Method launcher 
void Vector::main_menu()
{
	int choose = 0;
	Vector* v2 = new Vector();

	// Getting event from user
	do {
		system("cls");

		cout << "__________________MENU__________________\n"
			<< "1. Enter vector: \n"
			<< "2. Show vector: \n"
			<< "3. Add two vector: \n"
			<< "4. Multiple this vector with value k: \n"

			<< "_________________________________________\n"
			<< "Enter 0 to exit !\n"
			<< "You choose ? ";

		cin >> choose;

		switch (choose){
			case 1: {
				cin >> *this;
				break;
			}

			case 2: {
				cout << *this;
				break;
			}

			case 3: {
				Vector result = *this + *v2;

				if (result.get_dim() != -1) {
					cout << result;
				}

				break;
			}

			case 4: {
				int k;

				cout << "Enter value k: ";
				cin >> k;

				*this = *this * k;

				
				if (this->n_dim != -1) {
					cout << *this;
				}

				break;
			}

			case 0: {
				cout << "_________________________________________\n" << endl;
				cout << "\nThank for using !\n" << endl;
				fflush(stdin);
				cin.ignore();
				return;
			}
		}
		system("pause");

	} while (1);
}

Vector::~Vector()
{
	delete[] this->arr_n_dim_vector;
}