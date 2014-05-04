#include "neurone.h"
#include <random>
#include <iostream>

neurone::neurone()
{
    first = 1;
    value = 0;
}

neurone::~neurone()
{

}

float neurone::output()
{
    return value;
}

void neurone::input(Input input)
{
    if(first)
    {
        int i = 0;
        for (auto &x : input)
        {
            poid.push_back((float)(rand()%100-50)/100);
            i++;
        }
        first = !first;
    }
    int i = 0;
    float v = 0;
    for (auto &x : input)
    {
        v = (float)(v + (float)x*poid[i]);
        i++;
    }
    value = v + 1;
    //std::cout<<v<<std::endl;
}

void neurone::setValue(float vValue)
{
    value = vValue;
}

float neurone::getValue()
{
    return value;
}

Input getInput(Layer layer)
{
    Input input;
    for (auto &neuro : layer)
    {
        input.push_back(neuro->output());
    }
    return input;
}

Config getConfig(Reseau reseau)
{
    Config config;
    int x = 0;
    int y = 0;
    for (auto &layer : reseau)
    {
        Poid poid;
        for (auto &neuro : layer)
        {
            if(x!=0)
                poid.push_back(neuro->getValue());
            y++;
        }
        config.push_back(poid);
        x++;
        y = 0;
    }
    return config;
}
