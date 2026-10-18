Donor Management System in C++

A console-based Donor Management System developed in C++ to manage donors, beneficiaries, donations, events, volunteers, resources, and financial records. The system uses file handling for persistent data storage and provides an interactive, menu-driven interface with administrator authentication.

📌 Features
🔐 1. Admin Authentication
Secure administrator login.
Change administrator passwords.
Add new administrators.
Remove existing administrators.
👥 2. Beneficiary Management
Add new beneficiary records.
Update and delete existing records.
Search beneficiaries.
View beneficiary information.
💰 3. Donation Management
Record new donations.
Update and delete donation records.
View donation history.
Generate donation receipts.
📅 4. Event Management
Create, update, and delete events.
Search and view event details.
Register participants for events.
🤝 5. Volunteer Management
Add and manage volunteer records.
Update volunteer information.
Assign tasks to volunteers.
View volunteer details.
📦 6. Resource Management
Add, update, and delete resources.
Search and view resource records.
Allocate resources to beneficiaries or activities.
Track available and remaining quantities.
📊 7. Financial Management
Record income sources and expenses.
Generate financial reports.
Track budgets and financial transactions.
Monitor income and expenditure.
💾 8. File Handling
Store records in text files.
Retrieve saved data when the application restarts.
Maintain persistent records using C++ file streams.
🎨 9. Console Interface
Interactive, menu-driven interface.
Colored console text for improved readability.
Organized menus for easy navigation.
🛠️ Technologies Used
Programming Language: C++
Programming Paradigm: Object-Oriented Programming (OOP)
File Handling: ifstream and ofstream
Standard Template Library (STL): string
Console Interface: Windows Console API
Data Storage: Text files
📚 Concepts Demonstrated

This project demonstrates the practical implementation of the following programming concepts:

Object-Oriented Programming (OOP)
Classes and objects
File handling and data persistence
CRUD operations (Create, Read, Update, Delete)
Administrator authentication
Menu-driven programming
Data management and record processing
Basic financial calculations and reporting
Console-based user interface design
🚀 Getting Started
Prerequisites

Before running the project, ensure that you have:

A C++ compiler, such as MinGW or GCC.
An IDE or code editor, such as Visual Studio or Visual Studio Code.
A Windows environment for full compatibility with the Windows Console API.
Installation and Execution

1. Clone the repository

git clone https://github.com/YOUR-USERNAME/YOUR-REPOSITORY.git


2. Navigate to the project directory

cd YOUR-REPOSITORY


3. Compile the source code

If your main source file is named main.cpp, compile it using:

g++ main.cpp -o DonorManagementSystem


4. Run the application

DonorManagementSystem.exe

Note: Replace the repository URL, directory name, and source filename with the actual values used in your project. If the project contains multiple .cpp files, include all required source files during compilation.
📁 Data Storage

The system uses text files to store and retrieve application data. This allows records to remain available between application sessions without requiring a database.

Depending on the implementation, separate files can be used to store:

Administrator information
Beneficiary records
Donation records
Event details
Volunteer information
Resource records
Financial transactions
🔮 Future Improvements
Implement stronger password security and secure credential storage.
Introduce role-based access control for administrators and other users.
Improve input validation and error handling.
Replace text-file storage with a relational database, such as MySQL or SQLite.
Develop a graphical user interface (GUI).
Generate detailed donation receipts and financial reports.
Add data backup and recovery functionality.
Improve reporting and search capabilities.
🎯 Project Objective

The primary objective of this project is to demonstrate how C++ can be used to develop a practical management system using object-oriented programming, file handling, authentication, and CRUD operations.

It is designed as an academic project for students who want to strengthen their understanding of C++ programming and apply software development fundamentals to a real-world management scenario.

👨‍💻 Author

Ahmad Bilal

📄 License

This project is intended for educational and learning purposes. Add a suitable open-source license if you plan to distribute or reuse the project publicly.
