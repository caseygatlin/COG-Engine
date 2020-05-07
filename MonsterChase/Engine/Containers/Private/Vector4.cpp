#include "../Public/Vector4.h"
#include "../Public/Point2D.h"

namespace Engine
{
	const Vector4 Vector4::ZeroVector(0.0f, 0.0f, 0.0f, 0.0f);
	const Vector4 Vector4::OneVector(1.0f, 1.0f, 1.0f, 1.0f);

	Vector4::Vector4(const Point2D& i_src, const float& i_z, const float& i_w)
	{

		m_x = i_src.X();
		m_y = i_src.Y();
		m_z = i_z;
		m_w = i_w;

	}
}