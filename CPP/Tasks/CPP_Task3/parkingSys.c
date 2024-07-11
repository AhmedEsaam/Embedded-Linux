#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int sizes[3];
    int available[3];

} ParkingSystem;

ParkingSystem *parkingSystemCreate(int big, int medium, int small)
{
    ParkingSystem *ps = (ParkingSystem *)malloc(1 * sizeof(ParkingSystem));
    ps->sizes[0] = big;
    ps->sizes[1] = medium;
    ps->sizes[2] = small;

    ps->available[0] = big;
    ps->available[1] = medium;
    ps->available[2] = small;

    return ps;
}

bool parkingSystemAddCar(ParkingSystem *obj, int carType)
{
    if (obj->available[carType - 1] > 0)
    {
        obj->available[carType - 1]--;
        return true;
    }
    return false;
}

void parkingSystemFree(ParkingSystem *obj)
{
    for (int i = 0; i < 3; ++i)
    {
        obj->available[i] = obj->sizes[i];
    }
}
