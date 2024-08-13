#include "TextComponent.h"
#include "GameObject.h"
#include "TransformComponent.h"
#include "Font.h"
#include <stdexcept>
#include <SDL_ttf.h>
#include "Renderer.h"
#include "Texture2D.h"

//all code is from TextObject.cpp
dae::TextComponent::TextComponent(dae::GameObject* pOwner, std::string text, std::shared_ptr<dae::Font> font)
	:Component(pOwner)
	,m_needsUpdate(true)
	,m_text(text)
	,m_font(std::move(font))
	,m_textTexture(nullptr)
{
	m_TransformComponent =  pOwner->GetComponent<TransformComponent>();
}

void dae::TextComponent::Update()
{
	if (m_needsUpdate)
	{
		const SDL_Color color = { 255,255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(m_font->GetFont(), m_text.c_str(), color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_textTexture = std::make_shared<Texture2D>(texture);
		m_needsUpdate = false;
	}
}

void dae::TextComponent::Render()
{
	if (m_textTexture != nullptr)
	{
		const auto& pos = m_TransformComponent->GetPosition();
		Renderer::GetInstance().RenderTexture(*m_textTexture, pos.x, pos.y);
	}
}

void dae::TextComponent::SetPosition(float x, float y)
{
	m_TransformComponent->SetPosition(x, y, 0);
}

void dae::TextComponent::SetText(std::string text)
{
	m_text = text;
	m_needsUpdate = true;
}