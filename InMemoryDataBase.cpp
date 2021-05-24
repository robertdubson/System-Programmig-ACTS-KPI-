#include <iostream>
#include <list>

#include "InMemoryDataBase.h"

using namespace std;

InMemoryDataBase::InMemoryDataBase(){

    vector<Question> *geographyQuestions;

    geographyQuestions = new vector<Question>;

    vector<Variant> question1;

    Variant *var1q1;
    var1q1 = new Variant("Христофор Колумб");
    question1.push_back(*var1q1);
    Variant *var2q1;
    var2q1 = new Variant("Марко Поло");
    question1.push_back(*var2q1);
    Variant *var3q1;
    var3q1 = new Variant("Фернан Магеллан");
    question1.push_back(*var3q1);
    Variant *var4q1;
    var4q1 = new Variant("Америго Веспуччі");
    question1.push_back(*var4q1);

    Question *ques1;

    ques1 = new Question("Який великий дослідник відкрив Америку у 1492 році?", question1, *var1q1);

    geographyQuestions->push_back(*ques1);

    vector<Variant> question2;

    Variant *var1q2;
    var1q2 = new Variant("Венеція");
    question2.push_back(*var1q2);
    Variant *var2q2;
    var2q2 = new Variant("Берлін");
    question2.push_back(*var2q2);
    Variant *var3q2;
    var3q2 = new Variant("Вена");
    question2.push_back(*var3q2);
    Variant *var4q2;
    var4q2 = new Variant("Париж");
    question2.push_back(*var4q2);

    Question *ques2;

    ques2 = new Question("Яке місто є столицею Республіки Франція?", question2, *var4q2);

    geographyQuestions->push_back(*ques2);

    vector<Variant> question3;

    Variant *var1q3;
    Variant *var2q3;
    Variant *var3q3;
    Variant *var4q3;
    var1q3 = new Variant("Канада");
    question3.push_back(*var1q3);
    var2q3 = new Variant("Індія");
    question3.push_back(*var2q3);
    var3q3 = new Variant("Китай");
    question3.push_back(*var3q3);
    var4q3 = new Variant("Росія");
    question3.push_back(*var4q3);

    Question *ques3;

    ques3 = new Question("Яка держава має найбільшу на планеті кількість населення?", question3, *var3q3);

    geographyQuestions->push_back(*ques3);

    vector<Variant> question4;

    Variant *var1q4;
    var1q4 = new Variant("Кюсю");
    question4.push_back(*var1q4);
    Variant *var2q4;
    var2q4 = new Variant("Фудзі");
    question4.push_back(*var2q4);
    Variant *var3q4;
    var3q4 = new Variant("Едо");
    question4.push_back(*var3q4);
    Variant *var4q4;
    var4q4 = new Variant("Фукусіма");
    question4.push_back(*var4q4);

    Question *ques4;

    ques4 = new Question("Як називається найвища точка на території Японії?", question4, *var2q4);
    geographyQuestions->push_back(*ques4);

    vector<Variant> question5;

    Variant *var1q5;
    var1q5 = new Variant("Теократія");
    question5.push_back(*var1q5);
    Variant *var2q5;
    var2q5 = new Variant("Президентсько-парламентська республіка");
    question5.push_back(*var2q5);
    Variant *var3q5;
    var3q5 = new Variant("Конституційна монархія");
    question5.push_back(*var3q5);
    Variant *var4q5;
    var4q5 = new Variant("Парламентсько-президентська республіка");
    question5.push_back(*var4q5);

    Question *ques5;

    ques5 = new Question("Назвіть державний устрій Республіки Україна?", question5, *var4q5);

    geographyQuestions->push_back(*ques5);

    Quiz *geography;

    geography = new Quiz("Geography", *geographyQuestions);

    vector<Question> *historyQuestions;

    historyQuestions = new vector<Question>;

    vector<Variant> historyQuestion1;
    Variant *var1hq1;
    var1hq1 = new Variant("Ярослав Мудрий");
    historyQuestion1.push_back(*var1hq1);
    Variant *var2hq1;
    var2hq1 = new Variant("Княгиня Ольга");
    historyQuestion1.push_back(*var2hq1);
    Variant *var3hq1;
    var3hq1 = new Variant("Олег Віщий");
    historyQuestion1.push_back(*var3hq1);
    Variant *var4hq1;
    var4hq1 = new Variant("Володимир Великий");
    historyQuestion1.push_back(*var4hq1);

    Question *history1;

    history1 = new Question("Який князь проголосив Київ 'матір'ю городам руським'?", historyQuestion1, *var3hq1);
    historyQuestions->push_back(*history1);

    vector<Variant> historyQuestion2;
    Variant *var1hq2;
    var1hq2 = new Variant("Еразм Роттердамський");
    historyQuestion2.push_back(*var1hq2);
    Variant *var2hq2;
    var2hq2 = new Variant("Мартін Лютер");
    historyQuestion2.push_back(*var2hq2);
    Variant *var3hq2;
    var3hq2 = new Variant("Томас Мор");
    historyQuestion2.push_back(*var3hq2);
    Variant *var4hq2;
    var4hq2 = new Variant("Жан Кальвін");
    historyQuestion2.push_back(*var4hq2);

    Question *history2;

    history2 = new Question("Назвіть ім'я засновника руху Реформації, що виник у Німеччині у 17 столітті.", historyQuestion2, *var2hq2);

    historyQuestions->push_back(*history2);

    vector<Variant> historyQuestion3;
    Variant *var1hq3;
    var1hq3 = new Variant("Стагнація");
    historyQuestion3.push_back(*var1hq3);
    Variant *var2hq3;
    var2hq3 = new Variant("Відлига");
    historyQuestion3.push_back(*var2hq3);
    Variant *var3hq3;
    var3hq3 = new Variant("Перебудова");
    historyQuestion3.push_back(*var3hq3);
    Variant *var4hq3;
    var4hq3 = new Variant("Нова Економічна політика");
    historyQuestion3.push_back(*var4hq3);

    Question *history3;

    history3 = new Question("Як називають добу правління Леоніда Брежнєва?", historyQuestion3, *var1hq3);

    historyQuestions->push_back(*history3);

    vector<Variant> historyQuestion4;
    Variant *var1hq4;
    var1hq4 = new Variant("Тевтонський Орден");
    historyQuestion4.push_back(*var1hq4);
    Variant *var2hq4;
    var2hq4 = new Variant("Орден Госпітальєрів");
    historyQuestion4.push_back(*var2hq4);
    Variant *var3hq4;
    var3hq4 = new Variant("Орден Тамплієрів");
    historyQuestion4.push_back(*var3hq4);
    Variant *var4hq4;
    var4hq4 = new Variant("Орден Бенедиктівців");
    historyQuestion4.push_back(*var4hq4);

    Question *history4;

    history4 = new Question("Який орден було скандально розупущено за правління Філіппа IV Красивого?", historyQuestion4, *var3hq4);

    historyQuestions->push_back(*history4);

    vector<Variant> historyQuestion5;
    Variant *var1hq5;
    var1hq5 = new Variant("Італія, Японія, СРСР");
    historyQuestion5.push_back(*var1hq5);
    Variant *var2hq5;
    var2hq5 = new Variant("Німеччина, Італія, Японія");
    historyQuestion5.push_back(*var2hq5);
    Variant *var3hq5;
    var3hq5 = new Variant("США, Велика Британія, Франція");
    historyQuestion5.push_back(*var3hq5);
    Variant *var4hq5;
    var4hq5 = new Variant("Польща, Німеччина, СРСР");
    historyQuestion5.push_back(*var4hq5);



    Question *history5;

    history5 = new Question("Які держави входили до карїн 'Осі' у 30-х 40-х роках 20-го століття?", historyQuestion5, *var2hq5);

    historyQuestions->push_back(*history5);

    Quiz *history;

    history = new Quiz("History", *historyQuestions);

    vector<Question> *physicsQuestions;

    physicsQuestions = new vector<Question>;

    vector<Variant> phys1;
    Variant *v1ph1;
    v1ph1 = new Variant("Заснування квантової механіки");
    phys1.push_back(*v1ph1);
    Variant *v2ph1;
    v2ph1 = new Variant("Закон фотоелектричного ефекту");
    phys1.push_back(*v2ph1);
    Variant *v3ph1;
    v3ph1 = new Variant("Спеціальна теорія відносності");
    phys1.push_back(*v3ph1);
    Variant *v4ph1;
    v4ph1 = new Variant("Загальна теорія відносності");
    phys1.push_back(*v4ph1);

    Question *physicQuest1;

    physicQuest1 = new Question("За яке відкриття Альберта Ейнштейна було нагороджено Нобелівською премією?", phys1, *v2ph1);

    physicsQuestions->push_back(*physicQuest1);

    vector<Variant> phys2;
    Variant *v1ph2;
    v1ph2 = new Variant("Вольт");
    phys2.push_back(*v1ph2);
    Variant *v2ph2;
    v2ph2 = new Variant("Ампер");
    phys2.push_back(*v2ph2);
    Variant *v3ph2;
    v3ph2 = new Variant("Люкс");
    phys2.push_back(*v3ph2);
    Variant *v4ph2;
    v4ph2 = new Variant("Ньютон");
    phys2.push_back(*v4ph2);

    Question *physQuest2;

    physQuest2 = new Question("Одиниці вимірвання механічної сили", phys2, *v4ph2);

    physicsQuestions->push_back(*physQuest2);

    vector<Variant> phys3;
    Variant *v1ph3;
    v1ph3 = new Variant("Прискорення вільного падіння");
    phys3.push_back(*v1ph3);
    Variant *v2ph3;
    v2ph3 = new Variant("Кінетична енергія");
    phys3.push_back(*v2ph3);
    Variant *v3ph3;
    v3ph3 = new Variant("Сила тяжіння");
    phys3.push_back(*v3ph3);
    Variant *v4ph3;
    v4ph3 = new Variant("Потенційна енергія");
    phys3.push_back(*v4ph3);

    Question *physQuest3;

    physQuest3 = new Question("У формулі якої величини фігурує квадрат швидкості тіла?", phys3, *v2ph3);

    physicsQuestions->push_back(*physQuest3);

    vector<Variant> phys4;
    Variant *v1ph4;
    v1ph4 = new Variant("Ніколя Тесла");
    phys4.push_back(*v1ph4);
    Variant *v2ph4;
    v2ph4 = new Variant("Томас Едісон");
    phys4.push_back(*v2ph4);
    Variant *v3ph4;
    v3ph4 = new Variant("Альберт Ейнштейн");
    phys4.push_back(*v3ph4);
    Variant *v4ph4;
    v4ph4 = new Variant("Марія Кюрі");
    phys4.push_back(*v4ph4);

    Question *physQuest4;

    physQuest4 = new Question("Відкриття, пов'язані з радіоактивністю, є заслугою вченого:", phys4, *v4ph4);

    physicsQuestions->push_back(*physQuest4);

    vector<Variant> phys5;
    Variant *v1ph5;
    v1ph5 = new Variant("Галілео Галілея");
    phys5.push_back(*v1ph5);
    Variant *v2ph5;
    v2ph5 = new Variant("Леонардо да Вінчі");
    phys5.push_back(*v2ph5);
    Variant *v3ph5;
    v3ph5 = new Variant("Птолемея");
    phys5.push_back(*v3ph5);
    Variant *v4ph5;
    v4ph5 = new Variant("Арістотеля");
    phys5.push_back(*v4ph5);

    Question *physQuest5;

    physQuest5 = new Question("'І все-таки вона обертається...' - доленосна цитата фізика: ", phys5, *v1ph5);

    physicsQuestions->push_back(*physQuest5);

    Quiz *physics;

    physics = new Quiz("Physics", *physicsQuestions);

    quizzes.push_back(*geography);
    quizzes.push_back(*history);
    quizzes.push_back(*physics);

}
InMemoryDataBase::~InMemoryDataBase(){}

void InMemoryDataBase::AddQuiz(Quiz inQuiz){

    quizzes.push_back(inQuiz);

}

void InMemoryDataBase::AddRound(Round inRound){

    rounds.push_back(inRound);

}

void InMemoryDataBase::DeleteQuiz(Quiz inQuiz){

    for (int i = 0; i<=quizzes.size(); i++){

        if(inQuiz==quizzes[i]){

            quizzes.erase(quizzes.begin() + i);

        }

    }

}

void InMemoryDataBase::DeleteRound(Round inRound){


    for (int i = 0; i<=rounds.size(); i++){

        if(inRound.getPlayerName()==rounds[i].getPlayerName() && inRound.getRating()==rounds[i].getRating()){

            rounds.erase(rounds.begin() + i);

        }

    }


}

void InMemoryDataBase::UpdateQuiz(Quiz inQuiz){



}

void InMemoryDataBase::UpdateRound(Round inRound){


}

vector<Quiz> InMemoryDataBase::getQuizzes(){

    return quizzes;

}

vector<Round> InMemoryDataBase::getRounds(){

    return rounds;

}

void InMemoryDataBase::setQuizzes(vector<Quiz> inQuizzes){

    quizzes = inQuizzes;

}

void InMemoryDataBase::setRounds(vector<Round> inRounds){

    rounds = inRounds;

}
