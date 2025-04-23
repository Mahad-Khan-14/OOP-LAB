#include "iostream"
using namespace std;

class Shipment
{
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string n, double w) : trackingNumber(n), weight(w) {};

    virtual void EstimatedDeliveryTime() = 0;
    virtual void showDetails() = 0;
    virtual ~Shipment() {};
};

class AirFreight : public Shipment
{
public:
    AirFreight(string n, double w) : Shipment(n, w) {};

    void EstimatedDeliveryTime()
    {
        cout << "Estimated Delivery Time for AirFreight is: "
             << (weight < 150 ? "2 Days" : "3 Days") << endl;
    }

    void showDetails()
    {
        cout << "AirFreight Shipment Tracking # " << trackingNumber << ", Total Weight: " << weight << "Kg" << endl;
    }
};

class GroundShipment : public Shipment
{
public:
    GroundShipment(string n, double w) : Shipment(n, w) {};

    void EstimatedDeliveryTime()
    {
        cout << "Estimated Delivery Time for Ground Shipment is: "
             << (weight < 100 ? "3 Days" : "4 Days") << endl;
    }

    void showDetails()
    {
        cout << "Ground Shipment Tracking # " << trackingNumber << ", Total Weight: " << weight << "Kg" << endl;
    }
};

int main()
{
    Shipment *shipmentRoutes[2];
    shipmentRoutes[0] = new AirFreight("38-BC", 140);
    shipmentRoutes[1] = new GroundShipment("14-AD", 176);

    for (int i = 0; i < 2; i++)
    {
        shipmentRoutes[i]->EstimatedDeliveryTime();
        shipmentRoutes[i]->showDetails();
    }

    for (int i = 0; i < 2; i++)
    {
        delete shipmentRoutes[i];
    }

    return 0;
}