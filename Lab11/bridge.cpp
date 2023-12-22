#include <iostream>
#include <memory>

class LabelImpl
{
    private:
        std::string text;
    public:
        virtual void setText(std::string _text) = 0;
        virtual std::string getText() const = 0;
        virtual void getLabelPosition(double& x, double& y) = 0;
        virtual void draw() = 0;
};

class ConcreteLabelImpl1 : public LabelImpl
{
    private:
        std::string text;
    public:
        void setText(std::string _text) override
        {
            text = _text;
        }
        std::string getText() const override
        {
            return text;
        }
        void getLabelPosition(double& x, double& y) override
        {
            x = 0.0;
            y = 1.0;
        }
        void draw() override
        {
            std::cout << "Desenează Label-ul folosind biblioteca grafica x..." << std::endl;
        }
};

class ConcreteLabelImpl2 : public LabelImpl
{
    private:
        std::string text;
    public:
        void setText(std::string _text) override
        {
            text = _text;
        }
        std::string getText() const override
        {
            return text;
        }
        void getLabelPosition(double& x, double& y) override
        {
            x = 10.0;
            y = 20.0;
        }
        void draw() override
        {
            std::cout << "Desenează Label-ul folosind biblioteca grafica y..." << std::endl;
        }
};

class RadioButtonImpl
{
    public:
        virtual bool getStateOfRadioButtonsGroup() = 0;
        virtual bool getIsEnabled() = 0;
        virtual void draw() = 0;
};

class ConcreteRadioButtonImpl1 : public RadioButtonImpl
{
    public:
        bool getStateOfRadioButtonsGroup() override
        {
            return false;
        }

        bool getIsEnabled() override
        {
            return false;
        }
        void draw() override
        {
            std::cout << "Desenează RadioButton-ul folosind biblioteca grafica x..." << std::endl;
        }
};

class ConcreteRadioButtonImpl2 : public RadioButtonImpl
{
    public:
        bool getStateOfRadioButtonsGroup() override
        {
            return true;
        }

        bool getIsEnabled() override
        {
            return true;
        }
        void draw() override
        {
            std::cout << "Desenează RadioButton-ul folosind biblioteca grafica y..." << std::endl;
        }
};


class Widget
{
    public:
        virtual void draw() = 0;
};

class Label : public Widget
{
    private:
        std::shared_ptr<LabelImpl> impl;
    public:
        Label(std::shared_ptr<LabelImpl> _impl)
        : impl(_impl)
        {

        }
        void setText(std::string _text)
        {
            impl->setText(_text);
        }
        std::string getText()
        {
            return impl->getText();
        }
        void getLabelPosition(double& x, double& y)
        {
            impl->getLabelPosition(x, y);
        }
        void draw() override
        {
            impl->draw();
        }
};

class RadioButton : public Widget
{
    private:
        std::shared_ptr<RadioButtonImpl> impl;
    public:
        RadioButton(std::shared_ptr<RadioButtonImpl> _impl)
        : impl(_impl)
        {

        }
        bool getStateOfRadioButtonsGroup()
        {
            return impl->getStateOfRadioButtonsGroup();
        }
        bool getIsEnabled()
        {
            return impl->getIsEnabled();
        }
        void draw() override
        {
            impl->draw();
        }
};

int main()
{
    std::shared_ptr<LabelImpl> impl1 = std::dynamic_pointer_cast<LabelImpl>(
        std::make_shared<ConcreteLabelImpl1>()
    );
    Label label(impl1);

    label.draw();

    std::shared_ptr<RadioButtonImpl> impl2 = std::dynamic_pointer_cast<RadioButtonImpl>(
        std::make_shared<ConcreteRadioButtonImpl2>());
    RadioButton radioButton(impl2);

    radioButton.draw();

    return 0;
}