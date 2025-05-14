#include <stdio.h>
#include <math.h>

struct points
{
    int point1[2];
    int point2[2]; 
}p1,p2;

float distance(int m1[2],int m2[2])
{
    float d;
    d=sqrt(((m2[0]-m1[0])*(m2[0]-m1[0]))+((m2[1]-m1[1])*(m2[1]-m1[1])));
    return d;
}

void main()
{
    float d1,d2;
    printf("Enter the coordinates of the first group of two points : ");
    scanf("%d%d%d%d",&p1.point1[0],&p1.point1[1],&p1.point2[0],&p1.point2[1]);
    printf("\nEnter the coordinates of the second group of two points : ");
    scanf("%d%d%d%d",&p2.point1[0],&p2.point1[1],&p2.point2[0],&p2.point2[1]);
    
    d1=distance(p1.point1,p1.point2);
    d2=distance(p2.point1,p2.point2);

    printf("\nThe distance between the points of the first group is : %f",d1);
    printf("\nThe distance between the points of the second group is : %f",d2);

    printf("\nThe sum of the two distances is : %f",d1+d2);
}