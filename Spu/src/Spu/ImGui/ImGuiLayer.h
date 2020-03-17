#pragma once
#include "Spu/Layer.h"

#include "Spu/Events/ApplicationEvent.h"
#include "Spu/Events/KeyEvent.h"
#include "Spu/Events/MouseEvent.h"

namespace Spu {
	class SPU_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer() noexcept;
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float mTime = 0.f;
	};
}