CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

# ********************************** 添加项目名 **********************************
PROJECT(BaseTools)
MESSAGE(STATUS "set project name: ${PROJECT_NAME}")

# ********************************** 添加include目录 **********************************
SET(INCLUDE_DIRS include src)
INCLUDE_DIRECTORIES(${INCLUDE_DIRS})
MESSAGE(STATUS "set include dirs: ${INCLUDE_DIRS}")

# ********************************** 添加子模块目录 **********************************
ADD_SUBDIRECTORY(src)
