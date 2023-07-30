#include "Database.h"

Database* Database::instance = nullptr;

Database::Database()
{
    for (int i = 0; i < countTables; i++)
    {
        lastID_table.push_back(0);
    }
    system("mkdir saves");
    nameFile_Teachers = "saves//save_teachers.bin";
    nameFile_Students = "saves//save_students.bin";
    nameFile_Groups = "saves//save_groups.bin";
    nameFile_Subjects = "saves//save_subjects.bin";
    nameFile_Lessons = "saves//save_lessons.bin";
    nameFile_Pairs = "saves//save_pairs.bin";
    nameFile_Options = "saves//save_options.bin";
}

Database* Database::getInstance()
{
   if (instance == nullptr)
      instance = new Database();
   return instance;
}

int Database::getNextID(int numberTable)
{
    if (numberTable > 5 || numberTable < 0) {
        throw "Number table more or less count table";
    }
    return lastID_table[numberTable]++;
}

void Database::save()
{
   while (true)
   {
      try
      {
         saveOptions();
         saveTeachers();
         saveStudents();
         saveGroups();
         saveSubjects();
         saveLessons();
         savePairs();
         break;
      }
      catch (const string& exeption)
      {
         if (exeption == "NOT_FOUND_OPTIONS") {
            system("mkdir saves");
            saveOptions();
         }
         else if (exeption == "NOT_FOUND_TEACHERS") {
            system("mkdir saves");
            saveTeachers();
         }
         else if (exeption == "NOT_FOUND_STUDENTS") {
            system("mkdir saves");
            saveStudents();
         }
         else if (exeption == "NOT_FOUND_GROUPS") {
            system("mkdir saves");
            saveGroups();
         }
         else if (exeption == "NOT_FOUND_SUBJECTS") {
            system("mkdir saves");
            saveSubjects();
         }
         else if (exeption == "NOT_FOUND_LESSONS") {
            system("mkdir saves");
            saveLessons();
         }
         else if (exeption == "NOT_FOUND_PAIRS") {
            system("mkdir saves");
            savePairs();
         }
      }
   }
}

void Database::load()
{
   while (true) {
      try
      {
         loadOptions();
         loadTeachers();
         loadStudents();
         loadGroups();
         loadSubjects();
         loadLessons();
         loadPairs();
         break;
      }
      catch (const string& exeption)
      {
         if (exeption == "NOT_FOUND_OPTIONS") {
            system("mkdir saves");
            system("cls");
            cout << "File not found!\n";
            system("pause");
            break;
         }
         else if (exeption == "NOT_FOUND_TEACHERS") {
            system("mkdir saves");
            system("cls");
            cout << "File not found!\n";
            system("pause");
            break;
         }
         else if (exeption == "NOT_FOUND_STUDENTS") {
            system("mkdir saves");
            system("cls");
            cout << "File not found!\n";
            system("pause");
            break;
         }
         else if (exeption == "NOT_FOUND_GROUPS") {
            system("mkdir saves");
            system("cls");
            cout << "File not found!\n";
            system("pause");
            break;
         }
         else if (exeption == "NOT_FOUND_SUBJECTS") {
            system("mkdir saves");
            system("cls");
            cout << "File not found!\n";
            system("pause");
            break;
         }
         else if (exeption == "NOT_FOUND_LESSONS") {
            system("mkdir saves");
            system("cls");
            cout << "File not found!\n";
            system("pause");
            break;
         }
         else if (exeption == "NOT_FOUND_PAIRS") {
            system("mkdir saves");
            system("cls");
            cout << "File not found!\n";
            system("pause");
            break;
         }
      }
   }
}

void Database::addTeacher(Teacher obj)
{
   if (obj.getName().empty() || obj.getSurname().empty() || obj.getPatronymic().empty())
   {
      system("cls");
      cout << "Object have not correct values!\n\n";
      system("pause");
      return;
   }
    bool flag = false;
    int nextID = 0;
    int numberTable = 0;
    if (teachers.size() == 0) {
        nextID = getNextID(numberTable);
        obj.ID = nextID;
        string login = Database::loginGenerator(obj);
        obj.login = login;
        string password;
        cout << "Придумайте пароль: ";
        getline(cin, password);
        while (password.empty()) {
           cout << "Придумайте пожалуйста пароль: ";
           getline(cin, password);
        }
        obj.password = password;
        teachers.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
        system("cls");
        cout << "Вы успешно создали аккаунт!\n";
        cout << "Ваш логин: " << obj.getLogin() << "\n";
        system("pause");
        return;
    }
    map<int, Teacher>::iterator it = teachers.begin();
    while (it != teachers.end()) {
        if (it->second == obj) {
            flag = true;
            cout << "Teacher are already in the database !\n";
            system("pause");
            return;
        }
        it++;
    }
    nextID = getNextID(numberTable);
    obj.ID = nextID;
    string login = Database::loginGenerator(obj);
    //check login in database
    it = teachers.begin();
    while (it != teachers.end())
    {
       if (it->second.getLogin() == login) {
          login = Database::loginGenerator(obj);
          it = teachers.begin();
       }
       else
          it++;
    }
    obj.login = login;
    // create password
    string password;
    cout << "Придумайте пароль: ";
    getline(cin, password);
    while (password.empty()) {
       cout << "Придумайте пожалуйста пароль: ";
       getline(cin, password);
    }
    obj.password = password;
    teachers.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
    system("cls");
    cout << "Вы успешно создали аккаунт!\n";
    cout << "Ваш логин: " << obj.getLogin() << "\n";
    system("pause");
}

void Database::addTeacherSubject(int ID, int IDSubject)
{
   map<int, Teacher>::iterator it = teachers.begin();
   while (it != teachers.end()) {
      if (it->first == ID && it->second.getIsDelete() == false) {
         // Проверка наличия предмета у преподавателя
         int length = it->second.getSubjects().size();
         for (int i = 0; i < length; i++)
         {
            if (it->second.getSubjects()[i] == IDSubject) {
               cout << "Subject already added !\n";
               system("pause");
               return;
            }
         }
         it->second.addSubject(IDSubject);
         cout << " Subject added success!\n";
         system("pause");
         return;
      }
      it++;
   }
   cout << "Teacher not found!\n";
   system("pause");
}

void Database::addAdditionalForTeacher(string first, string second, int IDTeacher)
{
   map<int, Teacher>::iterator it = teachers.begin();
   while (it != teachers.end()) {
      if (it->first == IDTeacher) {
         it->second.addAdditional(first, second);
         return;
      }
      it++;
   }
   cout << "Teacher not found!\n";
}

void Database::addStudent(Student obj)
{
   if (obj.getName().empty() || obj.getSurname().empty() || obj.getPatronymic().empty())
   {
      system("cls");
      cout << "Object have not correct values!\n\n";
      system("pause");
      return;
   }
   int nextID = 0;
   int numberTable = 1;
   if (students.size() == 0) {
      nextID = getNextID(numberTable);
      obj.ID = nextID;
      string login = Database::loginGenerator(obj);
      obj.login = login;
      // create password
      string password = "1";
      cout << "Придумайте пароль: ";
      getline(cin, password);
      while (password.empty()) {
         cout << "Придумайте пожалуйста пароль: ";
         getline(cin, password);
      }
      obj.password = password;
      students.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
      system("cls");
      cout << "Вы успешно создали аккаунт!\n";
      cout << "Ваш логин: " << obj.getLogin() << "\n";
      system("pause");
      return;
   }
   map<int, Student>::iterator it = students.begin();
   while (it != students.end()) {
      if (it->second == obj) {
         cout << "Student are already in the database !\n";
         system("pause");
         return;
      }
      it++;
   }
   nextID = getNextID(numberTable);
   obj.ID = nextID;
   string login = Database::loginGenerator(obj);
   //check login in database
   it = students.begin();
   while (it != students.end())
   {
      if (it->second.getLogin() == login) {
         login = Database::loginGenerator(obj);
         it = students.begin();
      }
      else
         it++;
   }
   obj.login = login;
   // create password
   string password = "1";
   cout << "Придумайте пароль: ";
   getline(cin, password);
   while (password.empty()) {
      cout << "Придумайте пожалуйста пароль: ";
      getline(cin, password);
   }
   obj.password = password;

   students.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
   system("cls");
   cout << "Вы успешно создали аккаунт!\n";
   cout << "Ваш логин: " << obj.getLogin() << "\n";
   //system("pause");
}

void Database::addStudentInGroup(int IDGroup, int IDStudent)
{
   if (IDGroup < 0)
   {
      cout << "ID group less 0!\n";
      system("pause");
      return;
   }
   if (IDStudent < 0) {
      cout << "ID student less 0\n";
      system("pause");
      return;
   }
   bool hasStudent = false, hasGroup = false;
   map<int, Student>::iterator itStundent = students.begin();
   while (itStundent != students.end())
   {
      if (IDStudent == itStundent->first && itStundent->second.getIDGroup() == -1 && itStundent->second.getIsDelete() == false)
      {
         hasStudent = true;
         break;
      }
         itStundent++;
   }
   if (hasStudent == false)
   {
      cout << "Student not found or already in group!\n";
      system("pause");
      return;
   }
   map<int, Group>::iterator itGroup = groups.begin();
   while (itGroup != groups.end())
   {
      if (IDGroup == itGroup->first && itGroup->second.getIsDelete() == false) {
         hasGroup = true;
         break;
      }
         itGroup++;
   }
   if (hasGroup == false) {
      cout << "Group not found!\n";
      return;
   }
   itGroup->second.addStudent(itStundent->first);
   itStundent->second.IDGroup = itGroup->first;
   cout << " Student added success!\n";
   system("pause");
}

void Database::addAdditionalForStudent(string first, string second, int IDStudent)
{
   map<int, Student>::iterator it = students.begin();
   while (it != students.end()) {
      if (it->first == IDStudent) {
         it->second.addAdditional(first, second);
         return;
      }
      it++;
   }
   cout << "Student not found!\n";
}

void Database::addGroup(Group obj)
{
   if (obj.getName().empty())
   {
      system("cls");
      cout << "Object have not correct values!\n\n";
      system("pause");
      return;
   }
   int nextID = 0;
   int numberTable = 2;
   if (groups.size() == 0) {
      nextID = getNextID(numberTable);
      obj.ID = nextID;
      groups.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
      cout << " Group added success!\n";
      system("pause");
      return;
   }
   map<int, Group>::iterator it = groups.begin();
   while (it != groups.end()) {
      if (it->second == obj) {
         cout << "Group are already in the database !\n";
         system("pause");
         return;
      }
      it++;
   }
   nextID = getNextID(numberTable);
   obj.ID = nextID;
   groups.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
   cout << " Group added success!\n";
   system("pause");
}

void Database::addSubject(Subject obj)
{
   if (obj.getName().empty())
   {
      system("cls");
      cout << "Object have not correct values!\n\n";
      system("pause");
      return;
   }
   int nextID = 0;
   int numberTable = 3;
   if (subjects.size() == 0) {
      nextID = getNextID(numberTable);
      obj.ID = nextID;
      subjects.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
      cout << " Subject added success!\n";
      system("pause");
      return;
   }
   map<int, Subject>::iterator it = subjects.begin();
   while (it != subjects.end()) {
      if (it->second == obj) {
         cout << "Subject are already in the database !\n";
         system("pause");
         return;
      }
      it++;
   }
   nextID = getNextID(numberTable);
   obj.ID = nextID;
   subjects.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
   cout << " Subject added success!\n";
   system("pause");
}

void Database::addSubjectInGroup(int IDGroup, int IDSubject)
{
   if (IDGroup < 0)
   {
      cout << "ID group less 0!\n";
      return;
   }
   if (IDSubject < 0) {
      cout << "ID subject less 0\n";
      return;
   }
   bool hasSubject = false, hasGroup = false;
   map<int, Subject>::iterator itSubject = subjects.begin();
   while (itSubject != subjects.end())
   {
      if (IDSubject == itSubject->first && itSubject->second.getIsDelete() == false)
      {
         hasSubject = true;
         break;
      }
      itSubject++;
   }
   if (hasSubject == false)
   {
      cout << "Subject not found!\n";
      system("pause");
      return;
   }
   map<int, Group>::iterator itGroup = groups.begin();
   while (itGroup != groups.end())
   {
      if (IDGroup == itGroup->first && itGroup->second.getIsDelete() == false) {
         vector<int> subjectsInGroup = itGroup->second.getSubjects();
         int length = subjectsInGroup.size();
         for (int i = 0; i < length; i++)
         {
            if (subjectsInGroup[i] == IDSubject) {
               cout << "Subject already in group!\n";
               system("pause");
               return;
            }
         }
         hasGroup = true;
         break;
      }
      itGroup++;
   }
   if (hasGroup == false) {
      cout << "Group not found!\n";
      system("pause");
      return;
   }
   itGroup->second.addSubject(itSubject->first);
   cout << " Subject added success!\n";
   system("pause");
}

void Database::addLesson(Lesson obj)
{
   if (obj.getTopic().empty())
   {
      system("cls");
      cout << "Object have not correct values!\n\n";
      system("pause");
      return;
   }
   int nextID = 0;
   int numberTable = 4;
   if (lessons.size() == 0) {
      nextID = getNextID(numberTable);
      obj.ID = nextID;
      lessons.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
      return;
   }
   map<int, Lesson>::iterator it = lessons.begin();
   while (it != lessons.end()) {
      if (it->second == obj) {
         cout << "Lesson are already in the database !\n";
         system("pause");
         return;
      }
      else if (it->second.getIDPair() == obj.getIDPair()) {
         cout << "You can't added this lesson! (Lesson with pair are already in the database !)\n";
         system("pause");
         return;
      }
      it++;
   }
   nextID = getNextID(numberTable);
   obj.ID = nextID;
   lessons.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
}

void Database::addPair(Pair obj)
{
   if (obj.getNumber() == -1)
   {
      system("cls");
      cout << "Object have not correct values!\n\n";
      system("pause");
      return;
   }
   int nextID = 0;
   int numberTable = 5;
   if (pairs.size() == 0) {
      nextID = getNextID(numberTable);
      obj.ID = nextID;
      pairs.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
      cout << " Pair added success!\n";
      system("pause");
      return;
   }
   map<int, Pair>::iterator it = pairs.begin();
   while (it != pairs.end()) {
      if (it->second == obj) {
         cout << "Pair are ALREADY in the database !\n";
         system("pause");
         return;
      }
      else if (it->second.getNumberClassroom() == obj.getNumberClassroom() &&
         (it->second.getStart() <= obj.getStart() && it->second.getFinish() >= obj.getStart() ||
            it->second.getStart() <= obj.getFinish() && it->second.getFinish() >= obj.getFinish() ||
            it->second.getStart() <= obj.getStart() && it->second.getFinish() >= obj.getFinish() ||
            it->second.getStart() >= obj.getStart() && it->second.getFinish() <= obj.getFinish()
            ))
      {
         cout << "Time in object is NOT CORRECT!\n";
         system("pause");
         return;
      }
      it++;
   }
   nextID = getNextID(numberTable);
   obj.ID = nextID;
   pairs.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
   cout << " Pair added success!\n";
   system("pause");
}

void Database::removeTeacher(int ID)
{
   if (teachers.size() == 0) {
      cout << "Teacher's table is empty\n";
      return;
   }
   map<int, Teacher>::iterator it = teachers.begin();
   while (it != teachers.end())
   {
      if (it->first == ID) {
         it->second.isDelete = true;
         return;
      }
      it++;
   }
   cout << "Teacher not found!\n";
}

void Database::removeTeacherSubject(int ID, int IDSubject)
{
   map<int, Teacher>::iterator it = teachers.begin();
   while (it != teachers.end()) {
      if (it->first == ID && it->second.getIsDelete() == false) {
         // Проверка наличия предмета у преподавателя
         int length = it->second.getSubjects().size();
         for (int i = 0; i < length; i++)
         {
            if (it->second.getSubjects()[i] == IDSubject) {
               it->second.removeSubject(IDSubject);
               cout << " Remove success!\n";
               system("pause");
               return;
            }
         }
         cout << "Subject not found!\n";
         system("pause");
         return;
      }
      it++;
   }
   cout << "Teacher not found!\n";
   system("pause");
}

void Database::removeAdditionalForTeacher(string name, int IDTeacher)
{
   map<int, Teacher>::iterator it = teachers.begin();
   while (it != teachers.end()) {
      if (it->first == IDTeacher) {
         it->second.delAdditional(name);
         return;
      }
      it++;
   }
   cout << "Teacher not found!\n";
}

void Database::removeStudent(int ID)
{
    if (students.size() == 0) {
        cout << "Student's table is empty\n";
        return;
    }
    map<int, Student>::iterator it = students.begin();
    while (it != students.end())
    {
        if (it->first == ID) {
           it->second.isDelete = true;
            return;
        }
        it++;
    }
    cout << "Student not found!\n";
}

void Database::removeStudentInGroup(int IDGroup, int IDStudent)
{
   if (IDGroup < 0)
   {
      cout << "ID group less 0!\n";
      system("pause");
      return;
   }
   if (IDStudent < 0) {
      cout << "ID student less 0\n";
      system("pause");
      return;
   }
   bool hasStudent = false, hasGroup = false;
   map<int, Student>::iterator itStundent = students.begin();
   while (itStundent != students.end())
   {
      if (IDStudent == itStundent->first && itStundent->second.getIDGroup() != -1 && itStundent->second.getIsDelete() == false)
      {
         hasStudent = true;
         break;
      }
      itStundent++;
   }
   if (hasStudent == false)
   {
      cout << "Student not found or already deleted from group!\n";
      system("pause");
      return;
   }
   map<int, Group>::iterator itGroup = groups.begin();
   while (itGroup != groups.end())
   {
      if (IDGroup == itGroup->first && itGroup->second.getIsDelete() == false) {
         hasGroup = true;
         break;
      }
      itGroup++;
   }
   if (hasGroup == false) {
      cout << "Group not found!\n";
      return;
   }
   itGroup->second.delStudent(itStundent->first);
   itStundent->second.IDGroup = -1;
   cout << "  Success student removal from group!\n";
   system("pause");
}

void Database::removeAdditionalForStudent(string name, int IDStudent)
{
   map<int, Student>::iterator it = students.begin();
   while (it != students.end()) {
      if (it->first == IDStudent) {
         it->second.delAdditional(name);
         return;
      }
      it++;
   }
   cout << "Teacher not found!\n";
}

void Database::removeGroup(int ID)
{
   if (groups.size() == 0) {
      cout << "Group's table is empty\n";
      system("pause");
      return;
   }
   map<int, Group>::iterator it = groups.begin();
   while (it != groups.end())
   {
      if (it->first == ID)
      {
         it->second.isDelete = true;
         cout << "  Success removal group!\n";
         system("pause");
         return;
      }
      it++;
   }
   cout << "Group not found!\n";
}

void Database::removeSubject(int ID)
{
    if (subjects.size() == 0) {
        cout << "Subject's table is empty\n";
        system("pause");
        return;
    }
    map<int, Subject>::iterator it = subjects.begin();
    while (it != subjects.end())
    {
        if (it->first == ID) {
           it->second.isDelete = true;
           cout << "  Success removal subject!\n";
           system("pause");
            return;
        }
        it++;
    }
    cout << "Subject not found!\n";
    system("pause");
}

void Database::removeSubjectInGroup(int IDGroup, int IDSubject)
{
   if (IDGroup < 0)
   {
      cout << "ID group less 0!\n";
      system("pause");
      return;
   }
   if (IDSubject < 0) {
      cout << "ID subject less 0\n";
      system("pause");
      return;
   }
   bool hasSubject = false;
   map<int, Subject>::iterator itSubject = subjects.begin();
   while (itSubject != subjects.end())
   {
      if (IDSubject == itSubject->first && itSubject->second.getIsDelete() == false)
      {
         hasSubject = true;
         break;
      }
      itSubject++;
   }
   if (hasSubject == false)
   {
      cout << "Subject not found!\n";
      system("pause");
      return;
   }
   map<int, Group>::iterator itGroup = groups.begin();
   while (itGroup != groups.end())
   {
      if (IDGroup == itGroup->first && itGroup->second.getIsDelete() == false) {
         vector<int> subjectsInGroup = itGroup->second.getSubjects();
         int length = subjectsInGroup.size();
         bool hasSubjectInGroup = false;
         for (int i = 0; i < length; i++)
         {
            if (subjectsInGroup[i] == IDSubject) {
               itGroup->second.delSubject(itSubject->first);
               cout << "  Success removal subject from group!\n";
               system("pause");
               return;
            }
         }
         if (hasSubjectInGroup == false) {
            cout << "Subject already deleted from group!\n";
            system("pause");
            return;
         }
         break;
      }
      itGroup++;
   }
   cout << "Group not found!\n";
   system("pause");
}

void Database::removeLesson(int ID)
{
    if (lessons.size() == 0) {
        cout << "Lesson's table is empty\n";
        return;
    }
    map<int, Lesson>::iterator it = lessons.begin();
    while (it != lessons.end())
    {
        if (it->first == ID) {
           it->second.isDelete = true;
            return;
        }
        it++;
    }
    cout << "Lesson not found!\n";
}

void Database::removePair(int ID)
{
   if (pairs.size() == 0) {
      cout << "Pair's table is empty\n";
      system("pause");
      return;
   }
   map<int, Pair>::iterator it = pairs.begin();
   while (it != pairs.end())
   {
      if (it->first == ID) {
         it->second.isDelete = true;
         cout << "  Remove pair success!\n";
         system("pause");
         return;
      }
      it++;
   }
   cout << "Pair not found!\n";
}

void Database::changeTeacherPassword(string oldPassword, string newPassword, int IDTeacher)
{
   map<int, Teacher>::iterator it = teachers.begin();
   while (it != teachers.end()) {
      if (it->first == IDTeacher) {
         it->second.changePassword(oldPassword, newPassword);
         return;
      }
      it++;
   }
   cout << "Teacher not found!\n";
}

void Database::changeStudentPassword(string oldPassword, string newPassword, int IDStudent)
{
   map<int, Student>::iterator it = students.begin();
   while (it != students.end()) {
      if (it->first == IDStudent) {
         it->second.changePassword(oldPassword, newPassword);
         return;
      }
      it++;
   }
   cout << "Teacher not found!\n";
}

Teacher Database::loginTeacher()
{
   Teacher user;
   string login, password;
   cout << "Введите логин: ";
   getline(cin, login);
   while (login.empty()) {
      cout << "Пожалуста, введите коректный логин!\n";
      cout << "Логин: ";
      getline(cin, login);
   }
   user = getTeacherByLogin(login);
   if (user.getID() == -1) {
      cout << "Пользователь не найден!\n";
      system("pause");
      return Teacher();
   }
   int countAttempt = 0;
   cout << "Введите пароль: ";
   getline(cin, password);
   while (password.empty() && user.password != password) {
      cout << "Пароли неверный!\n";
      cout << "Пароль: ";
      getline(cin, login);
      if (countAttempt >= 5) {
         return Teacher();
      }
      countAttempt++;
   }
   return user;
}

Student Database::loginStudent()
{
   Student user;
   string login, password;
   cout << "Введите логин: ";
   getline(cin, login);
   while (login.empty()) {
      cout << "Пожалуста, введите коректный логин!\n";
      cout << "Логин: ";
      getline(cin, login);
   }
   user = getStudentByLogin(login);
   if (user.getID() == -1) {
      cout << "Пользователь не найден!\n";
      system("pause");
      return Student();
   }
   int countAttempt = 0;
   cout << "Введите пароль: ";
   getline(cin, password);
   while (password.empty() || user.password != password) {
      cout << "Пароли неверный!\n";
      cout << "Пароль: ";
      getline(cin, login);
      if (countAttempt >= 5) {
         return Student();
      }
      countAttempt++;
   }
   return user;
}

string Database::loginGenerator(Person obj)
{
   string alphabet = "abcdefghijklmnopqrstuvwxyz";
   string out;
   if (obj.getSurname().size() < 4)
      out = obj.getSurname();
   else
      for (int i = 0; i < 4; i++)
      {
         out += obj.getSurname().c_str()[i];
      }
   out += "_";
   srand(time(NULL));
   int temp = rand() % 26;
   int randLetter = temp;
   out += alphabet.c_str()[randLetter];
   temp = rand() % 26;
   while (randLetter == temp)
      temp = rand() % 26;
   randLetter = temp;
   out += alphabet.c_str()[randLetter];
   out += to_string(10 + rand() % 90);
   return out;
}

string Database::getNameMonthByNumber(int number)
{
   switch (number)
   {
   case 1:
      return string("January");
      break;
   case 2:
      return string("February");
      break;
   case 3:
      return string("March");
      break;
   case 4:
      return string("April");
      break;
   case 5:
      return string("May");
      break;
   case 6:
      return string("June");
      break;
   case 7:
      return string("July");
      break;
   case 8:
      return string("August");
      break;
   case 9:
      return string("September");
      break;
   case 10:
      return string("October");
      break;
   case 11:
      return string("November");
      break;
   case 12:
      return string("December");
      break;
   }
}
