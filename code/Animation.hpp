#pragma once

#include <iostream>

enum class Animation {
    Up = 0,
    Down = 1,
    Left = 2,
    Right = 3,
//    Idle = 4,
    IdleUp = 5,
    IdleDown = 6,
    IdleLeft = 7,
    IdleRight = 8
};

inline std::ostream& operator << (std::ostream& out, Animation animation)
{
    switch (animation) {
        case Animation::Up:
            return out << "Animation::Up";
        case Animation::Down:
            return out << "Animation::Down";
        case Animation::Left:
            return out << "Animation::Left";
        case Animation::Right:
            return out << "Animation::Right";
//        case Animation::Idle:
//            return out << "Animation::Idle";
        case Animation::IdleUp:
            return out << "Animation::IdleUp";
        case Animation::IdleDown:
            return out << "Animation::IdleDown";
        case Animation::IdleLeft:
            return out << "Animation::IdleLeft";
        case Animation::IdleRight:
            return out << "Animation::IdleRight";
        default:
            return out << "Animation::" << static_cast<int>(animation);
    }
}
