#include "Game.hpp"
#include "Engine.hpp"

Game game = Game();

int main() {
    Engine engine(1280, 720);
    return engine.initialize(&game);
}

