#include "Modules/Game.h"

int main(int argc, char* argv[]) {
   GAME::Game game{};
   while (!game.GetWindow()->IsDone()) {
      //game.HandleInput();
      game.Update();
      game.Render();
   }

   return 0;
}
