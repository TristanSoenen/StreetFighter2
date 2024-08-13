#pragma once
#include "glm/glm.hpp"
#include "Component.h"

namespace dae
{
	class GameObject;
	class TransformComponent final : public Component
	{
	public:
		TransformComponent(GameObject* pOwner);
		~TransformComponent() = default;

		const glm::vec3& GetPosition() const { return m_position; }
		void SetPosition(float x, float y, float z);
		const glm::vec3& GetWorldPosition();
		void UpdateWorldPosition();
		void SetDirtyFlag();
	private:
		glm::vec3 m_position;
		glm::vec3 m_WorldPosition;
		bool m_IsDirty = false;
	};
}