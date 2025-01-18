#include <stdio.h>
#include <string.h>

// Structures utulisées
typedef struct {
    char nom[50];
    int age;
    float score;
} Participant;

typedef struct {
    char nomCompetition[50];
    Participant participants[100];
    int nbParticipants;
} Competition;

Competition competitions[20];//declarer tableau de competitions
int nbCompetitions = 0;

// fonctions developpée
void ajouterCompetition() {
    if (nbCompetitions >= 20) {
        printf("\n Le tableau des competitions est complet.\n");
        return;
    }

    printf("\nEntrez nom de la competition : ");
    scanf("%s", competitions[nbCompetitions].nomCompetition);
    competitions[nbCompetitions].nbParticipants = 0;
    nbCompetitions++;
    printf("Competition ajoutee avec succes !\n");
}

void ajouterParticipant() {
    if (nbCompetitions == 0) {
        printf("\n Pas de competitions trouvees,ajoutez une competition d'abord.\n");
        return;
    }

    char nomCompetition[50];
    printf("\nEntrez nom de la competition : ");
    scanf("%s", nomCompetition);

    for (int i = 0; i < nbCompetitions; i++) {
        if (strcmp(competitions[i].nomCompetition, nomCompetition) == 0) {
            if (competitions[i].nbParticipants >= 100) {
                printf("\n Vous avez depasser la limite.\n");
                return;
            }

            Participant p;
            printf("\nEntrez nom du participant : ");
            scanf("%s", p.nom);
            printf("Entrez l'age du participant : ");
            scanf("%d", &p.age);
            printf("Entrez le score du participant : ");
            scanf("%f", &p.score);

            competitions[i].participants[competitions[i].nbParticipants++] = p;
            printf("Participant ajoute avec succes \n");
            return;
        }
    }

    printf("\nCompetition introuvable.\n");
}

void afficherParticipants() {
    if (nbCompetitions == 0) {
        printf("\n Pas de competition trouver.\n");
        return;
    }

    char nomCompetition[50];
    printf("\nEntrez nom de la competition : ");
    scanf("%s", nomCompetition);

    for (int i = 0; i < nbCompetitions; i++) {
        if (strcmp(competitions[i].nomCompetition, nomCompetition) == 0) {
            if (competitions[i].nbParticipants == 0) {
                printf("\nAucun participant dans cette competition.\n");
                return;
            }

            printf("\nParticipants de la competition %s :\n", nomCompetition);
            for (int j = 0; j < competitions[i].nbParticipants; j++) {
                Participant p = competitions[i].participants[j];
                printf("Nom : %s, Age : %d, Score : %.2f\n", p.nom, p.age, p.score);
            }
            return;
        }
    }

    printf("\nCompetition introuvable.\n");
}

void trouverMeilleurParticipant() {
    if (nbCompetitions == 0) {
        printf("\n Pas de competition trouver.\n");
        return;
    }

    char nomCompetition[50];
    printf("\nEntrez nom de la competition : ");
    scanf("%s", nomCompetition);

    for (int i = 0; i < nbCompetitions; i++) {
        if (strcmp(competitions[i].nomCompetition, nomCompetition) == 0) {
            if (competitions[i].nbParticipants == 0) {
                printf("\nAucun participant dans cette competition.\n");
                return;
            }

            Participant meilleur = competitions[i].participants[0];
            for (int j = 1; j < competitions[i].nbParticipants; j++) {
                if (competitions[i].participants[j].score > meilleur.score) {
                    meilleur = competitions[i].participants[j];
                }
            }

            printf("\nMeilleur participant : Nom : %s, Age : %d, Score : %.2f\n",
                   meilleur.nom, meilleur.age, meilleur.score);
            return;
        }
    }

    printf("\nCompetition introuvable.\n");
}

void calculerMoyenneScores() {
    if (nbCompetitions == 0) {
        printf("\nPas de competition trouver .\n");
        return;
    }

    char nomCompetition[50];
    printf("\nEntrez le nom de la competition : ");
    scanf("%s", nomCompetition);

    for (int i = 0; i < nbCompetitions; i++) {
        if (strcmp(competitions[i].nomCompetition, nomCompetition) == 0) {
            if (competitions[i].nbParticipants == 0) {
                printf("\nAucun participant dans cette competition.\n");
                return;
            }

            float somme = 0;
            for (int j = 0; j < competitions[i].nbParticipants; j++) {
                somme += competitions[i].participants[j].score;
            }

            float moyenne = somme / competitions[i].nbParticipants;
            printf("\nMoyenne des scores : %.2f\n", moyenne);
            return;
        }
    }

    printf("\nPas de competition trouver .\n");
}

void afficherParticipantsScoreSuperieur() {
    if (nbCompetitions == 0) {
        printf("\nPas de competition trouver .\n");
        return;
    }

    char nomCompetition[50];
    float scoreMin;
    printf("\nEntrez nom de la competition : ");
    scanf("%s", nomCompetition);
    printf("Entrez le score minimum : ");
    scanf("%f", &scoreMin);

    for (int i = 0; i < nbCompetitions; i++) {
        if (strcmp(competitions[i].nomCompetition, nomCompetition) == 0) {
            if (competitions[i].nbParticipants == 0) {
                printf("\nAucun participant dans cette competition.\n");
                return;
            }

            printf("\nParticipants avec un score > %.2f :\n", scoreMin);
            for (int j = 0; j < competitions[i].nbParticipants; j++) {
                if (competitions[i].participants[j].score > scoreMin) {
                    Participant p = competitions[i].participants[j];
                    printf("Nom : %s, Age : %d, Score : %.2f\n", p.nom, p.age, p.score);
                }
            }
            return;
        }
    }

    printf("\nPas de competition trouver.\n");
}

int main() {
    int choix;

    do {
        printf("\n======  Gestion des resultats sportifs ======\n");
        printf("1. Ajouter une competition\n");
        printf("2. Ajouter un participant a une competition \n");
        printf("3. Afficher les participants d'une competition\n");
        printf("4. Trouver le meilleur participant d'une competition \n");
        printf("5. Calculer la moyenne des scores d'une competition\n");
        printf("6. Afficher les participants avec un score superieur a une valeur\n");
        printf("7. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterCompetition();
                break;
            case 2:
                ajouterParticipant();
                break;
            case 3:
                afficherParticipants();
                break;
            case 4:
                trouverMeilleurParticipant();
                break;
            case 5:
                calculerMoyenneScores();
                break;
            case 6:
                afficherParticipantsScoreSuperieur();
                break;
            case 7:
                printf("\n c\'est la fin de programme ,Au revoir !\n");
                break;
            default:
                printf("\nChoix invalide, Veuillez choisir un nombre entre 1 et 7.\n");
        }
    } while (choix != 7);

    return 0;
}

