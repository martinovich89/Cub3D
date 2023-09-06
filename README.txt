***    -- SUJET --    ***
Cub3D est un projet visant à simuler un parcours de labyrinthe en perspective, donnant l'impression de 3D grâce à une technique appelée ray-casting, tout en utilisant la mini-libX.
Ce sujet puise son essence dans le célèbre jeu-vidéo Wolfenstein3D.

***    -- RENDU --    ***
- Makefile : all, clean, fclean, re, bonus
- Un fichier conf.cub contiendra les infos formatées* de configuration de lancement et de map.
- Le programme doit rejeter toute configuration erronée.
- Fonctions autorisées : open, close, read, write, malloc, free, perror, strerror, exit, ainsi que toutes les fonctions de la lib math, de la mlx, et de la libft.

***    -- CONSIGNES --    ***
- La gestion des fenêtres doit être parfaite : gestion de minimalisation, passage à une autre fenêtre etc.
- Les textures des murs du labytinthe doivent être différentes selon l'orientation Nord Est West Sud.
- Le programme doit pouvoir afficher un sprite.
- Le programme doit pouvoir sauver la première image rendue au format bmp lorsque le second argument est "––save".
- Les touches flèches directionnelles gauche et droite doivent pouvoir servir à effectuer une rotation de caméra.
- Les touches WASD doivent permettre de se déplacer d'avant en arrière et en strafant.
- Appuyer sur ESC doit faire quitter proprement le programme et fermer la fenêtre.
- Idem lorsqu'on appuie sur la croix rouge en bordure de fenêtre.

***   -- FORMAT --   ***
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

***    -- REMARQUES --    ***

Espaces permis uniquement entre informations dans les éléments (pas avant, pas apres).
Lignes vides permises uniquement entre les éléments (pas d'espace dedans.)
Une ligne vide sera permise à la fin du fichier, afin de faciliter l'édition vim en correction.
Afin de garantir une bonne expérience utilisateur, la résolution minimale autorisée est 300 x 300.
Un rgb est compté comme une seule et entière information. Nul espace autorisé entre r, g et b.
L'utilisation de la fonction exit rend le free des still reachable optionel dans ce projet.
A cause de la remarque précédente, l'utilisation de valgrind n'est pas recommandée dans ce projet.
Noter que l'utilisation de la transparence est rendue impossible pour les sprites (v1.0).