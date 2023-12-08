# TP de Synthèse – Ensea in the Shell (FRANCILLONNE Radji/GAMIETTE David)
## Q1) Affichage d’un message d’accueil, suivi d’un prompt simple
On souhaite afficher un message d’accueil dans la console, sans utiliser `printf()`. De ce fait, on va utiliser la fonction `write(int sortie, "message à afficher", int longueur du message)`.
On va assigner à L la valeur de longueur du message pour des soucis de lisibilité et de compréhension.

Remarque : Si L ne respecte pas la longueur de "message à afficher", alors on va soit afficher les L premiers caractères dans le cas où L<strlen("message à afficher"), sinon des caractères ASCII dans le cas où L>strlen("message à afficher").  

_strlen permet de retourner la valeur de la longueur d’une chaine de caractère mis en argument de cette fonction._

## Q2) Exécution de la commande saisie et retour au prompt (REPL : read–eval–print loop)
- Lecture de la commande saisie

On utilise la fonction `scanf("%s",char* buff)` afin de lire la commande rentrée. Dans notre cas, buff pointe vers la commande saisie.

- Exécution d’une commande simple (sans argument)

La fonction `execvp(char* buff, NULL)` permet d’éxecuter la commande qui est pointé par buff. L’argument permet de traiter les cas où la commande n’est pas compris dans une liste de commande qu’on aurait fournie en 2e argument de la fonction `execvp()`.
