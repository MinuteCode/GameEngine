#pragma once
#include "Model.h"

namespace Rendering {
	namespace Models {

		class Quad : public Models::Model
		{
		public:
			Quad();
			~Quad();

			void Create();
			virtual void Draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) override final;
			virtual void Update() override final;
		};
	}
}

