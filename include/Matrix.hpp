/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:24:38 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/10 00:30:36 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <tuple>
# include "Vector.hpp"

template <length_t Rows, length_t Columns, typename T>
struct Matrix
{
	public:

		typedef Vector<Columns, T> VectorType;

		struct Shape
		{
			length_t rows;
			length_t columns;

			friend std::ostream& operator<<(std::ostream& os, const Shape& s)
			{
				os << s.rows << 'x' << s.columns;
				return os;
			}
		};

		Matrix() : _mData()
		{
			if (isSquare())
			{
				for (size_t i = 0; i < _mData.size(); i++)
					_mData[i][i] = 1;
			}
		}
		Matrix(std::initializer_list<VectorType> il) : Matrix()
		{
			std::copy(il.begin(), il.end(), _mData.begin());
		}		
		Matrix(const Matrix& rhs) { *this = rhs; }

		constexpr bool isSquare() const { return Rows == Columns; }
		constexpr Shape getShape() const { return { Rows, Columns }; }

		Matrix& operator=(const Matrix& rhs)
		{
			for (size_t i = 0; i < _mData.size(); i++)
				_mData[i] = rhs._mData[i];
			return *this;
		}
		/* Arithmetic */
		Matrix operator+(const Matrix& rhs) const
		{
			Matrix result;

			for (size_t i = 0; i < _mData.size(); i++)
				result[i] = _mData[i] + rhs._mData[i];
			return result;
		}

		Matrix operator-() const
		{
			return *this * -1;
		}

		Matrix operator-(const Matrix& rhs) const
		{
			return *this + (-rhs);
		}

		Matrix operator*(const T& n) const
		{
			Matrix result;

			for (size_t i = 0; i < _mData.size(); i++)
				result[i] = _mData[i] * n;
			return result;
		}

		Vector<Rows, T> operator*(const Vector<Columns, T>& rhs) const
		{
			Vector<Rows, T> result;

			for (size_t i = 0; i < _mData.size(); i++)
				result[i] = _mData[i].dot(rhs);
			return result;
		}

		// VectorType operator*(const VectorType& rhs) const
		// {
		// 	VectorType result;

		// 	for (size_t i = 0; i < _mData.size(); i++)
		// 		result[i] = _mData[i].dot(rhs);
		// 	return result;
		// }

		const VectorType& operator[](length_t n) const
		{
			return _mData.at(n);
		}

		VectorType& operator[](length_t n)
		{
			return _mData.at(n);
		}

		friend std::ostream& operator<<(std::ostream& os, const Matrix& m)
		{
			std::for_each(m._mData.begin(), m._mData.end(), [&os](VectorType vec) {
				os << vec << '\n';
			});
			return os;
		}

	private:

		std::array<VectorType, Rows> _mData;
};

template <length_t R, length_t C, typename T>
Matrix<R, C, T> lerp(const Matrix<R, C, T>& u, const Matrix<R, C, T>& v, float t)
{
	Matrix<R, C, T> result;

	for (length_t i = 0; i < C; i++)
		result[i] = lerp(u[i], v[i], t);
	return result;
}

#endif
