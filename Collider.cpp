#include "DXUT.h"
#include "Collider.h"
#include "Object.h"

Collider::Collider()
{
}

Collider::~Collider()
{
}

void Collider::OnCollision(Collider* col)
{
	parent->OnCollision(col);
}
