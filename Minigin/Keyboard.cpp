#include "Keyboard.h"

bool dae::Keyboard::ProcessInput()
{
	if (!m_Commands.empty() && !m_Keys.empty())
	{
		for (int index{ 0 }; index < int(m_Keys.size()); index++)
		{
			if (IsPressed(m_Keys[index]))
			{
				m_Commands[index]->Execute();
			}
		}
	}

	return true;
}

bool dae::Keyboard::ProcessInputKeyUp(SDL_Event event)
{
	if (!m_CommandsKeyUp.empty() && !m_KeysKeyUp.empty())
	{	
		if (event.type == SDL_KEYUP)
		{
			for (int index{ 0 }; index < int(m_KeysKeyUp.size()); index++)
			{
				if(event.key.keysym.scancode == m_KeysKeyUp[index])
				{
					m_CommandsKeyUp[index]->Execute();
				}
			}
		}
	}

	return true;
}

void dae::Keyboard::CreateCommand(std::unique_ptr<dae::Command> pCommand, const int key, bool checkKeyUp)
{
	if (checkKeyUp == true)
	{
		m_CommandsKeyUp.emplace_back(std::move(pCommand));
		m_KeysKeyUp.emplace_back(key);
	}
	else 
	{
		m_Commands.emplace_back(std::move(pCommand));
		m_Keys.emplace_back(key);
	}
}