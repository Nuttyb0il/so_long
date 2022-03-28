Les consignes du jeu :
[✅] Le but du joueur est de collecter tous les items présents sur la carte, puis de s’échapper en empruntant le chemin le plus court possible.
[✅] Les touches W, A, S et D doivent être utilisées afin de mouvoir le personnage principal.
[✅] Le joueur doit être capable de se déplacer dans ces 4 directions : haut, bas, gauche, droite.
[✅] Le joueur ne doit pas pouvoir se déplacer dans les murs
[⭐] À chaque mouvement, le compte total de mouvement doit être affiché dans le shell. (mais je vais le faire dans la fenêtre donc bonus)
[✅] Vous devez utiliser une vue 2D (vue de haut ou de profil)
[✅] Le jeu n’a pas à être en temps réel
[✅] Bien que les exemples donnés montrent un thème dauphin, vous êtes libre de créer l’univers que vous voulez. 

Règles gestion graphique : 
[✅] Votre programme doit afficher une image dans une fenêtre.
[✅] La gestion de la fenêtre doit rester fluide (changer de fenêtre, la réduire, etc.).
[✅] Appuyer sur la touche ESC doit fermer la fenêtre et quitter le programme proprement.
[✅] Cliquer sur la croix en haut de la fenêtre doit fermer celle-ci et quitter le programme proprement.
[✅] Utiliser les images de la MiniLibX est obligatoire.

Règles de la carte (selon le parser de mon programme) :
[✅] La carte sera construite en utilisant 3 éléments : les murs, les items à collecter, et l’espace vide.
[✅] La carte doit contenir au moins 1 sortie, 1 item et 1 position de départ.
[✅] La carte doit être de forme rectangulaire.
[✅] La carte doit être fermée en étant encadrée par des murs. Si ce n’est pas le cas, le programme retourne une erreur.
[✅] Vous devez pouvoir parser tout type de carte du moment qu’elle respecte les règles énoncées ci-dessus.
[⭐] Si une erreur de configuration est détectée, le programme doit quitter proprement et retourner "Error\n" suivi d’un message d’erreur explicite de votre choix.

Bonus :
[❌] Le joueur peut perdre si son personnage est touché par une patrouille ennemie. (volontairement pas fait)
[⭐] Vous ajoutez des sprite animations.
[⭐] Le compte total de mouvement est directement affiché sur l’écran dans la fenêtre plutôt que dans le shell.

(comme on a le droit d'inventer nos bonus)
[⭐] Parser intéractif avec un joli linter
[⭐] Sprites placés aléatoirement dans une tile
[🐛] Spawn aléatoire si il y a plusieurs spawns dans la carte 

Reste à faire (trié par importance) : 
[✅] Fichier .tbl
[✅] Faire rebondir objets
[⏳] Table debug
[⏳] Utiliser des sprites plus petit si la map est très grande
[⏳] Barre de status
[⏳] Level designer