#include "MyTestPage1.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

my_test_page_1::my_test_page_1(QWidget* parent)
    : QWidget{parent}
{
}

my_test_page_1& my_test_page_1::layout_h()
{

}

my_test_page_1& my_test_page_1::layout_pop()
{
}

void my_test_page_1::add_layout_helper(QLayout* layout)
{
    if (m_layout_stack.empty()) {
        setLayout(layout);
    }
    else {

    }
}
