# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -std=c11 -O2

# Dossier des sources
SRC_DIR = algorithme_code

# Fichiers sources
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/ListSet.c \
       $(SRC_DIR)/StringArray.c

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Exécutable
TARGET = intersection

.PHONY: all clean re

# Cible par défaut
all: $(TARGET)

# Édition de liens
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compilation des fichiers .c
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJS) $(TARGET)

# Recompilation complète
re: clean all
