#QUal a versao que o CMAKE precisa
cmake_minimum_required(VERSION 2.8.3)

#Nome do pacote
project(cursoros-pkg)

#Acha o build system do ROS e os pacotes que dependemos
find_package(catkin REQUIRED COMPONENTS roscpp geometry_msgs turtlesim) 

#Declara o pacote do catkin.
catkin_package()

#Especifica local dos arquivos headers.
include_directories(include ${catkin_INCLUDE_DIRS})

#Adiciona um executavel e seus arquivos fonte;
add_executable(hello hello.cpp)
add_executable(pubvel pubvel.cpp)
add_executable(subpose subpose.cpp)

#Bibliotecas que devem ser linkadas.
target_link_libraries(hello ${catkin_LIBRARIES})
target_link_libraries(pubvel ${catkin_LIBRARIES})
target_link_libraries(subpose ${catkin_LIBRARIES})