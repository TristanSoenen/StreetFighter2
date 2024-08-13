#include "RenderComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "TransformComponent.h"

dae::RenderComponent::RenderComponent(GameObject* pOwner, const std::string& file)
	:Component(pOwner)
	,m_FilePath(file)
	,m_Size(0, 0)
{
	m_TransformComponent = pOwner->GetComponent<TransformComponent>();
	m_Texture = dae::ResourceManager::GetInstance().LoadTexture(m_FilePath);
}

dae::RenderComponent::RenderComponent(GameObject* pOwner, const std::string& file, glm::vec2 size)
	:Component(pOwner)
	,m_FilePath(file)
	,m_Size(size)
{
	m_TransformComponent = pOwner->GetComponent<TransformComponent>();
	m_Texture = dae::ResourceManager::GetInstance().LoadTexture(m_FilePath);
}

void dae::RenderComponent::Render()
{
	auto& pos = m_TransformComponent->GetPosition();
	if (m_Size.x == 0 || m_Size.y == 0)
	{
		dae::Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
	}
	else
	{
		dae::Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y, m_Size.x, m_Size.y);
	}
}

void dae::RenderComponent::SetTexture(const std::string& filepath)
{
	m_Texture = dae::ResourceManager::GetInstance().LoadTexture(filepath);
}