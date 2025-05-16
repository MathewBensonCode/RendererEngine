# Externals dependencies
#
include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS 
  )

FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  GIT_SHALLOW TRUE
  GIT_TAG v1.89.9-docking)

FetchContent_Declare(
  ImGuizmo
  GIT_REPOSITORY https://github.com/CedricGuillemet/ImGuizmo.git
  GIT_SHALLOW TRUE)

FetchContent_Declare(
  stbimage
  GIT_REPOSITORY https://github.com/nothings/stb.git
  GIT_SHALLOW TRUE)

FetchContent_Declare(
  glfw3
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS )

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS )

FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS )

FetchContent_Declare(
  EnTT 
  GIT_REPOSITORY https://github.com/skypjack/entt.git
  GIT_SHALLOW TRUE 
  FIND_PACKAGE_ARGS)

FetchContent_Declare(
  assimp
  GIT_REPOSITORY https://github.com/assimp/assimp.git
  GIT_TAG v5.3.0
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS )

FetchContent_Declare(
  stduuid
  GIT_REPOSITORY https://github.com/mariusbancila/stduuid.git
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS )

FetchContent_Declare(
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS )


FetchContent_Declare(
  spirv_cross_core
  GIT_REPOSITORY https://github.com/KhronosGroup/SPIRV-Cross.git
  GIT_TAG vulkan-sdk-1.4.309.0
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS )

FetchContent_Declare(
    VulkanMemoryAllocator
  GIT_REPOSITORY
    https://github.com/GPUOpen-LibrariesAndSDKs/VulkanMemoryAllocator
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS )

FetchContent_Declare(
    glslang
    GIT_REPOSITORY https://github.com/KhronosGroup/glslang.git
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS  
)

FetchContent_Declare(
    SPIRV-Tools
    GIT_REPOSITORY https://github.com/KhronosGroup/SPIRV-Tools.git
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS 
)


Fetchcontent_Declare(
    GTest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS )

Fetchcontent_Declare(
  nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS )

FetchContent_MakeAvailable(
  fmt
  imgui
  ImGuizmo
  stbimage
  glfw3
  spdlog
  glm
  EnTT
  assimp
  stduuid
  yaml-cpp
  spirv_cross_core
  VulkanMemoryAllocator
  glslang
  SPIRV-Tools
  GTest
  nlohmann_json
  )

