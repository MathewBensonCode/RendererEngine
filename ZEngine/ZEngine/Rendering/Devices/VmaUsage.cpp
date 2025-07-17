/*
 * We define those Macros before inclusion of VulkanDevice.h so we can enable impl from VMA header
 */
#define VMA_IMPLEMENTATION
#define VMA_VULKAN_VERSION 1003000 // Vulkan 1.3
#include <vk_mem_alloc.h>                            
