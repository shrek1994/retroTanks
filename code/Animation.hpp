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

constexpr int WINDOW_WIGTH = 800;
constexpr int WINDOW_HEIGTH = 600;

//TODO przeniesc to do osobnych plikow

struct Offset {
    int x, y;
};