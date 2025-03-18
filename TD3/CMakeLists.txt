# Ajouter le répertoire source
include_directories(src)

# Ajouter les fichiers sources
file(GLOB SOURCES "src/*.cpp")

# Créer un exécutable pour TD3
add_executable(TD3 ${SOURCES})