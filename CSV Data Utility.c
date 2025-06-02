#include<stdio.h>
#include<string.h>

// Declare Global Variable
int count = 0;
int rep = 0;
int searchCounter = 0;

// Declare Struct to Store Data
struct datas {
	char location[201];
	char city[201];
	int price;
	int rooms;
	int bathrooms;
	int carpark;
	char type[201];
	char furnish[201];
} cases[3950];

// Function to Print Header
void header() {
	for (rep = 0; rep < 5; rep++) {
		printf("\n");
	}
	printf("%64s\n", "HOUSES REPORT");
	printf("====================================================================================================================\n\n");
}

// Function to Print Menu
void menu() {
	printf("MENU\n");
	printf("====================\n");
	printf("What do you want to do?\n");
	printf("1. Display Data\n");
	printf("2. Search Data\n");
	printf("3. Sort Data\n");
	printf("4. Export Data\n");
	printf("5. Exit\n");
}

// Function to Read File
void readFile() {
	// Variables Declaration
	FILE *finp = fopen("case2file.csv", "r");
	char titles[401];
	
	// Scan the Titles
	fscanf(finp, "%[^\n]\n", &titles);
	
	// Scan Datas
	while (!feof(finp)) {
		fscanf(finp, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", &cases[count].location, &cases[count].city, &cases[count].price, &cases[count].rooms, &cases[count].bathrooms, &cases[count].carpark, &cases[count].type, &cases[count].furnish);
		count++;
	}
	// Close File
	fclose(finp);
	
	// Test Print
	// printf("%s %s %d %d %d %d %s %s\n", cases[0].location, cases[0].city, cases[0].price, cases[0].rooms, cases[0].bathrooms, cases[0].carpark, cases[0].type, cases[0].furnish);
}

// Menu 1 : Function to Display Data
// Function to Display Datas
void display(int row) {
	if (row > count) {
		row = count;
	}
	
	// Display Title
	printf("%-25s", "Location");
	printf("%-25s", "City");
	printf("%-10s", "Price");
	printf("%-8s", "Rooms");
	printf("%-12s", "Bathrooms");
	printf("%-10s", "Carpark");
	printf("%-14s", "Type");
	printf("%s\n", "Furnish");
	printf("--------------------------------------------------------------------------------------------------------------------");
	printf("\n");
	
	// Display Datas
	for (rep = 0; rep < row; rep++) {		
		printf("%-25s", cases[rep].location);
		printf("%-25s", cases[rep].city);
		printf("%-10d", cases[rep].price);
		printf("%-8d", cases[rep].rooms);
		printf("%-12d", cases[rep].bathrooms);
		printf("%-10d", cases[rep].carpark);
		printf("%-14s", cases[rep].type);
		printf("%s", cases[rep].furnish);
		printf("\n");
	}
	getchar();
}

// Menu 1 Function
void menu1() {
	// Variables Declaration
	int rows;
	
	// Scan Rows to be Displayed, Validate Rows as Positive Integer
	do {
		printf("Number of rows to be printed (1-%d) : ", count); 
		scanf("%d", &rows); getchar();	
	} while (rows < 1);
	printf("\n");
				
	// Call the Display Function
	display(rows);
}

// Menu 2 : Function to Search Data

// Function to Display Specific Data
void disp(int n) {
	printf("%-25s", cases[n].location);
	printf("%-25s", cases[n].city);
	printf("%-10d", cases[n].price);
	printf("%-8d", cases[n].rooms);
	printf("%-12d", cases[n].bathrooms);
	printf("%-10d", cases[n].carpark);
	printf("%-14s", cases[n].type);
	printf("%s", cases[n].furnish);
	printf("\n");
}

// Function to Search String
void searchS(char *column, char *searchStr) {
	// Count the Found Data
	// Search based on Column Location
	if (strcmp(column, "Location") == 0) {
		for (rep = 0; rep < count; rep++) {
			if (strcmp(cases[rep].location, searchStr) == 0) {
				searchCounter++;
			}
		}
	}
	
	// Search based on Column City
	else if (strcmp(column, "City") == 0) {
		for (rep = 0; rep < count; rep++) {
			if (strcmp(cases[rep].city, searchStr) == 0) {
				searchCounter++;
			}
		}
	}
	
	// Search based on Column Type
	else if (strcmp(column, "Type") == 0) {
		for (rep = 0; rep < count; rep++) {
			if (strcmp(cases[rep].type, searchStr) == 0) {
				searchCounter++;
			}
		}
	}
	
	// Search based on Column Furnish
	else if (strcmp(column, "Furnish") == 0) {
		for (rep = 0; rep < count; rep++) {
			if (strcmp(cases[rep].furnish, searchStr) == 0) {
				searchCounter++;
			}
		}
	}
	
	// Print the Results
	// Data not Found
	if (searchCounter == 0) {
		printf("Data not found!\n");
		getchar();
	}
	
	// Data Found
	else {
		printf("Data found!\nDetails of data :\n");
		printf("\n");
		printf("%-25s", "Location");
		printf("%-25s", "City");
		printf("%-10s", "Price");
		printf("%-8s", "Rooms");
		printf("%-12s", "Bathrooms");
		printf("%-10s", "Carpark");
		printf("%-14s", "Type");
		printf("%s\n", "Furnish");
		printf("--------------------------------------------------------------------------------------------------------------------");
		printf("\n");
		
		if (strcmp(column, "Location") == 0) {
			for (rep = 0; rep < count; rep++) {
				if (strcmp(cases[rep].location, searchStr) == 0) {
					// Call the Display Searched Data Function
					disp(rep);
				}
			}
		}
		else if (strcmp(column, "City") == 0) {
			for (rep = 0; rep < count; rep++) {
				if (strcmp(cases[rep].city, searchStr) == 0) {
					// Call the Display Searched Data Function
					disp(rep);
				}
			}
		}
		else if (strcmp(column, "Type") == 0) {
			for (rep = 0; rep < count; rep++) {
				if (strcmp(cases[rep].type, searchStr) == 0) {
					// Call the Display Searched Data Function
					disp(rep);
				}
			}
		}
		else if (strcmp(column, "Furnish") == 0) {
			for (rep = 0; rep < count; rep++) {
				if (strcmp(cases[rep].furnish, searchStr) == 0) {
					// Call the Display Searched Data Function
					disp(rep);
				}
			}
		}
		getchar();
	}
}

// Function to Search Integer
void searchI(char *column, int searchInt) {	
	// Count the Found Data
	// Search based on Column Price
	if (strcmp(column, "Price") == 0) {
		for (rep = 0; rep < count; rep++) {
			if (cases[rep].price == searchInt) {
				searchCounter++;
			}
		}
	}
	
	// Search based on Column Rooms
	else if (strcmp(column, "Rooms") == 0) {
		for (rep = 0; rep < count; rep++) {
			if (cases[rep].rooms == searchInt) {
				searchCounter++;
			}
		}
	}
	
	// Search based on Column Bathrooms
	else if (strcmp(column, "Bathrooms") == 0) {
		for (rep = 0; rep < count; rep++) {
			if (cases[rep].bathrooms == searchInt) {
				searchCounter++;
			}
		}
	}
	
	// Search based on Column Carpark
	else if (strcmp(column, "Carpark") == 0) {
		for (rep = 0; rep < count; rep++) {
			if (cases[rep].carpark == searchInt) {
				searchCounter++;
			}
		}
	}
	
	// Print the Results
	// Data not Found
	if (searchCounter == 0) {
		printf("Data not found!\n");
		getchar();
	}
	
	// Data Found
	else {
		printf("Data found!\nDetails of data :\n");
		printf("\n");
		printf("%-25s", "Location");
		printf("%-25s", "City");
		printf("%-10s", "Price");
		printf("%-8s", "Rooms");
		printf("%-12s", "Bathrooms");
		printf("%-10s", "Carpark");
		printf("%-14s", "Type");
		printf("%s\n", "Furnish");
		printf("--------------------------------------------------------------------------------------------------------------------");
		printf("\n");
		
		if (strcmp(column, "Price") == 0) {
			for (rep = 0; rep < count; rep++) {
				if (cases[rep].price == searchInt) {
					// Call the Display Searched Data Function
					disp(rep);
				}
			}
		}
		else if (strcmp(column, "Rooms") == 0) {
			for (rep = 0; rep < count; rep++) {
				if (cases[rep].rooms == searchInt) {
					// Call the Display Searched Data Function
					disp(rep);
				}
			}
		}
		else if (strcmp(column, "Bathrooms") == 0) {
			for (rep = 0; rep < count; rep++) {
				if (cases[rep].bathrooms == searchInt) {
					// Call the Display Searched Data Function
					disp(rep);
				}
			}
		}
		else if (strcmp(column, "Carpark") == 0) {
			for (rep = 0; rep < count; rep++) {
				if (cases[rep].carpark == searchInt) {
					// Call the Display Searched Data Function
					disp(rep);
				}
			}
		}
		getchar();
	}
}

void menu2() {
	// Variables Declaration
	char col[100];
	char searchStr[201];
	int searchInt;
	
	// Scan Column to be Searched, Validate Column Name
	do {
		printf("Choose Column (Location / City / Price / Rooms / Bathrooms / Carpark / Type / Furnish) : "); 
		scanf("%s", &col); getchar();
	} while (strcmp(col, "Location") != 0 && strcmp(col, "City") != 0 && strcmp(col, "Type") != 0 && strcmp(col, "Furnish") != 0 && strcmp(col, "Price") != 0 && strcmp(col, "Rooms") != 0 && strcmp(col, "Bathrooms") != 0 && strcmp(col, "Carpark") != 0);
				
	// If Column contains String Type of Data
	if (strcmp(col, "Location") == 0 || strcmp(col, "City") == 0 || strcmp(col, "Type") == 0 || strcmp(col, "Furnish") == 0) {
		printf("What data do you want to find? "); scanf("%[^\n]s", &searchStr); getchar();	
		// Call the Search String Function
		searchS(col, searchStr);
	}
				
	// If Column contains Integer Type of Data
	else if (strcmp(col, "Price") == 0 || strcmp(col, "Rooms") == 0 || strcmp(col, "Bathrooms") == 0 || strcmp(col, "Carpark") == 0) {
		printf("What data do you want to find? "); scanf("%d", &searchInt); getchar();
		// Call the Search Integer Function
		searchI(col, searchInt);
	}
				
	searchCounter = 0;
}

// Menu 3 : Function to Sort Data

// Function to Display
void displaysort() {
	// Display Title
	printf("%-25s", "Location");
	printf("%-25s", "City");
	printf("%-10s", "Price");
	printf("%-8s", "Rooms");
	printf("%-12s", "Bathrooms");
	printf("%-10s", "Carpark");
	printf("%-14s", "Type");
	printf("%s\n", "Furnish");
	printf("--------------------------------------------------------------------------------------------------------------------");
	printf("\n");
	
	// Display Datas
	for (rep = 0; rep < 10; rep++) {		
		printf("%-25s", cases[rep].location);
		printf("%-25s", cases[rep].city);
		printf("%-10d", cases[rep].price);
		printf("%-8d", cases[rep].rooms);
		printf("%-12d", cases[rep].bathrooms);
		printf("%-10d", cases[rep].carpark);
		printf("%-14s", cases[rep].type);
		printf("%s", cases[rep].furnish);
		printf("\n");
	}
	getchar();
}

// Function to Swap Values
void swap(int i, int j) {
	struct datas temp = cases[i];
	cases[i] = cases[j];
	cases[j] = temp;
}

// Location : Ascending
int partitionLA(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (strcmp(cases[j].location, cases[high].location) < 0) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortLA(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionLA(low, high);
		
		// Recursive
		quickSortLA(low, pivot-1);
		quickSortLA(pivot+1, high);
	}
}

// Location : Descending
int partitionLD(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (strcmp(cases[j].location, cases[high].location) > 0) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortLD(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionLD(low, high);
		
		// Recursive
		quickSortLD(low, pivot-1);
		quickSortLD(pivot+1, high);
	}
}

// City : Ascending
int partitionCA(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (strcmp(cases[j].city, cases[high].city) < 0) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortCA(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionCA(low, high);

		// Recursive
		quickSortCA(low, pivot-1);
		quickSortCA(pivot+1, high);
	}
}

// City : Descending
int partitionCD(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (strcmp(cases[j].city, cases[high].city) > 0) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortCD(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionCD(low, high);

		// Recursive
		quickSortCD(low, pivot-1);
		quickSortCD(pivot+1, high);
	}
}

// Type : Ascending
int partitionTA(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (strcmp(cases[j].type, cases[high].type) < 0) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortTA(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionTA(low, high);

		// Recursive
		quickSortTA(low, pivot-1);
		quickSortTA(pivot+1, high);
	}
}

// Type : Descending
int partitionTD(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (strcmp(cases[j].type, cases[high].type) > 0) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortTD(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionTD(low, high);

		// Recursive
		quickSortTD(low, pivot-1);
		quickSortTD(pivot+1, high);
	}
}

// Furnish : Ascending
int partitionFA(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (strcmp(cases[j].furnish, cases[high].furnish) < 0) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortFA(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionFA(low, high);

		// Recursive
		quickSortFA(low, pivot-1);
		quickSortFA(pivot+1, high);
	}
}

// Furnish : Descending
int partitionFD(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (strcmp(cases[j].furnish, cases[high].furnish) > 0) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortFD(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionFD(low, high);

		// Recursive
		quickSortFD(low, pivot-1);
		quickSortFD(pivot+1, high);
	}
}

// Price : Ascending
int partitionPrA(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (cases[j].price < cases[high].price) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortPrA(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionPrA(low, high);

		// Recursive
		quickSortPrA(low, pivot-1);
		quickSortPrA(pivot+1, high);
	}
}

// Price : Descending
int partitionPrD(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (cases[j].price > cases[high].price) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortPrD(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionPrD(low, high);

		// Recursive
		quickSortPrD(low, pivot-1);
		quickSortPrD(pivot+1, high);
	}
}

// Rooms : Ascending
int partitionRA(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (cases[j].rooms < cases[high].rooms) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortRA(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionRA(low, high);

		// Recursive
		quickSortRA(low, pivot-1);
		quickSortRA(pivot+1, high);
	}
}

// Rooms : Descending
int partitionRD(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (cases[j].rooms > cases[high].rooms) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortRD(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionRD(low, high);

		// Recursive
		quickSortRD(low, pivot-1);
		quickSortRD(pivot+1, high);
	}
}

// Bathrooms : Ascending
int partitionBathA(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (cases[j].bathrooms < cases[high].bathrooms) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortBathA(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionBathA(low, high);

		// Recursive
		quickSortBathA(low, pivot-1);
		quickSortBathA(pivot+1, high);
	}
}

// Bathrooms : Descending
int partitionBathD(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (cases[j].bathrooms > cases[high].bathrooms) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortBathD(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionBathD(low, high);
		
		// Recursive
		quickSortBathD(low, pivot-1);
		quickSortBathD(pivot+1, high);
	}
}

// Carpark : Ascending
int partitionCPA(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (cases[j].carpark < cases[high].carpark) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortCPA(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionCPA(low, high);

		// Recursive
		quickSortCPA(low, pivot-1);
		quickSortCPA(pivot+1, high);
	}
}

// Carpark : Descending
int partitionCPD(int low, int high) {
	int i = low - 1;
	int j;
	for (j = low; j <= high; j++) {
		if (cases[j].carpark > cases[high].carpark) {
			i++;
			// Call the Swap Function
			swap(i, j);
		}
	}
	i++;
	// Call the Swap Function
	swap(i, high);
	return i;
}

void quickSortCPD(int low, int high) {
	if (low < high) {
		// Store Value Returned from Partition Function
		int pivot = partitionCPD(low, high);

		// Recursive
		quickSortCPD(low, pivot-1);
		quickSortCPD(pivot+1, high);
	}
}

// Function to Sort String Ascending
void sortSASC(char *column) {	
	// Sorting based on Column Location
	if (strcmp(column, "Location") == 0) {
		// Call the Quick Sort Location Ascending Function
		quickSortLA(0, count-1);
	}
	
	// Sorting based on Column City
	else if (strcmp(column, "City") == 0) {
		// Call the Quick Sort City Ascending Function
		quickSortCA(0, count-1);
	}
	
	// Sorting based on Column Type
	else if (strcmp(column, "Type") == 0) {
		// Call the Quick Sort Type Ascending Function
		quickSortTA(0, count-1);
	}
	
	// Sorting based on Column Furnish
	else if (strcmp(column, "Furnish") == 0) {
		// Call the Quick Sort Furnish Ascending Function
		quickSortFA(0, count-1);		
	}
}

// Function to Sort String Descending
void sortSDESC(char *column) {
	// Sorting based on Column Location
	if (strcmp(column, "Location") == 0) {
		// Call the Quick Sort Location Descending Function
		quickSortLD(0, count-1);
	}
	
	// Sorting based on Column City
	else if (strcmp(column, "City") == 0) {
		// Call the Quick Sort City Descending Function
		quickSortCD(0, count-1);	
	}
	
	// Sorting based on Column Type
	else if (strcmp(column, "Type") == 0) {
		// Call the Quick Sort Type Descending Function
		quickSortTD(0, count-1);
	}
	
	// Sorting based on Column Furnish
	else if (strcmp(column, "Furnish") == 0) {
		// Call the Quick Sort Furnish Descending Function
		quickSortFD(0, count-1)	;
	}
}

// Function to Sort Integer Ascending
void sortIASC(char *column) {
	// Sorting based on Column Price
	if (strcmp(column, "Price") == 0) {
		// Call the Quick Sort Price Ascending Function
		quickSortPrA(0, count-1);
	}
	
	// Sorting based on Column Rooms
	else if (strcmp(column, "Rooms") == 0) {
		// Call the Quick Sort Rooms Ascending Function
		quickSortRA(0, count-1);
	}
	
	// Sorting based on Column Bathrooms
	else if (strcmp(column, "Bathrooms") == 0) {
		// Call the Quick Sort Bathrooms Ascending Function
		quickSortBathA(0, count-1);	
	}
	
	// Sorting based on Column Carpark
	else if (strcmp(column, "Carpark") == 0) {
		// Call the Quick Sort Carpark Ascending Function
		quickSortCPA(0, count-1);		
	}
}

// Function to Sort Integer Descending
void sortIDESC(char *column) {
	// Sorting based on Column Price
	if (strcmp(column, "Price") == 0) {
		// Call the Quick Sort Price Descending Function
		quickSortPrD(0, count-1);
	}
	// Sorting based on Column Rooms
	else if (strcmp(column, "Rooms") == 0) {
		// Call the Quick Sort Rooms Descending Function
		quickSortRD(0, count-1);
	}
	// Sorting based on Column Bathrooms
	else if (strcmp(column, "Bathrooms") == 0) {
		// Call the Quick Sort Bathrooms Descending Function
		quickSortBathD(0, count-1);		
	}
	// Sorting based on Column Carpark
	else if (strcmp(column, "Carpark") == 0) {
		// Call the Quick Sort Carpark Descending Function
		quickSortCPD(0, count-1);
	}
}

void menu3() {
	// Variables Declaration
	char col[100];
	char sorttype[100];
	
	// Scan Column to be Sorted, Validate Column Name
	do {
		printf("Choose Column (Location / City / Price / Rooms / Bathrooms / Carpark / Type / Furnish) : "); 
		scanf("%s", &col); getchar();
	} while (strcmp(col, "Location") != 0 && strcmp(col, "City") != 0 && strcmp(col, "Type") != 0 && strcmp(col, "Furnish") != 0 && strcmp(col, "Price") != 0 && strcmp(col, "Rooms") != 0 && strcmp(col, "Bathrooms") != 0 && strcmp(col, "Carpark") != 0);
		
	// Scan Sorting Type, Validate whether Ascending or Descending
	do {
		printf("Sort Type (ASC / DESC) : ");
		scanf("%[^\n]s", &sorttype); getchar();
	} while (strcmp(sorttype, "ASC") != 0 && strcmp(sorttype, "DESC") != 0);
				
	// If Column contains String Type of Data
	if (strcmp(col, "Location") == 0 || strcmp(col, "City") == 0 || strcmp(col, "Type") == 0 || strcmp(col, "Furnish") == 0) {	
		// If Sorting Type is Ascending
		if (strcmp(sorttype, "ASC") == 0) {
			// Call the Sort String Ascending Function
			sortSASC(col);
		} 
		
		// If Sorting Type is Descending
		else if (strcmp(sorttype, "DESC") == 0) {
			// Call the Sort String Descending Function
			sortSDESC(col);
		}
	}
				
				// If Column contains Integer Type of Data
	else if (strcmp(col, "Price") == 0 || strcmp(col, "Rooms") == 0 || strcmp(col, "Bathrooms") == 0 || strcmp(col, "Carpark") == 0) {
		// If Sorting Type is Ascending
		if (strcmp(sorttype, "ASC") == 0) {
			// Call the Sort Integer Ascending Function
			sortIASC(col);
		}
					
		// If Sorting Type is Descending
		else if (strcmp(sorttype, "DESC") == 0) {
			// Call the Sort Integer Descending Function
			sortIDESC(col);
		}
	}
				
	printf("Data Successfully Sorted.\nSorted Data : \n\n");
	
	// Call the Display 10 First Sorted Datas
	displaysort();
}

// Menu 4 : Function to Export Data
void menu4() {
	// Variables Declaration
	char exportedfilename[100];
	
	// Scan File Name to be Exported
	printf("File name : ");
	scanf("%[^\n]s", &exportedfilename); getchar();
				
	// Add .csv Extension to the File Name
	strcat(exportedfilename, ".csv");
			
	// Open the File
	FILE *exp = fopen(exportedfilename, "w");
				
	fprintf(exp, "%s,%s,%s,%s,%s,%s,%s,%s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish");
	// Print the Datas into the File
	for (rep = 0; rep < count; rep++) {
		fprintf(exp, "%s,%s,%d,%d,%d,%d,%s,%s\n", cases[rep].location, cases[rep].city, cases[rep].price, cases[rep].rooms, cases[rep].bathrooms, cases[rep].carpark, cases[rep].type, cases[rep].furnish);
	}
				
	// Close the File
	fclose(exp);
	printf("Data successfully written to file %s!\n", exportedfilename); getchar();
}

// Function Main
int main () {
	// Declare Variable
	int choice = 0;

	// Call the Read File Function
	readFile();

	// Program
	do {
		// Print Header
		header();

		// Print Menu
		menu();

		// Scan Choice, Validate Choice between 1-5
		do {
			printf("Choice : "); 
			scanf("%d", &choice); getchar();
		} while (choice < 1 || choice > 5);
		
		// Create Switch Case
		switch(choice) {
			// Menu 1 : Display
			case 1 : {
				menu1();
				break;
			}
			// Menu 2 : Search
			case 2 : {
				menu2();
				break;
			}
			// Menu 3 : Sort
			case 3 : {
				menu3();
				break;
			}
			// Menu 4 : Export
			case 4 : {
				menu4();
				break;
			}
			// Menu 5 : Exit
			case 5 : {
				printf("Thankyou for using this program!\n"); getchar();
				break;
			}
		}
		
		
	} while (choice != 5);
	
	return 0;
}
