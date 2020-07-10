#pragma once

#include "Vector4.h"
#include "../../Helpers/Public/FloatHelpers.h"
#include <math.h>

namespace Engine
{

	inline Vector4& Vector4::operator=(const Vector4& i_rhs)
	{

		if (this != &i_rhs)
		{

			m_x = i_rhs.m_x;
			m_y = i_rhs.m_y;
			m_z = i_rhs.m_z;
			m_w = i_rhs.m_w;

		}

		return (*this);

	}

	inline Vector4& Vector4::operator+=(const Vector4& i_rhs)
	{

		m_x += i_rhs.m_x;
		m_y += i_rhs.m_y;
		m_z += i_rhs.m_z;
		m_w += i_rhs.m_w;

		return (*this);

	}

	inline Vector4& Vector4::operator-=(const Vector4& i_rhs)
	{

		m_x -= i_rhs.m_x;
		m_y -= i_rhs.m_y;
		m_z -= i_rhs.m_z;
		m_w -= i_rhs.m_w;

		return (*this);

	}

	inline Vector4& Vector4::operator+=(const float& i_rhs)
	{

		m_x += i_rhs;
		m_y += i_rhs;
		m_z += i_rhs;
		m_w += i_rhs;

		return (*this);

	}

	inline Vector4& Vector4::operator-=(const float& i_rhs)
	{

		m_x -= i_rhs;
		m_y -= i_rhs;
		m_z -= i_rhs;
		m_w -= i_rhs;

		return (*this);

	}

	inline Vector4& Vector4::operator*=(const float& i_rhs)
	{

		m_x *= i_rhs;
		m_y *= i_rhs;
		m_z *= i_rhs;
		m_w *= i_rhs;

		return (*this);

	}

	inline Vector4& Vector4::operator/=(const float& i_rhs)
	{
		if (Helpers::CompareZeroF(i_rhs))
		{

			(*this) = ZeroVector;
			return (*this);

		}

		m_x /= i_rhs;
		m_y /= i_rhs;
		m_z /= i_rhs;
		m_w /= i_rhs;

		return (*this);

	}

	inline float Vector4::X() const
	{

		return m_x;

	}

	inline float Vector4::Y() const
	{

		return m_y;

	}

	inline float Vector4::Z() const
	{

		return m_z;

	}

	inline float Vector4::W() const
	{

		return m_w;

	}

	inline void Vector4::SetX(const float& i_x)
	{

		m_x = i_x;

	}

	inline void Vector4::SetY(const float& i_y)
	{

		m_y = i_y;

	}

	inline void Vector4::SetZ(const float& i_z)
	{

		m_z = i_z;

	}

	inline void Vector4::SetW(const float& i_w)
	{

		m_w = i_w;

	}

	inline float Vector4::Length() const
	{

		float xSquared = m_x * m_x;
		float ySquared = m_y * m_y;
		float zSquared = m_z * m_z;
		float wSquared = m_w * m_w;

		float length = sqrtf(xSquared + ySquared + zSquared + wSquared);

		return length;

	}

	inline void Vector4::Normalize()
	{

		float length = Length();

		if (Helpers::CompareZeroF(length))
		{

			m_x = m_y = m_z = m_w = 0.0f;

		}

		else
		{

			float lengthReciprocal = 1.0f / length;

			(*this) *= lengthReciprocal;

		}
	}

	inline Vector4 Vector4::GetNormalized() const
	{

		float length = Length();

		if (Helpers::CompareZeroF(length))
		{

			return ZeroVector;

		}

		else
		{

			float lengthReciprocal = 1.0f / length;

			return (*this) * lengthReciprocal;

		}
	}

	inline float dot(const Vector4& i_lhs, const Vector4& i_rhs)
	{

		float xProduct = i_lhs.X() * i_rhs.X();
		float yProduct = i_lhs.Y() * i_rhs.Y();
		float zProduct = i_lhs.Z() * i_rhs.Z();
		float wProduct = i_lhs.W() * i_rhs.W();

		return (xProduct + yProduct + zProduct + wProduct);

	}

	inline Vector4 operator+(const Vector4 i_lhs, const Vector4 i_rhs)
	{

		float x = i_lhs.X() + i_rhs.X();
		float y = i_lhs.Y() + i_rhs.Y();
		float z = i_lhs.Z() + i_rhs.Z();
		float w = i_lhs.W() + i_rhs.W();

		return Vector4(x, y, z, w);

	}

	inline Vector4 operator-(const Vector4 i_lhs, const Vector4 i_rhs)
	{

		float x = i_lhs.X() - i_rhs.X();
		float y = i_lhs.Y() - i_rhs.Y();
		float z = i_lhs.Z() - i_rhs.Z();
		float w = i_lhs.W() - i_rhs.W();

		return Vector4(x, y, z, w);

	}

	inline Vector4 operator+(const Vector4 i_lhs, const float i_rhs)
	{

		float x = i_lhs.X() + i_rhs;
		float y = i_lhs.Y() + i_rhs;
		float z = i_lhs.Z() + i_rhs;
		float w = i_lhs.W() + i_rhs;

		return Vector4(x, y, z, w);

	}

	inline Vector4 operator-(const Vector4 i_lhs, const float i_rhs)
	{

		float x = i_lhs.X() - i_rhs;
		float y = i_lhs.Y() - i_rhs;
		float z = i_lhs.Z() - i_rhs;
		float w = i_lhs.W() - i_rhs;

		return Vector4(x, y, z, w);

	}

	inline Vector4 operator*(const Vector4 i_lhs, const float i_rhs)
	{

		float x = i_lhs.X() * i_rhs;
		float y = i_lhs.Y() * i_rhs;
		float z = i_lhs.Z() * i_rhs;
		float w = i_lhs.W() * i_rhs;

		return Vector4(x, y, z, w);

	}

	inline Vector4 operator/(const Vector4 i_lhs, const float i_rhs)
	{

		if (Helpers::CompareZeroF(i_rhs))
		{

			return Vector4::ZeroVector;

		}

		float x = i_lhs.X() / i_rhs;
		float y = i_lhs.Y() / i_rhs;
		float z = i_lhs.Z() / i_rhs;
		float w = i_lhs.W() / i_rhs;

		return Vector4(x, y, z, w);

	}

	Vector4 operator+(const float i_lhs, const Vector4 i_rhs)
	{
		float x = i_rhs.X() + i_lhs;
		float y = i_rhs.Y() + i_lhs;
		float z = i_rhs.Z() + i_lhs;
		float w = i_rhs.W() + i_lhs;

		return Vector4(x, y, z, w);
	}

	Vector4 operator*(const float i_lhs, const Vector4 i_rhs)
	{
		float x = i_rhs.X() * i_lhs;
		float y = i_rhs.Y() * i_lhs;
		float z = i_rhs.Z() * i_lhs;
		float w = i_rhs.W() * i_lhs;

		return Vector4(x, y, z, w);
	}

	inline bool operator==(const Vector4& i_lhs, const Vector4& i_rhs)
	{

		bool xEqual = Helpers::RelativeEpsilonCompareF(i_lhs.X(), i_rhs.X(), 0.00001f);
		bool yEqual = Helpers::RelativeEpsilonCompareF(i_lhs.Y(), i_rhs.Y(), 0.00001f);
		bool zEqual = Helpers::RelativeEpsilonCompareF(i_lhs.Z(), i_rhs.Z(), 0.00001f);
		bool wEqual = Helpers::RelativeEpsilonCompareF(i_lhs.W(), i_rhs.W(), 0.00001f);

		return (xEqual && yEqual && zEqual && wEqual);

	}

	inline bool operator!=(const Vector4& i_lhs, const Vector4& i_rhs)
	{

		bool xEqual = Helpers::RelativeEpsilonCompareF(i_lhs.X(), i_rhs.X());
		bool yEqual = Helpers::RelativeEpsilonCompareF(i_lhs.Y(), i_rhs.Y());
		bool zEqual = Helpers::RelativeEpsilonCompareF(i_lhs.Z(), i_rhs.Z());
		bool wEqual = Helpers::RelativeEpsilonCompareF(i_lhs.W(), i_rhs.W());


		return (!xEqual || !yEqual || !zEqual || !wEqual);

	}




}