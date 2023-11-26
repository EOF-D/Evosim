#ifndef EVOSIM_WORLD_HPP
#define EVOSIM_WORLD_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace evosim {

  /**
   * @brief The World class responsible for handling Imgui + GLFW, loading
   * OpenGL via GLAD, and creating a 2D plane for organisms.
   */
  class World {
   public:
    /**
     * @brief Constructor for the World class.
     *
     * @param width Width of the 2D plane.
     * @param height Height of the 2D plane.
     * @param title Title of the GLFW window.
     */
    World(int width, int height, const char *title);

    /**
     * @brief Destructor for the World class.
     */
    ~World();

    /**
     * @brief Initialize the World, including GLFW, GLAD, and Imgui.
     *
     * @return True if initialization is successful, false otherwise.
     */
    bool initialize();

    /**
     * @brief Main loop for the application.
     */
    void run();

    /**
     * @brief Cleanup GLFW, GLAD, and Imgui resources.
     */
    // void cleanup();

   private:
    GLFWwindow *window;  // The actual GLFW window.

    int width;          // Width of the 2D plane.
    int height;         // Height of the 2D plane.
    const char *title;  // The title of the GLFW window.

    /**
     * @brief Render the simulation world.
     */
    void render();

    /**
     * @brief Handle GLFW input events.
     */
    void processInput();

    /**
     * @brief Initialize GLFW.
     *
     * @return true if successful, false otherwise.
     */
    bool initGLFW();

    /**
     * @brief Initialize GLAD.
     *
     * @return true if successful, false otherwise.
     */
    bool initGLAD();

    /**
     * @brief Initialize Imgui.
     *
     * @return true if successful, false otherwise.
     */
    bool initImgui();
  };
}  // namespace evosim

#endif  // !EVOSIM_WORLD_HPP
