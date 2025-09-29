#include "Modules/Game.h"
#include <SFML/System.hpp>
#include <SFML/System/Time.hpp>

int main(int argc, char *argv[]) {
  GAME::Game game{};
  while (!game.GetWindow()->IsDone()) {
    // game.HandleInput();
    game.Update();
    game.Render();
    game.RestartClock();
  }

  return 0;
}
