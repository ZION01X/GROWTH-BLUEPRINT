// ============================================================
//   FULL EXAM C++ SOLUTIONS — ALL UNIQUE QUESTION TYPES
//   Topic: Single-Level Inheritance with getdata() / putdata()
//   Pattern: 1 Base Class → 2 Derived Classes → main()
// ============================================================
// HOW TO USE THIS FILE:
//   Every question in your exam follows the EXACT same structure.
//   Learn the template once, swap names + data members per question.
//   All ~30 unique question types are solved below.
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// ============================================================
// THE UNIVERSAL TEMPLATE (memorize this!)
// ============================================================
/*
class Base {
protected:
    type1 member1;
    type2 member2;
public:
    void getdata() {
        cout << "Enter member1: "; cin >> member1;
        cout << "Enter member2: "; cin >> member2;
    }
    void putdata() {
        cout << "Member1: " << member1 << endl;
        cout << "Member2: " << member2 << endl;
    }
};

class Derived1 : public Base {
    type3 member3;
public:
    void getdata() {
        Base::getdata();
        cout << "Enter member3: "; cin >> member3;
    }
    void putdata() {
        Base::putdata();
        cout << "Member3: " << member3 << endl;
    }
};

class Derived2 : public Base {
    type4 member4;
public:
    void getdata() {
        Base::getdata();
        cout << "Enter member4: "; cin >> member4;
    }
    void putdata() {
        Base::putdata();
        cout << "Member4: " << member4 << endl;
    }
};

int main() {
    Derived1 obj1;
    Derived2 obj2;
    cout << "--- Enter Derived1 data ---\n"; obj1.getdata();
    cout << "--- Enter Derived2 data ---\n"; obj2.getdata();
    cout << "\n--- Derived1 Data ---\n";      obj1.putdata();
    cout << "\n--- Derived2 Data ---\n";      obj2.putdata();
    return 0;
}
*/


// ============================================================
// Q1: BANK ACCOUNTS — Account → Savings, Current
// ============================================================
class Account {
protected:
    string holderName;
    float balance;
public:
    void getdata() {
        cout << "Enter account holder name: "; cin >> holderName;
        cout << "Enter balance: ";             cin >> balance;
    }
    void putdata() {
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: "     << balance    << endl;
    }
};

class Savings : public Account {
    float interestRate;
public:
    void getdata() {
        Account::getdata();
        cout << "Enter interest rate: "; cin >> interestRate;
    }
    void putdata() {
        Account::putdata();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class Current : public Account {
    float overdraftLimit;
public:
    void getdata() {
        Account::getdata();
        cout << "Enter overdraft limit: "; cin >> overdraftLimit;
    }
    void putdata() {
        Account::putdata();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

void Q1_BankAccounts() {
    Savings s; Current c;
    cout << "--- Savings Account ---\n"; s.getdata();
    cout << "--- Current Account ---\n"; c.getdata();
    cout << "\n=== Savings ===\n"; s.putdata();
    cout << "\n=== Current ===\n"; c.putdata();
}


// ============================================================
// Q2: LIBRARY — LibraryItem → PrintedBook, EBook
// ============================================================
class LibraryItem {
protected:
    string title;
    int idNumber;
public:
    void getdata() {
        cout << "Enter title: ";     cin >> title;
        cout << "Enter ID number: "; cin >> idNumber;
    }
    void putdata() {
        cout << "Title: "     << title    << endl;
        cout << "ID Number: " << idNumber << endl;
    }
};

class PrintedBook : public LibraryItem {
    int pages;
public:
    void getdata() {
        LibraryItem::getdata();
        cout << "Enter number of pages: "; cin >> pages;
    }
    void putdata() {
        LibraryItem::putdata();
        cout << "Pages: " << pages << endl;
    }
};

class EBook : public LibraryItem {
    float fileSize;
public:
    void getdata() {
        LibraryItem::getdata();
        cout << "Enter file size (MB): "; cin >> fileSize;
    }
    void putdata() {
        LibraryItem::putdata();
        cout << "File Size (MB): " << fileSize << endl;
    }
};

void Q2_Library() {
    PrintedBook pb; EBook eb;
    cout << "--- Printed Book ---\n"; pb.getdata();
    cout << "--- E-Book ---\n";       eb.getdata();
    cout << "\n=== Printed Book ===\n"; pb.putdata();
    cout << "\n=== E-Book ===\n";       eb.putdata();
}


// ============================================================
// Q3: CLINIC — Staff → Doctor, Nurse
// ============================================================
class Staff {
protected:
    string staffName;
    int id;
public:
    void getdata() {
        cout << "Enter staff name: "; cin >> staffName;
        cout << "Enter ID: ";         cin >> id;
    }
    void putdata() {
        cout << "Name: " << staffName << endl;
        cout << "ID: "   << id        << endl;
    }
};

class Doctor : public Staff {
    string specialty;
public:
    void getdata() {
        Staff::getdata();
        cout << "Enter specialty: "; cin >> specialty;
    }
    void putdata() {
        Staff::putdata();
        cout << "Specialty: " << specialty << endl;
    }
};

class Nurse : public Staff {
    int shiftHours;
public:
    void getdata() {
        Staff::getdata();
        cout << "Enter shift hours per day: "; cin >> shiftHours;
    }
    void putdata() {
        Staff::putdata();
        cout << "Shift Hours/Day: " << shiftHours << endl;
    }
};

void Q3_Clinic() {
    Doctor d; Nurse n;
    cout << "--- Doctor ---\n"; d.getdata();
    cout << "--- Nurse ---\n";  n.getdata();
    cout << "\n=== Doctor ===\n"; d.putdata();
    cout << "\n=== Nurse ===\n";  n.putdata();
}


// ============================================================
// Q4: SPORTS CLUB — Member → Player, Coach
// ============================================================
class Member {
protected:
    string memberName;
    int age;
public:
    void getdata() {
        cout << "Enter name: "; cin >> memberName;
        cout << "Enter age: ";  cin >> age;
    }
    void putdata() {
        cout << "Name: " << memberName << endl;
        cout << "Age: "  << age        << endl;
    }
};

class Player : public Member {
    string position;
    int goals;
public:
    void getdata() {
        Member::getdata();
        cout << "Enter position: ";      cin >> position;
        cout << "Enter number of goals: "; cin >> goals;
    }
    void putdata() {
        Member::putdata();
        cout << "Position: " << position << endl;
        cout << "Goals: "    << goals    << endl;
    }
};

class Coach : public Member {
    int yearsExperience;
public:
    void getdata() {
        Member::getdata();
        cout << "Enter years of experience: "; cin >> yearsExperience;
    }
    void putdata() {
        Member::putdata();
        cout << "Years of Experience: " << yearsExperience << endl;
    }
};

void Q4_SportsClub() {
    Player p; Coach c;
    cout << "--- Player ---\n"; p.getdata();
    cout << "--- Coach ---\n";  c.getdata();
    cout << "\n=== Player ===\n"; p.putdata();
    cout << "\n=== Coach ===\n";  c.putdata();
}


// ============================================================
// Q5: SCHOOL WORKERS — Worker → Teacher, OfficeWorker
// ============================================================
class Worker {
protected:
    string workerName;
    int id;
public:
    void getdata() {
        cout << "Enter worker name: "; cin >> workerName;
        cout << "Enter ID: ";          cin >> id;
    }
    void putdata() {
        cout << "Name: " << workerName << endl;
        cout << "ID: "   << id         << endl;
    }
};

class Teacher : public Worker {
    int teachingHours;
public:
    void getdata() {
        Worker::getdata();
        cout << "Enter teaching hours/week: "; cin >> teachingHours;
    }
    void putdata() {
        Worker::putdata();
        cout << "Teaching Hours/Week: " << teachingHours << endl;
    }
};

class OfficeWorker : public Worker {
    int workingHours;
public:
    void getdata() {
        Worker::getdata();
        cout << "Enter working hours/week: "; cin >> workingHours;
    }
    void putdata() {
        Worker::putdata();
        cout << "Working Hours/Week: " << workingHours << endl;
    }
};

void Q5_SchoolWorkers() {
    Teacher t; OfficeWorker ow;
    cout << "--- Teacher ---\n";       t.getdata();
    cout << "--- Office Worker ---\n"; ow.getdata();
    cout << "\n=== Teacher ===\n";       t.putdata();
    cout << "\n=== Office Worker ===\n"; ow.putdata();
}


// ============================================================
// Q6: HOSPITAL PATIENTS — PatientInfo → AdultPatient, ChildPatient
// ============================================================
class PatientInfo {
protected:
    string patientName;
    string nationalId;
public:
    void getdata() {
        cout << "Enter patient name: "; cin >> patientName;
        cout << "Enter national ID: ";  cin >> nationalId;
    }
    void putdata() {
        cout << "Name: "       << patientName << endl;
        cout << "National ID: "<< nationalId  << endl;
    }
};

class AdultPatient : public PatientInfo {
    string jobTitle;
public:
    void getdata() {
        PatientInfo::getdata();
        cout << "Enter job title: "; cin >> jobTitle;
    }
    void putdata() {
        PatientInfo::putdata();
        cout << "Job Title: " << jobTitle << endl;
    }
};

class ChildPatient : public PatientInfo {
    string schoolName;
public:
    void getdata() {
        PatientInfo::getdata();
        cout << "Enter school name: "; cin >> schoolName;
    }
    void putdata() {
        PatientInfo::putdata();
        cout << "School Name: " << schoolName << endl;
    }
};

void Q6_HospitalPatients() {
    AdultPatient ap; ChildPatient cp;
    cout << "--- Adult Patient ---\n"; ap.getdata();
    cout << "--- Child Patient ---\n"; cp.getdata();
    cout << "\n=== Adult Patient ===\n"; ap.putdata();
    cout << "\n=== Child Patient ===\n"; cp.putdata();
}


// ============================================================
// Q7: PARKING — Vehicle → Car, Motorbike
// ============================================================
class Vehicle {
protected:
    string plateNumber;
    float parkingFeePerHour;
public:
    void getdata() {
        cout << "Enter plate number: ";         cin >> plateNumber;
        cout << "Enter parking fee per hour: "; cin >> parkingFeePerHour;
    }
    void putdata() {
        cout << "Plate Number: "         << plateNumber        << endl;
        cout << "Parking Fee/Hour: "     << parkingFeePerHour  << endl;
    }
};

class Car : public Vehicle {
    int doors;
public:
    void getdata() {
        Vehicle::getdata();
        cout << "Enter number of doors: "; cin >> doors;
    }
    void putdata() {
        Vehicle::putdata();
        cout << "Doors: " << doors << endl;
    }
};

class Motorbike : public Vehicle {
    int engineSize;
public:
    void getdata() {
        Vehicle::getdata();
        cout << "Enter engine size (cc): "; cin >> engineSize;
    }
    void putdata() {
        Vehicle::putdata();
        cout << "Engine Size (cc): " << engineSize << endl;
    }
};

void Q7_Parking() {
    Car car; Motorbike mb;
    cout << "--- Car ---\n";      car.getdata();
    cout << "--- Motorbike ---\n"; mb.getdata();
    cout << "\n=== Car ===\n";      car.putdata();
    cout << "\n=== Motorbike ===\n"; mb.putdata();
}


// ============================================================
// Q8: GAME CHARACTERS — Character → Warrior, Wizard
// ============================================================
class Character {
protected:
    string charName;
    int health;
public:
    void getdata() {
        cout << "Enter character name: "; cin >> charName;
        cout << "Enter health: ";         cin >> health;
    }
    void putdata() {
        cout << "Name: "   << charName << endl;
        cout << "Health: " << health   << endl;
    }
};

class Warrior : public Character {
    int strength;
public:
    void getdata() {
        Character::getdata();
        cout << "Enter strength: "; cin >> strength;
    }
    void putdata() {
        Character::putdata();
        cout << "Strength: " << strength << endl;
    }
};

class Wizard : public Character {
    int mana;
public:
    void getdata() {
        Character::getdata();
        cout << "Enter mana: "; cin >> mana;
    }
    void putdata() {
        Character::putdata();
        cout << "Mana: " << mana << endl;
    }
};

void Q8_GameCharacters() {
    Warrior w; Wizard wiz;
    cout << "--- Warrior ---\n"; w.getdata();
    cout << "--- Wizard ---\n";  wiz.getdata();
    cout << "\n=== Warrior ===\n"; w.putdata();
    cout << "\n=== Wizard ===\n";  wiz.putdata();
}


// ============================================================
// Q9: IN/OUT PATIENTS — Patient → InPatient, OutPatient
// ============================================================
class Patient {
protected:
    string patientName;
    int patientNumber;
public:
    void getdata() {
        cout << "Enter patient name: ";   cin >> patientName;
        cout << "Enter patient number: "; cin >> patientNumber;
    }
    void putdata() {
        cout << "Name: "   << patientName   << endl;
        cout << "Number: " << patientNumber << endl;
    }
};

class InPatient : public Patient {
    int daysInHospital;
    float dailyRoomCost;
public:
    void getdata() {
        Patient::getdata();
        cout << "Enter days in hospital: "; cin >> daysInHospital;
        cout << "Enter daily room cost: ";  cin >> dailyRoomCost;
    }
    void putdata() {
        Patient::putdata();
        cout << "Days in Hospital: " << daysInHospital << endl;
        cout << "Daily Room Cost: "  << dailyRoomCost  << endl;
    }
};

class OutPatient : public Patient {
    int numVisits;
    float feePerVisit;
public:
    void getdata() {
        Patient::getdata();
        cout << "Enter number of visits: "; cin >> numVisits;
        cout << "Enter fee per visit: ";     cin >> feePerVisit;
    }
    void putdata() {
        Patient::putdata();
        cout << "Number of Visits: " << numVisits  << endl;
        cout << "Fee Per Visit: "     << feePerVisit << endl;
    }
};

void Q9_InOutPatients() {
    InPatient ip; OutPatient op;
    cout << "--- In-Patient ---\n";  ip.getdata();
    cout << "--- Out-Patient ---\n"; op.getdata();
    cout << "\n=== In-Patient ===\n";  ip.putdata();
    cout << "\n=== Out-Patient ===\n"; op.putdata();
}


// ============================================================
// Q10: UNIVERSITY USERS — User → StudentUser, InstructorUser
// ============================================================
class User {
protected:
    string username;
    string password;
public:
    void getdata() {
        cout << "Enter username: "; cin >> username;
        cout << "Enter password: "; cin >> password;
    }
    void putdata() {
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
    }
};

class StudentUser : public User {
    int studentId;
public:
    void getdata() {
        User::getdata();
        cout << "Enter student ID: "; cin >> studentId;
    }
    void putdata() {
        User::putdata();
        cout << "Student ID: " << studentId << endl;
    }
};

class InstructorUser : public User {
    string officeRoom;
public:
    void getdata() {
        User::getdata();
        cout << "Enter office room: "; cin >> officeRoom;
    }
    void putdata() {
        User::putdata();
        cout << "Office Room: " << officeRoom << endl;
    }
};

void Q10_UniversityUsers() {
    StudentUser su; InstructorUser iu;
    cout << "--- Student User ---\n";     su.getdata();
    cout << "--- Instructor User ---\n";  iu.getdata();
    cout << "\n=== Student User ===\n";     su.putdata();
    cout << "\n=== Instructor User ===\n";  iu.putdata();
}


// ============================================================
// Q11: ONLINE SHOP — Product → PhysicalProduct, DigitalProduct
// ============================================================
class Product {
protected:
    string productName;
    float basePrice;
public:
    void getdata() {
        cout << "Enter product name: "; cin >> productName;
        cout << "Enter base price: ";   cin >> basePrice;
    }
    void putdata() {
        cout << "Product Name: " << productName << endl;
        cout << "Base Price: "   << basePrice   << endl;
    }
};

class PhysicalProduct : public Product {
    float weightKg;
public:
    void getdata() {
        Product::getdata();
        cout << "Enter weight (kg): "; cin >> weightKg;
    }
    void putdata() {
        Product::putdata();
        cout << "Weight (kg): " << weightKg << endl;
    }
};

class DigitalProduct : public Product {
    float fileSizeMB;
public:
    void getdata() {
        Product::getdata();
        cout << "Enter file size (MB): "; cin >> fileSizeMB;
    }
    void putdata() {
        Product::putdata();
        cout << "File Size (MB): " << fileSizeMB << endl;
    }
};

void Q11_OnlineShop() {
    PhysicalProduct pp; DigitalProduct dp;
    cout << "--- Physical Product ---\n"; pp.getdata();
    cout << "--- Digital Product ---\n";  dp.getdata();
    cout << "\n=== Physical Product ===\n"; pp.putdata();
    cout << "\n=== Digital Product ===\n";  dp.putdata();
}


// ============================================================
// Q12: LANGUAGE SCHOOL — Student → LocalStudent, ForeignStudent
// ============================================================
class Student {
protected:
    string studentName;
    string level;
public:
    void getdata() {
        cout << "Enter student name: "; cin >> studentName;
        cout << "Enter level: ";        cin >> level;
    }
    void putdata() {
        cout << "Name: "  << studentName << endl;
        cout << "Level: " << level       << endl;
    }
};

class LocalStudent : public Student {
    string cityName;
public:
    void getdata() {
        Student::getdata();
        cout << "Enter city name: "; cin >> cityName;
    }
    void putdata() {
        Student::putdata();
        cout << "City: " << cityName << endl;
    }
};

class ForeignStudent : public Student {
    string countryName;
public:
    void getdata() {
        Student::getdata();
        cout << "Enter country name: "; cin >> countryName;
    }
    void putdata() {
        Student::putdata();
        cout << "Country: " << countryName << endl;
    }
};

void Q12_LanguageSchool() {
    LocalStudent ls; ForeignStudent fs;
    cout << "--- Local Student ---\n";   ls.getdata();
    cout << "--- Foreign Student ---\n"; fs.getdata();
    cout << "\n=== Local Student ===\n";   ls.putdata();
    cout << "\n=== Foreign Student ===\n"; fs.putdata();
}


// ============================================================
// Q13: SCHOOL LIBRARY — Item → Book, Magazine
// ============================================================
class Item {
protected:
    string title;
    int yearOfPublication;
public:
    void getdata() {
        cout << "Enter title: ";               cin >> title;
        cout << "Enter year of publication: "; cin >> yearOfPublication;
    }
    void putdata() {
        cout << "Title: "               << title             << endl;
        cout << "Year of Publication: " << yearOfPublication << endl;
    }
};

class Book : public Item {
    int numPages;
public:
    void getdata() {
        Item::getdata();
        cout << "Enter number of pages: "; cin >> numPages;
    }
    void putdata() {
        Item::putdata();
        cout << "Pages: " << numPages << endl;
    }
};

class Magazine : public Item {
    int issueNumber;
public:
    void getdata() {
        Item::getdata();
        cout << "Enter issue number: "; cin >> issueNumber;
    }
    void putdata() {
        Item::putdata();
        cout << "Issue Number: " << issueNumber << endl;
    }
};

void Q13_SchoolLibrary() {
    Book b; Magazine m;
    cout << "--- Book ---\n";     b.getdata();
    cout << "--- Magazine ---\n"; m.getdata();
    cout << "\n=== Book ===\n";     b.putdata();
    cout << "\n=== Magazine ===\n"; m.putdata();
}


// ============================================================
// Q14: CAR SHOWROOM — CarModel → PetrolCar, ElectricCar
// ============================================================
class CarModel {
protected:
    string modelName;
    float basePrice;
public:
    void getdata() {
        cout << "Enter model name: "; cin >> modelName;
        cout << "Enter base price: "; cin >> basePrice;
    }
    void putdata() {
        cout << "Model Name: " << modelName << endl;
        cout << "Base Price: " << basePrice << endl;
    }
};

class PetrolCar : public CarModel {
    float engineSizeLiters;
public:
    void getdata() {
        CarModel::getdata();
        cout << "Enter engine size (liters): "; cin >> engineSizeLiters;
    }
    void putdata() {
        CarModel::putdata();
        cout << "Engine Size (L): " << engineSizeLiters << endl;
    }
};

class ElectricCar : public CarModel {
    float batteryKWh;
public:
    void getdata() {
        CarModel::getdata();
        cout << "Enter battery capacity (kWh): "; cin >> batteryKWh;
    }
    void putdata() {
        CarModel::putdata();
        cout << "Battery (kWh): " << batteryKWh << endl;
    }
};

void Q14_CarShowroom() {
    PetrolCar pc; ElectricCar ec;
    cout << "--- Petrol Car ---\n";   pc.getdata();
    cout << "--- Electric Car ---\n"; ec.getdata();
    cout << "\n=== Petrol Car ===\n";   pc.putdata();
    cout << "\n=== Electric Car ===\n"; ec.putdata();
}


// ============================================================
// Q15: HOSPITAL ROOMS — HospitalRoom → GeneralRoom, ICURoom
// ============================================================
class HospitalRoom {
protected:
    int roomNumber;
    int floor;
public:
    void getdata() {
        cout << "Enter room number: "; cin >> roomNumber;
        cout << "Enter floor: ";       cin >> floor;
    }
    void putdata() {
        cout << "Room Number: " << roomNumber << endl;
        cout << "Floor: "       << floor      << endl;
    }
};

class GeneralRoom : public HospitalRoom {
    int numBeds;
public:
    void getdata() {
        HospitalRoom::getdata();
        cout << "Enter number of beds: "; cin >> numBeds;
    }
    void putdata() {
        HospitalRoom::putdata();
        cout << "Number of Beds: " << numBeds << endl;
    }
};

class ICURoom : public HospitalRoom {
    int numMonitors;
public:
    void getdata() {
        HospitalRoom::getdata();
        cout << "Enter number of monitors: "; cin >> numMonitors;
    }
    void putdata() {
        HospitalRoom::putdata();
        cout << "Number of Monitors: " << numMonitors << endl;
    }
};

void Q15_HospitalRooms() {
    GeneralRoom gr; ICURoom icu;
    cout << "--- General Room ---\n"; gr.getdata();
    cout << "--- ICU Room ---\n";     icu.getdata();
    cout << "\n=== General Room ===\n"; gr.putdata();
    cout << "\n=== ICU Room ===\n";     icu.putdata();
}


// ============================================================
// Q16: MOBILE SHOP — Device → Phone, Tablet
// ============================================================
class Device {
protected:
    string modelName;
    float basePrice;
public:
    void getdata() {
        cout << "Enter model name: "; cin >> modelName;
        cout << "Enter base price: "; cin >> basePrice;
    }
    void putdata() {
        cout << "Model Name: " << modelName << endl;
        cout << "Base Price: " << basePrice << endl;
    }
};

class Phone : public Device {
    int simCards;
public:
    void getdata() {
        Device::getdata();
        cout << "Enter number of SIM cards: "; cin >> simCards;
    }
    void putdata() {
        Device::putdata();
        cout << "SIM Cards: " << simCards << endl;
    }
};

class Tablet : public Device {
    float screenSizeInches;
public:
    void getdata() {
        Device::getdata();
        cout << "Enter screen size (inches): "; cin >> screenSizeInches;
    }
    void putdata() {
        Device::putdata();
        cout << "Screen Size (inches): " << screenSizeInches << endl;
    }
};

void Q16_MobileShop() {
    Phone ph; Tablet tab;
    cout << "--- Phone ---\n";  ph.getdata();
    cout << "--- Tablet ---\n"; tab.getdata();
    cout << "\n=== Phone ===\n";  ph.putdata();
    cout << "\n=== Tablet ===\n"; tab.putdata();
}


// ============================================================
// Q17: DELIVERY — Shipment → Letter, Parcel
// ============================================================
class Shipment {
protected:
    string trackingNumber;
    float baseCost;
public:
    void getdata() {
        cout << "Enter tracking number: "; cin >> trackingNumber;
        cout << "Enter base cost: ";       cin >> baseCost;
    }
    void putdata() {
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Base Cost: "       << baseCost       << endl;
    }
};

class Letter : public Shipment {
    float weightGrams;
public:
    void getdata() {
        Shipment::getdata();
        cout << "Enter weight (grams): "; cin >> weightGrams;
    }
    void putdata() {
        Shipment::putdata();
        cout << "Weight (g): " << weightGrams << endl;
    }
};

class Parcel : public Shipment {
    float weightKg;
    float lengthCm;
public:
    void getdata() {
        Shipment::getdata();
        cout << "Enter weight (kg): ";         cin >> weightKg;
        cout << "Enter length (centimeters): "; cin >> lengthCm;
    }
    void putdata() {
        Shipment::putdata();
        cout << "Weight (kg): "  << weightKg << endl;
        cout << "Length (cm): "  << lengthCm << endl;
    }
};

void Q17_Delivery() {
    Letter l; Parcel p;
    cout << "--- Letter ---\n"; l.getdata();
    cout << "--- Parcel ---\n"; p.getdata();
    cout << "\n=== Letter ===\n"; l.putdata();
    cout << "\n=== Parcel ===\n"; p.putdata();
}


// ============================================================
// Q18: TRANSPORT — Vehicle2 → Bus, Truck
// ============================================================
class Vehicle2 {
protected:
    string vehicleId;
    float rentPerDay;
public:
    void getdata() {
        cout << "Enter vehicle ID: ";       cin >> vehicleId;
        cout << "Enter rent per day: ";     cin >> rentPerDay;
    }
    void putdata() {
        cout << "Vehicle ID: "   << vehicleId  << endl;
        cout << "Rent/Day: "     << rentPerDay << endl;
    }
};

class Bus : public Vehicle2 {
    int numSeats;
public:
    void getdata() {
        Vehicle2::getdata();
        cout << "Enter number of seats: "; cin >> numSeats;
    }
    void putdata() {
        Vehicle2::putdata();
        cout << "Seats: " << numSeats << endl;
    }
};

class Truck : public Vehicle2 {
    float maxLoadTons;
public:
    void getdata() {
        Vehicle2::getdata();
        cout << "Enter max load (tons): "; cin >> maxLoadTons;
    }
    void putdata() {
        Vehicle2::putdata();
        cout << "Max Load (tons): " << maxLoadTons << endl;
    }
};

void Q18_Transport() {
    Bus bus; Truck truck;
    cout << "--- Bus ---\n";   bus.getdata();
    cout << "--- Truck ---\n"; truck.getdata();
    cout << "\n=== Bus ===\n";   bus.putdata();
    cout << "\n=== Truck ===\n"; truck.putdata();
}


// ============================================================
// Q19: CINEMA — Ticket → NormalTicket, VipTicket
// ============================================================
class Ticket {
protected:
    int ticketNumber;
    float basePrice;
public:
    void getdata() {
        cout << "Enter ticket number: "; cin >> ticketNumber;
        cout << "Enter base price: ";    cin >> basePrice;
    }
    void putdata() {
        cout << "Ticket Number: " << ticketNumber << endl;
        cout << "Base Price: "    << basePrice    << endl;
    }
};

class NormalTicket : public Ticket {
    int seatRow;
public:
    void getdata() {
        Ticket::getdata();
        cout << "Enter seat row: "; cin >> seatRow;
    }
    void putdata() {
        Ticket::putdata();
        cout << "Seat Row: " << seatRow << endl;
    }
};

class VipTicket : public Ticket {
    float vipFee;
public:
    void getdata() {
        Ticket::getdata();
        cout << "Enter VIP fee: "; cin >> vipFee;
    }
    void putdata() {
        Ticket::putdata();
        cout << "VIP Fee: " << vipFee << endl;
    }
};

void Q19_Cinema() {
    NormalTicket nt; VipTicket vt;
    cout << "--- Normal Ticket ---\n"; nt.getdata();
    cout << "--- VIP Ticket ---\n";    vt.getdata();
    cout << "\n=== Normal Ticket ===\n"; nt.putdata();
    cout << "\n=== VIP Ticket ===\n";    vt.putdata();
}


// ============================================================
// Q20: UNIVERSITY COURSES — Course → TheoryCourse, LabCourse
// ============================================================
class Course {
protected:
    string courseName;
    string courseCode;
public:
    void getdata() {
        cout << "Enter course name: "; cin >> courseName;
        cout << "Enter course code: "; cin >> courseCode;
    }
    void putdata() {
        cout << "Course Name: " << courseName << endl;
        cout << "Course Code: " << courseCode << endl;
    }
};

class TheoryCourse : public Course {
    int lectureHours;
public:
    void getdata() {
        Course::getdata();
        cout << "Enter lecture hours/week: "; cin >> lectureHours;
    }
    void putdata() {
        Course::putdata();
        cout << "Lecture Hours/Week: " << lectureHours << endl;
    }
};

class LabCourse : public Course {
    int labHours;
public:
    void getdata() {
        Course::getdata();
        cout << "Enter lab hours/week: "; cin >> labHours;
    }
    void putdata() {
        Course::putdata();
        cout << "Lab Hours/Week: " << labHours << endl;
    }
};

void Q20_UniversityCourses() {
    TheoryCourse tc; LabCourse lc;
    cout << "--- Theory Course ---\n"; tc.getdata();
    cout << "--- Lab Course ---\n";    lc.getdata();
    cout << "\n=== Theory Course ===\n"; tc.putdata();
    cout << "\n=== Lab Course ===\n";    lc.putdata();
}


// ============================================================
// Q21: COMPUTER SHOP — Computer → Laptop, Desktop
// ============================================================
class Computer {
protected:
    string brandName;
    float basePrice;
public:
    void getdata() {
        cout << "Enter brand name: "; cin >> brandName;
        cout << "Enter base price: "; cin >> basePrice;
    }
    void putdata() {
        cout << "Brand Name: " << brandName << endl;
        cout << "Base Price: " << basePrice << endl;
    }
};

class Laptop : public Computer {
    float weightKg;
public:
    void getdata() {
        Computer::getdata();
        cout << "Enter weight (kg): "; cin >> weightKg;
    }
    void putdata() {
        Computer::putdata();
        cout << "Weight (kg): " << weightKg << endl;
    }
};

class Desktop : public Computer {
    string caseType;
public:
    void getdata() {
        Computer::getdata();
        cout << "Enter case type (e.g. Mini Tower): "; cin >> caseType;
    }
    void putdata() {
        Computer::putdata();
        cout << "Case Type: " << caseType << endl;
    }
};

void Q21_ComputerShop() {
    Laptop lap; Desktop desk;
    cout << "--- Laptop ---\n";  lap.getdata();
    cout << "--- Desktop ---\n"; desk.getdata();
    cout << "\n=== Laptop ===\n";  lap.putdata();
    cout << "\n=== Desktop ===\n"; desk.putdata();
}


// ============================================================
// Q22: HOTEL — Room → NormalRoom, Suite
// ============================================================
class Room {
protected:
    int roomNumber;
    float basePricePerNight;
public:
    void getdata() {
        cout << "Enter room number: ";           cin >> roomNumber;
        cout << "Enter base price per night: ";  cin >> basePricePerNight;
    }
    void putdata() {
        cout << "Room Number: "        << roomNumber        << endl;
        cout << "Base Price/Night: "   << basePricePerNight << endl;
    }
};

class NormalRoom : public Room {
    int numBeds;
public:
    void getdata() {
        Room::getdata();
        cout << "Enter number of beds: "; cin >> numBeds;
    }
    void putdata() {
        Room::putdata();
        cout << "Number of Beds: " << numBeds << endl;
    }
};

class Suite : public Room {
    int roomsInsideSuite;
public:
    void getdata() {
        Room::getdata();
        cout << "Enter rooms inside suite: "; cin >> roomsInsideSuite;
    }
    void putdata() {
        Room::putdata();
        cout << "Rooms in Suite: " << roomsInsideSuite << endl;
    }
};

void Q22_Hotel() {
    NormalRoom nr; Suite su;
    cout << "--- Normal Room ---\n"; nr.getdata();
    cout << "--- Suite ---\n";       su.getdata();
    cout << "\n=== Normal Room ===\n"; nr.putdata();
    cout << "\n=== Suite ===\n";       su.putdata();
}


// ============================================================
// Q23: RESTAURANT — MenuItem → FoodItem, DrinkItem
// ============================================================
class MenuItem {
protected:
    string itemName;
    float basePrice;
public:
    void getdata() {
        cout << "Enter item name: ";  cin >> itemName;
        cout << "Enter base price: "; cin >> basePrice;
    }
    void putdata() {
        cout << "Item Name: "  << itemName  << endl;
        cout << "Base Price: " << basePrice << endl;
    }
};

class FoodItem : public MenuItem {
    int calories;
public:
    void getdata() {
        MenuItem::getdata();
        cout << "Enter calories: "; cin >> calories;
    }
    void putdata() {
        MenuItem::putdata();
        cout << "Calories: " << calories << endl;
    }
};

class DrinkItem : public MenuItem {
    float sizeMl;
public:
    void getdata() {
        MenuItem::getdata();
        cout << "Enter size (ml): "; cin >> sizeMl;
    }
    void putdata() {
        MenuItem::putdata();
        cout << "Size (ml): " << sizeMl << endl;
    }
};

void Q23_Restaurant() {
    FoodItem fi; DrinkItem di;
    cout << "--- Food Item ---\n";  fi.getdata();
    cout << "--- Drink Item ---\n"; di.getdata();
    cout << "\n=== Food Item ===\n";  fi.putdata();
    cout << "\n=== Drink Item ===\n"; di.putdata();
}


// ============================================================
// Q24: MUSIC STORE — Album → CDAlbum, OnlineAlbum
// ============================================================
class Album {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Enter album title: "; cin >> title;
        cout << "Enter price: ";       cin >> price;
    }
    void putdata() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class CDAlbum : public Album {
    int numTracks;
public:
    void getdata() {
        Album::getdata();
        cout << "Enter number of tracks: "; cin >> numTracks;
    }
    void putdata() {
        Album::putdata();
        cout << "Tracks: " << numTracks << endl;
    }
};

class OnlineAlbum : public Album {
    float fileSizeMB;
public:
    void getdata() {
        Album::getdata();
        cout << "Enter file size (MB): "; cin >> fileSizeMB;
    }
    void putdata() {
        Album::putdata();
        cout << "File Size (MB): " << fileSizeMB << endl;
    }
};

void Q24_MusicStore() {
    CDAlbum cd; OnlineAlbum oa;
    cout << "--- CD Album ---\n";     cd.getdata();
    cout << "--- Online Album ---\n"; oa.getdata();
    cout << "\n=== CD Album ===\n";     cd.putdata();
    cout << "\n=== Online Album ===\n"; oa.putdata();
}


// ============================================================
// Q25: MEDICAL CENTER — Employee → DoctorEmployee, ReceptionistEmployee
// ============================================================
class Employee {
protected:
    string empName;
    float salary;
public:
    void getdata() {
        cout << "Enter employee name: "; cin >> empName;
        cout << "Enter salary: ";        cin >> salary;
    }
    void putdata() {
        cout << "Name: "   << empName << endl;
        cout << "Salary: " << salary  << endl;
    }
};

class DoctorEmployee : public Employee {
    string specialty;
public:
    void getdata() {
        Employee::getdata();
        cout << "Enter specialty: "; cin >> specialty;
    }
    void putdata() {
        Employee::putdata();
        cout << "Specialty: " << specialty << endl;
    }
};

class ReceptionistEmployee : public Employee {
    string shiftTime;
public:
    void getdata() {
        Employee::getdata();
        cout << "Enter shift time: "; cin >> shiftTime;
    }
    void putdata() {
        Employee::putdata();
        cout << "Shift Time: " << shiftTime << endl;
    }
};

void Q25_MedicalCenter() {
    DoctorEmployee de; ReceptionistEmployee re;
    cout << "--- Doctor Employee ---\n";       de.getdata();
    cout << "--- Receptionist Employee ---\n"; re.getdata();
    cout << "\n=== Doctor Employee ===\n";       de.putdata();
    cout << "\n=== Receptionist Employee ===\n"; re.putdata();
}


// ============================================================
// Q26: CLINIC VISITS — Visit → NormalVisit, EmergencyVisit
// ============================================================
class Visit {
protected:
    string patientName;
    string visitDate;
public:
    void getdata() {
        cout << "Enter patient name: "; cin >> patientName;
        cout << "Enter visit date: ";   cin >> visitDate;
    }
    void putdata() {
        cout << "Patient Name: " << patientName << endl;
        cout << "Visit Date: "   << visitDate   << endl;
    }
};

class NormalVisit : public Visit {
    string doctorName;
public:
    void getdata() {
        Visit::getdata();
        cout << "Enter doctor name: "; cin >> doctorName;
    }
    void putdata() {
        Visit::putdata();
        cout << "Doctor Name: " << doctorName << endl;
    }
};

class EmergencyVisit : public Visit {
    int priorityLevel;
public:
    void getdata() {
        Visit::getdata();
        cout << "Enter priority level: "; cin >> priorityLevel;
    }
    void putdata() {
        Visit::putdata();
        cout << "Priority Level: " << priorityLevel << endl;
    }
};

void Q26_ClinicVisits() {
    NormalVisit nv; EmergencyVisit ev;
    cout << "--- Normal Visit ---\n";    nv.getdata();
    cout << "--- Emergency Visit ---\n"; ev.getdata();
    cout << "\n=== Normal Visit ===\n";    nv.putdata();
    cout << "\n=== Emergency Visit ===\n"; ev.putdata();
}


// ============================================================
// Q27: SCHOOL EXAMS — Exam → MidtermExam, FinalExam
// ============================================================
class Exam {
protected:
    string subjectName;
    string examDate;
public:
    void getdata() {
        cout << "Enter subject name: "; cin >> subjectName;
        cout << "Enter exam date: ";    cin >> examDate;
    }
    void putdata() {
        cout << "Subject Name: " << subjectName << endl;
        cout << "Exam Date: "    << examDate    << endl;
    }
};

class MidtermExam : public Exam {
    float subtotalMark;
public:
    void getdata() {
        Exam::getdata();
        cout << "Enter subtotal mark: "; cin >> subtotalMark;
    }
    void putdata() {
        Exam::putdata();
        cout << "Subtotal Mark: " << subtotalMark << endl;
    }
};

class FinalExam : public Exam {
    float totalMark;
public:
    void getdata() {
        Exam::getdata();
        cout << "Enter total mark: "; cin >> totalMark;
    }
    void putdata() {
        Exam::putdata();
        cout << "Total Mark: " << totalMark << endl;
    }
};

void Q27_SchoolExams() {
    MidtermExam me; FinalExam fe;
    cout << "--- Midterm Exam ---\n"; me.getdata();
    cout << "--- Final Exam ---\n";   fe.getdata();
    cout << "\n=== Midterm Exam ===\n"; me.putdata();
    cout << "\n=== Final Exam ===\n";   fe.putdata();
}


// ============================================================
// Q28: SCHOOL ACTIVITIES — Activity → SportActivity, ClubActivity
// ============================================================
class Activity {
protected:
    string activityName;
    string dayOfWeek;
public:
    void getdata() {
        cout << "Enter activity name: "; cin >> activityName;
        cout << "Enter day of week: ";   cin >> dayOfWeek;
    }
    void putdata() {
        cout << "Activity Name: " << activityName << endl;
        cout << "Day of Week: "   << dayOfWeek    << endl;
    }
};

class SportActivity : public Activity {
    string placeOfTraining;
public:
    void getdata() {
        Activity::getdata();
        cout << "Enter place of training: "; cin >> placeOfTraining;
    }
    void putdata() {
        Activity::putdata();
        cout << "Place of Training: " << placeOfTraining << endl;
    }
};

class ClubActivity : public Activity {
    int numMembers;
public:
    void getdata() {
        Activity::getdata();
        cout << "Enter number of members: "; cin >> numMembers;
    }
    void putdata() {
        Activity::putdata();
        cout << "Number of Members: " << numMembers << endl;
    }
};

void Q28_SchoolActivities() {
    SportActivity sa; ClubActivity ca;
    cout << "--- Sport Activity ---\n"; sa.getdata();
    cout << "--- Club Activity ---\n";  ca.getdata();
    cout << "\n=== Sport Activity ===\n"; sa.putdata();
    cout << "\n=== Club Activity ===\n";  ca.putdata();
}


// ============================================================
//   MAIN — runs all questions (comment out what you don't need)
// ============================================================
int main() {

    // To test a specific question, just call its function:
    // Q1_BankAccounts();
    // Q2_Library();
    // Q3_Clinic();
    // ... etc.

    // Demo: run Q1 as a default example
    cout << "========================================\n";
    cout << "  DEMO: Q1 - Bank Accounts\n";
    cout << "========================================\n";
    Q1_BankAccounts();

    return 0;
}

// ============================================================
// QUICK REFERENCE: All 28 unique question types
// ============================================================
// Q1  - Account      → Savings,              Current
// Q2  - LibraryItem  → PrintedBook,          EBook
// Q3  - Staff        → Doctor,               Nurse
// Q4  - Member       → Player,               Coach
// Q5  - Worker       → Teacher,              OfficeWorker
// Q6  - PatientInfo  → AdultPatient,         ChildPatient
// Q7  - Vehicle      → Car,                  Motorbike
// Q8  - Character    → Warrior,              Wizard
// Q9  - Patient      → InPatient,            OutPatient
// Q10 - User         → StudentUser,          InstructorUser
// Q11 - Product      → PhysicalProduct,      DigitalProduct
// Q12 - Student      → LocalStudent,         ForeignStudent
// Q13 - Item         → Book,                 Magazine
// Q14 - CarModel     → PetrolCar,            ElectricCar
// Q15 - HospitalRoom → GeneralRoom,          ICURoom
// Q16 - Device       → Phone,                Tablet
// Q17 - Shipment     → Letter,               Parcel
// Q18 - Vehicle2     → Bus,                  Truck
// Q19 - Ticket       → NormalTicket,         VipTicket
// Q20 - Course       → TheoryCourse,         LabCourse
// Q21 - Computer     → Laptop,               Desktop
// Q22 - Room         → NormalRoom,           Suite
// Q23 - MenuItem     → FoodItem,             DrinkItem
// Q24 - Album        → CDAlbum,              OnlineAlbum
// Q25 - Employee     → DoctorEmployee,       ReceptionistEmployee
// Q26 - Visit        → NormalVisit,          EmergencyVisit
// Q27 - Exam         → MidtermExam,          FinalExam
// Q28 - Activity     → SportActivity,        ClubActivity
// ============================================================
