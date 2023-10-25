class LivingBeing
{
private:
    bool isAlive;
public:
    LivingBeing();
    bool getIsAlive() const;
    void kill();
    ~LivingBeing();
};