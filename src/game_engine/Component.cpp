#include "Component.h"
#include "Entity.h"
#include "Engine.h"
#include "Transform.h"

namespace game_engine
{
	void Component::OnInit()
	{

	}

	void Component::OnBegin()
	{

	}

	void Component::OnUpdate()
	{

	}

	void Component::OnDisplay()
	{

	}

	std::shared_ptr<Entity> Component::GetEntity()
	{
		return entity.lock();
	}

	std::shared_ptr<Engine> Component::GetEngine()
	{
		return GetEntity()->GetEngine();
	}

	std::shared_ptr<Keyboard> Component::GetKeyboard()
	{
		return GetEngine()->GetKeyboard();
	}

	std::shared_ptr<Entity> Component::AddEntity()
	{
		return GetEngine()->AddEntity();
	}

	std::shared_ptr<Transform> Component::GetTransform()
	{
		return GetEntity()->GetComponent<Transform>();
	}
}