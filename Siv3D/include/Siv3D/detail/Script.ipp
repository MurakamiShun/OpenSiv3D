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

namespace s3d
{
	template <class Fty>
	inline ScriptFunction<Fty> Script::getFunction(const StringView decl) const
	{
		if (isEmpty())
		{
			return nullptr;
		}

		if (const auto func = _getFunction(decl))
		{
			return ScriptFunction<Fty>{ _getModule(), func };
		}

		return ScriptFunction<Fty>{};
	}
}

template <>
inline void std::swap(s3d::Script& a, s3d::Script& b) noexcept
{
	a.swap(b);
}
