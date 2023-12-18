#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib> // for getenv

int main()
{
    // Set the GLFW_USE_WAYLAND environment variable to 1
    // This tells GLFW to use Wayland as the window system, if available
    setenv("GLFW_USE_WAYLAND", "1", 1);

    // Initialize the GLFW library
    glfwInit();

    // Tell GLFW to not create an OpenGL context
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    // Create a GLFW window
    // The window will not have an associated OpenGL context, because we set GLFW_CLIENT_API to GLFW_NO_API
    GLFWwindow *window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

    // Get the number of Vulkan instance extensions
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    // Print the number of Vulkan instance extensions
    std::cout << "Vulkan extension count: " << extensionCount << std::endl;

    // Get the value of the WAYLAND_DISPLAY environment variable
    // If this variable is set, the application is running on Wayland
    const char *waylandDisplay = getenv("WAYLAND_DISPLAY");
    if (waylandDisplay != nullptr)
    {
        std::cout << "Running on Wayland" << std::endl;
    }
    else
    {
        // If the WAYLAND_DISPLAY environment variable is not set, the application is not running on Wayland
        // It is likely running on XWayland or X11
        std::cout << "Not running on Wayland (likely XWayland or X11)" << std::endl;
    }

    // Main loop
    // This loop continues until the window should close
    while (!glfwWindowShouldClose(window))
    {
        // Poll for and process events
        glfwPollEvents();
    }

    // Destroy the window
    // This also destroys the associated Vulkan surface, if it exists
    glfwDestroyWindow(window);

    // Terminate GLFW
    // After this is called, you must not use any GLFW functions until you call glfwInit again
    glfwTerminate();

    return 0;
}