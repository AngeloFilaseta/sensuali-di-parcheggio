#ifndef SENSUALI_DI_PARCHEGGIO_HWCOMPONENT_H
#define SENSUALI_DI_PARCHEGGIO_HWCOMPONENT_H

//parent class of every hardware component
class HwComponent{
    public:
        //constructor: pin(pin number where component is wired)
        HwComponent(char pin);

        //returns the pin which this hardware component is wired to
        char pin();

    private:
        char pin_;
};

#endif //SENSUALI_DI_PARCHEGGIO_HWCOMPONENT_H
