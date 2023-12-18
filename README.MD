# Vulkan Window Creation with GLFW

This is a test project to create a Vulkan window using the GLFW library. It's a simple application that opens a window and prints out some information about the Vulkan environment.

## Features

- **Window Creation**: The application creates a window using the GLFW library. The window does not have an associated OpenGL context, because we're using Vulkan for rendering instead of OpenGL.

- **Vulkan Extension Count**: The application prints out the number of Vulkan instance extensions.

- **Wayland Detection**: The application checks if it's running on Wayland by checking the `WAYLAND_DISPLAY` environment variable.

## How to Run

To run this application, you'll need to have the Vulkan SDK and the GLFW library installed on your system. Once you have those installed, you can build and run the application using CMake and Make.

```bash
mkdir build
cd build
cmake ..
make
./VulkanWindow
```
