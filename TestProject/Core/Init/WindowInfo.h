#pragma once
#include <string>

namespace Core {

	struct WindowInfo {
		std::string name;
		int width, height;
		int position_x, position_y;
		bool isReshapable;

		WindowInfo()
		{
			name = "openGL window";
			width = 800;
			height = 600;
			position_x = 300;
			position_y = 300;
			isReshapable = true;
		}

		WindowInfo(const std::string& n, const int& w, const int& h, const int& pos_x, const int& pos_y, const bool& reshapable)
		{
			name = n;
			width = w;
			height = h;
			position_x = pos_x;
			position_y = pos_y;
			isReshapable = reshapable;
		}

		WindowInfo(const WindowInfo& info)
		{
			name = info.name;
			width = info.width;
			height = info.height;
			position_x = info.position_x;
			position_y = info.position_y;
			isReshapable = info.isReshapable;
		}

		void operator=(const WindowInfo& windowInfo)
		{
			name = windowInfo.name;
			width = windowInfo.width;
			height = windowInfo.height;
			position_x = windowInfo.position_x;
			position_y = windowInfo.position_y;
			isReshapable = windowInfo.isReshapable;
		}
	};
}
