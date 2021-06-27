﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2021 Ryo Suzuki
//	Copyright (c) 2016-2021 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include <Siv3D/Common.hpp>
# include <Siv3D/Common/OpenGL.hpp>
# include <Siv3D/Blob.hpp>
# include <Siv3D/ConstantBufferBinding.hpp>

namespace s3d
{
	class WebGPUPixelShader
	{
	private:

		Blob m_binary;

		GLuint m_pixelShader = 0;

		Array<ConstantBufferBinding> m_constantBufferBindings;
		Array<std::pair<uint32, GLint>> m_textureIndices;

		bool m_initialized = false;

		void setUniformBlockBinding(const String& name, GLuint index);

		void setUniformBlockBindings(const Array<ConstantBufferBinding>& bindings);

	public:

		struct Null {};

		WebGPUPixelShader() = default;

		explicit WebGPUPixelShader(Null);

		explicit WebGPUPixelShader(const StringView source, const Array<ConstantBufferBinding>& bindings);

		~WebGPUPixelShader();

		bool isInitialized() const noexcept;

		const Blob& getBinary() const noexcept;

		GLint getShader() const;

		void bindUniformBlocks(GLuint program);

		void setPSSamplerUniforms();
	};
}
