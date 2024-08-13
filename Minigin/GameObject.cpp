#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Component.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "algorithm"

dae::GameObject::GameObject()
{
	AddComponent(std::make_shared<dae::TransformComponent>(this));
	m_TransformComponent = GetComponent<dae::TransformComponent>();
	m_MarkForDead = false;
}

dae::GameObject::~GameObject() = default;

void dae::GameObject::Fixed_Update()
{
	for (auto& component : m_Components)
	{
		component->Fixed_Update();
	}
}

void dae::GameObject::Update()
{
	for (auto& component : m_Components)
	{
		component->Update();
	}
}

void dae::GameObject::Render() const
{
	for (auto& component : m_Components)
	{
		component->Render();
	}
}

void dae::GameObject::SetPosition(float x, float y)
{
	if (m_FreezePos == false && m_MarkForDead == false)
	{
		m_TransformComponent->SetPosition(x, y, 0.0f);
	}
}

glm::vec3 dae::GameObject::GetWorldPosition()
{
	return m_TransformComponent->GetWorldPosition();
}

void dae::GameObject::AddComponent(std::shared_ptr<Component> component)
{
	m_Components.emplace_back(component);
}

void dae::GameObject::RemoveComponent(std::shared_ptr<dae::Component> component)
{
	m_Components.erase(std::remove(m_Components.begin(), m_Components.end(), component), m_Components.end());
}

bool dae::GameObject::HasComponentBeenAdded(std::shared_ptr<dae::Component> component)
{
	if (std::find(m_Components.begin(), m_Components.end(), component) != m_Components.end())
	{
		return true;
	}
	return false;
}

void dae::GameObject::MarkForDead()
{
	m_MarkForDead = true;
}

std::shared_ptr<dae::GameObject> dae::GameObject::GetParent()
{
	return m_Parent;
}

void dae::GameObject::SetParent(std::shared_ptr<dae::GameObject> parent, bool keepWorldPosition)
{
	if (m_Parent == parent)
	{
		return;
	}
	if (parent == nullptr)
	{
		glm::vec3 newPos = m_TransformComponent->GetWorldPosition();
		m_TransformComponent->SetPosition(newPos.x, newPos.y, newPos.z);
	}
	else
	{
		if (keepWorldPosition == true)
		{
			glm::vec3 worldPos = m_TransformComponent->GetWorldPosition();
			glm::vec3 parentPos = parent->GetWorldPosition();
			glm::vec3 newPos = worldPos - parentPos;
			m_TransformComponent->SetPosition( newPos.x, newPos.y, newPos.z );
			m_TransformComponent->SetDirtyFlag();
		}
	}

	if (m_Parent)
	{
		m_Parent->RemoveChild(this);
	}

	m_Parent = parent;

	if (m_Parent)
	{
		m_Parent->AddChild(this);
	}
}

size_t dae::GameObject::GetChildrenCount()
{
	return m_Children.size();
}

dae::GameObject* dae::GameObject::GetChildAt(int index)
{
	return m_Children[index];
}

void dae::GameObject::AddChild(dae::GameObject* child)
{
	if (child != nullptr )
	{
		RemoveChild(child);
		m_Children.emplace_back(child);
	}
}

void dae::GameObject::RemoveChild(dae::GameObject* child)
{
	if (child == nullptr)
	{
		return;
	}
	if (m_Children.empty() == false)
	{
		m_Children.erase(std::remove(m_Children.begin(), m_Children.end(), child));
	}
}