include (CMakeFindDependencyMacro)

find_dependency(VulkanHeaders)
find_dependency(VulkanLoader)
find_dependency(glfw3)

include ("${CMAKE_CURRENT_LIST_DIR}/imgui-targets.cmake")
