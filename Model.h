#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

using namespace std;

class Lander
{
private:
    string name;
    int velocity,score,fuel;
public:
    string getName();
    void setName(string data_name);
    void setVelocity(int oldVelocity);
    int getVelocity();
    int getScore();
    int getFuel();


    Lander(string data_name)
    {
        setName(data_name);
        name = data_name;
        cout<<"New Lander__  ";
        getName();

        velocity, score = 0;
        fuel = 100;
    }

    ~Lander()
    {
        cout<<"Delete Lander";
    }

};



string Lander::getName()
{
    cout<<"Name: "<<name<<"\n";
    return name;
}

void Lander::setName(string data_name)
{
    string name = data_name;
}

int Lander::getVelocity()
{
    cout<<"Velocity: "<<velocity<<"\n";
    return velocity;
}

void Lander::setVelocity(int oldVelocity)
{
    int velocity = oldVelocity;
}

int Lander::getScore()
{
    cout<<"Score: "<<score<<"\n";
    return score;
}

int Lander::getFuel()
{
    cout<<"Fuel: "<<fuel<<"\n";
    return fuel;
}



#endif // MODEL_H_INCLUDED
