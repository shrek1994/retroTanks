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

//TODO przeniesc to do osobnych plikow

struct Offset {
    int x, y;
};