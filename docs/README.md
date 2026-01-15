# Projet : Intersection de fichiers - L2 SDA (Janvier 2020)

## Description
Ce projet consiste à implémenter une structure de données de type **ensemble (Set)** et à l’utiliser
pour calculer l’intersection de deux fichiers texte, ligne par ligne.

L’implémentation fournie repose sur une **liste chaînée**, conformément au code de base fourni dans l’énoncé.

Le programme affiche les lignes communes aux deux fichiers passés en argument, sans ordre particulier.

---

## Arborescence du projet

```

Projet/
├── algorithme_code/
│   ├── main.c
│   ├── ListSet.c
│   ├── Set.h
│   ├── StringArray.c
│   ├── StringArray.h
│   ├── A.txt
│   ├── B.txt
│   ├── English.txt
│   └── French.txt
├── docs/
│   └── README.md
│   └── sujet_projet_janvier2020.pdf
├── Makefile
└── .gitignore

```

---

## Compilation

### Compilation avec makefile

Depuis la racine du projet :

```bash
make
```

Cette commande génère l’exécutable `intersection`.

### Compilation sans makefile

Depuis le dossier `algorithme_code` :

```bash
cd algorithme_code
gcc -Wall -Wextra -std=c11 -O2 main.c ListSet.c StringArray.c -o intersection
```

---

## Exécution

```bash
./intersection fichier1.txt fichier2.txt
```

### Exemple depuis la racine du projet

```bash
./intersection algorithme_code/A.txt algorithme_code/B.txt
```

### Exemple depuis le dossier `algorithme_code`

```bash
cd algorithme_code
./intersection A.txt B.txt
```

### Sortie attendue

```
bbb
eee
```

(L’ordre d’affichage n’a pas d’importance.)

---

## Nettoyage depuis la racine du projet

Pour supprimer les fichiers objets et l’exécutable :

```bash
make clean
```

---

## Auteur

Projet réalisé dans le cadre du cours **Structures de Données et Algorithmes (L2)**
Université – Janvier 2020
