cmake_minimum_required(VERSION 3.27.4)
project(VulkanTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Vulkan REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_executable(VulkanTest main.cpp)
target_link_libraries(VulkanTest Vulkan::Vulkan glfw)