#include <iostream>
#include <memory>
#include <vector>

class Widget
{
    private:
        std::string id;

    public:
        Widget(const std::string& _id) : id(_id) {}
        virtual void draw() = 0;
};

class Label : public Widget
{
    private:
        std::string text;

    public:
        Label(const std::string& _id, const std::string& _text)
        : Widget(_id),
          text(_text)
        {

        }

        void draw() override
        {
            std::cout << "Afisam un Label" <<std::endl;
        }
};

class Button : public Widget
{
    private:
        std::string text;

    public:
        Button(const std::string& _id, const std::string& _text)
        : Widget(_id),
          text(_text)
        {

        }

        void draw() override
        {
            std::cout << "Afisam un Button" <<std::endl;
        }
};

class CheckBox : public Widget
{
    private:
        std::string text;
        bool isChecked;

    public:
        CheckBox(const std::string& _id, const std::string& _text, bool _isChecked)
        : Widget(_id),
          text(_text),
          isChecked(_isChecked)
        {

        }

        void draw() override
        {
            std::cout << "Afisam un CheckBox" <<std::endl;
        }
};

enum WidgetType
{
    LABEL,
    BUTTON,
    CHECKBOX
};

struct WidgetProps
{
    WidgetType type;
    std::string id;
    std::string text;
    bool isChecked; // este luat în considerare doar dacă type == CHECKBOX
};

class Window
{
    private:
        std::vector<std::shared_ptr<Widget>> widgets;

    protected:
        std::shared_ptr<Widget> createWidget(const WidgetProps& winProps)
        {
            std::shared_ptr<Widget> ptr;

            switch (winProps.type)
            {
                case WidgetType::LABEL:
                    std::cout<<"Se creeaza un Label" << std::endl;
                    ptr = std::dynamic_pointer_cast<Widget>(std::make_shared<Label>(
                        winProps.id, winProps.text));
                    break;
                case WidgetType::BUTTON:
                    std::cout<<"Se creeaza un Button" << std::endl;
                    ptr = std::dynamic_pointer_cast<Widget>(std::make_shared<Button>(
                        winProps.id, winProps.text));
                    break;
                case WidgetType::CHECKBOX:
                    std::cout<<"Se creeaza un Checkbox" << std::endl;
                    ptr = std::dynamic_pointer_cast<Widget>(std::make_shared<CheckBox>(
                        winProps.id, winProps.text, winProps.isChecked));
                    break;
                default:
                    break;
            }

            return ptr;
        }

    public:
        Window(const std::vector<WidgetProps>& winPropsVect)
        {
            for (auto it = winPropsVect.begin();
                 it != winPropsVect.end();
                 ++it)
            {
                auto widget = createWidget(*it);
                widgets.push_back(widget);
            }
        }
};

int main()
{
    std::vector<WidgetProps> widgetProps;
    widgetProps.push_back({WidgetType::LABEL, "123", "Label1", false});
    widgetProps.push_back({WidgetType::BUTTON, "124", "Click me", false});
    widgetProps.push_back({WidgetType::CHECKBOX, "125", "Some checkbox", true});

    Window win(widgetProps);

    return 0;
}