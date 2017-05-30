#include "God.hpp"
#include "game/Entity.hpp"
#include "renderer/Light.hpp"
#include "renderer/Camera.hpp"

DynamicPool<Entity> God::entities = DynamicPool<Entity>(32);
DynamicPool<Light> God::lights = DynamicPool<Light>(10);
