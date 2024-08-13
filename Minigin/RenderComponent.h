#pragma once
#include "Component.h"


namespace dae
{
	class Texture2D;
	class TransformComponent;

	class RenderComponent final : public Component
	{
	public:
		RenderComponent(GameObject* pOwner, const std::string& file);
		RenderComponent(GameObject* pOwner, const std::string& file, glm::vec2 size);
		~RenderComponent() = default;
		void Render() override;
		void SetTexture(const std::string& filepath);

	private:

		glm::vec2 m_Size;
		const std::string& m_FilePath;
		std::shared_ptr<Texture2D> m_Texture;
		std::shared_ptr<TransformComponent> m_TransformComponent;
	};
}