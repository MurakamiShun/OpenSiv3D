﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2022 Ryo Suzuki
//	Copyright (c) 2016-2022 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# include <Siv3D/Script.hpp>
# include <Siv3D/OpenMode.hpp>

namespace s3d
{
	using namespace AngelScript;

	void RegisterOpenMode(asIScriptEngine* engine)
	{
		int32 r = 0;
		constexpr char TypeName[] = "OpenMode";

		{
			r = engine->RegisterEnumValue(TypeName, "Trunc", static_cast<uint32>(OpenMode::Trunc)); assert(r >= 0);
			r = engine->RegisterEnumValue(TypeName, "Append", static_cast<uint32>(OpenMode::Append)); assert(r >= 0);
		}
	}
}