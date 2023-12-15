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
};

class QtLabel : public Label
{
    public:
        QtLabel(const std::string& _id, const std::string& _text)
        : Label(_id, _text)
        {

        }

        void draw() override
        {
            std::cout << "Afisam Label-ul folosind biblioteca Qt" << std::endl;
        }
};

class GtkLabel : public Label
{
    public:
        GtkLabel(const std::string& _id, const std::string& _text)
        : Label(_id, _text)
        {

        }

        void draw() override
        {
            std::cout << "Afisam Label-ul folosind biblioteca GTK" << std::endl;
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
};

class QtCheckBox : public CheckBox
{
    public:
        QtCheckBox(const std::string& _id, const std::string& _text, bool _isChecked)
        : CheckBox(_id, _text, _isChecked)
        {

        }

        void draw() override
        {
            std::cout << "Afisam CheckBox-ul folosind biblioteca Qt" << std::endl;
        }
};

class GtkCheckBox : public CheckBox
{
    public:
        GtkCheckBox(const std::string& _id, const std::string& _text, bool _isChecked)
        : CheckBox(_id, _text, _isChecked)
        {

        }

        void draw() override
        {
            std::cout << "Afisam CheckBox-ul folosind biblioteca GTK" << std::endl;
        }
};

enum WidgetType
{
    LABEL,
    CHECKBOX
};

struct WidgetProps
{
    WidgetType type;
    std::string id;
    std::string text;
    bool isChecked; // este luat în considerare doar dacă type == CHECKBOX
};

class AbstractWidgetFactory
{
    public:
        virtual std::shared_ptr<Widget> createWidget(const WidgetProps& winProps) = 0;
};

class QtWidgetFactory : public AbstractWidgetFactory
{
    private:
        void initLibrary()
        {

        }
    public:
        std::shared_ptr<Widget> createWidget(const WidgetProps& winProps) override
        {
            initLibrary();

            std::shared_ptr<Widget> ptr;

            switch (winProps.type)
            {
                case WidgetType::LABEL:
                    std::cout<<"Se creeaza un QtLabel" << std::endl;
                    ptr = std::dynamic_pointer_cast<Widget>(std::make_shared<QtLabel>(
                        winProps.id, winProps.text));
                    break;
                case WidgetType::CHECKBOX:
                    std::cout<<"Se creeaza un QtCheckbox" << std::endl;
                    ptr = std::dynamic_pointer_cast<Widget>(std::make_shared<QtCheckBox>(
                        winProps.id, winProps.text, winProps.isChecked));
                    break;
                default:
                    break;
            }

            return ptr;
        }
};

class GtkWidgetFactory : public AbstractWidgetFactory
{
    public:
        std::shared_ptr<Widget> createWidget(const WidgetProps& winProps) override
        {
            std::shared_ptr<Widget> ptr;

            switch (winProps.type)
            {
                case WidgetType::LABEL:
                    std::cout<<"Se creeaza un GtkLabel" << std::endl;
                    ptr = std::dynamic_pointer_cast<Widget>(std::make_shared<GtkLabel>(
                        winProps.id, winProps.text));
                    break;
                case WidgetType::CHECKBOX:
                    std::cout<<"Se creeaza un GtkCheckbox" << std::endl;
                    ptr = std::dynamic_pointer_cast<Widget>(std::make_shared<GtkCheckBox>(
                        winProps.id, winProps.text, winProps.isChecked));
                    break;
                default:
                    break;
            }

            return ptr;
        }
};

class Window
{
    private:
        std::vector<std::shared_ptr<Widget>> widgets;

    public:
        Window(AbstractWidgetFactory* widgetFactory,
               const std::vector<WidgetProps>& winPropsVect)
        {
            for (auto it = winPropsVect.begin();
                 it != winPropsVect.end();
                 ++it)
            {
                auto widget = widgetFactory->createWidget(*it);
                widgets.push_back(widget);
            }
        }
};

int main()
{
    std::vector<WidgetProps> widgetProps;
    widgetProps.push_back({WidgetType::LABEL, "123", "Label1", false});
    widgetProps.push_back({WidgetType::CHECKBOX, "125", "Some checkbox", true});

    QtWidgetFactory qtWidgetFactory;
    GtkWidgetFactory gtkWidgetFactory;

    Window winQt(&qtWidgetFactory, widgetProps);

    Window winGtk(&gtkWidgetFactory, widgetProps);

    return 0;
}