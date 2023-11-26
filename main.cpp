#include "include/world.hpp"
#include "include/logger.hpp"

int main() {
  evosim::World world(1920, 1080, "Evosim.");
  world.run();
  return 0;
}
