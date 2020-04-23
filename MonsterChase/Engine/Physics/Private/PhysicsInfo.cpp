
#include "../../GameObject/Public/GameObject.h"
#include "../../Containers/Public/Point2D.h"
#include "../../Containers/Public/Pointers.h"
#include "../Public/PhysicsInfo.h"

namespace Engine
{
    namespace Physics
    {
        void PhysicsInfo::Update(float i_dt)
        {
            SmartPtr<GameObject> gameObject = m_pObject.Acquire();

            Point2D objectVelocity = gameObject->getVelocity();

            Point2D forces(0.0F, 0.0F);

            if (gameObject->getDir() == 'u')
            {
                forces = Point2D(0.0F, .1F);
            }
            else if (gameObject->getDir() == 'd')
            {
                forces = Point2D(0.0F, -.1F);
            }
            else if (gameObject->getDir() == 'l')
            {
                forces = Point2D(-.1F, 0.0F);
            }
            else if (gameObject->getDir() == 'r')
            {
                forces = Point2D(.1F, 0.0F);
            }

            Point2D dragForce(0.0F, 0.0F);

            if (objectVelocity.X() > 0 && objectVelocity.Y() < 0)
            {
                dragForce += Point2D(m_drag * -1, m_drag);
            }
            else if (objectVelocity.X() < 0 && objectVelocity.Y() > 0)
            {
                dragForce += Point2D(m_drag, m_drag * -1);
            }
            else if (objectVelocity.X() < 0 || objectVelocity.Y() < 0)
            {
                dragForce += Point2D(m_drag, m_drag);
            }
            else if (objectVelocity.X() > 0 || objectVelocity.Y() > 0)
            {
                dragForce += Point2D(m_drag * -1, m_drag * -1);
            }

            forces += objectVelocity * objectVelocity * dragForce;

            Point2D acceleration = forces / m_mass;

            gameObject->SetVelocity(gameObject->getVelocity() + acceleration * i_dt);
            gameObject->changePosition(gameObject->getVelocity() * i_dt);
        }
    }
}