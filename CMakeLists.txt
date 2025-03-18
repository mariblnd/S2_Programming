cmake_minimum_required(VERSION 3.10)

# Définir le nom du projet
project(TD)

# Spécifier le standard C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajouter des options pour activer/désactiver les dossiers
option(BUILD_TD1 "Build the TD1 executable" OFF)
option(BUILD_TD2 "Build the TD2 executable" OFF)
option(BUILD_TD3 "Build the TD3 executable" ON)

# Ajouter les sous-dossiers
if(BUILD_TD1)
    add_subdirectory(TD1)
endif()

if(BUILD_TD2)
    add_subdirectory(TD2)
endif()

if(BUILD_TD3)
    add_subdirectory(TD3)
endif()