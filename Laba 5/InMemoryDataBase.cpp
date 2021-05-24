#include <iostream>
#include <list>
#include <QtSql>
#include "InMemoryDataBase.h"
#include <QMessageBox>
#include <QString>

using namespace std;

InMemoryDataBase::InMemoryDataBase(){

    /*vector<Question> *geographyQuestions;

    geographyQuestions = new vector<Question>;

    vector<Variant> question1;

    Variant *var1q1;
    var1q1 = new Variant("Христофор Колумб");
    var1q1->isCorrect = true;
    question1.push_back(*var1q1);
    Variant *var2q1;
    var2q1 = new Variant("Марко Поло");
    var2q1->isCorrect = false;
    question1.push_back(*var2q1);
    Variant *var3q1;
    var3q1 = new Variant("Фернан Магеллан");
    var3q1->isCorrect= false;
    question1.push_back(*var3q1);
    Variant *var4q1;
    var4q1 = new Variant("Америго Веспуччі");
    var4q1->isCorrect = false;
    question1.push_back(*var4q1);

    Question *ques1;

    ques1 = new Question("Який великий дослідник відкрив Америку у 1492 році?", question1);

    ques1->setRightAnwser(*var1q1);
    geographyQuestions->push_back(*ques1);

    vector<Variant> question2;

    Variant *var1q2;
    var1q2 = new Variant("Венеція");
    var1q2->isCorrect = false;
    question2.push_back(*var1q2);
    Variant *var2q2;
    var2q2 = new Variant("Берлін");
    var2q2->isCorrect = false;
    question2.push_back(*var2q2);
    Variant *var3q2;
    var3q2 = new Variant("Вена");
    var3q2->isCorrect = false;
    question2.push_back(*var3q2);
    Variant *var4q2;
    var4q2 = new Variant("Париж");
    var4q2->isCorrect = true;
    question2.push_back(*var4q2);

    Question *ques2;

    ques2 = new Question("Яке місто є столицею Республіки Франція?", question2);

    ques2->setRightAnwser(*var4q2);

    geographyQuestions->push_back(*ques2);

    vector<Variant> question3;

    Variant *var1q3;
    Variant *var2q3;
    Variant *var3q3;
    Variant *var4q3;
    var1q3 = new Variant("Канада");
    var1q3->isCorrect = false;
    question3.push_back(*var1q3);
    var2q3 = new Variant("Індія");
    var2q3->isCorrect = false;
    question3.push_back(*var2q3);
    var3q3 = new Variant("Китай");
    var3q3 ->isCorrect = true;
    question3.push_back(*var3q3);
    var4q3 = new Variant("Росія");
    var4q3->isCorrect = false;
    question3.push_back(*var4q3);

    Question *ques3;

    ques3 = new Question("Яка держава має найбільшу на планеті кількість населення?", question3);

    ques3->setRightAnwser(*var3q3);

    geographyQuestions->push_back(*ques3);

    vector<Variant> question4;

    Variant *var1q4;
    var1q4 = new Variant("Кюсю");
    var1q4->isCorrect = false;
    question4.push_back(*var1q4);
    Variant *var2q4;
    var2q4 = new Variant("Фудзі");
    var2q4->isCorrect = true;
    question4.push_back(*var2q4);
    Variant *var3q4;
    var3q4 = new Variant("Едо");
    var3q4->isCorrect = false;
    question4.push_back(*var3q4);
    Variant *var4q4;
    var4q4 = new Variant("Фукусіма");
    var4q4->isCorrect = false;
    question4.push_back(*var4q4);

    Question *ques4;

    ques4 = new Question("Як називається найвища точка на території Японії?", question4);

    ques4->setRightAnwser(*var3q3);

    geographyQuestions->push_back(*ques4);

    vector<Variant> question5;

    Variant *var1q5;
    var1q5 = new Variant("Теократія");
    var1q5->isCorrect = false;
    question5.push_back(*var1q5);
    Variant *var2q5;
    var2q5 = new Variant("Президентсько-парламентська республіка");
    var2q5->isCorrect = false;
    question5.push_back(*var2q5);
    Variant *var3q5;
    var3q5 = new Variant("Конституційна монархія");
    var3q5->isCorrect = false;
    question5.push_back(*var3q5);
    Variant *var4q5;
    var4q5 = new Variant("Парламентсько-президентська республіка");
    var4q5->isCorrect = true;
    question5.push_back(*var4q5);

    Question *ques5;

    ques5 = new Question("Назвіть державний устрій Республіки Україна?", question5);

    ques5->setRightAnwser(*var4q5);

    geographyQuestions->push_back(*ques5);

    Quiz *geography;

    geography = new Quiz("Geography", *geographyQuestions);

    vector<Question> *historyQuestions;

    historyQuestions = new vector<Question>;

    vector<Variant> historyQuestion1;
    Variant *var1hq1;
    var1hq1 = new Variant("Ярослав Мудрий");
    var1hq1->isCorrect = false;
    historyQuestion1.push_back(*var1hq1);
    Variant *var2hq1;
    var2hq1 = new Variant("Княгиня Ольга");
    var2hq1->isCorrect = false;
    historyQuestion1.push_back(*var2hq1);
    Variant *var3hq1;
    var3hq1 = new Variant("Олег Віщий");
    var3hq1->isCorrect = true;
    historyQuestion1.push_back(*var3hq1);
    Variant *var4hq1;
    var4hq1 = new Variant("Володимир Великий");
    var4hq1->isCorrect = false;
    historyQuestion1.push_back(*var4hq1);

    Question *history1;

    history1 = new Question("Який князь проголосив Київ матір`ю городам руським?", historyQuestion1);

    history1->setRightAnwser(*var3hq1);

    historyQuestions->push_back(*history1);

    vector<Variant> historyQuestion2;
    Variant *var1hq2;
    var1hq2 = new Variant("Еразм Роттердамський");
    var1hq2->isCorrect = false;
    historyQuestion2.push_back(*var1hq2);
    Variant *var2hq2;
    var2hq2 = new Variant("Мартін Лютер");
    var2hq2->isCorrect = true;
    historyQuestion2.push_back(*var2hq2);
    Variant *var3hq2;
    var3hq2 = new Variant("Томас Мор");
    var3hq2->isCorrect = false;
    historyQuestion2.push_back(*var3hq2);
    Variant *var4hq2;
    var4hq2 = new Variant("Жан Кальвін");
    var4hq2->isCorrect = false;
    historyQuestion2.push_back(*var4hq2);

    Question *history2;

    history2 = new Question("Назвіть ім`я засновника руху Реформації що виник у Німеччині у 17 столітті", historyQuestion2);

    history2->setRightAnwser(*var2hq2);

    historyQuestions->push_back(*history2);

    vector<Variant> historyQuestion3;
    Variant *var1hq3;
    var1hq3 = new Variant("Стагнація");
    var1hq3->isCorrect = true;
    historyQuestion3.push_back(*var1hq3);
    Variant *var2hq3;
    var2hq3 = new Variant("Відлига");
    var2hq3->isCorrect = false;
    historyQuestion3.push_back(*var2hq3);
    Variant *var3hq3;
    var3hq3 = new Variant("Перебудова");
    var3hq3->isCorrect = false;
    historyQuestion3.push_back(*var3hq3);
    Variant *var4hq3;
    var4hq3 = new Variant("Нова Економічна політика");
    var4hq3->isCorrect = false;
    historyQuestion3.push_back(*var4hq3);

    Question *history3;

    history3 = new Question("Як називають добу правління Леоніда Брежнєва?", historyQuestion3);

    history3->setRightAnwser(*var1hq3);

    historyQuestions->push_back(*history3);

    vector<Variant> historyQuestion4;
    Variant *var1hq4;
    var1hq4 = new Variant("Тевтонський Орден");
    var1hq4->isCorrect = false;
    historyQuestion4.push_back(*var1hq4);
    Variant *var2hq4;
    var2hq4 = new Variant("Орден Госпітальєрів");
    var2hq4->isCorrect = false;
    historyQuestion4.push_back(*var2hq4);
    Variant *var3hq4;
    var3hq4 = new Variant("Орден Тамплієрів");
    var3hq4->isCorrect = true;
    historyQuestion4.push_back(*var3hq4);
    Variant *var4hq4;
    var4hq4 = new Variant("Орден Бенедиктівців");
    var4hq4->isCorrect = false;
    historyQuestion4.push_back(*var4hq4);

    Question *history4;

    history4 = new Question("Який орден було скандально розупущено за правління Філіппа IV Красивого?", historyQuestion4);

    history4->setRightAnwser(*var3hq4);

    historyQuestions->push_back(*history4);

    vector<Variant> historyQuestion5;
    Variant *var1hq5;
    var1hq5 = new Variant("Італія, Японія, СРСР");
    var1hq5->isCorrect = false;
    historyQuestion5.push_back(*var1hq5);
    Variant *var2hq5;
    var2hq5 = new Variant("Німеччина, Італія, Японія");
    var2hq5->isCorrect = true;
    historyQuestion5.push_back(*var2hq5);
    Variant *var3hq5;
    var3hq5 = new Variant("США, Велика Британія, Франція");
    var3hq5->isCorrect = false;
    historyQuestion5.push_back(*var3hq5);
    Variant *var4hq5;
    var4hq5 = new Variant("Польща, Німеччина, СРСР");
    var4hq5->isCorrect = false;
    historyQuestion5.push_back(*var4hq5);



    Question *history5;

    history5 = new Question("Які держави входили до карїн Осі у 30-х 40-х роках 20-го століття?", historyQuestion5);

    history5->setRightAnwser(*var2hq5);

    historyQuestions->push_back(*history5);

    Quiz *history;

    history = new Quiz("History", *historyQuestions);

    vector<Question> *physicsQuestions;

    physicsQuestions = new vector<Question>;

    vector<Variant> phys1;
    Variant *v1ph1;
    v1ph1 = new Variant("Заснування квантової механіки");
    v1ph1->isCorrect = false;
    phys1.push_back(*v1ph1);
    Variant *v2ph1;
    v2ph1 = new Variant("Закон фотоелектричного ефекту");
    v2ph1->isCorrect = true;
    phys1.push_back(*v2ph1);
    Variant *v3ph1;
    v3ph1 = new Variant("Спеціальна теорія відносності");
    v3ph1->isCorrect = false;
    phys1.push_back(*v3ph1);
    Variant *v4ph1;
    v4ph1 = new Variant("Загальна теорія відносності");
    v4ph1->isCorrect = false;
    phys1.push_back(*v4ph1);

    Question *physicQuest1;

    physicQuest1 = new Question("За яке відкриття Альберта Ейнштейна було нагороджено Нобелівською премією?", phys1);

    physicQuest1->setRightAnwser(*v2ph1);

    physicsQuestions->push_back(*physicQuest1);

    vector<Variant> phys2;
    Variant *v1ph2;
    v1ph2 = new Variant("Вольт");
    v1ph2->isCorrect = false;
    phys2.push_back(*v1ph2);
    Variant *v2ph2;
    v2ph2 = new Variant("Ампер");
    v2ph2->isCorrect = false;
    phys2.push_back(*v2ph2);
    Variant *v3ph2;
    v3ph2 = new Variant("Люкс");
    v3ph2->isCorrect = false;
    phys2.push_back(*v3ph2);
    Variant *v4ph2;
    v4ph2 = new Variant("Ньютон");
    v4ph2->isCorrect = true;
    phys2.push_back(*v4ph2);


    Question *physQuest2;

    physQuest2 = new Question("Одиниці вимірвання механічної сили", phys2);

    physQuest2->setRightAnwser(*v4ph2);

    physicsQuestions->push_back(*physQuest2);

    vector<Variant> phys3;
    Variant *v1ph3;
    v1ph3 = new Variant("Прискорення вільного падіння");
    v1ph3->isCorrect = false;
    phys3.push_back(*v1ph3);
    Variant *v2ph3;
    v2ph3 = new Variant("Кінетична енергія");
    v2ph3->isCorrect = true;
    phys3.push_back(*v2ph3);
    Variant *v3ph3;
    v3ph3 = new Variant("Сила тяжіння");
    v3ph3->isCorrect = false;
    phys3.push_back(*v3ph3);
    Variant *v4ph3;
    v4ph3 = new Variant("Потенційна енергія");
    v4ph3->isCorrect = false;
    phys3.push_back(*v4ph3);

    Question *physQuest3;

    physQuest3 = new Question("У формулі якої величини фігурує квадрат швидкості тіла?", phys3);

    physQuest3->setRightAnwser(*v2ph3);

    physicsQuestions->push_back(*physQuest3);

    vector<Variant> phys4;
    Variant *v1ph4;
    v1ph4 = new Variant("Ніколя Тесла");
    v1ph4->isCorrect = false;
    phys4.push_back(*v1ph4);
    Variant *v2ph4;
    v2ph4 = new Variant("Томас Едісон");
    v2ph4->isCorrect = false;
    phys4.push_back(*v2ph4);
    Variant *v3ph4;
    v3ph4 = new Variant("Альберт Ейнштейн");
    v3ph4->isCorrect = false;
    phys4.push_back(*v3ph4);
    Variant *v4ph4;
    v4ph4 = new Variant("Марія Кюрі");
    v4ph4->isCorrect = true;
    phys4.push_back(*v4ph4);

    Question *physQuest4;

    physQuest4 = new Question("Відкриття пов`язані з радіоактивністю є заслугою вченого", phys4);

    physQuest4->setRightAnwser(*v4ph4);

    physicsQuestions->push_back(*physQuest4);

    vector<Variant> phys5;
    Variant *v1ph5;
    v1ph5 = new Variant("Галілео Галілея");
    v1ph5->isCorrect = true;
    phys5.push_back(*v1ph5);
    Variant *v2ph5;
    v2ph5 = new Variant("Леонардо да Вінчі");
    v2ph5->isCorrect = false;
    phys5.push_back(*v2ph5);
    Variant *v3ph5;
    v3ph5 = new Variant("Птолемея");
    v3ph5->isCorrect = false;
    phys5.push_back(*v3ph5);
    Variant *v4ph5;
    v4ph5 = new Variant("Арістотеля");
    v4ph5->isCorrect = false;
    phys5.push_back(*v4ph5);

    Question *physQuest5;

    physQuest5 = new Question("І все-таки вона обертається... - доленосна цитата фізика: ", phys5);

    physQuest5->setRightAnwser( *v1ph5);

    physicsQuestions->push_back(*physQuest5);

    Quiz *physics;

    physics = new Quiz("Physics", *physicsQuestions);

    quizzes.push_back(*geography);
    quizzes.push_back(*history);
    quizzes.push_back(*physics);
    */


    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("quizGame.sqlite");
    if (!sdb.open()) {
          qDebug() << sdb.lastError().text();
    }



    QSqlQuery query;

    QString qstr = "CREATE TABLE IF NOT EXISTS QUIZ ("
    "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
    "NAME VARCHAR(255));";

    if(query.exec(qstr)){

        QMessageBox msgboxx;

        msgboxx.setText("quizzes created!!");

        //msgboxx.exec();

    }
    else{
        QMessageBox msgboxx;

        msgboxx.setText("NOOO");

        msgboxx.exec();


    }

    qstr = "CREATE TABLE IF NOT EXISTS QUESTIONS ("
           "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, QUIZ_ID INTEGER , TEXT VARCHAR(2000));";

    if(query.exec(qstr)){

        QMessageBox msgboxx;

        msgboxx.setText("questions created!!");

        //msgboxx.exec();

    }
    else{
        QMessageBox msgboxx;

        msgboxx.setText("NOOO");

        msgboxx.exec();

    }

    qstr = "CREATE TABLE IF NOT EXISTS VARIANTS ("
           "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, QUESTION_ID INTEGER, TEXT VARCHAR(2000), IS_CORRECT BIT);";

    if(query.exec(qstr)){

        QMessageBox msgboxx;

        msgboxx.setText("variants created!!");

        msgboxx.exec();

    }
    else{
        QMessageBox msgboxx;

        msgboxx.setText("NOOO");

        //msgboxx.exec();

    }


    query.exec("SELECT * FROM QUIZ");
    while (query.next()) {

            int quizID = query.value(0).toInt();

            QString quizName = query.value(1).toString();
            QMessageBox box;
            QString IDstr;
            IDstr.setNum(quizID);
            box.setText(quizName + " " + IDstr);
            //box.exec();
            Quiz *nextQuiz;
            nextQuiz = new Quiz();
            nextQuiz->setID(quizID);
            nextQuiz->setName(quizName.toStdString());
            quizzes.push_back(*nextQuiz);
        }

    for (int i=0; i< quizzes.size(); i++){

        QString quizID;

        quizID.setNum(quizzes[i].getID());

        query.exec("SELECT * FROM QUESTIONS WHERE QUIZ_ID = " + quizID);

        vector<Question> currentQuestions;
        while(query.next()){


            int questionID = query.value(0).toInt();

            QString questionText = query.value(2).toString();

            QMessageBox box;

            QString QuesIDstr;

            QuesIDstr.setNum(questionID);

            box.setText(QuesIDstr + " " + questionText);

            //box.exec();

            Question *nextQues;

            nextQues = new Question();

            nextQues->setID(questionID);

            nextQues->setText(questionText.toStdString());

            currentQuestions.push_back(*nextQues);

            //quizzes[i].getQuestions().push_back(*nextQues);


                }

        for (int j = 0; j< currentQuestions.size(); j++){

            QString QuesID;

            QuesID.setNum(currentQuestions[j].getID());

            query.exec("SELECT * FROM VARIANTS WHERE QUESTION_ID =" + QuesID);

            vector<Variant> currentVariants;

            Variant *correctVariant;

            correctVariant = new Variant();

            while(query.next()){

                int VarID = query.value(0).toInt();

                QString quesText = query.value(2).toString();

                int isCorrect = query.value(3).toInt();

                QString varIDStr;

                QString isCorStr;

                isCorStr.setNum(isCorrect);

                varIDStr.setNum(VarID);

                QMessageBox box1;

                box1.setText(quesText + " " + isCorStr + " " + varIDStr);

                //box1.exec();

                Variant *nextVariant;

                nextVariant = new Variant();

                nextVariant->setID(VarID);

                nextVariant->setText(quesText.toStdString());

                if(isCorrect ==1){

                    nextVariant->isCorrect = true;
                    correctVariant = nextVariant;

                }
                else{

                    nextVariant->isCorrect = false;

                }

                currentVariants.push_back(*nextVariant);

                currentQuestions[j].setRightAnwser(*correctVariant);

                currentQuestions[j].setVariants(currentVariants);

            }

        quizzes[i].setQuestions(currentQuestions);

        }




    }



    /*

    for(int i=0; i<quizzes.size(); i++){

        QString currentName;

        currentName = QString::fromStdString(quizzes[i].getQuizName());

        qstr = "INSERT INTO QUIZ (NAME) VALUES ('" + currentName + "');";

        if(query.exec(qstr)){

            QMessageBox msgboxx;

            msgboxx.setText(currentName + "inserted successfully");

            msgboxx.exec();

        }
        else{
            QMessageBox msgboxx;

            msgboxx.setText("NOOO");

            msgboxx.exec();

        }

        int lastQuizID = query.lastInsertId().toInt();

        QString strID;

        strID.setNum(lastQuizID);

        for(int j=0; j<quizzes[i].getQuestions().size(); j++){

            QString questionText = QString::fromStdString(quizzes[i].getQuestions()[j].getText());
            qstr = "INSERT INTO QUESTIONS (QUIZ_ID, TEXT) VALUES (" + strID +",'" + questionText +"');";
            if(query.exec(qstr)){

                QMessageBox msgboxx;

                msgboxx.setText(questionText + "inserted successfully");

                msgboxx.exec();

            }
            else{

                QMessageBox msgboxx;

                msgboxx.setText("NOOO");

                msgboxx.exec();

            }

            int lastQuizIDsec = query.lastInsertId().toInt();

            QString strIDsec;

            strIDsec.setNum(lastQuizIDsec);

            for (int y=0; y<quizzes[i].getQuestions()[j].getAllVariants().size(); y++){

                QString variantText = QString::fromStdString(quizzes[i].getQuestions()[j].getAllVariants()[y].getText());

                bool isCorrect = quizzes[i].getQuestions()[j].getAllVariants()[y].isCorrect;

                int isCorrectInt;

                if(isCorrect){

                    isCorrectInt = 1;

                }
                else{

                    isCorrectInt = 0;
                }

                QString isCorrectStr;

                isCorrectStr.setNum(isCorrectInt);

                qstr = "INSERT INTO VARIANTS (QUESTION_ID, TEXT, IS_CORRECT) VALUES (" + strIDsec +",'" + variantText +"', '"+ isCorrectStr+ "');";
                if(query.exec(qstr)){

                    QMessageBox msgboxx;

                    msgboxx.setText(variantText + "inserted successfully");

                    msgboxx.exec();

                }
                else{

                    QMessageBox msgboxx;

                    msgboxx.setText("NOOO");

                    msgboxx.exec();

                }

            }

        }


    }*/

}
InMemoryDataBase::~InMemoryDataBase(){}

void InMemoryDataBase::AddQuiz(Quiz inQuiz){

    quizzes.push_back(inQuiz);

}



void InMemoryDataBase::DeleteQuiz(Quiz inQuiz){

    for (int i = 0; i<=quizzes.size(); i++){

        if(inQuiz==quizzes[i]){

            quizzes.erase(quizzes.begin() + i);

        }

    }

}



void InMemoryDataBase::UpdateQuiz(Quiz inQuiz){



}



vector<Quiz> InMemoryDataBase::getQuizzes(){

    return quizzes;

}



void InMemoryDataBase::setQuizzes(vector<Quiz> inQuizzes){

    quizzes = inQuizzes;

}


