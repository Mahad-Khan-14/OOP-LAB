#include "iostream"
#include "string"
using namespace std;

class Student
{
private:
    int id;
    string name;
    int *scores;
    int scoreNum;

public:
    Student(int StdId, string Name, int numScore, int *_scores) : id(StdId), name(Name), scoreNum(numScore)
    {
        scores = new int[scoreNum];
        for (int i = 0; i < scoreNum; i++)
        {
            scores[i] = _scores[i];
        }
    }

    Student(Student &other) : name(other.name), id(other.id), scoreNum(other.scoreNum)
    {
        scores = new int[scoreNum];
        for (int i = 0; i < scoreNum; i++)
        {
            scores[i] = other.scores[i];
        }
    }

    ~Student()
    {
        delete[] scores;
    }

    void displayStdudent()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Exam Scores: " << endl;
        for (int i = 0; i < scoreNum; i++)
        {
            cout << scores[i] << " " << endl;
        }
        cout << "---------------------------" << endl;
    }
};

int main()
{
    int score1[] = {85, 90, 95};
    Student s1(144, "Mahad", 3, score1);

    Student s2(s1);

    cout << "Record for Original Student: " << endl;
    s1.displayStdudent();

    cout << "Copied Student Record" << endl;
    s2.displayStdudent();

    return 0;
}
