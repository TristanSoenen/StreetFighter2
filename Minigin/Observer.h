#pragma once
#include "Structs.h"

namespace dae
{
	class Subject;
	class Observer
	{
	public:
		Observer() {};
		virtual ~Observer() = default;
		virtual void Notify(Event event) = 0;
	};
}