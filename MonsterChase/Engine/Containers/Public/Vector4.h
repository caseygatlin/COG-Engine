#pragma once


namespace Engine
{
	class Point2D;

	class Vector4
	{
	public:

		// Static constants
		static const Vector4 ZeroVector;
		static const Vector4 OneVector;

		//Constructors
		Vector4() :
			m_x(0.0F),
			m_y(0.0F),
			m_z(0.0F),
			m_w(0.0F)
		{}

		Vector4(const float& i_x, const float& i_y, const float& i_z, const float& i_w) :
			m_x(i_x),
			m_y(i_y),
			m_z(i_z),
			m_w(i_w)
		{}

		Vector4(const Vector4& i_src) :
			m_x(i_src.m_x),
			m_y(i_src.m_y),
			m_z(i_src.m_z),
			m_w(i_src.m_w)
		{}

		Vector4(const Point2D& i_src, const float& i_z = 1.0f, const float& i_w = 1.0f);

		// Assignment operators - with Vector4.
		inline Vector4& operator=(const Vector4& i_rhs);
		inline Vector4& operator+=(const Vector4& i_rhs);
		inline Vector4& operator-=(const Vector4& i_rhs);

		// Assignment operators - with float.
		inline Vector4& operator+=(const float& i_rhs);
		inline Vector4& operator-=(const float& i_rhs);
		inline Vector4& operator*=(const float& i_rhs);
		inline Vector4& operator/=(const float& i_rhs);

		// Getters for member variables.
		inline float X() const;
		inline float Y() const;
		inline float Z() const;
		inline float W() const;

		// Setters for member variables.
		inline void SetX(const float& i_x);
		inline void SetY(const float& i_y);
		inline void SetZ(const float& i_z);
		inline void SetW(const float& i_w);

		// Returns the magnitude of this vector.
		inline float Length() const;

		// Normalizes this vector.
		inline void Normalize();

		// Returns a normalized version of this vector.
		inline Vector4 GetNormalized() const;

	private:

		// Member variables
		float m_x;
		float m_y;
		float m_z;
		float m_w;

	};

	// Dot product
	inline float	dot(const Vector4& i_lhs, const Vector4& i_rhs);

	// Mathematical operations - with Vector4
	inline Vector4	operator+(const Vector4 i_lhs, const Vector4 i_rhs);
	inline Vector4	operator-(const Vector4 i_lhs, const Vector4 i_rhs);

	// Mathematical operations - with float
	inline Vector4	operator+(const Vector4 i_lhs, const float i_rhs);
	inline Vector4	operator-(const Vector4 i_lhs, const float i_rhs);
	inline Vector4	operator*(const Vector4 i_lhs, const float i_rhs);
	inline Vector4  operator/(const Vector4 i_lhs, const float i_rhs);
	inline Vector4	operator+(const float i_lhs, const Vector4 i_rhs);
	inline Vector4	operator*(const float i_lhs, const Vector4 i_rhs);

	// Equal /Not Equal to
	inline bool		operator==(const Vector4& i_lhs, const Vector4& i_rhs);
	inline bool		operator!=(const Vector4& i_lhs, const Vector4& i_rhs);

}

#include "Vector4-inl.h"