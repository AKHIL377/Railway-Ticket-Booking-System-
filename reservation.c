#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mynode
{
    char name[20];
    char gen[6];
    int age;
    struct mynode* link;
}
Node;
Node* start = NULL;
void details(int);
int seat(int);
int cal(int, int, int);
void bill(int, int);

char source[20], des[20], train[40];
char station[40], cla[40];
int time1, time2, a[55];
void main()
{
    int i, j, a1, a2, b, c;
	int x=0,d,e,r;
    char o;
    printf("Enter Number Of Passengers:-\n");
    fflush(stdin);
    scanf("%d", &j);

    details(j);
    printf("Enter The Source Place:-\n");
    fflush(stdin);
    gets(source);
    printf("Enter The Destination Place:-\n");
    gets(des);
    printf("\t\tThe Following Trains "
           "Are Available.....\n");
    printf("\t\t1. Rayalaseema Express.."
           ".......10:00 "
           "a.m........secundrabad Station\n");
    printf("\t\t2. Satabdi Express..."
           ".......05:00 "
           "p.m........Howrah Station\n");
    printf("\t\t3. vasco-da-gama Express..."
           ".......11:00 "
           "p.m........Goa"
           " Station\n");
    printf("\t\t4. Garib-Rath Express"
           ".........05:00 "
           "p.m........Sealdah Station\n");
    printf("\t\t5. Haripriya Express..."
           ".........07:00 "
           "a.m.........tirupathi Station\n");
    scanf("%d", &i);
    do {
        switch (i) {
        case 1:
		{
            strcpy(train,
                   "Rayalaseema Express");
            strcpy(station,
                   "Secundrabad Station");
            time1 = 10;
            time2 = 00;
            a1 = 2099;
            a2 = 1560;

            d = cal(a1, a2, j);
            printf("Total Bill Amount: %d\n",d);
        }; break;
        case 2: {
            strcpy(train,
                   "Satabdi Express");
            strcpy(station,
                   "Howrah Station");
            time1 = 05;
            time2 = 00;
            a1 = 1801;
            a2 = 981;

            d = cal(a1, a2, j);
            printf("Total Bill Amount: %d\n",d);
        }; break;
        case 3: {
            strcpy(train, "vasco-da-gamma Express");
            strcpy(station, "Goa station");
            time1 = 11;
            time2 = 00;
            a1 = 2199;
            a2 = 1780;

            d = cal(a1, a2, j);
            printf("Total Bill Amount: %d\n", d);
        }; break;
        case 4: {
            strcpy(train, "Garib-Rath Express");
            strcpy(station, "Sealdah Station");
            time1 = 05;
            time2 = 00;
            a1 = 1759;
            a2 = 1200;

            d = cal(a1, a2, j);
            printf("Total Bill Amount: %d\n", d);
        }; break;
        case 5: {
            strcpy(train, "Haripriya Express");
            strcpy(station, "Tirupathi Station");
            time1 = 07;
            time2 = 00;
            a1 = 2205;
            a2 = 1905;

            d = cal(a1, a2, j);
            printf("Total Bill Amount: %d\n", d);
        }; break;
        default:
            printf("Enter Correct choice.....\n");
            x = 1;
            break;
        }
    } while (x);
    printf("Now Book Your Seats......\n");

    seat(j);

    bill(d,j);
}
int cal(int y1, int y2, int h)
{
    int b, c, i, t, r, n;
    printf("\t\tEnter Your Choice......\n");
    printf("\t\t1. Sleeper Class....\n");
    printf("\t\t2. A.C Class.......\n");
    scanf("%d", &i);
    switch (i)
	{
    case 1:
	{
        strcpy(cla, "Sleeper Class");
        b = y2 * h;
        c = b + (b * 0.18);
    } break;
    case 2:
	{
        printf("\t\tEnter Your Choice....\n");
        printf("\t\t1. 3A Class....\n");
        printf("\t\t2. 2A Class....\n");
        printf("\t\t3. 1st Class A.C.....\n");
        scanf("%d", &n);
        switch (n)
		{
        case 1:
		{
            strcpy(cla, "3A Class");
            b = y1 * h;
            c = b + (b * 0.18);
        } break;
        case 2:
		{
            strcpy(cla, "2A Class");
            b = (y1 + 1000) * h;
            c = b + (b * 0.18);
        } break;
        case 3:
		{
            strcpy(cla, "1st Class A.C.");
            b = (y1 + 5000) * h;
            c = b + (b * 0.18);
        } break;
        default:
		{
            printf("\t\tEnter Right Choice......\n");
        }
        }
    }
	 break;
    default:
	{
        printf("\t\tEnter Right Choice......\n");
    }
    }
    return c;
}
 void details(int k)
{
    int i, a;
    char val[20], gen[6];
    for (i = 1; i <= k; i++)
	{
        printf("Enter The %dth Passenger Name: ", i);
        fflush(stdin);
        gets(val);
        printf("Enter The %dth Passenger Gender: ", i);
        fflush(stdin);
        gets(gen);
        printf("Enter The %dth Passenger Age: ", i);
        fflush(stdin);
        scanf("%d", &a);

        add_node(val, gen, a);
    }
}
void add_node(char lol[20], char der[6], int b)
{
    Node *newptr = NULL, *ptr;
    newptr = (Node*)malloc(sizeof(Node));
    strcpy(newptr->name, lol);
    strcpy(newptr->gen, der);
    newptr->age = b;
    newptr->link = NULL;
    if (start == NULL)
        start = newptr;
    else
	{
        ptr = start;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = newptr;
    }
}
int seat(int p)
{
    int i;
    printf("\t           -:SEAT MATRIX:-        \n");
    printf("\t(U)    (M)        (L)    (L)    "
           "    (U)\n\n");
    printf("\t01    02        03\t04        "
           "05\n\n");
    printf("\t06    07        08\t09        "
           "10\n");
    printf("\t11    12        13\t14        "
           "15\n\n");
    printf("\t16    17        18\t19        "
           "20\n");
    printf("\t21    22        23\t24        "
           "25\n\n");
    printf("\t26    27        28\t29        "
           "30\n");
    printf("\t31    32        33\t34        "
           "35\n\n");
    printf("\t36    37        38\t39        "
           "40\n");
    printf("\t41    42        43\t44        "
           "45\n\n");
    printf("\t46    47        48\t49        "
           "50\n");
    printf("\t51    52        53\t54        "
           "55\n\n");
    printf("\t56    57        58\t59        "
           "60\n");
    printf("\tEnter Seat Numbers: \n");
    for (i = 0; i < p; i++)
        scanf("%d", &a[i]);
}
void bill(int y, int j)
{
    int i;
    Node* ptr = start;
    for (i = 1; i <= j; i++)
	{
        printf("\t\t\%dst Passenger Name: ", i);
        puts(ptr->name);
        printf("\t\t%dst Passenger Gender: ", i);
        puts(ptr->gen);
        printf("\t\t%dst Passenger Age: %d\n\n", i,
               ptr->age);
        ptr = ptr->link;
    }
    printf("\n\nSource Place:-");
    puts(source);
    printf("\n\nDestination Place:-");
    puts(des);
    printf("\n\nThe Boarding Station:-");
    puts(station);
    printf("\n\nTrain Is:-");
    puts(train);
    printf("\n\nAllocated Class:-");
    puts(cla);
    printf("\n\nBoarding Time: %d:%d", time1, time2);
    printf("\n\nTotal Bill Amount: %d", y);
    printf("\n\nAllocated Seats Are:");
    for (i = 0; i < j; i++)
	{
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("\t\t\t\tThank You......\n");
}
