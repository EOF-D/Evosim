#include "../include/world.hpp"
#include "../include/logger.hpp"

namespace evosim {

  // Constructor & Destructor
  World::World(int width, int height, const char* title)
      : window(nullptr), width(width), height(height), title(title) {}

  World::~World() {
    // Cleanup Imgui resources
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // Cleanup GLFW resources
    if (window) {
      glfwDestroyWindow(window);
      window = nullptr;
    }

    glfwTerminate();
    logger::info("Cleanup completed.");
  }

  // Initialize the World, including GLFW, GLAD, and Imgui.
  bool World::initialize() {
    logger::info("Running initialization.");

    if (!initGLFW() || !initGLAD() || !initImgui()) {
      logger::error("Initialization failed.");
      return false;
    }

    return true;
  }

  bool World::initGLFW() {
    // Initialize GLFW.
    logger::info("Initializing GLFW.");

    if (!glfwInit()) {
      logger::error("Failed to initialize GLFW.");
      return false;
    }

    // Configure GLFW window properties.
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
      logger::error("Failed to create GLFW window.");
      glfwTerminate();
      return false;
    }

    glfwMakeContextCurrent(window);
    return true;
  }

  bool World::initGLAD() {
    logger::info("Initializing GLAD.");

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      logger::error("Failed to initialize GLAD.");
      return false;
    }

    return true;
  }

  bool World::initImgui() {
    logger::info("Initializing Imgui.");

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |=
        ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    return true;
  }

  void World::run() {
    logger::info("Running main loop.");

    // Initialize the World
    if (!initialize()) {
      logger::error("Failed to initialize the World.");
      return;
    }

    // Main loop
    while (!glfwWindowShouldClose(window)) {
      // Process input
      processInput();

      // Render the simulation
      render();

      // Poll and swap buffers
      glfwPollEvents();
      glfwSwapBuffers(window);
    }

    // Window was told to close.
    logger::info("Received ESC. Closing window.");
  }

  void World::processInput() {
    // Close window is ESC is pressed.
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      glfwSetWindowShouldClose(window, true);
    }
  }

  void World::render() {
    // Clear the framebuffer
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // TODO: Implement UI and replace placeholder.
    ImGui::ShowDemoWindow();

    // ImGui::Begin("Simulation Controls");
    // ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }
}  // namespace evosim
