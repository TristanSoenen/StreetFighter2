#pragma once
#include "GameObject.h"
#include <memory>

namespace dae
{
	class Component
	{
	public:
		virtual ~Component() = default;
		Component(const Component& other) = delete;
		Component(Component&& other) = delete;
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) = delete;

		virtual void Fixed_Update() {};
		virtual void Update() {};
		virtual void Render() {};

	protected:
		explicit Component(GameObject* pOwner) : m_pOwner(pOwner) {};
		GameObject* GetOwner() const { return m_pOwner; }
	private:
		GameObject* m_pOwner;
	};
}


