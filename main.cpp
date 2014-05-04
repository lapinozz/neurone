#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <neurone.h>

int main(int argc, char *argv[])
{
    srand ((time(0)));
    int rnd = rand() % 100 + 1;
    int selection = 51;
    int mov = 0;

    Reseau reseau;
    Layer layer;
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
    reseau.push_back(layer);
    layer.clear();
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
    reseau.push_back(layer);
    layer.clear();
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
    reseau.push_back(layer);
        layer.clear();
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
    reseau.push_back(layer);
        layer.clear();
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
    reseau.push_back(layer);
        layer.clear();
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
    reseau.push_back(layer);
        layer.clear();
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
    reseau.push_back(layer);
        layer.clear();
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
    reseau.push_back(layer);
        layer.clear();
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
    reseau.push_back(layer);
        layer.clear();
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
    reseau.push_back(layer);
        layer.clear();
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
    reseau.push_back(layer);
        layer.clear();
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
    reseau.push_back(layer);
        layer.clear();
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
    reseau.push_back(layer);
    layer.clear();
        layer.push_back(new neurone);
        layer.push_back(new neurone);
        layer.push_back(new neurone);
    reseau.push_back(layer);
    layer.clear();

    for (auto &layer : reseau)
    {
        for (auto &neuro : layer)
        {
            neuro->input(getInput(reseau[1]));
        }

    }

    reseau[0][0]->setValue(1);

    for(int z = 0; z < 10000; z++)
    {
        if(selection > rnd)
        {
            reseau[0][1]->setValue(1);
            reseau[0][2]->setValue(0);
        }
        else
        {
            reseau[0][2]->setValue(1);
            reseau[0][1]->setValue(0);
        }

        for (auto &neuro : reseau[1])
            neuro->poid[0] = (float)selection/50 - 1;

        int x = 0;
        int y = 0;
        for (auto &layer : reseau)
        {
            for (auto &neuro : layer)
            {
                if(x!=0)
                    neuro->input(getInput(reseau[x-1]));
                y++;
            }
            x++;
        }

        mov++;

        for (auto &layer : reseau)
        {
            for (auto &neuro : layer)
            {
                if(x!=0)
                    std::cout << (int)neuro->getValue() << " ";
            }
            x++;
            std::cout<<std::endl;
        }
        std::cout<<selection<<","<<rnd<<","<<mov<<std::endl;
        std::cout<<std::endl;

        if(reseau[0][2]->getValue())
            selection++;
        else if (reseau[0][1]->getValue())
            selection--;

        selection = std::max(0, selection);
        selection = std::min(100, selection);

        if(selection == rnd)
            rnd = rand() % 100 + 1;
    }
    int diference;

    if(selection < rnd)
        diference = rnd - selection;
    else
        diference = selection - rnd;

    Config config;

    if(diference > 49)
        config = getConfig(reseau);


}
