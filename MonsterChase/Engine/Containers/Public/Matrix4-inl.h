#pragma once

#include "Matrix4.h"

namespace Engine
{

	inline Matrix4 Matrix4::ScaleMatrix(const float& i_xScale, const float& i_yScale, const float& i_zScale)
	{
		return Matrix4(
			i_xScale, 0.0f		, 0.0f		, 0.0f, 
			0.0f	, i_yScale	, 0.0f		, 0.0f,
			0.0f	, 0.0f		, i_zScale	, 0.0f,
			0.0f	, 0.0f		, 0.0f		, 1.0f
			);
	}

	inline Matrix4 Matrix4::TranslationMatrix_RowVector(const float& i_xTranslation, const float& i_yTranslation, const float& i_zTranslation)
	{
		return Matrix4(
			1.0f			, 0.0f			, 0.0f			, 0.0f,
			0.0f			, 1.0f			, 0.0f			, 0.0f,
			0.0f			, 0.0f			, 1.0f			, 0.0f,
			i_xTranslation	, i_yTranslation, i_zTranslation, 1.0f
			);
	}

	inline Matrix4 Matrix4::TranslationMatrix_ColVector(const float& i_xTranslation, const float& i_yTranslation, const float& i_zTranslation)
	{
		return Matrix4(
			1.0f, 0.0f, 0.0f, i_xTranslation,
			0.0f, 1.0f, 0.0f, i_yTranslation,
			0.0f, 0.0f, 1.0f, i_zTranslation,
			0.0f, 0.0f, 0.0f, 1.0f
			);
	}

	inline Matrix4 Matrix4::TranslationMatrix_RowVector(const Point2D& i_point)
	{
		return TranslationMatrix_RowVector(i_point.X(), i_point.Y(), 0.0f);
	}

	inline Matrix4 Matrix4::TranslationMatrix_ColVector(const Point2D& i_point)
	{
		return TranslationMatrix_ColVector(i_point.X(), i_point.Y(), 0.0f);
	}

	inline Matrix4 Matrix4::XRotationMatrix_RowVector(const float& i_angle_Radians)
	{
		float sin = sinf(i_angle_Radians);
		float cos = cosf(i_angle_Radians);

		return Matrix4(
			1.0f, 0.0f	, 0.0f	, 0.0f,
			0.0f, cos	, sin	, 0.0f,
			0.0f, -sin	, cos	, 0.0f,
			0.0f, 0.0f	, 0.0f	, 1.0f
			);
	}

	inline Matrix4 Matrix4::YRotationMatrix_RowVector(const float& i_angle_Radians)
	{
		float sin = sinf(i_angle_Radians);
		float cos = cosf(i_angle_Radians);

		return Matrix4(
			cos	, 0.0f, -sin, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			sin	, 0.0f, cos	, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
			);
	}

	inline Matrix4 Matrix4::ZRotationMatrix_RowVector(const float& i_angle_Radians)
	{
		float sin = sinf(i_angle_Radians);
		float cos = cosf(i_angle_Radians);

		return Matrix4(
			cos	, sin	, 0.0f, 0.0f,
			-sin, cos	, 0.0f, 0.0f,
			0.0f, 0.0f	, 1.0f, 0.0f,
			0.0f, 0.0f	, 0.0f, 1.0f
			);
	}

	inline Matrix4 Matrix4::XRotationMatrix_ColVector(const float& i_angle_Radians)
	{
		float sin = sinf(i_angle_Radians);
		float cos = cosf(i_angle_Radians);

		return Matrix4(
			1.0f, 0.0f	, 0.0f	, 0.0f,
			0.0f, cos	, -sin	, 0.0f,
			0.0f, sin	, cos	, 0.0f,
			0.0f, 0.0f	, 0.0f	, 1.0f
			);
	}

	inline Matrix4 Matrix4::YRotationMatrix_ColVector(const float& i_angle_Radians)
	{
		float sin = sinf(i_angle_Radians);
		float cos = cosf(i_angle_Radians);

		return Matrix4(
			cos	, 0.0f, sin	, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			-sin, 0.0f, cos	, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
			);
	}

	inline Matrix4 Matrix4::ZRotationMatrix_ColVector(const float& i_angle_Radians)
	{
		float sin = sinf(i_angle_Radians);
		float cos = cosf(i_angle_Radians);

		return Matrix4(
			cos	, -sin	, 0.0f, 0.0f,
			sin	, cos	, 0.0f, 0.0f,
			0.0f, 0.0f	, 1.0f, 0.0f,
			0.0f, 0.0f	, 0.0f, 1.0f
			);
	}




	inline Vector4 Matrix4::GetRow(const size_t& i_row) const
	{

		switch (i_row)
		{

		case 1:
			return Vector4(m_R1C1, m_R1C2, m_R1C3, m_R1C4);
		case 2:
			return Vector4(m_R2C1, m_R2C2, m_R2C3, m_R2C4);
		case 3:
			return Vector4(m_R3C1, m_R3C2, m_R3C3, m_R3C4);
		case 4:
			return Vector4(m_R4C1, m_R4C2, m_R4C3, m_R4C4);

		default:
			return Vector4::ZeroVector;

		}
	}

	inline Vector4 Matrix4::GetColumn(const size_t& i_column) const
	{

		switch (i_column)
		{

		case 1:
			return Vector4(m_R1C1, m_R2C1, m_R3C1, m_R4C1);
		case 2:
			return Vector4(m_R1C2, m_R2C2, m_R3C2, m_R4C2);
		case 3:
			return Vector4(m_R1C3, m_R2C3, m_R3C3, m_R4C3);
		case 4:
			return Vector4(m_R1C4, m_R2C4, m_R3C4, m_R4C4);

		default:
			return Vector4::ZeroVector;

		}
	}

}