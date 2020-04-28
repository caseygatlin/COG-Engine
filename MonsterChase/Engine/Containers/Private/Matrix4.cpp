#include "../Public/Matrix4.h"
#include "../Public/Vector4.h"
#include "../../Helpers/Public/FloatHelpers.h"

namespace Engine
{
	Matrix4& Matrix4::operator=(const Matrix4& i_rhs)
	{
		if (this != &i_rhs)
		{

			m_R1C1 = i_rhs.m_R1C1;
			m_R1C2 = i_rhs.m_R1C2;
			m_R1C3 = i_rhs.m_R1C3;
			m_R1C4 = i_rhs.m_R1C4;
			m_R2C1 = i_rhs.m_R2C1;
			m_R2C2 = i_rhs.m_R2C2;
			m_R2C3 = i_rhs.m_R2C3;
			m_R2C4 = i_rhs.m_R2C4;
			m_R3C1 = i_rhs.m_R3C1;
			m_R3C2 = i_rhs.m_R3C2;
			m_R3C3 = i_rhs.m_R3C3;
			m_R3C4 = i_rhs.m_R3C4;
			m_R4C1 = i_rhs.m_R4C1;
			m_R4C2 = i_rhs.m_R4C2;
			m_R4C3 = i_rhs.m_R4C3;
			m_R4C4 = i_rhs.m_R4C4;

		}

		return (*this);
	}

	Matrix4 Matrix4::GetInverse() const
	{
		// Calculate the minors to make the matrix of minors.
		// -- First Row --
		float minor_R1C1 = Det3x3(
			m_R2C2, m_R2C3, m_R2C4,
			m_R3C2, m_R3C3, m_R3C4,
			m_R4C2, m_R4C3, m_R4C4
			);

		float minor_R1C2 = Det3x3(
			m_R2C1, m_R2C3, m_R2C4,
			m_R3C1, m_R3C3, m_R3C4,
			m_R4C1, m_R4C3, m_R4C4
			);

		float minor_R1C3 = Det3x3(
			m_R2C1, m_R2C2, m_R2C4,
			m_R3C1, m_R3C2, m_R3C4,
			m_R4C1, m_R4C2, m_R4C4
			);

		float minor_R1C4 = Det3x3(
			m_R2C1, m_R2C2, m_R2C3,
			m_R3C1, m_R3C2, m_R3C3,
			m_R4C1, m_R4C2, m_R4C3
			);

		// -- Second Row --
		float minor_R2C1 = Det3x3(
			m_R1C2, m_R1C3, m_R1C4,
			m_R3C2, m_R3C3, m_R3C4,
			m_R4C2, m_R4C3, m_R4C4
			);

		float minor_R2C2 = Det3x3(
			m_R1C1, m_R1C3, m_R1C4,
			m_R3C1, m_R3C3, m_R3C4,
			m_R4C1, m_R4C3, m_R4C4
			);

		float minor_R2C3 = Det3x3(
			m_R1C1, m_R1C2, m_R1C4,
			m_R3C1, m_R3C2, m_R3C4,
			m_R4C1, m_R4C2, m_R4C4
			);

		float minor_R2C4 = Det3x3(
			m_R1C1, m_R1C2, m_R1C3,
			m_R3C1, m_R3C2, m_R3C3,
			m_R4C1, m_R4C2, m_R4C3
			);

		// -- Third Row --
		float minor_R3C1 = Det3x3(
			m_R1C2, m_R1C3, m_R1C4,
			m_R2C2, m_R2C3, m_R2C4,
			m_R4C2, m_R4C3, m_R4C4
			);

		float minor_R3C2 = Det3x3(
			m_R1C1, m_R1C3, m_R1C4,
			m_R2C1, m_R2C3, m_R2C4,
			m_R4C1, m_R4C3, m_R4C4
			);

		float minor_R3C3 = Det3x3(
			m_R1C1, m_R1C2, m_R1C4,
			m_R2C1, m_R2C2, m_R2C4,
			m_R4C1, m_R4C2, m_R4C4
			);

		float minor_R3C4 = Det3x3(
			m_R1C1, m_R1C2, m_R1C3,
			m_R2C1, m_R2C2, m_R2C3,
			m_R4C1, m_R4C2, m_R4C3
			);

		// -- Fourth Row --
		float minor_R4C1 = Det3x3(
			m_R1C2, m_R1C3, m_R1C4,
			m_R2C2, m_R2C3, m_R2C4,
			m_R3C2, m_R3C3, m_R3C4
			);

		float minor_R4C2 = Det3x3(
			m_R1C1, m_R1C3, m_R1C4,
			m_R2C1, m_R2C3, m_R2C4,
			m_R3C1, m_R3C3, m_R3C4
			);

		float minor_R4C3 = Det3x3(
			m_R1C1, m_R1C2, m_R1C4,
			m_R2C1, m_R2C2, m_R2C4,
			m_R3C1, m_R3C2, m_R3C4
			);

		float minor_R4C4 = Det3x3(
			m_R1C1, m_R1C2, m_R1C3,
			m_R2C1, m_R2C2, m_R2C3,
			m_R3C1, m_R3C2, m_R3C3
			);

		Matrix4 cofactorMatrix(
			minor_R1C1, minor_R1C2 * -1, minor_R1C3, minor_R1C4 * -1,
			minor_R2C1 * -1, minor_R2C2, minor_R2C3 * -1, minor_R2C4,
			minor_R3C1, minor_R3C2 * -1, minor_R3C3, minor_R3C4 * -1,
			minor_R4C1 * -1, minor_R4C2, minor_R4C3 * -1, minor_R4C4
			);

		cofactorMatrix.Transpose();

		Vector4 cofactorR1 = cofactorMatrix.GetRow(1);

		float determinant4x4 = m_R1C1 * cofactorR1.X() + m_R1C2 * cofactorR1.Y() + m_R1C3 * cofactorR1.Z() + m_R1C4 * cofactorR1.W();

		Matrix4 inverseMatrix;

		if (!Helpers::CompareZeroF(determinant4x4))
		{

			float determinantReciprocal = 1.0f / determinant4x4;

			inverseMatrix = determinantReciprocal * cofactorMatrix;

		}

		return inverseMatrix;
	}

	Matrix4 Matrix4::GetTranspose() const
	{

		return Matrix4(
			m_R1C1, m_R2C1, m_R3C1, m_R4C1,
			m_R1C2, m_R2C2, m_R3C2, m_R4C2,
			m_R1C3, m_R2C3, m_R3C3, m_R4C3,
			m_R1C4, m_R2C4, m_R3C4, m_R4C4
			);

	}

	void Matrix4::Invert()
	{
		(*this) = GetInverse();
	}

	void Matrix4::Transpose()
	{
		(*this) = GetTranspose();
	}

	float Matrix4::Det2x2(const float& i_R1C1, const float& i_R1C2, const float& i_R2C1, const float& i_R2C2) const
	{
		return i_R1C1 * i_R2C2 - i_R1C2 * i_R2C1;
	}

	float Matrix4::Det3x3(const float& i_R1C1, const float& i_R1C2, const float& i_R1C3, const float& i_R2C1, const float& i_R2C2, const float& i_R2C3, const float& i_R3C1, const float& i_R3C2, const float& i_R3C3) const
	{
		return i_R1C1 * Det2x2(i_R2C2, i_R2C3, i_R3C2, i_R3C3) - i_R1C2 * Det2x2(i_R2C1, i_R2C3, i_R3C1, i_R3C3) + i_R1C3 * Det2x2(i_R2C1, i_R2C2, i_R3C1, i_R3C2);
	}

	Matrix4 operator*(const Matrix4& i_lhs, const Matrix4& i_rhs)
	{

		float	o_R1C1, o_R1C2, o_R1C3, o_R1C4,
				o_R2C1, o_R2C2, o_R2C3, o_R2C4,
				o_R3C1, o_R3C2, o_R3C3, o_R3C4,
				o_R4C1, o_R4C2, o_R4C3, o_R4C4;

		Vector4 lhs_R1 = i_lhs.GetRow(1);
		Vector4 lhs_R2 = i_lhs.GetRow(2);
		Vector4 lhs_R3 = i_lhs.GetRow(3);
		Vector4 lhs_R4 = i_lhs.GetRow(4);

		Vector4 rhs_R1 = i_rhs.GetRow(1);
		Vector4 rhs_R2 = i_rhs.GetRow(2);
		Vector4 rhs_R3 = i_rhs.GetRow(3);
		Vector4 rhs_R4 = i_rhs.GetRow(4);


		// Row 1 of the resulting matrix
		o_R1C1 =  lhs_R1.X() * rhs_R1.X();
		o_R1C1 += lhs_R1.Y() * rhs_R2.X();
		o_R1C1 += lhs_R1.Z() * rhs_R3.X();
		o_R1C1 += lhs_R1.W() * rhs_R4.X();

		o_R1C2 =  lhs_R1.X() * rhs_R1.Y();
		o_R1C2 += lhs_R1.Y() * rhs_R2.Y();
		o_R1C2 += lhs_R1.Z() * rhs_R3.Y();
		o_R1C2 += lhs_R1.W() * rhs_R4.Y();

		o_R1C3 =  lhs_R1.X() * rhs_R1.Z();
		o_R1C3 += lhs_R1.Y() * rhs_R2.Z();
		o_R1C3 += lhs_R1.Z() * rhs_R3.Z();
		o_R1C3 += lhs_R1.W() * rhs_R4.Z();

		o_R1C4 =  lhs_R1.X() * rhs_R1.W();
		o_R1C4 += lhs_R1.Y() * rhs_R2.W();
		o_R1C4 += lhs_R1.Z() * rhs_R3.W();
		o_R1C4 += lhs_R1.W() * rhs_R4.W();

		// Row 2 of the resulting matrix
		o_R2C1 =  lhs_R2.X() * rhs_R1.X();
		o_R2C1 += lhs_R2.Y() * rhs_R2.X();
		o_R2C1 += lhs_R2.Z() * rhs_R3.X();
		o_R2C1 += lhs_R2.W() * rhs_R4.X();

		o_R2C2 =  lhs_R2.X() * rhs_R1.Y();
		o_R2C2 += lhs_R2.Y() * rhs_R2.Y();
		o_R2C2 += lhs_R2.Z() * rhs_R3.Y();
		o_R2C2 += lhs_R2.W() * rhs_R4.Y();

		o_R2C3 =  lhs_R2.X() * rhs_R1.Z();
		o_R2C3 += lhs_R2.Y() * rhs_R2.Z();
		o_R2C3 += lhs_R2.Z() * rhs_R3.Z();
		o_R2C3 += lhs_R2.W() * rhs_R4.Z();

		o_R2C4 =  lhs_R2.X() * rhs_R1.W();
		o_R2C4 += lhs_R2.Y() * rhs_R2.W();
		o_R2C4 += lhs_R2.Z() * rhs_R3.W();
		o_R2C4 += lhs_R2.W() * rhs_R4.W();

		// Row 3 of the resulting matrix
		o_R3C1 =  lhs_R3.X() * rhs_R1.X();
		o_R3C1 += lhs_R3.Y() * rhs_R2.X();
		o_R3C1 += lhs_R3.Z() * rhs_R3.X();
		o_R3C1 += lhs_R3.W() * rhs_R4.X();

		o_R3C2 =  lhs_R3.X() * rhs_R1.Y();
		o_R3C2 += lhs_R3.Y() * rhs_R2.Y();
		o_R3C2 += lhs_R3.Z() * rhs_R3.Y();
		o_R3C2 += lhs_R3.W() * rhs_R4.Y();

		o_R3C3 =  lhs_R3.X() * rhs_R1.Z();
		o_R3C3 += lhs_R3.Y() * rhs_R2.Z();
		o_R3C3 += lhs_R3.Z() * rhs_R3.Z();
		o_R3C3 += lhs_R3.W() * rhs_R4.Z();

		o_R3C4 =  lhs_R3.X() * rhs_R1.W();
		o_R3C4 += lhs_R3.Y() * rhs_R2.W();
		o_R3C4 += lhs_R3.Z() * rhs_R3.W();
		o_R3C4 += lhs_R3.W() * rhs_R4.W();

		// Row 4 of the resulting matrix
		o_R4C1 =  lhs_R4.X() * rhs_R1.X();
		o_R4C1 += lhs_R4.Y() * rhs_R2.X();
		o_R4C1 += lhs_R4.Z() * rhs_R3.X();
		o_R4C1 += lhs_R4.W() * rhs_R4.X();

		o_R4C2 =  lhs_R4.X() * rhs_R1.Y();
		o_R4C2 += lhs_R4.Y() * rhs_R2.Y();
		o_R4C2 += lhs_R4.Z() * rhs_R3.Y();
		o_R4C2 += lhs_R4.W() * rhs_R4.Y();

		o_R4C3 =  lhs_R4.X() * rhs_R1.Z();
		o_R4C3 += lhs_R4.Y() * rhs_R2.Z();
		o_R4C3 += lhs_R4.Z() * rhs_R3.Z();
		o_R4C3 += lhs_R4.W() * rhs_R4.Z();

		o_R4C4 =  lhs_R4.X() * rhs_R1.W();
		o_R4C4 += lhs_R4.Y() * rhs_R2.W();
		o_R4C4 += lhs_R4.Z() * rhs_R3.W();
		o_R4C4 += lhs_R4.W() * rhs_R4.W();

		return Matrix4(
			o_R1C1, o_R1C2, o_R1C3, o_R1C4,
			o_R2C1, o_R2C2, o_R2C3, o_R2C4,
			o_R3C1, o_R3C2, o_R3C3, o_R3C4,
			o_R4C1, o_R4C2, o_R4C3, o_R4C4
			);

	}

	Matrix4 operator*(const float& i_lhs, const Matrix4& i_rhs)
	{
		Vector4 rhs_R1 = i_rhs.GetRow(1);
		Vector4 rhs_R2 = i_rhs.GetRow(2);
		Vector4 rhs_R3 = i_rhs.GetRow(3);
		Vector4 rhs_R4 = i_rhs.GetRow(4);

		rhs_R1 *= i_lhs;
		rhs_R2 *= i_lhs;
		rhs_R3 *= i_lhs;
		rhs_R4 *= i_lhs;

		return Matrix4(rhs_R1, rhs_R2, rhs_R3, rhs_R4);
	}

	Vector4 operator*(const Matrix4& i_lhs, const Vector4& i_rhs)
	{
		return Vector4(
			dot(i_lhs.GetRow(1), i_rhs),
			dot(i_lhs.GetRow(2), i_rhs),
			dot(i_lhs.GetRow(3), i_rhs),
			dot(i_lhs.GetRow(4), i_rhs)
			);
	}

	Vector4 operator*(const Vector4& i_lhs, const Matrix4& i_rhs)
	{
		return Vector4(
			dot(i_rhs.GetColumn(1), i_lhs),
			dot(i_rhs.GetColumn(2), i_lhs),
			dot(i_rhs.GetColumn(3), i_lhs),
			dot(i_rhs.GetColumn(4), i_lhs)
			);
	}


}