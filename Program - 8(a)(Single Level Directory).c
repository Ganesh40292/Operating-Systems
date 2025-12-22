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

Directory singleLevelDirectory;

void initializeDirectory()
{
    strcpy(singleLevelDirectory.name, "Root");
    singleLevelDirectory.numFiles = 0;
}

void addFile(char name[], int size)
{
    if (singleLevelDirectory.numFiles < MAX_FILES)
    {
        strcpy(singleLevelDirectory.files[singleLevelDirectory.numFiles].name, name);
        singleLevelDirectory.files[singleLevelDirectory.numFiles].size = size;
        singleLevelDirectory.numFiles++;
    }
    else
    {
        printf("Directory is full\n");
    }
}

void displayDirectory()
{
    int i;
    printf("\nSingle Level Directory");
    printf("\nDirectory Name: %s", singleLevelDirectory.name);
    printf("\nFiles:");
    for (i = 0; i < singleLevelDirectory.numFiles; i++)
    {
        printf("\n%s\t%d KB", singleLevelDirectory.files[i].name, singleLevelDirectory.files[i].size);
    }
}

int main()
{
    initializeDirectory();
    addFile("file1.txt", 1024);
    addFile("file2.txt", 2048);
    addFile("file3.txt", 3072);
    displayDirectory();
    return 0;
}

