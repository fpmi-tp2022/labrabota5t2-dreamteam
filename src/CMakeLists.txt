cmake_minimum_required(VERSION 3.21)

project(hippodrome)		
# Setting the global variable that contains root path to the current project.
set(${PROJECT_NAME}_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "include directory")
		

macro(add_source_folder folder_name)
  set(${folder_name}_files "")
  message(STATUS ../${folder_name}/imp/*.cpp )
  file(GLOB ${folder_name}_files RELATIVE ${CMAKE_CURRENT_LIST_DIR}
												  ./${folder_name}/imp/*.cpp 
												  ./${folder_name}/imp/*.c
												  ./${folder_name}/*.h)
  source_group(${folder_name} FILES ${${folder_name}_files})
  message(STATUS ${${folder_name}_files} ${${folder_name}_files})
  set(FILES_SOURCE ${FILES_SOURCE} ${${folder_name}_files})
endmacro()


add_source_folder(Authorization)
add_source_folder(DBManagment)
add_source_folder(Repositories)
add_source_folder(UserInteraction)

set(FILES_SOURCE ${FILES_SOURCE} main.cpp)				


add_executable(${PROJECT_NAME} ${FILES_SOURCE})
add_library(${PROJECT_NAME}_lib ${FILES_SOURCE})