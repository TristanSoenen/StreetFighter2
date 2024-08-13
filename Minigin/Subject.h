#pragma once
#include "Observer.h"
#include <vector>

namespace dae
{
	class Observer;
	class Subject
	{
	public:
		Subject() = default;
		virtual ~Subject() = default;
		void AddObserver(Observer* observer);
		void RemoveObserver(Observer* observer);

	protected:
		void NotifyObservers(const Event& event);
	private:
		std::vector<Observer*> m_Observers;
	};
}