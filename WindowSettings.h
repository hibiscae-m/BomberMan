//
// Created by Marius on 17/08/2023.
//

#ifndef DISPLAYMAP_WINDOWSETTINGS_H
#define DISPLAYMAP_WINDOWSETTINGS_H

#include <string_view>

class WindowSettings {
public:
    WindowSettings() = delete;
    static constexpr int WINDOW_WIDTH = 480;
    static constexpr int WINDOW_HEIGHT = 416;
    static constexpr float TIME_PER_FRAME = 1.f/60.f;
    static constexpr std::string_view WINDOW_NAME = "BomberMan!";
};


#endif //DISPLAYMAP_WINDOWSETTINGS_H
