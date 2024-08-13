#include <SDL.h>
#include "control.h"
#include "InputManager.h"
#include "Controller.h"
#include <backends/imgui_impl_sdl2.h>
#include "Command.h"

bool dae::InputManager::ProcessInput()
{
	if (m_Controllers.size() > 0)
	{
		for (int index = 0; index < int(m_Controllers.size()); index++)
		{
			m_Controllers[index]->ProcessInput();
		}
	}

	if (m_Keyboard != nullptr)
	{
		m_Keyboard->ProcessInput();
	}
	
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		//process event for IMGUI
		ImGui_ImplSDL2_ProcessEvent(&e);
		if (e.type == SDL_KEYUP) 
		{
			if (m_Keyboard != nullptr)
			{
				m_Keyboard->ProcessInputKeyUp(e);
			}
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
	
		// etc...
	}

	return true;
}

void dae::InputManager::CreateCommandKeyBoard(std::unique_ptr<dae::Command> pCommand, int key, bool checkKeyUp)
{
	m_Keyboard->CreateCommand(std::move(pCommand), key, checkKeyUp);
}

void dae::InputManager::CreateCommandForController(std::unique_ptr<Command> pCommand, int ControllerIndex,const int key, bool checkButtonUp)
{
	if (m_Controllers.size() > 0)
	{
		m_Controllers[ControllerIndex]->CreateCommand(std::move(pCommand), key, checkButtonUp);
	}
}

void dae::InputManager::AddController(std::unique_ptr<Controller> pController)
{
	m_Controllers.emplace_back(std::move(pController));
}