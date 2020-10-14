#pragma once
#include "IMesh.h"

namespace Z_Engine::Rendering::Meshes {

	struct Mesh2D : public IMesh<float, unsigned int> 
	{
		Mesh2D() = default;
		Mesh2D(
			const char * shader_name,
			const std::vector<float>& data,
			const std::vector<unsigned int>& index,
			std::initializer_list<Z_Engine::Rendering::Buffers::Layout::ElementLayout<float>> elements_list)
			:
			IMesh(shader_name, data, index, elements_list) 
		{}

		virtual ~Mesh2D() =  default;
	};
}