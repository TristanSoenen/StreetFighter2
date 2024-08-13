#pragma once
#include <memory>
#include "Transform.h"
#include "glm/glm.hpp"
#include <vector>
#include <string>

namespace dae
{
	class Component;
	class TransformComponent;
	class GameObject final
	{
	public:
		virtual void Fixed_Update();
		virtual void Update();
		virtual void Render() const;

		//===================Components===========================//
		void AddComponent(std::shared_ptr<Component> component);
		template <typename T> std::shared_ptr<T> GetComponent();
		void RemoveComponent(std::shared_ptr<Component> component);
		bool HasComponentBeenAdded(std::shared_ptr<Component> component);
		void MarkForDead();
		bool GetMarkedForDead() const
		{
			return m_MarkForDead;
		}

		void SetPosition(float x, float y);
		glm::vec3 GetWorldPosition();

		GameObject();
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		//==================parents and children======================//
		std::shared_ptr<GameObject> GetParent();
		void SetParent(std::shared_ptr<GameObject> parent, bool keepWorldPosition);
		size_t GetChildrenCount();
		GameObject* GetChildAt(int index);

	private:
		bool m_MarkForDead;
		bool m_FreezePos = false;
		//private Functions
		void AddChild(GameObject* child);
		void RemoveChild(GameObject* child);
		//components
		std::vector<std::shared_ptr<dae::Component>> m_Components;
		//parents & children
		std::shared_ptr<GameObject> m_Parent = nullptr;
		std::vector<GameObject*> m_Children;
		
		//these can be components
		std::shared_ptr<TransformComponent> m_TransformComponent;
	};


	//Chat GPT helped here
	template<typename T>
	inline std::shared_ptr <T> dae::GameObject::GetComponent()
	{
		for(auto& component : m_Components)
		{
			if (auto castedComponent = std::dynamic_pointer_cast<T>(component))
			{
				return castedComponent;
			}
		}
		return nullptr;
	}
}