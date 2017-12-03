#pragma once

constexpr unsigned FPS = 50;
constexpr unsigned MAX_FRAME_TIME = 1000 / FPS;


constexpr int AREAS_PER_WIGHT = 16 * 2;
constexpr int AREAS_PER_HEIGHT = 9 * 2;

constexpr int WINDOW_HEIGHT = 700;
constexpr int WINDOW_WIGHT = WINDOW_HEIGHT / AREAS_PER_HEIGHT * AREAS_PER_WIGHT;

constexpr int TANK_HEIGHT = 84;
constexpr int TANK_WIGHT = 83;
constexpr int BULLET_WIGHT_WHEN_IS_UP = 20;
constexpr int BULLET_HEIGHT_WHEN_IS_UP = 34;
constexpr int BULLET_WIGHT_WHEN_IS_LEFT = BULLET_HEIGHT_WHEN_IS_UP;
constexpr int BULLET_HEIGHT_WHEN_IS_LEFT = BULLET_WIGHT_WHEN_IS_UP;

constexpr int BUTTON_HEIGHT = WINDOW_HEIGHT / 9;
constexpr int BUTTON_WEIGHT = BUTTON_HEIGHT * 4;

constexpr int AREA_WIGHT = WINDOW_WIGHT / AREAS_PER_WIGHT;
constexpr int AREA_HEIGHT = WINDOW_HEIGHT / AREAS_PER_HEIGHT;
constexpr double SCALE_WIGHT = static_cast<double>(AREA_WIGHT) / static_cast<double>(TANK_WIGHT);
constexpr double SCALE_HEIGHT = static_cast<double>(AREA_HEIGHT) / static_cast<double>(TANK_HEIGHT);

constexpr double SPEED = 0.2;
