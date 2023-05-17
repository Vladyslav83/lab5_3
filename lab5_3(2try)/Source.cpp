#include <iostream>
#include <string>

class Window {
protected:
    std::string name;

public:
    Window(const std::string& name) : name(name) {}

    virtual void output(std::ostream& os) const {
        os << "Window Name: " << name << std::endl;
    }

    virtual void input(std::istream& is) {
        is >> name;
    }

    // Copy constructor
    Window(const Window& other) {
        name = other.name;
    }

    // Assignment operator
    Window& operator=(const Window& other) {
        if (this != &other) {
            name = other.name;
        }
        return *this;
    }
};

class TitleWindow : public Window {
private:
    std::string title;

public:
    TitleWindow(const std::string& name, const std::string& title)
        : Window(name), title(title) {}

    void output(std::ostream& os) const override {
        Window::output(os);
        os << "Title: " << title << std::endl;
    }

    void input(std::istream& is) override {
        Window::input(is);
        is >> title;
    }

    // Copy constructor
    TitleWindow(const TitleWindow& other) : Window(other) {
        title = other.title;
    }

    // Assignment operator
    TitleWindow& operator=(const TitleWindow& other) {
        if (this != &other) {
            Window::operator=(other);
            title = other.title;
        }
        return *this;
    }
};

int main() {
    // Creating and copying windows
    TitleWindow window1("Window1", "My Window");
    TitleWindow window2(window1); // Copy constructor
    TitleWindow window3("Window3", "Another Window");
    window3 = window2; // Assignment operator

    // Outputting windows
    window1.output(std::cout);
    window2.output(std::cout);
    window3.output(std::cout);

    // Inputting window
    TitleWindow window4("Window4", "");
    std::cout << "Enter a title for Window4: ";
    window4.input(std::cin);
    window4.output(std::cout);

    return 0;
}
