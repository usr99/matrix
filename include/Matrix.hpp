/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:24:38 by mamartin          #+#    #+#             */
/*   Updated: 2022/06/23 17:15:14 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP

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

		T trace() const
		{
			static_assert(Rows == Columns, "Trace function is not defined for non-square matrices");
			T sum = T();
			for (size_t i = 0; i < _mData.size(); i++)
				sum += _mData[i][i];
			return sum;
		}

		Matrix<Columns, Rows, T> transpose() const
		{
			Matrix<Columns, Rows, T> result;

			for (length_t i = 0; i < Rows; i++)
			{
				for (length_t j = 0; j < Columns; j++)
					result[j][i] = _mData[i][j];
			}
			return result;
		}

		Matrix& row_echelon()
		{
			int lead = 0;

			for (int row = 0; row < Rows; row++)
			{
				if (Columns <= lead)
					return *this;

				int i = row;
				while (_mData[i][lead] == 0)
				{
					i++;
					if (i == Rows)
					{
						i = row;
						lead++;
						if (Columns == lead)
							return *this;
					}
				}

				if (i != row)
					std::swap(_mData[i], _mData[row]);
				_mData[row] /= _mData[row][lead];

				for (int j = 0; j < Rows; j++)
				{
					if (j != row)
						_mData[j] -= _mData[row] * _mData[j][lead];
				}

				lead++;
			}

			return *this;
		}

		T determinant() const
		{
			return T();
		}

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

template <length_t M, length_t N, length_t P, typename T>
Matrix<M, P, T> operator*(const Matrix<M, N, T>& lhs, const Matrix<N, P, T>& rhs)
{
	auto dot_product = [&](length_t row, length_t col) {
		T sum = T();
		for (length_t i = 0; i < N; i++)
			sum = std::fma(lhs[row][i], rhs[i][col], sum);
		return sum;
	};

	Matrix<M, P, T> result;
	for (length_t row = 0; row < M; row++)
	{
		for (length_t col = 0; col < P; col++)
			result[row][col] = dot_product(row, col);
	}
	return result;
}

#endif
