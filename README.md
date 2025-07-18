LEXUS HOTEL ONLINE SYSTEM
A simple console-based hotel management system built in C++ for managing room bookings, client accounts, and administrative operations.

📋 Features
Client Portal
Account Creation: New users can create accounts with personal details
User Login: Secure login system with User ID and password
Room Booking: View available rooms and book accommodation
Payment Options:
Cash on arrival
Card payment (with discount)
Room Availability: Real-time display of booked and available rooms
Admin Portal
Secure Admin Access: Protected admin login (admin123/pakistan123)
Room Management: View detailed room status and occupancy
Client Information: Access client details for booked rooms
Booking Overview: Complete overview of all reservations
🏨 Room Information
Total Rooms: 10
Currently Booked: Rooms 2, 6, 7, 8, 10
Available: Rooms 1, 3, 4, 5, 9
🚀 Getting Started
Prerequisites
C++ compiler (GCC, Visual Studio, Code::Blocks, etc.)
Basic knowledge of C++ programming
Installation & Running
Clone the repository
bash
git clone https://github.com/yourusername/lexus-hotel-system.git
cd lexus-hotel-system
Compile the program
bash
g++ -o hotel_system project.cpp
Run the application
bash
./hotel_system
💻 Usage
For Clients
Run the program and enter client as user type
Choose to create a new account or login to existing one
Follow prompts to book rooms and make payments
For Administrators
Run the program and enter admin as user type
Login with credentials:
Login ID: admin123
Password: pakistan123
Access room details and client information
🔧 Technical Details
Data Structure
Uses struct Client to store customer information
Static arrays for storing client data and room bookings
Maximum capacity: 10 clients
Key Functions
showRoomDetails(): Displays room availability status
inputClientDetails(): Handles new account creation
loginClient(): Manages user authentication
bookRoom(): Processes room reservations
adminPortal(): Admin dashboard functionality
clientPortal(): Client interface management
📊 Sample Data
The system comes pre-loaded with sample client data:

Asim Ali (Room 2)
Shiza Laraib (Room 6)
Haris Pasha (Room 7)
Zaki Shah (Room 8)
Areesha Shabbir (Room 10)
🔐 Default Credentials
Admin Access
Username: admin123
Password: pakistan123
Sample Client Login
User ID: client123
Password: pakistan123
🛠️ Future Enhancements
 Database integration for persistent data storage
 GUI interface using Qt or similar framework
 Online payment gateway integration
 Room pricing and billing system
 Email confirmation system
 Advanced search and filtering options
 Reporting and analytics dashboard
📁 Project Structure
lexus-hotel-system/
├── project.cpp          # Main source code
├── README.md           # Project documentation
└── .gitignore          # Git ignore file
🤝 Contributing
Fork the repository
Create a feature branch (git checkout -b feature/AmazingFeature)
Commit your changes (git commit -m 'Add some AmazingFeature')
Push to the branch (git push origin feature/AmazingFeature)
Open a Pull Request
📝 License
This project is created for educational purposes as part of Programming Fundamentals lab work.


