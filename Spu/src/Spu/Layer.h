#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Spu {
	class SPU_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {};
		virtual void OnEvent(Event& e) {}

		const std::string& GetName() const { return mDebugName; }

	protected:
		std::string mDebugName;
	};
}