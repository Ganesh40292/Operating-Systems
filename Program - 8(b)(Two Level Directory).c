#include <stdio.h>
#include <string.h>

#define MAX_FILES 5
#define MAX_NAME_LENGTH 20

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int size;
} File;

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int numFiles;
    File files[MAX_FILES];
} Directory;

Directory directories[MAX_FILES];

void initializeDirectories()
{
    int i;
    for (i = 0; i < MAX_FILES; i++)
    {
        sprintf(directories[i].name, "Directory%d", i + 1);
        directories[i].numFiles = 0;
    }
}

void addFile(char name[], int size, int dirIndex)
{
    if (dirIndex >= 0 && dirIndex < MAX_FILES)
    {
        if (directories[dirIndex].numFiles < MAX_FILES)
        {
            strcpy(directories[dirIndex].files[directories[dirIndex].numFiles].name, name);
            directories[dirIndex].files[directories[dirIndex].numFiles].size = size;
            directories[dirIndex].numFiles++;
        }
        else
        {
            printf("Directory is full\n");
        }
    }
}

void displayDirectories()
{
    int i, j;
    printf("\nTwo Level Directory");
    for (i = 0; i < MAX_FILES; i++)
    {
        printf("\n\nDirectory Name: %s", directories[i].name);
        for (j = 0; j < directories[i].numFiles; j++)
        {
            printf("\n%s\t%d KB", directories[i].files[j].name, directories[i].files[j].size);
        }
    }
}

int main()
{
    initializeDirectories();
    addFile("file1.txt", 1024, 0);
    addFile("file2.txt", 2048, 1);
    addFile("file3.txt", 3072, 2);
    displayDirectories();
    return 0;
}

