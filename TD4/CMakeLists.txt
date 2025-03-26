# Ajouter le répertoire source
cmake_minimum_required(VERSION 3.20)
project(TD4)
include_directories(src)


# Ajouter les fichiers sources
file(GLOB SOURCES "src/*.cpp")

# Créer un exécutable pour TD3
add_executable(TD4 ${SOURCES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)