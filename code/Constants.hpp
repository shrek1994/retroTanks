#pragma once

constexpr unsigned AREAS_PER_SIDE = 10;

constexpr unsigned WINDOW_WIGHT = 600;
constexpr unsigned WINDOW_HEIGHT = WINDOW_WIGHT;

constexpr int TANK_HEIGHT = 85;
constexpr int TANK_WIGHT = 85;

constexpr unsigned AREA_WIGHT = WINDOW_WIGHT / AREAS_PER_SIDE;
constexpr unsigned AREA_HEIGHT = WINDOW_HEIGHT / AREAS_PER_SIDE;
constexpr double SCALE_WIGHT = static_cast<double>(AREA_WIGHT) / static_cast<double>(TANK_WIGHT);
constexpr double SCALE_HEIGHT = static_cast<double>(AREA_HEIGHT) / static_cast<double>(TANK_HEIGHT);

constexpr double SPEED = 0.3;
