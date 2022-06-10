/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:20:58 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/09 23:52:55 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <array>
# include <vector>
# include <functional>
# include <algorithm>
# include <cmath>
# include <numeric>

# include "lib.hpp"

typedef unsigned short length_t;

template <length_t L, typename T>
struct Vector
{
public:
	/* Default constructor */
	Vector() : _mData() {}
	/* Initialization constructor */
	Vector(std::initializer_list<T> il) : Vector()
	{
		std::copy(il.begin(), il.end(), _mData.begin());
	}
	/* Copy constructor */
	Vector(const Vector& rhs) { *this = rhs; }

	/* Methods */
	T dot(const Vector& rhs) const
	{
		T result = T();

		for (length_t i = 0; i < L; i++)
			result = std::fma(_mData[i], rhs._mData[i], result);
		return result;
	}

	float norm_1() const
	{
		return std::accumulate(_mData.begin(), _mData.end(), 0.f, [](T sum, T value) {
			return sum + abs(value);
		});
	}

	float norm() const
	{
		return std::pow(dot(*this), 0.5);
	}

	float norm_inf() const
	{
		return *std::max_element(_mData.begin(), _mData.end(), [](T a, T b) {
			return (abs(a) < abs(b));
		});
	}

	/* Capacity & Element access */
	constexpr length_t size() const { return L; }
	const T& x() const { return _at<0>(); }
	const T& y() const { return _at<1>(); }
	const T& z() const { return _at<2>(); }
	const T& w() const { return _at<3>(); }
	T& x() { return _at<0>(); }
	T& y() { return _at<1>(); }
	T& z() { return _at<2>(); }
	T& w() { return _at<3>(); }
	const T& operator[](length_t n) const { return _mData.at(n); }
	T& operator[](length_t n) { return _mData.at(n); }

	/* Operator overloads */
	Vector& operator=(const Vector& rhs)
	{
		std::copy(rhs._mData.begin(), rhs._mData.end(), _mData.begin());
		return *this;
	}
	/* Arithmetic */
	Vector operator+(const Vector& rhs) const
	{
		Vector result;

		for (length_t i = 0; i < L; i++)
			result[i] = _mData[i] + rhs._mData[i];
		return result;
	}

	Vector& operator+=(const Vector& rhs)
	{
		*this = operator+(rhs);
		return *this;
	}

	Vector operator-() const
	{
		return *this * -1;
	}

	Vector operator-(const Vector& rhs) const
	{
		return *this + (-rhs);
	}

	Vector operator*(const T &n) const
	{
		Vector result;

		for (length_t i = 0; i < L; i++)
			result[i] = _mData[i] * n;
		return result;
	}

	friend std::ostream& operator<<(std::ostream &os, const Vector&v)
	{
		os << '[';
		std::for_each(v._mData.begin(), v._mData.end() - 1, [&os](T val)
					  { os << val << ", "; });
		os << v._mData.back() << ']';
		return os;
	}

private:
	template <length_t Index>
	T& _at()
	{
		static_assert(L > Index, "undefined coordinate");
		return _mData[Index];
	}

	template <length_t Index>
	const T& _at() const
	{
		static_assert(L > Index, "undefined coordinate");
		return _mData[Index];
	}

	std::array<T, L> _mData;
};

template <length_t L, typename T>
Vector<L, T> linear_combination(const std::vector<Vector<L, T>>& u, const std::vector<T>& coefs)
{
	if (u.size() != coefs.size())
		throw std::range_error("linear_combination: inputs sizes differ");

	Vector<L, T> result;
	for (size_t i = 0; i < u.size(); i++)
		result += u[i] * coefs[i];
	return result;
}

template <length_t L, typename T>
Vector<L, T> lerp(const Vector<L, T>& u, const Vector<L, T>& v, float t)
{
	Vector<L, T> result;

	for (length_t i = 0; i < L; i++)
		result[i] = lerp(u[i], v[i], t);
	return result;
}

template <length_t L, typename T>
float angle_cos(const Vector<L, T>& u, const Vector<L, T>& v)
{
	return u.dot(v) / (u.norm() * v.norm());
}

template <typename T>
Vector<3, T> cross_product(const Vector<3, T>& u, const Vector<3, T>& v)
{
	return Vector<3, T>({
		std::fma(u.y(), v.z(), -(v.y() * u.z())),
		std::fma(u.z(), v.x(), -(v.z() * u.x())),
		std::fma(u.x(), v.y(), -(v.x() * u.y()))
	});
}

#endif
