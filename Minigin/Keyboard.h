#pragma once
#include <SDL.h>
#include "Command.h"
#include <vector>
#include <memory>

namespace dae
{
	class Keyboard final
	{
	public:
		Keyboard() = default;
		~Keyboard() = default;

		bool ProcessInput();
		bool ProcessInputKeyUp(SDL_Event event);
		//chat Gpt helped with the is pressed function
		bool IsPressed(unsigned int key) { const Uint8* state = SDL_GetKeyboardState(NULL);  return state[key]; }
		void CreateCommand(std::unique_ptr<dae::Command> pCommand, const int key, bool checkKeyUp);

	private:

		std::vector<std::unique_ptr<dae::Command>> m_Commands;
		std::vector<int> m_Keys;

		std::vector<std::unique_ptr<dae::Command>> m_CommandsKeyUp;
		std::vector<int> m_KeysKeyUp;
	};
}


