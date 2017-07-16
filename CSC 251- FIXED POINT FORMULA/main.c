/* PROGRAM TO FIND THE REAL ROOT OF AN EQUATION USING FIXED POINT FORMULAE */
/* CSC 251 -> NUMERICAL ANALYSIS */
/* GROUP  */
/* MATRIC NUMBER -> 20141622, 20141657, 20141604, 20141575, 20141579, 20141576, 20141571*/

#define _CRT_SECURE_NO_WARNINGS
#define NEWLINE printf("\n");
#define print(f_,...) sprintf( textToPrint, (f_), __VA_ARGS__); cout;
#define cout printAnimate(textToPrint);

// THIS PROGRAM WAS CREATED IN MICROSOFT VISUAL STUDIO (v14.0)2015
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <tchar.h>

HANDLE wHnd;	// Handle to write to console
HANDLE rHnd;	// Handle to read from console

static float X_REAL_ROOT;

#pragma region "FUNCTION TO FIND THE POWER OF A NUMBER"
//float pow(float x, int y)
//{
//	float i, xPow = 1;
//	for (i = 0; i < y; i++)
//	{
//		xPow *= x;
//	}
//	return xPow;
//}
#pragma endregion

#pragma region "FUNCTION TO RETURN THE SUFFIX OF NUMBER POSITION"
//FUNCTION TO RETURN THE SUFFIX OF NUMBER POSITION (e.g "st" for "1" as in "1st")
char *positionSuffix(int num)
{
	switch (num)
	{
	case 1:
		return "st";
		break;
	case 2:
		return "nd";
		break;
	case 3:
		return "rd";
		break;
	default:
		return "th";
	}
}
#pragma endregion

#pragma region "Function to Animate Console Output by Printing Char by Char"
void printAnimate(char *textToAnimate)
{
	int i = 0;
	int j = strlen(textToAnimate);
	for (i = 0; i < j; i++)
	{
		putchar(textToAnimate[i]);
		fflush(stdout);
		Sleep(20);
	}
}
#pragma endregion

#pragma region "Function to Generate Root Value from x0"
//FUNCTION TO RETURN ARRAY CONTAINING X(i) VALUES FOR EACH ITERATION AND EACH VALUE OF x0 (where i = 1,2,3...n)
float *generateRoots(int *xCoefficient, float xInitialValue, int  xMaximumPower)
{
	float *xArray = (float*)malloc(10 * sizeof(float));
	float xCurrentValue = xInitialValue;
	int *xCoef = xCoefficient;
	int xMax = xMaximumPower;
	float sum = 0;
	sum = (-1) * (float)xCoef[0];
	int j = 0, i;
	do
	{
		for (i = 2; i <= xMax; i++)
		{
			sum -= (pow(xCurrentValue, i) * xCoef[i]);
		}
		float xNew = roundf((sum / (xCoef[1])) * 10000) / 10000;
		xCurrentValue = xNew;
		xArray[j] = xNew;
		sum = (-1) * (float)xCoef[0];

		if (xArray[j] < (xInitialValue + 100) && (xInitialValue - 100) < xArray[j] && (xArray[j] == xArray[j - 1]))
		{
			X_REAL_ROOT = xArray[j];
		}
		j++;
	} while (j <= 10);
	return xArray;
}
#pragma endregion

#pragma region "Function to Convert YES or NO response to numbers"
int response(char *errResponse)
{
	char letter = toupper(errResponse[0]);
	switch (letter)
	{
	case 'Y':
		return 1;
		break;
	case 'N':
		return 0;
		break;
	default:
		return 2;
		break;
	}
}
#pragma endregion

#pragma region "Function to Set Console Features"
void setConsoleFeatures()
{
	/// #begin SET TITLE, WIDTH AND HEIGHT OF CONSOLE/TERMINAL WINDOW
	// Set up the handles for reading/writing
	SetConsoleTitle(_T("FIXED POINT FORMULA - CSC 251"));
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	// Change the console window size:
	// Create a COORD to hold the buffer size:
	// Set up the required window size:
	SMALL_RECT windowSize = { 0,0,150,768 };
	COORD bufferSize = { 150,768 };
	SetConsoleWindowInfo(wHnd, 1, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	// Set the console font color
	SetConsoleTextAttribute(wHnd, FOREGROUND_RED);
	/// #end
}
#pragma endregion

int main()
{
start:

	setConsoleFeatures();

	int xMaximumPower; //maximum power of x in the equation
	int i; // for for loops iteration
	int j; //inner for loops iteration
	char *textToPrint[150]; //to  hold parsed output to be printed char by char

	printf("______________________________________________________________________________________________________________________________________________________");
	printf("______________________________________________________________________________________________________________________________________________________");
	print("------------------------------------------------------------------------------------------------------------------------------------------------------");
	print("*\t\t\t\t|\tPROGRAM TO FIND ROOT OF EQUATION USING FIXED POINT FORMULAE\t|\t\t\t\t\t     *");
	print("*\t\t\t\t|\t\t CSC 251 ASSIGNMENT (NUMERICAL ANALYSIS) \t\t|\t\t\t\t\t     *");
	print("*\t\t\t\t|\t\t MATRIC NUMBER   :  NAMES     \t\t\t\t|\t\t\t\t\t     *");
	print("*\t\t\t\t|\t\t 1. 20141622     :  ODUKOYA SEYITAN VICTOR \t\t|\t\t\t\t\t     *");
	print("*\t\t\t\t|\t\t 2. 20141657     :  SOLOMON WILLIAMS \t\t\t|\t\t\t\t\t     *");
	print("*\t\t\t\t|\t\t 3. 20141604     :  IGWE OBINNA \t\t\t|\t\t\t\t\t     *");
	print("*\t\t\t\t|\t\t 4. 20141575     :  ADEYINKA DANIEL \t\t\t|\t\t\t\t\t     *");
	print("*\t\t\t\t|\t\t 5. 20141579     :  AKINTOLA OLALEKAN \t\t\t|\t\t\t\t\t     *");
	print("*\t\t\t\t|\t\t 6. 20141576     :  AJASA OLAMIDE \t\t\t|\t\t\t\t\t     *");
	print("*\t\t\t\t|\t\t 7. 20141571     :  ADENIRAN ADEYEMI \t\t\t|\t\t\t\t\t     *");
	print("*\t\t\t\t|\t\t LECTURER'S NAME :  MRS OJO\t\t \t\t|\t\t\t\t\t     *");
	print("------------------------------------------------------------------------------------------------------------------------------------------------------");
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------");


	int errcheck = 1;
	char errcheckinput[10];
	int *xCoefficient;
	do
	{
		//TO GET THE LARGEST POWER OF X IN THE EQUATION
		print("------|\tEnter the LARGEST POWER OF X in the Equation : ");
		scanf("%d", &xMaximumPower);
		NEWLINE;

		xCoefficient = (int*)malloc((xMaximumPower + 1) * sizeof(int));
		//TO STORE THE COEFFICIENTS X IN AN ARRAY
		for (i = xMaximumPower; i >= 0; i--)
		{
			print("------|\tEnter the coefficient of x^%d : ", i);
			scanf("%d", &xCoefficient[i]);
		}

		// TO CHECK IF THE EQUATION ENTERED IS CORRECT
		NEWLINE;
		print("------|\tCheck if the equation below matches your equation : ");
		NEWLINE;
		print("------|\t")
			for (i = xMaximumPower; i >= 0; i--)
			{
				if (i == 0)
				{
					print("%d", xCoefficient[0]);
					break;
				}

				if (xCoefficient[i] == 1)
				{
					print("X^%d ", i);
				}
				else
				{
					print("(%d)X^%d ", xCoefficient[i], i);
				}

				if (i > 0)
				{
					print("+ ");
				}
			}
		print(" = 0");
		NEWLINE;
		Sleep(3500);
	back:
		NEWLINE;
		print("------|\tIf the equaton matches your equation enter YES to continue : ");
		scanf("%s", &errcheckinput);
		errcheck = response(errcheckinput);
		NEWLINE;
		if (errcheck == 2)
		{
			print("------|\tinput error");
			goto back;
		}
	} while (errcheck == 0);


	//COLLECT VALUES OF x0
	int noOfx0; //number of x0 to be tested for
	print("------|\tHow many values of x0 do you want to test for : ");
	scanf("%d", &noOfx0);
	float *x0 = (float*)malloc(noOfx0 * sizeof(float));
	for (i = 0; i < noOfx0; i++)
	{
		print("------|\tEnter the %d%s value of x0 : ", (i + 1), positionSuffix(i + 1));
		scanf("%f", &x0[i]);
	}

	//GENERATE ARRAY FOR THE VALUES OF Xi IN ALL x0
	float **xRootValues = (float**)malloc(noOfx0 * sizeof(float*));
	for (i = 0; i < 10; i++)
	{
		xRootValues[i] = (float*)malloc(sizeof(float*) * 10);
	}

	//test printout of x Coeficients
	/*for (i = xMaximumPower; i >= 0; i--)
	{
	printf("%d, ", xCoefficient[i]);
	}*/
	//test printout of x0
	/*for (i = 0; i < noOfx0; i++)
	{
	printf("%f ", x0[i]);
	}*/

	for (i = 0; i < noOfx0; i++)
	{
		float *arrayToAllocate = generateRoots(xCoefficient, x0[i], xMaximumPower);
		for (j = 0; j < 10; j++)
		{
			//xRootValues[i] = generateRoots(x0[i], xMaximumPower, xCoefficient);
			xRootValues[i][j] = arrayToAllocate[j];
		}
	}

	//PRINT THE VALUES GENERATED
	NEWLINE;

	print("------------------------------------------------------------------------------------------------------------------------------------------------------");
	print("------|\tTABLE OF VALUES OF Xn FOR ALL x0 (where n = 0,1,2,...n)");
	NEWLINE;
	print("------------------------------------------------------------------------------------------------------------------------------------------------------");
	print("------|\tx0\t");
	for (i = 0; i < noOfx0; i++)
	{
		printf("|\t%.4f\t", x0[i]);
	}
	NEWLINE;
	print("------------------------------------------------------------------------------------------------------------------------------------------------------");
	for (i = 0; i < 10; i++)
	{
		print("------|\tx%d\t", (i + 1));
		for (j = 0; j < noOfx0; j++)
		{
			print("|\t%.4f\t", xRootValues[j][i]);
		}
		print("\n");
	}
	print("------------------------------------------------------------------------------------------------------------------------------------------------------");
	NEWLINE;
	NEWLINE;
	print("------|\The real root of the equation that can be generated by FIXED POINT FORMULAE is : %.4f", X_REAL_ROOT);
	NEWLINE;
	NEWLINE;
	Sleep(5000);
	// code to exit the application
	print("----|progam is exiting");
	for (i = 0; i < 4; i++)
	{
		Sleep(5000);
		printf(".");
	}
	printf("______________________________________________________________________________________________________________________________________________________");
	exit(0);
	return 0;
}