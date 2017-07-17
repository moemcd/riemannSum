//
//  main.c
//  Lab 08
//
//  Created by Morgan  McDowell on 3/22/17.
//  Copyright © 2017 Morgan  McDowell. All rights reserved.
//

#include <stdio.h>
#include <math.h>

//function declarations
double getInitial();
double getFinal(double);
double getRect();
double getChoice();
double leftCalc(double, double, double, double, double, double);
double midCalc(double, double, double, double, double, double);
double rightCalc(double, double, double, double, double, double);

int main()
{
    //local variables
    double a;
    double b;
    double c;
    double initial;
    double final;
    double rect;
    double choice;
    double width;
    double area;
    
    //statements
    printf("Enter integer coefficients [a b c]: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    printf("Enter the initial value of x: ");
    scanf("%lf", &initial);
    
    do
    {
        printf("Enter the final value of x: ");
        final = scanf("%lf", &final);
        if (final <= initial)
            printf("\nError! Final must be greater than initial!!\n \n");
    } while (final <= initial);
    
    do
    {
        printf("\nPlease enter the number of approximating rectangles: ");
        rect = scanf("%lf", &rect);
        if (rect <= 0)
            printf("\nError! Number of rectangles must be positive!!\n");
    } while (rect <= 0);
    
    printf("\nPlease choose your method of approximation: \n1. Left end-point\n2. Mid-point\n3. Right end-point\nYour choice: ");
    choice = scanf("%lf", &choice);
    
    while ((choice != 1) && (choice != 2) && (choice != 3))
    {
        printf("\nError! Invalid selection!!\n");
        printf("\nPlease choose your method of approximation: \n1. Left end-point\n2. Mid-point\n3. Right end-point\nYour choice: ");
        choice = scanf("%lf", &choice);
    }
    
    /*initial = getInitial();
    final = getFinal(initial);
    rect = getRect();
    choice = getChoice(); */
    
    width = (final - initial) / rect;
    
    if (choice == 1)
        area = leftCalc (a, b, c, initial, final, width);
    else if (choice == 2)
        area = midCalc (a, b, c, initial, final, width);
    else if (choice == 3)
        area = rightCalc (a, b, c, initial, final, width);
    
    printf("\nEstimated area: %lf sq. units\n", area);
    
    return(0);
}

/******************************************************************************
 * Function:    function name
 * Description: brief description of what the function does
 * Parameters:  variable1 name, data type, and description
 *              variable2 name, data type, and description
 * Return:      data type and description
 ******************************************************************************/
/*int getInitial()
{
    int initial;
    printf("Enter the initial value of x: ");
    scanf("%d", &initial);
    return initial;
}
*/
/******************************************************************************
 * Function:    function name
 * Description: brief description of what the function does
 * Parameters:  variable1 name, data type, and description
 *              variable2 name, data type, and description
 * Return:      data type and description
 ******************************************************************************/
/*int getFinal(initial)
{
    int final;
    do
    {
        printf("Enter the final value of x: ");
        scanf("%d", &final);
        if (final <= initial)
            printf("\nError! Final must be greater than initial!!\n \n");
    } while (final <= initial);
    
    return final;
}
*/
/******************************************************************************
 * Function:    function name
 * Description: brief description of what the function does
 * Parameters:  variable1 name, data type, and description
 *              variable2 name, data type, and description
 * Return:      data type and description
 ******************************************************************************/
/*int getRect()
{
    int rect;
    
    do
    {
        printf("\nPlease enter the number of approximating rectangles: ");
        scanf("%d", &rect);
        if (rect <= 0)
            printf("\nError! Number of rectangles must be positive!!\n");
    } while (rect <= 0);
    
    return rect;
}
*/
/******************************************************************************
 * Function:    function name
 * Description: brief description of what the function does
 * Parameters:  variable1 name, data type, and description
 *              variable2 name, data type, and description
 * Return:      data type and description
 ******************************************************************************/
/*int getChoice()
{
    int choice;
    
    printf("\nPlease choose your method of approximation: \n1. Left end-point\n2. Mid-point\n3. Right end-point\nYour choice: ");
    scanf("%d", &choice);
    
    while ((choice != 1) && (choice != 2) && (choice != 3))
    {
        printf("\nError! Invalid selection!!\n");
        printf("\nPlease choose your method of approximation: \n1. Left end-point\n2. Mid-point\n3. Right end-point\nYour choice: ");
        scanf("%d", &choice);
    }
    
    return(choice);
}
*/
/******************************************************************************
 * Function:    function name
 * Description: brief description of what the function does
 * Parameters:  variable1 name, data type, and description
 *              variable2 name, data type, and description
 * Return:      data type and description
 ******************************************************************************/
double leftCalc (double a, double b, double c, double initial, double final, double width)
{
    double area;
    
    while (initial < final)
    {
        area += width * (a * pow(initial, 2) + b * initial + c);
        initial += width;
    }
    
    return(area);
}

/******************************************************************************
 * Function:    function name
 * Description: brief description of what the function does
 * Parameters:  variable1 name, data type, and description
 *              variable2 name, data type, and description
 * Return:      data type and description
 ******************************************************************************/
double midCalc (double a, double b, double c, double initial, double final, double width)
{
    double area;
    
    while (initial < final)
    {
        initial += width / 2;
        area += width * (a * pow(initial, 2) + b * initial + c);
        initial += width / 2;
    }
    
    return area;
}

/******************************************************************************
 * Function:    function name
 * Description: brief description of what the function does
 * Parameters:  variable1 name, data type, and description
 *              variable2 name, data type, and description
 * Return:      data type and description
 ******************************************************************************/
double rightCalc (double a, double b, double c, double initial, double final, double width)
{
    double area;
    
    while (initial < final)
    {
        initial += width;
        area += width * (a * pow(initial, 2) + b * initial + c);
    }
    
    return area;
}
