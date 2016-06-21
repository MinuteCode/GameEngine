#pragma once

namespace Core {

	struct ContextInfo {
		int major_version, minor_version;
		bool core;

		ContextInfo()
		{
			major_version = 3;
			minor_version = 3;
			core = true;
		}

		ContextInfo(const int& maj_ver, const int& min_ver, const bool& c)
		{
			major_version = maj_ver;
			minor_version = min_ver;
			core = c;
		}

		ContextInfo(const ContextInfo& ci)
		{
			major_version = ci.major_version;
			minor_version = ci.minor_version;
			core = ci.core;
		}

		void operator=(const ContextInfo& ci)
		{
			major_version = ci.major_version;
			minor_version = ci.minor_version;
			core = ci.core;
		}
	};
}
