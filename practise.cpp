#include <iostream>
using namespace std;

class CSE {
private:
   int age;
   int reg_no;
   string name;
   string parentage;
   int semester;
   int roll_no;
   int attendence;
   float marks[5]; 
   float percentage;

public:
   CSE() : age(0), reg_no(0), name(""), parentage(""), semester(0), roll_no(0), attendence(0), percentage(0.0) {
      for (int i = 0; i < 5; i++) {
         marks[i] = 0.0;
      }
   }

   void get_details(int i) {
      const string suffixes[] = {"st", "nd", "rd"};
    string suffix = (i < 3) ? suffixes[i] : "th"; 

    cout << "Details of student " << (i + 1) << suffix << ": " << endl;

      cout << "Enter your current age: ";
      cin >> age;
      cout << "Enter registration no: ";
      cin >> reg_no;
      cout << "Enter name: ";
      cin >> name;
      cout << "Enter parent's name: ";
      cin >> parentage;
      cout << "Enter semester: ";
      cin >> semester;
      cout << "Enter roll no: ";
      cin >> roll_no;
      cout << "Enter attendance: ";
      cin >> attendence;
      cout << "Enter marks for 5 subjects (Max Marks 100): ";
      for (int j = 0; j < 5; j++) {
         cin >> marks[j];
      }
      cout << "---------------------------------------" << endl;
   }

   void show_details() const {
      cout<<"the given details are:-"<<endl;
      cout << "Name: " << name<< endl;
      cout<< "Age: " << age<< endl; 
      cout<< "Registration No: " << reg_no<< endl;
      cout << "Parentage: " << parentage << endl;
      cout<< "Semester: " << semester << endl;
      cout<< "Roll No: " << roll_no << endl;
      cout << "Attendance: " << attendence << endl;
      cout << "Marks: ";
      for (int j = 0; j < 5; j++) {
         cout << marks[j] << " ";
      }
      cout << endl << "---------------------------------------" << endl;
   }

   void show_names() const {
      cout << name << endl;
      cout << "---------------------------------------" << endl;
   }

   void show_roll() const {
      cout << roll_no << endl;
      cout << "---------------------------------------" << endl;
   }

   void print_attendence() const {
      cout << attendence << endl;
      cout << "---------------------------------------" << endl;
   }

   void show_shortage() const {
      if (attendence < 75) {
         cout << "Roll No: " << roll_no << ", Name: " << name << ", Attendance: " << attendence << endl;
      }
      cout << "---------------------------------------" << endl;
   }

   void calculate_percentage() {
      float total = 0.0;
      for (int j = 0; j < 5; j++) {
         total += marks[j];
      }
      percentage = (total / 500) * 100;
   }

   float get_percentage() const {
      return percentage;
   }

   void show_percentage() const {
      cout << "Roll No: " << roll_no << ", Name: " << name << ", Percentage: " << percentage << "%" << endl;
      cout << "---------------------------------------" << endl;
   }

   static void show_top5(CSE studentarr[], int students) {
      for (int i = 0; i < min(5, students); i++) {
         for (int j = i + 1; j < students; j++) {
            if (studentarr[j].get_percentage() > studentarr[i].get_percentage()) {
               CSE temp = studentarr[i];
               studentarr[i] = studentarr[j];
               studentarr[j] = temp;
            }
         }
      }

      cout << "Top 5 students based on percentage: " << endl;
      for (int i = 0; i < min(5, students); i++) {
         studentarr[i].show_percentage();
      }
      cout << "---------------------------------------" << endl;
   }
     void show_90(CSE studentarr[], int students) const {
      cout << "Students with more than 90% marks: " << endl;
      for (int i = 0; i < students; i++) {
         if (studentarr[i].get_percentage() > 90) {
            cout << "Name: " << studentarr[i].name 
                 << ", Roll No: " << studentarr[i].roll_no 
                 << ", Percentage: " << studentarr[i].percentage << "%" << endl;
         }
      }
      cout << "---------------------------------------" << endl;
   }
};

int main() {
   int students;
   cout << "Enter the total number of students whose data needs to be entered: ";
   cin >> students;

   CSE studentarr[students];

   for (int i = 0; i < students; i++) {
      studentarr[i].get_details(i);
   }

   cout << "\nStudent Details:\n";
   for (int i = 0; i < students; i++) {
      studentarr[i].show_details();
   }

   cout << "\nNames of students:\n";
   for (int i = 0; i < students; i++) {
      studentarr[i].show_names();
   }

   cout << "\nRoll numbers of students:\n";
   for (int i = 0; i < students; i++) {
      studentarr[i].show_roll();
   }

   cout << "\nAttendance of students:\n";
   for (int i = 0; i < students; i++) {
      studentarr[i].print_attendence();
   }

   cout << "\nStudents with attendance shortage:\n";
   for (int i = 0; i < students; i++) {
      studentarr[i].show_shortage();
   }

   cout << "\nCalculating percentage of all students:\n";
   for (int i = 0; i < students; i++) {
      studentarr[i].calculate_percentage();
   }

   CSE::show_top5(studentarr, students);
   cout << "\n";
   studentarr[0].show_90(studentarr, students);
return 0;
}