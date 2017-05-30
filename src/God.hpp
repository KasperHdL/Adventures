#pragma once

#include "utils/DynamicPool.hpp"
#include "utils/Pool.hpp"

class Entity;
class Light;
class Camera;
class Character;

class God{
    public:

    static DynamicPool<Entity> entities;
    static DynamicPool<Character> characters;
    static DynamicPool<Light> lights;

};
