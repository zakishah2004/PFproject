#include <iostream>
#include <string>
using namespace std;

struct Client {
    string name;
    string mobile;
    string email;
    string userId;
    string password;
    string bookingDate;
    string checkoutDate;
};

const int MAX_CLIENTS = 10;
Client clients[MAX_CLIENTS] = {
    {"Asim ali", "03185616423", "asimali123@gmail.com", "", "", "24/12/2024", "10/01/2025"},
    {"SHIZA LARAIB", "03179254234", "shiza123@gmail.com", "", "", "23/12/2024", "11/01/25"},
    {"Haris Pasha", "03101231239", "pasha420@gmail.com", "", "", "01/01/2025", "15/01/2025"},
    {"Zaki shah", "03101112226", "zsh0707@gmail.com", "", "", "07/01/2025", "10/01/2025"},
    {"Areesha Shabbir", "03005040179", "areeshashabir25@gmail.com", "", "", "10/01/2025", "20/01/2025"},
    {"", "", "", "client123", "pakistan123", "", ""},
    {"", "", "", "", "", "", ""},
    {"", "", "", "", "", "", ""},
    {"", "", "", "", "", "", ""},
    {"", "", "", "", "", "", ""}
};

int bookedRooms[] = { 2, 6, 7, 8, 10 };
int bookedCount = sizeof(bookedRooms) / sizeof(bookedRooms[0]);

void showRoomDetails() {
    cout << "BOOKED ROOMS:" << endl;
    for (int i = 0; i < bookedCount; i++) {
        cout << "Room " << bookedRooms[i] << endl;
    }
    cout << "AVAILABLE ROOMS:" << endl;
    cout << "Room 1, Room 3, Room 4, Room 5, Room 9" << endl;
}

void inputClientDetails(Client& client) {
    cout << "Enter your name: ";
    getline(cin, client.name);
    cout << "Enter your mobile number: ";
    getline(cin, client.mobile);
    cout << "Enter your email: ";
    getline(cin, client.email);
    cout << "Enter User ID: ";
    getline(cin, client.userId);
    cout << "Enter Password: ";
    getline(cin, client.password);
}

bool loginClient(Client& client) {
    string user_id, user_password;
    cout << "Enter User ID: ";
    getline(cin, user_id);
    cout << "Enter Password: ";
    getline(cin, user_password);
    return (user_id == client.userId && user_password == client.password);
}

void bookRoom(Client& client) {
    showRoomDetails();
    cout << "Select Room no: ";
    int roomno;
    cin >> roomno;

    // Check if the room is booked
    bool isBooked = false;
    for (int i = 0; i < bookedCount; i++) {
        if (bookedRooms[i] == roomno) {
            isBooked = true;
            break;
        }
    }

    if (isBooked) {
        cout << "Sorry, but this room is already booked." << endl;
    }
    else {
        cout << "You have booked room no " << roomno << endl;
        cout << "Press 1 to continue: ";
        int con;
        cin >> con;

        if (con == 1) {
            cout << "Select payment Method" << endl;
            cout << "Press 1 for cash on arrival\nPress 2 for Card Payment (Discounted Price): ";
            int payment;
            cin >> payment;

            if (payment == 2) {
                cout << "Enter Card Details: ";
                string card_details;
                cin >> card_details;
                cout << "Thank you for your payment." << endl;
            }
            else if (payment == 1) {
                cout << "Thank you for choosing cash on arrival." << endl;
            }
            else {
                cout << "Error: Invalid payment option." << endl;
            }
        }
        else {
            cout << "Error: Invalid option." << endl;
        }
    }
}

void adminPortal() {
    string loginId, password;
    cout << "Enter login ID: ";
    getline(cin, loginId);
    cout << "Enter password: ";
    getline(cin, password);

    if (loginId == "admin123" && password == "pakistan123") {
        cout << "Admin portal access granted." << endl;
        cout << "PRESS 1 TO SHOW ROOM DETAILS: ";
        int details;
        cin >> details;
        cin.ignore(); // to handle newline after cin

        if (details == 1) {
            showRoomDetails();
            cout << "Select Room no to show its Details: ";
            int roomno;
            cin >> roomno;
            cin.ignore(); // to handle newline after cin

            if (roomno >= 1 && roomno <= 10) {
                if (roomno == 1 || roomno == 3 || roomno == 4 || roomno == 5 || roomno == 9) {
                    cout << "You selected a room that is available for booking." << endl;
                }
                else {
                    // Display booked room details
                    for (int i = 0; i < bookedCount; i++) {
                        if (roomno == bookedRooms[i]) {
                            cout << "ROOM BOOKED BY " << clients[i].name << endl;
                            cout << "Contact no: " << clients[i].mobile << endl;
                            cout << "Email id: " << clients[i].email << endl;
                            cout << "Check in: " << clients[i].bookingDate << endl;
                            cout << "Check out: " << clients[i].checkoutDate << endl;
                            return;
                        }
                    }
                }
            }
            else {
                cout << "Invalid room number." << endl;
            }
        }
    }
    else {
        cout << "Invalid login credentials." << endl;
    }
}

void clientPortal() {
    cout << "Press 1 to Create an Account" << endl;
    cout << "Press 2 to Login to an existing Account" << endl;
    int acc;
    cin >> acc;
    cin.ignore(); // to handle newline after cin

    if (acc == 1) {
        inputClientDetails(clients[5]); // Assuming the 6th client is the new one
        cout << "Account created successfully!" << endl;
    }
    else if (acc != 2) {
        cout << "INVALID CHOICE" << endl;
        return;
    }

    if (loginClient(clients[5])) {
        cout << "Login successful!" << endl;
        cout << "WELCOME " << clients[5].name << endl;
        cout << "Press 1 To book a Room\nPress 2 to Logout: ";
        int details;
        cin >> details;

        if (details == 1) {
            bookRoom(clients[5]);
        }
    }
    else {
        cout << "Invalid User ID or Password." << endl;
    }
}

int main() {
    string userType;

    cout << "Welcome to LEXUS HOTEL ONLINE SYSTEM" << endl;
    cout << "Enter user type (admin/client): ";
    getline(cin, userType);

    if (userType == "admin") {
        adminPortal();
    }
    else if (userType == "client") {
        clientPortal();
    }
    else {
        cout << "Invalid user type." << endl;
    }

    return 0;
}