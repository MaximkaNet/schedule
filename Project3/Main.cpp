#include "Header.h"
#include <Windows.h>

int main()
{
   Database* database = Database::getInstance();
   setlocale(LC_ALL, "RUS");
   //" Войти как: \n1. Администратор\n2. Учебная часть\n3. Преподаватель\n4. Студент\n0. Выход\n"
   database->load();
   //path bar
   PathBar pathbar1;
   pathbar1.setSeparator(" -> ");

   //120 30
   int width = 120;
   int heigth = 30;

   //current date
   Date CurrentDate;
   CurrentDate.autoFill();

   bool activeSessionTeacher = false;
   bool activeSessionStudent = false;
   Teacher currentTeacher;
   Student currentStudent;

   Menu mainMenu(pathbar1("add", " Главная"));
   mainMenu.addSection("Администратор");
   mainMenu.addSection("Учебная часть");
   mainMenu.addSection("Преподаватель");
   mainMenu.addSection("Студент");
   bool turn = true;
   int ch = 0;
   //Main loop
   while (turn)
   {
      system("cls");

      ch = mainMenu();
      switch (ch)
      {
      // admin
      case 1:
      {
         system("cls");
         Menu menuAdmin(pathbar1("add", "Администратор"));
         menuAdmin.addSection("Добавить");
         menuAdmin.addSection("Показать");
         int chAdmin = 0;
         bool turnAdmin = true;
         while (turnAdmin) {
            // show menu
            chAdmin = menuAdmin();
            switch (chAdmin)
            {
               // add
            case 1:
            {
               system("cls");
               Menu menuAdmin_add(pathbar1("add", "Добавить"));
               menuAdmin_add.addSection("Cтудента");
               menuAdmin_add.addSection("Преподавателя");
               int chAdmin_add = 0;
               bool flagAdd = true;
               while (flagAdd)
               {
                  chAdmin_add = menuAdmin_add();
                  switch (chAdmin_add)
                  {
                  case 1:
                  {
                     system("cls");
                     cout << pathbar1("add", "Студента") << "\n";
                     Student temp;
                     temp = temp.create();
                     database->addStudent(temp);
                     pathbar1("remove");
                  }
                  break;
                  case 2:
                  {
                     system("cls");
                     cout << pathbar1("add", "Преподавателя") << "\n";
                     Teacher temp;
                     temp = temp.create();
                     database->addTeacher(temp);
                     pathbar1("remove");
                  }
                  break;
                  case 0:
                     flagAdd = false;
                     break;
                  }
                  system("cls");
               }
               pathbar1("remove");
               database->save();
            }
            break;
            // show
            case 2:
            {
               system("cls");
               Menu menuAdmin_show(pathbar1("add", "Показать"));
               menuAdmin_show.addSection("Cтудентов");
               menuAdmin_show.addSection("Преподавателей");
               menuAdmin_show.addSection("Пары");
               menuAdmin_show.addSection("Группы");
               menuAdmin_show.addSection("Предметы");
               menuAdmin_show.addSection("Уроки");
               int chAdmin_add = 0;
               bool flagAdd = true;
               while (flagAdd)
               {
                  chAdmin_add = menuAdmin_show();
                  switch (chAdmin_add)
                  {
                  // show students
                  case 1:
                  {
                     system("cls");
                     cout << pathbar1("add", "Студентов") << "\n";
                     cout << "  |---------- Студенты ---------|\n";

                     vector<Student> students = database->getStudents();
                     if (students[0].getID() == -1)
                        cout << "  Студентов ещё нет в базе даных!\n";
                     else {
                        int length = students.size();
                        for (int i = 0; i < length; i++)
                        {
                           if (students[i].getIsDelete() == false) {
                              cout << "_______________________________\n";
                              cout << "Login: " << students[i].getLogin() << "\n";
                              students[i].show();
                              cout << "===============================\n\n";
                           }
                        }
                     }
                     system("pause");
                     pathbar1("remove");
                  }
                  break;
                  // show teachers
                  case 2:
                  {
                     system("cls");
                     cout << pathbar1("add", "Преподавателей") << "\n";
                     cout << "  |---------- Преподаватели ---------|\n";
                     vector<Teacher> teachers = database->getTeachers();
                     if (teachers[0].getID() == -1)
                        cout << "  Преподаваделей ещё нет в базе даных!\n";
                     else {
                        vector<Subject> subjects = database->getSubjects();
                        int length = teachers.size();
                        for (int i = 0; i < length; i++)
                        {
                           if (teachers[i].getIsDelete() == false) {
                              cout << "_______________________________\n";
                              cout << "Login: " << teachers[i].getLogin() << "\n";
                              teachers[i].show(subjects);
                              cout << "===============================\n\n";
                           }
                        }
                     }
                     system("pause");
                     pathbar1("remove");
                  }
                  break;
                  // show pair
                  case 3:
                  {
                     system("cls");
                     cout << pathbar1("add", "Пары") << "\n";
                     cout << "|---------- Пары ---------|\n";
                     vector<Pair> pairs = database->getPairs();
                     if (pairs[0].getID() == -1)
                        cout << "  Пар ещё нет в базе даных!\n";
                     else {
                        vector<Teacher> teachers = database->getTeachers();
                        vector<Subject> subjects = database->getSubjects();
                        int length = pairs.size();
                        for (int i = 0; i < length; i++)
                        {
                           if (pairs[i].getIsDelete() == false) {
                              cout << "_______________________________\n";
                              pairs[i].show(teachers, subjects);
                              cout << "===============================\n\n";
                           }
                        }
                     }
                     system("pause");
                     pathbar1("remove");
                  }
                  break;
                  // show group
                  case 4:
                  {
                     system("cls");
                     cout << pathbar1("add", "Группы") << "\n";
                     cout << "  |---------- Группы ---------|\n";
                     vector<Group> groups = database->getGroups();
                     if (groups[0].getID() == -1)
                        cout << "  Групп ещё нет в базе даных!\n";
                     else {
                        vector<Student> students = database->getStudents();
                        vector<Subject> subjects = database->getSubjects();
                        int length = groups.size();
                        for (int i = 0; i < length; i++)
                        {
                           if (groups[i].getIsDelete() == false) {
                              cout << "_______________________________\n";
                              cout << "Name: " << groups[i].getName() << "\n";
                              cout << "Students: \n";
                              int length = students.size();
                              vector<int> studsOfGroup = groups[i].getStudents();
                              if (studsOfGroup.size() == 0)
                                 cout << "  В группе ещё нет студентов!\n";
                              else
                                 for (int j = 0, k = 0; j < length; j++)
                                 {
                                    // check students in group
                                    if (k <= studsOfGroup.size() - 1) {
                                       if (students[j].getID() == studsOfGroup[k]) {
                                          cout << " - " << students[j].getFIO() << "\n";
                                          k++;
                                       }
                                    }
                                    else
                                       break;
                                 }
                              cout << "Subjects: \n";
                              int lengthSbj = subjects.size();
                              vector<int> sbjsOfGroup = groups[i].getSubjects();
                              if (sbjsOfGroup.size() == 0)
                                 cout << "  В группе ещё не переподaют!\n";
                              else
                                 for (int j = 0, k = 0; j < lengthSbj; j++)
                                 {
                                    if (k <= sbjsOfGroup.size() - 1) {
                                       if (subjects[j].getID() == sbjsOfGroup[k]) {
                                          cout << " - " << subjects[j].getName() << "\n";
                                          k++;
                                       }
                                    }
                                    else
                                       break;
                                 }
                              cout << "===============================\n\n";
                           }
                        }
                     }
                     system("pause");
                     pathbar1("remove");
                  }
                  break;
                  // show subjects
                  case 5:
                  {
                     system("cls");
                     cout << pathbar1("add", "Предметы") << "\n";
                     cout << "  |---------- Предметы ---------|\n";
                     vector<Subject> subjects = database->getSubjects();
                     if (subjects[0].getID() == -1)
                        cout << "  Предметов ещё нет в базе даных!\n";
                     else {
                        int length = subjects.size();
                        for (int i = 0; i < length; i++)
                        {
                           if (subjects[i].getIsDelete() == false) {
                              cout << "_______________________________\n";
                              subjects[i].show();
                              cout << "===============================\n\n";
                           }
                        }
                     }
                     system("pause");
                     pathbar1("remove");
                  }
                  break;
                  // show lessons
                  case 6:
                  {
                     system("cls");
                     cout << pathbar1("add", "Уроки") << "\n";
                     cout << "  |---------- Уроки ---------|\n";
                     vector<Lesson> lessons = database->getLessons();
                     vector<Group> groups = database->getGroups();
                     vector<Teacher> teachers = database->getTeachers();
                     vector<Subject> subjects = database->getSubjects();
                     vector<Pair> pairs = database->getPairs();
                     if (lessons[0].getID() == -1)
                        cout << "  Уроков ещё нет в базе даных!\n";
                     else {
                        int length = lessons.size();
                        for (int i = 0; i < length; i++)
                        {
                           if (lessons[i].getIsDelete() == false) {
                              cout << "_______________________________\n";
                              lessons[i].show(groups, teachers, subjects, pairs);
                              cout << "===============================\n\n";
                           }
                        }
                     }
                     system("pause");
                     pathbar1("remove");
                  }
                  break;
                  // exit of this section
                  case 0:
                     flagAdd = false;
                     break;
                  }
                  system("cls");
               }
               pathbar1("remove");
            }
            break;
            // exit of this section
            case 0:
               turnAdmin = false;
               break;
            }
            system("cls");
         }
         pathbar1("remove");
      }
      break;
      // Study part
      case 2:
      {
         system("cls");
         Menu eduPart(pathbar1("add", "Учебная часть"));
         eduPart.addSection("Добавить");
         eduPart.addSection("Удалить");
         bool turnEduPart = true;
         int chEduPart = 0;
         while (turnEduPart)
         {
            chEduPart = eduPart();
            switch (chEduPart)
            {
            // add
            case 1:
            {
               system("cls");
               Menu eduPartAdd(pathbar1("add", "Добавить"));
               eduPartAdd.addSection("Пару (запланировать)");
               eduPartAdd.addSection("Группу");
               eduPartAdd.addSection("Студента в группу");
               eduPartAdd.addSection("Предмет");
               eduPartAdd.addSection("Предмет в группу");
               eduPartAdd.addSection("Предмет преподавателю");
               bool turnEducationPartAdd = true;
               int chEduPartAdd = 0;
               while (turnEducationPartAdd) {
                  chEduPartAdd = eduPartAdd();
                  switch (chEduPartAdd)
                  {
                  // add pair
                  case 1:
                  {
                     system("cls");
                     vector<Teacher> DBTeachers = database->getTeachers();
                     vector<Subject> DBSubjects = database->getSubjects();
                     vector<Group> DBGroups = database->getGroups();
                     if (DBTeachers[0].getID() == -1) {
                        cout << "В базе даных нет преподавателей!\n";
                        system("pause");
                        break;
                     }
                     else if (DBSubjects[0].getID() == -1) {
                        cout << "В базе даных нет предметов для изучения!\n";
                        system("pause");
                        break;
                     }
                     else if (DBGroups[0].getID() == -1) {
                        cout << "В базе даных нет групп!\n";
                        system("pause");
                        break;
                     }
                     Pair temp;
                     temp = Pair::create(DBTeachers, DBSubjects, DBGroups);
                     database->addPair(temp);
                  }
                  break;
                  // add group
                  case 2:
                  {
                     system("cls");
                     Group temp;
                     temp = Group::create();
                     database->addGroup(temp);
                     
                  }
                  break;
                  // add student in group
                  case 3:
                  {
                     system("cls");
                     vector<Group> DBGroups = database->getGroups();
                     if (DBGroups[0].getID() == -1) {
                        cout << "В базе даных отсутствуют группы!\n";
                        break;
                     }
                     int length = DBGroups.size();

                     Menu menuGroups("Groups");
                     for (int i = 0; i < length; i++)
                     {
                        menuGroups.addSection(DBGroups[i].getName());
                     }
                     int chGroup;
                     chGroup = menuGroups();
                     if (chGroup != 0)
                        chGroup -= 1;
                     else
                        break;

                     bool flagGroupCh = false;
                     vector<Student> DBStudents = database->getStudents();
                     if (DBStudents[0].getID() == -1)
                     {
                        cout << "Студенты не найдены!\n";
                        flagGroupCh = true;
                        break;
                     }
                     Menu choiceStudent("Выбор студента");
                     int lengthStudents = DBStudents.size();
                     for (int i = 0; i < lengthStudents; i++)
                     {
                        choiceStudent.addSection(DBStudents[i].getFIO());
                     }
                     int idStudent = 0;
                     while (true)
                     {
                        idStudent = choiceStudent();
                        if (idStudent != 0)
                        {
                           idStudent -= 1;
                           break;
                        }
                     }

                     bool flagStudentCh = false;
                     for (int j = 0; j < lengthStudents; j++)
                     {
                        if (idStudent == j) {
                           flagStudentCh = true;
                           database->addStudentInGroup(DBGroups[chGroup].getID(), idStudent);
                        }
                     }
                     if (flagStudentCh == false)
                        cout << "Студент не найден!\n";
                     flagGroupCh = true;
                     break;
                  }
                  break;
                  // add subject
                  case 4:
                  {
                     system("cls");
                     Subject temp;
                     temp = Subject::create();
                     database->addSubject(temp);
                  }
                  break;
                  // add subject in group
                  case 5:
                  {
                     system("cls");
                     vector<Group> DBGroups = database->getGroups();
                     if (DBGroups[0].getID() == -1) {
                        cout << "В базе даных отсутствуют группы!\n";
                        break;
                     }
                     int length = DBGroups.size();

                     Menu menuGroups("Groups");
                     for (int i = 0; i < length; i++)
                     {
                        menuGroups.addSection(DBGroups[i].getName());
                     }
                     int chGroup;
                     chGroup = menuGroups();
                     if (chGroup != 0)
                        chGroup -= 1;
                     else
                        break;


                     bool flagGroupCh = false;
                     vector<Subject> DBSubjects = database->getSubjects();
                     if (DBSubjects[0].getID() == -1)
                     {
                        cout << "Предметы не найдены!\n";
                        flagGroupCh = true;
                        system("pause");
                        break;
                     }
                     Menu choiceSubject("Выбор прдмета");
                     int lengthSubjects = DBSubjects.size();
                     for (int i = 0; i < lengthSubjects; i++)
                     {
                        choiceSubject.addSection(DBSubjects[i].getName());
                     }
                     int idSubject = 0;
                     while (true)
                     {
                        idSubject = choiceSubject();
                        if (idSubject != 0)
                        {
                           idSubject -= 1;
                           break;
                        }
                     }

                     bool flagSubjectCh = false;
                     for (int j = 0; j < lengthSubjects; j++)
                     {
                        if (idSubject == j) {
                           flagSubjectCh = true;
                           database->addSubjectInGroup(DBGroups[chGroup].getID(), idSubject);
                           
                        }
                     }
                     if (flagSubjectCh == false)
                        cout << "Предмет не найден!\n";
                     flagGroupCh = true;
                     database->save();
                     break;
                  }
                  break;
                  // add subject to teacher
                  case 6:
                  {
                     system("cls");
                     vector<Teacher> DBTeachers = database->getTeachers();
                     if (DBTeachers[0].getID() == -1) {
                        cout << "В базе даных отсутствуют преподаватели!\n";
                        break;
                     }
                     int length = DBTeachers.size();

                     Menu chTeacher("Преподаватели");
                     for (int i = 0; i < length; i++)
                     {
                        chTeacher.addSection(DBTeachers[i].getFIO());
                     }
                     int chTch = 0;
                     bool flagChSubjectForTeacher = true;
                     while (flagChSubjectForTeacher) {
                        chTch = chTeacher();
                        if (chTch != 0) {
                           chTch -= 1;
                           Menu menuTchSubjects("Выбор предмета");
                           vector<Subject> DBSubjects = database->getSubjects();
                           if (DBSubjects[0].getID() == -1) {
                              cout << "В базе даных отсутствуют предметы!\n";
                              system("pause");
                              break;
                           }
                           int lengthSubjects = DBSubjects.size();
                           for (int i = 0; i < lengthSubjects; i++)
                           {
                              menuTchSubjects.addSection(DBSubjects[i].getName());
                           }
                           int chTchSubject;
                           while (true)
                           {
                              chTchSubject = menuTchSubjects();
                              if (chTchSubject != 0) {
                                 chTchSubject -= 1;
                                 database->addTeacherSubject(DBTeachers[chTch].getID(), DBSubjects[chTchSubject].getID());
                                 
                                 flagChSubjectForTeacher = false;
                                 break;
                              }
                              else
                              {
                                 flagChSubjectForTeacher = false;
                                 break;
                              }
                              system("cls");
                           }
                        }
                        else
                           break;
                        system("cls");
                     }
                     database->save();
                  }
                  break;
                  case 0:
                     turnEducationPartAdd = false;
                     break;
                  }
                  database->save();
                  system("cls");
               }
               pathbar1("remove");
            }
            break;
            // remove
            case 2:
            {
               Menu eduPartRemove(pathbar1("add", "Удалить"));
               eduPartRemove.addSection("Пару");
               eduPartRemove.addSection("Студента из группы");
               eduPartRemove.addSection("Группу");
               eduPartRemove.addSection("Предмет");
               eduPartRemove.addSection("Предмет из группы");
               eduPartRemove.addSection("Предмет преподавателю");
               bool turnEduPartRemove = true;
               int chEduPartRemove = 0;
               while (turnEduPartRemove) {
                  chEduPartRemove = eduPartRemove();
                  switch (chEduPartRemove)
                  {
                  // delete pair
                  case 1:
                  {
                     system("cls");
                     vector<Pair> DBPairs = database->getPairs();
                     if (DBPairs[0].getID() == -1) {
                        cout << "В базе даных нет пар!\n";
                        break;
                     }
                     Menu choicePair(" Пары\n");
                     int length = DBPairs.size();
                     for (int i = 0; i < length; i++)
                     {
                        string nameSection = to_string(DBPairs[i].getNumber());
                        nameSection += " ";
                        nameSection += DBPairs[i].getDate().to_str();
                        choicePair.addSection(nameSection);
                     }
                     int chPair;
                     chPair = choicePair();
                     if (chPair != 0) {
                        chPair -= 1;
                     }
                     else
                        break;
                        database->removePair(DBPairs[chPair].getID());
                        
                  }
                  break;
                  //delete student from group
                  case 2:
                  {
                     vector<Group> DBGroups = database->getGroups();
                     if (DBGroups[0].getID() == -1) {
                        cout << "В базе даных отсутствуют группы!\n";
                        break;
                     }
                     int length = DBGroups.size();

                     Menu menuGroups("Groups");
                     for (int i = 0; i < length; i++)
                     {
                        menuGroups.addSection(DBGroups[i].getName());
                     }
                     int choiceGroup;
                     choiceGroup = menuGroups();
                     if (choiceGroup != 0) {
                        choiceGroup -= 1;
                     }
                     else
                        break;

                     bool flagGroupCh = true;
                     for (int i = 0; i < length; i++)
                     {
                        if (DBGroups[i].getID() == choiceGroup) {
                           vector<Student> DBStudents = database->getStudents();
                           if (DBStudents[0].getID() == -1)
                           {
                              cout << "Студенты не найдены!\n";
                              flagGroupCh = false;
                              break;
                           }
                           Menu choiceStudent("Выбор студента");
                           int lengthStudents = DBStudents.size();
                           for (int i = 0; i < lengthStudents; i++)
                           {
                              choiceStudent.addSection(DBStudents[i].getFIO());
                           }
                           int idStudent = 0;
                           while (true)
                           {
                              idStudent = choiceStudent();
                              if (idStudent != 0)
                              {
                                 idStudent -= 1;
                                 break;
                              }
                           }

                           bool flagStudentCh = false;
                           for (int j = 0; j < lengthStudents; j++)
                           {
                              if (idStudent == j) {
                                 flagStudentCh = true;
                                 database->removeStudentInGroup(DBGroups[i].getID(), idStudent);
                                 
                              }
                           }
                           if (flagStudentCh == false)
                              cout << "Студент не найден!\n";
                           flagGroupCh = true;
                           break;
                        }
                     }
                     if (flagGroupCh == false)
                        cout << "Группа не найдена!\n";
                     database->save();
                  }
                  break;
                  // delete group
                  case 3:
                  {
                     system("cls");
                     vector<Group> DBGroups = database->getGroups();
                     if (DBGroups[0].getID() == -1) {
                        cout << "В базе даных отсутствуют группы!\n";
                        system("pause");
                        break;
                     }
                     int length = DBGroups.size();

                     Menu menuGroups("Groups");
                     for (int i = 0; i < length; i++)
                     {
                        menuGroups.addSection(DBGroups[i].getName());
                     }
                     int choiceGroup;
                     choiceGroup = menuGroups();
                     if (choiceGroup != 0)
                        choiceGroup -= 1;
                     else
                        break;

                     bool flagGroupCh = false;
                     for (int i = 0; i < length; i++)
                     {
                        if (DBGroups[i].getID() == choiceGroup) {
                           database->removeGroup(DBGroups[i].getID());
                           flagGroupCh = true;
                           
                           break;
                        }
                     }
                     if (flagGroupCh == false)
                        cout << "Группа не найдена!\n";
                     database->save();
                  }
                  break;
                  //delete subject
                  case 4:
                  {
                     system("cls");
                     vector<Subject> DBSubjects = database->getSubjects();
                     if (DBSubjects[0].getID() == -1) {
                        cout << "В базе даных отсутствуют предметы!\n";
                        system("pause");
                        break;
                     }
                     int length = DBSubjects.size();

                     Menu choiceSubject(" Subjects:");
                     for (int i = 0; i < length; i++)
                     {
                        choiceSubject.addSection(DBSubjects[i].getName());
                     }
                     int chSubject;
                     chSubject = choiceSubject();
                     if (chSubject != 0) {
                        chSubject -= 1;
                        break;
                     }
                     else
                        break;

                     bool flagGroupCh = false;
                     for (int j = 0; j < length; j++)
                     {
                        if (chSubject == j) {
                           database->removeSubject(DBSubjects[j].getID());
                           
                           flagGroupCh = true;
                           break;
                        }
                     }
                     if (flagGroupCh == false)
                        cout << "Группа не найдена!\n";
                     database->save();
                  }
                  break;
                  // delete subject from group
                  case 5:
                  {
                     vector<Group> DBGroups = database->getGroups();
                     if (DBGroups[0].getID() == -1) {
                        cout << "В базе даных отсутствуют группы!\n";
                        break;
                     }
                     int length = DBGroups.size();

                     Menu menuGroups("Groups");
                     for (int i = 0; i < length; i++)
                     {
                        menuGroups.addSection(DBGroups[i].getName());
                     }
                     int choiceGroup;
                     choiceGroup = menuGroups();
                     if (choiceGroup != 0)
                        choiceGroup -= 1;
                     else
                        break;

                     bool flagGroupCh = false;
                     for (int i = 0; i < length; i++)
                     {
                        if (DBGroups[i].getID() == choiceGroup) {
                           vector<Subject> DBSubjects = database->getSubjects();
                           if (DBSubjects[0].getID() == -1)
                           {
                              cout << "Предметы не найдены!\n";
                              flagGroupCh = true;
                              break;
                           }
                           Menu choiceSubject("Выбор предмета");
                           int lengthSubjects = DBSubjects.size();
                           for (int i = 0; i < lengthSubjects; i++)
                           {
                              choiceSubject.addSection(DBSubjects[i].getName());
                           }
                           int idSubject = 0;
                              idSubject = choiceSubject();
                              if (idSubject != 0)
                              {
                                 idSubject -= 1;

                              }
                              else
                                 break;

                           bool flagSubjectCh = false;
                           for (int j = 0; j < lengthSubjects; j++)
                           {
                              if (idSubject == j) {
                                 flagSubjectCh = true;
                                 database->removeSubjectInGroup(DBGroups[i].getID(), idSubject);
                                 
                              }
                           }
                           if (flagSubjectCh == false)
                              cout << "Предмет не найден!\n";
                           flagGroupCh = true;
                           break;
                        }
                     }
                     if (flagGroupCh == false)
                        cout << "Группа не найдена!\n";
                  }
                  break;
                  // delete subject from teacher
                  case 6:
                  {
                     system("cls");
                     vector<Teacher> DBTeachers = database->getTeachers();
                     if (DBTeachers[0].getID() == -1) {
                        cout << "В базе даных отсутствуют преподаватели!\n";
                        system("pause");
                        break;
                     }
                     int length = DBTeachers.size();

                     Menu chTeacher("Преподаватели");
                     for (int i = 0; i < length; i++)
                     {
                        chTeacher.addSection(DBTeachers[i].getFIO());
                     }
                     int chTch = 0;
                     chTch = chTeacher();
                     if (chTch != 0) {
                        chTch -= 1;
                        Menu menuTchSubjects("Выбор предмета");
                        vector<int> subjectsTeacher = database->getTeacherByID(DBTeachers[chTch].getID()).getSubjects();
                        if (subjectsTeacher.size() == 0) {
                           cout << "У преподавателя отсутствуют предметы!\n";
                           system("pause");
                           break;
                        }
                        int lengthSubjects = subjectsTeacher.size();
                        vector<Subject> DBSubjects = database->getSubjects();
                        int lengthDBSubjects = DBSubjects.size();

                        // add sections in menu
                        for (int i = 0; i < lengthSubjects; i++)
                        {
                           for (int j = 0; j < lengthDBSubjects; j++)
                           {
                              if (subjectsTeacher[i] == DBSubjects[j].getID()) {
                                 menuTchSubjects.addSection(DBSubjects[j].getName() + " " + to_string(DBSubjects[j].getTermHours()));
                                 break;
                              }
                           }

                        }
                        int chTchSubject;
                        chTchSubject = menuTchSubjects();
                        if (chTchSubject != 0) {
                           chTchSubject -= 1;
                           database->removeTeacherSubject(DBTeachers[chTch].getID(), DBSubjects[chTchSubject].getID());
                           break;
                        }
                        else
                           break;
                     }
                     database->save();
                  }
                  break;
                  case 0:
                  {
                     turnEduPartRemove = false;
                  }
                  break;
                  }
               }
               pathbar1("remove");
            }
            break;
            case 0:
            {
               turnEduPart = false;
            }
            break;
            }
            system("cls");
         }
         pathbar1("remove");
         database->save();
      }
      break;
      // Teacher
      case 3:
      {
         system("cls");
         Menu teacherMenu(pathbar1("add", "Преподаватель"));
         teacherMenu.addSection("Добавить");
         teacherMenu.addSection("Показать");
         teacherMenu.addSection("Изменить");

         if (activeSessionTeacher == false) {
            // Login user
            currentTeacher = database->loginTeacher();
            if (currentTeacher.getID() == -1) {
               break;
            }
            activeSessionTeacher = true;
            cout << "Вы успешно вошли!\n";
            system("pause");
         }
         // ----------------------

         int chTch;
         bool turnTch = true;
         while (turnTch) {
            system("cls");
            chTch = teacherMenu();
            switch (chTch)
            {
            case 1:
            {
               Menu addTch(pathbar1("add", "Добавить"));
               addTch.addSection("Урок на сегодня");
               addTch.addSection("Урок на другую дату");
               bool turnTchAdd = true;
               int chTchAdd;
               while (turnTchAdd) {
                  system("cls");
                  chTchAdd = addTch();
                  switch (chTchAdd)
                  {
                  case 1:
                  {
                     vector<Pair> DBpairs = database->getPairsByDate(CurrentDate);
                     if (DBpairs[0].getID() == -1)
                     {
                        cout << "На сегодня нет запланированных занятий\n";
                        system("pause");
                        break;
                     }
                     Menu chPairMenu(pathbar1("add", "Занятия сегодня"));
                     int length = DBpairs.size();
                     bool isPairForUser = false;
                     for (int i = 0; i < length; i++)
                     {
                        if (DBpairs[i].getIDTeacher() == currentTeacher.getID()) {
                           string pairStr = "Номер ";
                           pairStr += to_string(DBpairs[i].getNumber());
                           chPairMenu.addSection(pairStr);
                           isPairForUser = true;
                        }
                     }
                     if (isPairForUser == false) {
                        cout << "У вас сегодня занятий нет!\n";
                     }
                     int pairCh;
                     while (true) {
                        pairCh = chPairMenu();
                        if (pairCh != 0)
                        {
                           pairCh -= 1;
                           break;
                        }
                        else
                           break;
                     }
                     if (pairCh == 0) {
                        pathbar1("remove");
                        database->save();
                        break;
                     }
                     Lesson temp = Lesson::create(DBpairs[pairCh].getID());
                     database->addLesson(temp);
                     pathbar1("remove");
                     database->save();
                  }
                  break;
                  case 2:
                  {
                     cout << "Введите дату: \n";
                     int day, month, year;
                     Date userDate;
                     while (true)
                     {
                        try
                        {
                           cout << "День (число): ";
                           cin >> day;
                           cout << "Месяц (число): ";
                           cin >> month;
                           cout << "Год (число): ";
                           cin >> year;
                           userDate.set_year(year);
                           userDate.set_month(month);
                           userDate.set_day(day);
                           break;
                        }
                        catch (const string& e) {
                           if (e == "ValNotCorrect")
                              cout << "Введите коректную дату!\n";
                        }
                     }
                     vector<Pair> DBpairs = database->getPairsByDate(userDate);
                     if (DBpairs[0].getID() == -1)
                     {
                        cout << "На " << userDate.to_str() << " нет запланированных занятий\n";
                        system("pause");
                        break;
                     }
                     string strDateMenu = "Занятия ";
                     strDateMenu += userDate.to_str();
                     Menu chPairMenu(pathbar1("add", strDateMenu));
                     int length = DBpairs.size();
                     bool isPairForUser = false;
                     for (int i = 0; i < length; i++)
                     {
                        if (DBpairs[i].getIDTeacher() == currentTeacher.getID()) {
                           string pairStr = "Номер ";
                           pairStr += to_string(DBpairs[i].getNumber());
                           chPairMenu.addSection(pairStr);
                           isPairForUser = true;
                        }
                     }
                     if (isPairForUser == false) {
                        cout << "У вас " << userDate.to_str() << " занятий нет!\n";
                     }
                     int pairCh;
                     while (true) {
                        pairCh = chPairMenu();
                        if (pairCh != 0)
                        {
                           pairCh -= 1;
                           break;
                        }
                        else
                           break;
                     }
                     if (pairCh == 0) {
                        pathbar1("remove");
                        database->save();
                        break;
                     }
                     Lesson temp = Lesson::create(DBpairs[pairCh].getID());
                     database->addLesson(temp);
                     pathbar1("remove");
                     database->save();
                  }
                  break;
                  case 0:
                     turnTchAdd = false;
                     break;
                  }
               }
               pathbar1("remove");
               database->save();
            }
            break;
            // show shedule
            case 2:
            {
               Menu showTch(pathbar1("add", "Показать"));
               showTch.addSection("На сегодня");
               showTch.addSection("На текущий месяц");
               showTch.addSection("На другой месяц");
               showTch.addSection("На текущий год");
               showTch.addSection("Всё расписание");
               bool turnTchAdd = true;
               int chTchAdd;
               while (turnTchAdd) {
                  system("cls");
                  chTchAdd = showTch();
                  switch (chTchAdd)
                  {
                  // today
                  case 1:
                  {
                     vector<Pair> DBpairs = database->getPairsByDate(CurrentDate);
                     vector<Subject> DBSubjects = database->getSubjects();
                     vector<Teacher> DBTeachers = database->getTeachers();
                     cout << "   -------- Расписание на сегодня ------- \n";
                     if (DBpairs[0].getID() == -1)
                     {
                        cout << "На сегодня нет запланированных занятий\n";
                        system("pause");
                        break;
                     }
                     int length = DBpairs.size();
                     for (int i = 0; i < length; i++)
                     {
                        if (DBpairs[i].getIDTeacher() == currentTeacher.getID() && DBpairs[i].getDate() == CurrentDate && DBpairs[i].getIsDelete() == false) {
                           cout << "_______________________________\n";
                           DBpairs[i].show(DBTeachers, DBSubjects);
                           cout << "===============================\n\n";
                        }
                     }
                     system("pause");
                     database->save();
                  }
                  break;
                  // current month
                  case 2:
                  {
                     string currentMonth = Database::getNameMonthByNumber(CurrentDate.get_month());
                     vector<Pair> DBpairs = database->getPairs();
                     cout << "   -------- Расписание нa " << currentMonth << " ------ - \n";
                     if (DBpairs[0].getID() == -1)
                     {
                        cout << "На " << currentMonth << " нет запланированных занятий\n";
                        system("pause");
                        break;
                     }
                     vector<Teacher> teachers = database->getTeachers();
                     vector<Subject> subjects = database->getSubjects();
                     int length = DBpairs.size();
                     bool hasPairForUser = false;
                     for (int i = 0; i < length; i++)
                     {
                        if (DBpairs[i].getIDTeacher() == currentTeacher.getID() && DBpairs[i].getDate().get_month() == CurrentDate.get_month() && DBpairs[i].getIsDelete() == false) {
                           cout << "_______________________________\n";
                           DBpairs[i].show(teachers, subjects);
                           cout << "===============================\n\n";
                           hasPairForUser = true;
                        }
                     }
                     if (hasPairForUser == false) {
                        cout << "У вас в" << currentMonth << " занятий нет!\n";
                        system("pause");
                     }
                     system("pause");
                     database->save();
                  }
                  break;
                  // any month
                  case 3:
                  {
                     cout << "Введите значения: \n";
                     int month, year;
                     Date userDate;
                     while (true)
                     {
                        try
                        {
                           cout << "Месяц (число): ";
                           cin >> month;
                           cout << "Год (число): ";
                           cin >> year;
                           userDate.set_year(year);
                           userDate.set_month(month);
                           break;
                        }
                        catch (const string& e) {
                           if (e == "ValNotCorrect")
                              cout << "Введите коректную дату!\n";
                        }
                     }
                     vector<Pair> DBpairs = database->getPairsByDate(userDate);
                     system("cls");
                     cout << "   -------- Расписание нa " << Database::getNameMonthByNumber(userDate.get_month()) << " ------- \n";
                     if (DBpairs[0].getID() == -1)
                     {
                        cout << "На " << Database::getNameMonthByNumber(userDate.get_month()) << " нет запланированных занятий\n";
                        system("pause");
                        break;
                     }
                     vector<Teacher> teachers = database->getTeachers();
                     vector<Subject> subjects = database->getSubjects();
                     int length = DBpairs.size();
                     bool isPairForUser = false;
                     for (int i = 0; i < length; i++)
                     {
                        if (DBpairs[i].getIDTeacher() == currentTeacher.getID() && DBpairs[i].getDate().get_month() == userDate.get_month() && DBpairs[i].getDate().get_year() == userDate.get_year() && DBpairs[i].getIsDelete() == false) {
                           cout << "_______________________________\n";
                           DBpairs[i].show(teachers, subjects);
                           cout << "===============================\n\n";
                           isPairForUser = true;
                        }
                     }
                     if (isPairForUser == false) {
                        cout << "У вас в " << Database::getNameMonthByNumber(userDate.get_month()) << " занятий нет!\n";
                        system("pause");
                     }
                     system("pause");
                  }
                  break;
                  // current year
                  case 4:
                  {
                     vector<Pair> DBpairs = database->getPairs();
                     cout << "   -------- Расписание в " << CurrentDate.get_year() << " ------ - \n";
                     if (DBpairs[0].getID() == -1)
                     {
                        cout << "На " << CurrentDate.get_year() << " год нет запланированных занятий\n";
                        system("pause");
                        break;
                     }
                     int length = DBpairs.size();
                     bool isPairForUser = false;
                     vector<Teacher> teachers = database->getTeachers();
                     vector<Subject> subjects = database->getSubjects();
                     for (int i = 0; i < length; i++)
                     {
                        if (DBpairs[i].getIDTeacher() == currentTeacher.getID() && DBpairs[i].getDate().get_year() == CurrentDate.get_year() && DBpairs[i].getIsDelete() == false) {
                           cout << "_______________________________\n";
                           DBpairs[i].show(teachers, subjects);
                           cout << "===============================\n\n";
                           isPairForUser = true;
                        }
                     }
                     if (isPairForUser == false) {
                        cout << "У вас в " << CurrentDate.get_year() << " году занятий нет!\n";
                        system("pause");
                     }
                     system("pause");
                  }
                  break;
                  // all shedule for user
                  case 5:
                  {
                     vector<Pair> DBpairs = database->getPairs();
                     cout << "   -------- Расписание ------- \n";
                     if (DBpairs[0].getID() == -1)
                     {
                        cout << "У вас запланированных занятий нет!\n";
                        system("pause");
                        break;
                     }
                     int length = DBpairs.size();
                     bool isPairForUser = false;
                     vector<Teacher> teachers = database->getTeachers();
                     vector<Subject> subjects = database->getSubjects();
                     for (int i = 0; i < length; i++)
                     {
                        if (DBpairs[i].getIDTeacher() == currentTeacher.getID()&& DBpairs[i].getIsDelete() == false) {
                           cout << "_______________________________\n";
                           DBpairs[i].show(teachers, subjects);
                           cout << "===============================\n\n";
                           isPairForUser = true;
                        }
                     }
                     if (isPairForUser == false) {
                        cout << "У вас запланированных занятий нет!\n";
                        system("pause");
                     }
                     system("pause");
                  }
                  break;
                  case 0:
                     turnTchAdd = false;
                     break;
                  }
               }
               pathbar1("remove");
            }
            break;
            // change info user
            case 3:
            {
               system("cls");
               Menu changeInfo(pathbar1("add", "Изменить"));
               changeInfo.addSection("Пароль");
               changeInfo.addSection("Добавить дополнительную информацию");
               changeInfo.addSection("Удалить дополнительную информацию");
               int chTchInfo;
               bool turnTchInfo = true;
               while (turnTchInfo)
               {
                  chTchInfo = changeInfo();
                  switch (chTchInfo)
                  {
                  // change password
                  case 1:
                  {
                     string oldPassword;
                     string newPassword;
                     cout << "Введите старый пароль: ";
                     getline(cin, oldPassword);
                     cout << "Введите новый пароль: ";
                     getline(cin, newPassword);
                     while (!currentTeacher.changePassword(oldPassword, newPassword)) {
                        cout << "Введите старый пароль: ";
                        getline(cin, oldPassword);
                        cout << "Введите новый пароль: ";
                        getline(cin, newPassword);
                     }
                     cout << "Операция успешна!\n";
                     database->changeTeacherPassword(oldPassword, newPassword, currentTeacher.getID());
                     system("pause");
                  }
                  break;
                  // add additional info
                  case 2:
                  {
                     string first, second;
                     cout << "Введите то что вы хотите добавить: ";
                     getline(cin, first);
                     cout << "Введите значение: ";
                     getline(cin, second);
                     currentTeacher.addAdditional(first, second);
                     database->addAdditionalForTeacher(first, second, currentTeacher.getID());
                  }
                  break;
                  // remove additional info
                  case 3:
                  {
                     Menu additionalInfoList("Дополнительная информация");
                     map<string, string> additional = currentTeacher.getAdditional();
                     if (additional.size() == 0)
                     {
                        cout << "    Отсутствует!\n";
                        system("pause");
                        break;
                     }
                     map<string, string>::iterator it = additional.begin();
                     while (it != additional.end()) {
                        additionalInfoList.addSection(it->first);
                        it++;
                     }
                     int indexElem = 1;
                     int chElem;
                     while (true) {
                        chElem = additionalInfoList();
                        if (chElem != 0) {
                           it = additional.begin();
                           while (it != additional.end())
                           {
                              if (indexElem == chElem) {
                                 currentTeacher.delAdditional(it->first);
                                 database->removeAdditionalForTeacher(it->first, currentTeacher.getID());
                                 break;
                              }
                              indexElem++;
                              it++;
                           }
                           break;
                        }
                        else
                           break;
                     }
                  }
                  break;
                  case 0:
                  {
                     turnTchInfo = false;
                  }
                  break;
                  }
                  system("cls");
               }
               pathbar1("remove");
               database->save();
            }
            break;
            case 0:
            {
               while (true)
               {
                  string chSession;
                  cout << "Завершить сесию? ( y / n ): ";
                  getline(cin, chSession);
                  if (chSession == "y" || chSession == "Y")
                  {
                     activeSessionTeacher = false;
                     break;
                  }
                  else if (chSession == "n" || chSession == "N")
                  {
                     break;
                  }
               }
               turnTch = false;
            }

            break;
            }
         }
         pathbar1("remove");
         database->save();
      }
      break;
      // student
      case 4:
      {
         system("cls");
         Menu studentMenu(pathbar1("add", "Студент"));
         studentMenu.addSection("Показать");
         studentMenu.addSection("Изменить");

         if (activeSessionStudent == false) {
            // Login user
            currentStudent = database->loginStudent();
            if (currentStudent.getID() == -1) {
               break;
            }
            activeSessionStudent = true;
            cout << "Вы успешно вошли!\n";
            system("pause");
         }
         // ----------------------

         int chStud;
         bool turnStud = true;
         while (turnStud) {
            system("cls");
            chStud = studentMenu();
            switch (chStud)
            {
            // show shedule
            case 1:
            {
               Menu showStud(pathbar1("add", "Показать"));
               showStud.addSection("На сегодня");
               showStud.addSection("На текущий месяц");
               showStud.addSection("На другой месяц");
               showStud.addSection("На текущий год");
               showStud.addSection("Всё расписание");
               bool turnStudShow = true;
               int chStudShow;
               while (turnStudShow) {
                  system("cls");
                  chStudShow = showStud();
                  switch (chStudShow)
                  {
                     // today
                  case 1:
                  {
                     vector<Pair> DBpairs = database->getPairsByDate(CurrentDate);
                     vector<Subject> DBSubjects = database->getSubjects();
                     vector<Teacher> DBTeachers = database->getTeachers();
                     cout << "   -------- Расписание на сегодня ------- \n";
                     if (DBpairs[0].getID() == -1)
                     {
                        cout << "На сегодня нет запланированных занятий\n";
                        system("pause");
                        break;
                     }
                     int length = DBpairs.size();
                     for (int i = 0; i < length; i++)
                     {
                        if (DBpairs[i].getIDGroup() == currentStudent.getIDGroup() && DBpairs[i].getDate() == CurrentDate && DBpairs[i].getIsDelete() == false) {
                           cout << "_______________________________\n";
                           DBpairs[i].show(DBTeachers, DBSubjects);
                           cout << "===============================\n\n";
                        }
                     }
                     system("pause");
                     database->save();
                  }
                  break;
                  // current month
                  case 2:
                  {
                     string currentMonth = Database::getNameMonthByNumber(CurrentDate.get_month());
                     vector<Pair> DBpairs = database->getPairs();
                     cout << "   -------- Расписание нa " << currentMonth << " ------ - \n";
                     if (DBpairs[0].getID() == -1)
                     {
                        cout << "На " << currentMonth << " нет запланированных занятий\n";
                        system("pause");
                        break;
                     }
                     vector<Teacher> teachers = database->getTeachers();
                     vector<Subject> subjects = database->getSubjects();
                     int length = DBpairs.size();
                     bool hasPairForUser = false;
                     for (int i = 0; i < length; i++)
                     {
                        if (DBpairs[i].getIDGroup() == currentStudent.getIDGroup() && DBpairs[i].getDate().get_month() == CurrentDate.get_month() && DBpairs[i].getIsDelete() == false) {
                           cout << "_______________________________\n";
                           DBpairs[i].show(teachers, subjects);
                           cout << "===============================\n\n";
                           hasPairForUser = true;
                        }
                     }
                     if (hasPairForUser == false) {
                        cout << "У вас в " << currentMonth << " занятий нет!\n";
                        system("pause");
                     }
                     system("pause");
                     database->save();
                  }
                  break;
                  // any month
                  case 3:
                  {
                     cout << "Введите значения: \n";
                     int month, year;
                     Date userDate;
                     while (true)
                     {
                        try
                        {
                           cout << "Месяц (число): ";
                           cin >> month;
                           cout << "Год (число): ";
                           cin >> year;
                           userDate.set_year(year);
                           userDate.set_month(month);
                           break;
                        }
                        catch (const string& e) {
                           if (e == "ValNotCorrect")
                              cout << "Введите коректную дату!\n";
                        }
                     }
                     vector<Pair> DBpairs = database->getPairsByDate(userDate);
                     system("cls");
                     cout << "   -------- Расписание нa " << Database::getNameMonthByNumber(userDate.get_month()) << " ------ - \n";
                     if (DBpairs[0].getID() == -1)
                     {
                        cout << "На " << Database::getNameMonthByNumber(userDate.get_month()) << " нет запланированных занятий\n";
                        system("pause");
                        break;
                     }
                     vector<Teacher> teachers = database->getTeachers();
                     vector<Subject> subjects = database->getSubjects();
                     int length = DBpairs.size();
                     bool isPairForUser = false;
                     for (int i = 0; i < length; i++)
                     {
                        if (DBpairs[i].getIDGroup() == currentStudent.getIDGroup() && DBpairs[i].getDate().get_month() == userDate.get_month() && DBpairs[i].getDate().get_year() == userDate.get_year() && DBpairs[i].getIsDelete() == false) {
                           cout << "_______________________________\n";
                           DBpairs[i].show(teachers, subjects);
                           cout << "===============================\n\n";
                           isPairForUser = true;
                        }
                     }
                     if (isPairForUser == false) {
                        cout << "У вас в " << Database::getNameMonthByNumber(userDate.get_month()) << " занятий нет!\n";
                        system("pause");
                     }
                     system("pause");
                  }
                  break;
                  // current year
                  case 4:
                  {
                     vector<Pair> DBpairs = database->getPairs();
                     cout << "   -------- Расписание в " << CurrentDate.get_year() << " ------ - \n";
                     if (DBpairs[0].getID() == -1)
                     {
                        cout << "На " << CurrentDate.get_year() << " год нет запланированных занятий\n";
                        system("pause");
                        break;
                     }
                     int length = DBpairs.size();
                     bool isPairForUser = false;
                     vector<Teacher> teachers = database->getTeachers();
                     vector<Subject> subjects = database->getSubjects();
                     for (int i = 0; i < length; i++)
                     {
                        if (DBpairs[i].getIDGroup() == currentStudent.getIDGroup() && DBpairs[i].getDate().get_year() == CurrentDate.get_year() && DBpairs[i].getIsDelete() == false) {
                           cout << "_______________________________\n";
                           DBpairs[i].show(teachers, subjects);
                           cout << "===============================\n\n";
                           isPairForUser = true;
                        }
                     }
                     if (isPairForUser == false) {
                        cout << "У вас в " << CurrentDate.get_year() << " году занятий нет!\n";
                        system("pause");
                     }
                     system("pause");
                  }
                  break;
                  // all shedule for user
                  case 5:
                  {
                     vector<Pair> DBpairs = database->getPairs();
                     cout << "   -------- Расписание ------- \n";
                     if (DBpairs[0].getID() == -1)
                     {
                        cout << "У вас запланированных занятий нет!\n";
                        system("pause");
                        break;
                     }
                     int length = DBpairs.size();
                     bool isPairForUser = false;
                     vector<Teacher> teachers = database->getTeachers();
                     vector<Subject> subjects = database->getSubjects();
                     for (int i = 0; i < length; i++)
                     {
                        if (DBpairs[i].getIDGroup() == currentStudent.getIDGroup() && DBpairs[i].getIsDelete() == false) {
                           cout << "_______________________________\n";
                           DBpairs[i].show(teachers, subjects);
                           cout << "===============================\n\n";
                           isPairForUser = true;
                        }
                     }
                     if (isPairForUser == false) {
                        cout << "У вас запланированных занятий нет!\n";
                        system("pause");
                     }
                     system("pause");
                  }
                  break;
                  case 0:
                     turnStudShow = false;
                     break;
                  }
               }
               pathbar1("remove");
            }
            break;
            // change info user
            case 2:
            {
               system("cls");
               Menu changeInfo(pathbar1("add", "Изменить"));
               changeInfo.addSection("Пароль");
               changeInfo.addSection("Добавить дополнительную информацию");
               changeInfo.addSection("Удалить дополнительную информацию");
               int chStudInfo;
               bool turnStudInfo = true;
               while (turnStudInfo)
               {
                  chStudInfo = changeInfo();
                  switch (chStudInfo)
                  {
                     // change password
                  case 1:
                  {
                     string oldPassword;
                     string newPassword;
                     cout << "Введите старый пароль: ";
                     getline(cin, oldPassword);
                     cout << "Введите новый пароль: ";
                     getline(cin, newPassword);
                     while (!currentStudent.changePassword(oldPassword, newPassword)) {
                        cout << "Введите старый пароль: ";
                        getline(cin, oldPassword);
                        cout << "Введите новый пароль: ";
                        getline(cin, newPassword);
                     }
                     cout << "Операция успешна!\n";
                     database->changeStudentPassword(oldPassword, newPassword, currentStudent.getID());
                     system("pause");
                  }
                  break;
                  // add additional info
                  case 2:
                  {
                     string first, second;
                     cout << "Введите то что вы хотите добавить: ";
                     getline(cin, first);
                     cout << "Введите значение: ";
                     getline(cin, second);
                     currentStudent.addAdditional(first, second);
                     database->addAdditionalForStudent(first, second, currentStudent.getID());
                  }
                  break;
                  // remove additional info
                  case 3:
                  {
                     Menu additionalInfoList("Дополнительная информация");
                     map<string, string> additional = currentStudent.getAdditional();
                     if (additional.size() == 0)
                     {
                        cout << "    Отсутствует!\n";
                        system("pause");
                        break;
                     }
                     map<string, string>::iterator it = additional.begin();
                     while (it != additional.end()) {
                        additionalInfoList.addSection(it->first);
                        it++;
                     }
                     int indexElem = 1;
                     int chElem;
                     while (true) {
                        chElem = additionalInfoList();
                        if (chElem != 0) {
                           it = additional.begin();
                           while (it != additional.end())
                           {
                              if (indexElem == chElem) {
                                 currentStudent.delAdditional(it->first);
                                 database->removeAdditionalForStudent(it->first, currentStudent.getID());
                                 break;
                              }
                              indexElem++;
                              it++;
                           }
                           break;
                        }
                        else
                           break;
                     }
                  }
                  break;
                  case 0:
                  {
                     turnStudInfo = false;
                  }
                  break;
                  }
                  system("cls");
                  database->save();
               }
               pathbar1("remove");
               database->save();
            }
            break;
            case 0:
            {
               while (true)
               {
                  string chSession;
                  cout << "Завершить сесию? ( y / n ): ";
                  getline(cin, chSession);
                  if (chSession == "y" || chSession == "Y")
                  {
                     activeSessionStudent = false;
                     break;
                  }
                  else if (chSession == "n" || chSession == "N")
                  {
                     break;
                  }
               }
               turnStud = false;
            }

            break;
            }
            
         }
         pathbar1("remove");
         database->save();
      }
      break;
      case 0:
         turn = false;
         break;
      }
      system("cls");
      database->save();
   }
   cout << "Start save in file...\n";
   clock_t tStart = clock();
   database->save();
   cout << "Save in file success ( " << (double)(clock() - tStart) / CLOCKS_PER_SEC << "sec ) !\n";
   system("pause");
   return 0;
}