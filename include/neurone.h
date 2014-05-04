#ifndef NEURONE_H
#define NEURONE_H

#include <vector>

class neurone;

typedef std::vector<neurone*> Layer;
typedef std::vector<Layer> Reseau;
typedef std::vector<float> Input;
typedef std::vector<float> Poid;
typedef std::vector<Poid> Config;

Input getInput(Layer layer);
Config getConfig(Reseau reseau);

class neurone
{
    public:
        neurone();
        virtual ~neurone();
        float output();
        void setValue(float vValue);
        float  getValue();
        void input(Input input);
        Poid poid;
    protected:
        float value;
        int first;
    private:
};

#endif // NEURONE_H
