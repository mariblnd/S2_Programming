# Ajouter le répertoire source
cmake_minimum_required(VERSION 3.20)
project(TD2)
include_directories(src)

# Ajouter les fichiers sources
file(GLOB SOURCES "src/*.cpp")

# Créer un exécutable pour TD2
add_executable(TD2 ${SOURCES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

