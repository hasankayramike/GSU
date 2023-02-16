#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "TP01.h"

int main(void)
{
    char operation[2], where[2], insertAfter[999], songToDelete[999], songToPlay[999], addSong[999], addArtist[999], addAlbum[999];
    int addDuration, addYear;
    char listType[4];
    printf("SL/CSL/DL/CDL: ");
    scanf("%s", listType);

    printf("Add your first song to the list\n");
    char song[999];
        printf("Song: ");
        scanf(" %[^\n]s", song);
    char artist[999]; 
        printf("Artist: ");
        scanf(" %[^\n]s", artist);
    char album[999]; 
        printf("Album: ");
        scanf(" %[^\n]s", album);
    int duration;
        printf("Duration in seconds: ");
        scanf("%d", &duration);
    int year;
        printf("Release Year: ");
        scanf("%d", &year);


    if (!strcasecmp(listType, "SL"))
    {
        list* SL = createNewListSL(song, artist, album, duration, year);
        printf("(a) to add a new song\n");
        printf("(d) to delete a song\n");
        printf("(p) to play a song\n");
        printf("(l) to list your songs\n");
        printf("To quit, enter any other key\n");
        printf(">>> "); scanf("%s", operation);
        while (!strcasecmp(operation, "a") || !strcasecmp(operation, "d") || !strcasecmp(operation, "p") || !strcasecmp(operation, "l"))
        {
            switch (tolower(operation[0]))
            {
                case 'a':

                    printf("(b) add at the beginning of the list\n");
                    printf("(m) add at the middle of the list\n");
                    printf("(e) add at the end of the list\n");
                    printf(">>> "); scanf("%s", where);
                    switch (tolower(where[0]))
                    {
                        case 'b':
                            printf("Song: ");
                            scanf(" %[^\n]s", addSong);
                            
                            printf("Artist: ");
                            scanf(" %[^\n]s", addArtist);
                            
                            printf("Album: ");
                            scanf(" %[^\n]s", addAlbum);
                            
                            printf("Duration in seconds: ");
                            scanf("%d", &addDuration);
                            
                            printf("Release Year: ");
                            scanf("%d", &addYear);
                    
                            insertAtTheBeginningSL(SL, addSong, addArtist, addAlbum, addDuration, addYear);
                            break;
                        case 'm':
                            printf("Song: ");
                            scanf(" %[^\n]s", addSong);
                            
                            printf("Artist: ");
                            scanf(" %[^\n]s", addArtist);
                            
                            printf("Album: ");
                            scanf(" %[^\n]s", addAlbum);
                            
                            printf("Duration in seconds: ");
                            scanf("%d", &addDuration);
                            
                            printf("Release Year: ");
                            scanf("%d", &addYear);
                    
                            printf("Add after this song: ");
                            scanf(" %[^\n]s", insertAfter);
                            insertAfterANodeSL(SL, insertAfter, addSong, addArtist, addAlbum, addDuration, addYear);
                            break;
                        case 'e':
                            printf("Song: ");
                            scanf(" %[^\n]s", addSong);
                            
                            printf("Artist: ");
                            scanf(" %[^\n]s", addArtist);
                            
                            printf("Album: ");
                            scanf(" %[^\n]s", addAlbum);
                            
                            printf("Duration in seconds: ");
                            scanf("%d", &addDuration);
                            
                            printf("Release Year: ");
                            scanf("%d", &addYear);
                            
                            insertAtTheEndSL(SL, addSong, addArtist, addAlbum, addDuration, addYear);
                            break;
                        default:
                            printf("Invalid command!\n");
                            break;
                    }
                    break;
                case 'd':
                    printf("(f) delete the first song\n");
                    printf("(s) delete a specific song\n");
                    printf("(l) delete the last song\n");
                    printf(">>> "); scanf("%s", where);
                    switch (tolower(where[0]))
                    {
                        case 'f':
                            removeFirstNodeSL(SL);
                            break;
                        case 's':
                            printf("Which song should be deleted: ");
                            scanf(" %[^\n]s", songToDelete);
                            removeFromMiddleSL(SL, songToDelete);
                            break;
                        case 'l':
                            removeLastNodeSL(SL);
                            break;
                        default:
                            printf("Invalid command!\n");
                            break;
                    }
                    break;
                case 'p':
                    printf("Which song would you like to play: ");
                    scanf(" %[^\n]s", songToPlay);
                    printNodeSL(SL, songToPlay);
                    break;
                case 'l':
                    printListSL(SL);
                    break;
                default:
                    break;
            }
            printf("(a) to add a new song\n");
            printf("(d) to delete a song\n");
            printf("(p) to play a song\n");
            printf("(l) to list your songs\n");
            printf("To quit, enter any other key\n");
            printf(">>> "); scanf("%s", operation);
        }
        printf("Byeee!\n");
        free(SL);
        return 0;
    }


    if (!strcasecmp(listType, "CSL"))
    {
        list* CSL = createNewListCSL(song, artist, album, duration, year);
        printf("(a) to add a new song\n");
        printf("(d) to delete a song\n");
        printf("(p) to play a song\n");
        printf("(l) to list your songs\n");
        printf("To quit, enter any other key\n");
        printf(">>> "); scanf("%s", operation);
        while (!strcasecmp(operation, "a") || !strcasecmp(operation, "d") || !strcasecmp(operation, "p") || !strcasecmp(operation, "l"))
        {
            switch (tolower(operation[0]))
            {
                case 'a':

                    printf("(b) add at the beginning of the list\n");
                    printf("(m) add at the middle of the list\n");
                    printf("(e) add at the end of the list\n");
                    printf(">>> "); scanf("%s", where);
                    switch (tolower(where[0]))
                    {
                        case 'b':
                            printf("Song: ");
                            scanf(" %[^\n]s", addSong);
                            
                            printf("Artist: ");
                            scanf(" %[^\n]s", addArtist);
                            
                            printf("Album: ");
                            scanf(" %[^\n]s", addAlbum);
                            
                            printf("Duration in seconds: ");
                            scanf("%d", &addDuration);
                            
                            printf("Release Year: ");
                            scanf("%d", &addYear);
                    
                            insertAtTheBeginningCSL(CSL, addSong, addArtist, addAlbum, addDuration, addYear);
                            break;
                        case 'm':
                            printf("Song: ");
                            scanf(" %[^\n]s", addSong);
                            
                            printf("Artist: ");
                            scanf(" %[^\n]s", addArtist);
                            
                            printf("Album: ");
                            scanf(" %[^\n]s", addAlbum);
                            
                            printf("Duration in seconds: ");
                            scanf("%d", &addDuration);
                            
                            printf("Release Year: ");
                            scanf("%d", &addYear);
                    
                            printf("Add after this song: ");
                            scanf(" %[^\n]s", insertAfter);
                            insertAfterANodeCSL(CSL, insertAfter, addSong, addArtist, addAlbum, addDuration, addYear);
                            break;
                        case 'e':
                            printf("Song: ");
                            scanf(" %[^\n]s", addSong);
                            
                            printf("Artist: ");
                            scanf(" %[^\n]s", addArtist);
                            
                            printf("Album: ");
                            scanf(" %[^\n]s", addAlbum);
                            
                            printf("Duration in seconds: ");
                            scanf("%d", &addDuration);
                            
                            printf("Release Year: ");
                            scanf("%d", &addYear);
                            
                            insertAtTheEndCSL(CSL, addSong, addArtist, addAlbum, addDuration, addYear);
                            break;
                        default:
                            printf("Invalid command!\n");
                            break;
                    }
                    break;
                case 'd':
                    printf("(f) delete the first song\n");
                    printf("(s) delete a specific song\n");
                    printf("(l) delete the last song\n");
                    printf(">>> "); scanf("%s", where);
                    switch (tolower(where[0]))
                    {
                        case 'f':
                            removeFirstNodeCSL(CSL);
                            break;
                        case 's':
                            printf("Which song should be deleted: ");
                            scanf(" %[^\n]s", songToDelete);
                            removeFromMiddleCSL(CSL, songToDelete);
                            break;
                        case 'l':
                            removeLastNodeCSL(CSL);
                            break;
                        default:
                            printf("Invalid command!\n");
                            break;
                    }
                    break;
                case 'p':
                    printf("Which song would you like to play: ");
                    scanf(" %[^\n]s", songToPlay);
                    printNodeCSL(CSL, songToPlay);
                    break;
                case 'l':
                    printListCSL(CSL);
                    break;
                default:
                    break;
            }
            printf("(a) to add a new song\n");
            printf("(d) to delete a song\n");
            printf("(p) to play a song\n");
            printf("(l) to list your songs\n");
            printf("To quit, enter any other key\n");
            printf(">>> "); scanf("%s", operation);
        }
        printf("Byeee!\n");
        free(CSL);
        return 0;
    }

    if (!strcasecmp(listType, "DL"))
    {
        list* DL = createNewListDL(song, artist, album, duration, year);
        printf("(a) to add a new song\n");
        printf("(d) to delete a song\n");
        printf("(p) to play a song\n");
        printf("(l) to list your songs\n");
        printf("To quit, enter any other key\n");
        printf(">>> "); scanf("%s", operation);
        while (!strcasecmp(operation, "a") || !strcasecmp(operation, "d") || !strcasecmp(operation, "p") || !strcasecmp(operation, "l"))
        {
            switch (tolower(operation[0]))
            {
                case 'a':

                    printf("(b) add at the beginning of the list\n");
                    printf("(m) add at the middle of the list\n");
                    printf("(e) add at the end of the list\n");
                    printf(">>> "); scanf("%s", where);
                    switch (tolower(where[0]))
                    {
                        case 'b':
                            printf("Song: ");
                            scanf(" %[^\n]s", addSong);
                            
                            printf("Artist: ");
                            scanf(" %[^\n]s", addArtist);
                            
                            printf("Album: ");
                            scanf(" %[^\n]s", addAlbum);
                            
                            printf("Duration in seconds: ");
                            scanf("%d", &addDuration);
                            
                            printf("Release Year: ");
                            scanf("%d", &addYear);
                    
                            insertAtTheBeginningDL(DL, addSong, addArtist, addAlbum, addDuration, addYear);
                            break;
                        case 'm':
                            printf("Song: ");
                            scanf(" %[^\n]s", addSong);
                            
                            printf("Artist: ");
                            scanf(" %[^\n]s", addArtist);
                            
                            printf("Album: ");
                            scanf(" %[^\n]s", addAlbum);
                            
                            printf("Duration in seconds: ");
                            scanf("%d", &addDuration);
                            
                            printf("Release Year: ");
                            scanf("%d", &addYear);
                    
                            printf("Add after this song: ");
                            scanf(" %[^\n]s", insertAfter);
                            insertAfterANodeDL(DL, insertAfter, addSong, addArtist, addAlbum, addDuration, addYear);
                            break;
                        case 'e':
                            printf("Song: ");
                            scanf(" %[^\n]s", addSong);
                            
                            printf("Artist: ");
                            scanf(" %[^\n]s", addArtist);
                            
                            printf("Album: ");
                            scanf(" %[^\n]s", addAlbum);
                            
                            printf("Duration in seconds: ");
                            scanf("%d", &addDuration);
                            
                            printf("Release Year: ");
                            scanf("%d", &addYear);
                            
                            insertAtTheEndDL(DL, addSong, addArtist, addAlbum, addDuration, addYear);
                            break;
                        default:
                            printf("Invalid command!\n");
                            break;
                    }
                    break;
                case 'd':
                    printf("(f) delete the first song\n");
                    printf("(s) delete a specific song\n");
                    printf("(l) delete the last song\n");
                    printf(">>> "); scanf("%s", where);
                    switch (tolower(where[0]))
                    {
                        case 'f':
                            removeFirstNodeDL(DL);
                            break;
                        case 's':
                            printf("Which song should be deleted: ");
                            scanf(" %[^\n]s", songToDelete);
                            removeFromMiddleDL(DL, songToDelete);
                            break;
                        case 'l':
                            removeLastNodeDL(DL);
                            break;
                        default:
                            printf("Invalid command!\n");
                            break;
                    }
                    break;
                case 'p':
                    printf("Which song would you like to play: ");
                    scanf(" %[^\n]s", songToPlay);
                    printNodeDL(DL, songToPlay);
                    break;
                case 'l':
                    printListDL(DL);
                    break;
                default:
                    break;
            }
            printf("(a) to add a new song\n");
            printf("(d) to delete a song\n");
            printf("(p) to play a song\n");
            printf("(l) to list your songs\n");
            printf("To quit, enter any other key\n");
            printf(">>> "); scanf("%s", operation);
        }
        printf("Byeee!\n");
        free(DL);
        return 0;
    }


    if (!strcasecmp(listType, "CDL"))
    {
        list* CDL = createNewListCDL(song, artist, album, duration, year);
        printf("(a) to add a new song\n");
        printf("(d) to delete a song\n");
        printf("(p) to play a song\n");
        printf("(l) to list your songs\n");
        printf("To quit, enter any other key\n");
        printf(">>> "); scanf("%s", operation);
        while (!strcasecmp(operation, "a") || !strcasecmp(operation, "d") || !strcasecmp(operation, "p") || !strcasecmp(operation, "l"))
        {
            switch (tolower(operation[0]))
            {
                case 'a':

                    printf("(b) add at the beginning of the list\n");
                    printf("(m) add at the middle of the list\n");
                    printf("(e) add at the end of the list\n");
                    printf(">>> "); scanf("%s", where);
                    switch (tolower(where[0]))
                    {
                        case 'b':
                            printf("Song: ");
                            scanf(" %[^\n]s", addSong);
                            
                            printf("Artist: ");
                            scanf(" %[^\n]s", addArtist);
                            
                            printf("Album: ");
                            scanf(" %[^\n]s", addAlbum);
                            
                            printf("Duration in seconds: ");
                            scanf("%d", &addDuration);
                            
                            printf("Release Year: ");
                            scanf("%d", &addYear);
                    
                            insertAtTheBeginningCDL(CDL, addSong, addArtist, addAlbum, addDuration, addYear);
                            break;
                        case 'm':
                            printf("Song: ");
                            scanf(" %[^\n]s", addSong);
                            
                            printf("Artist: ");
                            scanf(" %[^\n]s", addArtist);
                            
                            printf("Album: ");
                            scanf(" %[^\n]s", addAlbum);
                            
                            printf("Duration in seconds: ");
                            scanf("%d", &addDuration);
                            
                            printf("Release Year: ");
                            scanf("%d", &addYear);
                    
                            printf("Add after this song: ");
                            scanf(" %[^\n]s", insertAfter);
                            insertAfterANodeCDL(CDL, insertAfter, addSong, addArtist, addAlbum, addDuration, addYear);
                            break;
                        case 'e':
                            printf("Song: ");
                            scanf(" %[^\n]s", addSong);
                            
                            printf("Artist: ");
                            scanf(" %[^\n]s", addArtist);
                            
                            printf("Album: ");
                            scanf(" %[^\n]s", addAlbum);
                            
                            printf("Duration in seconds: ");
                            scanf("%d", &addDuration);
                            
                            printf("Release Year: ");
                            scanf("%d", &addYear);
                            
                            insertAtTheEndCDL(CDL, addSong, addArtist, addAlbum, addDuration, addYear);
                            break;
                        default:
                            printf("Invalid command!\n");
                            break;
                    }
                    break;
                case 'd':
                    printf("(f) delete the first song\n");
                    printf("(s) delete a specific song\n");
                    printf("(l) delete the last song\n");
                    printf(">>> "); scanf("%s", where);
                    switch (tolower(where[0]))
                    {
                        case 'f':
                            removeFirstNodeCDL(CDL);
                            break;
                        case 's':
                            printf("Which song should be deleted: ");
                            scanf(" %[^\n]s", songToDelete);
                            removeFromMiddleCDL(CDL, songToDelete);
                            break;
                        case 'l':
                            removeLastNodeCDL(CDL);
                            break;
                        default:
                            printf("Invalid command!\n");
                            break;
                    }
                    break;
                case 'p':
                    printf("Which song would you like to play: ");
                    scanf(" %[^\n]s", songToPlay);
                    printNodeCDL(CDL, songToPlay);
                    break;
                case 'l':
                    printListCDL(CDL);
                    break;
                default:
                    break;
            }
            printf("(a) to add a new song\n");
            printf("(d) to delete a song\n");
            printf("(p) to play a song\n");
            printf("(l) to list your songs\n");
            printf("To quit, enter any other key\n");
            printf(">>> "); scanf("%s", operation);
        }
        printf("Byeee!\n");
        free(CDL);
        return 0;
    }
    return -1;
}