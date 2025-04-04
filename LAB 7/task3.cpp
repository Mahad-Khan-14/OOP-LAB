#include <iostream>
using namespace std;

class Ticket
{
protected:
    int ticketID;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    Ticket(int id, string name, double p, string d, string dest)
        : ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}

    virtual void reserve()
    {
        cout << "Ticket reserved for " << passengerName << " to " << destination << " on " << date << ".\n";
    }

    virtual void cancel()
    {
        cout << "Ticket cancellation requested for " << passengerName << ".\n";
    }

    virtual void displayTicketInfo()
    {
        cout << "Ticket ID: " << ticketID << ", Passenger: " << passengerName
             << ", Price: $" << price << ", Date: " << date << ", Destination: " << destination << endl;
    }

    virtual ~Ticket() {}
};

class FlightTicket : public Ticket
{
private:
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string name, double p, string d, string dest, string airline, string fNum, string sClass)
        : Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(fNum), seatClass(sClass) {}

    void displayTicketInfo() override
    {
        cout << "Flight Ticket - Passenger: " << passengerName << ", Flight: " << flightNumber
             << ", Airline: " << airlineName << ", Class: " << seatClass << ", Price: $" << price << endl;
    }
};

class TrainTicket : public Ticket
{
private:
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string name, double p, string d, string dest, string trainNum, string coach, string depTime)
        : Ticket(id, name, p, d, dest), trainNumber(trainNum), coachType(coach), departureTime(depTime) {}

    void reserve() override
    {
        cout << "Train ticket auto-assigned for " << passengerName << " on train " << trainNumber
             << " at " << departureTime << ".\n";
    }

    void displayTicketInfo() override
    {
        cout << "Train Ticket - Passenger: " << passengerName << ", Train: " << trainNumber
             << ", Coach: " << coachType << ", Departure: " << departureTime << ", Price: $" << price << endl;
    }
};

class BusTicket : public Ticket
{
private:
    string busCompany;
    int seatNumber;

public:
    BusTicket(int id, string name, double p, string d, string dest, string busComp, int seatNum)
        : Ticket(id, name, p, d, dest), busCompany(busComp), seatNumber(seatNum) {}

    void cancel() override
    {
        cout << "Bus ticket for " << passengerName << " is eligible for a last-minute refund.\n";
    }

    void displayTicketInfo() override
    {
        cout << "Bus Ticket - Passenger: " << passengerName << ", Bus Company: " << busCompany
             << ", Seat: " << seatNumber << ", Price: $" << price << endl;
    }
};

class ConcertTicket : public Ticket
{
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, double p, string d, string venueName, string artist, string sType)
        : Ticket(id, name, p, d, venueName), artistName(artist), venue(venueName), seatType(sType) {}

    void displayTicketInfo() override
    {
        cout << "Concert Ticket - Passenger: " << passengerName << ", Artist: " << artistName
             << ", Venue: " << venue << ", Seat Type: " << seatType << ", Price: $" << price << endl;
    }
};

int main()
{
    const int numTickets = 4;
    Ticket *tickets[numTickets];

    tickets[0] = new FlightTicket(101, "Alice", 350, "12-04-2025", "New York", "Emirates", "EK202", "Business");
    tickets[1] = new TrainTicket(102, "Bob", 120, "15-04-2025", "Chicago", "TR100", "First Class", "10:00 AM");
    tickets[2] = new BusTicket(103, "Charlie", 50, "18-04-2025", "San Francisco", "Greyhound", 22);
    tickets[3] = new ConcertTicket(104, "David", 80, "20-04-2025", "Madison Square Garden", "Coldplay", "VIP");

    cout << "Online Ticket Reservation System:\n";
    for (int i = 0; i < numTickets; i++)
    {
        tickets[i]->displayTicketInfo();
        tickets[i]->reserve();
        tickets[i]->cancel();
        cout << "--------------------------\n";
    }

    for (int i = 0; i < numTickets; i++)
    {
        delete tickets[i];
    }

    return 0;
}
