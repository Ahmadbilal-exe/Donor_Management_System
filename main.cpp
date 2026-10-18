#include<iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <string>
#include <cstdlib>
#include <limits>
     /////ahmad ///////1234        username and password
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
using namespace std;
class Beneficiary {
	private:
		string Full_Name;
        string Father_Name;
        string CNIC_Number;
        string Contact_number;
        string city_name;
        static int id;
        
	public:
	 void add_Beneficiary (){
	 	system("cls");
	 	int id= getLastID() + 1;
			cout<<"Please Enter the requrired information"<<endl;
			cout<<"Enter your full name: ";
			cin.ignore();
			getline(cin,Full_Name);
			cout<<"Enter father full name: ";
			getline(cin,Father_Name);
			cout<<"Enter CNIC number (45101-8337787-7): ";
			cin>>CNIC_Number;
			cout<<"Enter Contact number: ";
			cin>>Contact_number;
			cout<<"Enter City name: ";
			cin.ignore();
            getline(cin, city_name);
			
		ofstream file("Beneficiary.txt",ios::app);             //file handling
                file << id << "," << Full_Name << "," << Father_Name << ","
     << CNIC_Number << "," << Contact_number << "," << city_name << endl;
                
				file.close();
                cout << "Beneficiary  Added Successfully!"<<endl;	
		}
		//end of add Beneficiary ...................................................
        
        //Update Beneficiary  by ID ...........................................................
    void update_Beneficiary (){
    	system("cls");
       	int input_id;
		string id_str, name, father, cnic, contact, city;
       	bool found = false;
       	cout<<"Enter the id of user you want update her/his data: ";
       	cin>>input_id;
       	 ifstream file("Beneficiary.txt");
       	 ofstream temp("temp.txt");
                while (getline(file, id_str, ',') &&
                   getline(file, name, ',') &&
                   getline(file, father, ',') &&
                   getline(file, cnic, ',') &&
                   getline(file, contact, ',') &&
                    getline(file, city)) {
                    	
           // int file_id = stoi(id_str);
           int file_id = atoi(id_str.c_str());
                    	 
            if(file_id == input_id){
            found=true;
            cout<<"Please Enter the requrired information"<<endl;
            cin.ignore();
			cout<<"Enter full name: ";
			getline(cin,name);
			cout<<"Enter father full name: ";
			getline(cin,father);
			cout<<"Enter CNIC number (45101-8337787-7): ";
			cin>>cnic;
			cout<<"Enter Contact number: ";
			cin>>contact;
			cin.ignore();
			cout<<"Enter City name: ";
			getline(cin,city);
				 }
				 temp << file_id << "," << name << "," << father << ","
             << cnic << "," << contact << "," << city << endl;     
               }
             file.close();
             temp.close();
             remove("Beneficiary.txt");
             rename("temp.txt","Beneficiary.txt");
             if (found)
               cout<<"Updated Successfully!\n";
            else
               cout<<"ID Not Found!\n";
}
              
    //end of update Beneficiary .....................................................................
    
    //start of delet Beneficiary .........................................................................
     void delete_Beneficiary (){
     	system("cls");
       	int input_id;
		string id_str, name, father, cnic, contact, city;
       	bool found = false;
       	cout<<"Enter the id of user you want delete her/his data: ";
       	cin>>input_id;
       	 ifstream file("Beneficiary .txt");
       	 ofstream temp("temp.txt");
                while (getline(file, id_str, ',') &&
                   getline(file, name, ',') &&
                   getline(file, father, ',') &&
                   getline(file, cnic, ',') &&
                   getline(file, contact, ',') &&
                    getline(file, city)) {
         //   int file_id = stoi(id_str);
             int file_id = atoi(id_str.c_str());       	 
            if(file_id == input_id){
            found=true;
				 }else{
				  temp << file_id << "," << name << "," << father << ","
             << cnic << "," << contact << "," << city << endl;     	
				 }
               }
             file.close();
             temp.close();
             remove("Beneficiary.txt");
             rename("temp.txt","Beneficiary.txt");
             if (found)
               cout<<"deleted  Successfully!\n";
            else
               cout<<"ID Not Found!\n";
}             
    //end of delete Beneficiary.....................................................................
    
    //veiw of Beneficiary data......................................................................
    void veiw_Beneficiary (){
    system("cls");
    cout<<"Beneficiary  data...................."<<endl;
    ifstream file("Beneficiary.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
	}
	//Search Beneficiary .........................................................................
	void search_Beneficiary (){
		system("cls");
			int input_id;
		string id_str, name, father, cnic, contact, city;
       	bool found = false;
       	cout<<"Enter the id of user you want search her/his data: ";
       	cin>>input_id;
       	 ifstream file("Beneficiary.txt");
                while (getline(file, id_str, ',') &&
                   getline(file, name, ',') &&
                   getline(file, father, ',') &&
                   getline(file, cnic, ',') &&
                   getline(file, contact, ',') &&
                    getline(file, city)) {
         //   int file_id = stoi(id_str);
          int file_id = atoi(id_str.c_str());          	 
            if(file_id != input_id){
            found=true;
				 }else{
				  cout << file_id << "," << name << "," << father << ","
             << cnic << "," << contact << "," << city << endl;     	
				 }
               }
             file.close();
             if (found)
               cout<<"Found  Successfully!\n";
            else
               cout<<"ID Not Found!\n";
}             
int getLastID() {
    ifstream file("Beneficiary.txt");
    string id_str, name, father, cnic, contact, city;
    int lastID = 1999;
    while (getline(file, id_str, ',') &&
           getline(file, name, ',') &&
           getline(file, father, ',') &&
           getline(file, cnic, ',') &&
           getline(file, contact, ',') &&
           getline(file, city)) {
      //  lastID = stoi(id_str);
      lastID = atoi(id_str.c_str());
    }
    file.close();
    return lastID;
}
};
class donation{
	private:
	int id;
	string Name;
	string Type;
	int Quantity;
	string Date_Received;
	public:
	void add_donation(){
		time_t now = time(0);       
       char* dt = ctime(&now);      
        Date_Received = dt;
        cout<<"Enter the donor id:";
		cin>>id;
		cin.ignore();
		cout<<"Enter the doner name: ";
		getline(cin,Name);
		cout<<"Enter the donation type: ";
		getline(cin,Type);
		cout<<"Enter the donation Quantity/Amount: ";
		cin>>Quantity;
		ofstream file("Donation.txt",ios::app);             //file handling
                file << id << "," << Name << "," 
     << Type << "," << Quantity << "," << Date_Received << endl;
		int choic;
		cout<<"Receipt generate Enter 1:"<<endl;
		cin>>choic;
		system("cls");
		switch(choic){
			case 1:
			receipt();
	        break;	
	}
	}
void receipt(){
    cout << "========================================"<<endl;
    cout << "           DONATION RECEIPT             "<<endl;
    cout << "========================================"<<endl;
    cout << "Donor ID      : " <<id<<endl;
    cout << "Donor Name    : " <<Name<<endl;
    cout << "Type          : " << Type << endl;
    cout << "Quantity      : " << Quantity << endl;
    cout << "Date Received : " << Date_Received << endl;
    cout << "----------------------------------------"<<endl;
    cout << "        Thank You For Your Donation     "<<endl;
    cout << "========================================"<<endl;
} 
//Update Donation  by ID ...........................................................
void update_Donation() {
    system("cls");
    int input_id;
    cout<<"Enter the id of user you want to update Donation: ";
    cin>>input_id;
    cin.ignore(); 
    ifstream file("Donation.txt");
    ofstream temp("temp.txt");
    string id_str, name, type, qty_str, date;
    bool found = false;
    time_t now = time(0);
    string newDate = ctime(&now);
 //   newDate.pop_back(); 
    while (getline(file, id_str, ',') &&
           getline(file, name, ',') &&
           getline(file, type, ',') &&
           getline(file, qty_str, ',') &&
           getline(file, date)) {
    //    int file_id=stoi(id_str);
    int file_id = atoi(id_str.c_str());
    int quantity = atoi(qty_str.c_str());
      //  int quantity=atoi(qty_str);
        if (file_id==input_id) {
            found=true;
            cout<<"Enter updated donor name: ";
            getline(cin, name);
            cout<<"Enter updated donation type: ";
            getline(cin, type);
            cout<<"Enter updated quantity: ";
            cin>>quantity;
            this->id = file_id;
            this->Name = name;
            this->Type = type;
            this->Quantity = quantity;
            this->Date_Received = newDate;
            temp << file_id << "," << name << "," << type << ","
                 << quantity << "," << newDate << endl;
        }
        else {
            temp << file_id << "," << name << "," << type << ","
                 << quantity << "," << date << endl;
        }
    }
    file.close();
    temp.close();
    remove("Donation.txt");
    rename("temp.txt", "Donation.txt");
    if (found) {
        cout << "Updated Successfully!"<<endl;
        int choic;
        cout << "Generate receipt? Enter 1: ";
        cin >> choic;
        if (choic == 1) {
            system("cls");
            receipt();
        }
    } else {
        cout << "ID Not Found!"<<endl;
    }
}          
    //end of update Donation............................................
    // delete Donation............................................
    void delete_Donation() {
    system("cls");
    int input_id;
    cout<<"Enter the id of user you want to delete Donation: ";
    cin>>input_id;
    cin.ignore(); 
    ifstream file("Donation.txt");
    ofstream temp("temp.txt");
    string id_str, name, type, qty_str, date;
    bool found = false;
    time_t now = time(0);
    string newDate = ctime(&now);
   // newDate.pop_back();
if (!newDate.empty()) {
    newDate.erase(newDate.length() - 1);
}
    while (getline(file, id_str, ',') &&
           getline(file, name, ',') &&
           getline(file, type, ',') &&
           getline(file, qty_str, ',') &&
           getline(file, date)) {
     //   int file_id=stoi(id_str);
     int file_id = atoi(id_str.c_str());
        int quantity = atoi(qty_str.c_str());
        if (file_id==input_id) {
            found=true;
            continue;
        }
        else {
            temp << file_id << "," << name << "," << type << ","
                 << quantity << "," << date << endl;
        }
    }
    file.close();
    temp.close();
    remove("Donation.txt");
    rename("temp.txt", "Donation.txt");
    if (found) {
        cout << "deleted Successfully!"<<endl;
    } else {
        cout << "ID Not Found!"<<endl;
    }
}
                 //end of delete Donation............................................
      //veiw of Donation data......................................................................
    void veiw_Donation (){
    system("cls");
    cout<<"Donation  data...................."<<endl;
    ifstream file("Donation.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
	}
	//Search Donation ......................................................................... 
};
class Event {
	private:
		string Event_Name;
        string Event_Type;
        string Event_Time;
        string Event_Date;
        string Event_Location;
        static int id;
        
	public:
	 void add_Event (){
	 	system("cls");
	 	 int id=getNextEventID()+1;
			cout<<"Please Enter the requrired information"<<endl;
			cout<<"Enter Event Name: ";
			cin.ignore();
			getline(cin,Event_Name);
			cout<<"Enter Event Type: ";
			getline(cin,Event_Type);
			cout<<"Enter Event Time(hh:mm): ";
			cin>>Event_Time;
			cout<<"Enter Event Date(dd/mm/yy): ";
			cin>>Event_Date;
			cout<<"Enter Event Location: ";
			cin.ignore();
            getline(cin,Event_Location);
		ofstream file("Event.txt",ios::app);             //file handling
                file << id << "," << Event_Name << "," << Event_Type << ","
     << Event_Time << "," << Event_Date << "," << Event_Location << endl;
                
				file.close();
                cout << "Event  Added Successfully!"<<endl;	
		}
		//end of add Event ...................................................
        
        //Update Event  by ID ...........................................................
    void update_Event (){
    	system("cls");
       	int input_id;
		string id_str, Name, Type, Time, Date, Location;
       	bool found = false;
       	cout<<"Enter the id of user you want update : ";
       	cin>>input_id;
       	 ifstream file("Event.txt");
       	 ofstream temp("temp.txt");
                while (getline(file, id_str, ',') &&
                   getline(file, Name, ',') &&
                   getline(file, Type, ',') &&
                   getline(file, Time, ',') &&
                   getline(file, Date, ',') &&
                    getline(file, Location)) {
       //     int file_id = stoi(id_str);
         int file_id = atoi(id_str.c_str());           	 
            if(file_id == input_id){
            found=true;
            cout<<"Please Enter the requrired information"<<endl;
			cout<<"Enter Event Name: ";
			cin.ignore();
			getline(cin,Name);
			cout<<"Enter Event Type: ";
			getline(cin,Type);
			cout<<"Enter Event Time(hh:mm): ";
			cin>>Time;
			cout<<"Enter Event Date(dd/mm/yy): ";
			cin>>Date;
			cout<<"Enter Event Location: ";
			cin.ignore();
            getline(cin,Location);
				 }
				 temp << id << "," << Name << "," << Type << ","
     << Time << "," << Date << "," << Location << endl;  
               }
             file.close();
             temp.close();
             remove("Event.txt");
             rename("temp.txt","Event.txt");
             if (found)
               cout<<"Updated Successfully!\n";
            else
               cout<<"ID Not Found!\n";
}
              
    //end of update Event .....................................................................
    
    //start of delet Event .........................................................................
     void delete_Event (){
     	system("cls");
       	int input_id;
		string id_str, Name, Type, Time, Date, Location;
       	bool found = false;
       	cout<<"Enter the id of event you want delete: ";
       	cin>>input_id;
       	 ifstream file("Event.txt");
       	 ofstream temp("temp.txt");
                while (getline(file, id_str, ',') &&
                   getline(file, Name, ',') &&
                   getline(file, Type, ',') &&
                   getline(file, Time, ',') &&
                   getline(file, Date, ',') &&
                    getline(file, Location)) {
         //   int file_id = stoi(id_str);
          int file_id = atoi(id_str.c_str());          	 
            if(file_id == input_id){
            found=true;
				 }else{
				  temp << file_id << "," << Name << "," << Type << ","
             << Time << "," << Date << "," << Location << endl;     	
				 }
               }
             file.close();
             temp.close();
             remove("Event.txt");
             rename("temp.txt","Event.txt");
             if (found)
               cout<<"deleted  Successfully!\n";
            else
               cout<<"ID Not Found!\n";
}             
    //end of delete Event.....................................................................
    
    //veiw of Event......................................................................
    void veiw_Event (){
    system("cls");
    cout<<"Event  data...................."<<endl;
    ifstream file("Event.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
	}
	//Search Event .........................................................................
	void search_Event (){
		system("cls");
			int input_id;
		string id_str, Name, Type, Time, Date, Location;
       	bool found = false;
       	cout<<"Enter the id of event you want search: ";
       	cin>>input_id;
       	 ifstream file("Event.txt");
                while (getline(file, id_str, ',') &&
                   getline(file, Name, ',') &&
                   getline(file, Type, ',') &&
                   getline(file, Time, ',') &&
                   getline(file, Date, ',') &&
                    getline(file, Location)) {
       //     int file_id = stoi(id_str);
         int file_id = atoi(id_str.c_str());           	 
            if(file_id != input_id){
            found=true;
				 }else{
				  cout << file_id << "," << Name << "," << Type << ","
             << Time << "," << Date << "," << Location << endl;     	
				 }
               }
             file.close();
             if (found)
               cout<<"Found  Successfully!\n";
            else
               cout<<"ID Not Found!\n";
}         
int getLastID() {
    ifstream file("Event.txt");

    string id_str, name, type, time, date, location;
    int lastID = 999;

    while (getline(file, id_str, ',') &&
           getline(file, name, ',') &&
           getline(file, type, ',') &&
           getline(file, time, ',') &&
           getline(file, date, ',') &&
           getline(file, location)) {

      //  lastID = stoi(id_str);
      lastID = atoi(id_str.c_str());
    }

    file.close();
    return lastID;
}    
int getNextID() {
    ifstream file("Event.txt");
    string id_str, name, type, time, date, location;
    int lastID = 999;
    while (getline(file, id_str, ',') &&
           getline(file, name, ',') &&
           getline(file, type, ',') &&
           getline(file, time, ',') &&
           getline(file, date, ',') &&
           getline(file, location)) {
     //   lastID = stoi(id_str);
     lastID = atoi(id_str.c_str());
    }
    file.close();
    return lastID + 1;
}
void register_participation() {
    system("cls");
    int eventID;
    string participantName;
    cout<<"Enter Event ID to join: ";
    cin>>eventID;
    cin.ignore();
    cout<<"Enter Participant Name: ";
    getline(cin, participantName);
    int participantID = getNextParticipantID();
    ofstream file("Participation.txt", ios::app);
    file<<participantID<<","<<eventID<<","<<participantName<<endl;
    file.close();
    cout<<"Participation participation Successfully!"<<endl;
}
int getNextParticipantID(){
    ifstream file("Participation.txt");
    string id_str, event_id, name;
    int lastID = 0;
    while (getline(file, id_str, ',') &&
           getline(file, event_id, ',') &&
           getline(file, name)) {

      //  lastID = stoi(id_str);
      lastID = atoi(id_str.c_str());
    }
    file.close();
    return lastID + 1;
}
int getNextEventID() {
    ifstream file("Event.txt");
    string id_str, name, type, time, date, location;
    int lastID = 999;
    while (getline(file, id_str, ',') &&
           getline(file, name, ',') &&
           getline(file, type, ',') &&
           getline(file, time, ',') &&
           getline(file, date, ',') &&
           getline(file, location)) {
  //      lastID = stoi(id_str);
  lastID = atoi(id_str.c_str());
    }
    file.close();
    return lastID + 1;
}
};
class Resources{
	private:
		string Resources_Name;
        string Resources_Type;
        int Resources_Quantity;
        float Resources_Cost;
        static int id;
        
	public:
	 void add_Resources (){
	 	system("cls");
	 	int id=getNextID()+1;
			cout<<"Please Enter the requrired information"<<endl;
			cout<<"Enter Resources Name: ";
			cin.ignore();
			getline(cin,Resources_Name);
			cout<<"Enter Resources Type: ";
			getline(cin,Resources_Type);
			cout<<"Enter Resources Quantity: ";
			cin>>Resources_Quantity;
			cout<<"Enter Resources Cost: ";
			cin>>Resources_Cost;
		ofstream file("Resources.txt",ios::app);             //file handling
                file << id << "," << Resources_Name << "," << Resources_Type << ","
     << Resources_Quantity << "," << Resources_Cost << endl;
                
				file.close();
                cout << "Resources  Added Successfully!"<<endl;	
		}
		//end of add Resources ...................................................
        
        //Update Resources  by ID ...........................................................
    void update_Resources (){
    	system("cls");
       	int input_id;
		string id_str, Name, Type,Quantity,Cost ;
       	bool found = false;
       	cout<<"Enter the id of user you want update data: ";
       	cin>>input_id;
       	 ifstream file("Resources.txt");
       	 ofstream temp("temp.txt");
                while (getline(file, id_str, ',') &&
                   getline(file, Name, ',') &&
                   getline(file, Type, ',') &&
                   getline(file, Quantity, ',') &&
                   getline(file, Cost)) {
            int file_id = atof(id_str.c_str());
                    	 
            if(file_id == input_id){
            found=true;
            cout<<"Please Enter the requrired information"<<endl;
			cout<<"Enter Resources Name: ";
			cin.ignore();
			getline(cin,Name);
			cout<<"Enter Resources Type: ";
			getline(cin,Type);
			cout<<"Enter Resources Quantity: ";
			cin>>Quantity;
			cout<<"Enter Resources Cost: ";
			cin>>Cost;
				 }
				 temp << file_id << "," << Name << "," << Type << ","
             << Quantity << "," << Cost <<endl;  
               }
             file.close();
             temp.close();
             remove("Resources.txt");
             rename("temp.txt","Resources.txt");
             if (found)
               cout<<"Updated Successfully!\n";
            else
               cout<<"ID Not Found!\n";
}
              
    //end of update Resources .....................................................................
    
    //start of delet Resources .........................................................................
     void delete_Resources (){
     	system("cls");
       	int input_id;
		string id_str, Name, Type,Quantity,Cost ;
       	bool found = false;
       	cout<<"Enter the id of user you want delete  data: ";
       	cin>>input_id;
       	 ifstream file("Resources.txt");
       	 ofstream temp("temp.txt");
                while (getline(file, id_str, ',') &&
                   getline(file, Name, ',') &&
                   getline(file, Type, ',') &&
                   getline(file, Quantity, ',') &&
                   getline(file, Cost)) {
            int file_id = atof(id_str.c_str());
                    	 
            if(file_id == input_id){
            found=true;
				 }else{
				  temp << file_id << "," << Name << "," << Type << ","
             << Quantity << "," << Cost <<endl;     	
				 }
               }
             file.close();
             temp.close();
             remove("Resources.txt");
             rename("temp.txt","Resources.txt");
             if (found)
               cout<<"deleted  Successfully!\n";
            else
               cout<<"ID Not Found!\n";
}             
    //end of delete Resources.....................................................................
    
    //veiw of Resources......................................................................
    void veiw_Resources (){
    system("cls");
    cout<<"Resources  data...................."<<endl;
    ifstream file("Resources.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
	}
	//Search Resources .........................................................................
	void search_Resources (){
		system("cls");
			int input_id;
		string id_str, Name, Type,Quantity,Cost ;
       	bool found = false;
       	cout<<"Enter the id of Resources you want search : ";
       	cin>>input_id;
       	 ifstream file("Resources.txt");
                while (getline(file, id_str, ',') &&
                   getline(file, Name, ',') &&
                   getline(file, Type, ',') &&
                   getline(file, Quantity, ',') &&
                   getline(file, Cost)) {
            int file_id = atof(id_str.c_str());
                    	 
            if(file_id != input_id){
            found=true;
				 }else{
				  cout << file_id << "," << Name << "," << Type << ","
             << Quantity << "," << Cost <<endl;     	
				 }
               }
             file.close();
             if (found)
               cout<<"Found  Successfully!\n";
            else
               cout<<"ID Not Found!\n";
}             
void allocate_Resources() {
    system("cls");
    int input_id, allocate_qty;
    cout<<"Enter Resource ID to allocate: ";
    cin>>input_id;
    ifstream file("Resources.txt");
    ofstream temp("temp.txt");
    string id_str, Name, Type, Quantity, Cost;
    bool found = false;
    while (getline(file, id_str, ',') &&
           getline(file, Name, ',') &&
           getline(file, Type, ',') &&
           getline(file, Quantity, ',') &&
           getline(file, Cost)) {
        int file_id = atof(id_str.c_str());
        int quantity = atof(Quantity.c_str());
        if (file_id == input_id) {
            found = true;
            cout << "\nResource Found!\n";
            cout << "Name      : " << Name << endl;
            cout << "Type      : " << Type << endl;
            cout << "Available : " << quantity << endl;
            cout << "Enter quantity to allocate: ";
            cin >> allocate_qty;
            if (allocate_qty > quantity || allocate_qty <= 0) {
                cout << "Invalid quantity!\n";
            } else {
                quantity -= allocate_qty;
                string receiver;
                cin.ignore();
                cout << "Enter receiver name: ";
                getline(cin, receiver);
                ofstream log("Allocation.txt", ios::app);
                log << file_id << "," << Name << "," << receiver
                    << "," << allocate_qty << endl;
                log.close();
                cout << "Resource Allocated Successfully!"<<endl;;
                cout << "Allocated : " << allocate_qty << endl;
                cout << "Remaining : " << quantity << endl;
            }
        }
        temp << file_id << "," << Name << "," << Type << ","
             << quantity << "," << Cost << endl;
    }
    file.close();
    temp.close();
    remove("Resources.txt");
    rename("temp.txt", "Resources.txt");
    if (!found) {
        cout << "ID Not Found!"<<endl;
    }
}
int getNextID() {
    ifstream file("Resources.txt");
    string id_str, name, type, qty, cost;
    int lastID = 999;
    while (getline(file, id_str, ',') &&
           getline(file, name, ',') &&
           getline(file, type, ',') &&
           getline(file, qty, ',') &&
           getline(file, cost)) {
        lastID = atof(id_str.c_str());
    }
    file.close();
    return lastID + 1;
}
};

int Resources::id=1000;
class financial{
	private:
	string Expense_Name;
	string Expense_Category;
	double Expense_Cost;
	string Expense_date;
	string Expense_purpose;
	string sources_name;
	float amount_received;
	string received_Date;
	public:
 void expenses(){
		int id;
		system("cls");
			cout<<"Please Enter the requrired information"<<endl;
			cout<<"Enter Expenses Name: ";
			cin.ignore();
			getline(cin,Expense_Name);
			cout<<"Enter Expense Category: ";
			getline(cin,Expense_Category);
			cout<<"Enter Expenses Cost: ";
			cin>>Expense_Cost;
			cout<<"Enter Expense purpose: ";
			cin>>Expense_purpose;
			cout<<"Enter Expense date(dd/mm/yy): ";
			cin>>Expense_date;
		ofstream file("Expenses.txt",ios::app);             //file handling
		int id1=getNextID("Expenses.txt");
                file << id1 << "," << Expense_Name << "," << Expense_Category << ","
     << Expense_Cost << Expense_date << "," << Expense_purpose <<endl;
                
				file.close();
                cout << "Expenses  Added Successfully!"<<endl;	
		}
		//end of add Expenses ...................................................
		 //veiw of Resources......................................................................
    void veiw_Expenses (){
    system("cls");
    cout<<"Expenses  data...................."<<endl;
    ifstream file("Expenses.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
	}
	//vwei Expenses .........................................................................
    void sources(){
		int id;
		system("cls");
			cout<<"Please Enter the requrired information"<<endl;
			cout<<"Enter sources name: ";
			cin.ignore();
			getline(cin,sources_name);
			cout<<"Enter amount_received: ";
			cin>>amount_received;
			cout<<"Enter received Date(dd/mm/yy): ";
			cin>>received_Date;
		ofstream file("sources.txt",ios::app);  
		int id2 =  getNextID("sources.txt");         //file handling
                file << id2 << "," << sources_name << "," << amount_received << ","
     << received_Date << endl;
                
				file.close();
                cout << "sources  Added Successfully!"<<endl;	
		}
		//end of add Expenses ...................................................  
		int getNextID(string filename) {
  //  ifstream file(filename);
ifstream file(filename.c_str());
    string id_str, f1, f2, f3, f4; // generic fields
    int lastID = 0;
    while (getline(file, id_str, ',') &&
           getline(file, f1, ',') &&
           getline(file, f2, ',') &&
           getline(file, f3, ',') &&
           getline(file, f4)) {
     //   lastID = stoi(id_str); // last record ka ID
     lastID = atoi(id_str.c_str());
    }
    file.close();
    return lastID + 1;
}void generateReport(){
    ifstream expFile("Expenses.txt");
    ifstream srcFile("sources.txt");
    string id, name, category, cost, date, purpose;
    string s_id, s_name, s_amount, s_date;
    double totalExpenses = 0;
    double totalIncome = 0;
    while (getline(expFile, id, ',') &&
           getline(expFile, name, ',') &&
           getline(expFile, category, ',') &&
           getline(expFile, cost, ',') &&
           getline(expFile, date, ',') &&
           getline(expFile, purpose)) {
       // totalExpenses += stod(cost);   //convet string  into decimal
      totalExpenses += atof(cost.c_str());
	}
    while (getline(srcFile, s_id, ',') &&
           getline(srcFile, s_name, ',') &&
           getline(srcFile, s_amount, ',') &&
           getline(srcFile, s_date)) {
        totalIncome += atof(s_amount.c_str());
    }
    expFile.close();
    srcFile.close();
    // ===== REPORT OUTPUT =====
    cout <<"========== FINANCIAL REPORT =========="<<endl;
    cout <<"Total Income   : "<<totalIncome << endl;
    cout <<"Total Expenses : "<<totalExpenses << endl;
    double balance=totalIncome-totalExpenses;
    cout << "--------------------------------------\n";
    if(balance>0)
    cout<<"Profit         : " << balance << endl;
    else if(balance<0)
        cout<<"Loss           : " << balance << endl;
    else
        cout<<"Break Even     : 0"<<endl;
    cout << "======================================\n";
}
void trackBudget(){
    ifstream expFile("Expenses.txt");
    ifstream srcFile("sources.txt");
    string id, name, category, cost, date, purpose;
    string s_id, s_name, s_amount, s_date;
    double totalExpenses = 0;
    double totalIncome = 0;
    while (getline(expFile, id, ',') &&
           getline(expFile, name, ',') &&
           getline(expFile, category, ',') &&
           getline(expFile, cost, ',') &&
           getline(expFile, date, ',') &&
           getline(expFile, purpose)) {
        totalExpenses += atof(cost.c_str());
    }
    while (getline(srcFile, s_id, ',') &&
           getline(srcFile, s_name, ',') &&
           getline(srcFile, s_amount, ',') &&
           getline(srcFile, s_date)) {
        totalIncome += atof(s_amount.c_str());
    }
    expFile.close();
    srcFile.close();
    double remaining = totalIncome - totalExpenses;
    cout<<"====== BUDGET TRACKER ======"<<endl;
    cout<<"Total Income   : " << totalIncome << endl;
    cout<<"Total Expenses : " << totalExpenses << endl;
    cout<<"Remaining      : " << remaining << endl;

    if (remaining<0)
        cout << "?  Budget exceeded!"<<endl;
    else
        cout << "  Budget under Control"<<endl;

    cout << "============================\n";
}
};
int Event::id=1000; 
class volunteer{
	private:
		string Full_Name;
        string Father_Name;
        string CNIC_Number;
        string Contact_number;
        string city_name;
        static int id;
        
	public:
	 void add_volunteer(){
	 	system("cls");
	 	id=getLastID()+1;
			cout<<"Please Enter the requrired information"<<endl;
			cout<<"Enter your full name: ";
			cin.ignore();
			getline(cin,Full_Name);
			cout<<"Enter father full name: ";
			getline(cin,Father_Name);
			cout<<"Enter CNIC number (45101-8337787-7): ";
			cin>>CNIC_Number;
			cout<<"Enter Contact number: ";
			cin>>Contact_number;
			cout<<"Enter City name: ";
			cin.ignore();
            getline(cin, city_name);
		ofstream file("volunteer.txt",ios::app);             //file handling
                file << id << "," << Full_Name << "," << Father_Name << ","
     << CNIC_Number << "," << Contact_number << "," << city_name << endl;
                
				file.close();
                cout << "volunteer Added Successfully!"<<endl;	
		}
		//end of add volunteer...................................................
        
        //Update volunteer by ID ...........................................................
    void update_volunteer(){
    	system("cls");
       	int input_id;
		string id_str, name, father, cnic, contact, city;
       	bool found = false;
       	cout<<"Enter the id of user you want update her/his data: ";
       	cin>>input_id;
       	 ifstream file("volunteer.txt");
       	 ofstream temp("temp.txt");
                while (getline(file, id_str, ',') &&
                   getline(file, name, ',') &&
                   getline(file, father, ',') &&
                   getline(file, cnic, ',') &&
                   getline(file, contact, ',') &&
                    getline(file, city)) {
            int file_id = atof(id_str.c_str());
                    	 
            if(file_id == input_id){
            found=true;
            cout<<"Please Enter the requrired information"<<endl;
            cin.ignore();
			cout<<"Enter full name: ";
			getline(cin,name);
			cout<<"Enter father full name: ";
			getline(cin,father);
			cout<<"Enter CNIC number (45101-8337787-7): ";
			cin>>cnic;
			cout<<"Enter Contact number: ";
			cin>>contact;
			cin.ignore();
			cout<<"Enter City name: ";
			getline(cin,city);
				 }
				 temp << file_id << "," << name << "," << father << ","
             << cnic << "," << contact << "," << city << endl;     
               }
             file.close();
             temp.close();
             remove("volunteer.txt");
             rename("temp.txt","volunteer.txt");
             if (found)
               cout<<"Updated Successfully!\n";
            else
               cout<<"ID Not Found!\n";
}
              
    //end of update volunteer.....................................................................
    
    //start of delet volunteer.........................................................................
     void delete_volunteer(){
     	system("cls");
       	int input_id;
		string id_str, name, father, cnic, contact, city;
       	bool found = false;
       	cout<<"Enter the id of user you want delete her/his data: ";
       	cin>>input_id;
       	 ifstream file("volunteer.txt");
       	 ofstream temp("temp.txt");
                while (getline(file, id_str, ',') &&
                   getline(file, name, ',') &&
                   getline(file, father, ',') &&
                   getline(file, cnic, ',') &&
                   getline(file, contact, ',') &&
                    getline(file, city)) {
            int file_id = atof(id_str.c_str());
                    	 
            if(file_id == input_id){
            found=true;
				 }else{
				  temp << file_id << "," << name << "," << father << ","
             << cnic << "," << contact << "," << city << endl;     	
				 }
               }
             file.close();
             temp.close();
             remove("volunteer.txt");
             rename("temp.txt","volunteer.txt");
             if (found)
               cout<<"deleted  Successfully!\n";
            else
               cout<<"ID Not Found!\n";
}             
    //end of delete volunteer.....................................................................
    
    //veiw of volunteer data......................................................................
    void veiw_volunteer(){
    system("cls");
    cout<<"volunteer data...................."<<endl;
    ifstream file("volunteer.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
	}
	//Search volunteer.........................................................................
	void search_volunteer(){
		system("cls");
			int input_id;
		string id_str, name, father, cnic, contact, city;
       	bool found = false;
       	cout<<"Enter the id of user you want search her/his data: ";
       	cin>>input_id;
       	 ifstream file("volunteer.txt");
                while (getline(file, id_str, ',') &&
                   getline(file, name, ',') &&
                   getline(file, father, ',') &&
                   getline(file, cnic, ',') &&
                   getline(file, contact, ',') &&
                    getline(file, city)) {
            int file_id = atof(id_str.c_str());
                    	 
            if(file_id != input_id){
            found=true;
				 }else{
				  cout << file_id << "," << name << "," << father << ","
             << cnic << "," << contact << "," << city << endl;     	
				 }
               }
             file.close();
             if (found)
               cout<<"Found  Successfully!\n";
            else
               cout<<"ID Not Found!\n";
}    
int getLastID() {
    ifstream file("volunteer.txt");
    string id_str, name, father, cnic, contact, city;
    int lastID = 999;
    while (getline(file, id_str, ',') &&
           getline(file, name, ',') &&
           getline(file, father, ',') &&
           getline(file, cnic, ',') &&
           getline(file, contact, ',') &&
           getline(file, city)) {
        lastID = atof(id_str.c_str());
    }
    file.close();
    return lastID;
}   
void assign_task() {
    system("cls");
    int input_id;
    string task;
    cout << "Enter Volunteer ID to assign task: ";
    cin >> input_id;
    cin.ignore();
    ifstream file("volunteer.txt");
    ofstream temp("temp.txt");
    string id_str, name, father, cnic, contact, city;
    bool found = false;
    while (getline(file, id_str, ',') &&
           getline(file, name, ',') &&
           getline(file, father, ',') &&
           getline(file, cnic, ',') &&
           getline(file, contact, ',') &&
           getline(file, city)) {
        int file_id = atof(id_str.c_str());

        if (file_id == input_id) {
            found = true;
            cout << "Volunteer Found: " << name << endl;
            cout << "Enter Task to Assign: ";
            getline(cin, task);
            ofstream taskFile("tasks.txt", ios::app);
            taskFile << file_id << "," << name << "," << task << endl;
            taskFile.close();
            cout << "Task Assigned Successfully!\n";
        }
        temp << file_id << "," << name << "," << father << ","
             << cnic << "," << contact << "," << city << endl;
    }
    file.close();
    temp.close();
    remove("volunteer.txt");
    rename("temp.txt", "volunteer.txt");
    if (!found) {
        cout << "ID Not Found!\n";
    }
}      
};
int volunteer::id=1000; 
class Authentication{
	public:
bool adminLogin(){
    ifstream file("admin.txt");
    string u, p, user, pass;
    cout<<"username: ";
    cin>>user;
    cout<<"password: ";
    cin>>pass;
    while(getline(file, u, ',') && getline(file, p)){
if(!p.empty() && p[p.length()-1] == '\r')
    p.erase(p.length()-1);

        if(user == u && pass == p){
            cout<<"login successful!\n";
            	while(1){
		cout<<"\n\n"<<endl;
		cout<<".............................Main funcionality..........................."<<endl;
		cout<<"1.Beneficiary."<<endl;
		cout<<"2.Donation"<<endl;
		cout<<"3.Event"<<endl;
		cout<<"4.Financial"<<endl;
		cout<<"5.Resourse"<<endl;
		cout<<"6.Donor"<<endl;
		cout<<"7.EXIT"<<endl;
		 int choice1;
    cout<<"enterr the choice:";
    cin>>choice1;
    if(choice1==7){
    	break;
	}
    switch(choice1){
        case 1:{
             	int choice;
    setColor(11); // green
	cout<<"    .....................................Beneficiary  MANAGEMENT SYSTEM..........................."<<endl;
	cout<<"    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"    ::                              1.Add Beneficiary                                           ::"<<endl;
	cout<<"    ::                              2.Update Beneficiary                                        ::"<<endl;
	cout<<"    ::                              3.Delete Beneficiary                                        ::"<<endl;
	cout<<"    ::                              4.search Beneficiary                                        ::"<<endl;
	cout<<"    ::                              5.veiw  Beneficiary                                         ::"<<endl;
	cout<<"    ::                              6.exit                                                      ::"<<endl;
	cout<<"    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"Enter choice:";
	cin>>choice;
    Beneficiary  b;
    switch(choice) {
       case 1: b.add_Beneficiary(); break;
       case 2: b.update_Beneficiary (); break;
       case 3: b.delete_Beneficiary (); break;
       case 4: b.search_Beneficiary (); break;
       case 5: b.veiw_Beneficiary (); break;
       case 6: break;
       default:
       cout<<"Invalid Choice! Try again."<<endl;
}
break;
             }   //cas2 endl
             
    case 2:{
    		int choice;
    setColor(11); // green
	cout<<"    .....................................Donation  MANAGEMENT SYSTEM.............................."<<endl;
	cout<<"    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"    ::                              1.Add Donation                                              ::"<<endl;
	cout<<"    ::                              2.Update Donation                                           ::"<<endl;
	cout<<"    ::                              3.Delete Donation                                           ::"<<endl;
	cout<<"    ::                              4.veiw  Donation                                            ::"<<endl;
	cout<<"    ::                              5.exit                                                      ::"<<endl;
	cout<<"    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"Enter choice:";
	cin>>choice;
    donation  d1;
    switch(choice) {
       case 1: d1.add_donation(); break;
       case 2: d1.update_Donation (); break;
       case 3: d1.delete_Donation (); break;
       case 4: d1.veiw_Donation (); break;
       case 5: break;
       default:
       cout<<"Invalid Choice! Try again."<<endl;
}
		break;
	}         //end of case 3
	case 3:{
			int choice;
    setColor(11); // green
	cout<<"    .....................................Event  MANAGEMENT SYSTEM................................."<<endl;
	cout<<"    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"    ::                              1.Add Event                                                 ::"<<endl;
	cout<<"    ::                              2.Update Event                                              ::"<<endl;
	cout<<"    ::                              3.Delete Event                                              ::"<<endl;
	cout<<"    ::                              4.search Event                                              ::"<<endl;
	cout<<"    ::                              5.veiw Event                                                ::"<<endl;
	cout<<"    ::                              6.Register participant                                      ::"<<endl;
	cout<<"    ::                              7.EXIT                                                      ::"<<endl;
	cout<<"    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"Enter choice:";
	cin>>choice;
    Event  E;
    switch(choice) {
       case 1: E.add_Event(); break;
       case 2: E.update_Event (); break;
       case 3: E.delete_Event (); break;
       case 4: E.search_Event (); break;
       case 5: E.veiw_Event (); break;
       case 6: E.register_participation(); break;
       case 7:break;
 	    default:
       cout<<"Invalid Choice! Try again."<<endl;
}
		break;
	}     //end og caase 4
	case 4:{
			int choice;
    setColor(11); // green
	cout<<"    .....................................FINANCIAL MANAGEMENT SYSTEM.............................."<<endl;
	cout<<"    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"    ::                              1.Add expenses                                              ::"<<endl;
	cout<<"    ::                              2.Add sources                                               ::"<<endl;
	cout<<"    ::                              3.GenerateReport                                            ::"<<endl;
	cout<<"    ::                              4.TrackBudget                                               ::"<<endl;
	cout<<"    ::                              5.EXIT                                                      ::"<<endl;
	cout<<"    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"Enter choice:";
	cin>>choice;
    financial f;
    switch(choice) {
       case 1: f.expenses(); break;
       case 2: f.sources(); break;
       case 3: f.generateReport(); break;
       case 4: f.trackBudget(); break;
       case 5: break;
       default:
       cout<<"Invalid Choice! Try again."<<endl;
}
		break;
	}  //end og 5
	case 5:{
			int choice;
    setColor(11); // green
	cout<<"    .....................................Resourse  MANAGEMENT SYSTEM.............................."<<endl;
	cout<<"    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"    ::                              1.Add Resourse                                              ::"<<endl;
	cout<<"    ::                              2.Update Resourse                                           ::"<<endl;
	cout<<"    ::                              3.Delete Resourse                                           ::"<<endl;
	cout<<"    ::                              4.search Resourse                                           ::"<<endl;
	cout<<"    ::                              5.veiw Resourse                                             ::"<<endl;
	cout<<"    ::                              6.allocate_Resources                                        ::"<<endl;
	cout<<"    ::                              7.EXIT                                                      ::"<<endl;
	cout<<"    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"Enter choice:";
	cin>>choice;
    Resources  r;
    switch(choice) {
       case 1: r.add_Resources(); break;
       case 2: r.update_Resources (); break;
       case 3: r.delete_Resources (); break;
       case 4: r.search_Resources (); break;
       case 5: r.veiw_Resources (); break;
       case 6: r.allocate_Resources(); break;
       case 7:break;
       default:
       cout<<"Invalid Choice! Try again."<<endl;
}
		break;
	}   ///end og 6
	case 6  :{
			int choice;
    setColor(11); // green
	cout<<"    .....................................DONOR MANAGEMENT SYSTEM.................................."<<endl;
	cout<<"    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"    ::                              1.Add volunteer                                             ::"<<endl;
	cout<<"    ::                              2.Update volunteer                                          ::"<<endl;
	cout<<"    ::                              3.Delete volunteer                                          ::"<<endl;
	cout<<"    ::                              4.search volunteer                                          ::"<<endl;
	cout<<"    ::                              5.veiw  volunteer                                           ::"<<endl;
	cout<<"    ::                              6.Assign task to volunteer                                  ::"<<endl;
	cout<<"    ::                              7.EXIT                                                      ::"<<endl;
	cout<<"    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"Enter choice:";
	cin>>choice;
    volunteer v;
    switch(choice) {
       case 1: v.add_volunteer(); break;
       case 2: v.update_volunteer(); break;
       case 3: v.delete_volunteer(); break;
       case 4: v.search_volunteer(); break;
       case 5: v.veiw_volunteer(); break;
       case 6: v.assign_task(); break;
       case 7:break;
       default:
       cout<<"Invalid Choice! Try again."<<endl;
}
		break;
	}//endd of case 7
//	case 7:{
//		cout<<"Thanks you......................"<<endl;
//		break;
//	}
             } //switch wnd  
	}
            return true;
        }
    }

    cout<<"Invalid Login!\n";
    return false;
}
	void logout(){
		exit(0);
	}
void changePassword(){
    string oldPass,newPass;
    string user,pass;
    loadAdmin(user,pass);
    cout<<"Enter Old Password: ";
    cin>>oldPass;
    if(oldPass==pass){
        cout<<"Enter New Password: ";
        cin>>newPass;
        saveAdmin(user,newPass);
        cout<<"Password Changed Successfully!\n";
    }
    else{
        cout<<"Wrong Old Password!\n";
    }
}
	void loadAdmin(string &user,string &pass){
    ifstream file("admin.txt");
    getline(file, user, ',');
    getline(file, pass);
    file.close();
}
void saveAdmin(string user, string pass){
    ofstream file("admin.txt");
    file << user << "," << pass;
    file.close();
}
void addAdmin(){
    string user, pass;
    cout<<"Enter new admin username: ";
    cin>>user;
    cout<<"Enter password: ";
    cin>>pass;
    ofstream file("admin.txt", ios::app);
    file<<user << "," << pass << endl;
    file.close();
    cout<<"Admin added successfully!\n";
}
void removeAdmin(){
    string target;
    cout<<"Enter admin username to remove: ";
    cin>>target;
    ifstream in("admin.txt");
    ofstream out("temp.txt");
    string user, pass;
    bool found = false;
    while(getline(in, user, ',') && getline(in, pass)){
        if(user == target){
            found = true;
            continue; // skip this admin
        }
        out<<user << "," << pass << endl;
    }
    in.close();
    out.close();
    remove("admin.txt");
    rename("temp.txt", "admin.txt");
    if(found)
        cout << "Admin removed successfully!\n";
    else
        cout << "Admin not found!\n";
}
};
int main(){
setColor(11); 
cout <<"                             **********************************************\n";
cout <<"                            *                                              *\n";
cout <<"                           *                      DONOR                      *\n";
cout <<"                          *                    MANAGEMENT                     *\n";
cout <<"                           *                     SYSTEM                      *\n";
cout <<"                            *                                               *\n";
cout <<"                             ***********************************************\n";
while(1){
	           	int choice;
    setColor(11); // green
	cout<<"\n\n    .........................................Authentication......................................."<<endl;
	cout<<"    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"    ::                              1.Login                                                     ::"<<endl;
	cout<<"    ::                              2.Logout                                                    ::"<<endl;
	cout<<"    ::                              3.change_password()                                         ::"<<endl;
	cout<<"    ::                              4.Add admin                                                 ::"<<endl;
	cout<<"    ::                              5.remove admin                                              ::"<<endl;
	cout<<"    ::                              6.EXIT                                                      ::"<<endl;
	cout<<"    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"Enter choice:";
	cin>>choice;
    Authentication A;
    switch(choice) {
       case 1: A.adminLogin(); break;
       case 2: A.logout() ; break;
       case 3: A.changePassword(); break;
       case 4: A.addAdmin(); break;
       case 5: A.removeAdmin(); break;
       case 6: {
       	cout<<"THANKSYOU.........."<<endl;exit(0);
	   }
       default:
       cout<<"Invalid Choice! Try again."<<endl;
}
}
   
}
