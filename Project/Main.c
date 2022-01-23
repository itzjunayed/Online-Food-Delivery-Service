//Header file for input output
#include<stdio.h>
//Header file for system, exit function
#include<stdlib.h>
//Header file for string built in function
#include<string.h>

//structure for taking user information
struct information
{
    char name[50];
    char address[50];
    char number[15];
    char email[50];
    char password[50];
} info;

//declaring file
FILE *file;

//payment slip
void slipPrint(int voucher, char location, int item[][2], int selection, char emailAddress[])
{
    //opening the file for reading
    file = fopen("Information.txt","r");

    system("cls");

    printf("\n\n                                    Payment Slip Print\n");
    printf("-----------------------------------------------------------------------------------------------\n\n");
    //reading the whole file
    while(fread(&info,sizeof(info),1,file)==1)
    {
        if(strcmp(info.email,emailAddress)==0)
        {
            printf("Name: %s\nAddress: %s\nNumber: %s\n\n",info.name,info.address,info.number);
        }
    }
    printf("       Item Name                     Quantity                  Price\n");
    printf("---------------------------------------------------------------------------\n");
    int i=0, total=0;
    while(i<selection)
    {
        if(item[i][0]==1)
        {
            printf("Chicken Burger                          %d                      %d\n",item[i][1],item[i][1]*140);
            total += item[i][1]*140;
        }
        else if(item[i][0]==2)
        {
            printf("Chicken Cheese Burger                   %d                      %d\n",item[i][1],item[i][1]*160);
            total += item[i][1]*160;
        }
        else if(item[i][0]==3)
        {
            printf("Chicken Chowmein                        %d                      %d\n",item[i][1],item[i][1]*180);
            total += item[i][1]*180;
        }
        else if(item[i][0]==4)
        {
            printf("Smokey BBQ Chicken Burger               %d                      %d\n",item[i][1],item[i][1]*160);
            total += item[i][1]*160;
        }
        else if(item[i][0]==5)
        {
            printf("Smokey Chicken Cheese Burger            %d                      %d\n",item[i][1],item[i][1]*180);
            total += item[i][1]*180;
        }
        else if(item[i][0]==6)
        {
            printf("Chicken & Bacon Bite Burger             %d                      %d\n",item[i][1],item[i][1]*210);
            total += item[i][1]*210;
        }
        else if(item[i][0]==7)
        {
            printf("Chicken Curry                           %d                      %d\n",item[i][1],item[i][1]*140);
            total += item[i][1]*140;
        }
        else if(item[i][0]==8)
        {
            printf("Honey Chicken                           %d                      %d\n",item[i][1],item[i][1]*100);
            total += item[i][1]*100;
        }
        else if(item[i][0]==9)
        {
            printf("Sweet & Spicy Chicken                   %d                      %d\n",item[i][1],item[i][1]*100);
            total += item[i][1]*100;
        }
        else if(item[i][0]==10)
        {
            printf("Black Diamond Chicken                   %d                      %d\n",item[i][1],item[i][1]*100);
            total += item[i][1]*100;
        }
        else if(item[i][0]==11)
        {
            printf("Smokey BBQ Sub Sandwich                 %d                      %d\n",item[i][1],item[i][1]*180);
            total += item[i][1]*180;
        }
        else if(item[i][0]==12)
        {
            printf("Buffalo Wings                           %d                      %d\n",item[i][1],item[i][1]*109);
            total += item[i][1]*109;
        }
        else if(item[i][0]==13)
        {
            printf("Peri Peri Wings                         %d                      %d\n",item[i][1],item[i][1]*150);
            total += item[i][1]*150;
        }
        else if(item[i][0]==14)
        {
            printf("Cheesy Chicken Nachos                   %d                      %d\n",item[i][1],item[i][1]*170);
            total += item[i][1]*170;
        }
        else if(item[i][0]==15)
        {
            printf("Mexican Hot & Spicy Nachos              %d                      %d\n",item[i][1],item[i][1]*220);
            total += item[i][1]*220;
        }
        else if(item[i][0]==16)
        {
            printf("Crispy Wings                            %d                      %d\n",item[i][1],item[i][1]*150);
            total += item[i][1]*150;
        }
        else if(item[i][0]==17)
        {
            printf("Chicken Fried Rice (Vegs)               %d                      %d\n",item[i][1],item[i][1]*120);
            total += item[i][1]*120;
        }
        else if(item[i][0]==18)
        {
            printf("T-bone Steak                            %d                      %d\n",item[i][1],item[i][1]*1200);
            total += item[i][1]*1200;
        }
        else if(item[i][0]==19)
        {
            printf("Ribeye                                  %d                      %d\n",item[i][1],item[i][1]*1800);
            total += item[i][1]*1800;
        }
        else if(item[i][0]==20)
        {
            printf("Chicken Alfredo Pasta                   %d                      %d\n",item[i][1],item[i][1]*250);
            total += item[i][1]*250;
        }

        i++;
    }
    printf("---------------------------------------------------------------------------\n");
    printf("                                                              = %d\n",total);
    printf("Adding %d%c off\n",voucher,37);
    int delivery;
    if(location=='y' || location=='Y')
    {
        delivery = 50;
    }
    else
    {
        delivery = 100;
    }
    printf("Delivery Charge +%dTK\n",delivery);
    printf("---------------------------------------------------------------------------\n");
    float result = total - (total*((float)voucher/100)) + delivery;
    printf("Total Bill with delivery charge                               = %f\n",result);//total bill
    //closing the file
    fclose(file);
    printf("\nThanks for ordering :) \n");
    //program closed
    exit(0);
}
//Home page after login
void mainPage(char emailAddress[],char pass[])
{
    //opening the file for reading
    file = fopen("Information.txt","r");

    system("cls");

    int selection;
    //food list
    printf("\n                                 Online Food Delivery Service\n");
    printf("-----------------------------------------------------------------------------------------------\n\n");
    printf("    Available Item Code           Item Name                Quantity             Price            \n");
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("              1                 Chicken Burger                1                  140 TK\n");
    printf("              2              Chicken Cheese Burger            1                  160 TK\n");
    printf("              3                Chicken Chowmein               1                  180 TK\n");
    printf("              4            Smokey BBQ Chicken Burger          1                  160 TK\n");
    printf("              5          Smokey Chicken Cheese Burger         1                  180 TK\n");
    printf("              6           Chicken & Bacon Bite Burger         1                  210 TK\n");
    printf("              7                 Chicken Curry                 1                  140 TK\n");
    printf("              8                 Honey Chicken                 1                  100 TK\n");
    printf("              9             Sweet & Spicy Chicken             1                  100 TK\n");
    printf("             10             Black Diamond Chicken             1                  100 TK\n");
    printf("             11            Smokey BBQ Sub Sandwich            1                  180 TK\n");
    printf("             12                 Buffalo Wings                 1                  109 TK\n");
    printf("             13                Peri Peri Wings                1                  150 TK\n");
    printf("             14             Cheesy Chicken Nachos             1                  170 TK\n");
    printf("             15           Mexican Hot & Spicy Nachos          1                  220 TK\n");
    printf("             16                  Crispy Wings                 1                  150 TK\n");
    printf("             17            Chicken Fried Rice (Vegs)          1                  120 TK\n");
    printf("             18                  T-bone Steak                 1                 1200 TK\n");
    printf("             19                     Ribeye                    1                 1800 TK\n");
    printf("             20              Chicken Alfredo Pasta            1                  250 TK\n");
    printf("-----------------------------------------------------------------------------------------------\n\n");
    //reading the whole file
    while(fread(&info,sizeof(info),1,file)==1)
    {
        if(strcmp(info.email,emailAddress)==0 && strcmp(info.password,pass)==0)
        {
            printf("Name: %s\nAddress: %s\nEmail: %s\n\n",info.name,info.address,info.email);
        }
    }

    printf("How many item you want to buy: ");
    scanf("%d",&selection);//for measuring that how many item user want to buy

    int item[selection][2];

    int i=0;
    while(i<selection)
    {
        printf("%d. Input item code: ",i+1);
        scanf("%d",&item[i][0]);
        printf("%d. Input item quantity: ",i+1);
        scanf("%d",&item[i][1]);
        i++;
    }
    char location;
    fflush(stdin);
    printf("Are you inside Dhaka(y/n): ");
    scanf("%c",&location);

    char coupon[50];
    char c1[]="heyFoodie",c2[]="onlineFOOD",c3[]="100yummy"; //coupon code list
    fflush(stdin);
    printf("Do you have any coupon (if yes then input the code or else input n/N): ");
    gets(coupon);
    //checking the user input coupon code matched or not
    int voucher;
    if(strcmp(c1,coupon)==0 || strcmp(c3,coupon)==0)
    {
        voucher = 15;
    }
    else if(strcmp(c2,coupon)==0)
    {
        voucher = 10;
    }
    else
    {
        voucher = 0;
    }
    //calling the function for payment slip print
    slipPrint(voucher, location, item, selection, emailAddress);
    //closing the file
    fclose(file);
}
//login page
void logIn()
{
    //opening the file for reading
    file = fopen("Information.txt","r");

    system("cls");
    char emailAddress[50],pass[50];
    int count=0;
    //user input for login
    fflush(stdin);
    printf(">> Input Email: ");
    fgets(emailAddress,sizeof(emailAddress),stdin);

    fflush(stdin);
    printf(">> Input Password: ");
    fgets(pass,sizeof(pass),stdin);
    //reading the whole file
    while(fread(&info,sizeof(info),1,file)==1)
    {
        if(strcmp(info.email,emailAddress)==0 && strcmp(info.password,pass)==0)//checking if matched or not
        {
            count = 1;//if matched
        }
    }
    if(count==0)
    {
        printf("Invalid Email or Password");
        return;
    }
    else
    {
        mainPage(emailAddress,pass);//calling the mainPage function
    }
    //closing the file
    fclose(file);
}
//creating an account
void create()
{
    //opening the file for appending
    file = fopen("Information.txt","a");
    //inputing the information
    system("cls");
    printf(">>Please input the information required for sign up<<\n\n");

    fflush(stdin);
    printf(">> Name: ");
    fgets(info.name,sizeof(info.name),stdin);

    fflush(stdin);
    printf(">> Address: ");
    fgets(info.address,sizeof(info.address),stdin);

    fflush(stdin);
    printf(">> Number: ");
    fgets(info.number,sizeof(info.number),stdin);

    fflush(stdin);
    printf(">> Email: ");
    fgets(info.email,sizeof(info.email),stdin);

    fflush(stdin);
    printf(">> Password: ");
    fgets(info.password,sizeof(info.password),stdin);

    //writing on file
    fwrite(&info,sizeof(info),1,file);
    //closing the file
    fclose(file);
}
//signing up function
void signUp()
{
    system("cls");

    int selection;
    printf("1. Create an account\n");
    printf("2. Already have an account\n");
    printf("Input 1 or 2: ");
    scanf("%d",&selection);//selection process whether to create account or to direct login

    switch(selection)
    {
    case 1:
        create();//calling create function
        break;
    case 2:
        logIn();//calling login function
        break;
    default:
        printf("Please input right digit.\n");//if entry digit wrong
    }
}
//starting page
int main()
{
    system("cls");

    int selection = -1;
    //welcome screen
    printf("\n                            Welcome To Online Food Delivery Service\n");
    printf("----------------------------------------------------------------------------------------------\n");

    while(selection != 0)//process will continue till the user input 0
    {
        printf("\n                                         0. Exit\n");
        printf("                                         1. Sign Up\n");
        printf("                                         2. Log In\n\n\n");
        printf("Input 0 or 1 or 2: ");
        scanf("%d",&selection);

        switch(selection)
        {
        case 0:
            break;
        case 1:
            signUp();//calling the signUp function
            break;
        case 2:
            logIn();//calling the login function
            break;
        default:
            printf("Please input right digit.\n");
        }
    }
    return 0;
}
