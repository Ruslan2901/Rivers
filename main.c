#include "Func.h"

int main(int argc, char* argv[]) {
	node_river* node;
	node = NULL;
	char riverName[20];
	char riverRegion[30];
	int riverDepth;
	float length;
	int total_length = 0;
	bool CorrectInput;

	for (int i = 1; i < 13; i++) {
		CorrectInput = false;
		while (!CorrectInput)
		{
			printf("Enter the name of the river: ");
			fgets(riverName, 20, stdin);
			// Input validation
			if (riverName[0] == '\n' || riverName[0] == '\0')
				CorrectInput = false;
			else
				CorrectInput = true;
			if (riverName[strlen(riverName) - 1] == '\n')
				riverName[strlen(riverName) - 1] = '\0';
			else getchar();

			if (!CorrectInput)
			{
				printf("Error\n\n");
			}
		}
		CorrectInput = false;
		while (!CorrectInput)
		{
			printf("Region of location: ");
			fgets(riverRegion, 30, stdin);

			// Input validation
			if (riverRegion[0] == '\n' || riverRegion[0] == '\0')
				CorrectInput = false;
			else
				CorrectInput = true;

			if (riverRegion[strlen(riverRegion) - 1] == '\n')
				riverRegion[strlen(riverRegion) - 1] = '\0';
			else
				getchar();
			if (!CorrectInput)
			{
				printf("Error\n\n");
			}
		}
		CorrectInput = false;
		while (!CorrectInput)
		{
			printf("Depth (m): ");
			// Input validation
			if (scanf("%d", &riverDepth) == 1 && riverDepth > 0)
				CorrectInput = true;
			if (!CorrectInput)
			{
				printf("Error\n\n");
			}
			clear_stdin();
		}
		CorrectInput = false;
		while (!CorrectInput)
		{
			printf("Length: ");
			// Input validation
			if (scanf("%f", &length) == 1 && length >= 0)
				CorrectInput = true;
			if (!CorrectInput)
			{
				printf("Error\n\n");
			}
			clear_stdin();
		}
		if (riverDepth <= 50) {
			total_length += Add_to_list(&node, riverName, riverRegion, riverDepth, length);
		}
		// Add an entry to the list
		printf("\nRecord # %d added successfully \nPress any key to move to next record", i);
		getchar();
	}
	// Filling a text file with the entered information about lakes
	char file[50] = { 0 };
	printf("\n");
	CorrectInput = false;
	while (!CorrectInput)
	{
		printf("Enter the name of the file where you want to save the entered information: ");
		fgets(file, 50, stdin);

		// Input validation
		if (file[0] == '\n' || file[0] == '\0')
			CorrectInput = false;
		else
			CorrectInput = true;

		if (file[strlen(file) - 1] == '\n')
			file[strlen(file) - 1] = '\0';
		else getchar();
	}

	if (Write_data_to_file(&node, file))
		printf("List saved to file %s\n", file);
	else
		printf("An error occurred while saving\n");
	printf("Total lenght: %d km\n", total_length);
	printf("Press any key to continue\n");
	getchar();

	return 0;
}