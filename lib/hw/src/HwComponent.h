#ifndef SENSUALI_DI_PARCHEGGIO_HWCOMPONENT_H
#define SENSUALI_DI_PARCHEGGIO_HWCOMPONENT_H

/**
 * @brief parent class of every hardware component
 */
class HwComponent{
public:

    /**
     * @brief Construct a new Hw Component object
     * 
     * @param pin pin number where component is wired
     */
    explicit HwComponent(char pin);

    /**
     * @brief Return the pin which this hardware component is wired to.
     * 
     * @return char the pin.
     */
    char pin() const;

private:

    char pin_;
};

#endif //SENSUALI_DI_PARCHEGGIO_HWCOMPONENT_H
