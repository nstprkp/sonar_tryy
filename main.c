#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headder.h"

struct flat
{
    int floor;
    int number;
    char family[50];
};

void sortBuble(struct flat *skyscraper, int t, int n)
{
    struct flat tmp;

    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<i; j++)
        {
            if ((skyscraper[j].floor > skyscraper[j + 1].floor && t==1) ||
                (skyscraper[j].number > skyscraper[j + 1].number && t==2) ||
                (strcmp(skyscraper[j].family, skyscraper[j + 1].family)>0  && t==3) ) //strcmp(strings[j], strings[j+1]) > 0
            {
                tmp = skyscraper[j];
                skyscraper[j] = skyscraper[j + 1];
                skyscraper[j + 1] = tmp;
            }
        }
    }

    printf("\nAfter sort: \n");
    for (int i=0; i<n; i++) {
        printf("%d. family: %s, floor: %d, number: %d; \n", i+1, skyscraper[i].family, skyscraper[i].floor, skyscraper[i].number);
    }
}

int main()
{
    struct flat *skyscraper;
    printf("Enter the number of apartments in skyscraper: ");
    int n;
    scanf("%d", &n);

    skyscraper=(struct flat*)calloc(n, sizeof(struct flat));

    printf("Enter information about apartments: \n");
    for (int i=0; i<n; i++) {
        printf("Enter the foor: ");
        scanf("%d", &skyscraper[i].floor);
        printf("Enter the number of flat: ");
        scanf("%d", &skyscraper[i].number);
        printf("Enter the last name of the family that lives in flat: ");
        scanf("%s", &skyscraper[i].family);
    }

    printf("\nPress the button. \nIf you want to sort by floor - 1, by number - 2, by family - 3: ");
    int t;
    scanf("%d", &t);

    sortBuble(skyscraper, t, n);
  /*  printf("\nInformations about flat: \n");
    for (int i=0; i<n; i++) {
        printf("%d. family: %s, floor: %d, number: %d; \n", i+1, skyscraper[i].family, skyscraper[i].floor, skyscraper[i].number);
    }*/
    return 0;
}
