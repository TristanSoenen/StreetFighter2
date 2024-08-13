#pragma once
#include "Command.h"
#include <memory>

namespace dae
{
	class Controller final
	{
	public:
		Controller();
		~Controller();

		bool IsDownThisFrame(unsigned int button) const;
		bool IsUpThisFrame(unsigned int button) const;
		bool IsPressed(unsigned int button) const;

		bool ProcessInput();
		void CreateCommand(std::unique_ptr<dae::Command> pCommand, const int key, bool checkButtonUp);
	private:

		class ControllerImpl;
		std::unique_ptr<ControllerImpl> m_ControllerImpl;
	};
}