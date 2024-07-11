class ParkingSystem
{
private:
    int big, medium, small;
    int available[3];

public:
    ParkingSystem(int big, int medium, int small) : big(big), medium(medium), small(small)
    {
        available[0] = big;
        available[1] = medium;
        available[2] = small;
    }

    bool addCar(int carType)
    {
        if (available[carType - 1] > 0)
        {
            available[carType - 1]--;
            return true;
        }
        return false;
    }
};