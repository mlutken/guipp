#include "test_page_a1.h"
#include <qboxlayout.h>
#include <qpushbutton.h>


test_page_a1::test_page_a1(QWidget* parent) :
    page_type_a{parent}
{
    build_page();
    // build_page_qt_way();
}

void test_page_a1::build_page_qt_way()
{
    setLayout(new QVBoxLayout{});

    auto button1 = new QPushButton("Hello from test_page_a1 (qt_way)!");
    layout()->addWidget(button1);
    auto button2 = new QPushButton("Button 2!");
    layout()->addWidget(button2);

}

void test_page_a1::build_page()
{
    layout_v().button("Hello from test_page_a1").button("Button 2!");
    layout_h().button("H1").button("h2");
}
