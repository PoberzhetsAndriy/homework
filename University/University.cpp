// задача: 28, група: статистика 1, ПІ: Побережець Андрій, файл містить: класи,їх атрибути та методи


#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;




// КЛАСИ:


//абстрактний клас ЛЮДИНА

class Human
{
public:
    string name;
    virtual void print() = 0;
};

//підклас ПРАЦІВНИК
class Worker : public Human
{
public:
    string profession;
    double experience;

    double salary(double rate) {
        return rate + experience * 200;
    }
    void print() override {
        cout << name << " " << profession << " " << experience << " " << endl;
    }
};

//підклас ВИКЛАДАЧ
class Lecturer : public Human
{
public:
    string profession;
    double experience;
    string degree;
    //функція що підраховує зарплату викладача
    double salary(double rate) {
        if (degree == "PhD") {
            return rate * 115 / 100 + experience * 200;
        }
        else if (degree == "PHD") {
            return rate * 130 / 100 + experience * 200;
        }
        else {
            return rate + experience * 200;
        }
    }
    //функція що виводить данні класу в консоль
    void print() override {
        cout << name << " " << profession << " " << experience << " " << degree << endl;
    }
};

//підклас СТУДЕНТ
class Student : public Human
{
public:
    // функція визначення стипендії
    double countscholarship(double avmark) {
        if (avmark >= 4.5) {
            return 2000;
        }
        else if (avmark > 4) {
            return 1500;
        }
        else {
            return 0;
        }
    }
    void print() override {
        cout << name << endl;
    }


};

//клас ЗАЛІКОВКА
class Record
{
public:
    string stud_name;

    string math_lecname;
    string physics_lecname;
    string philosophy_lecname;

    double mathmark;
    double physicsmark;
    double philosophymark;

    // функція визначення середнього балу заліковки
    double avmark() {
        return (mathmark + physicsmark + philosophymark) / 3;
    }
    void r_print() {
        cout << stud_name << " " << math_lecname << " " << physics_lecname << " " << philosophy_lecname << " "
        << mathmark << " " << physicsmark << " " << philosophymark << endl;
    }
};

//клас ПРОФЕСІЯ
class Profession
{
public:
    string prof_name;
    double prof_rate;
    
    void p_print() {
        cout << prof_name << " " << prof_rate << endl;
    }
};




//  ФУНКЦІЇ


//функуія введення інформації про працівників з клавіатури
vector<Worker> Worker_kboard_in()
{
    vector<Worker> w;
    int lec_num;
    string word;
    cout << "Workers number: " << endl;
    cin >> lec_num;

    for (int i = 0; i < lec_num; i++) {
        cout << endl << "lecturer#" + to_string(i + 1) << endl;
        
        Worker obj;
        cout << "name: ";
        cin >> word;
        obj.name = word;
        
        cout << "proffesion: ";
        cin >> word;
        obj.profession = word;
        
        cout << "experience: ";
        cin >> word;
        double d = atof(word.c_str());
        obj.experience = d;
        
        w.push_back(obj);
    }
    cout << endl;
    return w;
}

//функція зчитування інформації про працівників з файлу
vector<Worker> Worker_file_in(string fname)
{
    Worker obj;
    vector<Worker> w;
    ifstream file(fname);
    string word;
    file >> word;
    while (!file.eof()) {
        Worker obj;
        file >> word;
        obj.name = word;
        
        file >> word;
        obj.profession = word;
        
        file >> word;
        double d = atof(word.c_str());
        obj.experience = d;
        
        w.push_back(obj);
    }
    w.resize(w.size() - 1);
    return w;
}


//функуія введення інформації про викладачів з клавіатури
vector<Lecturer> Lecturers_kboard_in()
{
    vector<Lecturer> l;
    int lec_num;
    string word;
    cout << "lecturers number: " << endl;
    cin >> lec_num;

    for (int i = 0; i < lec_num; i++) {
        cout << endl << "lecturer#" + to_string(i + 1) << endl;
        
        Lecturer obj;
        cout << "name: ";
        cin >> word;
        obj.name = word;
        
        cout << "proffesion: ";
        cin >> word;
        obj.profession = word;
        
        cout << "experience: ";
        cin >> word;
        double d = atof(word.c_str());
        obj.experience = d;
        
        cout << "degree: ";
        cin >> word;
        obj.degree = word;
        
        l.push_back(obj);
    }
    cout << endl;
    return l;
}

//функція зчитування інформації про викладачів з файлу
vector<Lecturer> Lecturers_file_in(string fname)
{
    Lecturer obj;
    vector<Lecturer> l;
    ifstream file(fname);
    string word;
    file >> word;
    while (!file.eof()) {
        Lecturer obj;
        file >> word;
        obj.name = word;
        
        file >> word;
        obj.profession = word;
        
        file >> word;
        double d = atof(word.c_str());
        obj.experience = d;
        
        file >> word;
        obj.degree = word;
        
        l.push_back(obj);
    }
    l.resize(l.size() - 1);
    return l;
}


//функція введення інформації про студентів з клавіатури
vector<Student> Students_kboard_in() {
    int stud_num;
    vector<Student> s;
    string word;
    cout << "students number: ";
    cin >> stud_num;
    cout << "enter students names" << endl;
    for (int i = 0; i < stud_num; i++) {
        Student obj;
        cin >> word;
        obj.name = word;
        s.push_back(obj);
    }
    cout << endl;
    return s;
}

//функція зчитування інформації про студентів з файлу
vector<Student> Students_file_in(string fname) {
    ifstream file(fname);
    vector<Student> s;
    string word;
    file >> word;
    while (file >> word) {
        Student obj;
        obj.name = word;
        s.push_back(obj);
    }
    return s;
}


//функуія введення інформації про заліковки з клавіатури
vector<Record> Record_kboard_in()
{
    int rec_num;
    string word;
    vector<Record> r;
    cout << "records number: ";
    cin >> rec_num;

    double d;
    for (int i = 0; i < rec_num; i++) {
        cout << endl << "Record#" + to_string(i + 1) << endl;
        
        Record obj;
        
        cout << "stud_name: ";
        cin >> word;
        obj.stud_name = word;
        
        cout << "math_lecname: ";
        cin >> word;
        obj.math_lecname = word;
        
        cout << "physics_lecname: ";
        cin >> word;
        obj.physics_lecname = word;
        
        cout << "philosophy_lecname: ";
        cin >> word;
        obj.philosophy_lecname = word;
        
        cout << "mathmark: ";
        cin >> word;
        d = atof(word.c_str());
        obj.mathmark = d;
        
        cout << "physicsmark: ";
        cin >> word;
        d = atof(word.c_str());
        obj.physicsmark = d;
        
        cout << "philosophymark: ";
        cin >> word;
        d = atof(word.c_str());
        obj.philosophymark = d;
        
        r.push_back(obj);
    }
    cout << endl;
    return r;
}

//функція зчитування інформації про заліковки з файлу
vector<Record> Record_file_in(string fname)
{
    Record obj;
    vector<Record> r;
    ifstream file(fname);
    string word;
    file >> word;
    double d;
    while (!file.eof()) {
        Record obj;
     
        file >> word;
        obj.stud_name = word;
        
        file >> word;
        obj.math_lecname = word;
        
        file >> word;
        obj.physics_lecname = word;
        
        file >> word;
        obj.philosophy_lecname = word;
        
        
        file >> word;
        d = atof(word.c_str());
        obj.mathmark = d;
        
        file >> word;
        d = atof(word.c_str());
        obj.physicsmark = d;
        
        file >> word;
        d = atof(word.c_str());
        obj.philosophymark = d;
        
        r.push_back(obj);
    }
    r.resize(r.size() -1);
    return r;
}


//функуія введення інформації про професії з клавіатури
vector<Profession> Profession_kboard_in()
{
    int prof_num;
    string word;
    vector<Profession> p;
    cout << "professions number: " << endl;
    cin >> prof_num;
    double d;

    for (int i = 0; i < prof_num; i++) {
        Profession obj;
        
        cout << endl << "Profession#" + to_string(i + 1) << endl;

        cout << "profession: ";
        cin >> word;
        obj.prof_name = word;

        cout << "rate: ";
        cin >> word;
        d = atof(word.c_str());
        obj.prof_rate = d;
        
        p.push_back(obj);
    }
    cout << endl;
    return p;
}

//функція зчитування інформації про професії з файлу
vector<Profession> Profession_file_in(string fname)
{
    ifstream file(fname);
    string word;
    vector<Profession> p;
    double d;
    file >> word;
    for (int i = 0; i < 5; i++) {
        Profession obj;
        
        file >> word;
        obj.prof_name = word;
        
        file >> word;
        d = atof(word.c_str());
        obj.prof_rate = d;
        
        p.push_back(obj);
    }
    return p;
}


// ТЕСТУВАННЯ

int main()
{
    bool method;
    vector<Worker> w;
    vector<Lecturer> l;
    vector<Student> s;
    vector<Record> r;
    vector<Profession> p;


    cout << "choose method of input: kboard 1, file 0  " << endl;
    cin >> method;
    cout << endl;

    if (method == 1) {
        w = Worker_kboard_in();
        l = Lecturers_kboard_in();
        s = Students_kboard_in();
        r = Record_kboard_in();
        p = Profession_kboard_in();
    }
    else if (method == 0) {
        w = Worker_file_in("University(Worker).json");
        l = Lecturers_file_in("University(lecturers).json");
        s = Students_file_in("University(students).json");
        r = Record_file_in("University(record).json");
        p = Profession_file_in("University(profession).json");
    }

    // виведення данних обєктів класу ПРАЦІВНИК
    for (int i = 0; i < w.size() ; i++) {
        w[i].print();
    }
    cout << endl;

   // виведення данних обєктів класу ВИКЛАДАЧ
    for (int i = 0; i < l.size() ; i++) {
        l[i].print();
    }
    cout << endl;

    // виведення данних обєктів класу СТУДЕНТ
    for (int i = 0; i < s.size(); i++) {
        s[i].print();
    }
    cout << endl;

    // виведення данних обєктів класу ЗАЛІКОВКА
    for (int i = 0; i < r.size() ; i++) {
        r[i].r_print();
    }
    cout << endl;    
    
    
    // виведення данних обєктів класу ПРОФЕСІЯ
    for (int i = 0; i < p.size(); i++) {
        p[i].p_print();
    }
    cout << endl;
    
    
    //підрахунок зарплат викладачів
    cout << "Lecturers salary:" << endl;
    for (int i = 0; i < l.size() ; i++) {
        for (int j = 0; j < p.size() ; j++) {
            if(l[i].profession == p[j].prof_name){
                cout << "name: " << l[i].name << "  salary: " << l[i].salary(p[j].prof_rate) << endl;
            }
        }
    }
    cout << endl;
    
    //підрахунок зарплат працівників
    cout << "Workers salary:" << endl;
    for (int i = 0; i < w.size() ; i++) {
        for (int j = 0; j < p.size() ; j++) {
            if(w[i].profession == p[j].prof_name){
                cout << "name: " << w[i].name << "  salary: " << w[i].salary(p[j].prof_rate) << endl;
            }
        }
    }
    cout << endl;
    
    //підрахунок стипендії студентів
    cout << "Scholarship:" << endl;
    for (int i = 0; i < s.size() ; i++) {
        for (int j = 0; j < r.size() ; j++) {
            if(s[i].name == r[j].stud_name){
                cout << "name: " << s[i].name << "  scholarship: " << s[i].countscholarship(r[j].avmark()) << endl ;
            }
        }
    }
    
    
    //підрахунок середнього балу студентів що навчаються у даного викладача
    string lecturer;
    cout << endl << "enter lecturers name: ";
    cin >> lecturer;
    cout << endl << "Average marks of lecturers students:" << endl;
    
    double sum = 0;
    for (int i = 0; i < r.size(); i++) {
        if (r[i].math_lecname == lecturer || r[i].physics_lecname == lecturer || r[i].philosophy_lecname == lecturer  ){
            cout << "name: " << r[i].stud_name + " " << "average mark: " << r[i].avmark() << endl;
        }
        
    }
    cout << endl;
    
    return 0;
}