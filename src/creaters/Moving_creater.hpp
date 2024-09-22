#pragma once

#include "Charlie2D.hpp"
#include "Vector2f.hpp"

Entity *createMoving(Box box, Vector2f otherPos, float speed = 60);
