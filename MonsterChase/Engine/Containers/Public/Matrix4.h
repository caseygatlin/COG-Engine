#pragma once

#include "Vector4.h"
#include "Point2D.h"

namespace Engine
{
	class Matrix4
	{
	public:

		static const Matrix4 IdentityMatrix;

		inline static Matrix4 ScaleMatrix(const float& i_xScale, const float& i_yScale, const float& i_zScale);

		inline static Matrix4 TranslationMatrix_RowVector(const float& i_xTranslation, const float& i_yTranslation, const float& i_zTranslation);
		inline static Matrix4 TranslationMatrix_ColVector(const float& i_xTranslation, const float& i_yTranslation, const float& i_zTranslation);
		inline static Matrix4 TranslationMatrix_RowVector(const Point2D& i_point);
		inline static Matrix4 TranslationMatrix_ColVector(const Point2D& i_point);

		inline static Matrix4 XRotationMatrix_RowVector(const float& i_angle_Radians);
		inline static Matrix4 YRotationMatrix_RowVector(const float& i_angle_Radians);
		inline static Matrix4 ZRotationMatrix_RowVector(const float& i_angle_Radians);

		inline static Matrix4 XRotationMatrix_ColVector(const float& i_angle_Radians);
		inline static Matrix4 YRotationMatrix_ColVector(const float& i_angle_Radians);
		inline static Matrix4 ZRotationMatrix_ColVector(const float& i_angle_Radians);

		Matrix4() :
			m_R1C1(0.0f), m_R1C2(0.0f), m_R1C3(0.0f), m_R1C4(0.0f),
			m_R2C1(0.0f), m_R2C2(0.0f), m_R2C3(0.0f), m_R2C4(0.0f),
			m_R3C1(0.0f), m_R3C2(0.0f), m_R3C3(0.0f), m_R3C4(0.0f),
			m_R4C1(0.0f), m_R4C2(0.0f), m_R4C3(0.0f), m_R4C4(0.0f)
		{}
		
		Matrix4(
			float  i_R1C1 , float  i_R1C2 , float  i_R1C3 , float  i_R1C4 ,
			float  i_R2C1 , float  i_R2C2 , float  i_R2C3 , float  i_R2C4 ,
			float  i_R3C1 , float  i_R3C2 , float  i_R3C3 , float  i_R3C4 ,
			float  i_R4C1 , float  i_R4C2 , float  i_R4C3 , float  i_R4C4 ) :

			m_R1C1(i_R1C1), m_R1C2(i_R1C2), m_R1C3(i_R1C3), m_R1C4(i_R1C4),
			m_R2C1(i_R2C1), m_R2C2(i_R2C2), m_R2C3(i_R2C3), m_R2C4(i_R2C4),
			m_R3C1(i_R3C1), m_R3C2(i_R3C2), m_R3C3(i_R3C3), m_R3C4(i_R3C4),
			m_R4C1(i_R4C1), m_R4C2(i_R4C2), m_R4C3(i_R4C3), m_R4C4(i_R4C4)
		{}

		Matrix4(const Vector4& i_R1, const Vector4& i_R2, const Vector4& i_R3, const Vector4& i_R4) :
			m_R1C1(i_R1.X()), m_R1C2(i_R1.Y()), m_R1C3(i_R1.Z()), m_R1C4(i_R1.W()),
			m_R2C1(i_R2.X()), m_R2C2(i_R2.Y()), m_R2C3(i_R2.Z()), m_R2C4(i_R2.W()),
			m_R3C1(i_R3.X()), m_R3C2(i_R3.Y()), m_R3C3(i_R3.Z()), m_R3C4(i_R3.W()),
			m_R4C1(i_R4.X()), m_R4C2(i_R4.Y()), m_R4C3(i_R4.Z()), m_R4C4(i_R4.W())
		{}


		Matrix4(const Matrix4& i_src) :
			m_R1C1(i_src.m_R1C1), m_R1C2(i_src.m_R1C2), m_R1C3(i_src.m_R1C3), m_R1C4(i_src.m_R1C4),
			m_R2C1(i_src.m_R2C1), m_R2C2(i_src.m_R2C2), m_R2C3(i_src.m_R2C3), m_R2C4(i_src.m_R2C4),
			m_R3C1(i_src.m_R3C1), m_R3C2(i_src.m_R3C2), m_R3C3(i_src.m_R3C3), m_R3C4(i_src.m_R3C4),
			m_R4C1(i_src.m_R4C1), m_R4C2(i_src.m_R4C2), m_R4C3(i_src.m_R4C3), m_R4C4(i_src.m_R4C4)
		{}

		Matrix4& operator=(const Matrix4& i_rhs);

		inline Vector4 GetRow(const size_t& i_row) const;
		inline Vector4 GetColumn(const size_t& i_column) const;
		Matrix4 GetInverse() const;
		Matrix4 GetTranspose() const;
		
		void Invert();
		void Transpose();

	private:

		float	m_R1C1, m_R1C2, m_R1C3, m_R1C4,
				m_R2C1, m_R2C2, m_R2C3, m_R2C4,
				m_R3C1, m_R3C2, m_R3C3, m_R3C4,
				m_R4C1, m_R4C2, m_R4C3, m_R4C4;

		float Det2x2(
			const float& i_R1C1, const float& i_R1C2,
			const float& i_R2C1, const float& i_R2C2
			) const;

		float Det3x3(
			const float& i_R1C1, const float& i_R1C2, const float& i_R1C3,
			const float& i_R2C1, const float& i_R2C2, const float& i_R2C3,
			const float& i_R3C1, const float& i_R3C2, const float& i_R3C3
			) const;
	};

	Matrix4 operator*(const Matrix4& i_lhs, const Matrix4& i_rhs);
	Matrix4 operator*(const float& i_lhs, const Matrix4& i_rhs);
	Vector4 operator*(const Matrix4& i_lhs, const Vector4& i_rhs);
	Vector4 operator*(const Vector4& i_lhs, const Matrix4& i_rhs);

	// Equal /Not Equal to
	bool operator==(const Matrix4& i_lhs, const Matrix4& i_rhs);
	bool operator!=(const Matrix4& i_lhs, const Matrix4& i_rhs);

}

#include "Matrix4-inl.h"