# Externals dependencies
#
include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS REQUIRED
  )

FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  GIT_SHALLOW TRUE
  GIT_TAG v1.89.9-docking)

FetchContent_Declare(
  stbimage
  GIT_REPOSITORY https://github.com/nothings/stb.git
  GIT_SHALLOW TRUE)

FetchContent_Declare(
  glfw3
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS REQUIRED)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS REQUIRED)

FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS REQUIRED)

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
  FIND_PACKAGE_ARGS)

FetchContent_Declare(
  stduuid
  GIT_REPOSITORY https://github.com/mariusbancila/stduuid.git
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS)

FetchContent_Declare(
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS NAMES yaml-cpp)

FetchContent_Declare(
  ImGuizmo
  GIT_REPOSITORY https://github.com/CedricGuillemet/ImGuizmo.git
  GIT_SHALLOW TRUE)

FetchContent_Declare(
  spirv_cross_core
  FIND_PACKAGE_ARGS REQUIRED
  )

FetchContent_Declare(
  spirv_cross_glsl
  FIND_PACKAGE_ARGS REQUIRED
  )

FetchContent_Declare(
  VulkanMemoryAllocator
  GIT_REPOSITORY
    https://github.com/GPUOpen-LibrariesAndSDKs/VulkanMemoryAllocator
  GIT_SHALLOW TRUE
  )

FetchContent_Declare(
    glslang
    FIND_PACKAGE_ARGS REQUIRED 
)

FetchContent_Declare(
    SPIRV-Tools
    FIND_PACKAGE_ARGS REQUIRED
)


Fetchcontent_Declare(
    GTest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS
)

Fetchcontent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS
)


FetchContent_MakeAvailable(
  fmt
  imgui
  stbimage
  glfw3
  spdlog
  glm
  entt
  assimp
  stduuid
  yaml-cpp
  ImGuizmo
  spirv_cross_core
  spirv_cross_glsl
  VulkanMemoryAllocator
  glslang
  SPIRV-Tools
  GTest
  nlohmann_json
  )

find_package(Vulkan REQUIRED)

set(IMGUIDIR ${FETCHCONTENT_BASE_DIR}/imgui-src)

add_library(imgui STATIC)

target_sources(
  imgui
  PRIVATE ${IMGUIDIR}/imgui.cpp
          ${IMGUIDIR}/imgui_demo.cpp
          ${IMGUIDIR}/imgui_draw.cpp
          ${IMGUIDIR}/imgui_tables.cpp
          ${IMGUIDIR}/imgui_widgets.cpp
          ${IMGUIDIR}/misc/cpp/imgui_stdlib.cpp
          ${IMGUIDIR}/backends/imgui_impl_glfw.cpp
          ${IMGUIDIR}/backends/imgui_impl_vulkan.cpp)

target_include_directories(imgui PUBLIC ${IMGUIDIR})

target_compile_definitions(imgui PUBLIC GLFW_INCLUDE_VULKAN)

target_link_libraries(imgui PUBLIC glfw Vulkan::Vulkan)

add_library(imguizmo STATIC)

target_sources(imguizmo
               PRIVATE ${FETCHCONTENT_BASE_DIR}/imguizmo-src/ImGuizmo.cpp)

target_include_directories(imguizmo
                           PUBLIC ${FETCHCONTENT_BASE_DIR}/imguizmo-src)

target_link_libraries(imguizmo PUBLIC imgui)

add_library (imported::External_libs INTERFACE IMPORTED)

target_include_directories(imported::External_libs INTERFACE ${FETCHCONTENT_BASE_DIR}/stbimage-src)

target_link_libraries(imported::External_libs INTERFACE
	vulkan
	fmt::fmt
	glm::glm
	imguizmo
	spdlog::spdlog
	glfw
    EnTT::EnTT
	assimp::assimp
	stduuid
	yaml-cpp::yaml-cpp
    spirv-cross-core
    spirv-cross-glsl
    glslang::SPIRV
	GPUOpen::VulkanMemoryAllocator
	SPIRV-Tools
)
