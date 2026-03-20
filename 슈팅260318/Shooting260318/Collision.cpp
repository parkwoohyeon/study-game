#include "Collision.h"
#include "Struct.h"


bool CollisionPoint(const Vector2* const lhs,
	const Vector2* const rhs)
{
	int size = 1;
	if (lhs->y <= rhs->y + 1 && lhs->y <= rhs->y - 1) {
		if (lhs->x <= rhs->x + size && lhs->x >= rhs->x - size) {
			return true;
		}
	}
	return false;

}