// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store
// course details
struct Course {
	char cname[30];
	char sdate[30];
};

// Driver code
int main()
{
	FILE* of;
	of = fopen("test.txt", "w");
	if (of == NULL) {
		fprintf(stderr,
				"\nError to open the file\n");
		exit(1);
	}

	struct Course inp1 = { "Algorithms",
						"30OCT" };
	struct Course inp2 = { "DataStructures",
						"28SEPT" };
	struct Course inp3 = { "Programming",
						"1NOV" };
	fwrite(&inp1, sizeof(struct Course),
		1, of);
	fwrite(&inp2, sizeof(struct Course),
		1, of);
	fwrite(&inp3, sizeof(struct Course),
		1, of);
	if (fwrite != 0)
		printf("Contents to file written successfully !\n");
	else
		printf("Error writing file !\n");
	fclose(of);

	// File pointer to read from file
	FILE* inf;
	struct Course inp;
	inf = fopen("test.txt", "r");

	if (inf == NULL) {
		fprintf(stderr,
				"\nError to open the file\n");
		exit(1);
	}

	while (fread(&inp, sizeof(struct Course),
				1, inf))
		printf("Course Name = %s Started = %s\n",
			inp.cname, inp.sdate);
	fclose(inf);
}
