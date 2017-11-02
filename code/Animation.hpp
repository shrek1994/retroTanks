#pragma once

enum class Animation {
    Up,
    Down,
    Left,
    Right,
    Idle,
    IdleUp,
    IdleDown,
    IdleLeft,
    IdleRight
};

constexpr int WINDOW_WIGHT = 800;
constexpr int WINDOW_HEIGHT = 600;

//TODO przeniesc to do osobnych plikow

struct Offset {
    int x, y;
};