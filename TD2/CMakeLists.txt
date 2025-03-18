# Ajouter le répertoire source
include_directories(src)

# Ajouter les fichiers sources
file(GLOB SOURCES "src/*.cpp")

# Créer un exécutable pour TD2
add_executable(TD2 ${SOURCES})