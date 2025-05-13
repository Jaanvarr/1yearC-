#pragma once
#include <iostream>
#include <math.h>
#include <time.h>

class Vector {
public:

	Vector() : capacity(1), size(0), vector(nullptr) {}

	Vector(size_t num) : capacity(num), size(num) {
		vector = new int[num];
	}

	Vector(size_t num, int n) : capacity(num), size(num) {
		vector = new int[num];
		for (size_t i = 0; i < num; i++)
		{
			vector[i] = n;
		}
	}

	Vector(const Vector& other) {
		size = other.size;
		capacity = other.capacity;
		vector = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			vector[i] = other.vector[i];
		}
	}

	Vector& operator=(const Vector& other) {
		Vector tmp(other);
		return tmp;
	}

	Vector(Vector&& other) noexcept {

		size = other.size;
		capacity = other.capacity;
		other.capacity = 1;
		other.size = 0;
		vector = nullptr;
		std::swap(vector, other.vector);
	}



	Vector& operator=(Vector&& other) noexcept {
		size = other.size;
		capacity = other.capacity;
		delete[] vector;
		vector = new int[1];
		std::swap(vector, other.vector);
		other.capacity = 1;
		other.size = 0;
	}

	int& operator[](size_t ind) {
		if (ind < size)
			return vector[ind];
	}

	const int operator[](size_t ind) const {
		if (ind < size)
			return vector[ind];
	}

	void resize() {
		if (size <= capacity) {
			int* tmp = new int[capacity];
			for (size_t i = 0; i < size; i++)
			{
				tmp[i] = vector[i];
			}
			delete[] vector;
			capacity *= 2;
			vector = new int[capacity];
			for (size_t i = 0; i < size; i++)
			{
				vector[i] = tmp[i];
			}
			delete[] tmp;
		}
	}


	void Fill(size_t param = 100) {
		for (size_t i = 0; i < size; i++)
		{
			vector[i] = rand() % param;
		}
	}

	size_t Size() const {
		return size;
	}

	size_t Capacity() const {
		return capacity;
	}

	~Vector() {
		delete[] vector;
	}

private:
	size_t capacity;
	size_t size;
	int* vector;


};

std::ostream& operator<<(std::ostream& out, const Vector& v) {
	for (size_t i = 0; i < v.Size(); i++)
	{
		out << v[i] << " ";
	}
	return out;
}

void operator>>(std::istream& in, Vector& v) {
	for (size_t i = 0; i < v.Size(); i++)
	{
		in >> v[i];
	}
}