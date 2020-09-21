SUJET :
Cub3D est un projet visant à simuler un parcours de labyrinthe en perspective, donnant l'impression de 3D grâce à une technique appelée ray-casting, tout en utilisant la mini-libX.
Ce sujet puise son essence dans le célèbre jeu-vidéo Wolfenstein3D.

RENDU :
- Makefile : all, clean, fclean, re, bonus
- Un fichier conf.cub contiendra les infos formatées* de configuration de lancement et de map.
- Le programme doit rejeter toute configuration erronée.
- Fonctions autorisées : open, close, read, write, malloc, free, perror, strerror, exit, ainsi que toutes les fonctions de la lib math, de la mlx, et de la libft.

CONSIGNES :
- La gestion des fenêtres doit être parfaite : gestion de minimalisation, passage à une autre fenêtre etc.
- Les textures des murs du labytinthe doivent être différentes selon l'orientation Nord Est West Sud.
- Le programme doit pouvoir afficher un sprite.
- Le programme doit pouvoir sauver la première image rendue au format bmp lorsque le second argument est "––save".
- Les touches flèches directionnelles gauche et droite doivent pouvoir servir à effectuer une rotation de caméra.
- Les touches WASD doivent permettre de se déplacer d'avant en arrière et en strafant.
- Appuyer sur ESC doit faire quitter proprement le programme et fermer la fenêtre.
- Idem lorsqu'on appuie sur la croix rouge en bordure de fenêtre.

*FORMAT :
- Exemple de fichier de conf :
+-----------------------------------+
| R 1920 1080                       |
| NO ./path_to_the_north_texture    |
| SO ./path_to_the_south_texture    |
| WE ./path_to_the_west_texture     |
| EA ./path_to_the_east_texture     |
|                                   |
| S ./path_to_the_sprite_texture    |
| F 220,100,0                       |
| C 225,30,0                        |
|                                   |
|         1111111111111111111111111 |
|         1000000000110000000000001 |
|         1011000001110000002000001 |
|         1001000000000000000000001 |
| 111111111011000001110000000000001 |
| 100000000011000001110111111111111 |
| 11110111111111011100000010001     |
| 11110111111111011101010010001     |
| 11000000110101011100000010001     |
| 10002000000000001100000010001     |
| 10000000000000001101010010001     |
| 11000001110101011111011110N0111   |
| 11110111 1110101 101111010001     |
| 11111111 1111111 111111111111     |
+-----------------------------------+
- Les arguments peuvent être listés dans n'importe quel ordre.
- La map doit être à la fin.
- Les différentes informations sur chaque ligne peuvent être séparées par un ou plusieurs espaces.
- La map doit contenir uniquement les caractères : '0' = espace, '1' = mur, '2' = sprite, 'N'/'E'/'W'/'S' = position et direction du joueur au lancement du programme.
- Si la Résolution demandée est plus grande que l'écran, celle-ci doit se réajuster à la résolution max.
- La map doit être entièrement fermée par des murs.
- Chaque ligne peut être espacée d'une ou plusieurs lignes vides.
- Les espaces sont pris en compte dans le parsing de la map, et doivent donc aussi être alloués.

//////////////////////////////////////////////////////////////////////////////////

ELEMENTS DE RESOLUTION

I/ La mlx
 1. Installer la mlx
 2. La faire compiler
 3. Afficher une fenêtre
 4. Faire fonctionner les options de la fenêtre
 4. Dessiner un carré de pixels colorés dans la fenêtre

II/ Le parsing
 1. Déclarer les structures et les allouer / initialiser à l'aide de "constructors"
 2. Aller chercher les valeurs décrites dans le fichier à l'aide de setters qui utilisent get_next_line pour :
  a. les infos de résolution / couleurs / textures
  b. la map
 3. Checker si les valeurs sont correctes / existantes pour chaque élément.

III/ Le Rendering
 1. Faire une boucle qui actualise la position et l'orientation du joueur dans la map en fonction des touches appuyées en utilisant:
  a. Une fonction de translation
  b. Une fonction de rotation
  c. Une gestion de collision aux limites de la map, sinon segfault
 2. Pour afficher le résultat à l'écran, utiliser une fonction de ray-casting calculant :
  a. La distance du joueur le séparant du premier mur rencontré en prolongeant son axe central de champs de vision et tous les autres axes sur chaque pixel en largeur.
  b. La hauteur des murs en fonction de cette direction pour chaque bande verticale de pixels
  c. Ajuster les texels de la texture concernée en conséquence.