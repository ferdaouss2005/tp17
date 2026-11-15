# tp17

EXERCICE1


<img width="147" height="224" alt="image" src="https://github.com/user-attachments/assets/3d72ce12-74e7-4c8c-a60d-60e1f3d93ec4" />

# Exercice 1 – Classe Point3D

Dans cet exercice, nous avons créé une classe `Point3D` permettant de représenter un point dans un espace à trois dimensions à l'aide de trois coordonnées : X, Y et Z. Nous avons séparé le projet en trois fichiers : `Point3D.h` contenant la déclaration de la classe, `Point3D.cpp` contenant la définition de ses méthodes et `main.cpp` permettant de tester son fonctionnement. Dans le programme principal, nous avons créé deux objets de type `Point3D` : le premier avec les coordonnées (2, 3, 4) et le deuxième avec les coordonnées (5, 6, 7). Nous avons ensuite affiché les coordonnées des deux points à l'écran. La compilation et l'exécution du programme ont été réalisées avec succès, et le résultat obtenu est : « Premier point : X = 2, Y = 3, Z = 4 » et « Deuxième point : X = 5, Y = 6, Z = 7 ». Cet exercice nous a permis de comprendre la création d'une classe en C++, la séparation entre les fichiers header et source, ainsi que l'instanciation et l'utilisation des objets.





EXERCICE2


<img width="593" height="62" alt="image" src="https://github.com/user-attachments/assets/aead06f2-7528-4367-a2f8-804b22832136" />



Geo2D – Mini-bibliothèque géométrique

Description

Ce projet consiste à créer une petite bibliothèque géométrique en C++ contenant trois classes : Point, Segment et Triangle.

Structure du projet

Geo2D/
│
├── include/
│   ├── Point.h
│   ├── Segment.h
│   └── Triangle.h
│
├── src/
│   ├── Point.cpp
│   ├── Segment.cpp
│   └── Triangle.cpp
│
├── main.cpp
├── Makefile
└── README.md

Les classes

Point : représente un point dans un plan avec deux coordonnées (x, y).

Segment : représente un segment entre deux points et contient la méthode longueur().

Triangle : représente un triangle formé de trois points et contient la méthode perimetre().

Chaque classe possède un constructeur par défaut et un constructeur paramétré.

Compilation et exécution

Compiler le projet avec g++ :

g++ -Iinclude main.cpp src/Point.cpp src/Segment.cpp src/Triangle.cpp -o demo.exe

Exécuter le programme :

.\demo.exe

Résultat attendu

# Exercice 3 – Création d'une bibliothèque statique et partagée

<img width="413" height="41" alt="image" src="https://github.com/user-attachments/assets/b12ca5a5-e5d1-4b3c-bffc-c4e30b5cbc6d" />


<img width="454" height="44" alt="image" src="https://github.com/user-attachments/assets/e9f11fdc-f2f8-4398-93c8-92f6cdd7f470" />


## 1. Objectif

Créer une bibliothèque C++ réutilisable contenant deux classes :
- `Logger` : implémentation du pattern Singleton pour afficher des messages.
- `Config` : chargement et lecture des paramètres depuis un fichier de configuration.

L'objectif est de créer et tester une bibliothèque statique et une bibliothèque partagée.

## 2. Structure du projet

```text
UtilLib/
│
├── include/
│   ├── Logger.h
│   └── Config.h
│
├── src/
│   ├── Logger.cpp
│   └── Config.cpp
│
├── config.json
├── testLib.cpp
├── Logger.o
├── Config.o
├── libutil.a
├── libutil.dll
├── libutil.dll.a
├── testLib.exe
└── testShared.exe
```

## 3. Compilation des fichiers sources

```bash
g++ -Iinclude -c src/Logger.cpp src/Config.cpp
```

Cette commande génère les fichiers objets `Logger.o` et `Config.o`.

## 4. Création de la bibliothèque statique

```bash
ar rcs libutil.a Logger.o Config.o
```

### Liaison et exécution

```bash
g++ testLib.cpp -Iinclude ./libutil.a -o testLib.exe
.\testLib.exe
```

## 5. Création de la bibliothèque partagée

Sous Windows avec MinGW :

```bash
g++ -shared -o libutil.dll Logger.o Config.o "-Wl,--out-implib,libutil.dll.a"
```

### Liaison et exécution

```bash
g++ testLib.cpp -Iinclude -L. -lutil -o testShared.exe
.\testShared.exe
```

## 6. Résultat obtenu

Les deux programmes affichent le même résultat :

```text
[LOG] Application demarree
Nom : Ferdaouss
```

## 7. Différence entre bibliothèque statique et partagée

- **Bibliothèque statique (.a)** : le code de la bibliothèque est intégré dans l'exécutable lors de la compilation et de l'édition des liens.
- **Bibliothèque partagée (.so sous Linux / .dll sous Windows)** : le code est chargé dynamiquement à l'exécution. La bibliothèque doit être accessible au système.

## 8. Rôle de LD_LIBRARY_PATH

Sous Linux, `LD_LIBRARY_PATH` permet d'indiquer au système les répertoires supplémentaires dans lesquels rechercher les bibliothèques partagées `.so`.

Exemple :

```bash
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
```

Sous Windows, cette variable n'est pas utilisée. Le système recherche notamment les DLL dans le dossier de l'exécutable et dans les répertoires du `PATH`.

## 9. Conclusion

Cet exercice a permis de créer, compiler et tester une bibliothèque statique et une bibliothèque partagée en C++. Il a également permis de comprendre les différences entre ces deux types de bibliothèques et leur utilisation dans un projet.

# Exercice 4 – Classe Template et fichier d'en-tête uniquement





Dans cet exercice, nous avons créé une classe template `Matrix<T, N, M>` dans le fichier `Matrix.h` afin de manipuler des matrices de taille fixe avec différents types de données et dimensions. Cette classe contient une méthode `at(i, j)` pour accéder aux éléments, l'opérateur `+` pour additionner deux matrices de mêmes dimensions, l'opérateur `*` pour effectuer leur multiplication et l'opérateur `<<` pour afficher les matrices. Dans le fichier `main.cpp`, nous avons instancié deux matrices entières `Matrix<int, 2, 2>` nommées A et B, puis effectué leur affichage, leur addition et leur multiplication. Nous avons également créé une matrice réelle `Matrix<double, 3, 3>` afin de tester la classe avec le type `double`. La compilation a été réalisée avec la commande `g++ -c main.cpp -o main.o`, qui génère un seul fichier objet, puis nous avons créé l'exécutable et lancé le programme. Aucune compilation séparée de `Matrix.h` n'est nécessaire, car toutes les méthodes templates sont définies dans le fichier d'en-tête. Enfin, déplacer ces définitions dans un fichier `.cpp` séparé pourrait provoquer une erreur de liaison (`undefined reference`), car le compilateur doit avoir accès à leur définition complète au moment de l'instanciation du template.
