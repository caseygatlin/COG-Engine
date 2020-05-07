#pragma once

#include "../../../Containers/Public/Point2D.h"

namespace Engine
{
	namespace Physics
	{
		// An Axis-Aligned Bounding Box for defining the collision space around an object.
		struct AABB
		{
			// Default constructor
			AABB() :
				Center(Point2D(0.0f, 0.0f)),
				Extents(Point2D(0.0f, 0.0f))
			{}

			// Constructor with variable assigning
			AABB(const Point2D& i_center, const Point2D& i_extents) :
				Center(i_center),
				Extents(i_extents)
			{}

			// Copy constructor
			AABB(const AABB& i_src) :
				Center(i_src.Center),
				Extents(i_src.Extents)
			{}

			// Assignment operator
			AABB& operator=(const AABB& i_src)
			{

				if (this != &i_src)
				{

					Center = i_src.Center;
					Extents = i_src.Extents;

				}
			}

			bool operator==(const AABB& i_rhs)
			{
				bool centerEqual = Center == i_rhs.Center;
				bool extentsEqual = Extents == i_rhs.Extents;

				return (centerEqual && extentsEqual);
			}

			bool operator!=(const AABB& i_rhs)
			{
				bool centerEqual = Center == i_rhs.Center;
				bool extentsEqual = Extents == i_rhs.Extents;

				return (!centerEqual || !extentsEqual);
			}

			// Center point for bounding box
			Point2D Center;

			// Extents in the x and y axes
			Point2D Extents;

		};

	}
}


