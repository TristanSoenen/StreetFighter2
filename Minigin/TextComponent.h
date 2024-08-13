#pragma once
#include "Component.h"
namespace dae
{
	class Font;
	class TransformComponent;
	class Texture2D;

	class TextComponent final : public Component
	{
	public:
		TextComponent(GameObject* pOwner, std::string text, std::shared_ptr<Font> font);
		~TextComponent() = default;
		void Update() override;
		void Render() override;
		void SetPosition(float x, float y);
		void SetText(std::string text);
	private:
		bool m_needsUpdate;
		std::string m_text;
		std::shared_ptr<TransformComponent> m_TransformComponent;
		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture2D> m_textTexture;
	};
}